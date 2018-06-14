cmake_minimum_required(VERSION 3.9)
project(Fract_ol C)

set(CMAKE_C_STANDARD 11)

if(UNIX AND NOT APPLE)
    set(LINUX TRUE)
endif()

# if(NOT LINUX) should work, too, if you need that
if(LINUX)
    message(STATUS ">>> Linux")
    link_directories(libmlx libft)
    include_directories(libmlx libft)
    set ( PROJECT_LINK_LIBS  libmlx_Linux.a libft.a)
    set (LINKED_LIBS  -lXext -lX11 -lm )
    # linux stuff here
else()
    message(STATUS ">>> Not Linux")
    FIND_LIBRARY(OpenGL_LIBRARY OpenGL)
    INCLUDE_DIRECTORIES ( /System/Library/Frameworks )
    FIND_LIBRARY(COCOA_LIBRARY Cocoa)
    FIND_LIBRARY(GLUT_LIBRARY GLUT )
    MARK_AS_ADVANCED (COCOA_LIBRARY
            GLUT_LIBRARY
            OpenGL_LIBRARY)
    SET(EXTRA_LIBS ${COCOA_LIBRARY} ${GLUT_LIBRARY} ${OpenGL_LIBRARY})
    link_directories(minilibx_macos libft)
    include_directories(minilibx_macos libft)
    set ( PROJECT_LINK_LIBS libmlx.a libft.a)
    set (LINKED_LIBS  -lmlx -lm)
    # stuff that should happen not on Linux
endif()

add_executable(Fract_ol src/main.c include/fractol.h src/init_env.c src/remove_env.c src/key_hooks.c src/julia.c src/complex.c src/mandelbrot.c src/map_legend.c src/mouse_hooks.c src/burningship.c)
target_link_libraries(Fract_ol ${PROJECT_LINK_LIBS} -Werror -Wextra -Wall ${LINKED_LIBS} ${EXTRA_LIBS})