#pragma once
#include <stdio.h>
#include <glad/glad.h>          // Initialize with gladLoadGL()
// Include glfw3.h after our OpenGL definitions
#include <GLFW/glfw3.h>

#include <shader.h>

class triangle
{
private:
	float vertices[18] = {
		// positions         // colors
		 0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,  // bottom right
		-0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,  // bottom left
		 0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f   // top 
	};
	GLuint VBO, VAO;
	Shader shader;
public:
	triangle();
	void draw();
};

