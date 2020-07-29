#version 330
out vec4 FragColor;

in vec3 Normal;
in vec3 FragPos;

uniform vec3 lightPos1;
uniform vec3 lightColor1;
uniform vec3 viewPos;

vec3 objectColor=vec3(1.0f, 0.5f, 0.31f);
float specularStrength = 0.5;


void main()
{
    float ambientStrength = 0.1;
    vec3 ambient = ambientStrength * objectColor;
    vec3 ambienColor = ambient * objectColor;

    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(lightPos1 - FragPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = diff * lightColor1;

    vec3 viewDir = normalize(viewPos - FragPos);
    vec3 reflectDir = reflect(-lightDir, norm);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 64);
    vec3 specular = specularStrength * spec * lightColor1;

    vec3 result = (ambient + diffuse+specular) * objectColor;
    FragColor = vec4(result, 1.0);
}