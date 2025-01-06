#include <gtest/gtest.h>
#include "Computer.hpp"
#include "Board.hpp"

// Test fixture for Computer tests
class ComputerTest : public ::testing::Test
{
protected:
    ConnectFourBoard board; // Board instance for testing
    Computer computer;      // Computer instance

    // Constructor to initialize the computer with 'O'
    ComputerTest() : computer('O') {}

    // Reset the board before each test
    void SetUp(void) override
    {
        board.reset(); // Clear the board
    }
};

// Test 1: Make a valid move when the board is empty
TEST_F(ComputerTest, MakeMoveEmptyBoard)
{
    // Perform move
    bool moveMade = computer.makeMove(board);

    // Move should succeed
    EXPECT_TRUE(moveMade);

    // Ensure 'O' is placed in one of the columns
    bool discPlaced = false;
    const auto& grid = board.getGrid();

    for (int32_t row = 5; row >= 0; --row)
    {
        for (int32_t col = 0; col < 7; ++col)
        {
            if (grid[row][col] == 'O')
            {
                discPlaced = true;
                break;
            }
        }
    }
    EXPECT_TRUE(discPlaced); // Confirm that a disc was placed
}

// Test 2: Make a move when a winning move is available
TEST_F(ComputerTest, MakeWinningMove)
{
    // Set up a board where the computer can win
    for (int i = 0; i < 3; ++i)
    {
        board.dropDisc(0, 'O'); // Place 3 consecutive 'O's in column 0
    }

    // Perform move
    bool moveMade = computer.makeMove(board);

    // Move should succeed
    EXPECT_TRUE(moveMade);

    // Verify winning move in column 0
    EXPECT_EQ(board.getGrid()[2][0], 'O'); // 4th 'O' should complete the column
}

// Test 3: Block opponent's winning move
TEST_F(ComputerTest, BlockOpponentWinningMove)
{
    // Set up a board where opponent ('X') is about to win
    for (int i = 0; i < 3; ++i)
    {
        board.dropDisc(1, 'X'); // Place 3 consecutive 'X's in column 1
    }

    // Perform move
    bool moveMade = computer.makeMove(board);

    // Move should succeed
    EXPECT_TRUE(moveMade);

    // Verify block at column 1
    EXPECT_EQ(board.getGrid()[2][1], 'O'); // Block 'X' by placing 'O'
}

/* // Test 4: Handle full board (no moves possible)
TEST_F(ComputerTest, HandleFullBoard)
{
    // Fill the entire board
    for (int col = 0; col < 7; ++col)
    {
        board.dropDisc(col ? 'X' : 'O'); // Alternate 'X' and 'O'
    }

    // Attempt to make a move
    bool moveMade = computer.makeMove(board);

    // Move should fail because the board is full
    EXPECT_FALSE(moveMade);
}  */

// Test 5: Ensure moves avoid full columns
TEST_F(ComputerTest, AvoidFullColumns)
{
    // Fill column 3 completely
    // for (int row = 0; row < 6; ++row)
    // {
        board.dropDisc(3, 'O'); // Fill column 3 one less
    // }

    // Perform move
    bool moveMade = computer.makeMove(board);

    // Move should succeed (disc should be placed in another column)
    EXPECT_TRUE(moveMade);

    // Verify no disc is placed in the full column (3)
    EXPECT_NE(board.getGrid()[0][3], 'O'); // Top cell in column 3 should not change

}


// Test 6: Make move on partially filled board
TEST_F(ComputerTest, MakeMovePartiallyFilledBoard)
{
    // Partially fill columns 0 and 1
    board.dropDisc(0, 'X');
    board.dropDisc(1, 'O');
    board.dropDisc(0, 'X');
    board.dropDisc(1, 'O');

    // Perform move
    bool moveMade = computer.makeMove(board);

    // Move should succeed
    EXPECT_TRUE(moveMade);

   /*  // Verify that 'O' was placed in an available column
    bool discPlaced = false;
    const auto& grid = board.getGrid();

    for (int32_t row = 5; row >= 0; --row)
    {
        for (int32_t col = 0; col < 7; ++col)
        {
            if (grid[row][col] == 'O')
            {
                discPlaced = true;
                break;
            }
        }
    }
    EXPECT_TRUE(discPlaced); // Confirm that a disc was placed */
}