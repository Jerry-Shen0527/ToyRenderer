#pragma once
#include <AbstractLight.h>
#include <Scene.h>

class DirLight :public AbstractLight
{
public:
	DirLight(glm::vec3& dir);

	void add_light_to_shader(Shader& shader, int id) override;
	void draw() override;
	void set_cam_matrix(Camera& camera) override;

	void shadow(Scene* scene);
private:
	void init();

	

	glm::vec3 direction;
	const GLuint SHADOW_WIDTH = 1024*2;
	const GLuint SHADOW_HEIGHT = 1024*2;
	GLuint depthMapFBO;
	GLuint depthMap;

	
	glm::mat4 lightSpaceMatrix;
	void computeLightSpaceMat();
public:
	void set_direction(const glm::vec3& direction);

};
