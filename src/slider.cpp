#include "includes/slider.hpp"

// void initIMGUI(GLFWwindow *window) {
// 	ImGui::CreateContext();
// 	ImGui_ImplGlfw_InitForOpenGL(window, true);
// 	ImGui::StyleColorsDark();
// 	ImGui_ImplOpenGL3_Init("#version 400");
// }

void initSliderValues(Slider &slider) {
	slider.windowWidth = ImGui::GetWindowWidth();
	slider.childWidth = 0;
	slider.textWidth = 0;
	slider.sliderWidth = 70;
	slider.sliderBaseValue = 1;
}

void drawSliderMenu(GLFWwindow *window) {
	Slider slider;
	const GLFWvidmode *mode = glfwGetVideoMode(glfwGetPrimaryMonitor());

	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();

	setImGuiStyle();

	initSliderValues(slider);

	ImGui::SetNextWindowSize(ImVec2(295, 635));
	ImGui::SetNextWindowPos(
		ImVec2(mode->width - (mode->width - 200), (mode->height - (mode->height - 50))));

	ImGui::Begin("window", nullptr, ImGuiWindowFlags_AlwaysAutoResize);
	ImGui::SetCursorPos(ImVec2(10, 10));

	drawHeadSlider(slider);
	ImGui::SameLine();
	drawBodySlider(slider);

	drawLeftUpperArmSlider(slider);
	ImGui::SameLine();
	drawLeftForearmSlider(slider);

	drawRightUpperArmSlider(slider);
	ImGui::SameLine();
	drawRightForearmSlider(slider);

	drawLeftThighSlider(slider);
	ImGui::SameLine();
	drawLeftLowerLegSlider(slider);

	drawRightThighSlider(slider);
	ImGui::SameLine();
	drawRightLowerLegSlider(slider);

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

void drawHeadSlider(Slider &slider) {
	ImGui::BeginChild("Head", ImVec2(135, 120), true);
	const char *text = "Head";
	slider.childWidth = ImGui::GetContentRegionAvail().x;
	slider.textWidth = ImGui::CalcTextSize(text).x;
	ImGui::SetCursorPosX((slider.childWidth - slider.textWidth + (CHAR_PIXEL_SIZE * 2)) / 2);
	ImGui::Text("%s", text);
	ImGui::Separator();
	ImGui::Spacing();
	ImGui::PushItemWidth(slider.sliderWidth);
	ImGui::SliderInt("Height", &slider.sliderBaseValue, 1, 10);
	ImGui::PopItemWidth();

	ImGui::Spacing();

	ImGui::SetCursorPosX((slider.childWidth - slider.sliderWidth - 25 - CHAR_PIXEL_SIZE) / 2);
	ImGui::PushItemWidth(slider.sliderWidth);
	ImGui::SliderInt("Width", &slider.sliderBaseValue, 1, 10);
	ImGui::PopItemWidth();

	ImGui::Spacing();

	ImGui::SetCursorPosX((slider.childWidth - slider.sliderWidth - 25 - CHAR_PIXEL_SIZE) / 2);
	ImGui::PushItemWidth(slider.sliderWidth);
	ImGui::SliderInt("Depth", &slider.sliderBaseValue, 1, 10);
	ImGui::PopItemWidth();

	ImGui::EndChild();
}

void drawBodySlider(Slider &slider) {
	ImGui::BeginChild("Body", ImVec2(135, 120), true);
	const char *text = "Body";
	slider.textWidth = ImGui::CalcTextSize(text).x;
	ImGui::SetCursorPosX((slider.childWidth - slider.textWidth + (CHAR_PIXEL_SIZE * 2)) / 2);
	ImGui::Text("%s", text);
	ImGui::Separator();
	ImGui::Spacing();
	ImGui::PushItemWidth(slider.sliderWidth);
	ImGui::SliderInt("Height", &slider.sliderBaseValue, 1, 10);
	ImGui::PopItemWidth();

	ImGui::Spacing();

	ImGui::SetCursorPosX((slider.childWidth - slider.sliderWidth - 25 - CHAR_PIXEL_SIZE) / 2);
	ImGui::PushItemWidth(slider.sliderWidth);
	ImGui::SliderInt("Width", &slider.sliderBaseValue, 1, 10);
	ImGui::PopItemWidth();

	ImGui::Spacing();

	ImGui::SetCursorPosX((slider.childWidth - slider.sliderWidth - 25 - CHAR_PIXEL_SIZE) / 2);
	ImGui::PushItemWidth(slider.sliderWidth);
	ImGui::SliderInt("Depth", &slider.sliderBaseValue, 1, 10);
	ImGui::PopItemWidth();

	ImGui::EndChild();
}

void drawLeftUpperArmSlider(Slider &slider) {
	ImGui::BeginChild("LeftUpperArm", ImVec2(135, 120), true);
	const char *text = "Left Upper Arm";
	slider.textWidth = ImGui::CalcTextSize(text).x;
	ImGui::SetCursorPosX((slider.childWidth - slider.textWidth + (CHAR_PIXEL_SIZE * 2)) / 2);
	ImGui::Text("%s", text);
	ImGui::Separator();
	ImGui::Spacing();
	ImGui::PushItemWidth(slider.sliderWidth);
	ImGui::SliderInt("Height", &slider.sliderBaseValue, 1, 10);
	ImGui::PopItemWidth();

	ImGui::Spacing();

	ImGui::SetCursorPosX((slider.childWidth - slider.sliderWidth - 25 - CHAR_PIXEL_SIZE) / 2);
	ImGui::PushItemWidth(slider.sliderWidth);
	ImGui::SliderInt("Width", &slider.sliderBaseValue, 1, 10);
	ImGui::PopItemWidth();

	ImGui::Spacing();

	ImGui::SetCursorPosX((slider.childWidth - slider.sliderWidth - 25 - CHAR_PIXEL_SIZE) / 2);
	ImGui::PushItemWidth(slider.sliderWidth);
	ImGui::SliderInt("Depth", &slider.sliderBaseValue, 1, 10);
	ImGui::PopItemWidth();

	ImGui::EndChild();
}

void drawLeftForearmSlider(Slider &slider) {
	ImGui::BeginChild("LeftForearm", ImVec2(135, 120), true);
	const char *text = "Left Forearm";
	slider.textWidth = ImGui::CalcTextSize(text).x;
	ImGui::SetCursorPosX((slider.childWidth - slider.textWidth + (CHAR_PIXEL_SIZE * 2)) / 2);
	ImGui::Text("%s", text);
	ImGui::Separator();
	ImGui::Spacing();
	ImGui::PushItemWidth(slider.sliderWidth);
	ImGui::SliderInt("Height", &slider.sliderBaseValue, 1, 10);
	ImGui::PopItemWidth();

	ImGui::Spacing();

	ImGui::SetCursorPosX((slider.childWidth - slider.sliderWidth - 25 - CHAR_PIXEL_SIZE) / 2);
	ImGui::PushItemWidth(slider.sliderWidth);
	ImGui::SliderInt("Width", &slider.sliderBaseValue, 1, 10);
	ImGui::PopItemWidth();

	ImGui::Spacing();

	ImGui::SetCursorPosX((slider.childWidth - slider.sliderWidth - 25 - CHAR_PIXEL_SIZE) / 2);
	ImGui::PushItemWidth(slider.sliderWidth);
	ImGui::SliderInt("Depth", &slider.sliderBaseValue, 1, 10);
	ImGui::PopItemWidth();

	ImGui::EndChild();
}

void drawRightUpperArmSlider(Slider &slider) {
	ImGui::BeginChild("RightUpperArm", ImVec2(135, 120), true);
	const char *text = "Right Upper Arm";
	slider.textWidth = ImGui::CalcTextSize(text).x;
	ImGui::SetCursorPosX((slider.childWidth - slider.textWidth + (CHAR_PIXEL_SIZE * 2)) / 2);
	ImGui::Text("%s", text);
	ImGui::Separator();
	ImGui::Spacing();
	ImGui::PushItemWidth(slider.sliderWidth);
	ImGui::SliderInt("Height", &slider.sliderBaseValue, 1, 10);
	ImGui::PopItemWidth();

	ImGui::Spacing();

	ImGui::SetCursorPosX((slider.childWidth - slider.sliderWidth - 25 - CHAR_PIXEL_SIZE) / 2);
	ImGui::PushItemWidth(slider.sliderWidth);
	ImGui::SliderInt("Width", &slider.sliderBaseValue, 1, 10);
	ImGui::PopItemWidth();

	ImGui::Spacing();

	ImGui::SetCursorPosX((slider.childWidth - slider.sliderWidth - 25 - CHAR_PIXEL_SIZE) / 2);
	ImGui::PushItemWidth(slider.sliderWidth);
	ImGui::SliderInt("Depth", &slider.sliderBaseValue, 1, 10);
	ImGui::PopItemWidth();

	ImGui::EndChild();
}

void drawRightForearmSlider(Slider &slider) {
	ImGui::BeginChild("RightForearm", ImVec2(135, 120), true);
	const char *text = "Right Forearm";
	slider.textWidth = ImGui::CalcTextSize(text).x;
	ImGui::SetCursorPosX((slider.childWidth - slider.textWidth + (CHAR_PIXEL_SIZE * 2)) / 2);
	ImGui::Text("%s", text);
	ImGui::Separator();
	ImGui::Spacing();
	ImGui::PushItemWidth(slider.sliderWidth);
	ImGui::SliderInt("Height", &slider.sliderBaseValue, 1, 10);
	ImGui::PopItemWidth();

	ImGui::Spacing();

	ImGui::SetCursorPosX((slider.childWidth - slider.sliderWidth - 25 - CHAR_PIXEL_SIZE) / 2);
	ImGui::PushItemWidth(slider.sliderWidth);
	ImGui::SliderInt("Width", &slider.sliderBaseValue, 1, 10);
	ImGui::PopItemWidth();

	ImGui::Spacing();

	ImGui::SetCursorPosX((slider.childWidth - slider.sliderWidth - 25 - CHAR_PIXEL_SIZE) / 2);
	ImGui::PushItemWidth(slider.sliderWidth);
	ImGui::SliderInt("Depth", &slider.sliderBaseValue, 1, 10);
	ImGui::PopItemWidth();

	ImGui::EndChild();
}

void drawLeftThighSlider(Slider &slider) {
	ImGui::BeginChild("LeftThigh", ImVec2(135, 120), true);
	const char *text = "Left Thigh";
	slider.textWidth = ImGui::CalcTextSize(text).x;
	ImGui::SetCursorPosX((slider.childWidth - slider.textWidth + (CHAR_PIXEL_SIZE * 2)) / 2);
	ImGui::Text("%s", text);
	ImGui::Separator();
	ImGui::Spacing();
	ImGui::PushItemWidth(slider.sliderWidth);
	ImGui::SliderInt("Height", &slider.sliderBaseValue, 1, 10);
	ImGui::PopItemWidth();

	ImGui::Spacing();

	ImGui::SetCursorPosX((slider.childWidth - slider.sliderWidth - 25 - CHAR_PIXEL_SIZE) / 2);
	ImGui::PushItemWidth(slider.sliderWidth);
	ImGui::SliderInt("Width", &slider.sliderBaseValue, 1, 10);
	ImGui::PopItemWidth();

	ImGui::Spacing();

	ImGui::SetCursorPosX((slider.childWidth - slider.sliderWidth - 25 - CHAR_PIXEL_SIZE) / 2);
	ImGui::PushItemWidth(slider.sliderWidth);
	ImGui::SliderInt("Depth", &slider.sliderBaseValue, 1, 10);
	ImGui::PopItemWidth();

	ImGui::EndChild();
}

void drawLeftLowerLegSlider(Slider &slider) {
	ImGui::BeginChild("LeftLowerLeg", ImVec2(135, 120), true);
	const char *text = "Left Lower Leg";
	slider.textWidth = ImGui::CalcTextSize(text).x;
	ImGui::SetCursorPosX((slider.childWidth - slider.textWidth + (CHAR_PIXEL_SIZE * 2)) / 2);
	ImGui::Text("%s", text);
	ImGui::Separator();
	ImGui::Spacing();
	ImGui::PushItemWidth(slider.sliderWidth);
	ImGui::SliderInt("Height", &slider.sliderBaseValue, 1, 10);
	ImGui::PopItemWidth();

	ImGui::Spacing();

	ImGui::SetCursorPosX((slider.childWidth - slider.sliderWidth - 25 - CHAR_PIXEL_SIZE) / 2);
	ImGui::PushItemWidth(slider.sliderWidth);
	ImGui::SliderInt("Width", &slider.sliderBaseValue, 1, 10);
	ImGui::PopItemWidth();

	ImGui::Spacing();

	ImGui::SetCursorPosX((slider.childWidth - slider.sliderWidth - 25 - CHAR_PIXEL_SIZE) / 2);
	ImGui::PushItemWidth(slider.sliderWidth);
	ImGui::SliderInt("Depth", &slider.sliderBaseValue, 1, 10);
	ImGui::PopItemWidth();

	ImGui::EndChild();
}

void drawRightThighSlider(Slider &slider) {
	ImGui::BeginChild("RightThigh", ImVec2(135, 120), true);
	const char *text = "Right Thigh";
	slider.textWidth = ImGui::CalcTextSize(text).x;
	ImGui::SetCursorPosX((slider.childWidth - slider.textWidth + (CHAR_PIXEL_SIZE * 2)) / 2);
	ImGui::Text("%s", text);
	ImGui::Separator();
	ImGui::Spacing();
	ImGui::PushItemWidth(slider.sliderWidth);
	ImGui::SliderInt("Height", &slider.sliderBaseValue, 1, 10);
	ImGui::PopItemWidth();

	ImGui::Spacing();

	ImGui::SetCursorPosX((slider.childWidth - slider.sliderWidth - 25 - CHAR_PIXEL_SIZE) / 2);
	ImGui::PushItemWidth(slider.sliderWidth);
	ImGui::SliderInt("Width", &slider.sliderBaseValue, 1, 10);
	ImGui::PopItemWidth();

	ImGui::Spacing();

	ImGui::SetCursorPosX((slider.childWidth - slider.sliderWidth - 25 - CHAR_PIXEL_SIZE) / 2);
	ImGui::PushItemWidth(slider.sliderWidth);
	ImGui::SliderInt("Depth", &slider.sliderBaseValue, 1, 10);
	ImGui::PopItemWidth();

	ImGui::EndChild();
}

void drawRightLowerLegSlider(Slider &slider) {
	ImGui::BeginChild("RightLowerLeg", ImVec2(135, 120), true);
	const char *text = "Right Lower Leg";
	slider.textWidth = ImGui::CalcTextSize(text).x;
	ImGui::SetCursorPosX((slider.childWidth - slider.textWidth + (CHAR_PIXEL_SIZE * 2)) / 2);
	ImGui::Text("%s", text);
	ImGui::Separator();
	ImGui::Spacing();
	ImGui::PushItemWidth(slider.sliderWidth);
	ImGui::SliderInt("Height", &slider.sliderBaseValue, 1, 10);
	ImGui::PopItemWidth();

	ImGui::Spacing();

	ImGui::SetCursorPosX((slider.childWidth - slider.sliderWidth - 25 - CHAR_PIXEL_SIZE) / 2);
	ImGui::PushItemWidth(slider.sliderWidth);
	ImGui::SliderInt("Width", &slider.sliderBaseValue, 1, 10);
	ImGui::PopItemWidth();

	ImGui::Spacing();

	ImGui::SetCursorPosX((slider.childWidth - slider.sliderWidth - 25 - CHAR_PIXEL_SIZE) / 2);
	ImGui::PushItemWidth(slider.sliderWidth);
	ImGui::SliderInt("Depth", &slider.sliderBaseValue, 1, 10);
	ImGui::PopItemWidth();

	ImGui::EndChild();
}