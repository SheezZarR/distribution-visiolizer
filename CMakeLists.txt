cmake_minimum_required(VERSION "3.26")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project("My Project")

find_package(glfw3 3.3 REQUIRED)
find_package(OpenGL REQUIRED)

add_subdirectory(vendor)

add_executable(test "src/main.cpp") 

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

target_link_libraries(test INTERFACE glfw)
target_link_libraries(test INTERFACE OpenGL::GL)

target_link_libraries(test PUBLIC Dearimgui)
target_include_directories(test PUBLIC
	"${PROJECT_BINARY_DIR}"
	"${PROJECT_SOURCE_DIR}/vendor"
	"${PROJECT_SOURCE_DIR}/vendor/backends"
)
