#include "Board.h"
#include "Team.h"

using namespace std;

Board::Board(int bg, Point p, vector<Piece*> cp) : BG(bg), P(p), Safe(false) {
	CP = cp;
}

Board::Board(Player& P) {
	BG = P.Clr;
	Safe = true;
}
Board::Board()
{
	BG = WHITE;
	Safe = false;
}

void Board::setPlayer(Player& P) {
	BG = P.Clr;
	Safe = true;
}

void Board::Draw()
{
	//setcolor(YELLOW);
	if (Safe == false) {
		setcolor(WHITE);
		circle(P.x, P.y, 20);
		setfillstyle(SOLID_FILL, WHITE);
		floodfill(P.x, P.y, WHITE);
	}
	else {
		setcolor(DARKGRAY);
		circle(P.x, P.y, 20);
		setfillstyle(SOLID_FILL, DARKGRAY);
		floodfill(P.x, P.y, DARKGRAY);
	}

}

void Board::DrawPiece() {
	//int i = CP.size();
	//CP[i - 1]->Draw(P);
	//CP[i]->Draw(P);
	if (CP.size() == 0)
		return;
	else
	{
		int top = CP.size();
		CP[top - 1]->Draw(P);
	}
}

void Board::SetPoint(Point p) {
	P = p;
}

void Board::SetPoint(int r, int c)
{
	P.x = r; P.y = c;
}

void Board::MakeSafe() {
	Safe = true;
}

int Board::NPcs() {
	return CP.size();
}

bool Board::ValidPiece(Team T) {
	for (int i = 0; i < CP.size(); i++) {
		if (CP[i]->IsMyPiece(T) == true)
			return true;
	}
	return false;
}

bool Board::ValidPiece(Player P) {
	for (int i = 0; i < CP.size(); i++) {
		if (P.Clr == (*CP[i]).Clr)
			return true;
	}
	return false;
}

bool Board::IsSafe() {
	return Safe;
}

void Board::DrawHome()
{
	int c;
	switch (BG)
	{
	case 0:c = CYAN; break;
	case 1:c = RED; break;
	case 2:c = BLUE; break;
	case 3:c = MAGENTA; break;
	case 4:c = GREEN; break;
	case 5:c = YELLOW; break;
	}
	setcolor(WHITE);
	setfillstyle(SOLID_FILL, LIGHTGRAY);
	circle(P.x, P.y, 20);
	floodfill(P.x, P.y, WHITE);
	setcolor(c);
	circle(P.x, P.y, 15);
	circle(P.x, P.y, 16);
	circle(P.x, P.y, 17);
	circle(P.x, P.y, 18);
	circle(P.x, P.y, 19);
}

bool Board::Is_Clicked(Point S)
{
	if (S.x < P.x + 20 && S.x> P.x - 20 && S.y < P.y + 20 && S.y> P.y - 20)
	{
		return true;
	}
	return false;
}

void Board::AddPiece(Piece P)
{
	CP.push_back(&P);
}

void Board::Remove_Piece(Piece P)
{
	int ind=0,j=0;
	for (int i{ 0 }; i < CP.size(); i++)
	{
		if (*CP[i] == P)
		{
			ind = j;
		}j++;
		 
	}
	CP.erase(CP.begin() + ind);
}
