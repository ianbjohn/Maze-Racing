#include "MB_Button.h"


MB_Button::MB_Button(float x, float y, float w, float h, void( *clickFunc)())
{
	this->x = x;
	this->y = y;
	width = w;
	height = h;
	this->clickFunc = clickFunc;
}


void MB_Button::onClick()
{
	clickFunc();
}


void MB_Button::draw(sf::RenderWindow& w)
{
	//Draw background rectangle
	//Draw button text
}