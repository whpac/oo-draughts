cmake_minimum_required(VERSION 3.20)
project(draughts2)

set(CMAKE_CXX_STANDARD 14)

add_executable(draughts2 src/main.cpp
        src/view/console_view.cpp src/view/console_view.hpp
        src/board/board.cpp src/board/board.hpp
        src/board/draughts_board.cpp src/board/draughts_board.hpp
        src/board/position.cpp src/board/position.hpp
        src/board/pieces/pawn.cpp src/board/pieces/pawn.hpp src/board/pieces/normal_pawn.cpp src/board/pieces/normal_pawn.hpp src/input/console_input.cpp src/input/console_input.hpp src/input/commands/command.cpp src/input/commands/command.hpp src/input/commands/move_command.cpp src/input/commands/move_command.hpp src/input/commands/quit_command.cpp src/input/commands/quit_command.hpp)

