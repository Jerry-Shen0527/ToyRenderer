#include <iostream>
#include <Renderer.h>
float deltaTime = 0.0f;
float lastFrame = 0.0f;

float lastX = 0;
float lastY = 0;
bool firstMouse = true;

float Renderer::xoffset;
float Renderer::yoffset;

void Renderer::mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
	if (firstMouse)
	{
		lastX = xpos;
		lastY = ypos;
		firstMouse = false;
	}

	xoffset = xpos - lastX;
	yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top

	lastX = xpos;
	lastY = ypos;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void Renderer::init()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	window = glfwCreateWindow(width, height, "OpenGL", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return;
	}
	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	glfwSetCursorPosCallback(window, mouse_callback);

	// tell GLFW to capture our mouse
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	// glad: load all OpenGL function pointers
	// ---------------------------------------
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return;
	}
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	//GLuint depthMapFBO;
	//glGenFramebuffers(1, &depthMapFBO);

	//const GLuint SHADOW_WIDTH = 1024, SHADOW_HEIGHT = 1024;

	//GLuint depthMap;
	//glGenTextures(1, &depthMap);
	//glBindTexture(GL_TEXTURE_2D, depthMap);
	//glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT, SHADOW_WIDTH, SHADOW_HEIGHT, 0, GL_DEPTH_COMPONENT, GL_FLOAT, NULL);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	//glBindFramebuffer(GL_FRAMEBUFFER, depthMapFBO);
	//glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, depthMap, 0);
	//glDrawBuffer(GL_NONE);
	//glReadBuffer(GL_NONE);
	//glBindFramebuffer(GL_FRAMEBUFFER, 0);
	//// 1. 首选渲染深度贴图
	//glViewport(0, 0, SHADOW_WIDTH, SHADOW_HEIGHT);
	//glBindFramebuffer(GL_FRAMEBUFFER, depthMapFBO);
	//glClear(GL_DEPTH_BUFFER_BIT);
	//ConfigureShaderAndMatrices();
	//RenderScene();
	//glBindFramebuffer(GL_FRAMEBUFFER, 0);
	//// 2. 像往常一样渲染场景，但这次使用深度贴图
	//glViewport(0, 0, SCR_WIDTH, SCR_HEIGHT);
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//ConfigureShaderAndMatrices();
	//glBindTexture(GL_TEXTURE_2D, depthMap);
}

void Renderer::exec(std::function<void(void)> call_back)
{
	cam = &scenes_.front().get_cam();
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	//by default
	auto shader_ = shaders_[0];
	//shader_.use();
	while (!glfwWindowShouldClose(window))
	{
		glClearColor(float(37 / 255.0), float(37 / 255.0), float(38 / 255.0), 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		float currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;

		call_back();

		for (auto scene : scenes_)
		{
			scene.draw(shader_, width, height);
		}
		processInput(window);
		cam->ProcessMouseMovement(xoffset, yoffset);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return;
}

void Renderer::add_Shader(const Shader& shader)
{
	shaders_.push_back(shader);
}

void Renderer::processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);

	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);

	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		cam->ProcessKeyboard(FORWARD, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		cam->ProcessKeyboard(BACKWARD, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		cam->ProcessKeyboard(LEFT, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		cam->ProcessKeyboard(RIGHT, deltaTime);

	if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
		cam->ProcessKeyboard(UP, deltaTime);

	if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
		cam->ProcessKeyboard(DOWN, deltaTime);

	if (glfwGetKey(window, GLFW_KEY_B) == GLFW_PRESS)
		shaders_[0].setBool("bling", true);
	if (glfwGetKey(window, GLFW_KEY_P) == GLFW_PRESS)
		shaders_[0].setBool("bling", false);
}