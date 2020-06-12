#pragma once
#include "drawable.h"
#include "../material/mBasic.h"

class triangle:
	public drawable
{
private:
	static float vertices[18];
public:
	triangle();
	virtual void draw() override;
};

