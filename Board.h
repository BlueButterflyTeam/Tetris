#pragma once
#ifndef _BOARD_
#define _BOARD_

#include <array>

#include "Block.h"

#define BOARD_HEIGHT 20			//Board height in cells
#define BOARD_WIDTH 10			//Board width in cells

using std::array;

class Board
{
public:
	Board();
	~Board();

	bool isBlockFree(int pX, int pY);
	void shiftLinesDown(int beginLine);

private:
	array<array<Block, BOARD_WIDTH>, BOARD_HEIGHT> board;			//Double array. Contains blocks.
};

#endif