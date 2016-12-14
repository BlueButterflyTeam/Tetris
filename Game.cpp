#include "Game.h"

#include <time.h>

Game::Game()
{
	init();
}


Game::~Game()
{
}

void Game::init()
{
	//init random numbers generator
	srand(time(NULL));

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
	this->currentTetromino.randomize();
	this->nextTetromino.randomize();
	this->currentTetrominoPosX = BOARD_WIDTH / 2 - (PIECE_BLOCKS - 1) / 2;
	this->currentTetrominoPosY = 0;
}
