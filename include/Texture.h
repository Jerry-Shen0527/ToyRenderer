#pragma once

#include <assimp/types.h>
unsigned int TextureFromFile(const char* path, const std::string& directory, bool gamma = false);
class Texture {
public:
	Texture() {}
	Texture(const char* path, const std::string& directory)
	{
		id = TextureFromFile(path, directory);
	}

public:
	unsigned int id;
	std::string type;
	aiString path;  // 我们储存纹理的路径用于与其它纹理进行比较
};
