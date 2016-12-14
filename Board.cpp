#include "Board.h"

Board::Board()
{
	//Fill board with empty blocks
	for (size_t line = 0; line < BOARD_HEIGHT; line++)
	{
		board[line].fill(false);
	}
}

Board::~Board()
{
}

void Board::shiftLinesDown(unsigned int beginLine)
{
	//Shift values of all lines from beginLine except the one at the top. Values from line n become values from line n - 1.
	for (size_t line = beginLine; line > 0; line--)
	{
		for (size_t column = 0; column < BOARD_WIDTH; column++)
		{
			board[line][column] = board[line - 1][column];
		}
	}

	//Clear the line at the top
	for (size_t column = 0; column < BOARD_WIDTH; column++)
	{
		board[0][column] = false;
	}
}

void Board::storeTetromino(unsigned int pX, unsigned int pY, Tetromino tetromino)
{
	// (0,0) is the upper-left corner of the tetromino. pX and pY are the coordinates of the tetromino's upper left corner at the collision.
	for (size_t x = 0; x < PIECE_BLOCKS; x++)
	{
		for (size_t y = 0; y < PIECE_BLOCKS; y++)
		{
			if (tetromino.matrix[x][y] == true)
			{
				this->board[pX + x][pY + y] = true;
			}
		}
	}
}
