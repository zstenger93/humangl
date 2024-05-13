#ifndef CUBE_HPP
#define CUBE_HPP

#include "includes.hpp"
#include "matrix.hpp"

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
  void rotateCube(glm::vec3 angle, glm::vec3 &initialRotationPoint);
  std::vector<Cube> recusiveCubes();
  float getAverageCoordinate() const;
  void changeRotationPoint(glm::vec3 newRotationPoint);
};

#endif