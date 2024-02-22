cmake_minimum_required(VERSION "3.26")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project("My Project")

find_package(glfw3 3.3 REQUIRED)
find_package(OpenGL REQUIRED)

add_executable(3dviz "src/main.cpp") 

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

target_link_libraries(3dviz glfw)
target_link_libraries(3dviz OpenGL::GL)

add_subdirectory(
	"vendor/"
)

target_include_directories( 
	3dviz
	PUBLIC "${PROJECT_SOURCE_DIR}/src"
	PUBLIC "${PROJECT_SOURCE_DIR}/vendor"
	PUBLIC "${PROJECT_SOURCE_DIR}/vendor/backends"
	
	PUBLIC "${PROJECT_BINARY_DIR}/src"
	PUBLIC "${PROJECT_BINARY_DIR}/vendor"
	PUBLIC "${PROJECT_BINARY_DIR}/vendor/backends"
)

target_link_libraries(3dviz Dearimgui)
