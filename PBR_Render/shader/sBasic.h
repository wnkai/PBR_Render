#pragma once
#include "shader.h"

class sBasic :
	public Shader<sBasic>
{

public:
	static void apply()
	{
		GetInstance().use();
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

