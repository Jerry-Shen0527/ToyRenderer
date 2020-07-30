#pragma once
#include "Mesh.h"
#include "Model.h"
#include "glm/glm/glm.hpp"
#include <CommonSettings.h>
#include <Camera.h>

class AbstractLight
{
public:
	virtual void draw() = 0;
	virtual void set_cam_matrix(Camera& camera) = 0;
	
	virtual  void add_light_to_shader(Shader& shader, int id) = 0;

	virtual ~AbstractLight() {}

protected:
	glm::vec3 ambient;
	glm::vec3 diffuse;
	glm::vec3 specular;
};
