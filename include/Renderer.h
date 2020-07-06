#pragma once
//#include <Camera.h>
#include <Shader.h>
#include <functional>
#include <GLFW/glfw3.h>

class Renderer
{
public:
	Renderer() :width(800), height(800) { init(); }
	Renderer(int w, int h) :width(w), height(h) { init(); }
	void init();
	void exec(std::function<void(void)> call_back);

	//void set_cam(Camera& c) { cam = &c; }

	Shader shader_;

	const int get_width() { return width; }
	const int get_height() { return height; }

private:
	int width;
	int height;

	static const size_t vbo_amount = 10;

	GLFWwindow* window;


	//void processInput(GLFWwindow* window);
};
