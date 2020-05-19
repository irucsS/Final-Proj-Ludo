#pragma once
#include "graphics.h"
#include "Point.h"
class Button
{
protected:
	int value;
public: 
	Point index;
	 Button();
	 Button(Point i, int v = 0);
	 void ChangeValue(int v); // Change Value of the button for every turn
	 int GetValue(); // returns the value stored in the button
	 void ChangeIndex(Point i);
	 void Draw(Point S); // Draw the button
	 void EraseValue(Point S); // Erase the number drawn in it
	 void DrawValue(Point S); // Draw the value in the button
	 bool Is_Clicked(Point S);

	 ~Button() {}
	
};

