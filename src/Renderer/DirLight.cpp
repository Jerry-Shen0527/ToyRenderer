#include <DirLight.h>

#include "AbstractLight.h"

DirLight::DirLight(glm::vec3& dir)
{
	init();
	direction = dir;
}

void DirLight::add_light_to_shader(Shader& shader, int id)
{
	computeLightSpaceMat();

	shader.use();
	shader.setMat4("lightSpaceMatrix", lightSpaceMatrix);
	glActiveTexture(GL_TEXTURE0 + (15 - id));
	glBindTexture(GL_TEXTURE_2D, depthMap);
	shader.setInt("shadowMap[" + std::to_string(id) + "]", (15 - id));

	shader.setVec3("directionLights[" + std::to_string(id) + "].ambient", ambient);
	shader.setVec3("directionLights[" + std::to_string(id) + "].diffuse", diffuse);
	shader.setVec3("directionLights[" + std::to_string(id) + "].specular", specular);
	shader.setVec3("directionLights[" + std::to_string(id) + "].direction", direction);

	shader.setInt("shadowMap[" + std::to_string(id) + "].shadowMap", depthMap);
}

void DirLight::draw()
{
	//Direct light cannot be drawn!
}

void DirLight::set_cam_matrix(Camera& camera)
{
	//do nothing!
}

void DirLight::shadow(Scene* scene)
{
	glBindFramebuffer(GL_FRAMEBUFFER, depthMapFBO);
	computeLightSpaceMat();
	shadow_shader.use();
	shadow_shader.setMat4("lightSpaceMatrix", lightSpaceMatrix);
	glViewport(0, 0, SHADOW_WIDTH, SHADOW_HEIGHT);
	glClear(GL_DEPTH_BUFFER_BIT);
	scene->draw_models(shadow_shader);
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

void DirLight::init()
{
	glGenFramebuffers(1, &depthMapFBO);

	glGenTextures(1, &depthMap);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, depthMap);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT,
		SHADOW_WIDTH, SHADOW_HEIGHT, 0, GL_DEPTH_COMPONENT, GL_FLOAT, NULL);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
	GLfloat borderColor[] = { 1.0, 1.0, 1.0, 1.0 };
	glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, borderColor);

	glBindFramebuffer(GL_FRAMEBUFFER, depthMapFBO);
	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, depthMap, 0);
	glDrawBuffer(GL_NONE);
	glReadBuffer(GL_NONE);
	glBindFramebuffer(GL_FRAMEBUFFER, 0);

	shadow_shader.init(resource_path + "Shaders\\Light\\shadow.vert", resource_path + "Shaders\\Light\\shadow.frag");
}

void DirLight::computeLightSpaceMat()
{
	GLfloat near_plane = -5.0f, far_plane = 10.0f;
	glm::mat4 lightProjection = glm::ortho(-10.0f, 10.0f, -10.0f, 10.0f, near_plane, far_plane);
	auto lightView = glm::lookAt(-direction, glm::vec3(0.0f), glm::vec3(0.0, 1.0, 0.0));
	lightSpaceMatrix = lightProjection * lightView;
}

void DirLight::set_direction(const glm::vec3& direction)
{
	this->direction = direction;
}