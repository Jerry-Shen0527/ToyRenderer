#version 330 core
out vec4 FragColor;

in vec3 Normal;
in vec3 FragPos;
uniform vec3 lightPos;


void main()
{
	FragColor=vec4(1.0f);
}