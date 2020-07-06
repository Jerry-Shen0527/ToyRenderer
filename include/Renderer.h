#pragma once
#include <Camera.h>
#include <GLFW/glfw3.h>
#include <Shader.h>
#include <functional>

class Renderer
{
public:
	Renderer(const char* vs, const char* fs) :width(800), height(600) { init(vs, fs); }
	Renderer(const char* vs, const char* fs, int w, int h) :width(w), height(h) { init(vs, fs); }
	void init(const char* vs, const char* fs);
	void exec(std::function<void(void)> call_back);

	void set_cam(Camera& c) { cam = &c; }

	void get_vertex(float*, int idx);
	void get_element(unsigned int*);
	Shader shader_;

	const int get_width() { return width; }
	const int get_height() { return height; }

private:
	int width;
	int height;

	GLFWwindow* window;

	Camera* cam;

	unsigned VAO;
	unsigned VBO[10];
	unsigned EBO;

	void processInput(GLFWwindow* window);
};

