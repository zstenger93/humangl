#include "includes/slider.hpp"

void initSliderValues(Slider &slider) {
	if (slider.childWidth == 0) {
		slider.windowWidth = ImGui::GetWindowWidth();
		slider.sliderBaseValue.x = 1;
		slider.sliderBaseValue.y = 1;
		slider.sliderBaseValue.z = 1;
	}
}

void drawSliderMenu(Cube *human, Sliders &sliders) {
	const GLFWvidmode *mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();
	setImGuiStyle();
	initSliderValues(sliders.headSlider);
	initSliderValues(sliders.bodySlider);
	initSliderValues(sliders.leftUpperArmSlider);
	initSliderValues(sliders.leftForearmSlider);
	initSliderValues(sliders.rightUpperArmSlider);
	initSliderValues(sliders.rightForearmSlider);
	initSliderValues(sliders.leftThighSlider);
	initSliderValues(sliders.leftLowerLegSlider);
	initSliderValues(sliders.rightThighSlider);
	initSliderValues(sliders.rightLowerLegSlider);

	ImGui::SetNextWindowSize(ImVec2(295, 635));
	ImGui::SetNextWindowPos(
		ImVec2(mode->width - (mode->width - 115), (mode->height - (mode->height - 500))));
	ImGui::Begin("window", nullptr, ImGuiWindowFlags_AlwaysAutoResize);
	ImGui::SetCursorPos(ImVec2(10, 10));

	drawHeadSlider(human, sliders.headSlider);
	ImGui::SameLine();
	drawBodySlider(human, sliders.bodySlider);

	drawLeftUpperArmSlider(human, sliders.leftUpperArmSlider);
	ImGui::SameLine();
	drawLeftForearmSlider(human, sliders.leftForearmSlider);

	drawRightUpperArmSlider(human, sliders.rightUpperArmSlider);
	ImGui::SameLine();
	drawRightForearmSlider(human, sliders.rightForearmSlider);

	drawLeftThighSlider(human, sliders.leftThighSlider);
	ImGui::SameLine();
	drawLeftLowerLegSlider(human, sliders.leftLowerLegSlider);

	drawRightThighSlider(human, sliders.rightThighSlider);
	ImGui::SameLine();
	drawRightLowerLegSlider(human, sliders.rightLowerLegSlider);

	ImGui::End();
	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void setImGuiStyle() {
	ImGuiStyle *style = &ImGui::GetStyle();

	style->WindowBorderSize = 1;
	style->WindowRounding = 8;
	style->ChildBorderSize = 1;
	style->ChildRounding = 8;
	style->GrabRounding = 4;
	style->Colors[ImGuiCol_SliderGrab] = ImVec4(0.0f, 0.0f, 0.0f, 1.0f);
	style->FrameRounding = 4;
}

void drawHeadSlider(Cube *human, Slider &headSlider) {
	ImGui::BeginChild("Head", ImVec2(135, 120), true);
	double initialY = headSlider.sliderBaseValue.y, initialX = headSlider.sliderBaseValue.x,
		   initialZ = headSlider.sliderBaseValue.z;
	const char *text = "Head";
	headSlider.childWidth = ImGui::GetContentRegionAvail().x;
	headSlider.textWidth = ImGui::CalcTextSize(text).x;
	ImGui::SetCursorPosX((headSlider.childWidth - headSlider.textWidth + (CHAR_PIXEL_SIZE * 2)) /
						 2);
	ImGui::Text("%s", text);
	ImGui::Separator();
	ImGui::Spacing();
	ImGui::PushItemWidth(headSlider.sliderWidth);
	ImGui::SliderFloat("Height", &headSlider.sliderBaseValue.y, 1, 10);
	ImGui::PopItemWidth();
	ImGui::Spacing();
	ImGui::SetCursorPosX((headSlider.childWidth - headSlider.sliderWidth - 25 - CHAR_PIXEL_SIZE) /
						 2);
	ImGui::PushItemWidth(headSlider.sliderWidth);
	ImGui::SliderFloat("Width", &headSlider.sliderBaseValue.x, 1, 10);
	ImGui::PopItemWidth();
	ImGui::Spacing();
	ImGui::SetCursorPosX((headSlider.childWidth - headSlider.sliderWidth - 25 - CHAR_PIXEL_SIZE) /
						 2);
	ImGui::PushItemWidth(headSlider.sliderWidth);
	ImGui::SliderFloat("Depth", &headSlider.sliderBaseValue.z, 1, 10);
	ImGui::PopItemWidth();
	ImGui::EndChild();
	if (initialY != headSlider.sliderBaseValue.y || initialX != headSlider.sliderBaseValue.x ||
		initialZ != headSlider.sliderBaseValue.z)
		human->_cubes[4]->resizeCube(glm::vec3(headSlider.sliderBaseValue.x,
											   headSlider.sliderBaseValue.y,
											   headSlider.sliderBaseValue.z));
}

void drawBodySlider(Cube *human, Slider &bodySlider) {
	double initialY = bodySlider.sliderBaseValue.y, initialX = bodySlider.sliderBaseValue.x,
		   initialZ = bodySlider.sliderBaseValue.z;
	ImGui::BeginChild("Body", ImVec2(135, 120), true);
	const char *text = "Body";
	bodySlider.childWidth = ImGui::GetContentRegionAvail().x;
	bodySlider.textWidth = ImGui::CalcTextSize(text).x;
	ImGui::SetCursorPosX((bodySlider.childWidth - bodySlider.textWidth + (CHAR_PIXEL_SIZE * 2)) /
						 2);
	ImGui::Text("%s", text);
	ImGui::Separator();
	ImGui::Spacing();
	ImGui::PushItemWidth(bodySlider.sliderWidth);
	ImGui::SliderFloat("Height", &bodySlider.sliderBaseValue.y, 1, 10);
	ImGui::PopItemWidth();
	ImGui::Spacing();
	ImGui::SetCursorPosX((bodySlider.childWidth - bodySlider.sliderWidth - 25 - CHAR_PIXEL_SIZE) /
						 2);
	ImGui::PushItemWidth(bodySlider.sliderWidth);
	ImGui::SliderFloat("Width", &bodySlider.sliderBaseValue.x, 1, 10);
	ImGui::PopItemWidth();
	ImGui::Spacing();
	ImGui::SetCursorPosX((bodySlider.childWidth - bodySlider.sliderWidth - 25 - CHAR_PIXEL_SIZE) /
						 2);
	ImGui::PushItemWidth(bodySlider.sliderWidth);
	ImGui::SliderFloat("Depth", &bodySlider.sliderBaseValue.z, 1, 10);
	ImGui::PopItemWidth();
	ImGui::EndChild();
	if (initialY != bodySlider.sliderBaseValue.y || initialX != bodySlider.sliderBaseValue.x ||
		initialZ != bodySlider.sliderBaseValue.z)
		human->resizeCube(glm::vec3(bodySlider.sliderBaseValue.x, bodySlider.sliderBaseValue.y,
									bodySlider.sliderBaseValue.z));
}

void drawLeftUpperArmSlider(Cube *human, Slider &leftUpperArmSlider) {
	double initialY = leftUpperArmSlider.sliderBaseValue.y,
		   initialX = leftUpperArmSlider.sliderBaseValue.x,
		   initialZ = leftUpperArmSlider.sliderBaseValue.z;
	ImGui::BeginChild("LeftUpperArm", ImVec2(135, 120), true);
	const char *text = "Left Upper Arm";
	leftUpperArmSlider.childWidth = ImGui::GetContentRegionAvail().x;
	leftUpperArmSlider.textWidth = ImGui::CalcTextSize(text).x;
	ImGui::SetCursorPosX(
		(leftUpperArmSlider.childWidth - leftUpperArmSlider.textWidth + (CHAR_PIXEL_SIZE * 2)) / 2);
	ImGui::Text("%s", text);
	ImGui::Separator();
	ImGui::Spacing();
	ImGui::PushItemWidth(leftUpperArmSlider.sliderWidth);
	ImGui::SliderFloat("Height", &leftUpperArmSlider.sliderBaseValue.y, 1, 10);
	ImGui::PopItemWidth();
	ImGui::Spacing();
	ImGui::SetCursorPosX(
		(leftUpperArmSlider.childWidth - leftUpperArmSlider.sliderWidth - 25 - CHAR_PIXEL_SIZE) /
		2);
	ImGui::PushItemWidth(leftUpperArmSlider.sliderWidth);
	ImGui::SliderFloat("Width", &leftUpperArmSlider.sliderBaseValue.x, 1, 10);
	ImGui::PopItemWidth();
	ImGui::Spacing();
	ImGui::SetCursorPosX(
		(leftUpperArmSlider.childWidth - leftUpperArmSlider.sliderWidth - 25 - CHAR_PIXEL_SIZE) /
		2);
	ImGui::PushItemWidth(leftUpperArmSlider.sliderWidth);
	ImGui::SliderFloat("Depth", &leftUpperArmSlider.sliderBaseValue.z, 1, 10);
	ImGui::PopItemWidth();
	ImGui::EndChild();
	if (initialY != leftUpperArmSlider.sliderBaseValue.y ||
		initialX != leftUpperArmSlider.sliderBaseValue.x ||
		initialZ != leftUpperArmSlider.sliderBaseValue.z)
		human->_cubes[0]->resizeCube(glm::vec3(leftUpperArmSlider.sliderBaseValue.x,
											   leftUpperArmSlider.sliderBaseValue.y,
											   leftUpperArmSlider.sliderBaseValue.z));
}

void drawLeftForearmSlider(Cube *human, Slider &leftForearmSlider) {
	double initialY = leftForearmSlider.sliderBaseValue.y,
		   initialX = leftForearmSlider.sliderBaseValue.x,
		   initialZ = leftForearmSlider.sliderBaseValue.z;
	ImGui::BeginChild("LeftForearm", ImVec2(135, 120), true);
	const char *text = "Left Forearm";
	leftForearmSlider.childWidth = ImGui::GetContentRegionAvail().x;
	leftForearmSlider.textWidth = ImGui::CalcTextSize(text).x;
	ImGui::SetCursorPosX(
		(leftForearmSlider.childWidth - leftForearmSlider.textWidth + (CHAR_PIXEL_SIZE * 2)) / 2);
	ImGui::Text("%s", text);
	ImGui::Separator();
	ImGui::Spacing();
	ImGui::PushItemWidth(leftForearmSlider.sliderWidth);
	ImGui::SliderFloat("Height", &leftForearmSlider.sliderBaseValue.y, 1, 10);
	ImGui::PopItemWidth();
	ImGui::Spacing();
	ImGui::SetCursorPosX(
		(leftForearmSlider.childWidth - leftForearmSlider.sliderWidth - 25 - CHAR_PIXEL_SIZE) / 2);
	ImGui::PushItemWidth(leftForearmSlider.sliderWidth);
	ImGui::SliderFloat("Width", &leftForearmSlider.sliderBaseValue.x, 1, 10);
	ImGui::PopItemWidth();
	ImGui::Spacing();
	ImGui::SetCursorPosX(
		(leftForearmSlider.childWidth - leftForearmSlider.sliderWidth - 25 - CHAR_PIXEL_SIZE) / 2);
	ImGui::PushItemWidth(leftForearmSlider.sliderWidth);
	ImGui::SliderFloat("Depth", &leftForearmSlider.sliderBaseValue.z, 1, 10);
	ImGui::PopItemWidth();
	ImGui::EndChild();
	if (initialY != leftForearmSlider.sliderBaseValue.y ||
		initialX != leftForearmSlider.sliderBaseValue.x ||
		initialZ != leftForearmSlider.sliderBaseValue.z)
		human->_cubes[0]->_cubes[0]->resizeCube(glm::vec3(leftForearmSlider.sliderBaseValue.x,
														  leftForearmSlider.sliderBaseValue.y,
														  leftForearmSlider.sliderBaseValue.z));
}

void drawRightUpperArmSlider(Cube *human, Slider &rightUpperArmSlider) {
	double initialY = rightUpperArmSlider.sliderBaseValue.y,
		   initialX = rightUpperArmSlider.sliderBaseValue.x,
		   initialZ = rightUpperArmSlider.sliderBaseValue.z;
	ImGui::BeginChild("RightUpperArm", ImVec2(135, 120), true);
	const char *text = "Right Upper Arm";
	rightUpperArmSlider.childWidth = ImGui::GetContentRegionAvail().x;
	rightUpperArmSlider.textWidth = ImGui::CalcTextSize(text).x;
	ImGui::SetCursorPosX(
		(rightUpperArmSlider.childWidth - rightUpperArmSlider.textWidth + (CHAR_PIXEL_SIZE * 2)) /
		2);
	ImGui::Text("%s", text);
	ImGui::Separator();
	ImGui::Spacing();
	ImGui::PushItemWidth(rightUpperArmSlider.sliderWidth);
	ImGui::SliderFloat("Height", &rightUpperArmSlider.sliderBaseValue.y, 1, 10);
	ImGui::PopItemWidth();
	ImGui::Spacing();
	ImGui::SetCursorPosX(
		(rightUpperArmSlider.childWidth - rightUpperArmSlider.sliderWidth - 25 - CHAR_PIXEL_SIZE) /
		2);
	ImGui::PushItemWidth(rightUpperArmSlider.sliderWidth);
	ImGui::SliderFloat("Width", &rightUpperArmSlider.sliderBaseValue.x, 1, 10);
	ImGui::PopItemWidth();
	ImGui::Spacing();
	ImGui::SetCursorPosX(
		(rightUpperArmSlider.childWidth - rightUpperArmSlider.sliderWidth - 25 - CHAR_PIXEL_SIZE) /
		2);
	ImGui::PushItemWidth(rightUpperArmSlider.sliderWidth);
	ImGui::SliderFloat("Depth", &rightUpperArmSlider.sliderBaseValue.z, 1, 10);
	ImGui::PopItemWidth();
	ImGui::EndChild();
	if (initialY != rightUpperArmSlider.sliderBaseValue.y ||
		initialX != rightUpperArmSlider.sliderBaseValue.x ||
		initialZ != rightUpperArmSlider.sliderBaseValue.z)
		human->_cubes[1]->resizeCube(glm::vec3(rightUpperArmSlider.sliderBaseValue.x,
											   rightUpperArmSlider.sliderBaseValue.y,
											   rightUpperArmSlider.sliderBaseValue.z));
}

void drawRightForearmSlider(Cube *human, Slider &rightForearmSlider) {
	double initialY = rightForearmSlider.sliderBaseValue.y,
		   initialX = rightForearmSlider.sliderBaseValue.x,
		   initialZ = rightForearmSlider.sliderBaseValue.z;
	ImGui::BeginChild("RightForearm", ImVec2(135, 120), true);
	const char *text = "Right Forearm";
	rightForearmSlider.childWidth = ImGui::GetContentRegionAvail().x;
	rightForearmSlider.textWidth = ImGui::CalcTextSize(text).x;
	ImGui::SetCursorPosX(
		(rightForearmSlider.childWidth - rightForearmSlider.textWidth + (CHAR_PIXEL_SIZE * 2)) / 2);
	ImGui::Text("%s", text);
	ImGui::Separator();
	ImGui::Spacing();
	ImGui::PushItemWidth(rightForearmSlider.sliderWidth);
	ImGui::SliderFloat("Height", &rightForearmSlider.sliderBaseValue.y, 1, 10);
	ImGui::PopItemWidth();
	ImGui::Spacing();
	ImGui::SetCursorPosX(
		(rightForearmSlider.childWidth - rightForearmSlider.sliderWidth - 25 - CHAR_PIXEL_SIZE) /
		2);
	ImGui::PushItemWidth(rightForearmSlider.sliderWidth);
	ImGui::SliderFloat("Width", &rightForearmSlider.sliderBaseValue.x, 1, 10);
	ImGui::PopItemWidth();
	ImGui::Spacing();
	ImGui::SetCursorPosX(
		(rightForearmSlider.childWidth - rightForearmSlider.sliderWidth - 25 - CHAR_PIXEL_SIZE) /
		2);
	ImGui::PushItemWidth(rightForearmSlider.sliderWidth);
	ImGui::SliderFloat("Depth", &rightForearmSlider.sliderBaseValue.z, 1, 10);
	ImGui::PopItemWidth();
	ImGui::EndChild();
	if (initialY != rightForearmSlider.sliderBaseValue.y ||
		initialX != rightForearmSlider.sliderBaseValue.x ||
		initialZ != rightForearmSlider.sliderBaseValue.z)
		human->_cubes[1]->_cubes[0]->resizeCube(glm::vec3(rightForearmSlider.sliderBaseValue.x,
														  rightForearmSlider.sliderBaseValue.y,
														  rightForearmSlider.sliderBaseValue.z));
}

void drawLeftThighSlider(Cube *human, Slider &leftThighSlider) {
	double initialY = leftThighSlider.sliderBaseValue.y,
		   initialX = leftThighSlider.sliderBaseValue.x,
		   initialZ = leftThighSlider.sliderBaseValue.z;
	ImGui::BeginChild("LeftThigh", ImVec2(135, 120), true);
	const char *text = "Left Thigh";
	leftThighSlider.childWidth = ImGui::GetContentRegionAvail().x;
	leftThighSlider.textWidth = ImGui::CalcTextSize(text).x;
	ImGui::SetCursorPosX(
		(leftThighSlider.childWidth - leftThighSlider.textWidth + (CHAR_PIXEL_SIZE * 2)) / 2);
	ImGui::Text("%s", text);
	ImGui::Separator();
	ImGui::Spacing();
	ImGui::PushItemWidth(leftThighSlider.sliderWidth);
	ImGui::SliderFloat("Height", &leftThighSlider.sliderBaseValue.y, 1, 10);
	ImGui::PopItemWidth();
	ImGui::Spacing();
	ImGui::SetCursorPosX(
		(leftThighSlider.childWidth - leftThighSlider.sliderWidth - 25 - CHAR_PIXEL_SIZE) / 2);
	ImGui::PushItemWidth(leftThighSlider.sliderWidth);
	ImGui::SliderFloat("Width", &leftThighSlider.sliderBaseValue.x, 1, 10);
	ImGui::PopItemWidth();
	ImGui::Spacing();
	ImGui::SetCursorPosX(
		(leftThighSlider.childWidth - leftThighSlider.sliderWidth - 25 - CHAR_PIXEL_SIZE) / 2);
	ImGui::PushItemWidth(leftThighSlider.sliderWidth);
	ImGui::SliderFloat("Depth", &leftThighSlider.sliderBaseValue.z, 1, 10);
	ImGui::PopItemWidth();
	ImGui::EndChild();
	if (initialY != leftThighSlider.sliderBaseValue.y ||
		initialX != leftThighSlider.sliderBaseValue.x ||
		initialZ != leftThighSlider.sliderBaseValue.z)
		human->_cubes[2]->resizeCube(glm::vec3(leftThighSlider.sliderBaseValue.x,
											   leftThighSlider.sliderBaseValue.y,
											   leftThighSlider.sliderBaseValue.z));
}

void drawLeftLowerLegSlider(Cube *human, Slider &leftLowerLegSlider) {
	double initialY = leftLowerLegSlider.sliderBaseValue.y,
		   initialX = leftLowerLegSlider.sliderBaseValue.x,
		   initialZ = leftLowerLegSlider.sliderBaseValue.z;
	ImGui::BeginChild("LeftLowerLeg", ImVec2(135, 120), true);
	const char *text = "Left Lower Leg";
	leftLowerLegSlider.childWidth = ImGui::GetContentRegionAvail().x;
	leftLowerLegSlider.textWidth = ImGui::CalcTextSize(text).x;
	ImGui::SetCursorPosX(
		(leftLowerLegSlider.childWidth - leftLowerLegSlider.textWidth + (CHAR_PIXEL_SIZE * 2)) / 2);
	ImGui::Text("%s", text);
	ImGui::Separator();
	ImGui::Spacing();
	ImGui::PushItemWidth(leftLowerLegSlider.sliderWidth);
	ImGui::SliderFloat("Height", &leftLowerLegSlider.sliderBaseValue.y, 1, 10);
	ImGui::PopItemWidth();
	ImGui::Spacing();
	ImGui::SetCursorPosX(
		(leftLowerLegSlider.childWidth - leftLowerLegSlider.sliderWidth - 25 - CHAR_PIXEL_SIZE) /
		2);
	ImGui::PushItemWidth(leftLowerLegSlider.sliderWidth);
	ImGui::SliderFloat("Width", &leftLowerLegSlider.sliderBaseValue.x, 1, 10);
	ImGui::PopItemWidth();
	ImGui::Spacing();
	ImGui::SetCursorPosX(
		(leftLowerLegSlider.childWidth - leftLowerLegSlider.sliderWidth - 25 - CHAR_PIXEL_SIZE) /
		2);
	ImGui::PushItemWidth(leftLowerLegSlider.sliderWidth);
	ImGui::SliderFloat("Depth", &leftLowerLegSlider.sliderBaseValue.z, 1, 10);
	ImGui::PopItemWidth();
	ImGui::EndChild();
	if (initialY != leftLowerLegSlider.sliderBaseValue.y ||
		initialX != leftLowerLegSlider.sliderBaseValue.x ||
		initialZ != leftLowerLegSlider.sliderBaseValue.z)
		human->_cubes[2]->_cubes[0]->resizeCube(glm::vec3(leftLowerLegSlider.sliderBaseValue.x,
														  leftLowerLegSlider.sliderBaseValue.y,
														  leftLowerLegSlider.sliderBaseValue.z));
}

void drawRightThighSlider(Cube *human, Slider &rightThighSlider) {
	double initialY = rightThighSlider.sliderBaseValue.y,
		   initialX = rightThighSlider.sliderBaseValue.x,
		   initialZ = rightThighSlider.sliderBaseValue.z;
	ImGui::BeginChild("RightThigh", ImVec2(135, 120), true);
	const char *text = "Right Thigh";
	rightThighSlider.childWidth = ImGui::GetContentRegionAvail().x;
	rightThighSlider.textWidth = ImGui::CalcTextSize(text).x;
	ImGui::SetCursorPosX(
		(rightThighSlider.childWidth - rightThighSlider.textWidth + (CHAR_PIXEL_SIZE * 2)) / 2);
	ImGui::Text("%s", text);
	ImGui::Separator();
	ImGui::Spacing();
	ImGui::PushItemWidth(rightThighSlider.sliderWidth);
	ImGui::SliderFloat("Height", &rightThighSlider.sliderBaseValue.y, 1, 10);
	ImGui::PopItemWidth();
	ImGui::Spacing();
	ImGui::SetCursorPosX(
		(rightThighSlider.childWidth - rightThighSlider.sliderWidth - 25 - CHAR_PIXEL_SIZE) / 2);
	ImGui::PushItemWidth(rightThighSlider.sliderWidth);
	ImGui::SliderFloat("Width", &rightThighSlider.sliderBaseValue.x, 1, 10);
	ImGui::PopItemWidth();
	ImGui::Spacing();
	ImGui::SetCursorPosX(
		(rightThighSlider.childWidth - rightThighSlider.sliderWidth - 25 - CHAR_PIXEL_SIZE) / 2);
	ImGui::PushItemWidth(rightThighSlider.sliderWidth);
	ImGui::SliderFloat("Depth", &rightThighSlider.sliderBaseValue.z, 1, 10);
	ImGui::PopItemWidth();
	ImGui::EndChild();
	if (initialY != rightThighSlider.sliderBaseValue.y ||
		initialX != rightThighSlider.sliderBaseValue.x ||
		initialZ != rightThighSlider.sliderBaseValue.z)
		human->_cubes[3]->resizeCube(glm::vec3(rightThighSlider.sliderBaseValue.x,
											   rightThighSlider.sliderBaseValue.y,
											   rightThighSlider.sliderBaseValue.z));
}

void drawRightLowerLegSlider(Cube *human, Slider &rightLowerLegSlider) {
	double initialY = rightLowerLegSlider.sliderBaseValue.y,
		   initialX = rightLowerLegSlider.sliderBaseValue.x,
		   initialZ = rightLowerLegSlider.sliderBaseValue.z;
	ImGui::BeginChild("RightLowerLeg", ImVec2(135, 120), true);
	const char *text = "Right Lower Leg";
	rightLowerLegSlider.childWidth = ImGui::GetContentRegionAvail().x;
	rightLowerLegSlider.textWidth = ImGui::CalcTextSize(text).x;
	ImGui::SetCursorPosX(
		(rightLowerLegSlider.childWidth - rightLowerLegSlider.textWidth + (CHAR_PIXEL_SIZE * 2)) /
		2);
	ImGui::Text("%s", text);
	ImGui::Separator();
	ImGui::Spacing();
	ImGui::PushItemWidth(rightLowerLegSlider.sliderWidth);
	ImGui::SliderFloat("Height", &rightLowerLegSlider.sliderBaseValue.y, 1, 10);
	ImGui::PopItemWidth();
	ImGui::Spacing();
	ImGui::SetCursorPosX(
		(rightLowerLegSlider.childWidth - rightLowerLegSlider.sliderWidth - 25 - CHAR_PIXEL_SIZE) /
		2);
	ImGui::PushItemWidth(rightLowerLegSlider.sliderWidth);
	ImGui::SliderFloat("Width", &rightLowerLegSlider.sliderBaseValue.x, 1, 10);
	ImGui::PopItemWidth();
	ImGui::Spacing();
	ImGui::SetCursorPosX(
		(rightLowerLegSlider.childWidth - rightLowerLegSlider.sliderWidth - 25 - CHAR_PIXEL_SIZE) /
		2);
	ImGui::PushItemWidth(rightLowerLegSlider.sliderWidth);
	ImGui::SliderFloat("Depth", &rightLowerLegSlider.sliderBaseValue.z, 1, 10);
	ImGui::PopItemWidth();
	ImGui::EndChild();
	if (initialY != rightLowerLegSlider.sliderBaseValue.y ||
		initialX != rightLowerLegSlider.sliderBaseValue.x ||
		initialZ != rightLowerLegSlider.sliderBaseValue.z)
		human->_cubes[3]->_cubes[0]->resizeCube(glm::vec3(rightLowerLegSlider.sliderBaseValue.x,
														  rightLowerLegSlider.sliderBaseValue.y,
														  rightLowerLegSlider.sliderBaseValue.z));
}