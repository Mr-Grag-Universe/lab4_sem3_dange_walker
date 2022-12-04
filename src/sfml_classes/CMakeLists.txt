cmake_minimum_required(VERSION 3.16)
project(SFML_graphic)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})

include_directories(OpenGL)
include_directories(OpenGL/include) # OpenGL/include has to contain the required OpenGL's .h files
include_directories(OpenGL/lib) # OpenGL/lib has to contain the required OpenGL's .lib files
include_directories(../libs/SFML)

add_library(${PROJECT_NAME}
    sfml_object.cpp
    sfml_common.hpp
    sfml_object.hpp
    sfml_sound.hpp
)

find_package(OpenGL REQUIRED)

target_link_libraries(${PROJECT_NAME} ${OPENGL_gl_LIBRARY})
target_link_libraries(${PROJECT_NAME} sfml-system sfml-window sfml-graphics sfml-audio ${SFML_DEPENDENCIES})
message("SUCCESSFULL linking")

# =========================

target_include_directories(${PROJECT_NAME} PRIVATE "../lib" "../objects")
target_link_libraries(${PROJECT_NAME} sfml-system sfml-window sfml-graphics sfml-audio)
if (UNIX)
   target_link_libraries(${PROJECT_NAME} pthread)
endif (UNIX)

if(MSVC)
   foreach(lib ${SFML_LIBS})
      get_target_property(lib_path ${lib} LOCATION)
      file(COPY ${lib_path} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
   endforeach()
endif(MSVC)