cmake_minimum_required(VERSION 3.22)
project(w65510 C)

set(CMAKE_C_STANDARD 17)

add_executable(w65510 main.c helpers/helpers.h helpers/helper.c sorting/bubble/bubble.h sorting/bubble/bubble.c sorting/merge/merge.c sorting/merge/merge.h sorting/selection/selection.h sorting/selection/selection.c search/linear/linear.h search/binary/binary.h search/binary/binary.c search/linear/linear.c menu/menu.h menu/menu.c)
