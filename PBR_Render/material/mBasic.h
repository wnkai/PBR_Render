#pragma once
#include "material.h"
#include "sBasic.h"
#include <stb_image.h>

class mBasic :
	public material
{
public:

	mBasic();
	virtual void apply(const Camera& cm) override;
private:
	GLuint albedoMap;
};

