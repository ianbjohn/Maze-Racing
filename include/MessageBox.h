#ifndef MESSAGEBOX_H
#define MESSAGEBOX_H
#include "MB_Button.h"


class MB_Button;


class MessageBox
{
private:
	MB_Button *button1, *button2;
	bool type;		//0 - one button, 1 - two buttons
	char* message;


public:
	float x, y, width, height;
	//Font, background color

	MessageBox(float x, float y, float w, float h, MB_Button* b1, MB_Button* b2, bool type, const char* message);
	void tick();
	void draw(sf::RenderWindow& w);
};

#endif