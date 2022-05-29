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
    ChessLib/figures/*.h
    PlayerLib/player.h)
# set(PROJECT_SOURCES )

# add_executable(LoggerApp LoggerApp/LoggerApp.cpp ${PROJECT_SOURCES})

# add_executable(CollectionUnitTests UnitTests/CollectionUnitTest.cpp ${PROJECT_SOURCES})
# add_executable(LoggerUnitTests UnitTests/LoggerUnitTest.cpp ${PROJECT_SOURCES})
# target_link_libraries(LoggerUnitTests PUBLIC gtest_main)
# target_link_libraries(CollectionUnitTests PUBLIC gtest_main)