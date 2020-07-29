#pragma once
#include<AbstractModel.h>
enum class type
{
	model = 0,
	light = 1
};

class ModelFactory
{
public:
	std::unique_ptr<AbstractModel> get_model(type, std::string s="");
};
