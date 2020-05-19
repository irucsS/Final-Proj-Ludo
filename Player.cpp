#include "Player.h"
#include"Board.h"
Player::Player(const string& N, int C, int NOP,int Tn) :Name(N), Clr(C)
{
	Home = new Board[5];
	for (int i{ 0 }; i < 5; i++)
	{
		Home[i].setPlayer(*this);
	}
	Pcs = new Piece[NOP]; nops = NOP;
	
	//for the starting location of pieces in the bases 
	//will also help in resetting the piece
	if (Tn >= 4)
	{
		Home6(C);
	}
	else
	{
		Home4(C);
	}
}

Board& Player::operator[](int i)
{
	return Home[i];
}

int Player::CurrIndex(Piece* FP)
{
	for (int i = 0; i < 6; i++)
	{
		for (int j{ 0 }; j < Home[i].CP.size(); j++)
		{
			if (this->Home[i].CP[j] == FP)
				return i;
		}
	}
	return -1;
}

int Player::PiecesLeft()
{
	return nops;
}
void Player::RemovePiece(int i){
	
	Pcs[i].HasWon = true;
	nops--;
}
void Player::Home4(int C)
{
	Point b1, b2, b3, b4; int R = 20;
	switch (C)
	{
	case 0:
		b1.x = 100; b1.y = 70;
		b2.x = 200; b2.y = 70;
		b3.x = 100; b3.y = 180;
		b4.x = 200; b4.y = 180;
		Pcs[0].setPlayer(*this, b1);
		Pcs[1].setPlayer(*this, b2);
		Pcs[2].setPlayer(*this, b3);
		Pcs[3].setPlayer(*this, b4);
		/*	circle(b1.x, b1.y, 20);
			circle(b2.x, b2.y, 20);
			circle(b3.x, b3.y, 20);
			circle(b4.x, b4.y, 20);
		*/	break;
	case 1:

		b1.x = 100 + R * 18; b1.y = 70;
		b2.x = 200 + R * 18; b2.y = 70;
		b3.x = 100 + R * 18; b3.y = 180;
		b4.x = 200 + R * 18; b4.y = 180;
		/*b1.x = 100; b1.y = 70 + R * 20;
		b2.x = 200; b2.y = 70 + R * 20;
		b3.x = 100; b3.y = 180 + R * 20;
		b4.x = 200; b4.y = 180 + R * 20;
		*/
		Pcs[0].setPlayer(*this, b1);
		Pcs[1].setPlayer(*this, b2);
		Pcs[2].setPlayer(*this, b3);
		Pcs[3].setPlayer(*this, b4);
		/*circle(b1.x, b1.y, 20);
		circle(b2.x, b2.y, 20);
		circle(b3.x, b3.y, 20);
		circle(b4.x, b4.y, 20);
		*/break;
	case 2:
		b1.x = 100 + R * 18; b1.y = 70 + R * 20;
		b2.x = 200 + R * 18; b2.y = 70 + R * 20;
		b3.x = 100 + R * 18; b3.y = 180 + R * 20;
		b4.x = 200 + R * 18; b4.y = 180 + R * 20;
		Pcs[0].setPlayer(*this, b1);
		Pcs[1].setPlayer(*this, b2);
		Pcs[2].setPlayer(*this, b3);
		Pcs[3].setPlayer(*this, b4);
		/*	circle(b1.x, b1.y, 20);
			circle(b2.x, b2.y, 20);
			circle(b3.x, b3.y, 20);
			circle(b4.x, b4.y, 20);
		*/	break;
	case 3:
		/*	b1.x = 100 + R * 18; b1.y = 70 + R * 20;
			b2.x = 200 + R * 18; b2.y = 70 + R * 20;
			b3.x = 100 + R * 18; b3.y = 180 + R * 20;
			b4.x = 200 + R * 18; b4.y = 180 + R * 20;
		*/	b1.x = 100; b1.y = 70 + R * 20;
		b2.x = 200; b2.y = 70 + R * 20;
		b3.x = 100; b3.y = 180 + R * 20;
		b4.x = 200; b4.y = 180 + R * 20;

		Pcs[0].setPlayer(*this, b1);
		Pcs[1].setPlayer(*this, b2);
		Pcs[2].setPlayer(*this, b3);
		Pcs[3].setPlayer(*this, b4);
		/*circle(b1.x, b1.y, 20);
		circle(b2.x, b2.y, 20);
		circle(b3.x, b3.y, 20);
		circle(b4.x, b4.y, 20);
		*/break;
	}
}
void Player::Home6(int C)
{
	Point b1, b2, b3, b4; int R = 20;
	switch (C)
	{
	case 0:
		b1.x = 40 * 3; b1.y = 260;
		b2.x = 40 * 3; b2.y = 300;
		b3.x = 40 * 3; b3.y = 340;
		b4.x = 40 * 3; b4.y = 380;
		Pcs[0].setPlayer(*this, b1);
		Pcs[1].setPlayer(*this, b2);
		Pcs[2].setPlayer(*this, b3);
		Pcs[3].setPlayer(*this, b4);
		/*	circle(b1.x, b1.y, 20);
			circle(b2.x, b2.y, 20);
			circle(b3.x, b3.y, 20);
			circle(b4.x, b4.y, 20);
		*/	break;
	case 1:

		b1.x = 40 * 6; b1.y = 70;
		b2.x = 40 * 8; b2.y = 70;
		b3.x = 40 * 6; b3.y = 180;
		b4.x = 40 * 8; b4.y = 180;
		Pcs[0].setPlayer(*this, b1);
		Pcs[1].setPlayer(*this, b2);
		Pcs[2].setPlayer(*this, b3);
		Pcs[3].setPlayer(*this, b4);

		//b1.x = 100 + R * 18; b1.y = 70;
		//b2.x = 200 + R * 18; b2.y = 70;
		//b3.x = 100 + R * 18; b3.y = 180;
		//b4.x = 200 + R * 18; b4.y = 180;

		/*b1.x = 100; b1.y = 70 + R * 20;
		b2.x = 200; b2.y = 70 + R * 20;
		b3.x = 100; b3.y = 180 + R * 20;
		b4.x = 200; b4.y = 180 + R * 20;
		*/
		/*circle(b1.x, b1.y, 20);
		circle(b2.x, b2.y, 20);
		circle(b3.x, b3.y, 20);
		circle(b4.x, b4.y, 20);
		*/break;
	case 2:
		b1.x = (40 * 19); b1.y = 70;
		b2.x = (40 * 21); b2.y = 70;
		b3.x = (40 * 19); b3.y = 180;
		b4.x = (40 * 21); b4.y = 180;
		Pcs[0].setPlayer(*this, b1);
		Pcs[1].setPlayer(*this, b2);
		Pcs[2].setPlayer(*this, b3);
		Pcs[3].setPlayer(*this, b4);
		/*	circle(b1.x, b1.y, 20);
			circle(b2.x, b2.y, 20);
			circle(b3.x, b3.y, 20);
			circle(b4.x, b4.y, 20);
		*/	break;
	case 3:
		/*	b1.x = 100 + R * 18; b1.y = 70 + R * 20;
			b2.x = 200 + R * 18; b2.y = 70 + R * 20;
			b3.x = 100 + R * 18; b3.y = 180 + R * 20;
			b4.x = 200 + R * 18; b4.y = 180 + R * 20;
		*/
		b1.x = 40 * 24; b1.y = 260;
		b2.x = 40 * 24; b2.y = 300;
		b3.x = 40 * 24; b3.y = 340;
		b4.x = 40 * 24; b4.y = 380;

		Pcs[0].setPlayer(*this, b1);
		Pcs[1].setPlayer(*this, b2);
		Pcs[2].setPlayer(*this, b3);
		Pcs[3].setPlayer(*this, b4);
		/*circle(b1.x, b1.y, 20);
		circle(b2.x, b2.y, 20);
		circle(b3.x, b3.y, 20);
		circle(b4.x, b4.y, 20);
		*/break;
	case 4:
		b1.x = (40 * 19); b1.y = 70 + R * 20;
		b2.x = (40 * 21); b2.y = 70 + R * 20;
		b3.x = (40 * 19); b3.y = 180 + R * 20;
		b4.x = (40 * 21); b4.y = 180 + R * 20;

		Pcs[0].setPlayer(*this, b1);
		Pcs[1].setPlayer(*this, b2);
		Pcs[2].setPlayer(*this, b3);
		Pcs[3].setPlayer(*this, b4);
		break;
	case 5:
		b1.x = (40 * 6); b1.y = 70 + R * 20;
		b2.x = (40 * 8); b2.y = 70 + R * 20;
		b3.x = (40 * 6); b3.y = 180 + R * 20;
		b4.x = (40 * 8); b4.y = 180 + R * 20;

		Pcs[0].setPlayer(*this, b1);
		Pcs[1].setPlayer(*this, b2);
		Pcs[2].setPlayer(*this, b3);
		Pcs[3].setPlayer(*this, b4);
		break;
	}
}
bool Player::HWon(){
	return nops == 0;
}
