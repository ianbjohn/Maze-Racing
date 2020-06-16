#ifndef MB_BUTTON_H
#define MB_BUTTON_H
#include "Game.h"


class MB_Button
{
private:
	void( *clickFunc)();


public:
	MB_Button(float x, float y, float w, float h, void( *clickFunc)());

	float x, y, width, height;
	const char* text;

	//Font, background color	

	void onClick();
	void draw(sf::RenderWindow& w);
};

#endif