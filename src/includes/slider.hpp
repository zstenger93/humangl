#ifndef SLIDER_HPP
#define SLIDER_HPP

#include "cube.hpp"
#include "headers.hpp"

#define CHAR_PIXEL_SIZE 8

struct Slider {
	float windowWidth;
	float childWidth = 0;
	float textWidth = 0;
	float sliderWidth = 70;
	glm::vec3 sliderBaseValue;
};

struct Sliders {
	Slider headSlider;
	Slider bodySlider;
	Slider leftUpperArmSlider;
	Slider leftForearmSlider;
	Slider rightUpperArmSlider;
	Slider rightForearmSlider;
	Slider leftThighSlider;
	Slider leftLowerLegSlider;
	Slider rightThighSlider;
	Slider rightLowerLegSlider;
};

void setImGuiStyle();
void initIMGUI(GLFWwindow *window);
void initSliderValues(Slider &slider);
void drawSliderMenu(Cube *human, Sliders &sliders);
void drawHeadSlider(Cube *human, Slider &headSlider);
void drawBodySlider(Cube *human, Slider &bodySlider);
void drawLeftUpperArmSlider(Cube *human, Slider &leftUpperArmSlider);
void drawLeftForearmSlider(Cube *human, Slider &leftForearmSlider);
void drawRightUpperArmSlider(Cube *human, Slider &rightUpperArmSlider);
void drawRightForearmSlider(Cube *human, Slider &rightForearmSlider);
void drawLeftThighSlider(Cube *human, Slider &leftThighSlider);
void drawLeftLowerLegSlider(Cube *human, Slider &leftLowerLegSlider);
void drawRightThighSlider(Cube *human, Slider &rightThighSlider);
void drawRightLowerLegSlider(Cube *human, Slider &rightLowerLegSlider);

#endif