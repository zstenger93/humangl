#include "../includes/matrixStack.hpp"

MatrixStack::MatrixStack() { matrixStack.push(glm::mat4(1.0f)); }

void MatrixStack::pushMatrix() { matrixStack.push(matrixStack.top()); }

void MatrixStack::popMatrix() {
	if (matrixStack.size() > 1) matrixStack.pop();
}

void MatrixStack::translate(const glm::vec3 &translation) {
	matrixStack.top() = glm::translate(matrixStack.top(), translation);
}

void MatrixStack::rotate(float angle, const glm::vec3 &axis) {
	matrixStack.top() = glm::rotate(matrixStack.top(), glm::radians(angle), axis);
}

void MatrixStack::scale(const glm::vec3 &scaleFactors) {
	matrixStack.top() = glm::scale(matrixStack.top(), scaleFactors);
}

glm::mat4 MatrixStack::getModelMatrix() const { return matrixStack.top(); }
