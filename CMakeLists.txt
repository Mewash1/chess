cmake_minimum_required(VERSION 3.14)
project(DeepBlue_2.0)

# GoogleTest requires at least C++11
set(CMAKE_CXX_STANDARD 11)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG main
)
FetchContent_MakeAvailable(googletest)


set(PROJECT_SOURCES
    BoardLib/board.h
    BoardLib/board.cpp
    ChessLib/figures/figure.cpp
    ChessLib/figures/bishop.h
    ChessLib/figures/figure.h
    ChessLib/figures/king.h
    ChessLib/figures/knight.h
    ChessLib/figures/pawn.h
    ChessLib/figures/queen.h
    ChessLib/figures/rook.h
    PlayerLib/player.cpp
    PlayerLib/include_all_figures.h
    PlayerLib/player.h)
# set(PROJECT_SOURCES)

add_executable(temp temp.cpp ${PROJECT_SOURCES})

# add_executable(CollectionUnitTests UnitTests/CollectionUnitTest.cpp ${PROJECT_SOURCES})
# add_executable(LoggerUnitTests UnitTests/LoggerUnitTest.cpp ${PROJECT_SOURCES})
# target_link_libraries(LoggerUnitTests PUBLIC gtest_main)
# target_link_libraries(CollectionUnitTests PUBLIC gtest_main)
