#pragma once
#include <Mesh.h>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

class Model
{
public:
	static std::vector<Texture> textures_loaded;
	Model() {}

	Model(char const* path)
	{
		load_model(path);
	}

	void add_mesh(Mesh& mesh);
	void draw(Shader& shader);

	glm::vec3& get_pos() { return  pos; }
	void set_pos(const glm::vec3& position);

private:
	std::vector<Mesh> meshes;
	std::string directory;

	glm::vec3 pos;

	void load_model(std::string path);
	void process_node(aiNode* node, const aiScene* scene);
	Mesh process_mesh(aiMesh* mesh, const aiScene* scene);
	std::vector<Texture> load_material_textures(aiMaterial* mat, aiTextureType type, std::string typeName);
};

unsigned int TextureFromFile(const char* path, const std::string& directory, bool gamma = false);
