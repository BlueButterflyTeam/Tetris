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

	int deletedLinesCount;
	int level;
	int score;
	int timer;
	int speed;
	bool gameRunning;

	int currentTetrominoPosX;
	int currentTetrominoPosY;
	int nextTetrominoPosX;
	int nextTetrominoPosY;


	Board board;
	Tetromino currentTetromino;
	Tetromino nextTetromino;

	void init();
	void createNewPiece();
};

#endif