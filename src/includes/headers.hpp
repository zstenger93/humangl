#ifndef HEADERS_HPP
#define HEADERS_HPP

/*
	Header file collection for standard libraries and
	for installed extra libraries like GLFW, GLAD, GLM
*/
#define GL_SILENCE_DEPRECATION
#include <OpenGL/OpenGL.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <chrono>
#include <cmath>
#include <csignal>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <thread>
#include <vector>

#include "../includes/glad/glad.h"
#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"

#define WINDOW_WIDTH 3200
#define WINDOW_HEIGHT 1800

enum RenderMode { WIREFRAME, POINTS, FILLED };

struct Vertex {
	float x, y, z, texX, texY, normalX, normalY, normalZ;
};

struct Uv {
	float u, v, w;
};

struct Ka {
	float r, g, b;
};

struct Kd {
	float r, g, b;
};

struct Ks {
	float r, g, b;
};

struct Mtl {
	Ka ka;
	Kd kd;
	Ks ks;
	float Ns, Ni, d;
	int illum;
};

#endif