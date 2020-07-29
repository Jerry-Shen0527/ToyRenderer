#pragma once

#include <assimp/types.h>
unsigned int TextureFromFile(const std::string& directory, const std::string& file, bool gamma = false);
class Texture {
public:
	Texture() {}
	Texture(const std::string& path, const std::string& directory, std::string type = "texture_diffuse");

public:
	unsigned int id;
	std::string type;
	aiString path;  // ���Ǵ��������·������������������бȽ�
};
