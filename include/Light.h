#pragma once
#include "Mesh.h"
#include "Model.h"
#include "glm/glm/glm.hpp"

class Light
{
public:
	Light() :color(0.0f, 1.0f, 1.0f)
	{
		init();
		model_.set_pos(glm::vec3(0,0,2));
	}

	void draw();

	void init();

	void set_model(Model& model) { model_ = model; }
	Shader& get_shader();
	void set_shader(Shader& shader) { shader_ = shader; }

	glm::vec3& get_pos() { return  model_.get_pos(); }
	void set_pos(const glm::vec3& position);

private:
	glm::vec3 color;

	//Mesh mesh_;
	Model model_;

	Shader shader_;
};
