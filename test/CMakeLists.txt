# Add Google Test Framework
# find_package(GTest REQUIRED)
# include_directories(${GTEST_INCLUDE_DIRS})

# # Add test source files
# file(GLOB TEST_SOURCES *.cpp)

# add_executable(runTests
#     BoardTest.cpp
#     ../src/Board.cpp # Ensure Board.cpp is linked
# )

# Add executable for tests
# add_executable(runTests ${TEST_SOURCES})

# # Link with GTest and GMock
# target_link_libraries(runTests GTest::GTest GTest::Main)

# # Register tests
# add_test(NAME RunAllTests COMMAND runTests)

# Add GoogleTest Framework
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

 # Add test executable
add_executable(runTests
    maintest.cpp       # Main entry point for tests
    BoardTest.cpp
    FriendPlayerTest.cpp
    ComputerTest.cpp
    PlayerTest.cpp
    ../src/Board.cpp
    ../src/Player.cpp
    ../src/Computer.cpp
    ../src/FriendPlayer.cpp
)

# Link test executable with GTest and GMock
target_link_libraries(runTests GTest::GTest GTest::Main)

# Register tests
add_test(NAME RunAllTests COMMAND runTests)