#include "../includes/includes.hpp"

void mainLoop(GLFWwindow *window) {
  Cube Human;
  
  while (!glfwWindowShouldClose(window)) {
    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(window);
    glfwPollEvents();
  }
}

void initGLEW(GLFWwindow *window) {
  if (!window) {
    std::cerr << "Failed to create GLFW window" << std::endl;
    glfwTerminate();
    exit(1);
  }
  glfwMakeContextCurrent(window);
  if (glewInit() != GLEW_OK) {
    std::cerr << "Failed to initialize GLEW" << std::endl;
    glfwTerminate();
    exit(1);
  }
}

void initGLFW() {
  if (!glfwInit()) {
    std::cerr << "Failed to initialize GLFW" << std::endl;
    exit(1);
  }
}

int main() {
  initGLFW();
  GLFWwindow *window =
      glfwCreateWindow(1920, 1080, "HumanGL", nullptr, nullptr);
  initGLEW(window);
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
  mainLoop(window);
  return 0;
}