#pragma once
#include <string>
#include <assimp/scene.h>

#include "Mesh.h"
#include "Model.h"

class AssimpLoader
{
public:
	AssimpLoader(std::string filename)
	{
		load_model(filename);
	}

	void load_model(std::string path);
	void process_node(aiNode* node, const aiScene* scene);
	std::vector<Texture> load_material_textures(aiMaterial* mat, aiTextureType type, std::string typeName);
	Mesh process_mesh(aiMesh* mesh, const aiScene* scene);

	Model get_model();

private:
	static std::vector<Texture> textures_loaded;
	std::string directory;

	std::vector<Mesh> meshes;
public:
	std::vector<Mesh>& get_meshes();
private:
	glm::vec3 pos;

};
