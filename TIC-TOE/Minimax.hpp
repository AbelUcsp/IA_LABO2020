#include <iostream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
#include <cmath>
#include <random>

#include<GL/glut.h>

using namespace std;

template <typename T, size_t N> const T* mybegin(const T(&a)[N]) { return a; }
template <typename T, size_t N> const T* myend(const T(&a)[N]) { return a + N; }

vector<char> board;

bool isValidMove(int pos, vector<char> boardT) //check in board if can move in a empty box
{
	if (boardT[pos] == 'C')
	{
		return true;
	}
	return false;
}

bool isPossibleMove(vector<char> boardw)
{
	for (size_t i = 0; i < boardw.size(); i++)
	{
		if (boardw[i] == 'C')
		{
			return true;
		}
	}
	return false;
}

void printboardchar(vector<char> board)
{
	int count = 0;
	for (size_t i = 0; i < board.size(); i++)
	{
		count++;
		cout << board[i];
		if (count % 3 == 0)
		{
			cout << endl;
		}
		else
		{
			cout << "-";
		}
	}
	//cout << endl;
}



class MiniMax
{
public:
	vector<char>internalBoard;
	bool isMax = false;
	bool isMin = false;
	int deep;/// Profundidad actual
	int RValue;/// Valor que resulta de evaluar
	char Player;///Valor de jugador que le toca en ese nodo
	int MinimaxVal;
	vector <MiniMax*> sons;
	int Possitive;
	int Neggative;

	MiniMax(int _deep, bool _isMax, bool _isMin, vector<char> Iboard, char _Player)
	{
		isMax = _isMax;
		isMin = _isMin;
		deep = _deep;
		Player = _Player;
		internalBoard = Iboard;
		RValue = evaluate();
		if (deep - 1 > 0 and isPossibleMove(internalBoard) == true)
		{
			for (size_t i = 0; i < 9; i++)
			{
				if (isValidMove(i, internalBoard) == true)
				{
					vector<char>Tboard0 = internalBoard;
					Tboard0[i] = Player;
					char AuxChar = 'C';
					if (Player == 'A') { AuxChar = 'B'; }
					else { AuxChar = 'A'; }
					bool MinTemp, MaxTemp;
					if (isMax == true)
					{
						MinTemp = true;
						MaxTemp = false;
					}
					if (isMin == true)
					{
						MinTemp = false;
						MaxTemp = true;
					}
					MiniMax* NewSon = new MiniMax(deep - 1, MaxTemp, MinTemp, Tboard0, AuxChar);
					sons.push_back(NewSon);
				}
			}
		}
		else
		{
			MinimaxVal = RValue;
		}
	}

	int evaluate() // usa internalBoard, ve lo mas favorable para la IA
	{
		//A = square <--- EL HUMANO
		//B = circle <--- LA IA
		int Positive = 0;
		int Negative = 0;
		if ((internalBoard[2] == 'B' or internalBoard[2] == 'C') and (internalBoard[4] == 'B' or internalBoard[4] == 'C') and (internalBoard[6] == 'B' or internalBoard[6] == 'C'))
		{
			Positive++;
		}
		if ((internalBoard[2] == 'A' or internalBoard[2] == 'C') and (internalBoard[4] == 'A' or internalBoard[4] == 'C') and (internalBoard[6] == 'A' or internalBoard[6] == 'C'))
		{
			Negative++;
		}

		if ((internalBoard[0] == 'B' or internalBoard[0] == 'C') and (internalBoard[4] == 'B' or internalBoard[4] == 'C') and (internalBoard[8] == 'B' or internalBoard[8] == 'C'))
		{
			Positive++;
		}
		if ((internalBoard[0] == 'A' or internalBoard[0] == 'C') and (internalBoard[4] == 'A' or internalBoard[4] == 'C') and (internalBoard[8] == 'A' or internalBoard[8] == 'C'))
		{
			Negative++;
		}

		if ((internalBoard[0] == 'B' or internalBoard[0] == 'C') and (internalBoard[1] == 'B' or internalBoard[1] == 'C') and (internalBoard[2] == 'B' or internalBoard[2] == 'C'))
		{
			Positive++;
		}
		if ((internalBoard[0] == 'A' or internalBoard[0] == 'C') and (internalBoard[1] == 'A' or internalBoard[1] == 'C') and (internalBoard[2] == 'A' or internalBoard[2] == 'C'))
		{
			Negative++;
		}

		if ((internalBoard[3] == 'B' or internalBoard[3] == 'C') and (internalBoard[4] == 'B' or internalBoard[4] == 'C') and (internalBoard[5] == 'B' or internalBoard[5] == 'C'))
		{
			Positive++;
		}
		if ((internalBoard[3] == 'A' or internalBoard[3] == 'C') and (internalBoard[4] == 'A' or internalBoard[4] == 'C') and (internalBoard[5] == 'A' or internalBoard[5] == 'C'))
		{
			Negative++;
		}

		if ((internalBoard[6] == 'B' or internalBoard[6] == 'C') and (internalBoard[7] == 'B' or internalBoard[7] == 'C') and (internalBoard[8] == 'B' or internalBoard[8] == 'C'))
		{
			Positive++;
		}
		if ((internalBoard[6] == 'A' or internalBoard[6] == 'C') and (internalBoard[7] == 'A' or internalBoard[7] == 'C') and (internalBoard[8] == 'A' or internalBoard[8] == 'C'))
		{
			Negative++;
		}

		if ((internalBoard[0] == 'B' or internalBoard[0] == 'C') and (internalBoard[3] == 'B' or internalBoard[3] == 'C') and (internalBoard[6] == 'B' or internalBoard[6] == 'C'))
		{
			Positive++;
		}
		if ((internalBoard[0] == 'A' or internalBoard[0] == 'C') and (internalBoard[3] == 'A' or internalBoard[3] == 'C') and (internalBoard[6] == 'A' or internalBoard[6] == 'C'))
		{
			Negative++;
		}

		if ((internalBoard[1] == 'B' or internalBoard[1] == 'C') and (internalBoard[4] == 'B' or internalBoard[4] == 'C') and (internalBoard[7] == 'B' or internalBoard[7] == 'C'))
		{
			Positive++;
		}
		if ((internalBoard[1] == 'A' or internalBoard[1] == 'C') and (internalBoard[4] == 'A' or internalBoard[4] == 'C') and (internalBoard[7] == 'A' or internalBoard[7] == 'C'))
		{
			Negative++;
		}

		if ((internalBoard[2] == 'B' or internalBoard[2] == 'C') and (internalBoard[5] == 'B' or internalBoard[5] == 'C') and (internalBoard[8] == 'B' or internalBoard[8] == 'C'))
		{
			Positive++;
		}
		if ((internalBoard[2] == 'A' or internalBoard[2] == 'C') and (internalBoard[5] == 'A' or internalBoard[5] == 'C') and (internalBoard[8] == 'A' or internalBoard[8] == 'C'))
		{
			Negative++;
		}
		Possitive = Positive;
		Neggative = Negative;
		//cout << "Possitive: " << Positive << "- Negative: " << Negative<<" = "<<Positive-Negative << endl;
		return Positive - Negative;
	}
};
