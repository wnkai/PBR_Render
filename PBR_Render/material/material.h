#pragma once
#include <iostream>
#include <cmath>
#include <memory>
#include <mutex>
#include "shader.h"

class material
{
public:
	static const string shader_name;
	material() {};
	virtual ~material() {};
	virtual void apply() = 0;
};


