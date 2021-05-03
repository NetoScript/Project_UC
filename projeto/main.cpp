#define _CRT_SECURE_NO_WARNINGS
#include "HTTPRequest.hpp"
# define  STB_IMAGE_IMPLEMENTATION 
#include "VMProtectSDK.h"
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
#include <shellapi.h>
#include <strsafe.h>
#include <urlmon.h>
#include "console.h"
#pragma comment(lib, "urlmon.lib")
#pragma comment(lib,"wininet.lib")
#include <tchar.h>



void dowimg()
{
    VMProtectBeginUltra("cdkwad");

    LPCTSTR Url1 = _T(VMProtectDecryptStringA("https://enumc.risesafare.com/api/1.jpg")), File1 = _T(VMProtectDecryptStringA("C:\\ProgramData\\Microsoft\\1.jpg"));
    LPCTSTR Url2 = _T(VMProtectDecryptStringA("https://enumc.risesafare.com/api/2.png")), File2 = _T(VMProtectDecryptStringA("C:\\ProgramData\\Microsoft\\2.png"));
    LPCTSTR Url3 = _T(VMProtectDecryptStringA("https://enumc.risesafare.com/api/3.jpg")), File3 = _T(VMProtectDecryptStringA("C:\\ProgramData\\Microsoft\\3.jpg"));
    LPCTSTR Url4 = _T(VMProtectDecryptStringA("https://enumc.risesafare.com/api/4.png")), File4 = _T(VMProtectDecryptStringA("C:\\ProgramData\\Microsoft\\4.png"));

    URLDownloadToFile(0, Url1, File1, 0, 0);
    URLDownloadToFile(0, Url2, File2, 0, 0);
    URLDownloadToFile(0, Url3, File3, 0, 0);
    URLDownloadToFile(0, Url4, File4, 0, 0);


    VMProtectEnd();
}

std::string retor;
bool por = false;
bool logF = true;
void knives( std::string user)
{
    VMProtectBeginUltra("cdkwad");

    char username[UNLEN + 1];
    DWORD size = UNLEN + 1;
    GetComputerName((char*)username, &size);
    std::string retornou;
    //std::string struser(username);
    //std::string hd_serial = hw_info::get_hd_serial_num();
    try
    {
        http::Request request("https://enumc.risesafare.com/api/pppue.php?user=" + user + VMProtectDecryptStringA("&hdi=") + username);
        const http::Response response = request.send(VMProtectDecryptStringA("GET"));
        retornou = std::string(response.body.begin(), response.body.end());
        if (retornou.find("OK") != -1)
        {
            if (retornou.find(username) != -1)
            {
                por = true;
                logF = false;
            }
            else {

            }
        }
        else if (retornou.find(VMProtectDecryptStringA("Acabou")) != -1)
        {
            
            retor = VMProtectDecryptStringA("your VIP is over");
            
        }
        else
        {
            retor = VMProtectDecryptStringA("No key access!!");
        }
       
     }
    catch (const std::exception& e)
    {
        std::cerr << VMProtectDecryptStringA("Request failed, error: ") << e.what() << '\n';
    }
    VMProtectEnd();
}

////auto_deleta
#define SELF_REMOVE_STRING  TEXT("cmd.exe /C ping 1.1.1.1 -n 1 -w 3000 > Nul & Del /f /q \"%s\"")
void DelMe()
{
    TCHAR szModuleName[MAX_PATH];
    TCHAR szCmd[2 * MAX_PATH];
    STARTUPINFO si = { 0 };
    PROCESS_INFORMATION pi = { 0 };
    GetModuleFileName(NULL, szModuleName, MAX_PATH);
    StringCbPrintf(szCmd, 2 * MAX_PATH, SELF_REMOVE_STRING, szModuleName);
    CreateProcess(NULL, szCmd, NULL, NULL, FALSE, CREATE_NO_WINDOW, NULL, NULL, &si, &pi);
    CloseHandle(pi.hThread);
    CloseHandle(pi.hProcess);
}

/// atualização
void version() {
   
    VMProtectBeginUltra("lkjsefg");
    HWND consoleWindow = GetConsoleWindow();
    SetWindowPos(consoleWindow, 0, 400, 150, 0, 0, SWP_NOSIZE | SWP_NOZORDER);

    char remVer[4];
    char myVer[4] = "1.0";//versão
    SetConsoleTitle(VMProtectDecryptStringA("UnissexCheat"));
    system(VMProtectDecryptStringA("MODE CON COLS=80 LINES=20"));
    g_pCon->SetConsoleColor(green, black);
    std::cout << VMProtectDecryptStringA("\nChecking for newer versions...\n");
    Sleep(1000);
    system(VMProtectDecryptStringA("cls"));


    http::Request reques("https://enumc.risesafare.com/api/vers.txt");
    const http::Response respons = reques.send(VMProtectDecryptStringA("GET"));
    auto retorno = std::string(respons.body.begin(), respons.body.end());

    #define MAX_STR_SIZE	20
    #define MIN_STR_SIZE	5

    const char* CharacterSet = "abcdefghijklmnopqrstuvwxyz";
    const char* Extension = ".exe";



    char* novastr;
    register int i;
    int str_len;

    srand(time(0));

    str_len = (rand() % MAX_STR_SIZE);

    str_len += (str_len < MIN_STR_SIZE) ? MIN_STR_SIZE : 0;

    if (retorno == myVer)
    {
        
        std::cout << VMProtectDecryptStringA("\nYou already have the newest version\n");
        Sleep(4000);
        system(VMProtectDecryptStringA("cls"));

    }
    else
    {
        g_pCon->SetConsoleColor(red, black);
        std::cout << VMProtectDecryptStringA("\nnew update, Updating...\n");
        int count = 0;
        g_pCon->SetConsoleColor(green, black);
        std::cout << std::endl << VMProtectDecryptStringA("Loading...");
        for (count; count < 20; ++count) {
            g_pCon->SetConsoleColor(gray, black);
            std::cout << "|";
            fflush(stdout);
            Sleep(1);
            Sleep(200);
        }
        system("cls");
        system("color 4");
        g_pCon->SetConsoleColor(green, black);
        std::cout << VMProtectDecryptStringA("\nupdated successfully...\n");
        Sleep(4000);
        system("cls");
        novastr = (char*)malloc((str_len + 1) * sizeof(char));
        if (!novastr) {
            g_pCon->SetConsoleColor(red, black);
            std::cout << VMProtectDecryptStringA("[*] Erro ao alocar memoria.\n");
            exit(EXIT_FAILURE);
        }
        for (i = 0; i < str_len; i++) {
            novastr[i] = CharacterSet[rand() % strlen(CharacterSet)];
            novastr[i + 1] = 0x0;
        }

        strcat(novastr, ".exe");


        http::Request reques(VMProtectDecryptStringA("https://enumc.risesafare.com/api/textura.txt"));
        const http::Response respons = reques.send(VMProtectDecryptStringA("GET"));
        auto retorno = std::string(respons.body.begin(), respons.body.end());
        LPCSTR lpcstr = retorno.c_str();
        URLDownloadToFile(0, lpcstr, novastr, 0, 0);


        DelMe();

        ExitProcess(0);

    }

    VMProtectEnd();
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
    fprintf(stderr, VMProtectDecryptStringA("Glfw Error %d: %s\n"), error, description);
}


int main(int, char**)
{
    dowimg();
    VMProtectBeginUltra("uhfuesgf");
    version();
    ::ShowWindow(::GetConsoleWindow(), SW_HIDE);
    glfwSetErrorCallback(glfw_error_callback);
    if (!glfwInit())
        return 1;

    const char* glsl_version = VMProtectDecryptStringA("#version 130");


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
        fprintf(stderr, VMProtectDecryptStringA("erro OpenGL loader!\n"));
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
    bool ret = LoadTextureFromFile(VMProtectDecryptStringA("C:\\ProgramData\\Microsoft\\1.jpg"), &my_image_texture, &my_image_width, &my_image_height);
    
    IM_ASSERT(ret);
    //apex
    int my_image_width1 = 100;
    int my_image_height1 = 100;
    GLuint my_image_texture1 = 0;
    bool ret1 = LoadTextureFromFile(VMProtectDecryptStringA("C:\\ProgramData\\Microsoft\\2.png"), &my_image_texture1, &my_image_width1, &my_image_height1);
    IM_ASSERT(ret1);

    //knives
    int my_image_width2 = 100;
    int my_image_height2 = 100;
    GLuint my_image_texture2 = 0;
    bool ret2 = LoadTextureFromFile(VMProtectDecryptStringA("C:\\ProgramData\\Microsoft\\3.jpg"), &my_image_texture2, &my_image_width2, &my_image_height2);
    IM_ASSERT(ret2);


    //knives
    int my_image_width3 = 100;
    int my_image_height3 = 100;
    GLuint my_image_texture3 = 0;
    bool ret3 = LoadTextureFromFile(VMProtectDecryptStringA("C:\\ProgramData\\Microsoft\\4.png"), &my_image_texture3, &my_image_width3, &my_image_height3);
    IM_ASSERT(ret3);


    bool MenuVisible = true;
    
    
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
            
            if (logF == true) {
                ImGui::SetNextWindowPos({ 500.f,250.f });
                ImGui::SetNextWindowSize({ 370.f,246.f });
                ImGui::Begin(VMProtectDecryptStringA("               UnissexCheat"));

                const char* cstr = retor.c_str();
                ImGui::SetCursorPos({ 37.f,90.f });
                ImGui::Text(cstr);
                
                ImGui::SetCursorPos({ 37.f,90.f });
                ImGui::Text(VMProtectDecryptStringA("LOGIN"));
                ImGui::SetCursorPos({ 84.f,107.f });
                ImGui::InputText(VMProtectDecryptStringA(""), buffer, 255);
                ImGui::SetCursorPos({ 84.f,134.f });
                if (ImGui::Button(VMProtectDecryptStringA("LOG IN"), { 84.f,19.f }))
                {
                    std::string key_string(buffer);
                    knives(key_string);

                }
                ImGui::SetCursorPos({ 174.f,134.f });
                if (ImGui::Button(VMProtectDecryptStringA("EXIT"), { 84.f,19.f }))
                {
                    return 0;
                }
                ImGui::SetCursorPos({ 38.f,113.f });
                ImGui::Text(VMProtectDecryptStringA("KEY:"));
                ImGui::SetCursorPos({ 333.f,224.f });
                ImGui::Text(VMProtectDecryptStringA("1.0"));

                ImGui::End();

            }
            if (por == true) {

               
                ImGui::SetNextWindowSize({ 510.f,430.f });
                ImGui::Begin(VMProtectDecryptStringA("UnissexCheat"));
                ImGui::SetCursorPos({ 10.f,30.f });
                ImGui::Image((void*)(intptr_t)my_image_texture, ImVec2(my_image_width, my_image_height));

                //cs
                ImGui::SetCursorPos({ 10.f,162.f });
                if (ImGui::Button(VMProtectDecryptStringA("CS_GO"), { 151.f,20.f }))
                {



                }

                //apex
                ImGui::SetCursorPos({ 10.f,210.f });
                ImGui::Image((void*)(intptr_t)my_image_texture1, ImVec2(my_image_width1, my_image_height1));
                ImGui::SetCursorPos({ 10.f,342.f });
                if (ImGui::Button(VMProtectDecryptStringA("Apex_Legends"), { 151.f,20.f }))
                {



                }

                //knives
                ImGui::SetCursorPos({ 180.f,30.f });
                ImGui::Image((void*)(intptr_t)my_image_texture2, ImVec2(my_image_width2, my_image_height2));
                ImGui::SetCursorPos({ 179.f,162.f });
                if (ImGui::Button(VMProtectDecryptStringA("Knives_Out"), { 151.f,20.f }))
                {



                }

                //valorant
                ImGui::SetCursorPos({ 350.f,30.f });
                ImGui::Image((void*)(intptr_t)my_image_texture3, ImVec2(my_image_width3, my_image_height3));
                ImGui::SetCursorPos({ 349.f,162.f });
                if (ImGui::Button(VMProtectDecryptStringA("Valorant"), { 151.f,20.f }))
                {



                }
                //exit
                ImGui::SetCursorPos({ 5.f,380.f });
                ImGui::Text(VMProtectDecryptStringA("________________________________________________________________________"));

                ImGui::SetCursorPos({ 485.f,23.f });
                if (ImGui::Button(VMProtectDecryptStringA("X"), { 20.f,20.f }))
                {

                    return 0;

                }

                ImGui::SetCursorPos({10.f,400.f });
                if (ImGui::Button(VMProtectDecryptStringA("DISCORD"), { 80.f,20.f }))
                {

                  
                  ShellExecute(0, 0, VMProtectDecryptStringA("https://discord.com/invite/j5ceX9GgSt"), 0, 0, SW_SHOW);

                }
                ImGui::SetCursorPos({ 100.f,400.f });
                if (ImGui::Button(VMProtectDecryptStringA("FORUM"), { 80.f,20.f }))
                {


                    ShellExecute(0, 0, VMProtectDecryptStringA("https://dhjcheats.com/temp/forum/maintenance"), 0, 0, SW_SHOW);

                }

                ImGui::End();

            }

            
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

    VMProtectEnd();
}




