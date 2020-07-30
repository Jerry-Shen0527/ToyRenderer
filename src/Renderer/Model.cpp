#include <Model.h>

Model::Model() 
{
}

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

glm::vec3& Model::get_pos()
{
	return geo_.get_pos();
}

GeoTransform& Model::get_geo()
{
	return geo_;
}

