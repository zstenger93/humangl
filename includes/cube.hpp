#ifndef CUBE_HPP
#define CUBE_HPP

#include "includes.hpp"

class Cube {
public:
  glm::vec3 _rotationPoint;
  std::vector<glm::vec3> _points;
  std::vector<glm ::ivec3> _triangles;
  std::vector<Cube> _cubes;
  Cube();
  ~Cube();
  void generateTheCube();
};

#endif