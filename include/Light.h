#pragma once
#include "Mesh.h"
#include "glm/glm/glm.hpp"

class Light
{
public:
	Light() :color(0.0f, 1.0f, 1.0f), pos(0, 0, 0) { init(); }

	void draw();

	void init();

	void set_mesh(Mesh& mesh) { mesh_ = mesh; }

	Shader& get_shader();
	void set_shader(Shader& shader) { shader_ = shader; }

	glm::vec3& get_pos() { return  pos; }
	void set_pos(const glm::vec3& position);

private:
	glm::vec3 color;
	glm::vec3 pos;

	Mesh mesh_;

	Shader shader_;
};
