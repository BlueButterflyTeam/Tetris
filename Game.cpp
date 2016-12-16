#include "Game.h"

#include <time.h>

Game::Game(int screenHeight)
{
	this->screenHeight = screenHeight;
	init();
}


Game::~Game()
{
}

void Game::init()
{
	//init random numbers generator
	srand(time(NULL));

	//Init values
	this->timer = 0;
	this->deletedLinesCount = 0;
	this->score = 0;
	this->level = 1;
	this->speed = 500;
	this->gameRunning = true;
	this->currentTetrominoPosX = 0;
	this->currentTetrominoPosY = 0;
	this->nextTetrominoPosX = BOARD_WIDTH + 2;
	this->nextTetrominoPosY = 0;
	this->board.clear();
}

void Game::createNewPiece()
{
	//Create a new piece and place it in the next piece. Cuurent piece is remplaced by former next piece.
	this->currentTetromino.randomize();
	this->nextTetromino.randomize();
	//Reset Pos of current tetromino
	this->currentTetrominoPosX = BOARD_WIDTH / 2 - (PIECE_BLOCKS - 1) / 2;
	this->currentTetrominoPosY = 0;
}

//Check if lines are destroyable, and delete them. Return number of deleted lines.
void Game::deletePossibleLines()
{
	int numberOfDeletedLines = 0;
	bool needToDeleteLine;

	for (size_t line = 0; line < BOARD_HEIGHT; line++)
	{
		//Default to true. Becomes false if a blank block is detected.
		needToDeleteLine = true;
		for (size_t column = 0; column < BOARD_WIDTH; column++)
		{
			if (board.board[line][column] == COLOR_NONE)
			{
				needToDeleteLine = false;
			}
		}

		if (needToDeleteLine)
		{
			board.shiftLinesDown(line);
			numberOfDeletedLines++;
			line--;
		}
	}

	score += numberOfDeletedLines * NUMBER_OF_POINTS_PER_DELETED_LINE;
}

void Game::storeTetromino()
{
	board.storeTetromino(currentTetrominoPosY, currentTetrominoPosX, currentTetromino);

	deletePossibleLines();

	createNewPiece();
}

void Game::drawScene()
{
	drawBoard();
	drawPiece(currentTetrominoPosX, currentTetrominoPosY, currentTetromino);
	drawPiece(nextTetrominoPosX, nextTetrominoPosY, nextTetromino);
}

void Game::drawPiece(int pX, int pY, Tetromino tetromino)
{
	//Get positions values in pixels
	int pPixelsX = getXPosInPixels(pX);
	int pPixelsY = getYPosInPixels(pY);

	// Array of colors in RGB
	array<int, 3> color = colorToRGB(tetromino.color);

	// 0->R, 1->G, 2->B
	glColor3i(color[0], color[1], color[2]);

	//Travel the matrix of the tetromino
	for (size_t line = 0; line < PIECE_BLOCKS; line++)
	{
		for (size_t column = 0; column < PIECE_BLOCKS; column++)
		{
			if (tetromino.matrix[line][column])
			{
				//If there is a block to draw, draw it
				glRectf(
					GLfloat(pPixelsX + column * BLOCK_SIZE),
					GLfloat(pPixelsY + line * BLOCK_SIZE),
					GLfloat((pPixelsX + column * BLOCK_SIZE) + BLOCK_SIZE - 1),
					GLfloat((pPixelsY + line * BLOCK_SIZE) + BLOCK_SIZE - 1));
			}
		}
	}
}

void Game::drawBoard()
{
		// Calculate the limits of the board in pixels 
		int mX1 = BOARD_POSITION - (BLOCK_SIZE * (BOARD_WIDTH / 2)) - 1;
		int mX2 = BOARD_POSITION + (BLOCK_SIZE * (BOARD_WIDTH / 2));
		int mY = screenHeight - (BLOCK_SIZE * BOARD_HEIGHT);

		// Rectangles that delimits the board

		glColor3f(0.0f, 0.0f, 0.0f);
		glRectf(
			GLfloat(mX1 - BOARD_LINE_WIDTH),
			GLfloat(mY),
			GLfloat(mX1),
			GLfloat(screenHeight - 1));

		glRectf(GLfloat(mX2),
			GLfloat(mY),
			GLfloat(mX2 + BOARD_LINE_WIDTH),
			GLfloat(screenHeight - 1));



		// Drawing the blocks that are already stored in the board
		mX1 += 1;

		for (int line = 0; line < BOARD_WIDTH; line++)
		{
			for (int column = 0; column < BOARD_HEIGHT; column++)
			{
				// Check if the block is filled, if so, draw it
				if (board.board[line][column] != COLOR_NONE)
				{
					// Array of colors in RGB
					array<int, 3> color = colorToRGB(board.board[line][column]);

					// 0->R, 1->G, 2->B
					glColor3i(color[0], color[1], color[2]);

					glRectf(
						GLfloat(mX1 + column * BLOCK_SIZE),
						GLfloat(mY + line * BLOCK_SIZE),
						GLfloat((mX1 + column * BLOCK_SIZE) + BLOCK_SIZE - 1),
						GLfloat((mY + line * BLOCK_SIZE) + BLOCK_SIZE - 1));
				}
			}
		}
}

int Game::getXPosInPixels(int pX)
{
	return ((BOARD_POSITION - (BLOCK_SIZE * (BOARD_WIDTH / 2))) + (pX * BLOCK_SIZE));
}

int Game::getYPosInPixels(int pY)
{
	return ((this->screenHeight - (BLOCK_SIZE * BOARD_HEIGHT)) + (pY * BLOCK_SIZE));
}

std::array<int, 3> Game::colorToRGB(Color color) {
	switch (color)
	{
	case RED:
		return{ 255, 0, 0 };
		break;
	case BLUE:
		return{ 0, 0, 255 };
		break;
	case GREEN:
		return{ 0, 255, 0 };
		break;
	case CYAN:
		return{ 0, 255, 255 };
		break;
	case MAGENTA:
		return{ 255, 0, 255 };
		break;
	case ORANGE:
		return{ 255, 165, 0 };
		break;
	case YELLOW:
		return{ 255, 255, 0 };
		break;
	case BLACK:
		return{ 0, 0, 0 };
		break;
	case WHITE:
		return{ 255, 255, 255 };
		break;
	default:
		return{ 255, 0, 0 };
		break;
	}
}