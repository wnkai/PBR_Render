#include "mSky.h"

mSky::mSky()
{
	// load textures
	// -------------
	vector<std::string> faces
	{
		string("resources/textures/skybox/right.jpg"),
		string("resources/textures/skybox/left.jpg"),
		string("resources/textures/skybox/top.jpg"),
		string("resources/textures/skybox/bottom.jpg"),
		string("resources/textures/skybox/front.jpg"),
		string("resources/textures/skybox/back.jpg")
	};
	cubemapTexture = loadCubemap(faces);
}

void mSky::apply(const Camera & cm)
{
	auto view = glm::mat4(glm::mat3(cm.GetViewMatrix()));
	auto projection = glm::perspective(glm::radians(75.0f), 1280.0f / 720.0f, 0.1f, 10000.0f);

	glBindTexture(GL_TEXTURE_CUBE_MAP, cubemapTexture);
	sSky::apply(view, projection);
}
