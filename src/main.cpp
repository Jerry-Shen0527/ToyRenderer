#include <Renderer.h>
#include <string>

const std::string shader_path = "C:\\Users\\Jerry\\WorkSpace\\ToyRenderer\\resources\\Shaders\\";

float vertices[] = {
    -0.5f, -0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
     0.0f,  0.5f, 0.0f
};

unsigned int indices[] = { // 注意索引从0开始! 
    0, 1, 2, // 第一个三角形
};



int main()
{
    Renderer r((shader_path + "Simple\\1.vert").c_str(), (shader_path + "Simple\\1.frag").c_str());

    r.get_vertex(vertices, 0, sizeof(vertices));
    r.get_element(indices, sizeof(indices));

    r.exec([] {});
}