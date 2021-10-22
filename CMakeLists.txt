cmake_minimum_required(VERSION 3.20)
project(draughts2)

set(CMAKE_CXX_STANDARD 14)

add_executable(draughts2 src/main.cpp
        src/view/console.cpp src/view/console.hpp
        src/board/board.cpp src/board/board.hpp
        src/board/draughts_board.cpp src/board/draughts_board.hpp
        src/board/position.cpp src/board/position.hpp
        src/board/pieces/pawn.cpp src/board/pieces/pawn.hpp)

