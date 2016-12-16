#include "Board.h"

Board::Board()
{
	clear();
}

Board::~Board()
{
}

void Board::shiftLinesDown(int beginLine)
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
	board[0].fill(COLOR_NONE);
}

void Board::storeTetromino(int pLine, int pColumn, Tetromino tetromino)
{
	// (0,0) is the upper-left corner of the tetromino. pX and pY are the coordinates of the tetromino's upper left corner before the collision.
	for (size_t line = 0; line < PIECE_BLOCKS; line++)
	{
		for (size_t column = 0; column < PIECE_BLOCKS; column++)
		{
			if (tetromino.matrix[line][column])
			{
				//There is a tetromino's block at this coordinates. So store it in the board.
				this->board[pLine + line][pColumn + column] = tetromino.color;
			}
		}
	}
}

bool Board::isPossibleMovement(int pLine, int pColumn, Tetromino tetromino)
{
	// (0,0) is the upper-left corner of the tetromino. pX and pY are the coordinates of the tetromino's upper left corner at the collision.
	for (size_t line = 0; line < PIECE_BLOCKS; line++)
	{
		for (size_t column = 0; column < PIECE_BLOCKS; column++)
		{
			if (tetromino.matrix[line][column])
			{
				if (pColumn + column < 0 || pColumn + column > BOARD_WIDTH || line < 0 || line > BOARD_HEIGHT)
				{
					//This block is off limits
					return false;
				}

				//There is a block in the tetromino at this coordinates
				if (board[line + pLine][column + pColumn] != COLOR_NONE)
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
		board[line].fill(COLOR_NONE);
	}
}
