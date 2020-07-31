#version 330
out vec4 FragColor;

in VS_OUT {
    vec3 FragPos;
    vec3 Normal;
    vec2 TexCoords;
    vec4 FragPosLightSpace;
} fs_in;

uniform vec3 viewPos;
uniform bool bling;


struct Material {
    sampler2D texture_diffuse1;
    sampler2D texture_specular1;
    sampler2D texture_normal1;
    sampler2D texture_height1;
    float shininess;
}; 


struct PointLight {
    vec3 position;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;

    float constant;
    float linear;
    float quadratic;
};

struct DirLight {
    vec3 direction;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;

};  

#define NR_POINT_LIGHTS 4
uniform PointLight pointLights[NR_POINT_LIGHTS];
uniform DirLight directionLights[NR_POINT_LIGHTS];
uniform sampler2D shadowMap[NR_POINT_LIGHTS];
//uniform sampler2D shadowMap[NR_POINT_LIGHTS];


uniform Material material;
float bias = 0.005;

float ShadowCalculation(vec4 fragPosLightSpace,int i)
{
    // 执行透视除法
    vec3 projCoords = fragPosLightSpace.xyz / fragPosLightSpace.w;
    projCoords = projCoords * 0.5 + 0.5;
    float closestDepth = texture(shadowMap[i], projCoords.xy).r;
    float currentDepth = projCoords.z;
    float shadow = currentDepth  -bias> closestDepth  ? 1.0 : 0.0;
    if(projCoords.z > 1.0)
        shadow = 0.0;


    return shadow;
}

vec3 CalcDirLight(DirLight light, vec3 normal, vec3 viewDir,int i)
{
    vec3 lightDir = normalize(-light.direction);
    // 漫反射着色
    float diff = max(dot(normal, lightDir), 0.0);
    // 镜面光着色
    vec3 reflectDir = reflect(-lightDir, normal);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
    // 合并结果
    vec3 ambient  = light.ambient  * vec3(texture(material.texture_diffuse1, fs_in.TexCoords));
    vec3 diffuse  = light.diffuse  * diff * vec3(texture(material.texture_diffuse1, fs_in.TexCoords));
    vec3 specular = light.specular * spec * vec3(texture(material.texture_specular1, fs_in.TexCoords));

    float shadow = ShadowCalculation(fs_in.FragPosLightSpace,i);  

    vec3 result= ambient + (1-shadow)*(diffuse + specular);
    result=vec3(max(0,result.x),max(0,result.y),max(0,result.z));
    return result;
}

vec3 CalcPointLight(PointLight light, vec3 normal, vec3 fragPos, vec3 viewDir)
{
    vec3 lightDir = normalize(light.position - fragPos);
    // 漫反射着色
    float diff = max(dot(normal, lightDir), 0.0);
    // 镜面光着色
    vec3 reflectDir = reflect(-lightDir, normal);
    vec3 halfwayDir = normalize(lightDir + viewDir);
    float spec;
    if(bling)
    {
        spec= pow(max(dot(halfwayDir, normal), 0.0), material.shininess);
    }
    else
    {
        spec = pow(max(dot(viewDir, reflectDir ), 0.0), material.shininess);
    }
    // 衰减
    float distance    = length(light.position - fragPos);
    float attenuation = 1.0 / (light.constant + light.linear * distance + 
                 light.quadratic * pow(distance ,2.2));    
    // 合并结果
    vec3 ambient  = light.ambient * vec3(texture(material.texture_diffuse1, fs_in.TexCoords));
    vec3 diffuse  = light.diffuse * diff * vec3(texture(material.texture_diffuse1, fs_in.TexCoords));
    vec3 specular = light.specular * spec * vec3(texture(material.texture_specular1, fs_in. TexCoords));
    ambient  *= attenuation;
    diffuse  *= attenuation;
    specular *= attenuation;
        vec3 result= (ambient + diffuse + specular);
    result=vec3(max(0,result.x),max(0,result.y),max(0,result.z));
    return result;
}


void main()
{
     // 属性
    vec3 norm = normalize(   fs_in.Normal);
    vec3 viewDir = normalize(viewPos - fs_in.FragPos);
    vec3 result= vec3(0.0f, 0.0f, 0.0f);
    // 第一阶段：定向光照
    for(int i = 0; i < NR_POINT_LIGHTS; i++)
        result += CalcDirLight(directionLights[i], norm, viewDir,i); 
    // 第二阶段：点光源
    for(int i = 0; i < NR_POINT_LIGHTS; i++)
        result += CalcPointLight(pointLights[i], norm, fs_in.FragPos,viewDir); 
    float gamma = 2.2;
    FragColor.rgb = pow(FragColor.rgb, vec3(1.0/gamma));
    FragColor = vec4(result, 1.0);
}