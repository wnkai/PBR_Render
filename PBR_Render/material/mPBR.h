#pragma once
#include "material.h"
#include "sPBR.h"
#include <stb_image.h>
class mPBR :
	public material
{
public:
	mPBR();
	virtual void apply(const Camera& cm) override;
private:

};

