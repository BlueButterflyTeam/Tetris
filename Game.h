#pragma once
#ifndef _GAME_
#define _GAME_

#include "Board.h"

class Game
{
public:
	Game();
	~Game();

	unsigned int deletedLinesCount;
	unsigned int level;
	unsigned int score;
	unsigned int timer;
	bool gameRunning;

	Board board;
};

#endif