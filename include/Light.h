#pragma once
#include "Mesh.h"
#include "Model.h"
#include "glm/glm/glm.hpp"

class Light :public AbstractModel
{
public:
	Light()  { init(); }
	Light(std::vector<Mesh> &meshes) : model_(meshes) { init(); }

	void init();

	Shader& get_shader();
	void set_shader(Shader& shader);
	void set_model(Model& model);

	void add_light_to_shader(Shader& shader, int id);

	glm::vec3& get_pos();
	void translate(const glm::vec3& position);

	void draw();

	//light can be drawn directly
	void draw(Shader& shader) override;

	glm::vec3& get_color();
private:
	glm::vec3 color;
public:
	void set_color(const glm::vec3& color);
private:
	Model model_;
	Shader shader_;

	glm::vec3 ambient;
	glm::vec3 diffuse;
	glm::vec3 specular;
};

