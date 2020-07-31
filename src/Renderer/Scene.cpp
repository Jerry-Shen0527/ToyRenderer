#include <Scene.h>
#include <CommonSettings.h>

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

	for (int i = 0; i < lights_.size(); ++i)
	{
		lights_[i]->set_cam_matrix(cam);
		lights_[i]->draw();
		lights_[i]->shadow(this);

		lights_[i]->add_light_to_shader(shader, i);

	}
	
	glViewport(0, 0, width, height);

	cam.setShader(shader);
	shader.setVec3("viewPos", cam.Position);
	draw_models(shader);
}

void Scene::draw_models(Shader shader)
{
	for (auto& model_ : models_)
	{
		model_.draw(shader);
	}
}