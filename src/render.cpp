#include "includes/render.hpp"

#include <iostream>

#include "includes/camera.hpp"
#include "includes/keyPress.hpp"
#include "includes/object.hpp"
#define STB_IMAGE_IMPLEMENTATION
#include "includes/texture.hpp"
#define STB_IMAGE_IMPLEMENTATION
#include "includes/slider.hpp"

void renderingLoop(GLFWwindow *window, Shader &shader, Camera &camera, Object &object) {
	int version = 1;
	int light = 2;
	int prevTex = -1;
	glm::vec3 color(1.0f, 0.0f, 0.0f);
	Cube *human = new Cube();
	Sliders sliders;

	initHuman(human);
	humanSettings(human);
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
		humanAnimations(window, human);
		object.Triangles = humanGLLogic(window, object, human);
		glBindBuffer(GL_ARRAY_BUFFER, object.VBO_triangles);
		glBufferData(GL_ARRAY_BUFFER, object.Triangles.size() * sizeof(float),
					 object.Triangles.data(), GL_STATIC_DRAW);
		if (human->_inAnimation != true)
			drawSliderMenu(human, sliders);
		renderText(window, object, color);
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	clearLeaks(human);
	delete human;
}
