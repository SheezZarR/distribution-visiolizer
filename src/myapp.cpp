#include "imgui.h"
#include "imgui_internal.h"
#include "myapp.h"

namespace MyApp {
    void RenderUI() {    
        ImGui::Begin("Opengl");

        ImGui::Text("Hello ImGUI!");    
    
        ImGui::End();
    }

    void RenderUI2() {
        ImGui::Begin("Properties");

        ImGui::Text("Nope...");

        ImGui::End();
    }

    void ShowDockWindow()
    {
        ImGuiID main_id = ImGui::DockSpaceOverViewport(ImGui::GetMainViewport());
        static bool first_time = true;

        if (first_time) {
            first_time = false;

            ImGuiID ogl_id = ImGui::GetID("Opengl");
            ImGuiID properties_id = ImGui::GetID("Properties");

            ImGui::DockBuilderAddNode(main_id, ImGuiDockNodeFlags_DockSpace);
            ImGui::DockBuilderSplitNode(main_id, ImGuiDir_Left, 0.3f, &ogl_id, &properties_id);
            ImGui::DockBuilderDockWindow("Opengl", ogl_id);
            ImGui::DockBuilderDockWindow("Properties", properties_id);

        }   
        
        
        /*
        // Splits is accurate in this block.

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
        
        //ImGuiWindowFlags_NoTitleBar
        window_flags |= (
            ImGuiWindowFlags_NoCollapse |
            ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove |
            ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus
        );
        
        ImGui::Begin("MyDockSpace", nullptr, window_flags);
        ImGui::PopStyleVar(3);

        ImGuiID dockspace_id = ImGui::GetID("MyDockSpace");
        
        if (ImGui::DockBuilderGetNode(dockspace_id) == NULL) {
            // TODO: respect .ini file (probably solved with the statement above)
            
            ImGui::DockBuilderRemoveNode(dockspace_id); // clearing existing layout
            ImGui::DockBuilderAddNode(dockspace_id, dockspace_flags);
            
            ImGuiID ogl_window_id = ImGui::GetID("Opengl");
            ImGuiID prop_window_id = ImGui::GetID("Properties");

            ImGui::DockBuilderSplitNode(
                dockspace_id,
                ImGuiDir_Right,
                0.25f,
                &prop_window_id,
                &ogl_window_id
            );

            ImGui::DockBuilderDockWindow("Opengl", ogl_window_id);
            ImGui::DockBuilderDockWindow("Properties", prop_window_id);
            ImGui::DockBuilderFinish(dockspace_id);


        }

        ImGui::DockSpace(dockspace_id, ImVec2(0.0f, 0.0f));

        ImGui::End();
        */ 
    }


}
