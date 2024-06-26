#ifndef CUBE_HPP
#define CUBE_HPP

#include "headers.hpp"
#include "object.hpp"

class Cube {
   public:
	std::vector<glm::vec3> _points;
	std::vector<glm ::ivec3> _triangles;
	std::vector<Cube *> _cubes;
	Cube *_parentCube;
	int _parentCubeAttachmentPoint1Index;
	int _parentCubeAttachmentPoint2Index;
	int _childCubeAttachmentPoint1Index;
	int _childCubeAttachmentPoint2Index;
	int _animationMode;
	bool _inAnimation;
	glm::vec3 _baseScaleValue = glm::vec3(1.0f, 1.0f, 1.0f);
	glm::vec3 _baseAngle = glm::vec3(0.0f, 0.0f, 0.0f);
	Cube();
	~Cube();
	void generateCube();
	std::vector<Cube> recusiveCubes();
	Cube(Cube *parentCube, int parentCubeAttachmentPoint1, int parentCubeAttachemntPoint2,
		 int childCubeAttachmentPoint1, int childCubeAttachmentPoint2);
	void moveCube(glm::vec3 translation);
	glm::vec3 calculateTranslationCube();
	void rotateCube(glm::vec3 angle, glm::vec3 &rotationPoint);
	void rotateCubeHelper(glm::vec3 angle);
	void resizeCube(glm::vec3 scale);
	void resizeCubeHelper();
	void resetCubeAngle(int mode);
};

glm::vec3 calculateCenter(glm::vec3 &point1, glm::vec3 &point2);
glm::vec3 calculateTranslation(glm::vec3 point1, glm::vec3 point2);
std::vector<float> transformVectorToFloat(GLFWwindow *window, std::vector<Cube> cubes);
std::vector<float> humanGLLogic(GLFWwindow *window, Object &object, Cube *human);
void rotatePoint(glm::vec3 &point, glm::vec3 angle, glm::vec3 &rotationPoint);
void humanAnimations(GLFWwindow *window, Cube *human);
void initHuman(Cube *human);
void humanSettings(Cube *human);
void clearLeaks(Cube *human);
void walk(Cube *human, int i);
void run(Cube *human, int i);
void stand(Cube *human, int i);
void jump(Cube *human, int i);
void box(Cube *human, int i);
void kickBox(Cube *human, int i);

#endif