#pragma once
#ifndef _BOARD_
#define _BOARD_

#include "Color.h"
#include "TetrominoType.h"
#include "TetrominoRotation.h"

#include <array>

using std::array;

#define PIECE_BLOCKS 5		// Number of horizontal and vertical blocks of a matrix piece

class Tetromino
{
public:
	Tetromino();
	~Tetromino();

	Color getColor();
	void setColor(Color color);
	TetrominoType getType();
	void setType(TetrominoType type);
	TetrominoRotation getRotation();
	void setRotation(TetrominoRotation rotation);
	array<array<bool, PIECE_BLOCKS>, PIECE_BLOCKS> getMatrix();
	void setMatrix(TetrominoType type, TetrominoRotation rotation);

private:
	Color color;
	TetrominoType type;
	TetrominoRotation rotation;
	array<array<bool, PIECE_BLOCKS>, PIECE_BLOCKS> matrix;

	array<array<bool, PIECE_BLOCKS>, PIECE_BLOCKS> getSquare(TetrominoRotation rotation);
	array<array<bool, PIECE_BLOCKS>, PIECE_BLOCKS> getI(TetrominoRotation rotation);
	array<array<bool, PIECE_BLOCKS>, PIECE_BLOCKS> getL(TetrominoRotation rotation);
	array<array<bool, PIECE_BLOCKS>, PIECE_BLOCKS> getMirroredL(TetrominoRotation rotation);
	array<array<bool, PIECE_BLOCKS>, PIECE_BLOCKS> getN(TetrominoRotation rotation);
	array<array<bool, PIECE_BLOCKS>, PIECE_BLOCKS> getMirroredN(TetrominoRotation rotation);
	array<array<bool, PIECE_BLOCKS>, PIECE_BLOCKS> getT(TetrominoRotation rotation);
};

#endif