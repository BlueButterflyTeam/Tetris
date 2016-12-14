#include "Game.h"



Game::Game()
{
	this->timer = 0;
	this->deletedLinesCount = 0;
	this->score = 0;
	this->level = 1;
	this->gameRunning = true;
}


Game::~Game()
{
}
