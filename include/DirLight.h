#pragma once
#include <AbstractLight.h>

class DirLight:public AbstractLight
{
public:
	void add_light_to_shader(Shader& shader, int id) override;
	void draw() override;
	void get_shader() override;
};
