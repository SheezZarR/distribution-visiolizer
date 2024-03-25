#include <iostream>

#include "glad.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include "imgui.h"
#include "imgui_internal.h"
#include "myapp.h"

#define GL_SILENCE_DEPRECATION
#if defined(IMGUI_IMPL_OPENGL_ES2)
#include <GLES2/gl2.h>
#endif
#include <GLFW/glfw3.h> // Will drag system OpenGL headers

namespace MyApp {
    FrameBuffers::FrameBuffers(const int width, const int height) {
        glGenFramebuffers(1, &fbo);
        glBindFramebuffer(GL_FRAMEBUFFER, fbo);

        glGenTextures(1, &texture);
        glBindTexture(GL_TEXTURE_2D, texture);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, texture, 0);

        glGenRenderbuffers(1, &rbo);
        glBindRenderbuffer(GL_RENDERBUFFER, rbo);
        glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, width, height);
        glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, rbo);

        if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
            std::cout << "ERROR::FRAMEBUFFER:: Framebuffer is not complete!" << std::endl;

        glBindFramebuffer(GL_FRAMEBUFFER, 0);
        glBindTexture(GL_TEXTURE_2D, 0);
        glBindRenderbuffer(GL_RENDERBUFFER, 0);
    }

    FrameBuffers::~FrameBuffers() 
    {
        glDeleteFramebuffers(1, &fbo);
        glDeleteTextures(1, &texture);
        glDeleteRenderbuffers(1, &rbo);
    }

    unsigned int FrameBuffers::getFrameTexture() 
    {
        return texture;
    }
    
    void FrameBuffers::RescaleFrameBuffer(const int width, const int height) 
    {
        glBindTexture(GL_TEXTURE_2D, texture);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, texture, 0);

        glBindRenderbuffer(GL_RENDERBUFFER, rbo);
        glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, width, height);
        glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, rbo);
    }
    void FrameBuffers::Bind() const 
    {
        glBindFramebuffer(GL_FRAMEBUFFER, fbo);
    }

    void FrameBuffers::Unbind() const 
    {
        glBindFramebuffer(GL_FRAMEBUFFER, 0);
    }

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
        
        //ImGuiWindowFlags_NoTitleBar
        window_flags |= (
            ImGuiWindowFlags_NoCollapse |
            ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove |
            ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus
        );
        
        ImGui::Begin("GlobalDockSpace", nullptr, window_flags);
        ImGui::PopStyleVar(3);

        ImGuiID dockspace_id = ImGui::GetID("GlobalDockSpace");
        
        if (ImGui::DockBuilderGetNode(dockspace_id) == NULL) 
        {
            // TODO: respect .ini file (probably solved with the statement above)
            // TODO: :nerd: determine whether to include this block of code at the start. 
            
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

    }

    void ShowOpenGLWindow() {
        
        ImGui::Begin("Opengl");
        { 
            ImGui::Text("Hi ImGui!");

            ImGui::BeginChild("Viewport");
            {
                ImGui::Text("Silly goober");
            }
            ImGui::EndChild();
        }
        ImGui::End();
    }

    void ShowOpenGLWindow(FrameBuffers* sceneBuf) {
        
        ImGui::Begin("Opengl");
        { 
            ImGui::Text("Hi ImGui!");

            ImGui::BeginChild("Viewport");
            // const float width = ImGui::GetContentRegionAvail().x;
            // const float height = ImGui::GetContentRegionAvail().y;

            // *m_width = width;
            // *m_height = height;

            ImGui::Image(
                (ImTextureID)sceneBuf->getFrameTexture(),
                ImGui::GetContentRegionAvail(),
                ImVec2(0, 1),
                ImVec2(1, 0)
            );

            ImGui::EndChild();
        }
        ImGui::End();
    }

    void ShowPropertiesWindow() 
    {        
        ImGui::Begin("Properties");

        ImGui::Text("Nope...");

        ImGui::End();
        
        // TODO: dock the window
        ImGui::ShowDemoWindow();
    }
}
