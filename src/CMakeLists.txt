cmake_minimum_required(VERSION 3.16)
project(game)

set(CMAKE_CXX_STANDARD 20)
# set(CMAKE_PREFIX_PATH C:/Users/Stephan/Desktop/vs_code_game/SFML-2.5.1)

# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
# # set(SFML_DIR C:/Users/Stephan/Desktop/vs_code_game/SFML-2.5.1/lib/cmake/SFML)
# set(SFML_STATIC_LIBRARIES FALSE)


include_directories(OpenGL)
include_directories(OpenGL/include) # OpenGL/include has to contain the required OpenGL's .h files
include_directories(OpenGL/lib) # OpenGL/lib has to contain the required OpenGL's .lib files

# include_directories(SYSTEM "C:/Users/Stephan/Desktop/vs_code_game/src/include/")

# set(SFML_STATIC_LIBRARIES TRUE)
# # include_directories(libs/glfw-3.3.8/include libs/glfw-3.3.8/deps)
# # add_subdirectory(libs/glfw-3.3.8)

# set(UDEV_PATH_INCLUDES "/opt/udev/include")
# set(SFML_DIR "C:/prog_libs/SFML-2.5.1-windows-gcc-7.3.0-mingw-64-bit/SFML-2.5.1")
# set(CMAKE_PREFIX_PATH "C:/prog_libs/SFML-2.5.1-windows-gcc-7.3.0-mingw-64-bit/SFML-2.5.1")
# find_package(SFML REQUIRED COMPONENTS audio graphics window system)

include_directories(libs/SFML)
add_subdirectory(libs/SFML)

# =========================

include_directories(alive_obj loot physics)

set(SOURCES
   static/first_room.txt

   main.cpp
   Object.cpp
   Object.hpp
   World.cpp
   Map.cpp

   environment/Env.cpp
   environment/Floor.cpp
   environment/Door.cpp
   environment/Wall.cpp
   
   alive_obj/Alive.cpp
   alive_obj/Character.cpp

   physics/Hitbox.cpp
   draw/Draw.cpp

   containers/Box.cpp
   containers/Chest.cpp
   containers/BackPack.cpp

   weapon/Sward.cpp
   )

add_executable(game ${SOURCES})
# # target_include_directories(sfml_game PUBLIC SFML-2.5.1/include)

# # target_compile_definitions(sfml_game PRIVATE SFML_STATIC)

# # target_link_libraries(game glfw glad)
target_link_libraries(game ${OPENGL_gl_LIBRARY})

# # find_package(SFML COMPONENTS graphics REQUIRED)
find_package(OpenGL REQUIRED)
target_link_libraries(game sfml-system sfml-window sfml-graphics ${SFML_DEPENDENCIES})

# target_link_libraries(sfml_game ${GLFW})
# target_link_libraries(sfml_game ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
# target_link_libraries(sfml_game sfml-graphics sfml-audio)


# =========================

target_include_directories(${PROJECT_NAME} PRIVATE "include" "lib")
target_link_libraries(${PROJECT_NAME} sfml-system sfml-window sfml-graphics sfml-audio)
if (UNIX)
   target_link_libraries(${PROJECT_NAME} pthread)
endif (UNIX)

# Copy data dir to the binary directory
# file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/data DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

if(MSVC)
   foreach(lib ${SFML_LIBS})
      get_target_property(lib_path ${lib} LOCATION)
      file(COPY ${lib_path} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
   endforeach()
endif(MSVC)


# ==================================
# ================================