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
	
	glm::vec3 Position;
	glm::vec3 Normal;
	glm::vec2 TexCoords;
};

struct Texture {
	unsigned int id;
	std::string type;
	aiString path;  // ���Ǵ���������·�������������������бȽ�
};

class Mesh
{
public:
    std::vector<Vertex> vertices;
    std::vector<unsigned int> indices;
    std::vector<Texture> textures;

	Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices, std::vector<Texture> textures);
    void draw(Shader& shader);

private:

	unsigned int VAO, VBO, EBO;

    void setup_mesh();
};