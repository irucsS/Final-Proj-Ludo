//#include"Player.h"
#include<vector>
using namespace std;
#pragma once
class Player;
class Team
{
	friend class LudoGame;
	friend class Player;
protected:
	vector<Player*>Tm;
	char Tag;
public:
	Team();
	Team(Player& P, char T);
	void AddPlayer(Player P);
	void Remove(Player& P);
	int Size();		//this tells the size of Tm
	int PColor(int i)	//returns the color of ith player on the ith index of the tm array  
	{

	}
	char TeamTag();

};
