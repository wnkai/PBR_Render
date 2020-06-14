#pragma once
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include <stdio.h>
#include <glad/glad.h>          // Initialize with gladLoadGL()
// Include glfw3.h after our OpenGL definitions
#include <GLFW/glfw3.h>

#include <shader.h>
#include "camera.h"

static void glfw_error_callback(int error, const char* description)
{
	fprintf(stderr, "Glfw Error %d: %s\n", error, description);
}

class ui
{
private:
	GLFWwindow* window;
	ImVec4 clear_color;
	bool show_demo_window;
	bool canMouseRotate;
	bool show_bout_window;
public:
	ui();
	void init();
	void set(Camera& cm);
	void process(Camera& cm);
	void end();
	void draw();
	inline GLFWwindow* getWindow() {
		return window;
	}
	inline ImVec4 getColor()
	{
		return clear_color;
	}
};

