#pragma once
//#include <Camera.h>
#include <Shader.h>
#include <functional>
#include <GLFW/glfw3.h>

#include "Camera.h"
#include "Scene.h"

class Renderer
{
public:
	Renderer() :width(1200), height(1200) { init(); }
	Renderer(int w, int h) :width(w), height(h) { init(); }

	void init();
	void exec(std::function<void(void)> call_back = [] {});

	void add_Shader(const Shader& shader);
	void add_scene(const Scene&& scene) { scenes_.push_back(scene); }

private:
	int width;
	int height;

	std::vector<Scene> scenes_;

	Camera* cam;
	std::vector<Shader> shaders_;

	GLFWwindow* window;

	float deltaTime = 0.0f;
	float lastFrame = 0.0f;
	void processInput(GLFWwindow* window);

	static float xoffset;
	static float yoffset; // reversed since y-coordinates go from bottom to top

	static void mouse_callback(GLFWwindow* window, double xpos, double ypos);
};
