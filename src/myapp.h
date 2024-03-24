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
            unsigned int fbo = 0;
            unsigned int texture = 0;
            unsigned int rbo = 0;

    };

    void ShowDockWindow();
    
    void ShowOpenGLWindow();
    void ShowPropertiesWindow();

}