#include "Team.h"
#include"Player.h"

Team::Team() { }
void Team::AddPlayer(Player P)
{
	Tm.push_back(&P);
}
Team::Team(Player& P, char T)
{
	Tm.push_back(&P);
}
void Team::Remove(Player& P)
{
	int id = 0; Player* TP = &P; int j = 0;
	for (int i{ 0 }; i < Tm.size(); i++)
	{
		if (Tm[i] == &P)
		{
			id = j;
		}j++;
	}
	Tm.erase(Tm.begin() + id);
}