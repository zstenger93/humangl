#include "../includes/cube.hpp"
#include "../includes/globals.hpp"
#include "../includes/includes.hpp"

void Cube::generateTheCube(float offset) {
  _points.reserve(8);
  _points.push_back(glm::vec3(-DEF + offset, -DEF + offset, -DEF));
  _points.push_back(glm::vec3(DEF + offset, -DEF + offset, -DEF));
  _points.push_back(glm::vec3(DEF + offset, DEF + offset, -DEF));
  _points.push_back(glm::vec3(-DEF + offset, DEF + offset, -DEF));
  _points.push_back(glm::vec3(-DEF + offset, -DEF + offset, DEF));
  _points.push_back(glm::vec3(DEF + offset, -DEF + offset, DEF));
  _points.push_back(glm::vec3(DEF + offset, DEF + offset, DEF));
  _points.push_back(glm::vec3(-DEF + offset, DEF + offset, DEF));
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
  _color = 1;
  _rotationPoint = glm::vec3(0, 0, 0);
  generateTheCube(0);
}

Cube::Cube(glm::vec3 connectionPoint, int directionX, int directionY,
           float color)
    : _rotationPoint(connectionPoint), _color(color) {
  generateTheCube(0);
  for (auto &point : _points) {
    point.x += connectionPoint.x;
    point.y += connectionPoint.y;
    point.x += directionX * DEF;
    point.y += directionY * DEF;
  }
}

void Cube::CubeHelper() {
  glBegin(GL_TRIANGLES);
  for (size_t i = 0; i < _triangles.size(); ++i) {
    glm::ivec3 triangle = _triangles[i];
    glVertex3f(_points[triangle.x].x / g_proportion, _points[triangle.x].y,
               _points[triangle.x].z);
    glVertex3f(_points[triangle.y].x / g_proportion, _points[triangle.y].y,
               _points[triangle.y].z);
    glVertex3f(_points[triangle.z].x / g_proportion, _points[triangle.z].y,
               _points[triangle.z].z);
  }
  glEnd();
}

void Cube::drawCube() {
  glColor4f(1 / _color, 1 / _color, 1 / _color, 1.0f);
  CubeHelper();
  for (auto cubes : _cubes) {
    cubes.drawCube();
  }
}

void Cube::rotateCube(glm::vec3 angle) {
  for (auto &point : _points) {
    point.x -= angle.x;
    point.y -= angle.y;
    point.z -= angle.z;
  }
  for (auto &cube : _cubes) {
    cube.rotateCube(angle);
  }
}

Cube::~Cube() {}