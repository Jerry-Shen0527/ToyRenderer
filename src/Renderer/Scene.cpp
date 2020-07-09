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
	for (auto light : lights_)
	{
		light.get_shader().use();
		light.get_shader().setMat4("projection", projection);
		light.get_shader().setMat4("view", view);
		light.draw();
	}

	auto shader_ = shader;
	shader_.use();

	shader_.setMat4("projection", projection);
	shader_.setMat4("view", view);

	for (auto& model_ : models_)
	{
		// render the loaded model
		glm::mat4 model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(0.0f, 0.0f, 0.0f));
		model = glm::scale(model, glm::vec3(1.0f, 1.0f, 1.0f) * 0.3f);
		shader_.setMat4("model", model);
		model_.draw(shader_);
	}
}