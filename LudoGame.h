#include"Board.h"
#include"Team.h"
#include"Dice.h"
#include"graphics.h"
#include"Button.h"
//#include"Player.h"
#pragma once

class LudoGame
{
	friend class Player;
	friend class Team;
	friend class Piece;
	friend class Dice;
	friend class Board;
protected:
	Board* MoveBoard;
	vector<Team>T;
	vector<Player>Ps;
	Piece* Sp;
	Dice D;
	int NOT; int NOP,Tno;
	int Turn; int tc;
	Button R1;
	Button R2;
	Button R3;
public:
	LudoGame()
	{

	}
	void Initialize();
	void Print_Game();
	void Play_Turn();
	bool Out_of_Home();
	bool Turn_Change();
	void Piece_Select(Point S);
	int Dice_Number_Select();
	void Update_Board();
	void Move_On_Board();
	bool Selected_Piece_Win(Point S);
	void Check_Kill(int);
	void Move(int Di,Point S);
	void Display_Stats();
	void Prt_Team_Win();
	void Initialize_Home();
	void Play();
	void GetInput(Point& S);
	void ShowCurrentTurn();
	void Print_HomeEnds();
	void GetInput_Mouse(Point& S);
	void Draw_HomeArr(int i);
	void Print_Pieces();
	void Print_Name(char* N);
	void MovefromBase();
	bool AnyPieceOut(int k);
	void ShowRolled();
	void Move_Animate(int Di);
	bool Going_Home(int Di);
	bool Inside_Home();
	void EnterHome(Piece P);
	bool MoveInHome(int vl);
	void EliminatePlayer(); 
	void home_decor_for_4();
	void Print_Home_Six();
	void Inital4();
	void Inital6();
	void Print_Board_6();
	void home_decor_for_6();
};

