add_library(
	Dearimgui 
	STATIC
	imgui.cpp
	imgui_demo.cpp
	imgui_draw.cpp
	imgui_tables.cpp
	imgui_widgets.cpp
	backends/imgui_impl_opengl3.cpp
	backends/imgui_impl_glfw.cpp
)

target_include_directories(
	Dearimgui
	PUBLIC "${PROJECT_SOURCE_DIR}/vendor/imgui"
	PUBLIC "${PROJECT_SOURCE_DIR}/vendor/imgui/backends"	
)