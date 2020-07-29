#include <Light.h>

#include "CommonSettings.h"

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

void Light::translate(const glm::vec3& position)
{
	model_.translate(position);
}

void Light::draw(Shader& shader)
{
	model_.draw(shader);
}