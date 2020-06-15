
#include <iostream>

#include "pattern.h"

Pattern::Pattern(double _row1[5], double _row2[5], double _row3[5], double _row4[5], double _row5[5], double _row6[5], double _row7[5]) {
	for (int i = 0; i < 5; i++) {
		row1[i] = _row1[i];
		row2[i] = _row2[i];
		row3[i] = _row3[i];
		row4[i] = _row4[i];
		row5[i] = _row5[i];
		row6[i] = _row6[i];
		row7[i] = _row7[i];
	}
}

Pattern::Pattern()
{
	double bayas = 1;
	double row1[5] = { 0 };
	double row2[5] = { 0 };
	double row3[5] = { 0 };
	double row4[5] = { 0 };
	double row5[5] = { 0 };
	double row6[5] = { 0 };
	double row7[5] = { 0 };
}

void Pattern::print()
{
	for (int i = 0; i < 5; i++) {
		std::cout << row1[i] << " ";
	}
	std::cout << std::endl;
	for (int i = 0; i < 5; i++) {
		std::cout << row2[i] << " ";
	}
	std::cout << std::endl;
	for (int i = 0; i < 5; i++) {
		std::cout << row3[i] << " ";
	}
	std::cout << std::endl;
	for (int i = 0; i < 5; i++) {
		std::cout << row4[i] << " ";
	}
	std::cout << std::endl;
	for (int i = 0; i < 5; i++) {
		std::cout << row5[i] << " ";
	}
	std::cout << std::endl;
	for (int i = 0; i < 5; i++) {
		std::cout << row6[i] << " ";
	}
	std::cout << std::endl;
	for (int i = 0; i < 5; i++) {
		std::cout << row7[i] << " ";
	}
	std::cout << std::endl;
}

void Pattern::update() {
	std::cin >> row1[0] >> row1[1] >> row1[2] >> row1[3] >> row1[4];
	std::cin >> row2[0] >> row2[1] >> row2[2] >> row2[3] >> row2[4];
	std::cin >> row3[0] >> row3[1] >> row3[2] >> row3[3] >> row3[4];
	std::cin >> row4[0] >> row4[1] >> row4[2] >> row4[3] >> row4[4];
	std::cin >> row5[0] >> row5[1] >> row5[2] >> row5[3] >> row5[4];
	std::cin >> row6[0] >> row6[1] >> row6[2] >> row6[3] >> row6[4];
	std::cin >> row7[0] >> row7[1] >> row7[2] >> row7[3] >> row7[4];
}
