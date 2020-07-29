#include <Model.h>
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

void Model::add_mesh(Mesh& mesh)
{
	meshes.push_back(mesh);
}

void Model::draw(Shader& shader)
{
	geo_.shader_set(shader);
	for (unsigned int i = 0; i < meshes.size(); i++)
		meshes[i].draw(shader);
}

void Model::set_pos(const glm::vec3& position)
{
	geo_.translate(position);
}

