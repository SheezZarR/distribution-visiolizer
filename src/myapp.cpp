#include "imgui.h"
#include "myapp.h"

namespace MyApp {
    void ShowDockWindow()
    {
        static ImGuiDockNodeFlags dockspace_flags = ImGuiDockNodeFlags_None;

        ImGuiWindowFlags window_flags = (
            ImGuiWindowFlags_NoDocking | 
            ImGuiWindowFlags_MenuBar
        );

        const ImGuiViewport* viewport = ImGui::GetMainViewport();
        ImGui::SetNextWindowPos(viewport->WorkPos);
        ImGui::SetNextWindowSize(viewport->WorkSize);
        ImGui::SetNextWindowViewport(viewport->ID);
        ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
        ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
        ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));
        

        window_flags |= (
            ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse |
            ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove |
            ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus
        );

        ImGui::Begin("Main Dockspace", nullptr, window_flags);

        ImGui::PopStyleVar(3);

        ImGuiID dockspace_id = ImGui::GetID("MainDockspace");
        ImGui::DockSpace(dockspace_id, ImVec2(0.0f, 0.0f), dockspace_flags);

        ImGui::End();

    }

    void RenderUI(bool* show_my_ui) {
        
        ImGui::Begin("My First IMGUI Window", show_my_ui);

        ImGui::Text("Hello ImGUI!");    
    
        ImGui::End();
    }

    void RenderUI2() {
        ImGui::Begin("My Second Window");

        ImGui::Text("Nope...");

        ImGui::End();
    }
}
