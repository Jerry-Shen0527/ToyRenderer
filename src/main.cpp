#include <Scene.h>
#include <string>
#include <iostream>

#include "Renderer.h"
#include <CommonSettings.h>

float vertices[] = {
	-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f, 0.0f, 1.0f,
	 0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f, 1.0f, 1.0f,
	 0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f, 1.0f, 0.0f,
	 0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f, 1.0f, 0.0f,
	-0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f, 0.0f, 0.0f,
	-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f, 0.0f, 1.0f,
											  
	-0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f, 0.0f, 1.0f,
	 0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f, 1.0f, 1.0f,
	 0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f, 1.0f, 0.0f,
	 0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f, 1.0f, 0.0f,
	-0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f, 0.0f, 0.0f,
	-0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f, 0.0f, 1.0f,
											  
	-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f, 0.0f, 1.0f,
	-0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f, 1.0f, 1.0f,
	-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f, 1.0f, 0.0f,
	-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f, 1.0f, 0.0f,
	-0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f, 0.0f, 0.0f,
	-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f, 0.0f, 1.0f,
											  
	 0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f, 0.0f, 1.0f,
	 0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f, 1.0f, 1.0f,
	 0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f, 1.0f, 0.0f,
	 0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f, 1.0f, 0.0f,
	 0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f, 0.0f, 0.0f,
	 0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f, 0.0f, 1.0f,
											  
	-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f, 0.0f, 1.0f,
	 0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f, 1.0f, 1.0f,
	 0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f, 1.0f, 0.0f,
	 0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f, 1.0f, 0.0f,
	-0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f, 0.0f, 0.0f,
	-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f, 0.0f, 1.0f,
											  
	-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f, 0.0f, 1.0f,
	 0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f, 1.0f, 1.0f,
	 0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f, 1.0f, 0.0f,
	 0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f, 1.0f, 0.0f,
	-0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f, 0.0f, 0.0f,
	-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f, 0.0f, 1.0f
};
//
//unsigned int indices[] = { // 注意索引从0开始!
//	0, 1, 2, // 第一个三角形
//};

int main()
{
	Renderer renderer;

	std::vector<Vertex> vertices_vec;
	std::vector<unsigned> indices_vec;

	for (int i = 0; i < sizeof(vertices) / sizeof(float); i += 8)
	{
		vertices_vec.push_back(Vertex(glm::vec3(vertices[i], vertices[i + 1], vertices[i + 2]), glm::vec3(vertices[i + 3], vertices[i + 4], vertices[i + 5]),glm::vec2(vertices[i+6],vertices[i+7])));
	}

	Mesh mesh(vertices_vec, indices_vec, std::vector<Texture>());

	Model model;
	model.add_mesh(mesh);
	//Model model((resource_path + "Models\\nanosuit\\nanosuit.obj").c_str());

	Light light;
	light.set_model(model);
	light.translate(glm::vec3(0, 4, 0));


	Scene scene;
	scene.add_model(model);
	scene.add_camera(Camera());
	scene.add_light(light);
	renderer.add_scene(std::move(scene));

	scene.activate_cam(0);

	Shader shader;
	shader.init((resource_path + "Shaders\\Simple\\1.vert").c_str(), (resource_path + "Shaders\\Simple\\1.frag").c_str());

	renderer.add_Shader(shader);

	renderer.exec([] {});

	return 0;
}
