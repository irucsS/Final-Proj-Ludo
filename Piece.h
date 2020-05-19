#include"Team.h"
#include"Point.h"
#include"graphics.h"
#pragma once
class Piece
{
	friend class Board;
	friend class Ludogame;
protected:
	Team* CT;
		//optional can be removed
public:
	int B_ind;	//also used in reset 
	int Clr;
	Point B_Loc;
	Piece();	
	bool OutofBase;		
	bool HasKilled;
	bool HasWon;
	Piece(int C, Team* T);
	void Draw(Point P);		//this will draw a particular piece
	bool IsMyPiece(Team T);  //this function will check whether this is the team's piece or not
	bool IsMyPiece(Player P); //this function will check whether this is the player's piece or not 	
	void Reset();		//when a piece is killed , it will be reset 
	void setPlayer(Player P,Point bl);
	void UnDraw();
	bool Is_Clicked(Point S);
	bool operator==(const Piece& P)
	{
		return B_Loc == P.B_Loc;
	}
};

