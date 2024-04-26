#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

// Global variables
std::string log_message;
int display_w = 800, display_h = 600;
ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

void debug(std::string message){
	log_message = message;
}

void show_menu(){
	if(ImGui::BeginMainMenuBar()){
		if(ImGui::BeginMenu("File")){
            if (ImGui::MenuItem("Open..", "Ctrl+O")) { }
            if (ImGui::MenuItem("Save", "Ctrl+S"))   { }
            if (ImGui::MenuItem("Close", "Ctrl+W"))  { }
            ImGui::EndMenu();
		}
		ImGui::EndMainMenuBar();
	}
}

void show_hierarchy(){
	ImGui::Begin("Hierarchy");

    ImGui::End();
}

void show_project(){
	ImGui::Begin("Project");

	ImGui::End();
}

void show_console(){
	ImGui::Begin("Console");

	if(ImGui::Button("Clear")){
		debug("");
	}

	ImGui::SameLine();

	if(ImGui::Button("Debug")){
		debug("Debug message");
	}
	
	ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);

	ImGui::Text("%s", log_message.c_str());

	ImGui::End();
}

void show_scene(){
	ImGui::Begin("Scene");

	ImGui::End();
}

void show_inspector(){
	static float f = 0.0f;
	static int counter = 0;

	ImGui::Begin("Inspector");

	ImGui::Text("This is some useful text.");

	ImGui::SliderFloat("float", &f, 0.0f, 1.0f);
	ImGui::ColorEdit3("clear color", (float*)&clear_color);

	if (ImGui::Button("Button"))
		counter++;
	ImGui::SameLine();
	ImGui::Text("counter = %d", counter);

	ImGui::End();
}

int main(void){
	if(!glfwInit())
		return -1;
	
	GLFWwindow* window = glfwCreateWindow(display_w, display_h, "Ferx", NULL, NULL);
	if(!window){
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
	    std::cout << "Failed to initialize GLAD" << std::endl;
	    return -1;
	}
	    
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
	io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;

	ImGuiStyle& style = ImGui::GetStyle();
    ImVec4* colors = style.Colors;
	ImGui::StyleColorsDark();

	// Setup Platform/Renderer backends
	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL3_Init();

	while(!glfwWindowShouldClose(window)){
		// Set up draw data for rendering
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();

		// Setup docking
		ImGui::DockSpaceOverViewport(ImGui::GetMainViewport());
		colors[ImGuiCol_DockingEmptyBg] = clear_color;

		// Show windows
		show_menu();        
        show_hierarchy();
        show_scene();
		show_project();
		show_console();
		show_inspector();

        // Rendering
        ImGui::Render();
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClearColor(clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		ImGui::EndFrame();

		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	
    // Cleanup
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(window);
    glfwTerminate();

	return 0;
}
