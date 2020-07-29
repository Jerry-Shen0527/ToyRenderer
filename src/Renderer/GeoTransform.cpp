#include <GeoTransform.h>

GeoTransform::GeoTransform() :scale_(1, 1, 1), q_(glm::radians(0.0f), glm::vec3(0, 0, 0)), pos_(0, 0, 0)
{
	int i = 0;
}

GeoTransform::GeoTransform(glm::vec3& vec) : pos_(vec), scale_(1, 1, 1), q_(0, glm::vec3(0, 0, 0))
{
}

void GeoTransform::translate(glm::vec3 vec)
{
	pos_ += vec;
}

void GeoTransform::rotate(glm::vec3 vec, real theta)
{
	q_ = glm::qua<real>(theta, vec) * q_;
}

void GeoTransform::scale(glm::vec3 vec)
{
	scale_ *= vec;
}

void GeoTransform::scale(real s)
{
	scale_ *= s;
}

void GeoTransform::shader_set(Shader& shader)
{
	glm::mat4 model(1.0f);

	model = glm::scale(model, scale_);
	model = glm::mat4_cast(q_) * model;
	model = glm::translate(model, pos_);

	shader.setMat4("model", model);
}