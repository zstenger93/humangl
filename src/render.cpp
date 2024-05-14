#include "includes/render.hpp"

#include <iostream>

#include "includes/camera.hpp"
#include "includes/keyPress.hpp"
#include "includes/object.hpp"
#define STB_IMAGE_IMPLEMENTATION
#include "includes/texture.hpp"
#define STB_IMAGE_IMPLEMENTATION
#include "includes/slider.hpp"



























std::vector<float> humanGLLogic(Object &object) {
	std::vector<float> newPoints;
	
	
	return newPoints;
}

void renderingLoop(GLFWwindow *window, Shader &shader, Camera &camera, Object &object) {
	int version = 1;
	int light = 2;
	int prevTex = -1;
	glm::vec3 color(1.0f, 0.0f, 0.0f);
	while (!glfwWindowShouldClose(window)) {
		createTexture(object, prevTex);
		camera.fps(camera);
		keyPressHandler(window, version, camera, object, shader, color);
		shader.settings(object);
		shader.use();
		shader.setTexture_OR_setColor(shader, version, color, light);
		shader.setModel(camera, shader, object.model);
		shader.setPerspective(camera, shader);
		shader.setView(camera, shader);
		draw(object);
		static int x = 0;
		if (x < 1) {
			size_t cubesize = object.Triangles.size();
			for (int i = 0; i < cubesize; i++) {
					object.Triangles.push_back(object.Triangles[i] + 2.0);
				std::cout << object.Triangles[i] << std::endl;
				if (i != 0 && i % 4 == 0) {
					// std::cout << std::endl;
				}
			}
			x++;
		}
		glBindBuffer(GL_ARRAY_BUFFER, object.VBO_triangles);
		glBufferData(GL_ARRAY_BUFFER, object.Triangles.size() * sizeof(float),
					 object.Triangles.data(), GL_STATIC_DRAW);

		drawSliderMenu(window);

		renderText(window, object, color);
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
}
