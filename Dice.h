#pragma once
#include"graphics.h"

class Dice
{
	friend class LudoGame;
private:
	//rand()%6+1
	int Roll();		//this will generate a random number b/w 1 to 6		//utility function
	void Play_Animation(int num);		//this will animate the dice on the graphics.h window this will be inside the PlayDice function
	int cx = 1200;
	int cy = 150;
	int PDice = 0;
	//congifs
	void print_6();
	void print_5();
	void print_4();
	void print_3();
	void print_2();
	void print_1();

	void erase_6();
	void erase_5();
	void erase_4();
	void erase_3();
	void erase_2();
	void erase_1();

protected:
	int Rolled[3];
public:
	Dice()
	{
	//	Rolled = new int[3];
		for (int i{ 0 }; i < 3; i++)
			Rolled[i] = 0;
	}
	/*const int operator[](int i)
	{
		return Rolled[i];
	}*/
	void PlayDice();	// this will play the turn for a particular player and the validity will be checked in this function
	//Play Dice function will initialize the Rolled Array of integers
	bool Left();		//this function will tell whether the player has any remaining dice rolls left or not
	int Get_Input();
};



