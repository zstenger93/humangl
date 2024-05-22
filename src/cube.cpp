#include <iostream>

#include "includes/camera.hpp"
#include "includes/keyPress.hpp"
#include "includes/object.hpp"
#include "includes/render.hpp"
#define STB_IMAGE_IMPLEMENTATION
#include "includes/texture.hpp"
#define STB_IMAGE_IMPLEMENTATION
#include "includes/slider.hpp"

void Cube::generateCube() {
	_points.reserve(8);
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

// this function is use to retive cubes
std::vector<Cube> Cube::recusiveCubes() {
	std::vector<Cube> tempCubes;
	tempCubes.push_back(*this);
	for (unsigned long i = 0; i < _cubes.size(); i++) {
		std::vector<Cube> temp = _cubes[i]->recusiveCubes();
		tempCubes.insert(tempCubes.end(), temp.begin(), temp.end());
	}
	return tempCubes;
}

// this functon initializes the body of cube
Cube::Cube() {
	generateCube();
	_parentCubeAttachmentPoint1Index = 0;
	_parentCubeAttachmentPoint2Index = 6;
	_parentCube = nullptr;
	_animationMode = 0;
}

Cube::~Cube() {}

Cube::Cube(Cube &parentCube, int parentCubeAttachmentPoint1, int parentCubeAttachemntPoint2,
		   int childCubeAttachmentPoint1, int childCubeAttachmentPoint2) {
	generateCube();
	_parentCube = &parentCube;
	_parentCubeAttachmentPoint1Index = parentCubeAttachmentPoint1;
	_parentCubeAttachmentPoint2Index = parentCubeAttachemntPoint2;
	_childCubeAttachmentPoint1Index = childCubeAttachmentPoint1;
	_childCubeAttachmentPoint2Index = childCubeAttachmentPoint2;
	moveCube(calculateTranslationCube());
}
// this function is used to move the cube
glm::vec3 calculateCenter(glm::vec3 &point1, glm::vec3 &point2) {
	return glm::vec3((point1.x + point2.x) / 2, (point1.y + point2.y) / 2,
					 (point1.z + point2.z) / 2);
}

glm::vec3 calculateTranslation(glm::vec3 point1, glm::vec3 point2) {
	return glm::vec3(point2.x - point1.x, point2.y - point1.y, point2.z - point1.z);
}

glm::vec3 Cube::calculateTranslationCube() {
	if (_parentCube == nullptr)
		return calculateTranslation(_points[_childCubeAttachmentPoint1Index],
									_points[_parentCubeAttachmentPoint2Index]);
	glm::vec3 parentPoint = calculateCenter(_parentCube->_points[_parentCubeAttachmentPoint1Index],
											_parentCube->_points[_parentCubeAttachmentPoint2Index]);
	glm::vec3 childPoint = calculateCenter(_points[_childCubeAttachmentPoint1Index],
										   _points[_childCubeAttachmentPoint2Index]);
	glm::vec3 translation = calculateTranslation(childPoint, parentPoint);
	return translation;
}

void Cube::centerCube() {
	if (_parentCube == nullptr) {
		glm::vec3 center = glm::vec3(0.0f, 0.0f, 0.0f);
		moveCube(calculateTranslation(center,
									  calculateCenter(_points[_childCubeAttachmentPoint1Index],
													  _points[_childCubeAttachmentPoint2Index])));
		return;
	}
}

void Cube::moveCube(glm::vec3 translation) {
	for (unsigned long i = 0; i < _points.size(); i++) {
		_points[i] += translation;
	}
	for (auto &cube : _cubes) {
		cube->moveCube(translation);
	}
}

void Cube::resizeCubeHelper() {
	moveCube(calculateTranslationCube());
	for (auto &cube : _cubes) {
		cube->resizeCubeHelper();
	}
}

void Cube::resizeCube(glm::vec3 scale) {
	for (unsigned long i = 0; i < _points.size(); i++) {
		_points[i].x *= scale.x / _baseScaleValue.x;
		_points[i].y *= scale.y / _baseScaleValue.y;
		_points[i].z *= scale.z / _baseScaleValue.z;
	}
	_baseScaleValue = scale;
	resizeCubeHelper();
}

std::vector<float> transformVectorToFloat(std::vector<Cube> cubes) {
	std::vector<float> points;
	for (unsigned long i = 0; i < cubes.size(); i++) {
		for (unsigned long j = 0; j < cubes[i]._triangles.size(); j++) {
			glm::ivec3 triangle = cubes[i]._triangles[j];
			glm::vec3 vertex1 = cubes[i]._points[triangle.x];
			glm::vec3 vertex2 = cubes[i]._points[triangle.y];
			glm::vec3 vertex3 = cubes[i]._points[triangle.z];
			points.push_back(vertex1.x);
			points.push_back(vertex1.y);
			points.push_back(vertex1.z);
			points.push_back(0);
			points.push_back(0);
			points.push_back(vertex2.x);
			points.push_back(vertex2.y);
			points.push_back(vertex2.z);
			points.push_back(0);
			points.push_back(1);
			points.push_back(vertex3.x);
			points.push_back(vertex3.y);
			points.push_back(vertex3.z);
			points.push_back(1);
			points.push_back(0);
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

void rotatePoint(glm::vec3 &point, glm::vec3 angle, glm::vec3 &rotationPoint) {
	float x, y, z, temp_y, temp_x, temp_z;
	point -= rotationPoint;
	glm::vec3 rad = glm::radians(angle);
	// x
	temp_y = point.y;
	temp_z = point.z;
	y = temp_y * cos(rad.x) - temp_z * sin(rad.x);
	z = temp_y * sin(rad.x) + temp_z * cos(rad.x);

	// y
	temp_x = point.x;
	temp_z = z;
	x = temp_x * cos(rad.y) + temp_z * sin(rad.y);
	z = -temp_x * sin(rad.y) + temp_z * cos(rad.y);

	// z
	temp_x = x;
	temp_y = y;
	x = temp_x * cos(rad.z) - temp_y * sin(rad.z);
	y = temp_x * sin(rad.z) + temp_y * cos(rad.z);

	point.x = x;
	point.y = y;
	point.z = z;
	point += rotationPoint;
}

void Cube::rotateCube(glm::vec3 angle, glm::vec3 &rotationPoint) {
	for (unsigned long i = 0; i < _points.size(); i++) {
		rotatePoint(_points[i], angle, rotationPoint);
	}
	for (auto &cube : _cubes) {
		cube->rotateCube(angle, rotationPoint);
	}
}

void Cube::rotateCubeHelper(glm::vec3 angle) {
	glm::vec3 rotationPoint = calculateCenter(_points[_childCubeAttachmentPoint1Index],
											  _points[_childCubeAttachmentPoint2Index]);
	rotateCube(angle, rotationPoint);
}

void walk(Cube &human, int i) {
	if (i < 20) {
		human._cubes[0]->rotateCubeHelper(glm::vec3(1.0f, 0.0f, 00.0f));
		human._cubes[1]->rotateCubeHelper(glm::vec3(-1.0f, 0.0f, 00.0f));
		human._cubes[2]->rotateCubeHelper(glm::vec3(1.0f, 0.0f, 00.0f));
		human._cubes[3]->rotateCubeHelper(glm::vec3(-1.0f, 0.0f, 00.0f));
	}
	if (i > 20 && i < 60) {
		human._cubes[0]->rotateCubeHelper(glm::vec3(-1.0f, 0.0f, 00.0f));
		human._cubes[1]->rotateCubeHelper(glm::vec3(1.0f, 0.0f, 00.0f));
		human._cubes[2]->rotateCubeHelper(glm::vec3(-1.0f, 0.0f, 00.0f));
		human._cubes[3]->rotateCubeHelper(glm::vec3(1.0f, 0.0f, 00.0f));
	}
	if (i > 60 && i < 80) {
		human._cubes[0]->rotateCubeHelper(glm::vec3(1.0f, 0.0f, 00.0f));
		human._cubes[1]->rotateCubeHelper(glm::vec3(-1.0f, 0.0f, 00.0f));
		human._cubes[2]->rotateCubeHelper(glm::vec3(1.0f, 0.0f, 00.0f));
		human._cubes[3]->rotateCubeHelper(glm::vec3(-1.0f, 0.0f, 00.0f));
	}
}

void run(Cube &human, int i) {
	if (i < 20) {
		human._cubes[0]->rotateCubeHelper(glm::vec3(3.0f, 0.0f, 0.0f));
		human._cubes[1]->rotateCubeHelper(glm::vec3(-3.0f, 0.0f, 0.0f));
		human._cubes[2]->rotateCubeHelper(glm::vec3(3.0f, 0.0f, 0.0f));
		human._cubes[3]->rotateCubeHelper(glm::vec3(-3.0f, 0.0f, 0.0f));
		human._cubes[1]->_cubes[0]->rotateCubeHelper(glm::vec3(-5.0f, 0.0f, 0.0f));
	} else if (i < 60) {
		human._cubes[0]->rotateCubeHelper(glm::vec3(-3.0f, 0.0f, 0.0f));
		human._cubes[1]->rotateCubeHelper(glm::vec3(3.0f, 0.0f, 0.0f));
		human._cubes[2]->rotateCubeHelper(glm::vec3(-3.0f, 0.0f, 0.0f));
		human._cubes[3]->rotateCubeHelper(glm::vec3(3.0f, 0.0f, 0.0f));
		if (i < 40)
			human._cubes[1]->_cubes[0]->rotateCubeHelper(glm::vec3(5.0f, 0.0f, 0.0f));
		else if (i < 100)
			human._cubes[0]->_cubes[0]->rotateCubeHelper(glm::vec3(-5.0f, 0.0f, 0.0f));
	} else if (i < 80) {
		human._cubes[0]->rotateCubeHelper(glm::vec3(3.0f, 0.0f, 0.0f));
		human._cubes[1]->rotateCubeHelper(glm::vec3(-3.0f, 0.0f, 0.0f));
		human._cubes[2]->rotateCubeHelper(glm::vec3(3.0f, 0.0f, 0.0f));
		human._cubes[3]->rotateCubeHelper(glm::vec3(-3.0f, 0.0f, 0.0f));
		human._cubes[0]->_cubes[0]->rotateCubeHelper(glm::vec3(5.0f, 0.0f, 0.0f));
	}
}

void jump(Cube &human, int i) {
	if (i < 20) {
		human._cubes[0]->rotateCubeHelper(glm::vec3(0.0f, 0.0f, -3.0f));
		human._cubes[1]->rotateCubeHelper(glm::vec3(0.0f, 0.0f, 3.0f));
		human._cubes[2]->rotateCubeHelper(glm::vec3(0.0f, 0.0f, 3.0f));
		human._cubes[3]->rotateCubeHelper(glm::vec3(0.0f, 0.0f, -3.0f));
	} else if (i < 40) {
		human._cubes[0]->rotateCubeHelper(glm::vec3(0.0f, 0.0f, 3.0f));
		human._cubes[1]->rotateCubeHelper(glm::vec3(0.0f, 0.0f, -3.0f));
		human._cubes[2]->rotateCubeHelper(glm::vec3(0.0f, 0.0f, -3.0f));
		human._cubes[3]->rotateCubeHelper(glm::vec3(0.0f, 0.0f, 3.0f));
	} else if (i < 60) {
		human._cubes[0]->rotateCubeHelper(glm::vec3(0.0f, 0.0f, -3.0f));
		human._cubes[1]->rotateCubeHelper(glm::vec3(0.0f, 0.0f, 3.0f));
		human._cubes[2]->rotateCubeHelper(glm::vec3(0.0f, 0.0f, 3.0f));
		human._cubes[3]->rotateCubeHelper(glm::vec3(0.0f, 0.0f, -3.0f));
	} else if (i < 80) {
		human._cubes[0]->rotateCubeHelper(glm::vec3(0.0f, 0.0f, 3.0f));
		human._cubes[1]->rotateCubeHelper(glm::vec3(0.0f, 0.0f, -3.0f));
		human._cubes[2]->rotateCubeHelper(glm::vec3(0.0f, 0.0f, -3.0f));
		human._cubes[3]->rotateCubeHelper(glm::vec3(0.0f, 0.0f, 3.0f));
	}
}

void stand(Cube &human, int i) {
	(void)i;
	return;
}

void renderHuman(Cube &human) {
	static int i = 0;
	static int animationLoop = 0;
	if (i == 40) {
		animationLoop = human._animationMode;
		human._animationMode += 1;
		human._animationMode %= 4;
	}
	if (animationLoop == 0)
		run(human, i);
	else if (animationLoop == 1)
		walk(human, i);
	else if (animationLoop == 2)
		stand(human, i);
	else if (animationLoop == 3)
		jump(human, i);
	i++;
	if (i > 80) i = 0;
}

void initHuman(Cube &human) {
	Cube *leftArm = new Cube(human, 3, 7, 2, 6);
	Cube *rightArm = new Cube(human, 2, 6, 3, 7);
	Cube *rightLeg = new Cube(human, 0, 5, 3, 7);
	Cube *leftLeg = new Cube(human, 0, 5, 2, 6);
	Cube *head = new Cube(human, 3, 6, 0, 5);
	Cube *leftShin = new Cube(*leftLeg, 0, 5, 3, 6);
	Cube *rightShin = new Cube(*rightLeg, 0, 5, 3, 6);
	Cube *leftForeArm = new Cube(*leftArm, 0, 7, 1, 6);
	Cube *rightForeArm = new Cube(*rightArm, 1, 6, 0, 7);
	leftArm->_cubes.push_back(leftForeArm);
	rightArm->_cubes.push_back(rightForeArm);
	leftLeg->_cubes.push_back(leftShin);
	rightLeg->_cubes.push_back(rightShin);
	human._cubes.push_back(leftArm);
	human._cubes.push_back(rightArm);
	human._cubes.push_back(rightLeg);
	human._cubes.push_back(leftLeg);
	human._cubes.push_back(head);
}

void humanSettings(Cube &human) {
	human.centerCube();
	human.resizeCube(glm::vec3(2.0f, 4.0f, 2.0f));
	human._cubes[0]->resizeCube(glm::vec3(2.5f, 1.0f, 1.0f));
	human._cubes[0]->_cubes[0]->resizeCube(glm::vec3(2.5f, 1.0f, 1.0f));
	human._cubes[0]->rotateCubeHelper(glm::vec3(180.0f, 0.0f, 90.0f));
	human._cubes[1]->resizeCube(glm::vec3(2.5f, 1.0f, 1.0f));
	human._cubes[1]->_cubes[0]->resizeCube(glm::vec3(2.5f, 1.0f, 1.0f));
	human._cubes[1]->rotateCubeHelper(glm::vec3(180.0f, 0.0f, 270.0f));
	human._cubes[2]->resizeCube(glm::vec3(1.0f, 2.0f, 1.0f));
	human._cubes[3]->resizeCube(glm::vec3(1.0f, 2.0f, 1.0f));
	human._cubes[2]->_cubes[0]->resizeCube(glm::vec3(1.0f, 2.0f, 1.0f));
	human._cubes[3]->_cubes[0]->resizeCube(glm::vec3(1.0f, 2.0f, 1.0f));
	human._cubes[4]->resizeCube(glm::vec3(1.2f, 1.2f, 1.2f));
}

void clearLeaks(Cube &human) {
	for (auto &cube : human._cubes) {
		clearLeaks(*cube);
		delete cube;
	}
}
