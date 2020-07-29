#include <Scene.h>

Camera& Scene::get_cam()
{
	if (active_index < cameras_.size())
	{
		return cameras_[active_index];
	}
	return default_camera;
}

void Scene::draw(Shader& shader, int width, int height)
{
	auto& cam = get_cam();

	glm::mat4 projection = glm::perspective(glm::radians(cam.Zoom), (float)width / (float)height, 0.1f, 100.0f);
	glm::mat4 view = cam.GetViewMatrix();
	for (int i = 0; i < lights_.size(); ++i)
	{
		lights_[i].get_shader().use();
		lights_[i].get_shader().setMat4("projection", projection);
		lights_[i].get_shader().setMat4("view", view);
		lights_[i].draw();

		lights_[i].add_light_to_shader(shader, i);
	}

	auto shader_ = shader;
	shader_.use();

	shader_.setMat4("projection", projection);
	shader_.setMat4("view", view);

	for (auto& model_ : models_)
	{
		// render the loaded model

		model_.get_geo().shader_set(shader_);
		model_.draw(shader_);
	}
}