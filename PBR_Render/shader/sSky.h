#pragma once
#include "shader.h"
class sSky :
	public Shader<sSky>
{
public:
	static void apply(glm::mat4& view, glm::mat4& projection)
	{
		GetInstance().use();
		GetInstance().setInt("skybox", 0);
		GetInstance().setMat4("view", view);
		GetInstance().setMat4("projection", projection);
	}
	static GLuint getID()
	{
		return GetInstance().ID;
	}
private:
	sSky() :Shader("shader/sky.vs", "shader/sky.fs")
	{};
	~sSky() {};

	friend Shader<sSky>;
	friend class auto_ptr<sSky>;

	sSky(const sSky&) = delete;
	sSky& operator =(const sSky&) = delete;

};

