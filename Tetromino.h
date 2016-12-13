#pragma once
#ifndef _BOARD_
#define _BOARD_

#include "Color.h"

class Tetromino
{
public:
	Tetromino();
	~Tetromino();
private:
	Color color;
};

#endif