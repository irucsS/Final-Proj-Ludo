#include "Piece.h"
#include "Player.h"
#include "Point.h"
Piece::Piece():OutofBase(false), HasKilled(false),HasWon(false)
{
}
Piece::Piece(int C, Team* T) : Clr(C), CT(T), OutofBase(false), HasKilled(false), HasWon(false) {}
void Piece::Draw(Point P)
{
	int c;
	switch (Clr)
	{
	case 0:c = CYAN; break;
	case 1:c = RED; break;
	case 2:c = BLUE; break;
	case 3:c = MAGENTA; break;
	case 4:c = GREEN; break;
	case 5:c = YELLOW; break;
	}
	setcolor(c);
	circle(P.x, P.y, 15);
	setfillstyle(SOLID_FILL, c);
	floodfill(P.x, P.y, c);
}
bool Piece::IsMyPiece(Team T)
{
	return &T == CT;
}
bool Piece::IsMyPiece(Player P)
{
	return Clr == P.GetColour();
}
void Piece::Reset()
{
	OutofBase = false;
	Draw(B_Loc);
}

void Piece::setPlayer(Player P,Point bl)
{

	Clr = P.GetColour();
	B_Loc = bl; HasWon = false;
}

void Piece::UnDraw()
{
	setfillstyle(SOLID_FILL, LIGHTBLUE);
	floodfill(B_Loc.x, B_Loc.y, LIGHTBLUE);
}

bool Piece::Is_Clicked(Point S)
{
	if (S.x < B_Loc.x + 20 && S.x> B_Loc.x - 20 && S.y < B_Loc.y + 20 && S.y> B_Loc.y - 20)
	{
		//Clr = 2;
		//Draw(B_Loc);
		return true;
	}
	return false;
}


