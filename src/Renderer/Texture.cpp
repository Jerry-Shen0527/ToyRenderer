#include <iostream>
#include <Texture.h>

#include "glad/glad.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

unsigned int TextureFromFile(const std::string& directory, const std::string& filename, bool gamma)
{
	auto full_name = directory + '\\' + filename;

	unsigned int textureID;
	glGenTextures(1, &textureID);

	int width, height, nrComponents;
	unsigned char* data = stbi_load(full_name.c_str(), &width, &height, &nrComponents, 0);
	if (data)
	{
		GLenum internalformat;
		GLenum format;
		if (nrComponents == 1) {
			internalformat = GL_RED;
			format = GL_RED;
		}
		else if (nrComponents == 3) {
			internalformat = GL_SRGB;
			format = GL_RGB;
		}
		else if (nrComponents == 4)
		{
			internalformat = GL_SRGB_ALPHA;
			format = GL_RGBA;
		}

		glBindTexture(GL_TEXTURE_2D, textureID);
		if (gamma)
		{
			glTexImage2D(GL_TEXTURE_2D, 0, internalformat, width, height, 0, format, GL_UNSIGNED_BYTE, data);
		}
		else
		{
			glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
		}
		glGenerateMipmap(GL_TEXTURE_2D);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		stbi_image_free(data);
	}
	else
	{
		std::cout << "Texture failed to load at path: " << directory << std::endl;
		stbi_image_free(data);
	}

	return textureID;
}

Texture::Texture(const std::string& path, const std::string& directory, std::string type,bool gamma)
{
	id = TextureFromFile(path, directory,gamma);
	this->type = type;
}