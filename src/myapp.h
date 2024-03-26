#pragma once

namespace MyApp {

    class FrameBuffers {
        public:
            FrameBuffers(const int width, const int height);
            ~FrameBuffers();
            
            unsigned int getFrameTexture();
            void RescaleFrameBuffer(const int width, const int height);
            void Bind() const;
            void Unbind() const;
        
        private:
            GLuint fbo = 0;
            GLuint texture = 0;
            GLuint rbo = 0;

    };

    void ShowDockWindow();
    
    void ShowOpenGLWindow();
    void ShowOpenGLWindow(FrameBuffers* sceneBuf);
    void ShowPropertiesWindow();

}