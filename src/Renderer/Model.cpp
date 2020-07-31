#include <Model.h>

Model::Model()
{
	specular = glm::vec3(1.0, 1.0, 1.0);
	specular *= 0.5;
	shiniess = 32.0f;
}

void Model::add_mesh(Mesh& mesh)
{
	meshes.push_back(mesh);
}

void Model::draw(Shader& shader)
{
	shader.setVec3("material.specular", specular);
	shader.setFloat("material.shininess", shiniess);
	geo_.shader_set(shader);
	for (unsigned int i = 0; i < meshes.size(); i++)
		meshes[i].draw(shader);
}

GeoTransform& Model::get_geo()
{
	return geo_;
}