#pragma once
#include "drawable.h"
#include "../material/mSky.h"
#include <stb_image.h>
class sky :public drawable
{
private:
	static GLfloat vertices[];
public:
	sky();
	virtual void draw(const Camera& cm) const override;
};

