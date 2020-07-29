#include <memory>
#include <ModelFactory.h>
#include <Assimp_Loader.h>
#include <Model.h>

#include "Light.h"

std::unique_ptr<AbstractModel> ModelFactory::get_model(type t, std::string filename)
{
	std::unique_ptr<AbstractModel> ptr;
	if (filename.length() > 0)
	{
		AssimpLoader loader(filename);

		if (t == type::model)
		{
			ptr.reset(new Model(loader.get_meshes()));
		}
		else if (t == type::light)
		{
			ptr.reset(new Light(loader.get_meshes()));
		}
	}
	return  ptr;
}