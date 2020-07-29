#pragma once
#include <Shader.h>

#include "GeoTransform.h"
#include "Mesh.h"

class AbstractModel
{
public:

	AbstractModel() {}

	virtual void draw(Shader& shader) = 0;

	virtual  ~AbstractModel() {}

public:
	GeoTransform& get_geo();

protected:
	GeoTransform geo_;
};
