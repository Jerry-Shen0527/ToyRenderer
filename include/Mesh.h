#pragma once

#include <Shader.h>
#include <string>
#include <vector>
#include <assimp/types.h>
#include <glad/glad.h>
#include <glm/glm/glm.hpp>
#include <Texture.h>

struct Vertex
{
	Vertex() {}
	Vertex(glm::vec3& pos) { Position = pos; }
	Vertex(glm::vec3& pos, glm::vec3& normal) { Position = pos; Normal = normal; }
	Vertex(glm::vec3& pos, glm::vec3& normal, glm::vec2& texcoords) { Position = pos; Normal = normal; TexCoords = texcoords; }

	glm::vec3 Position;
	glm::vec3 Normal;
	glm::vec2 TexCoords;
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
