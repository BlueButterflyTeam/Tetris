#pragma once
#ifndef _GAME_
#define _GAME_

#include "Board.h"

#include <glew.h>

#define NUMBER_OF_POINTS_PER_DELETED_LINE 50

class Game
{
public:
	Game(int screenHeight);
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

	int screenHeight;


	Board board;
	Tetromino currentTetromino;
	Tetromino nextTetromino;

	void init();
	void createNewPiece();
	void deletePossibleLines();
	void storeTetromino();

	void drawScene();
	void drawPiece(int pX, int pY, Tetromino tetromino);
	void drawBoard();

	int getXPosInPixels(int pX);
	int getYPosInPixels(int pY);
	std::array<int, 3> colorToRGB(Color color);
};

#endif