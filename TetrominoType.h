#pragma once
enum TetrominoType {SQUARE, I, L, MIRRORED_L, N, MIRRORED_N, T, NB_TYPES};

TetrominoType getRandomTetrominoType() {
	return static_cast<TetrominoType>(rand() % NB_TYPES);
}