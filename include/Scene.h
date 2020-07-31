#pragma once
#include "Camera.h"
#include "Model.h"
#include <AbstractLight.h>

class AbstractLight;
class Scene
{
public:
	Scene() = default;

	void add_model(const Model& model) { models_.push_back(model); }
	void add_camera(Camera& camera) { cameras_.push_back(camera); }
	void add_light(std::shared_ptr<AbstractLight>  light)
	{
		lights_.push_back(light);
	}

	void activate_cam(int index) { active_index = index; }

	Camera& get_cam();

	void draw(Shader& shader, int width, int height);
	void draw_models(Shader shader);

private:
	
	size_t active_index;

	std::vector<Model> models_;
	std::vector<Camera> cameras_;
	std::vector<std::shared_ptr<AbstractLight>> lights_;

	Camera default_camera;

	//Todo:lights
};
