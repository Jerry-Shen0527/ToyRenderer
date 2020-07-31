#pragma once
#include "glm/glm/glm.hpp"
#include <Camera.h>
#include <Scene.h>


class Scene;
class AbstractLight
{
public:
	AbstractLight() :ambient(0.2, 0.2, 0.2), diffuse(0.5, 0.5, 0.5), specular(1.0, 1.0, 1.0) {  }

	virtual void draw() = 0;
	virtual void set_cam_matrix(Camera& camera) = 0;

	virtual  void add_light_to_shader(Shader& shader, int id) = 0;
	virtual void shadow(Scene* scene) {}

	virtual ~AbstractLight() {}

protected:
	Shader shadow_shader;


public:
	virtual Shader& get_shadow_shader();
protected:
	glm::vec3 ambient;
	glm::vec3 diffuse;
	glm::vec3 specular;
};
