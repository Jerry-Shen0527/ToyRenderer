#include <Light.h>

#include "CommonSettings.h"

void Light::init()
{
	using namespace glm;
	//color = vec3(1.0f, 1.0f, 1.0f);
	ambient = vec3(0.2f, 0.2f, 0.2f);
	diffuse = vec3(0.5f, 0.5f, 0.5f);
	specular = vec3(1.0f, 1.0f, 1.0f);

	shader_.init((resource_path + "Shaders\\Light\\light.vert").c_str(), (resource_path + "Shaders\\Light\\light.frag").c_str());
	set_color(specular);
}

Shader& Light::get_shader()
{
	return shader_;
}

void Light::set_shader(Shader& shader)
{
	shader_ = shader;
}

void Light::set_model(Model& model)
{
	model_ = model;
}

void Light::add_light_to_shader(Shader& shader, int id)
{
	id++;
	shader.use();

	shader.setVec3("light" + std::to_string(id)+".ambient", ambient);
	shader.setVec3("light" + std::to_string(id) + ".diffuse", diffuse);
	shader.setVec3("light" + std::to_string(id) + ".specular", specular);
	shader.setVec3("light" + std::to_string(id)+".position", get_pos());
}

glm::vec3& Light::get_pos()
{
	return model_.get_pos();
}

void Light::translate(const glm::vec3& position)
{
	model_.get_geo().translate(position);
}

void Light::draw()
{
	draw(shader_);
}

void Light::draw(Shader& shader)
{
	model_.draw(shader);
}
glm::vec3& Light::get_color()
{
	return color;
}

void Light::set_color(const glm::vec3& color)
{
	this->color = color;

	shader_.use();
	shader_.setVec3("color", color);
}