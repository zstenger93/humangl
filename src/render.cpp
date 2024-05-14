#include "includes/render.hpp"

#include <iostream>

#include "includes/camera.hpp"
#include "includes/keyPress.hpp"
#include "includes/object.hpp"
#define STB_IMAGE_IMPLEMENTATION
#include "includes/texture.hpp"
#define STB_IMAGE_IMPLEMENTATION
#include "includes/slider.hpp"


class Cube
{
	public: 
		glm::vec3 _rotationPoint;
		std::vector<glm::vec3> _points;
		std::vector<glm ::ivec3> _triangles;
		std::vector<Cube> _cubes;

		Cube();
		~Cube();
		void generateCube();
};


void Cube::generateCube()
{
	_points.push_back(glm::vec3(0.0f, 0.0f, 0.0f));
	_points.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	_points.push_back(glm::vec3(1.0f, 1.0f, 0.0f));
	_points.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	_points.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	_points.push_back(glm::vec3(1.0f, 0.0f, 1.0f));
	_points.push_back(glm::vec3(1.0f, 1.0f, 1.0f));
	_points.push_back(glm::vec3(0.0f, 1.0f, 1.0f));

	_triangles.push_back(glm::ivec3(0, 1, 2));
	_triangles.push_back(glm::ivec3(0, 2, 3));
	_triangles.push_back(glm::ivec3(4, 5, 6));
	_triangles.push_back(glm::ivec3(4, 6, 7));
	_triangles.push_back(glm::ivec3(0, 1, 5));
	_triangles.push_back(glm::ivec3(0, 5, 4));
	_triangles.push_back(glm::ivec3(1, 2, 6));
	_triangles.push_back(glm::ivec3(1, 6, 5));
	_triangles.push_back(glm::ivec3(2, 3, 7));
	_triangles.push_back(glm::ivec3(2, 7, 6));
	_triangles.push_back(glm::ivec3(3, 0, 4));
	_triangles.push_back(glm::ivec3(3, 4, 7));
}

Cube::Cube()
{
	generateCube();
}


Cube::~Cube()
{
}

std::vector<float> transformVectorToFloat(Cube &human)
{
	std::vector<float> points;


	return points;
}

std::vector<float> humanGLLogic(Object &object, Cube &human) {
	std::vector<float> newPoints;
	object.Triangles.clear();
	
	
	return newPoints;
}

void renderingLoop(GLFWwindow *window, Shader &shader, Camera &camera, Object &object) {
	int version = 1;
	int light = 2;
	int prevTex = -1;
	glm::vec3 color(1.0f, 0.0f, 0.0f);
	Cube human;
	while (!glfwWindowShouldClose(window)) {
		createTexture(object, prevTex);
		camera.fps(camera);
		keyPressHandler(window, version, camera, object, shader, color);
		shader.settings(object);
		shader.use();
		shader.setTexture_OR_setColor(shader, version, color, light);
		shader.setModel(camera, shader, object.model);
		shader.setPerspective(camera, shader);
		shader.setView(camera, shader);
		draw(object);
		object.Triangles = humanGLLogic(object, human);
		glBindBuffer(GL_ARRAY_BUFFER, object.VBO_triangles);
		glBufferData(GL_ARRAY_BUFFER, object.Triangles.size() * sizeof(float),
					 object.Triangles.data(), GL_STATIC_DRAW);

		drawSliderMenu(window);

		renderText(window, object, color);
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
}
