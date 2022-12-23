cmake_minimum_required(VERSION 3.16)
project(Game_finall)

set(CMAKE_CXX_STANDARD 20)
# set(CMAKE_PREFIX_PATH C:/Users/Stephan/Desktop/vs_code_game/SFML-2.5.1)

# set(STATIC_FILES_SRC_PATH "/home/stepan/Рабочий стол/vs_code_game/src/static/")
# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
# # set(SFML_DIR C:/Users/Stephan/Desktop/vs_code_game/SFML-2.5.1/lib/cmake/SFML)
# set(SFML_STATIC_LIBRARIES FALSE)


include_directories(OpenGL)
include_directories(OpenGL/include) # OpenGL/include has to contain the required OpenGL's .h files
include_directories(OpenGL/lib) # OpenGL/lib has to contain the required OpenGL's .lib files

include_directories(libs/SFML)
add_subdirectory(libs/SFML)

# =========================

include_directories(alive_obj physics environment)

set(SOURCES
   # static/first_room.txt

   boot_menu.cpp
   
   main.cpp
   interraction.cpp
   objects/Object.cpp
   objects/Object.hpp
   World.cpp
   Map.cpp

   physics/Hitbox.cpp
   draw/Draw.cpp

   containers/Box.cpp
   containers/Chest.cpp
   containers/BackPack.cpp

   weapon/Sward.cpp

   my_stl_containers/include/vector.hpp

   constants.hpp
   )

add_executable(${PROJECT_NAME} ${SOURCES})

add_subdirectory(my_stl_containers)
add_subdirectory(game)
add_subdirectory(menu)
add_subdirectory(backpack_menu)
add_subdirectory(message_menu)
add_subdirectory(sfml_classes)
add_subdirectory(alive_obj)
add_subdirectory(environment)
add_subdirectory(texture_engine)
add_subdirectory(loot)
add_subdirectory(events)
message("SUCCESSFULL adding directories")
# target_link_libraries(game my_stl)
# # target_include_directories(sfml_game PUBLIC SFML-2.5.1/include)

# # target_compile_definitions(sfml_game PRIVATE SFML_STATIC)

# # target_link_libraries(game glfw glad)
target_link_libraries(${PROJECT_NAME} ${OPENGL_gl_LIBRARY})

# # find_package(SFML COMPONENTS graphics REQUIRED)
find_package(OpenGL REQUIRED)
target_include_directories(${PROJECT_NAME}
   PRIVATE
   my_stl_containers

   game
   menu
   backpack_menu
   message_menu

   alive_obj
   objects
   sfml_classes
   environment

   events
)
target_link_libraries(${PROJECT_NAME} sfml-system sfml-window sfml-graphics ${SFML_DEPENDENCIES} vector environment events)
target_link_libraries(alive_objects sfml-system sfml-window sfml-graphics ${SFML_DEPENDENCIES} loot)
target_link_libraries(${PROJECT_NAME} game menu backpack_menu messages SFML_graphic ${SFML_DEPENDENCIES} alive_objects)
target_link_libraries(game sfml-system sfml-window sfml-graphics alive_objects ${SFML_DEPENDENCIES})
target_link_libraries(menu sfml-system sfml-window sfml-graphics alive_objects ${SFML_DEPENDENCIES})
target_link_libraries(messages sfml-system sfml-window sfml-graphics alive_objects ${SFML_DEPENDENCIES})
target_link_libraries(backpack_menu sfml-system sfml-window sfml-graphics alive_objects ${SFML_DEPENDENCIES})
target_link_libraries(quest sfml-system sfml-window sfml-graphics ${SFML_DEPENDENCIES})

message("SUCCESSFULL linking")

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

option(BUILD_DOC "Build documentation" ON)

# check if Doxygen is installed
find_package(Doxygen)
if (DOXYGEN_FOUND)
    # set input and output files
    set(DOXYGEN_IN /home/stepan/Desktop/vs_code_game/src/docs/Doxyfile.in)
    set(DOXYGEN_OUT /home/stepan/Desktop/vs_code_game/src/Doxyfile)
    set(INPUT ./)

    # request to configure the file
    configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)
    message("Doxygen build started")

    # note the option ALL which allows to build the docs together with the application
    add_custom_target(all_doc_doxygen ALL
        COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        COMMENT "Generating API documentation with Doxygen"
        VERBATIM )
else (DOXYGEN_FOUND)
  message("Doxygen need to be installed to generate the doxygen documentation")
endif (DOXYGEN_FOUND)