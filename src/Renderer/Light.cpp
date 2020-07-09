#include <Light.h>

#include "CommonSettings.h"

void Light::draw()
{
	glm::mat4 model(1.0f);
	model = glm::translate(model, pos);
	shader_.setMat4("model", model);
	mesh_.draw(shader_);
}

void Light::init()
{
	shader_.init((resource_path + "Shaders\\Light\\light.vert").c_str(), (resource_path + "Shaders\\Light\\light.frag").c_str());

	shader_.use();
	shader_.setVec3("color", color);

}

Shader& Light::get_shader()
{
	return shader_;
}

void Light::set_pos(const glm::vec3& position)
{
	pos = position;
}