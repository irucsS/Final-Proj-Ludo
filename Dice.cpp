#include "Dice.h"
#include <stdlib.h>


bool Dice::Left()
{
	int temp = 0;
	for (int i = 0; i < 3; i++)
	{
		temp += Rolled[i];
	}
	if (temp != 0)
	{
		return true;
	}
	return false;
}
void Dice::PlayDice()
{
	for (int i{ 0 }; i < 3; i++)
		Rolled[i] = 0;
	int num, i = 0;
	Rolled[0] = Get_Input();
	Rolled[1] = Get_Input();
	Rolled[2] = Get_Input();
	return;

	if (PDice != 0)
	{
		switch (PDice) {
		case 1: erase_1();
			break;
		case 2: erase_2();
			break;
		case 3: erase_3();
			break;
		case 4: erase_4();
			break;
		case 5: erase_5();
			break;
		case 6: erase_6();
			break;
		}
	}
	do
	{
		if (i != 0)
		{
			switch (num) {
			case 1: erase_1();
				break;
			case 2: erase_2();
				break;
			case 3: erase_3();
				break;
			case 4: erase_4();
				break;
			case 5: erase_5();
				break;
			case 6: erase_6();
				break;
			}
		}
		num = Roll();
		Rolled[i] = num;
		Play_Animation(num);
		i++;
	} while (num == 6 && i < 3);
	PDice = num;
}


int Dice::Roll()
{
	return (rand() % 6 + 1);
}
void Dice::Play_Animation(int num)
{
	int Delay = 100;
	while (Delay < 500)
	{
		int RandNum = Roll();
		switch (RandNum)
		{
		case 1:
			print_1();
			delay(Delay);
			erase_1();
			break;
		case 2:
			print_2();
			delay(Delay);
			erase_2();
			break;
		case 3:
			print_3();
			delay(Delay);
			erase_3();
			break;
		case 4:
			print_4();
			delay(Delay);
			erase_4();
			break;
		case 5:
			print_5();
			delay(Delay);
			erase_5();
			break;
		case 6:
			print_6();
			delay(Delay);
			erase_6();
			break;
		}
		Delay += 50;
	}
	switch (num) {
	case 1: print_1();
		break;
	case 2: print_2();
		break;
	case 3: print_3();
		break;
	case 4: print_4();
		break;
	case 5: print_5();
		break;
	case 6: print_6();
		break;
	}
}

void Dice::print_6()
{

	setcolor(WHITE);
	rectangle(1150, 100, 1250, 200);
	setfillstyle(SOLID_FILL, WHITE);
	floodfill(1151, 101, WHITE);

	setcolor(BLACK);
	circle(cx - 20, cy, 11);
	setfillstyle(SOLID_FILL, BLACK);
	floodfill(cx - 20, cy, BLACK);

	setcolor(BLACK);
	circle(cx + 20, cy, 11);
	setfillstyle(SOLID_FILL, BLACK);
	floodfill(cx + 20, cy, BLACK);

	setcolor(BLACK);
	circle(cx - 20, cy - 27, 11);
	setfillstyle(SOLID_FILL, BLACK);
	floodfill(cx - 20, cy - 27, BLACK);

	setcolor(BLACK);
	circle(cx + 20, cy - 27, 11);
	setfillstyle(SOLID_FILL, BLACK);
	floodfill(cx + 20, cy - 27, BLACK);


	setcolor(BLACK);
	circle(cx - 20, cy + 27, 11);
	setfillstyle(SOLID_FILL, BLACK);
	floodfill(cx - 20, cy + 27, BLACK);

	setcolor(BLACK);
	circle(cx + 20, cy + 27, 11);
	setfillstyle(SOLID_FILL, BLACK);
	floodfill(cx + 20, cy + 27, BLACK);
}


void Dice::print_5()
{
	//confif for 5
	setcolor(WHITE);
	rectangle(1150, 100, 1250, 200);
	setfillstyle(SOLID_FILL, WHITE);
	floodfill(1151, 101, WHITE);

	setcolor(BLACK);

	circle(cx, cy, 12);
	setfillstyle(SOLID_FILL, BLACK);
	floodfill(cx, cy, BLACK);

	setcolor(BLACK);

	circle(cx - 25, cy - 25, 12);
	setfillstyle(SOLID_FILL, BLACK);
	floodfill(cx - 25, cy - 25, BLACK);

	setcolor(BLACK);

	circle(cx + 25, cy + 25, 12);
	setfillstyle(SOLID_FILL, BLACK);
	floodfill(cx + 25, cy + 25, BLACK);

	setcolor(BLACK);

	circle(cx + 25, cy - 25, 12);
	setfillstyle(SOLID_FILL, BLACK);
	floodfill(cx + 25, cy - 25, BLACK);

	setcolor(BLACK);

	circle(cx - 25, cy + 25, 12);
	setfillstyle(SOLID_FILL, BLACK);
	floodfill(cx - 25, cy + 25, BLACK);
}

void Dice::print_4()
{
	setcolor(WHITE);
	rectangle(1150, 100, 1250, 200);
	setfillstyle(SOLID_FILL, WHITE);
	floodfill(1151, 101, WHITE);

	setcolor(BLACK);
	circle(cx - 20, cy - 20, 12);
	setfillstyle(SOLID_FILL, BLACK);
	floodfill(cx - 20, cy - 20, BLACK);

	setcolor(BLACK);
	circle(cx + 20, cy - 20, 12);
	setfillstyle(SOLID_FILL, BLACK);
	floodfill(cx + 20, cy - 20, BLACK);

	setcolor(BLACK);
	circle(cx - 20, cy + 20, 12);
	setfillstyle(SOLID_FILL, BLACK);
	floodfill(cx - 20, cy + 20, BLACK);

	setcolor(BLACK);
	circle(cx + 20, cy + 20, 12);
	setfillstyle(SOLID_FILL, BLACK);
	floodfill(cx + 20, cy + 20, BLACK);
}

void Dice::print_3()
{
	setcolor(WHITE);
	rectangle(1150, 100, 1250, 200);
	setfillstyle(SOLID_FILL, WHITE);
	floodfill(1151, 101, WHITE);

	setcolor(BLACK);
	circle(cx, cy, 12);
	setfillstyle(SOLID_FILL, BLACK);
	floodfill(cx, cy, BLACK);

	setcolor(BLACK);

	circle(cx - 25, cy - 25, 12);
	setfillstyle(SOLID_FILL, BLACK);
	floodfill(cx - 25, cy - 25, BLACK);

	setcolor(BLACK);

	circle(cx + 25, cy + 25, 12);
	setfillstyle(SOLID_FILL, BLACK);
	floodfill(cx + 25, cy + 25, BLACK);
}

void Dice::print_2()
{
	setcolor(WHITE);
	rectangle(1150, 100, 1250, 200);
	setfillstyle(SOLID_FILL, WHITE);
	floodfill(1151, 101, WHITE);

	setcolor(BLACK);
	circle(cx - 20, cy, 12);
	setfillstyle(SOLID_FILL, BLACK);
	floodfill(cx - 20, cy, BLACK);

	setcolor(BLACK);
	circle(cx + 20, cy, 12);
	setfillstyle(SOLID_FILL, BLACK);
	floodfill(cx + 20, cy, BLACK);
}

void Dice::print_1()
{
	setcolor(WHITE);
	rectangle(1150, 100, 1250, 200);
	setfillstyle(SOLID_FILL, WHITE);
	floodfill(1151, 101, WHITE);

	setcolor(BLACK);

	circle(cx, cy, 12);
	setfillstyle(SOLID_FILL, BLACK);
	floodfill(cx, cy, BLACK);
}

void Dice::erase_6() {
	setfillstyle(SOLID_FILL, WHITE);
	floodfill(cx - 20, cy, WHITE);
	setfillstyle(SOLID_FILL, WHITE);
	floodfill(cx + 20, cy, WHITE);
	setfillstyle(SOLID_FILL, WHITE);
	floodfill(cx - 20, cy - 27, WHITE);
	setfillstyle(SOLID_FILL, WHITE);
	floodfill(cx - 20, cy + 27, WHITE);
	setfillstyle(SOLID_FILL, WHITE);
	floodfill(cx + 20, cy - 27, WHITE);
	setfillstyle(SOLID_FILL, WHITE);
	floodfill(cx + 20, cy + 27, WHITE);
}

void Dice::erase_5() {
	setfillstyle(SOLID_FILL, WHITE);
	floodfill(cx, cy, WHITE);
	setfillstyle(SOLID_FILL, WHITE);
	floodfill(cx - 25, cy - 25, WHITE);
	setfillstyle(SOLID_FILL, WHITE);
	floodfill(cx + 25, cy + 25, WHITE);
	setfillstyle(SOLID_FILL, WHITE);
	floodfill(cx - 25, cy + 25, WHITE);
	setfillstyle(SOLID_FILL, WHITE);
	floodfill(cx + 25, cy - 25, WHITE);
}

void Dice::erase_4() {
	setfillstyle(SOLID_FILL, WHITE);
	floodfill(cx - 20, cy - 20, WHITE);

	setfillstyle(SOLID_FILL, WHITE);
	floodfill(cx + 20, cy - 20, WHITE);

	setfillstyle(SOLID_FILL, WHITE);
	floodfill(cx - 20, cy + 20, WHITE);

	setfillstyle(SOLID_FILL, WHITE);
	floodfill(cx + 20, cy + 20, WHITE);
}

void Dice::erase_3() {
	setfillstyle(SOLID_FILL, WHITE);
	floodfill(cx, cy, WHITE);
	setfillstyle(SOLID_FILL, WHITE);
	floodfill(cx + 25, cy + 25, WHITE);
	setfillstyle(SOLID_FILL, WHITE);
	floodfill(cx - 25, cy - 25, WHITE);
}

void Dice::erase_2() {
	setfillstyle(SOLID_FILL, WHITE);
	floodfill(cx - 20, cy, WHITE);

	setfillstyle(SOLID_FILL, WHITE);
	floodfill(cx + 20, cy, WHITE);
}

void Dice::erase_1() {
	setfillstyle(SOLID_FILL, WHITE);
	floodfill(cx, cy, WHITE);
}

int Dice::Get_Input()
{
	int t;
	while (!kbhit())
	{

	}
	t = getch() - 48;
	return t;
}