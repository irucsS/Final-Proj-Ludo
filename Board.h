#pragma once
#include "Point.h"
#include "Piece.h"
#include"Player.h"
#include"graphics.h"
#include<vector>

using namespace std;

class Board
{
	friend class LudoGame;
	friend class Player;
	friend class Piece;
protected:
	Point P;
	vector<Piece*> CP;
	int BG;
	bool Safe;
public:
	Board();
	Board(int bg, Point p, vector<Piece*> cp);
	Board(Player& P);
	void setPlayer(Player&);
	void Draw();
	void DrawPiece();
	void SetPoint(Point);
	void SetPoint(int r, int c);
	void MakeSafe();
	int NPcs();
	bool ValidPiece(Team T); //use loop to check through the vector array
	bool ValidPiece(Player P);
	bool IsSafe();
	void DrawHome();
	bool Is_Clicked(Point Ps);
	void AddPiece(Piece P);
	void Remove_Piece(Piece P);
};
