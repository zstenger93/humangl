#ifndef OBJECT_HPP
#define OBJECT_HPP

#include "camera.hpp"
#include "headers.hpp"
#include "text.hpp"

class Object {
   public:
	Mtl mtl;				// material file content
	Text text;				// for text drawing to screen
	int polyCount;			// counted from file
	std::vector<Uv> uv;		// vt aka uv coordinates
	int textureType = 0;	// switching between textures
	unsigned int texture;	// texture used for the object
	bool hasSlash = false;	// flag for type of the object file
	std::string windowName;
	glm::vec3 lightSourcePos;
	std::vector<Vertex> vertices;				  // triangle ad square coordinates
	std::vector<char *> textures;				  // all textures saved here
	RenderMode renderMode = FILLED;				  // default, hotkey available
	std::vector<glm::vec3> normals;				  // vn aka normals for light calculations
	std::vector<std::vector<int> > faces;		  // contains each from the obj file
	std::vector<std::vector<int> > uv_index;	  // indexes for uv coordinates from each face
	std::vector<std::vector<Vertex> > triangles;  // contains all shapes for now
	// NEED TO REMOVE 4th 5th VALUE, or get ready for pain
	std::vector<float> Triangles, unpreaparedSquares, Squares;	// converting squares to triangles
	GLuint VAO_triangles, VBO_triangles, VAO_squares, VBO_squares,
		normalVBO;	// vertex arrays and buffers maybe for elements arrays later
};

void drawKeyBindingsPanel();
void cleanUp(Object &object);
void createVaoVbo(Object &object);
void initIMGUI(GLFWwindow *window);
void saveTextures(Object &object, char **argv);
void drawInfoPanel(Object &object, glm::vec3 &color);
void renderText(GLFWwindow *window, Object &object, glm::vec3 &color);

#endif