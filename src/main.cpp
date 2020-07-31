#include <Scene.h>
#include <string>
#include <iostream>

#include "Renderer.h"
#include <CommonSettings.h>
#include <PointLight.h>

#include "Assimp_Loader.h"
#include "DirLight.h"

//float vertices[] = {
//	-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f, 0.0f, 1.0f,
//	 0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f, 1.0f, 1.0f,
//	 0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f, 1.0f, 0.0f,
//	 0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f, 1.0f, 0.0f,
//	-0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f, 0.0f, 0.0f,
//	-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f, 0.0f, 1.0f,
//
//	-0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f, 0.0f, 1.0f,
//	 0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f, 1.0f, 1.0f,
//	 0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f, 1.0f, 0.0f,
//	 0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f, 1.0f, 0.0f,
//	-0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f, 0.0f, 0.0f,
//	-0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f, 0.0f, 1.0f,
//
//	-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f, 0.0f, 1.0f,
//	-0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f, 1.0f, 1.0f,
//	-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f, 1.0f, 0.0f,
//	-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f, 1.0f, 0.0f,
//	-0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f, 0.0f, 0.0f,
//	-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f, 0.0f, 1.0f,
//
//	 0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f, 0.0f, 1.0f,
//	 0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f, 1.0f, 1.0f,
//	 0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f, 1.0f, 0.0f,
//	 0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f, 1.0f, 0.0f,
//	 0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f, 0.0f, 0.0f,
//	 0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f, 0.0f, 1.0f,
//
//	-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f, 0.0f, 1.0f,
//	 0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f, 1.0f, 1.0f,
//	 0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f, 1.0f, 0.0f,
//	 0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f, 1.0f, 0.0f,
//	-0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f, 0.0f, 0.0f,
//	-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f, 0.0f, 1.0f,
//
//	-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f, 0.0f, 1.0f,
//	 0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f, 1.0f, 1.0f,
//	 0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f, 1.0f, 0.0f,
//	 0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f, 1.0f, 0.0f,
//	-0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f, 0.0f, 0.0f,
//	-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f, 0.0f, 1.0f
//};

float vertices[] = {
	// positions            // normals         // texcoords
	 10.0f, -0.5f,  10.0f,  0.0f, 1.0f, 0.0f,  10.0f,  0.0f,
	-10.0f, -0.5f,  10.0f,  0.0f, 1.0f, 0.0f,   0.0f,  0.0f,
	-10.0f, -0.5f, -10.0f,  0.0f, 1.0f, 0.0f,   0.0f, 10.0f,

	 10.0f, -0.5f,  10.0f,  0.0f, 1.0f, 0.0f,  10.0f,  0.0f,
	-10.0f, -0.5f, -10.0f,  0.0f, 1.0f, 0.0f,   0.0f, 10.0f,
	 10.0f, -0.5f, -10.0f,  0.0f, 1.0f, 0.0f,  10.0f, 10.0f
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
		vertices_vec.push_back(Vertex(glm::vec3(vertices[i], vertices[i + 1], vertices[i + 2]), glm::vec3(vertices[i + 3], vertices[i + 4], vertices[i + 5]), glm::vec2(vertices[i + 6], vertices[i + 7])));
	}

	Mesh mesh(vertices_vec, indices_vec, std::vector<Texture>());

	mesh.add_texture(Texture(resource_path, "Textures\\wood.jpg", "texture_diffuse", true));
	mesh.add_texture(Texture(resource_path, "Textures\\wood.jpg", "texture_specular"));

	Model model_plane;
	model_plane.add_mesh(mesh);

	Model model_light;
	model_light.add_mesh(mesh);
	AssimpLoader loader((resource_path + "Models\\nanosuit\\nanosuit.obj").c_str());
	Model model(loader.get_model());
	model.get_geo().translate(glm::vec3(.0f, -0.5f, .0f));

	model.get_geo().scale(0.2);

	auto model2 = model;
	model2.get_geo().translate(glm::vec3(2.0f, .0f, .0f));

	Scene scene;

	using  namespace  std;
	auto light = make_shared<PointLight>();
	light->set_model(model_light);
	light->translate(glm::vec3(0, 3, 1));
	light->get_geo().scale(0.01);

	auto dir_light = make_shared<DirLight>(glm::vec3(-1, -1, -1));
	scene.add_light(dir_light);

	scene.add_model(model);
	scene.add_model(model2);
	scene.add_model(model_plane);
	scene.add_camera(Camera());
	scene.add_light(light);
	renderer.add_scene(std::move(scene));

	scene.activate_cam(0);

	Shader shader;
	shader.init(resource_path + "Shaders\\light_experiments\\ShadowMap.vert", resource_path + "Shaders\\light_experiments\\ShadowMap.frag");

	renderer.add_Shader(shader);

	renderer.exec([] {});

	return 0;
}