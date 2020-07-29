#pragma once
#include "glm/glm/glm.hpp"

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
