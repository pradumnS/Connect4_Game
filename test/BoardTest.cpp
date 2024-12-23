#include <gtest/gtest.h>
#include <algorithm> // For std::count
#include "Board.hpp"

// ------------------------- Test Fixture for ConnectFourBoard -------------------------
class ConnectFourBoardTest : public ::testing::Test {
protected:
    ConnectFourBoard board; // Create a board instance for testing

    // Reset the board before each test
    void SetUp() override {
         board.reset(); 
        //board = ConnectFourBoard(); // Reinitialize board
    }
};

// ------------------------- Initialization Tests -------------------------

// Test Board Initialization
TEST_F(ConnectFourBoardTest, BoardInitialization) {
    const auto& grid = board.getGrid();

    // Check dimensions
    EXPECT_EQ(grid.size(), 6);    // Rows
    EXPECT_EQ(grid[0].size(), 7); // Columns

    // Verify all cells are initialized with '.'
    for (const auto& row : grid) {
        for (char cell : row) {
            EXPECT_EQ(cell, '.'); // Empty cells should be '.'
        }
    }
}

// ------------------------- Basic Functionality Tests -------------------------

// Test isFull() - Empty Board
TEST_F(ConnectFourBoardTest, BoardNotFullInitially) {
    EXPECT_FALSE(board.isFull()); // Board should not be full initially
}

TEST_F(ConnectFourBoardTest, BoardFull) {
    for (int col = 0; col <= 6; ++col) { // Use 1-based indexing
        for (int i = 0; i < 6; ++i) {  // Drop 6 discs per column
            EXPECT_TRUE(board.dropDisc(col, 'X')) << "Failed to drop disc at column " << col;
        }
    }
    EXPECT_TRUE(board.isFull()) << "Board should be full.";
}

 // Test isColumnAvailable() - Available column
TEST_F(ConnectFourBoardTest, ColumnAvailable) {
    EXPECT_TRUE(board.isColumnAvailable(3)); // Column 3 should be available initially
}

// Test isColumnAvailable() - Full column
TEST_F(ConnectFourBoardTest, ColumnFull) {
    for (int i = 0; i < 6; ++i) {
        board.dropDisc(4, 'O'); // Fill column 3
    }
    EXPECT_FALSE(board.isColumnAvailable(4)); // Column 3 should be full
}

// ------------------------- Drop Disc Tests -------------------------

TEST_F(ConnectFourBoardTest, DropDiscValid) {
    EXPECT_TRUE(board.dropDisc(3, 'X'));         // Drop a disc in column 3 (0-based index)
    EXPECT_EQ(board.getGrid()[5][3], 'X');       // Expect it in the bottom row (index 5)
}



// Test dropDisc() - Invalid Column (Out of Bounds)
TEST_F(ConnectFourBoardTest, DropDiscInvalidColumn) {
    EXPECT_FALSE(board.dropDisc(-1, 'X')); // Negative column
    EXPECT_FALSE(board.dropDisc(8, 'X'));  // Column out of bounds
}

// Test dropDisc() - Full Column
TEST_F(ConnectFourBoardTest, DropDiscInFullColumn) {
    for (int i = 1; i < 8; ++i) {
        board.dropDisc(2, 'X'); // Fill column 2
    }
    EXPECT_FALSE(board.dropDisc(2, 'O')); // Attempt to drop in a full column
}

// ------------------------- Specialized Drop Functions Tests -------------------------

// Test dropDiscToColumn()
TEST_F(ConnectFourBoardTest, DropDiscToColumn) {
    EXPECT_TRUE(board.dropDiscToColumn(5, 3, 'O')); // Drop at (5, 2) base on index 1 3 will become 3-1 2
    EXPECT_EQ(board.getGrid()[5][3], 'O');          // Validate placement
}

// Test dropDiscToRow()
TEST_F(ConnectFourBoardTest, DropDiscToRow) {
    EXPECT_TRUE(board.dropDiscToRow(4, 4, 'O')); // Drop in row 4, column 3
    EXPECT_EQ(board.getGrid()[4][4], 'O');       // Validate placement
}

TEST_F(ConnectFourBoardTest, dropDiscToDiagonal) {
    EXPECT_TRUE(board.dropDiscToDiagonal(3, 2, 'O'));  // 1-based input (row=3, col=2)
    EXPECT_EQ(board.getGrid()[3][2], 'O');        // Verify 0-based output (row=4, col=3)
}


// Test dropDiscToGap()
TEST_F(ConnectFourBoardTest, DropDiscToGap) {
    EXPECT_TRUE(board.dropDiscToGap(4, 3, 'O')); // Drop in a gap
    EXPECT_EQ(board.getGrid()[4][3], 'O');       // Validate placement
} 



