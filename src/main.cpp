#include "../includes/cube.hpp"
#include "../includes/globals.hpp"

float g_proportion = 1.777f;

void addBodyParts(Cube &Human) {
  Cube LeftHandTop(glm::vec3(-DEF, 0.0, 0.0), -1, 0, 2);
  Cube RightHandTop(glm::vec3(DEF, 0.0, 0.0), 1, 0, 3);
  Cube LeftLegTop(glm::vec3(-DEF / 2, -DEF, 0.0), -1, -1, 4);
  Cube RightLegTop(glm::vec3(DEF / 2, -DEF, 0.0), 1, -1, 5);
  Cube Head(glm::vec3(0.0, DEF, 0.0), 0, 1, 6);
  Cube LeftHandBottom(glm::vec3(-3 * DEF, 0.0, 0.0), -1, 0, 7);
  Cube RightHandBottom(glm::vec3(3 * DEF, 0.0, 0.0), 1, 0, 8);
  Cube LeftLegBottom(glm::vec3(-DEF / 2, -3 * DEF, 0.0), -1, -1, 9);
  Cube RightLegBottom(glm::vec3(DEF / 2, -3 * DEF, 0.0), 1, -1, 10);
  LeftHandTop._cubes.push_back(LeftHandBottom);
  RightHandTop._cubes.push_back(RightHandBottom);
  LeftLegTop._cubes.push_back(LeftLegBottom);
  RightLegTop._cubes.push_back(RightLegBottom);
  Human._cubes.push_back(Head);
  Human._cubes.push_back(LeftHandTop);
  Human._cubes.push_back(RightHandTop);
  Human._cubes.push_back(LeftLegTop);
  Human._cubes.push_back(RightLegTop);
}

void changeWindowSize(GLFWwindow *window, int width, int height) {
  glViewport(0, 0, width, height);
  g_proportion = static_cast<float>(width) / static_cast<float>(height);
  (void)window;
}

void mainLoop(GLFWwindow *window) {
  Cube Human;
  addBodyParts(Human);
  glfwSetFramebufferSizeCallback(window, changeWindowSize);
  while (!glfwWindowShouldClose(window)) {
    glClear(GL_COLOR_BUFFER_BIT);
    Human.drawCube();
    Human.rotateCube(glm::vec3(0.01, 0.01, 0.01));
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