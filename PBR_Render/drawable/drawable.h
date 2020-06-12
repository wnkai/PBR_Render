#pragma once
#include <glad/glad.h>          // Initialize with gladLoadGL()
// Include glfw3.h after our OpenGL definitions
#include <GLFW/glfw3.h>
#include "../material/material.h"

class drawable
{
protected:
	GLuint VBO, VAO;
	std::unique_ptr<material> mat;
public:
	drawable() {};
	virtual void draw() = 0;
};

