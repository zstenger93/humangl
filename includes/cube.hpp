#ifndef CUBE_HPP
#define CUBE_HPP

#include "includes.hpp"

class Cube {
public:
  glm::vec3 _rotationPoint;
  std::vector<glm::vec3> _points;
  std::vector<glm ::ivec3> _triangles;
  std::vector<Cube> _cubes;
  float _color;
  Cube();
  ~Cube();
  void generateTheCube(float offset);
  Cube(glm::vec3 connectionPoint, int directionX, int directionY, float color);
  void drawCube();
  void CubeHelper();
  void generateTheCube(float offset);
  void rotateCube(glm::vec3 angle);
};

#endif