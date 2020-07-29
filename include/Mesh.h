#pragma once

#include <Shader.h>
#include <string>
#include <vector>
#include <assimp/types.h>
#include <glad/glad.h>
#include <glm/glm/glm.hpp>
#include <Texture.h>

#include "Vertex.h"


class Mesh
{
public:
	Mesh() {}

	std::vector<Vertex> vertices;
	std::vector<unsigned int> indices;
	std::vector<Texture> textures;

	Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices, std::vector<Texture> textures);
	void draw(Shader& shader);

	void add_texture(Texture& texture);

private:

	unsigned int VAO, VBO, EBO;

	void setup_mesh();
};
