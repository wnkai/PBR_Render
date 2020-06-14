#include "ui.h"

ui::ui()
{
}

void ui::init()
{
	glfwSetErrorCallback(glfw_error_callback);
	if (!glfwInit())
		return;

	const char* glsl_version = "#version 430";
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	window = glfwCreateWindow(1920, 1080, "PBR_Render", NULL, NULL);
	if (window == NULL)
		return;
	glfwMakeContextCurrent(window);
	glfwSwapInterval(1); // Enable vsync

	bool err = gladLoadGL() == 0;
	if (err)
	{
		fprintf(stderr, "Failed to initialize OpenGL loader!\n");
		return;
	}

	// Setup Dear ImGui context
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
	//io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

	// Setup Dear ImGui style
	ImGui::StyleColorsDark();
	//ImGui::StyleColorsClassic();

	// Setup Platform/Renderer bindings
	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL3_Init(glsl_version);

	show_demo_window = false;
	clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
}

void ui::set(Camera& cm)
{
	
	ImGui::BeginMainMenuBar();

	if (ImGui::BeginMenu("File"))
	{
		ImGui::MenuItem("Open");
		ImGui::MenuItem("Save");
		if (ImGui::MenuItem("Exit"))
		{
			exit(0);
		}
		ImGui::EndMenu();
	}

	if (ImGui::BeginMenu("Edit"))
	{
		ImGui::MenuItem("Copy");
		ImGui::EndMenu();
	}

	if (ImGui::BeginMenu("Help"))
	{
		if (ImGui::MenuItem("About"))
		{
			show_bout_window = !show_bout_window;
		}
		ImGui::Checkbox("Demo Window", &show_demo_window);      // Edit bools storing our window open/close state
		ImGui::EndMenu();
	}

	ImGui::EndMainMenuBar();

	// 1. Show the big demo window (Most of the sample code is in ImGui::ShowDemoWindow()! You can browse its code to learn more about Dear ImGui!).
	if (show_demo_window)
		ImGui::ShowDemoWindow(&show_demo_window);

	if (show_bout_window)
	{
		ImGui::Begin("About");
		ImGui::Text("A PBR Render Demo");
		ImGui::End();
	}

	// 2. Show a simple window that we create ourselves. We use a Begin/End pair to created a named window.
	{
		static float f = 0.0f;

		ImGui::Begin("Camera");   
		// Create a window called "Hello, world!" and append into it.
		ImGui::Checkbox("Can Mouse Rotate", &canMouseRotate);      // Edit bools storing our window open/close state

		ImGui::SliderFloat("Pitch", (float*)&cm.Pitch, -89.0f, 89.0f);
		ImGui::SliderFloat("Yaw", (float*)&cm.Yaw, -180.0f, 180.0f);
		ImGui::DragFloat3("Position", (float*)&cm.Position);


		ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
		//ImGui::e
		
		ImGui::End();
	}

}

void ui::process(Camera & cm)
{
	static double lastTime = glfwGetTime();
	double currentTime = glfwGetTime();
	float deltaTime = float(currentTime - lastTime);

	// Get mouse position
	
	if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_RIGHT) == GLFW_PRESS)
	{
		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
		cm.ProcessMouseMovement(ImGui::GetIO().MouseDelta.x,-ImGui::GetIO().MouseDelta.y);
	}
	else
	{
		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
	}

	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
	{
		cm.ProcessKeyboard(FORWARD, deltaTime);
	}
	// Move backward
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
	{
		cm.ProcessKeyboard(BACKWARD, deltaTime);
	}
	// Strafe left
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
	{
		cm.ProcessKeyboard(LEFT, deltaTime);
	}
	// Strafe right
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
	{
		cm.ProcessKeyboard(RIGHT, deltaTime);
	}
	
}

void ui::end()
{
	// Cleanup
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();

	glfwDestroyWindow(window);
	glfwTerminate();
}

void ui::draw()
{
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}
