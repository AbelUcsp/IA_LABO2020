#pragma once

class Pattern
{
public:
	double bayas = 1;
	double row1[5] = { 0 };
	double row2[5] = { 0 };
	double row3[5] = { 0 };
	double row4[5] = { 0 };
	double row5[5] = { 0 };
	double row6[5] = { 0 };
	double row7[5] = { 0 };
	Pattern(double _row1[5], double _row2[5], double _row3[5], double _row4[5], double _row5[5], double _row6[5], double _row7[5]);
	Pattern();
	void print();
	void update();
};

