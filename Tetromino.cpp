#include "Tetromino.h"



Tetromino::Tetromino()
{
}


Tetromino::~Tetromino()
{
}

Color Tetromino::getColor()
{
	return this->color;
}

void Tetromino::setColor(Color color)
{
	this->color = color;
}

TetrominoType Tetromino::getType()
{
	return this->type;
}

void Tetromino::setType(TetrominoType type)
{
	this->type = type;
}

TetrominoRotation Tetromino::getRotation()
{
	return this->rotation;
}

void Tetromino::setRotation(TetrominoRotation rotation)
{
	this->rotation = rotation;
}

array<array<bool, PIECE_BLOCKS>, PIECE_BLOCKS> Tetromino::getMatrix()
{
	return this->matrix;
}

void Tetromino::setMatrix(TetrominoType type, TetrominoRotation rotation)
{
	array<array<bool, PIECE_BLOCKS>, PIECE_BLOCKS> matrix;

	switch (type)
	{
	case SQUARE:
		matrix = getSquare(rotation);
		break;
	case I:
		matrix = getI(rotation);
		break;
	case L:
		matrix = getL(rotation);
		break;
	case MIRRORED_L:
		matrix = getMirroredL(rotation);
		break;
	case N:
		matrix = getN(rotation);
		break;
	case MIRRORED_N:
		matrix = getMirroredN(rotation);
		break;
	case T:
		matrix = getT(rotation);
		break;
	default:
		for (size_t line = 0; line < PIECE_BLOCKS; line++)
		{
			matrix[line].fill(false);
		}
		break;
	}

	this->matrix = matrix;
}

array<array<bool, PIECE_BLOCKS>, PIECE_BLOCKS> Tetromino::getSquare(TetrominoRotation rotation)
{
	return { { 
	{ 0,0,0,0,0 },
	{ 0,0,0,0,0 },
	{ 0,0,1,1,0 },
	{ 0,0,1,1,0 },
	{ 0,0,0,0,0 } 
		} };
}

array<array<bool, PIECE_BLOCKS>, PIECE_BLOCKS> Tetromino::getI(TetrominoRotation rotation)
{
	array<array<bool, PIECE_BLOCKS>, PIECE_BLOCKS> matrix;

	switch (rotation)
	{
	case NONE:
		matrix = { {
			{ 0,0,0,0,0 },
			{ 0,0,0,0,0 },
			{ 0,1,1,1,1 },
			{ 0,0,0,0,0 },
			{ 0,0,0,0,0 }
			} };
		break;
	case ONCE:
		matrix = { {
			{ 0,0,1,0,0 },
			{ 0,0,1,0,0 },
			{ 0,0,1,0,0 },
			{ 0,0,1,0,0 },
			{ 0,0,0,0,0 }
			} };
		break;
	case TWICE:
		matrix = { {
			{ 0,0,0,0,0 },
			{ 0,0,0,0,0 },
			{ 1,1,1,1,0 },
			{ 0,0,0,0,0 },
			{ 0,0,0,0,0 }
			} };
		break;
	case THRICE:
		matrix = { {
			{ 0,0,0,0,0 },
			{ 0,0,1,0,0 },
			{ 0,0,1,0,0 },
			{ 0,0,1,0,0 },
			{ 0,0,1,0,0 }
			} };
		break;
	default:
		matrix = { {
			{ 0,0,0,0,0 },
			{ 0,0,0,0,0 },
			{ 0,1,1,1,1 },
			{ 0,0,0,0,0 },
			{ 0,0,0,0,0 }
			} };
		break;
	}

	return matrix;
}

array<array<bool, PIECE_BLOCKS>, PIECE_BLOCKS> Tetromino::getL(TetrominoRotation rotation)
{
	array<array<bool, PIECE_BLOCKS>, PIECE_BLOCKS> matrix;

	switch (rotation)
	{
	case NONE:
		matrix = { {
			{ 0,0,0,0,0 },
			{ 0,0,1,0,0 },
			{ 0,0,1,0,0 },
			{ 0,0,1,1,0 },
			{ 0,0,0,0,0 }
			} };
		break;
	case ONCE:
		matrix = { {
			{ 0,0,0,0,0 },
			{ 0,0,0,1,0 },
			{ 0,1,1,1,0 },
			{ 0,0,0,0,0 },
			{ 0,0,0,0,0 }
			} };
		break;
	case TWICE:
		matrix = { {
			{ 0,0,0,0,0 },
			{ 0,1,1,0,0 },
			{ 0,0,1,0,0 },
			{ 0,0,1,0,0 },
			{ 0,0,0,0,0 }
			} };
		break;
	case THRICE:
		matrix = { {
			{ 0,0,0,0,0 },
			{ 0,0,0,0,0 },
			{ 0,1,1,1,0 },
			{ 0,1,0,0,0 },
			{ 0,0,0,0,0 }
			} };
		break;
	default:
		matrix = { {
			{ 0,0,0,0,0 },
			{ 0,0,1,0,0 },
			{ 0,0,1,0,0 },
			{ 0,0,1,1,0 },
			{ 0,0,0,0,0 }
			} };
		break;
	}

	return matrix;
}

array<array<bool, PIECE_BLOCKS>, PIECE_BLOCKS> Tetromino::getMirroredL(TetrominoRotation rotation)
{
	array<array<bool, PIECE_BLOCKS>, PIECE_BLOCKS> matrix;

	switch (rotation)
	{
	case NONE:
		matrix = { {
			{ 0,0,0,0,0 },
			{ 0,0,1,0,0 },
			{ 0,0,1,0,0 },
			{ 0,1,1,0,0 },
			{ 0,0,0,0,0 }
			} };
		break;
	case ONCE:
		matrix = { {
			{ 0,0,0,0,0 },
			{ 0,0,0,0,0 },
			{ 0,1,1,1,0 },
			{ 0,0,0,1,0 },
			{ 0,0,0,0,0 }
			} };
		break;
	case TWICE:
		matrix = { {
			{ 0,0,0,0,0 },
			{ 0,0,1,1,0 },
			{ 0,0,1,0,0 },
			{ 0,0,1,0,0 },
			{ 0,0,0,0,0 }
			} };
		break;
	case THRICE:
		matrix = { {
			{ 0,0,0,0,0 },
			{ 0,1,0,0,0 },
			{ 0,1,1,1,0 },
			{ 0,0,0,0,0 },
			{ 0,0,0,0,0 }
			} };
		break;
	default:
		matrix = { {
			{ 0,0,0,0,0 },
			{ 0,0,1,0,0 },
			{ 0,0,1,0,0 },
			{ 0,1,1,0,0 },
			{ 0,0,0,0,0 }
			} };
		break;
	}

	return matrix;
}

array<array<bool, PIECE_BLOCKS>, PIECE_BLOCKS> Tetromino::getN(TetrominoRotation rotation)
{
	array<array<bool, PIECE_BLOCKS>, PIECE_BLOCKS> matrix;

	switch (rotation)
	{
	case NONE:
		matrix = { {
			{ 0,0,0,0,0 },
			{ 0,0,0,1,0 },
			{ 0,0,1,1,0 },
			{ 0,0,1,0,0 },
			{ 0,0,0,0,0 }
			} };
		break;
	case ONCE:
		matrix = { {
			{ 0,0,0,0,0 },
			{ 0,1,1,0,0 },
			{ 0,0,1,1,0 },
			{ 0,0,0,0,0 },
			{ 0,0,0,0,0 }
			} };
		break;
	case TWICE:
		matrix = { {
			{ 0,0,0,0,0 },
			{ 0,0,1,0,0 },
			{ 0,1,1,0,0 },
			{ 0,1,0,0,0 },
			{ 0,0,0,0,0 }
			} };
		break;
	case THRICE:
		matrix = { {
			{ 0,0,0,0,0 },
			{ 0,0,0,0,0 },
			{ 0,1,1,0,0 },
			{ 0,0,1,1,0 },
			{ 0,0,0,0,0 }
			} };
		break;
	default:
		matrix = { {
			{ 0,0,0,0,0 },
			{ 0,0,0,1,0 },
			{ 0,0,1,1,0 },
			{ 0,0,1,0,0 },
			{ 0,0,0,0,0 }
			} };
		break;
	}

	return matrix;
}

array<array<bool, PIECE_BLOCKS>, PIECE_BLOCKS> Tetromino::getMirroredN(TetrominoRotation rotation)
{
	array<array<bool, PIECE_BLOCKS>, PIECE_BLOCKS> matrix;

	switch (rotation)
	{
	case NONE:
		matrix = { {
			{ 0,0,0,0,0 },
			{ 0,0,1,0,0 },
			{ 0,0,1,1,0 },
			{ 0,0,0,1,0 },
			{ 0,0,0,0,0 }
			} };
		break;
	case ONCE:
		matrix = { {
			{ 0,0,0,0,0 },
			{ 0,0,1,1,0 },
			{ 0,1,1,0,0 },
			{ 0,0,0,0,0 },
			{ 0,0,0,0,0 }
			} };
		break;
	case TWICE:
		matrix = { {
			{ 0,0,0,0,0 },
			{ 0,1,0,0,0 },
			{ 0,1,1,0,0 },
			{ 0,0,1,0,0 },
			{ 0,0,0,0,0 }
			} };
		break;
	case THRICE:
		matrix = { {
			{ 0,0,0,0,0 },
			{ 0,0,0,0,0 },
			{ 0,0,1,1,0 },
			{ 0,1,1,0,0 },
			{ 0,0,0,0,0 }
			} };
		break;
	default:
		matrix = { {
			{ 0,0,0,0,0 },
			{ 0,0,1,0,0 },
			{ 0,0,1,1,0 },
			{ 0,0,0,1,0 },
			{ 0,0,0,0,0 }
			} };
		break;
	}

	return matrix;
}

array<array<bool, PIECE_BLOCKS>, PIECE_BLOCKS> Tetromino::getT(TetrominoRotation rotation)
{
	array<array<bool, PIECE_BLOCKS>, PIECE_BLOCKS> matrix;

	switch (rotation)
	{
	case NONE:
		matrix = { {
			{ 0,0,0,0,0 },
			{ 0,0,1,0,0 },
			{ 0,1,1,1,0 },
			{ 0,0,0,0,0 },
			{ 0,0,0,0,0 }
			} };
		break;
	case ONCE:
		matrix = { {
			{ 0,0,0,0,0 },
			{ 0,0,1,0,0 },
			{ 0,1,1,0,0 },
			{ 0,0,1,0,0 },
			{ 0,0,0,0,0 }
			} };
		break;
	case TWICE:
		matrix = { {
			{ 0,0,0,0,0 },
			{ 0,0,0,0,0 },
			{ 0,1,1,1,0 },
			{ 0,0,1,0,0 },
			{ 0,0,0,0,0 }
			} };
		break;
	case THRICE:
		matrix = { {
			{ 0,0,0,0,0 },
			{ 0,0,1,0,0 },
			{ 0,0,1,1,0 },
			{ 0,0,1,0,0 },
			{ 0,0,0,0,0 }
			} };
		break;
	default:
		matrix = { {
			{ 0,0,0,0,0 },
			{ 0,0,1,0,0 },
			{ 0,1,1,1,0 },
			{ 0,0,0,0,0 },
			{ 0,0,0,0,0 }
			} };
		break;
	}

	return matrix;
}
