#include "Board.h"

Board::Board()
{
	clear();
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
	board[0].fill(false);
}

void Board::storeTetromino(int pX, int pY, Tetromino tetromino)
{
	// (0,0) is the upper-left corner of the tetromino. pX and pY are the coordinates of the tetromino's upper left corner before the collision.
	for (size_t x = 0; x < PIECE_BLOCKS; x++)
	{
		for (size_t y = 0; y < PIECE_BLOCKS; y++)
		{
			if (tetromino.matrix[x][y])
			{
				//There is a tetromino's block at this coordinates. So store it in the board.
				this->board[pX + x][pY + y] = true;
			}
		}
	}
}

bool Board::isPossibleMovement(int pX, int pY, Tetromino tetromino)
{
	// (0,0) is the upper-left corner of the tetromino. pX and pY are the coordinates of the tetromino's upper left corner at the collision.
	for (size_t x = 0; x < PIECE_BLOCKS; x++)
	{
		for (size_t y = 0; y < PIECE_BLOCKS; y++)
		{
			if (tetromino.matrix[x][y])
			{
				if (pX + x < 0 || pX + x > BOARD_WIDTH || y < 0 || y > BOARD_HEIGHT)
				{
					//This block is off limits
					return false;
				}

				//There is a block in the tetromino at this coordinates
				if (board[pX + x][pY + y])
				{
					//This block is not free
					return false;
				}
			}
		}
	}

	//This movement is possible
	return true;
}

void Board::clear()
{
	//Fill board with empty blocks
	for (size_t line = 0; line < BOARD_HEIGHT; line++)
	{
		board[line].fill(false);
	}
}
