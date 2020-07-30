#pragma once
#include <Mesh.h>

#include "GeoTransform.h"


class Model 
{
public:
	Model();

	Model(const std::vector<Mesh>&& meshes) { this->meshes = meshes; }
	Model(const std::vector<Mesh>& meshes) { this->meshes = meshes; }

	void add_mesh(Mesh& mesh);
	void draw(Shader& shader);

	glm::vec3& get_pos();

private:
	std::vector<Mesh> meshes;

	GeoTransform geo_;
public:
	GeoTransform& get_geo();
};
