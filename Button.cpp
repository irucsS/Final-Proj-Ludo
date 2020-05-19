#include "Button.h"

Button::Button(){
	value = 0;
}


Button::Button(Point i, int v): value(v), index(i) {}

void Button::ChangeIndex(Point i) {
	index = i;
}

void Button::ChangeValue(int v)
{
	value = v;
}
int Button::GetValue()
{
	return value;
}
void Button::Draw(Point S)
{
	setcolor(WHITE);
	circle(S.x, S.y, 26);
	//rectangle(S.x-26, S.y-26, S.x + 26, S.y + 26);
}
void Button::DrawValue(Point S)
{
	setcolor(WHITE);
	bgiout << value;
	outstreamxy(S.x - 5, S.y-5);
}
void Button::EraseValue(Point S)
{
	setcolor(WHITE);
	bgiout << "  ";
	outstreamxy(S.x-5, S.y-5);
}
bool Button::Is_Clicked(Point S)
{
	if (S.x < index.x + 26 && S.x> index.x - 26 && S.y < index.y + 26 && S.y> index.y - 26)
	{
		return true;
	}
	return false;
}


