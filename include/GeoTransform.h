#include <Shader.h>

#include "CommonSettings.h"

class GeoTransform
{
public:
	GeoTransform();
	GeoTransform(glm::vec3& vec);

	void translate(glm::vec3 vec);
	void rotate(glm::vec3 vec, real theta);
	void scale(glm::vec3 vec);
	void scale(real s);

	void shader_set(Shader& shader);
protected:
	glm::vec3 scale_;
	glm::vec3 pos_;
	glm::qua<real> q_;
};
