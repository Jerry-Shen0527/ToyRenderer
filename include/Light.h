#pragma once
#include "Mesh.h"
#include "Model.h"
#include "glm/glm/glm.hpp"

class Light :public AbstractModel
{
public:
	Light() :color(0.0f, 1.0f, 1.0f) { init(); }
	Light(std::vector<Mesh> &meshes) : model_(meshes) { init(); }

	void init();

	Shader& get_shader();
	void set_shader(Shader& shader) { shader_ = shader; }
	void set_model(Model& model) { model_ = model; }

	void add_light_to_shader(Shader& shader, int id);

	glm::vec3& get_pos() { return  model_.get_pos(); }
	void translate(const glm::vec3& position);

	void draw() { draw(shader_); }

	//light can be drawn directly
	void draw(Shader& shader) override;

private:
	glm::vec3 color;
	Model model_;
	Shader shader_;
};
