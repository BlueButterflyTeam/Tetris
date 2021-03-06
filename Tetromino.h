#pragma once
#ifndef _TETROMINO_
#define _TETROMINO_

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

	void setColor(TetrominoType type);
	void setMatrix(TetrominoType type, TetrominoRotation rotation);
	void randomize();

	Color color;
	TetrominoType type;
	TetrominoRotation rotation;
	array<array<bool, PIECE_BLOCKS>, PIECE_BLOCKS> matrix;
	void rotateLeft();
	void rotateRight();
	
private:
	array<array<bool, PIECE_BLOCKS>, PIECE_BLOCKS> getO(TetrominoRotation rotation);
	array<array<bool, PIECE_BLOCKS>, PIECE_BLOCKS> getI(TetrominoRotation rotation);
	array<array<bool, PIECE_BLOCKS>, PIECE_BLOCKS> getL(TetrominoRotation rotation);
	array<array<bool, PIECE_BLOCKS>, PIECE_BLOCKS> getJ(TetrominoRotation rotation);
	array<array<bool, PIECE_BLOCKS>, PIECE_BLOCKS> getZ(TetrominoRotation rotation);
	array<array<bool, PIECE_BLOCKS>, PIECE_BLOCKS> getS(TetrominoRotation rotation);
	array<array<bool, PIECE_BLOCKS>, PIECE_BLOCKS> getT(TetrominoRotation rotation);

	TetrominoType getRandomTetrominoType();
};

#endif