#include <AbstractLight.h>

class PointLight :public AbstractLight
{
public:
	PointLight() { init(); }
	PointLight(std::vector<Mesh>& meshes) : model_(meshes) { init(); }

	void init();

	Shader& get_shader();
	void set_model(Model& model);

	void add_light_to_shader(Shader& shader, int id) override;

	glm::vec3& get_pos();
	void translate(const glm::vec3& position);

	void draw();

	GeoTransform& get_geo();

	glm::vec3& get_color();
	//glm::vec3 color;
	//void set_color(const glm::vec3& color);
private:
	Model model_;
	Shader shader_;

	real constant;
	real linear;
	real quadratic;
};
