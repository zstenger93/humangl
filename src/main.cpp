#include "../includes/cube.hpp"

void addBodyParts(Cube &Human) {
  Cube LeftHand(glm::vec3(-0.5, 0.0, 0.0), -1, 0, 1);
  Cube RightHand(glm::vec3(0.5, 0.0, 0.0), 1, 0, 2);
  Cube LeftLeg(glm::vec3(-0.3, -0.5, 0.0), -1, -1, 3);
  Cube RightLeg(glm::vec3(0.3, -0.5, 0.0), 1, -1, 4);
  Cube Head(glm::vec3(0.0, 0.5, 0.0), 0, 1, 5);
  Human._cubes.push_back(LeftHand);
  Human._cubes.push_back(RightHand);
  Human._cubes.push_back(LeftLeg);
  Human._cubes.push_back(RightLeg);
  Human._cubes.push_back(Head);
}

void mainLoop(GLFWwindow *window) {
  Cube Human;
  addBodyParts(Human);
  cout << Human._cubes.size() << endl;
  while (!glfwWindowShouldClose(window)) {
    glClear(GL_COLOR_BUFFER_BIT);
    Human.drawCube();
    glfwSwapBuffers(window);
    glfwPollEvents();
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
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
  mainLoop(window);
  glfwDestroyWindow(window);
  glfwTerminate();
  return 0;
}