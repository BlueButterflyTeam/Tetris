#include "Tetromino.h"

Tetromino::Tetromino()
{
	randomize();
}


Tetromino::~Tetromino()
{
}

void Tetromino::setColor(TetrominoType type)
{
	Color color;

	switch (type)
	{
	case O:
		color = YELLOW;
		break;
	case I:
		color = CYAN;
		break;
	case L:
		color = ORANGE;
		break;
	case J:
		color = BLUE;
		break;
	case S:
		color = GREEN;
		break;
	case Z:
		color = RED;
		break;
	case T:
		color = MAGENTA;
		break;
	default:
		color = BLACK;
		break;
	}

	this->color = color;
}

void Tetromino::setMatrix(TetrominoType type, TetrominoRotation rotation)
{
	array<array<bool, PIECE_BLOCKS>, PIECE_BLOCKS> matrix;

	switch (type)
	{
	case O:
		matrix = getO(rotation);
		break;
	case I:
		matrix = getI(rotation);
		break;
	case L:
		matrix = getL(rotation);
		break;
	case J:
		matrix = getJ(rotation);
		break;
	case Z:
		matrix = getZ(rotation);
		break;
	case S:
		matrix = getS(rotation);
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

void Tetromino::randomize()
{
	this->type = getRandomTetrominoType();
	this->rotation = ROTATION_NONE;
	setColor(this->type);
	setMatrix(this->type, this->rotation);
}

void Tetromino::rotateLeft()
{
	//Add 90 degrees
	this->rotation = static_cast<TetrominoRotation>(static_cast<int>(this->rotation) + 1 % NB_ROTATIONS);
	setMatrix(this->type, this->rotation);
}

void Tetromino::rotateRight()
{
	// Substract 90 degress
	this->rotation = static_cast<TetrominoRotation>(static_cast<int>(this->rotation) - 1 % NB_ROTATIONS);
	setMatrix(this->type, this->rotation);
}

array<array<bool, PIECE_BLOCKS>, PIECE_BLOCKS> Tetromino::getO(TetrominoRotation rotation)
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
	case ROTATION_NONE:
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
	case ROTATION_NONE:
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

array<array<bool, PIECE_BLOCKS>, PIECE_BLOCKS> Tetromino::getJ(TetrominoRotation rotation)
{
	array<array<bool, PIECE_BLOCKS>, PIECE_BLOCKS> matrix;

	switch (rotation)
	{
	case ROTATION_NONE:
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

array<array<bool, PIECE_BLOCKS>, PIECE_BLOCKS> Tetromino::getZ(TetrominoRotation rotation)
{
	array<array<bool, PIECE_BLOCKS>, PIECE_BLOCKS> matrix;

	switch (rotation)
	{
	case ROTATION_NONE:
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

array<array<bool, PIECE_BLOCKS>, PIECE_BLOCKS> Tetromino::getS(TetrominoRotation rotation)
{
	array<array<bool, PIECE_BLOCKS>, PIECE_BLOCKS> matrix;

	switch (rotation)
	{
	case ROTATION_NONE:
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
	case ROTATION_NONE:
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

TetrominoType Tetromino::getRandomTetrominoType() {
	return static_cast<TetrominoType>(rand() % NB_TYPES);
}