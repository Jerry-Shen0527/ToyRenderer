#include <Scene.h>
#include <string>
#include <iostream>

#include "Renderer.h"

const std::string resource_path = "C:\\Users\\Jerry\\WorkSpace\\ToyRenderer\\resources\\";

float vertices[] = {
	-0.5f, -0.5f, 0.0f,
	 0.5f, -0.5f, 0.0f,
	 0.0f,  0.5f, 0.0f
};

unsigned int indices[] = { // 注意索引从0开始!
	0, 1, 2, // 第一个三角形
};

int main()
{
	Renderer renderer;

	//std::vector<Vertex> vertices_vec;
	//std::vector<unsigned> indices_vec;

	//for (int i = 0; i < sizeof(vertices) / sizeof(float); i += 3)
	//{
	//	vertices_vec.push_back(Vertex(glm::vec3(vertices[i], vertices[i + 1], vertices[i + 2])));
	//}

	//for (int i = 0; i < sizeof(indices) / sizeof(unsigned); ++i)
	//	indices_vec.push_back(indices[i]);

	//Mesh mesh(vertices_vec, indices_vec, std::vector<Texture>());

	//Model model;
	//model.add_mesh(mesh);

	Model model((resource_path + "Models\\nanosuit\\nanosuit.obj").c_str());

	Scene scene;
	scene.add_model(model);

	renderer.add_scene(std::move(scene));

	Shader shader;
	shader.init((resource_path + "Shaders\\Simple\\1.vert").c_str(), (resource_path + "Shaders\\Simple\\1.frag").c_str());

	renderer.add_Shader(shader);

	renderer.exec([] {});

	return 0;
}