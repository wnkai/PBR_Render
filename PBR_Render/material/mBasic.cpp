#include "mBasic.h"


mBasic::mBasic()
{
	glGenTextures(1, &albedoMap);
	glBindTexture(GL_TEXTURE_2D, albedoMap);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	// set texture filtering parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	int width, height, nrChannels;
	stbi_set_flip_vertically_on_load(false); // tell stb_image.h to flip loaded texture's on the y-axis.
	// The FileSystem::getPath(...) is part of the GitHub repository so we can find files on any IDE/platform; replace it with your own image path.
	unsigned char *data = stbi_load(string("resources/textures/rustediron-streaks/rustediron-streaks_basecolor.png").c_str(), &width, &height, &nrChannels, 0);
	if (data)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	stbi_image_free(data);
}

void mBasic::apply(const Camera& cm)
{

	auto model = glm::mat4(1.0);
	auto view = cm.GetViewMatrix();
	auto projection = glm::perspective(glm::radians(75.0f), 1280.0f / 720.0f, 0.1f, 1000.0f);

	glBindTexture(GL_TEXTURE_2D, albedoMap);
	sBasic::apply(model, view, projection);
}
