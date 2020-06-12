#pragma once
#include "drawable.h"
#include "../material/mBasic.h"

class triangle:
	public drawable
{
private:
	static float vertices[];
	static GLuint indices[];
public:
	triangle();
	virtual void draw(const Camera& cm) const override;
};

