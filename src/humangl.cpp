#include "../includes/camera.hpp"
#include "../includes/glfw.hpp"
#include "../includes/headers.hpp"
#include "../includes/object.hpp"

Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));

int main(int argc, char **argv) {

	Object object;

	initGLFW();

	GLFWwindow *window = createWindow(object);

	while (!glfwWindowShouldClose(window)) {
		// glfwSwapBuffers(window);
		glfwPollEvents();
	}


	return 0;
}

void mouse_callback(GLFWwindow *window, double xposIn, double yposIn) {
	float xpos = static_cast<float>(xposIn);
	float ypos = static_cast<float>(yposIn);

	if (camera.firstMouse) {
		camera.lastX = xpos;
		camera.lastY = ypos;
		camera.firstMouse = false;
	}
	float xoffset = xpos - camera.lastX;
	float yoffset = camera.lastY - ypos;

	camera.lastX = xpos;
	camera.lastY = ypos;
	camera.ProcessMouseMovement(xoffset, yoffset);
}

void scroll_callback(GLFWwindow *window, double xoffset, double yoffset) {
	camera.ProcessMouseScroll(static_cast<float>(yoffset));
}
