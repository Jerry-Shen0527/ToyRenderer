#pragma once
#include <Mesh.h>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include "AbstractModel.h"

class Model :public AbstractModel
{
public:
	Model() {}

	Model(const std::vector<Mesh>&& meshes) { this->meshes = meshes; }
	Model(const std::vector<Mesh>& meshes) { this->meshes = meshes; }

	void add_mesh(Mesh& mesh);
	void draw(Shader& shader);

	glm::vec3& get_pos() { return  pos; }
	void set_pos(const glm::vec3& position);

private:
	std::vector<Mesh> meshes;
	glm::vec3 pos;
};

unsigned int TextureFromFile(const char* path, const std::string& directory, bool gamma = false);
