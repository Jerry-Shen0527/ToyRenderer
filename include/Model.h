#pragma once
#include <Mesh.h>

#include "GeoTransform.h"

class Model
{
public:
	Model();

	Model(const std::vector<Mesh>&& meshes) :Model() { this->meshes = meshes; }
	Model(const std::vector<Mesh>& meshes) :Model() { this->meshes = meshes; }

	void add_mesh(Mesh& mesh);
	void draw(Shader& shader);

private:
	std::vector<Mesh> meshes;

	glm::vec3 specular;
	float shiniess;

	GeoTransform geo_;
public:
	GeoTransform& get_geo();
};
