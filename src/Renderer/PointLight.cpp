#pragma once

#include <PointLight.h>

#include "AbstractLight.h"
#include "CommonSettings.h"

void PointLight::init()
{
	using namespace glm;
	ambient = vec3(0.2f, 0.2f, 0.2f);
	diffuse = vec3(0.5f, 0.5f, 0.5f);
	specular = vec3(1.0f, 1.0f, 1.0f);

	shader_.init(resource_path + "Shaders\\Light\\light.vert", resource_path + "Shaders\\Light\\light.frag");

	shader_.use();
	shader_.setVec3("color", specular);
}

Shader& PointLight::get_shader()
{
	return shader_;
}

void PointLight::set_model(Model& model)
{
	model_ = model;
}

void PointLight::add_light_to_shader(Shader& shader, int id)
{
	shader.use();

	shader.setVec3("pointLights[" + std::to_string(id) + "].ambient", ambient);
	shader.setVec3("pointLights[" + std::to_string(id) + "].diffuse", diffuse);
	shader.setVec3("pointLights[" + std::to_string(id) + "].specular", specular);
	shader.setVec3("pointLights[" + std::to_string(id) + "].position", get_geo().get_pos());
	shader.setFloat("pointLights[" + std::to_string(id) + "].constant", 1.0f);
	shader.setFloat("pointLights[" + std::to_string(id) + "].linear", 0.09f);
	shader.setFloat("pointLights[" + std::to_string(id) + "].quadratic", 0.032f);
}

void PointLight::translate(const glm::vec3& position)
{
	model_.get_geo().translate(position);
}

void PointLight::draw()
{
	model_.draw(shader_);
}

GeoTransform& PointLight::get_geo()
{
	return model_.get_geo();
}

void PointLight::set_cam_matrix(Camera& camera)
{
	camera.setShader(shader_);
}