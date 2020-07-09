#pragma once

#include <Shader.h>	
#include <string>
#include <vector>
#include <assimp/types.h>
#include <glad/glad.h>
#include <glm/glm/glm.hpp>

struct Vertex
{
	Vertex() {}
	Vertex(glm::vec3& pos) { Position = pos; }
	Vertex(glm::vec3& pos, glm::vec3& normal) { Position = pos; Normal = normal; }
	
	glm::vec3 Position;
	glm::vec3 Normal;
	glm::vec2 TexCoords;
};

struct Texture {
	unsigned int id;
	std::string type;
	aiString path;  // 我们储存纹理的路径用于与其它纹理进行比较
};

class Mesh
{
public:
	Mesh() {}
	
    std::vector<Vertex> vertices;
    std::vector<unsigned int> indices;
    std::vector<Texture> textures;

	Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices, std::vector<Texture> textures);
    void draw(Shader& shader);

private:

	unsigned int VAO, VBO, EBO;

    void setup_mesh();
};
