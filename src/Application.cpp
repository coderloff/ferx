#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

using std::string;

string log;
bool show_demo_window = true;
bool show_another_window = false;
ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

void debug(string message){
	log = message;
}

bool open_main = true;

void show_main(){
	if(ImGui::BeginMainMenuBar()){
		if(ImGui::BeginMenu("File")){
            if (ImGui::MenuItem("Open..", "Ctrl+O")) { /* Do stuff */ }
            if (ImGui::MenuItem("Save", "Ctrl+S"))   { /* Do stuff */ }
            if (ImGui::MenuItem("Close", "Ctrl+W"))  { show_another_window = false; }
            ImGui::EndMenu();
		}
		ImGui::EndMainMenuBar();
	}
}

void show_tools(){
	static float f = 0.0f;
	static int counter = 0;

	ImGui::Begin("Tools");                          // Create a window called "Hello, world!" and append into it.

	ImGui::Text("This is some useful text.");               // Display some text (you can use a format strings too)
	ImGui::Checkbox("Demo Window", &show_demo_window);      // Edit bools storing our window open/close state
	ImGui::Checkbox("Another Window", &show_another_window);

	ImGui::SliderFloat("float", &f, 0.0f, 1.0f);            // Edit 1 float using a slider from 0.0f to 1.0f
	ImGui::ColorEdit3("clear color", (float*)&clear_color); // Edit 3 floats representing a color

	if (ImGui::Button("Button"))                            // Buttons return true when clicked (most widgets return true when edited/activated)
		counter++;
	ImGui::SameLine();
	ImGui::Text("counter = %d", counter);

	ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
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

	ImGui::Text(log.c_str());

	ImGui::End();
}

void show_inspector(){
	ImGui::Begin("Inspector");

	ImGui::End();
}

int main(void){
	GLFWwindow* window;

	if(!glfwInit())
		return -1;

	window = glfwCreateWindow(640, 480, "Ferx", NULL, NULL);
	if(!window){
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	if(glewInit() != GLEW_OK)
		std::cout << "Error while initializing GLEW!\n";

	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
	ImGui::StyleColorsDark();
	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL3_Init();

	io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;

	while(!glfwWindowShouldClose(window)){
		glClear(GL_COLOR_BUFFER_BIT);

		glfwPollEvents();

		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();

        ImGui::DockSpaceOverViewport();

		// 1. Show the big demo window (Most of the sample code is in ImGui::ShowDemoWindow()! You can browse its code to learn more about Dear ImGui!).
        // if (show_demo_window)
        //     ImGui::ShowDemoWindow(&show_demo_window);

        // 2. Show a simple window that we create ourselves. We use a Begin/End pair to created a named window.
		show_main();
        
        show_tools();

		show_console();

        // 3. Show another simple window.
        if (show_another_window)
        {
            ImGui::Begin("Another Window", &show_another_window,ImGuiWindowFlags_MenuBar);   // Pass a pointer to our bool variable (the window will have a closing button that will clear the bool when clicked)
            if (ImGui::BeginMenuBar())
            {
                if (ImGui::BeginMenu("File"))
                {
                    if (ImGui::MenuItem("Open..", "Ctrl+O")) { /* Do stuff */ }
                    if (ImGui::MenuItem("Save", "Ctrl+S"))   { /* Do stuff */ }
                    if (ImGui::MenuItem("Close", "Ctrl+W"))  { show_another_window = false; }
                    ImGui::EndMenu();
                }
                ImGui::EndMenuBar();
            }
            ImGui::Text("Hello from another window!");
            ImGui::End();
        }
        
        // Rendering
        ImGui::Render();
        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClearColor(clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		glfwSwapBuffers(window);
	}

	glfwTerminate();

	return 0;
}
