#pragma once
enum TetrominoType {O, I, L, J, S, Z, T, NB_TYPES};

TetrominoType getRandomTetrominoType() {
	return static_cast<TetrominoType>(rand() % NB_TYPES);
}