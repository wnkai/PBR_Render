#pragma once
#include <iostream>
#include <cmath>
#include <memory>
#include <mutex>
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "shader.h"
#include "../camera.h"
#include <stb_image.h>

class material
{
public:
	static const string shader_name;
	material() {};
	virtual ~material() {};
	virtual void apply(const Camera& cm) = 0;
};