#include "MessageBox.h"


MessageBox::MessageBox(float x, float y, float w, float h, MB_Button* b1, MB_Button* b2, bool type, const char* message)
{
	this->x = x;
	this->y = y;
	width = w;
	height = h;
	button1 = b1;
	button2 = b2;
	this->type = type;
	this->message = (char* ) message;
}


void MessageBox::tick()
{
	//If user clicked and mouse was inside one of the buttons
		//Call the button's onClick function, and then exit (Tell the game the message box is done being displayed)
		//delete both buttons
}


void MessageBox::draw(sf::RenderWindow& w)
{
	//Draw background rectangle
	//Draw message
	//Draw buttons
}