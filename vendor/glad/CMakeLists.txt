add_library(
    glad
    STATIC
    glad.c
    glad.h
    khrplatform.h
)

target_include_directories(
	glad
	PUBLIC "${PROJECT_SOURCE_DIR}/vendor/glad"
)