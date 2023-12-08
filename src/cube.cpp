#include "../includes/cube.hpp"
#include "../includes/includes.hpp"

void Cube::generateTheCube() {
  _points.reserve(8);
  float defCubeSize = 0.5f;
  _points.push_back(glm::vec3(-defCubeSize, -defCubeSize, -defCubeSize));
  _points.push_back(glm::vec3(defCubeSize, -defCubeSize, -defCubeSize));
  _points.push_back(glm::vec3(defCubeSize, defCubeSize, -defCubeSize));
  _points.push_back(glm::vec3(-defCubeSize, defCubeSize, -defCubeSize));
  _points.push_back(glm::vec3(-defCubeSize, -defCubeSize, defCubeSize));
  _points.push_back(glm::vec3(defCubeSize, -defCubeSize, defCubeSize));
  _points.push_back(glm::vec3(defCubeSize, defCubeSize, defCubeSize));
  _points.push_back(glm::vec3(-defCubeSize, defCubeSize, defCubeSize));
  _triangles.reserve(12);
  _triangles.push_back(glm::ivec3(0, 1, 2));
  _triangles.push_back(glm::ivec3(2, 3, 0));
  _triangles.push_back(glm::ivec3(4, 5, 6));
  _triangles.push_back(glm::ivec3(6, 7, 4));
  _triangles.push_back(glm::ivec3(0, 3, 7));
  _triangles.push_back(glm::ivec3(7, 4, 0));
  _triangles.push_back(glm::ivec3(1, 5, 6));
  _triangles.push_back(glm::ivec3(6, 2, 1));
  _triangles.push_back(glm::ivec3(3, 2, 6));
  _triangles.push_back(glm::ivec3(6, 7, 3));
  _triangles.push_back(glm::ivec3(0, 1, 5));
  _triangles.push_back(glm::ivec3(5, 4, 0));
}

Cube::Cube() {
  _rotationPoint = glm::vec3(0, 0, 0);
  generateTheCube();
}

Cube::~Cube() {}