#include <DirLight.h>

void DirLight::add_light_to_shader(Shader& shader, int id)
{
	id++;
	shader.use();

	shader.setVec3("light" + std::to_string(id) + ".ambient", ambient);
	shader.setVec3("light" + std::to_string(id) + ".diffuse", diffuse);
	shader.setVec3("light" + std::to_string(id) + ".specular", specular);
}

void DirLight::draw()
{
	//Direct light cannot be drawn!
}
