#pragma once
#include "shader.h"

class sBasic :
	public Shader<sBasic>
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
	sBasic():Shader("shader/tran.vs","shader/tran.fs")
	{};
	~sBasic() {};

	friend Shader<sBasic>;
	friend class auto_ptr<sBasic>;

	sBasic(const sBasic&) = delete;
	sBasic& operator =(const sBasic&) = delete;
};

