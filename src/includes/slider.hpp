#ifndef SLIDER_HPP
#define SLIDER_HPP

#include "headers.hpp"

#define CHAR_PIXEL_SIZE 8

struct Slider {
float windowWidth;
float childWidth;
float textWidth;
float sliderWidth;
int sliderBaseValue;
};

void initIMGUI(GLFWwindow *window);
void initSliderValues(Slider &slider);

void setImGuiStyle();

void drawSliderMenu(GLFWwindow *window);
void drawHeadSlider(Slider &slider);

void drawBodySlider(Slider &slider);

void drawLeftUpperArmSlider(Slider &slider);
void drawLeftForearmSlider(Slider &slider);

void drawRightUpperArmSlider(Slider &slider);
void drawRightForearmSlider(Slider &slider);

void drawLeftThighSlider(Slider &slider);
void drawLeftLowerLegSlider(Slider &slider);

void drawRightThighSlider(Slider &slider);
void drawRightLowerLegSlider(Slider &slider);

#endif