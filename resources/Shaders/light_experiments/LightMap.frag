#version 330
out vec4 FragColor;

in vec3 Normal;
in vec3 FragPos;
in vec2 TexCoords;

uniform vec3 viewPos;


struct Material {
    sampler2D texture_diffuse1;
    sampler2D texture_specular1;
    float shininess;
}; 

uniform Material material;

struct Light {
    vec3 position;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;

    float constant;
    float linear;
    float quadratic;
};

uniform Light light1;



void main()
{

    float distance    = length(light1.position - FragPos);
    float attenuation = 1.0 / (light1.constant + light1.linear * distance + light1.quadratic * (distance * distance));

    vec3 ambient  = light1.ambient * vec3(texture(material.texture_diffuse1, TexCoords));

    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(light1.position - FragPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse  = light1.diffuse * (diff *vec3(texture(material.texture_diffuse1, TexCoords)));

    vec3 viewDir = normalize(viewPos - FragPos);
    vec3 reflectDir = reflect(-lightDir, norm);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
    vec3 specular = light1.specular * (spec * vec3(texture(material.texture_specular1,TexCoords)));

    vec3 result =ambient +diffuse+specular;
    FragColor = vec4(result*attenuation, 1.0);
}