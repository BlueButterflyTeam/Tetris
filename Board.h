#pragma once
#ifndef _BOARD_
#define _BOARD_

#include <array>

#include "Tetromino.h"

#define BOARD_LINE_WIDTH 6          // Width of each of the two lines that delimit the board
#define BLOCK_SIZE 30               // Width and Height of each block of a tetromino
#define BOARD_POSITION 220          // Center position of the board from the left of the screen
#define BOARD_WIDTH 10              // Board width in blocks
#define BOARD_HEIGHT 20             // Board height in blocks
#define MIN_VERTICAL_MARGIN 20      // Minimum vertical margin for the board limit     
#define MIN_HORIZONTAL_MARGIN 20    // Minimum horizontal margin for the board limit
#define PIECE_BLOCKS 5				// Number of horizontal and vertical blocks of a matrix piece

using std::array;

class Board
{
public:
	Board();
	~Board();

	array<array<bool, BOARD_WIDTH>, BOARD_HEIGHT> board;			//Double array. Contains blocks. True = Block present.

	void shiftLinesDown(unsigned int beginLine);
	void storeTetromino(unsigned int pX, unsigned int pY, Tetromino tetromino);
	bool isPossibleMovement(unsigned int pX, unsigned int pY, Tetromino tetromino);
};

#endif