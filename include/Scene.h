#pragma once
#include "Camera.h"
#include "PointLight.h"
#include "Model.h"

class Scene
{
public:
	Scene() = default;

	void add_model(const Model& model) { models_.push_back(model); }
	void add_camera(const Camera& camera) { cameras_.push_back(camera); }
	void add_light(const PointLight& light) { lights_.push_back(light); }

	void activate_cam(int index) { active_index = index; }

	Camera &get_cam();

	void draw(Shader& shader, int width, int height);

private:
	size_t active_index;

	std::vector<Model> models_;
	std::vector<Camera> cameras_;
	std::vector<AbstractLight> lights_;

	Camera default_camera;

	//Todo:lights
};
