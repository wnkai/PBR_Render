#pragma once
#include <glad/glad.h>          // Initialize with gladLoadGL()
// Include glfw3.h after our OpenGL definitions
#include <GLFW/glfw3.h>

#include <glad/glad.h> // holds all OpenGL type declarations
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "../material/material.h"
#include "../camera.h"

class drawable
{
protected:
	GLuint VBO, VAO, EBO;
	std::unique_ptr<material> mat;
public:
	drawable() {};
	virtual void draw(const Camera& cm) const = 0 ;
};

