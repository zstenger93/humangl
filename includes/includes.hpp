#ifndef INCLUDES_HPP
#define INCLUDES_HPP

#include <algorithm>
#include <exception>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::string;
using std::vector;

#include <GL/glew.h>
#ifdef __APPLE__
#include <OpenGL/gl.h>
#else
#include <GL/gl.h>
#endif

#include <GLFW/glfw3.h>
// const GLuint ShaderError = static_cast<GLuint>(-1);
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#endif