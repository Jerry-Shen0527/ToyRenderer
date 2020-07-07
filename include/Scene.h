#pragma once
#include "Camera.h"
#include "Model.h"

class Scene
{
public:
	Scene() = default;
		
	void add_model(const Model& model) { models_.push_back(model); }
	void add_camera(const Camera& camera) { cameras_.push_back(camera); }

	void activate_cam(int index) { active_index = index; }

	Camera get_cam()
	{
		if (active_index < cameras_.size())
		{
			return cameras_[active_index];
		}
		return {};
	}

	void Draw(Shader& shader)
	{
		for (auto& model : models_)
		{
			model.draw(shader);
		}
	}

private:
	size_t active_index{};

	std::vector<Model> models_;
	std::vector<Camera> cameras_;

	//Todo:lights
};
