cmake_minimum_required(VERSION "3.26")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project("My Project")

find_package(glfw3 3.3 REQUIRED)
find_package(OpenGL REQUIRED)

add_executable(3dviz "src/main.cpp" "src/myapp.cpp") 

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

target_link_libraries(3dviz glfw)
target_link_libraries(3dviz OpenGL::GL)

add_subdirectory("vendor/imgui")
add_subdirectory("vendor/glad")


target_include_directories( 
	3dviz
	PUBLIC "${PROJECT_SOURCE_DIR}/src"
	PUBLIC "${PROJECT_SOURCE_DIR}/vendor"
	PUBLIC "${PROJECT_SOURCE_DIR}/vendor/glad"
	PUBLIC "${PROJECT_SOURCE_DIR}/vendor/imgui"
	PUBLIC "${PROJECT_SOURCE_DIR}/vendor/imgui/backends"
)

target_link_libraries(3dviz Dearimgui)
target_link_libraries(3dviz glad)
