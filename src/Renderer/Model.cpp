#include <Model.h>

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

void Model::translate(const glm::vec3& position)
{
	geo_.translate(position);
}

