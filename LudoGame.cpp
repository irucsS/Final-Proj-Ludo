#include "LudoGame.h"
#include"Player.h"
void LudoGame::Initialize()
{
	tc = 0;
	R1.ChangeIndex(Point(1150, 275));
	R2.ChangeIndex(Point(1210, 275));
	R3.ChangeIndex(Point(1270, 275)); 
	cout << "Enter the Number of Players";
	cin >> Tno;
	if (Tno > 4)
	{
		NOP = 6;
		Inital6();
	}
	else
	{
		NOP = 4;
		Inital4();
	}

}
void LudoGame::Initialize_Home()
{
	for (int i{ 0 }; i < NOP; i++)
	{

	}
}
void LudoGame::Play()
{
	Point S;
	Initialize();		//memory allocation step 1	
	//Print_Game();
// this function prints the ludo board and the players pieces 
//the draw functions of piece, board etc will be called in this function
	do
	{
		Play_Turn();	// this function displays the turn of the current player and
		//rolls the dice for the player.The validation will be done in the Dice class so we don’t need to check it here.
		if (!Out_of_Home() && D.Rolled[0] != 6)
		{
			delay(1000);
			while (!kbhit());
			getch();
			Turn_Change();
			continue;
		}
		do
		{
			Piece_Select(S);//it will check whether the user has selected a valid piece according   
													//	to the rules of the game.
		//	Dice_Number_Select();	//this will ask by which number rolled on the dice the 
									//selected piece is to be moved in case of six / multiple dice rolls
			Move(Dice_Number_Select(),S);
		} while (D.Left());
		if (tc == 0)
		{
			Turn_Change();
		}
		else tc--;
	} while (Ps.size()>1);

	Display_Stats();

}
void LudoGame::GetInput(Point& S)
{
	GetInput_Mouse(S);
}
void LudoGame::ShowCurrentTurn()
{
	//x=800 y=320
	Print_Name("                        ");
	switch (Turn)
	{
	case 0:
		Print_Name("CYAN ");
		break;
	case 1:
		Print_Name("RED");
		break;
	case 2:
		Print_Name("BLUE");
		break;
	case 3:
		Print_Name("MAGENTA");
		break;
	case 4:
		Print_Name("GREEN");
		break;
	case 5:
		Print_Name("YELLOW");
		break;
	}
}
void LudoGame::Print_HomeEnds()
{

	int R = 20, sx = 100, sy = 40;
	int D = R * 2;
	int IND = 0; NOP = 4;
	if (NOP <= 4)
	{
		for (int i{ 0 }; i < 5; i++)	//1st loop
		{
				//MoveBoard[IND].SetPoint(sx + (i * D), D * 6 + sy);
			Ps[IND].Home[i].SetPoint(sx + (i * D), D * 6 + sy + D);
			//	circle(sx+(i*D), D * 6 + sy+D, R);
			//	delay(100);
		}
		IND++;
		if (IND > NOP)return;
		for (int i{ 0 }; i < 5; i++)	//2nd loop
		{
			Ps[IND].Home[i].SetPoint((5 * D) + sx + D, sy + (i * D) + sy);
			//MoveBoard[IND].SetPoint((5 * D) + sx, sy + (i * D) + sy);
		//	delay(100);
			//circle((5 * D) + sx+D, sy+(i*D)+sy, R);
		}
		IND++;
		if (IND > NOP)return;
		for (int i{ 4 }; i >= 0; i--)	//5th loop
		{
			Ps[IND].Home[4-i].SetPoint(sx + (i * D) + (8 * D), D * 6 + sy + D);
			//MoveBoard[IND].SetPoint(sx + (i * D) + (8 * D), D * 6 + sy);
				//delay(100);
				//circle(sx + (i * D)+(8*D), D * 6 + sy+D, R);
		}
		IND++;
		if (IND > NOP)return;
		for (int i{ 4 }; i >= 0; i--)	//8th loop
		{
			Ps[IND].Home[4-i].SetPoint((7 * D) + sx - D, sy + (i * D) + sy + (8 * D));
			//MoveBoard[IND].SetPoint((7 * D) + sx, sy + (i * D) + sy + (8 * D));
				//delay(100);
		//		circle((7 * D) + sx-D, sy + (i * D) + sy+(8*D), R);
		}
	}

	for (int i{ 0 }; i < NOP; i++)
	{
		Draw_HomeArr(i);
	}

	
}
void LudoGame::Print_Game()
{
	int R = 20, sx = 100, sy = 40;
	int D = R * 2;
	int IND = 0;
	//setcolor(WHITE);
//	rectangle(30, 10, 650, 630);
	setcolor(LIGHTBLUE);
	setfillstyle(SOLID_FILL, LIGHTBLUE);
	bar(30, 10, 650, 630);

	//warning don't touch this xD
	for (int i{ 0 }; i < 5; i++, IND++)	//1st loop
	{

		MoveBoard[IND].SetPoint(sx + (i * D), D * 6 + sy);
		//circle(sx+(i*D), D * 6 + sy, R);
		//delay(300);
	}
	for (int i{ 4 }; i >= 0; i--, IND++)	//2nd loop
	{
		MoveBoard[IND].SetPoint((5 * D) + sx, sy + (i * D) + sy);
		//delay(300);
	//	circle((5 * D) + sx, sy+(i*D)+sy, R);
	}
	for (int i{ 0 }; i < 3; i++, IND++)	//3rd loop
	{
		MoveBoard[IND].SetPoint(sx + (5 * D) + (i * D), sy);
		//	delay(300);
		//	circle(sx + (5*D)+(i*D), sy, R);
	}
	for (int i{ 0 }; i < 5; i++, IND++)	//4rth loop
	{
		MoveBoard[IND].SetPoint((7 * D) + sx, sy + (i * D) + sy);
		//	delay(300);
		//	circle((7 * D) + sx, sy + (i * D) + sy, R);
	}
	for (int i{ 0 }; i < 5; i++, IND++)	//5th loop
	{
		MoveBoard[IND].SetPoint(sx + (i * D) + (8 * D), D * 6 + sy);
		//	delay(300);
			//circle(sx + (i * D)+(8*D), D * 6 + sy, R);
	}
	for (int i{ 0 }; i < 3; i++, IND++)	//6th loop 
	{
		MoveBoard[IND].SetPoint(sx + (13 * D), sy + (D * 6) + i * D);
		//	delay(300);
		//	circle(sx + (13 * D), sy + (D * 6) + i * D, R);
	}
	for (int i{ 4 }; i >= 0; i--, IND++)	//7th loop
	{
		MoveBoard[IND].SetPoint(sx + (i * D) + (8 * D), D * 8 + sy);
		//	delay(300);
		//	circle(sx + (i * D) + (8 * D), D * 8 + sy, R);
	}
	for (int i{ 0 }; i < 5; i++, IND++)	//8th loop
	{
		MoveBoard[IND].SetPoint((7 * D) + sx, sy + (i * D) + sy + (8 * D));
		//	delay(300);
		//	circle((7 * D) + sx, sy + (i * D) + sy+(8*D), R);
	}
	for (int i{ 2 }; i >= 0; i--, IND++)	//9th loop
	{
		MoveBoard[IND].SetPoint(sx + (5 * D) + (i * D), sy + (D * 14));
		//	delay(300);
		//	circle(sx + (5 * D) + (i * D), sy+(D*14), R);
	}
	for (int i{ 4 }; i >= 0; i--, IND++)	//10th loop
	{
		MoveBoard[IND].SetPoint((5 * D) + sx, sy + (i * D) + sy + (8 * D));
		//	delay(300);
		//	circle((5 * D) + sx, sy + (i * D) + sy+(8*D), R);
	}
	for (int i{ 4 }; i >= 0; i--, IND++)	//11th loop
	{
		MoveBoard[IND].SetPoint(sx + (i * D), D * 6 + sy + (D * 2));
		//	delay(300);
		//	circle(sx + (i * D), D * 6 + sy+(D*2), R);
	}
	for (int i{ 2 }; i >= 0; i--, IND++)	//12th loop 
	{
		MoveBoard[IND].SetPoint(sx - D, sy + (D * 6) + i * D);
		//	delay(300);
		//	circle(sx-D , sy + (D * 6) + i * D, R);
	}
	setcolor(WHITE);
	delay(100);
	for (int i{ 0 }; i < 13 * NOP; i++)
	{
		//delay(100);
		if (i % 13 == 0)
		{
			MoveBoard[i].MakeSafe();
			MoveBoard[i + 8].MakeSafe();
		}
		MoveBoard[i].Draw();
	}
	home_decor_for_4();
	Print_HomeEnds();
	Print_Pieces();
	Point S;
	GetInput_Mouse(S);
}
void LudoGame::ShowRolled(){
	int x = 1150;
	int y = 275;
	Point P1, P2, P3;
	P1.x = x;
	P1.y = y;
	P2.x = x + 60;
	P2.y = y;
	P3.x = x + 120;
	P3.y = y;

	R1.EraseValue(P1);
	R2.EraseValue(P2);
	R3.EraseValue(P3);

	R1.ChangeValue(D.Rolled[0]);
	R2.ChangeValue(D.Rolled[1]);
	R3.ChangeValue(D.Rolled[2]);

	R1.Draw(P1);
	R1.DrawValue(P1);
	R2.Draw(P2);
	R2.DrawValue(P2);
	R3.Draw(P3);
	R3.DrawValue(P3);
}
void LudoGame::Move_Animate(int Di)
{
	int diff = 0;
	if (Sp->B_ind + D.Rolled[Di] >= 13 * NOP) {
		diff = abs((13 * NOP-1) - (Sp->B_ind + D.Rolled[Di]));
	}
	for (int j{ 0 }; j < D.Rolled[Di]; j++)
	{
		if (Sp->B_ind + j < 13 * NOP) {
			if (MoveBoard[Sp->B_ind + j].CP.size() == 0)
			{
				MoveBoard[Sp->B_ind + j].CP.push_back(Sp);
				MoveBoard[Sp->B_ind + j].DrawPiece();
				delay(100);
				MoveBoard[Sp->B_ind + j].Remove_Piece(*Sp);
				MoveBoard[Sp->B_ind + j].Draw();
				MoveBoard[Sp->B_ind + j].DrawPiece();
			}
		}
		else {
			if (MoveBoard[abs(diff - j)].CP.size() == 0)
			{
				MoveBoard[abs(diff - j)].CP.push_back(Sp);
				MoveBoard[abs(diff - j)].DrawPiece();
				delay(100);
				MoveBoard[abs(diff - j)].Remove_Piece(*Sp);
				MoveBoard[abs(diff - j)].Draw();
				MoveBoard[abs(diff - j)].DrawPiece();
			}
		}
	}
	if (Sp->B_ind + D.Rolled[Di] >= 13 * NOP)
	{
		MoveBoard[Sp->B_ind].Remove_Piece(*Sp);
		MoveBoard[Sp->B_ind].Draw();
		Check_Kill(Di);
		Sp->B_ind = 0;
		MoveBoard[Sp->B_ind + (diff)-1].CP.push_back(Sp);
		Sp->B_ind = diff-1;
		MoveBoard[Sp->B_ind].DrawPiece();
		return;
	}
	MoveBoard[Sp->B_ind].Remove_Piece(*Sp);
	MoveBoard[Sp->B_ind].Draw();
	Check_Kill(Di);
	MoveBoard[Sp->B_ind + D.Rolled[Di]].CP.push_back(Sp);
	MoveBoard[Sp->B_ind].DrawPiece();
	Sp->B_ind += D.Rolled[Di];
	MoveBoard[Sp->B_ind].DrawPiece();
	
}
bool LudoGame::Going_Home(int Di)
{
	if (Inside_Home())
		return false;
	int st = (Sp->Clr * 13) - 2; int k=0;
	if (st < 0)st = 51 + st; int left=0;
	if (!Sp->HasKilled)
		return false;
	for (int i{ 0 }; i < D.Rolled[Di];i++)
	{
		left = D.Rolled[Di] - i;
		if (Sp->B_ind + i == st )
		{
			if (left != 0)
			{
				left--;
				if (left > 4)
				{
					for (int i{ 0 }; i < Ps[Turn].nops; i++)
					{
						if (&Ps[Turn].Pcs[i] == Sp)
						{
							MoveBoard[Sp->B_ind].Draw();
							MoveBoard[Sp->B_ind].Remove_Piece(*Sp);
							Ps[Turn].RemovePiece(i);
							D.Rolled[Di] = 0;
							return true;
						}
					}
				}
				MoveBoard[Sp->B_ind].Draw();
				Ps[Turn].Home[left].CP.push_back(Sp);
				Ps[Turn].Home[left].DrawPiece();
				MoveBoard[Sp->B_ind].Remove_Piece(*Sp);
				D.Rolled[Di] = 0;
				return true;
			}
		}
	}
	//D.Rolled[Di] = 0;

	return false;
	//for (int i{ 0 }; i < D.Rolled[Di]; i++)
	//{
	//	if (Sp->B_ind + i == st)
	//	{
	//		if (D.Rolled[Di] - i - (D.Rolled[Di] - i) == -1)
	//		{
	//			MoveBoard[Sp->B_ind].Remove_Piece(*Sp);
	//			for (int i{ 0 }; i < Ps[Turn].nops; i++)
	//			{
	//				if (&Ps[Turn].Pcs[i] == Sp)
	//				{
	//					MoveBoard[Sp->B_ind].Draw();
	//					Ps[Turn].RemovePiece(i);
	//					return true;
	//				}
	//			}
	//		}
	//		MoveBoard[Sp->B_ind].Draw();
	//		Ps[Turn].Home[abs(D.Rolled[Di] - i - (D.Rolled[Di] - i))].CP.push_back(Sp);
	//		Ps[Turn].Home[abs(D.Rolled[Di] - i - (D.Rolled[Di] - i))].DrawPiece();
	//		MoveBoard[Sp->B_ind].Remove_Piece(*Sp);
	//		return true;
	//	}
	//}
}
bool LudoGame::Inside_Home()
{
	for (int i{ 0 }; i < 5; i++)
	{
		for (int j{ 0 }; j < Ps[Turn].Home[i].CP.size(); j++)

			if (Ps[Turn].Home[i].CP[j] == Sp)
			{
				return true;
			}
	}
	return false;
}
void LudoGame::EnterHome(Piece P)
{
	



}
bool LudoGame::MoveInHome(int vl)
{
	bool del = false;
	for (int i{ 0 }; i < 5; i++)
	{
		for (int j{ 0 }; j < Ps[Turn].Home[i].CP.size(); j++)
		{
			if (Ps[Turn].Home[i].CP[j] == Sp)
			{
				if (i + D.Rolled[vl] > 4)
				{
					if (i + D.Rolled[vl] == 5)
					{
						int temp = 0;
						for (int k{ 0 }; Ps[Turn].Home[i].CP.size(); k++)
						{
							if (Ps[Turn].Home[i].CP[k] == Sp)
							{
								 del = true;
								for (int p{ 0 }; p < 4; p++)
								{
									if (Ps[Turn].Pcs[p] == *Sp)
									{
										temp = p;
									}
								}
								break;
							}
						}
						if (del)
						{
							Ps[Turn].Home[i].Remove_Piece(*Sp);
							Ps[Turn].Home[i].DrawHome();
							Ps[Turn].RemovePiece(temp);
							D.Rolled[vl] = 0;
						}
					}
					return true;
				}
				else
				{
					Ps[Turn].Home[i].DrawHome();
					//Ps[Turn].Home[i].DrawPiece();
					Ps[Turn].Home[i + D.Rolled[vl]].CP.push_back(Sp);
					Ps[Turn].Home[i + D.Rolled[vl]].DrawPiece();
					Ps[Turn].Home[i].Remove_Piece(*Sp);
					Ps[Turn].Home[i].DrawPiece();
				}
				D.Rolled[vl] = 0;
				return true;
			}
		}
	}
	//D.Rolled[vl] = 0;
	return false;






	//bool del = false;
	//for (int i{ 0 }; i < 5; i++)
	//{
	//	for (int j{ 0 }; j < Ps[Turn].Home[i].CP.size(); j++)
	//	{
	//		if (Ps[Turn].Home[i].CP[j]==Sp)
	//		{
	//			if (i + D.Rolled[vl] > 4)
	//			{
	//				if (i + D.Rolled[vl] == 5)
	//				{
	//					int temp = 0;

	//					for (int j{ 0 }; j < 5; j++)
	//					{
	//						for (int k{ 0 }; Ps[Turn].Home[i].CP.size(); k++)
	//						{
	//							if (Ps[Turn].Home[i].CP[k] == Sp)
	//							{
	//								temp = k; del = true;
	//								break;
	//							}
	//						}
	//					}
	//					if (del)
	//					{
	//						Ps[Turn].Home[i].Remove_Piece(*Sp);
	//						Ps[Turn].Home[i].DrawHome();
	//						Ps[Turn].RemovePiece(temp);
	//						D.Rolled[vl] = 0;
	//					}
	//				}
	//				return true;
	//			}
	//			else
	//			{
	//				Ps[Turn].Home[i].DrawHome();
	//				//Ps[Turn].Home[i].DrawPiece();
	//				Ps[Turn].Home[i + D.Rolled[vl]].CP.push_back(Sp);
	//				Ps[Turn].Home[i + D.Rolled[vl]].DrawPiece();
	//				Ps[Turn].Home[i].Remove_Piece(*Sp);
	//				Ps[Turn].Home[i].DrawPiece();
	//			}
	//			D.Rolled[vl] = 0;
	//			return true;
	//		}
	//	}
	//}
	////D.Rolled[vl] = 0;
	//return false;
}
void LudoGame::Play_Turn()
{
	ShowCurrentTurn(); int sp;
	D.PlayDice(); Point S;
	ShowRolled();
	bool t = true;
	for (int i{ 0 }; i < 3; i++)
	{
		if (D.Rolled[i] != 6)
		{
			t = false; break;
		}
	}
	if (t)
	{
		Turn_Change();
		Play_Turn();
	}
	cout << endl;	//loop for checking the dice array
	//if (D.Rolled[0] != 6 && !AnyPieceOut(Turn))		//if all the pieces are in home and dice haven't rolled a 6
	//{
	//	Turn_Change();
	//	return;
	//}
	//	Piece_Select(S);

	/*for (int i{ 0 }; i < Ps[Turn].nops; i++)
	{
		if (Ps[Turn].Pcs[i].OutofBase == true)
		{
			return;
		}
	}
	*/
	//MovefromBase();
}
void LudoGame::Print_Name(char* N)
{
	setcolor(WHITE);
	settextstyle(4, HORIZ_DIR, 3);
	outtextxy(1150, 320, N);
	//cout<<Turn;
}
void LudoGame::MovefromBase()
{
	if (D.Rolled[0] == 6)
	{

	}
}
bool LudoGame::AnyPieceOut(int k)
{
	int ind=0;
	for (int i{ 0 }; i < Ps.size(); i++)
	{
		if (Ps[i].Clr == k)
		{
			ind = i;
		}
	}
	for (int i{ 0 }; i < Ps[ind].nops; i++)
	{
		if (Ps[ind].Pcs[i].OutofBase == true)
		{
			return true;
		}
	}
	return false;
}
bool LudoGame::Out_of_Home() 
{
	return AnyPieceOut(Turn);
}
bool LudoGame::Turn_Change()
{
	Turn++;
	if (Turn == Tno)
		Turn = 0;
	while (Ps[Turn].HWon())
	{
		if (Ps[Turn].HWon() == true)
		{
			Turn++; if (Turn == Tno)
				Turn = 0;
		}
	}
	return false;
	/*
	Turn++;
	if (Turn == Ps.size())
		Turn = 0;
	while (Ps[Turn].HWon())
	{
		if (Ps[Turn].HWon() == true)
		{
			Turn++; if (Turn == Ps.size())
				Turn = 0;
		}
	}
	return false;*/
}
void LudoGame::Piece_Select(Point S)
{
	bool GetAgain = true;
	do
	{
		GetInput(S);
		for (int i{ 0 }; i < 4/*Ps[Turn].nops*/; i++)
		{
			if (Ps[Turn].Pcs[i].Is_Clicked(S) && !Ps[Turn].Pcs[i].HasWon)
			{
				GetAgain = false; Sp = &(Ps[Turn].Pcs[i]);
			}
			for (int j{ 0 }; j < 13 * NOP; j++)
			{
				if (MoveBoard[j].Is_Clicked(S))
				{
					for (int k{ 0 }; k < MoveBoard[j].CP.size(); k++)
					{
						if (MoveBoard[j].CP[k]->Clr == Turn && !MoveBoard[j].CP[k]->HasWon)
						{
							GetAgain = false; Sp = MoveBoard[j].CP[k];
						}
					}
				}
			}
			for (int k{ 0 }; k < 5; k++)
			{
				if (Ps[Turn].Home[k].Is_Clicked(S))
				{
					for (int l{ 0 }; l < Ps[Turn].Home[k].CP.size(); l++)
					{
						if (Ps[Turn].Home[k].CP[l]->Clr == Turn)
						{
							GetAgain = false; Sp = Ps[Turn].Home[k].CP[l];
						}
					}
				}
			}
		}
	} while (GetAgain);
}
int LudoGame::Dice_Number_Select()
{
	do
	{
		Point S;
		GetInput(S);
		if (R1.Is_Clicked(S))
		{
			return 0;
		}
		else if (R2.Is_Clicked(S))
		{
			return 1;
		}
		else if (R3.Is_Clicked(S))
		{
			return 2;
		}
	}while (1);
}
void LudoGame::Update_Board()
{

}
void LudoGame::Move_On_Board() {}
bool LudoGame::Selected_Piece_Win(Point S) { return false; }
void LudoGame::Check_Kill(int Di)
{
	int ind;
	if (Sp->B_ind + D.Rolled[Di] > (13 * NOP - 1))
	{
		int diff = abs((13 * NOP - 1) - (Sp->B_ind + D.Rolled[Di]));
		Sp->B_ind = 0;
		ind = abs(Sp->B_ind + diff-1);
	}
	else
	{
		ind = Sp->B_ind + D.Rolled[Di];
	}
	if (MoveBoard[ind].IsSafe() == true)
		return;

	if (MoveBoard[ind].CP.size() == 0)
		return;
	if (MoveBoard[ind].CP[0]->Clr == Turn)
		return;
	else 
	{
		MoveBoard[ind].Draw();
		MoveBoard[ind].CP[0]->Reset(); tc++;
		MoveBoard[ind].Remove_Piece(*(MoveBoard[ind].CP[0])); Sp->HasKilled = true;
		cout << "Inside Check Kill function's else statement" << endl;
	}

	/*if (MoveBoard[Sp->B_ind + D.Rolled[Di]].IsSafe() == true)
		return;

	if (MoveBoard[Sp->B_ind + D.Rolled[Di]].CP.size() == 0)
		return;
	if (MoveBoard[Sp->B_ind + D.Rolled[Di]].CP[0]->Clr == Turn)
		return;
	else {
		MoveBoard[Sp->B_ind + D.Rolled[Di]].Draw();
		MoveBoard[Sp->B_ind + D.Rolled[Di]].CP[0]->Reset();
		MoveBoard[Sp->B_ind + D.Rolled[Di]].Remove_Piece(*(MoveBoard[Sp->B_ind + D.Rolled[Di]].CP[0]));
		cout << "Inside Check Kill function's else statement" << endl;
	}*/
}
void LudoGame::Move(int Di,Point S)
{
	int ind = Sp->Clr * 13;
	if (Sp->OutofBase == false)
	{
		if (D.Rolled[Di] != 6)return;
		MoveBoard[ind].CP.push_back(Sp);
		MoveBoard[ind].DrawPiece();
		Sp->UnDraw(); D.Rolled[Di] = 0;
		Sp->B_ind = ind; Sp->OutofBase = true;
	//	D.Rolled[Di] = 0;
	}
	else if (Going_Home(Di) || MoveInHome(Di))
	{
		cout << "In the Home function check";
	}
	else
	{
		Move_Animate(Di);
		D.Rolled[Di] = 0;
	}
	switch (Di)
	{
	case 0:R1.ChangeValue(D.Rolled[0]); R1.DrawValue(R1.index);
		break;
	case 1:
		R2.ChangeValue(D.Rolled[1]); R2.DrawValue(R2.index);
		break;
	case 2:R3.ChangeValue(D.Rolled[2]); R3.DrawValue(R3.index);
		break;
	}
}
void LudoGame::Display_Stats()
{

}
void LudoGame::Prt_Team_Win()
{

}
void LudoGame::GetInput_Mouse(Point& S)
{
	int Dim = 80;
	while (!ismouseclick(WM_LBUTTONDOWN))
	{
	}
	getmouseclick(WM_LBUTTONDOWN, S.x, S.y);
	cout << "The mouse was clicked at: ";
	cout << "x=" << S.x;
	cout << " y=" << S.y << endl;
}
void LudoGame::Draw_HomeArr(int i)
{
	for (int j{ 0 }; j < 5; j++)
	{
		Ps[i].Home[j].DrawHome();
	//	delay(100);
	}

}
void LudoGame::Print_Pieces()
{
	for (int i{ 0 }; i < Ps.size(); i++)
	{
		for (int j{ 0 }; j < Ps[i].PiecesLeft(); j++)
		{
			Ps[i].Pcs[j].Reset();
		}
	}
}
void LudoGame::EliminatePlayer()
{
	int id=-1; int j = 0;
	for (int i{ 0 }; i < Ps.size(); i++)
	{
		if (Ps[i].HWon() == true)
		{
			id = j;
		}j++;
	}
	if(id!=-1)
	Ps.erase(Ps.begin() + id);
	/*int ind = 0, j = 0;
	for (int i{ 0 }; i < CP.size(); i++)
	{
		if (CP[i] == &P)
		{
			ind = j;
		}j++;
	}
	CP.erase(CP.begin() + ind);*/
}
void LudoGame::home_decor_for_4()
{
	int centre_x = 340;
	int centre_y = 316;

	//rectangle(centre_x-57,centre_y+ 57,centre_x +60, centre_y-60);
	rectangle(287, 266, 393, 369);
	line(287, 266, 393, 369);
	line(393, 267, 287, 368);

	setcolor(BLUE);
	setfillstyle(SOLID_FILL, BLUE);
	floodfill(centre_x, centre_y - 10, WHITE);

	setcolor(GREEN);
	setfillstyle(SOLID_FILL, GREEN);
	floodfill(centre_x + 10, centre_y, WHITE);

	int PISS_YELLOW = 14;
	setcolor(PISS_YELLOW);
	setfillstyle(SOLID_FILL, PISS_YELLOW);
	floodfill(centre_x, centre_y + 10, WHITE);

	setcolor(RED);
	setfillstyle(SOLID_FILL, RED);
	floodfill(centre_x - 10, centre_y, WHITE);

}
void LudoGame::Print_Home_Six()
{
	int R = 20, sx = 100, sy = 40;
	int D = R * 2;
	int IND = 0; NOP = 6;
	if (NOP <= 6)
	{
		for (int i{ 0 }; i < 5; i++)	//1st loop
		{
			//MoveBoard[IND].SetPoint(sx + (i * D), D * 6 + sy);
			Ps[IND].Home[i].SetPoint(sx + (i * D) + (3 * D), D * 6 + sy + D);
			//setcolor(RED);
			//setfillstyle(SOLID_FILL, RED);
			//circle(sx + (i * D) + (3 * D), D * 6 + sy + D, 20);
			//floodfill(sx + (i * D) + (3 * D), D * 6 + sy + D, RED);
			//delay(100);
		}
		IND++;
		if (IND > NOP)return;
		for (int i{ 0 }; i < 5; i++)	//2nd loop
		{
			Ps[IND].Home[i].SetPoint((8 * D) + sx + D, sy + (i * D) + sy);
			//MoveBoard[IND].SetPoint((5 * D) + sx, sy + (i * D) + sy);
			//delay(100);
			//setcolor(BLUE);
			//setfillstyle(SOLID_FILL, BLUE);
			//circle((8 * D) + sx + D, sy + (i * D) + sy, R);
			//floodfill((8 * D) + sx + D, sy + (i * D) + sy, BLUE);
		}
		IND++;
		if (IND > NOP)return;
		for (int i{ 0 }; i < 5; i++)	//3rd loop
		{
			Ps[IND].Home[i].SetPoint((12 * D) + sx + D, sy + (i * D) + sy);
			//MoveBoard[IND].SetPoint((5 * D) + sx, sy + (i * D) + sy);
			//delay(100);
			//setcolor(GREEN);
			//setfillstyle(SOLID_FILL, GREEN);
			//circle((12 * D) + sx + D, sy + (i * D) + sy, R);
			//floodfill((12 * D) + sx + D, sy + (i * D) + sy, GREEN);
		}
		IND++;
		if (IND > NOP)return;
		for (int i{ 4 }; i >= 0; i--)	//4th loop
		{
			Ps[IND].Home[4 - i].SetPoint(sx + (i * D) + (15 * D), D * 6 + sy + D);
			//MoveBoard[IND].SetPoint(sx + (i * D) + (8 * D), D * 6 + sy);
			//delay(100);
			//setcolor(YELLOW);
			//setfillstyle(SOLID_FILL, YELLOW);
			//circle(sx + (i * D) + (15 * D), D * 6 + sy + D, R);
			//floodfill(sx + (i * D) + (15 * D), D * 6 + sy + D, YELLOW);
		}
		IND++;
		if (IND > NOP)return;
		for (int i{ 4 }; i >= 0; i--)	//5th loop
		{
			Ps[IND].Home[4 - i].SetPoint((14 * D) + sx - D, sy + (i * D) + sy + (8 * D));
			//MoveBoard[IND].SetPoint((7 * D) + sx, sy + (i * D) + sy + (8 * D));
			//delay(100);
			//setcolor(MAGENTA);
			//setfillstyle(SOLID_FILL, MAGENTA);
			//circle((14 * D) + sx - D, sy + (i * D) + sy + (8 * D), R);
			//floodfill((14 * D) + sx - D, sy + (i * D) + sy + (8 * D), MAGENTA);
		}
		IND++;
		if (IND > NOP)return;
		for (int i{ 4 }; i >= 0; i--)	//6th loop
		{
			Ps[IND].Home[4 - i].SetPoint((10 * D) + sx - D, sy + (i * D) + sy + (8 * D));
			//MoveBoard[IND].SetPoint((7 * D) + sx, sy + (i * D) + sy + (8 * D));
			//delay(100);
			//setcolor(CYAN);
			//setfillstyle(SOLID_FILL, CYAN);
			//circle((10 * D) + sx - D, sy + (i * D) + sy + (8 * D), R);
			//floodfill((10 * D) + sx - D, sy + (i * D) + sy + (8 * D), CYAN);
		}
		for (int i{ 0 }; i < NOP; i++)
		{
			Draw_HomeArr(i);
		}
	}
}
void LudoGame::Print_Board_6()
{
	int R = 20, sx = 100, sy = 40;
	int D = R * 2;
	int IND = 0;
	MoveBoard = new Board[13 * 6];
	//setcolor(WHITE);
//	rectangle(30, 10, 650, 630);
	setcolor(LIGHTBLUE);
	setfillstyle(SOLID_FILL, LIGHTBLUE);
	bar(30, 10, 1050, 630);
	for (int i{ 0 }; i < 5; i++, IND++)	//1st loop
	{
		MoveBoard[IND].SetPoint(sx + (i * D) + (3 * D), D * 6 + sy);
		//setcolor(WHITE);
		//circle(sx+(i*D), D * 6 + sy, R);
		//setfillstyle(SOLID_FILL, WHITE);
		//floodfill(sx + (i * D), D * 6 + sy, WHITE);
		//delay(300);
	}
	for (int i{ 4 }; i >= 0; i--, IND++)	//2nd loop
	{
		MoveBoard[IND].SetPoint((8 * D) + sx, sy + (i * D) + sy);
		//delay(300);
		//setcolor(WHITE);
		//circle((5 * D) + sx, sy+(i*D)+sy, R);
		//setfillstyle(SOLID_FILL, WHITE);
		//floodfill((5 * D) + sx, sy + (i * D) + sy, WHITE);
	}
	for (int i{ 0 }; i < 3; i++, IND++)	//3rd loop
	{
		MoveBoard[IND].SetPoint(sx + (8 * D) + (i * D), sy);
		//delay(300);
		//setcolor(WHITE);
		//circle(sx + (5*D)+(i*D), sy, R);
		//setfillstyle(SOLID_FILL, WHITE);
		//floodfill(sx + (5 * D) + (i * D), sy, WHITE);
	}
	for (int i{ 0 }; i < 5; i++, IND++)	//4rth loop
	{
		MoveBoard[IND].SetPoint((10 * D) + sx, sy + (i * D) + sy);
		//delay(300);
		//setcolor(WHITE);
		//circle((7 * D) + sx, sy + (i * D) + sy, R);
		//setfillstyle(SOLID_FILL, WHITE);
		//floodfill((7 * D) + sx, sy + (i * D) + sy, WHITE);
	}
	for (int i{ 4 }; i >= 0; i--, IND++)	//5th loop
	{
		MoveBoard[IND].SetPoint((12 * D) + sx, sy + (i * D) + sy);
		//delay(300);
		//setcolor(WHITE);
		//circle((9 * D) + sx, sy + (i * D) + sy, R);
		//setfillstyle(SOLID_FILL, WHITE);
		//floodfill((9 * D) + sx, sy + (i * D) + sy, WHITE);
	}
	for (int i{ 0 }; i < 3; i++, IND++)	//6th loop
	{
		MoveBoard[IND].SetPoint(sx + (12 * D) + (i * D), sy);
		//delay(300);
		//setcolor(WHITE);
		//circle(sx + (9 * D) + (i * D), sy, R);
		//setfillstyle(SOLID_FILL, WHITE);
		//floodfill(sx + (9 * D) + (i * D), sy, WHITE);
	}
	for (int i{ 0 }; i < 5; i++, IND++)	//7th loop
	{
		MoveBoard[IND].SetPoint((14 * D) + sx, sy + (i * D) + sy);
		//delay(300);
		//setcolor(WHITE);
		//circle((11 * D) + sx, sy + (i * D) + sy, R);
		//setfillstyle(SOLID_FILL, WHITE);
		//floodfill((11 * D) + sx, sy + (i * D) + sy, WHITE);
	}
	for (int i{ 0 }; i < 5; i++, IND++)	//8th loop
	{
		MoveBoard[IND].SetPoint(sx + (i * D) + (15 * D), D * 6 + sy);
		//delay(300);
		//setcolor(WHITE);
		//circle(sx + (i * D)+(12*D), D * 6 + sy, R);
		//setfillstyle(SOLID_FILL, WHITE);
		//floodfill(sx + (i * D) + (12 * D), D * 6 + sy, WHITE);
	}
	for (int i{ 0 }; i < 3; i++, IND++)	//9th loop 
	{
		MoveBoard[IND].SetPoint(sx + (20 * D), sy + (D * 6) + i * D);
		//delay(300);
		//setcolor(WHITE);
		//circle(sx + (17 * D), sy + (D * 6) + i * D, R);
		//setfillstyle(SOLID_FILL, WHITE);
		//floodfill(sx + (17 * D), sy + (D * 6) + i * D, WHITE);
	}
	for (int i{ 4 }; i >= 0; i--, IND++)	//10th loop
	{
		MoveBoard[IND].SetPoint(sx + (i * D) + (15 * D), D * 8 + sy);
		//delay(300);
		//setcolor(WHITE);
		//circle(sx + (i * D) + (12 * D), D * 8 + sy, R);
		//setfillstyle(SOLID_FILL, WHITE);
		//floodfill(sx + (i * D) + (12 * D), D * 8 + sy, WHITE);
	}
	for (int i{ 0 }; i < 5; i++, IND++)	//11th loop
	{
		MoveBoard[IND].SetPoint((14 * D) + sx, sy + (i * D) + sy + (8 * D));
		//delay(300);
		//setcolor(WHITE);
		//circle((11 * D) + sx, sy + (i * D) + sy+(8*D), R);
		//setfillstyle(SOLID_FILL, WHITE);
		//floodfill((11 * D) + sx, sy + (i * D) + sy + (8 * D), WHITE);
	}
	for (int i{ 2 }; i >= 0; i--, IND++)	//12th loop
	{
		MoveBoard[IND].SetPoint(sx + (12 * D) + (i * D), sy + (D * 14));
		//delay(300);
		//setcolor(WHITE);
		//circle(sx + (9 * D) + (i * D), sy+(D*14), R);
		//setfillstyle(SOLID_FILL, WHITE);
		//floodfill(sx + (9 * D) + (i * D), sy + (D * 14), WHITE);
	}
	for (int i{ 4 }; i >= 0; i--, IND++)	//13th loop
	{
		MoveBoard[IND].SetPoint((12 * D) + sx, sy + (i * D) + sy + (8 * D));
		//delay(300);
		//setcolor(WHITE);
		//circle((9 * D) + sx, sy + (i * D) + sy+(8*D), R);
		//setfillstyle(SOLID_FILL, WHITE);
		//floodfill((9 * D) + sx, sy + (i * D) + sy + (8 * D), WHITE);
	}
	for (int i{ 0 }; i < 5; i++, IND++)	//14th loop
	{
		MoveBoard[IND].SetPoint((10 * D) + sx, sy + (i * D) + sy + (8 * D));
		//delay(300);
		//setcolor(WHITE);
		//circle((7 * D) + sx, sy + (i * D) + sy + (8 * D), R);
		//setfillstyle(SOLID_FILL, WHITE);
		//floodfill((7 * D) + sx, sy + (i * D) + sy + (8 * D), WHITE);
	}
	for (int i{ 2 }; i >= 0; i--, IND++)	//15th loop
	{
		MoveBoard[IND].SetPoint(sx + (8 * D) + (i * D), sy + (D * 14));
		//delay(300);
		//setcolor(WHITE);
		//circle(sx + (5 * D) + (i * D), sy + (D * 14), R);
		//setfillstyle(SOLID_FILL, WHITE);
		//floodfill(sx + (5 * D) + (i * D), sy + (D * 14), WHITE);
	}
	for (int i{ 4 }; i >= 0; i--, IND++)	//16th loop
	{
		MoveBoard[IND].SetPoint((8 * D) + sx, sy + (i * D) + sy + (8 * D));
		//delay(300);
		//setcolor(WHITE);
		//circle((5 * D) + sx, sy + (i * D) + sy + (8 * D), R);
		//setfillstyle(SOLID_FILL, WHITE);
		//floodfill((5 * D) + sx, sy + (i * D) + sy + (8 * D), WHITE);
	}
	for (int i{ 4 }; i >= 0; i--, IND++)	//17th loop
	{
		MoveBoard[IND].SetPoint(sx + (i * D) + (3 * D), D * 6 + sy + (D * 2));
		//delay(300);
		//setcolor(WHITE);
		//circle(sx + (i * D), D * 6 + sy+(D*2), R);
		//setfillstyle(SOLID_FILL, WHITE);
		//floodfill(sx + (i * D), D * 6 + sy + (D * 2), WHITE);
	}
	for (int i{ 2 }; i >= 0; i--, IND++)	//18th loop 
	{
		MoveBoard[IND].SetPoint(sx - D + (3 * D), sy + (D * 6) + i * D);
		//delay(300);
		//setcolor(WHITE);
		//circle(sx-D , sy + (D * 6) + i * D, R);
		//setfillstyle(SOLID_FILL, WHITE);
		//floodfill(sx - D, sy + (D * 6) + i * D, WHITE);
	}
	setcolor(WHITE);
	delay(100);
	for (int i{ 0 }; i < 13 * 6; i++)
	{
		//delay(100);
		if (i % 13 == 0)
		{
			MoveBoard[i].MakeSafe();
			MoveBoard[i + 8].MakeSafe();
		}
		MoveBoard[i].Draw();
		//delay(300);
	}
	Print_Home_Six();
	Print_Pieces(); home_decor_for_6();
}
void LudoGame::Inital4()
{
	Turn = 0;
	NOP = 4; 
	R1.ChangeIndex(Point(1150, 275));
	R2.ChangeIndex(Point(1210, 275));
	R3.ChangeIndex(Point(1270, 275));
	MoveBoard = new Board[13 * 4];
	Player P1("Player 1", 0, 4, 3), P2("Player 2", 3, 4, 3), P3("Player 3", 1, 4, 3);
	Player P4("Player 4", 2, 4, 3);
	Ps.push_back(P1);
	Ps.push_back(P3);
	Ps.push_back(P4);
	Ps.push_back(P2);
	Print_Game();
}
void LudoGame::Inital6()
{
	Turn = 0;
	R1.ChangeIndex(Point(1150, 275));
	R2.ChangeIndex(Point(1210, 275));
	R3.ChangeIndex(Point(1270, 275));
	Player P1("Player 1", 0, 4,5), P2("Player 2", 1, 4,5), P3("Player 3", 2, 4,5);
	Player P4("Player 4", 3, 4,5), P5("Player 5", 4, 4,5), P6("Player 6", 5, 4,5);
	Ps.push_back(P1);
	Ps.push_back(P2);
	Ps.push_back(P3);
	Ps.push_back(P4);
	Ps.push_back(P5);
	Ps.push_back(P6);
	Print_Board_6();
}
void LudoGame::home_decor_for_6()
{
	rectangle(402, 265, 673, 374);
	line(402, 265, 541, 374);
	line(541, 374, 673, 265);
	line(541, 265, 402, 374);
	line(541, 265, 673, 374);
	int cx = 540;
	int cy = 320;

	setcolor(LIGHTBLUE);
	setfillstyle(INTERLEAVE_FILL, LIGHTBLUE);
	floodfill(cx, cy, YELLOW);

	//red
	setcolor(RED);
	setfillstyle(SOLID_FILL, RED);
	floodfill(cx - 50, cy - 20, YELLOW);
	//cyan
	setcolor(CYAN);
	setfillstyle(SOLID_FILL, CYAN);
	floodfill(cx - 100, cy - 20, YELLOW);
	//yellow
	setcolor(YELLOW);
	setfillstyle(SOLID_FILL, YELLOW);
	floodfill(cx - 50, cy + 20, YELLOW);
	//green
	setcolor(GREEN);
	setfillstyle(SOLID_FILL, GREEN);
	floodfill(cx + 50, cy + 20, YELLOW);
	//magenta
	setcolor(MAGENTA);
	setfillstyle(SOLID_FILL, MAGENTA);
	floodfill(cx + 100, cy - 20, YELLOW);
	//blue
	setcolor(BLUE);
	setfillstyle(SOLID_FILL, BLUE);
	floodfill(cx + 50, cy - 20, YELLOW);
}
void LudoGame::Print_Options()
{
	setcolor(LIGHTGREEN);
	setfillstyle(SLASH_FILL, LIGHTGREEN);
	bar(150, 200, 400, 400);
	setcolor(YELLOW);
	setfillstyle(SLASH_FILL, YELLOW);
	bar(550, 200, 800, 400);
	settextstyle(3, HORIZ_DIR, 4);
	outtextxy(165, 270, "NEW GAME");
	setcolor(LIGHTGREEN);
	settextstyle(3, HORIZ_DIR, 4);
	outtextxy(610, 270, "SAVED");
	setcolor(CYAN);
	rectangle(100, 150, 450, 450);
	rectangle(500, 150, 850, 450);

}
void LudoGame::Start()
{
	Print_Options();
	Point S;
	int Dim = 80;
	while (!ismouseclick(WM_LBUTTONDOWN))
	{
	}
	getmouseclick(WM_LBUTTONDOWN, S.x, S.y);
	cout << "The mouse was clicked at: ";
	cout << "x=" << S.x;
	cout << " y=" << S.y << endl;
	if (S.x > 100 && S.y > 150 && S.x < 450 && S.x < 450)
	{
		//Load_Board("NewGame.txt");
	}
	else if (S.x > 500 && S.y > 150 && S.x < 850 && S.y < 450)
	{
		//Load_Board("Saved.txt");
	}
	cleardevice();
	//Play_On_Window();
}
void LudoGame::Save()
{

	ofstream Wrtr("Saved.txt");
	/*for (int i{ 0 }; i < 13 * NOP; i++)
	{
		Wrtr<<MoveBoard[i].
	}*/


}