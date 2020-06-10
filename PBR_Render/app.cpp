#include"ui.h"
#include"drawable/triangle.h"

int main(int, char**)
{
	ui myui;
	
	myui.init();
	
	// set up vertex data (and buffer(s)) and configure vertex attributes
	// ------------------------------------------------------------------
	triangle tr;

	while(!glfwWindowShouldClose(myui.getWindow()))
	{
		glfwPollEvents();

		// Start the Dear ImGui frame
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();
		myui.set();

		// Rendering
		ImGui::Render();
		int display_w, display_h;
		glfwGetFramebufferSize(myui.getWindow(), &display_w, &display_h);
		glViewport(0, 0, display_w, display_h);
		glClearColor(myui.getColor().x, myui.getColor().y, myui.getColor().z, myui.getColor().w);
		glClear(GL_COLOR_BUFFER_BIT);

		// Our draw
		tr.draw();
		myui.draw();
		//------------
		
		glfwSwapBuffers(myui.getWindow());
	}
	
	myui.end();
	return 0;
}