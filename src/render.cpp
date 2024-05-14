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
		glm::vec3 _parentCubeAttachmentPoint;
		Cube *_parentCube;
		Cube();
		~Cube();
		void generateCube();
		std::vector<Cube> recusiveCubes();
		void renderHuman();
		void cubeSelectIVec();
		Cube(Cube &parentCube, glm::vec3 parentCubeAttachmentPoint, glm::vec3 childCubeAttachmentPoint);
		void moveCube(glm::vec3 translation);
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
	// Front face
	_triangles.push_back(glm::ivec3(0, 1, 2));
	_triangles.push_back(glm::ivec3(0, 2, 3));
	// Back face
	_triangles.push_back(glm::ivec3(4, 5, 6));
	_triangles.push_back(glm::ivec3(4, 6, 7));
	// Left face
	_triangles.push_back(glm::ivec3(0, 1, 5));
	_triangles.push_back(glm::ivec3(0, 5, 4));
	// Right face
	_triangles.push_back(glm::ivec3(1, 2, 6));
	_triangles.push_back(glm::ivec3(1, 6, 5));
	// Top face
	_triangles.push_back(glm::ivec3(2, 3, 7));
	_triangles.push_back(glm::ivec3(2, 7, 6));
	// Bottom face
	_triangles.push_back(glm::ivec3(3, 0, 4));
	_triangles.push_back(glm::ivec3(3, 4, 7));
}

std::vector<Cube> Cube::recusiveCubes() {
  std::vector<Cube> tempCubes;
  tempCubes.push_back(*this); 
  for (unsigned long i = 0; i < _cubes.size(); i++) {
    std::vector<Cube> temp = _cubes[i].recusiveCubes();
    tempCubes.insert(tempCubes.end(), temp.begin(), temp.end());
  }
  return tempCubes;
}

Cube::Cube()
{
	generateCube();
	_rotationPoint = glm::vec3(0.5f, 0.5f, 0.5f);
	_parentCubeAttachmentPoint = glm::vec3(0.5f, 0.5f, 0.5f);
	_parentCube = nullptr;
	Cube leftArm(*this, glm::vec3(0.0f, 1.0f, 0.5f), glm::vec3(1.0f, 1.0f, 0.5f));
	Cube rightArm(*this, glm::vec3(1.0f, 1.0f, 0.5f), glm::vec3(0.0f, 1.0f, 0.5f));
	Cube head(*this, glm::vec3(0.5f, 1.0f, 0.5f), glm::vec3(0.5f, 0.0f, 0.5f));
	Cube leftForeArm(leftArm, glm::vec3(0.0f, 0.5f, 0.5f), glm::vec3(1.0f, 0.5f, 0.5f));
	Cube rightForeArm(rightArm, glm::vec3(1.0f, 0.5f, 0.5f), glm::vec3(0.0f, 0.5f, 0.5f));
	leftArm._cubes.push_back(leftForeArm);
	rightArm._cubes.push_back(rightForeArm);
	_cubes.push_back(leftArm);
	_cubes.push_back(rightArm);
	_cubes.push_back(head);
}

glm::vec3 translateAttachmentPointToCoordinate(Cube &cube, glm::vec3 &attachmentPoint)
{
    glm::vec3 minPoint(FLT_MAX);
    glm::vec3 maxPoint(FLT_MIN);
    for (auto &point : cube._points)
    {
        minPoint = glm::min(minPoint, point);
        maxPoint = glm::max(maxPoint, point);
    }
    glm::vec3 size = maxPoint - minPoint;
    glm::vec3 translation = minPoint + size * attachmentPoint;
    return translation;
}

void Cube::moveCube(glm::vec3 translation)
{
	for (auto &point: _points)
	{
		point += translation;
	}
	for (auto &cube: _cubes)
	{
		cube.moveCube(translation);
	}
}

Cube::Cube(Cube &parentCube, glm::vec3 parentCubeAttachmentPoint, glm::vec3 childCubeAttachmentPoint)
{
	_parentCube = &parentCube;
	_parentCubeAttachmentPoint = parentCubeAttachmentPoint;
	_rotationPoint = childCubeAttachmentPoint;
	generateCube();
	glm::vec3 translationParent = translateAttachmentPointToCoordinate(parentCube, parentCubeAttachmentPoint);
	glm::vec3 trnaslationChild = translateAttachmentPointToCoordinate(*this, childCubeAttachmentPoint);
	moveCube(translationParent - trnaslationChild);
}


Cube::~Cube()
{
}

std::vector<float> transformVectorToFloat(std::vector<Cube> cubes)
{
	std::vector<float> points;
	for (unsigned long i = 0; i < cubes.size(); i++)
	{
		for (unsigned long j = 0; j < cubes[i]._triangles.size(); j++)
		{
			glm::ivec3 triangle = cubes[i]._triangles[j];
			glm::vec3 vertex1 = cubes[i]._points[triangle.x];
			glm::vec3 vertex2 = cubes[i]._points[triangle.y];
			glm::vec3 vertex3 = cubes[i]._points[triangle.z];
			points.push_back(vertex1.x);
			points.push_back(vertex1.y);
			points.push_back(vertex1.z);
			points.push_back(i / (float)cubes.size());
			points.push_back(i / (float)cubes.size());
			points.push_back(vertex2.x);
			points.push_back(vertex2.y);
			points.push_back(vertex2.z);
			points.push_back(i / (float)cubes.size());
			points.push_back(i / (float)cubes.size());
			points.push_back(vertex3.x);
			points.push_back(vertex3.y);
			points.push_back(vertex3.z);
			points.push_back(i / (float)cubes.size());
			points.push_back(i / (float)cubes.size());
		}
	}
	return points;
}

std::vector<float> humanGLLogic(Object &object, Cube &human) {
	std::vector<float> newPoints;
	object.Triangles.clear();
	std::vector<Cube> listOfCubes = human.recusiveCubes();
	newPoints = transformVectorToFloat(listOfCubes);
	return newPoints;
}


void Cube::renderHuman()
{
	moveCube(glm::vec3(0.01f, 0.0f, 0.0f));
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
		human.renderHuman();
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
