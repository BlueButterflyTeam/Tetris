#pragma once
enum TetrominoRotation {NONE, ONCE, TWICE, THRICE, NB_ROTATIONS};

TetrominoRotation getRandomTetrominoRotation() {
	return static_cast<TetrominoRotation>(rand() % NB_ROTATIONS);
}