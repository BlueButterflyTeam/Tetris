#pragma once
#ifndef _GAME_
#define _GAME_

#include "Board.h"
#include "Tetromino.h"

class Game
{
public:
	Game();
	~Game();

	unsigned int deletedLinesCount;
	unsigned int level;
	unsigned int score;
	unsigned int timer;
	unsigned int speed;
	bool gameRunning;

	unsigned int currentTetrominoPosX;
	unsigned int currentTetrominoPosY;
	unsigned int nextTetrominoPosX;
	unsigned int nextTetrominoPosY;


	Board board;
	Tetromino currentTetromino;
	Tetromino nextTetromino;

	void init();
	void createNewPiece();
};

#endif