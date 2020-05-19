#include<iostream>
#include<string>
//#include"Board.h"
using namespace std;
#pragma once

class Piece;
class Board;
class Player
{
	friend class Team;
	friend class LudoGame;
	friend class Board;
protected:
	string Name;
	Board* Home;
	int Clr;
	Piece* Pcs; int nops;
public:
	Player(const string& N, int C, int NOP,int Tn);
	Board& operator[](int i);
	int CurrIndex(Piece* FP);		//this returns where the piece is lying on the home array 
	int PiecesLeft();	//return how many pieces of the player has left 
	int GetColour()
	{
		return Clr;
	}
	bool HWon();
	void RemovePiece(int i);
	void Home4(int C);
	void Home6(int C);
};

