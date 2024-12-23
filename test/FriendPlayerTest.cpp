#include <gtest/gtest.h>
#include "FriendPlayer.hpp"
#include "Board.hpp"
#include <sstream>
#include <iostream>

// Test fixture for FriendPlayer tests
class FriendPlayerTest : public ::testing::Test
{
protected:
    ConnectFourBoard board;                    // Board instance for testing
    FriendPlayer player;                       // FriendPlayer instance

    // Initialize board and player before each test
    FriendPlayerTest() : player("Player1", 'X') {}

    void SetUp(void) override
    {
        board.reset(); // Ensure board is cleared before each test
    }
};

// Test 1: Make a valid move
TEST_F(FriendPlayerTest, MakeValidMove)
{
    // Simulate user input for column 4 (1-based index)
    std::istringstream input("4\n");
    std::cin.rdbuf(input.rdbuf()); // Redirect input stream for testing

    // Make move
    player.makeMove(board);

    // Verify that 'X' is placed in column 3 (0-based index)
    EXPECT_EQ(board.getGrid()[5][3], 'X'); // Check bottom row, 4th column
}

// Test 2: Handle invalid input (non-numeric)
TEST_F(FriendPlayerTest, HandleInvalidInputNonNumeric)
{
    // Simulate invalid input followed by valid input
    std::istringstream input("abc\n4\n");
    std::cin.rdbuf(input.rdbuf()); // Redirect input stream

    // Make move
    player.makeMove(board);

    // Verify that 'X' is placed in column 3 (0-based index)
    EXPECT_EQ(board.getGrid()[5][3], 'X');
}

// Test 3: Handle invalid input (out-of-range input)
TEST_F(FriendPlayerTest, HandleOutOfRangeInput)
{
    // Simulate out-of-range input (-1, 8) followed by valid input (5)
    std::istringstream input("-1\n8\n5\n");
    std::cin.rdbuf(input.rdbuf()); // Redirect input stream

    // Make move
    player.makeMove(board);

    // Verify that 'X' is placed in column 4 (0-based index)
    EXPECT_EQ(board.getGrid()[5][4], 'X'); // Column 5 in 1-based indexing
}

// Test 4: Handle input in a full column
TEST_F(FriendPlayerTest, HandleFullColumnInput)
{
    // Fill column 4 completely with 'O'
    for (int i = 0; i < 6; ++i) {
        board.dropDisc(3, 'O'); // Column 4 in 1-based index
    }

    // Simulate input attempting to use full column 4, then column 5
    std::istringstream input("4\n5\n");
    std::cin.rdbuf(input.rdbuf());

    // Make move
    player.makeMove(board);

    // Verify that 'X' is placed in column 4 (0-based index)
    EXPECT_EQ(board.getGrid()[5][4], 'X'); // Column 5 in 1-based indexing
}

// Test 5: Fill entire board and ensure no moves can be made
TEST_F(FriendPlayerTest, HandleFullBoard)
{
    // Fill the entire board
    for (int col = 0; col < 7; ++col) {
        for (int row = 0; row < 6; ++row) {
            board.dropDisc(col, 'O'); // Fill with 'O'
        }
    }

    // Simulate input attempting to drop disc in any column
    std::istringstream input("1\n2\n3\n4\n5\n6\n7\n");
    std::cin.rdbuf(input.rdbuf());

    // Expect the makeMove function to exit gracefully
    testing::internal::CaptureStdout();
    player.makeMove(board); // Should detect full board and exit
    std::string output = testing::internal::GetCapturedStdout();

    // Verify the output contains a message about a full board
    EXPECT_TRUE(output.find("The board is full! No moves can be made.") != std::string::npos);
}
 
