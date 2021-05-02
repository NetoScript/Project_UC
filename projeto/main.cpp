#include "HTTPRequest.hpp"
# define  STB_IMAGE_IMPLEMENTATION 
#include  "stb_image.h " 
#include <iostream>
#include <Windows.h>
#include "GL/glew.h"
#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"
#include <stdio.h>
#include <GLFW/glfw3.h>
#include "Helpers.h"
#include "imgui_builder.h"
#include <Lmcons.h>
std::string retor;

void knives( std::string user, std::string livre)
{

    std::string livres = "livre";

    char username[UNLEN + 1];
    DWORD size = UNLEN + 1;
    GetComputerName((char*)username, &size);
    std::string retornou;
    //std::string struser(username);


    //std::string hd_serial = hw_info::get_hd_serial_num();
    try
    {
        http::Request request("https://enumc.risesafare.com/api/pppue.php?user=" + user +  "&hdi=" + username);
        const http::Response response = request.send("GET");

        retornou = std::string(response.body.begin(), response.body.end());

        if (retornou.find("OK") != -1)
        {
            if (retornou.find(username) != -1 || retornou.find(livres) != -1)
            {
               
                retor = retornou;
               std::cout <<  retor << "\n";
            }
            else {

            }

        }
        else if (retornou.find("Acabou") != -1)
        {

            std::cout << "\nyour VIP is over\n";
            Sleep(7000);
        }
        else
        {

            std::cout << "\nNo key access!!\n";
            Sleep(7000);
        }

    }
    catch (const std::exception& e)
    {
        std::cerr << "Request failed, error: " << e.what() << '\n';
    }

}
void ToggleButton(const char* str_id, bool* v)
{
    ImVec2 p = ImGui::GetCursorScreenPos();
    ImDrawList* draw_list = ImGui::GetWindowDrawList();
    float height = ImGui::GetFrameHeight();
    float width = height * 1.55f;
    float radius = height * 0.50f;
    if (ImGui::InvisibleButton(str_id, ImVec2(width, height)))
        *v = !*v;
    ImU32 col_bg;
    if (ImGui::IsItemHovered())
        col_bg = *v ? IM_COL32(145 + 20, 211, 68 + 20, 255) : IM_COL32(218 - 20, 218 - 20, 218 - 20, 255);
    else
        col_bg = *v ? IM_COL32(145, 211, 68, 255) : IM_COL32(218, 218, 218, 255);
    draw_list->AddRectFilled(p, ImVec2(p.x + width, p.y + height), col_bg, height * 0.5f);
    draw_list->AddCircleFilled(ImVec2(*v ? (p.x + width - radius) : (p.x + radius), p.y + radius), radius - 1.5f, IM_COL32(255, 255, 255, 255));
}



static void glfw_error_callback(int error, const char* description)
{
    fprintf(stderr, "Glfw Error %d: %s\n", error, description);
}


int main(int, char**)
{
    
    glfwSetErrorCallback(glfw_error_callback);
    if (!glfwInit())
        return 1;

    const char* glsl_version = "#version 130";


    GLFWmonitor* Monitor = glfwGetPrimaryMonitor();
    if (!Monitor)
    {
        return 0;
    }

    
   
   int Width = glfwGetVideoMode(Monitor)->width;
   int Height = glfwGetVideoMode(Monitor)->height;
   glfwWindowHint(GLFW_FLOATING, true);
   glfwWindowHint(GLFW_RESIZABLE, false);
   glfwWindowHint(GLFW_MAXIMIZED, true);
   glfwWindowHint(GLFW_TRANSPARENT_FRAMEBUFFER, true);

  
  
    // Creaar windows graphics
    GLFWwindow* Window = glfwCreateWindow(Width, Height, "", NULL, NULL);

    if (Window == NULL)
        return 1;

   glfwSetWindowAttrib(Window, GLFW_DECORATED, false);//remover barra branca


    glfwMakeContextCurrent(Window);
    glfwSwapInterval(1); // ativar vsync

   

    if (glewInit() != GLEW_OK)
    {
        fprintf(stderr, "erro OpenGL loader!\n");
        return 1;
    }

    // ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    
    ImGuiStyle& style = ImGui::GetStyle();

    // Config ImGui stilo
    ImGui::StyleColorsDark();
    //ImGui::StyleColorsClassic();
    
    style.WindowRounding = (5.0f);
    style.Colors[ImGuiCol_TitleBgActive] = ImColor(37, 41, 51,171);
    style.Colors[ImGuiCol_Button] = ImColor(56, 59, 69,171);
    style.Colors[ImGuiCol_FrameBg] = ImColor(62, 60, 64, 171);
    // Setup Platform/Renderer backends
    ImGui_ImplGlfw_InitForOpenGL(Window, true);
    ImGui_ImplOpenGL3_Init(glsl_version);

    //carregar imagem
    //csgo
    int my_image_width = 100;
    int my_image_height = 100;
    GLuint my_image_texture = 0;
    bool ret = LoadTextureFromFile("1.jpg", &my_image_texture, &my_image_width, &my_image_height);
    
    IM_ASSERT(ret);
    //apex
    int my_image_width1 = 100;
    int my_image_height1 = 100;
    GLuint my_image_texture1 = 0;
    bool ret1 = LoadTextureFromFile("2.png", &my_image_texture1, &my_image_width1, &my_image_height1);
    IM_ASSERT(ret1);

    //knives
    int my_image_width2 = 100;
    int my_image_height2 = 100;
    GLuint my_image_texture2 = 0;
    bool ret2 = LoadTextureFromFile("3.jpg", &my_image_texture2, &my_image_width2, &my_image_height2);
    IM_ASSERT(ret2);


    bool MenuVisible = true;
    bool por = false;
    
    ///main loop
    while (!glfwWindowShouldClose(Window))
    {
       
        
        glfwPollEvents();
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
       

        if (GetAsyncKeyState(VK_INSERT) & 1) 
        {

            MenuVisible = !MenuVisible;
            if (MenuVisible) {
                ShowMenu(Window);
            }
            else 
            {
                HideMenu(Window);
            }
        }
        static char buffer[14];
        if (MenuVisible) {
            //draw here
            

            ImGui::SetNextWindowSize({ 370.f,246.f });
            ImGui::Begin("               UnissexCheat");
            ImGui::SetCursorPos({ 37.f,90.f });
            ImGui::Text("LOGIN");
            ImGui::SetCursorPos({ 84.f,107.f });
            ImGui::InputText("", buffer, 255);
            ImGui::SetCursorPos({ 84.f,134.f });
            if (ImGui::Button("LOG IN", { 84.f,19.f }))
            {
                std::string key_string(buffer);
                knives(key_string,"livre");
                por = true;

            }
            ImGui::SetCursorPos({ 174.f,134.f });
            if (ImGui::Button("EXIT", { 84.f,19.f }))
            {
                return 0;
            }
            ImGui::SetCursorPos({ 38.f,113.f });
            ImGui::Text("KEY:");
            ImGui::SetCursorPos({ 333.f,224.f });
            ImGui::Text("1.0");


            if (por == true) {


                ImGui::SetNextWindowSize({ 510.f,380.f });
                ImGui::Begin("UnissexCheat");
                ImGui::SetCursorPos({ 10.f,30.f });
                ImGui::Image((void*)(intptr_t)my_image_texture, ImVec2(my_image_width, my_image_height));

                //cs
                ImGui::SetCursorPos({ 10.f,162.f });
                if (ImGui::Button("LOG IN", { 151.f,20.f }))
                {



                }

                //apex
                ImGui::SetCursorPos({ 10.f,210.f });
                ImGui::Image((void*)(intptr_t)my_image_texture1, ImVec2(my_image_width1, my_image_height1));
                ImGui::SetCursorPos({ 10.f,340.f });
                if (ImGui::Button("LOG IN", { 151.f,20.f }))
                {



                }


                //knives
                ImGui::SetCursorPos({ 180.f,30.f });
                ImGui::Image((void*)(intptr_t)my_image_texture2, ImVec2(my_image_width2, my_image_height2));
                ImGui::SetCursorPos({ 179.f,162.f });
                if (ImGui::Button("LOG IN", { 151.f,20.f }))
                {



                }


                ImGui::End();

            }


            ImGui::End();

            
        }

        // Rendering
        ImGui::Render();
        int display_w, display_h;
        glfwGetFramebufferSize(Window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());


        glfwSwapBuffers(Window);
          
    }
  
    // Cleanup
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(Window);
    glfwTerminate();
    
    return 0;
}




