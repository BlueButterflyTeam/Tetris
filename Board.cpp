#include "Board.h"

Board::Board()
{
	//Fill board with empty blocks
	for (size_t line = 0; line < BOARD_HEIGHT; line++)
	{
		board[line].fill(BLOCK_EMPTY);
	}
}

Board::~Board()
{
}

bool Board::isBlockFree(int pX, int pY)
{
	return board[pX][pY] == BLOCK_EMPTY;
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
	for (size_t column = 0; column < BOARD_WIDTH; column++)
	{
		board[0][column] = BLOCK_EMPTY;
	}
}
