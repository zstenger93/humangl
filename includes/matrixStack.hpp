#ifndef MATRIXSTACK_HPP
#define MATRIXSTACK_HPP

#include "headers.hpp"

class MatrixStack {
   public:
	MatrixStack();

	void pushMatrix();
	void popMatrix();
	void scale(const glm::vec3 &scaleFactors);
	void translate(const glm::vec3 &translation);
	void rotate(float angle, const glm::vec3 &axis);
	glm::mat4 getModelMatrix() const;

   private:
	std::stack<glm::mat4> matrixStack;
};

#endif