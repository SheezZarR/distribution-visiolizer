#include "imgui.h"

namespace MyApp {
    void RenderUI() {
        ImGui::Begin("My First IMGUI Window");

        ImGui::Text("Hello ImGUI!");    
    
        ImGui::End();
    }
}
