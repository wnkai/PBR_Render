#include"ui.h"
#include"drawable/triangle.h"
#include"drawable/sky.h"
#include "drawable/Model.h"
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>


int main(int, char**)
{
	ui myui;
	Camera camera(glm::vec3(0.0f, 0.0f, 2.0f));
	
	myui.init();
	glEnable(GL_DEPTH_TEST);

	// set up vertex data (and buffer(s)) and configure vertex attributes
	// ------------------------------------------------------------------
	triangle tr;
	sky sk;
	Model mod(string("resources/model/nanosuit/nanosuit.obj"));

	while(!glfwWindowShouldClose(myui.getWindow()))
	{
		glfwPollEvents();
		myui.process(camera);

		// Start the Dear ImGui frame
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();
		myui.set(camera);

		// Rendering
		ImGui::Render();
		int display_w, display_h;
		glfwGetFramebufferSize(myui.getWindow(), &display_w, &display_h);
		glViewport(0, 0, display_w, display_h);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// Our draw
		sk.draw(camera);
		tr.draw(camera);
		sPBR::GetInstance().setVec3("viewPos", camera.Position);
		mod.draw(camera);
		myui.draw();
		//------------
		
		glfwSwapBuffers(myui.getWindow());
		

		
		camera.updateCameraVectors();
	}
	
	myui.end();
	return 0;
}