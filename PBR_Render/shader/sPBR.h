#pragma once
#include "shader.h"
class sPBR :
	public Shader<sPBR>
{
public:
	static void apply(glm::mat4& model, glm::mat4& view, glm::mat4& projection)
	{
		GetInstance().use();
		GetInstance().setMat4("model", model);
		GetInstance().setMat4("view", view);
		GetInstance().setMat4("projection", projection);
		GetInstance().setInt("albedoMap", 0);
	}
	static GLuint getID()
	{
		return GetInstance().ID;
	}
private:
	sPBR() :Shader("shader/tran.vs", "shader/tran.fs")
	{};
	~sPBR() {};

	friend Shader<sPBR>;
	friend class auto_ptr<sPBR>;

	sPBR(const sPBR&) = delete;
	sPBR& operator =(const sPBR&) = delete;
};

