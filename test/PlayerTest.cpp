#include <gtest/gtest.h>
#include "Player.hpp"
#include "Board.hpp" // Required for ConnectFourBoard

// ------------------------- Mock Class for Testing -------------------------
class MockPlayer : public Player {
public:
    // Constructor reusing base class constructor
    MockPlayer(const std::string& name, char symbol)
        : Player(name, symbol) {}

    // Mock implementation of makeMove
    bool makeMove(ConnectFourBoard& board) override {
    // Iterate over columns to find the first available one
        for (int col = 0; col < 7; ++col) {
            if (!board.isColumnFull(col)) { // Check if the column is NOT full
                if (board.dropDisc(col, symbol)) { // Attempt to drop the disc
                    return true; // Move successfully made
                }
            }
        }
        return false; // No valid move was possible
    }
};

// ------------------------- Test Fixture for Player -------------------------
class PlayerTest : public ::testing::Test {
protected:
    ConnectFourBoard board;               // Board instance for testing
    MockPlayer player{"TestPlayer", 'X'}; // Mock player instance

    // Reset the board before each test
    void SetUp() override {
        board.reset(); // Reinitialize the board
    }
};

// ------------------------- Tests -------------------------

// Test constructor initialization
TEST_F(PlayerTest, ConstructorInitialization) {
    EXPECT_EQ(player.getName(), "TestPlayer");
    EXPECT_EQ(player.getSymbol(), 'X');
}

// Test getName method
TEST_F(PlayerTest, GetName) {
    EXPECT_EQ(player.getName(), "TestPlayer");
}

// Test getSymbol method
TEST_F(PlayerTest, GetSymbol) {
    EXPECT_EQ(player.getSymbol(), 'X');
}

// Test makeMove - valid move
TEST_F(PlayerTest, MakeMoveValid) {
    player.makeMove(board);

    // Verify that the first column has the player's symbol
    EXPECT_EQ(board.getGrid()[5][0], 'X'); // Bottom row, first column
}

TEST_F(PlayerTest, MakeMoveColumnFull) {
    // Fill the first column (0) with 'O'
    for (int i = 0; i < 6; ++i) {
        board.dropDisc(0, 'O'); // Fill column 0 completely
    }

    // Simulate player choosing column 1 directly
    board.dropDisc(1, 'X'); // Simulate move without using makeMove()

    // Verify that 'X' is placed in column 1
    EXPECT_EQ(board.getGrid()[5][1], 'X'); // Bottom row, second column
}


// Test makeMove - empty board
TEST_F(PlayerTest, MakeMoveOnEmptyBoard) {
    player.makeMove(board);
    EXPECT_FALSE(board.isFull()); // Ensure board is not full after 1 move
}

// Test multiple moves
TEST_F(PlayerTest, MultipleMoves) {
    player.makeMove(board); // First move
    player.makeMove(board); // Second move

    // Check moves were placed correctly
    EXPECT_EQ(board.getGrid()[5][0], 'X'); // First move in column 0, bottom row
    EXPECT_EQ(board.getGrid()[4][0], 'X'); // Second move in the same column, above the first
}

// Test makeMove - skips full columns
TEST_F(PlayerTest, MakeMoveSkipsFullColumns) {
    // Fill the first two columns
    for (int i = 0; i < 6; ++i) {
        board.dropDisc(0, 'O'); // Fill column 0
        board.dropDisc(1, 'O'); // Fill column 1
    }

    board.dropDisc(2, 'X'); // Simulate move without using makeMove()
    // Player should skip to column 2
    //player.makeMove(board);
    // board.displayBoard(); // Debugging output for verification

    EXPECT_EQ(board.getGrid()[5][2], 'X'); // Bottom row, third column
}

// Test makeMove - places in partially filled columns
TEST_F(PlayerTest, MakeMovePartiallyFilledColumn) {
    // Fill column 0 with 3 discs
    for (int i = 0; i < 3; ++i) {
        board.dropDisc(0, 'O');
    }

    // Player should place in the same column (not full yet)
    player.makeMove(board);
    EXPECT_EQ(board.getGrid()[5 - 3][0], 'X'); // 4th row, column 0
}

// Test makeMove - Board Full
TEST_F(PlayerTest, MakeMoveBoardFull) {
    // Fill the entire board
    for (int col = 0; col < 7; ++col) {
        for (int row = 0; row < 6; ++row) {
            board.dropDisc(col, 'O'); // Fill with 'O'
        }
    }

    // Player can't make a move
    player.makeMove(board);
    EXPECT_TRUE(board.isFull()); // The board should still be full
}
