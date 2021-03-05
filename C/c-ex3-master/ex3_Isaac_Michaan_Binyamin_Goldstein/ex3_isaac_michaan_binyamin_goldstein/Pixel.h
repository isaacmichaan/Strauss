#pragma once
#include <iostream>

const unsigned char BLACK = (unsigned char)219;
const unsigned char GRAY = (unsigned char)176;
const unsigned char WHITE = (unsigned char)32;

class Pixel
{
private:
	char m_color;

public:
	Pixel();
	~Pixel();
	char getColor() const;// returns m_color
	int setColor(char); // returns m_color
	friend std::ostream& operator<<(std::ostream& , const Pixel& ); //cout m_color
};

bool operator==(const Pixel& exist, const Pixel & other);
bool operator!=(const Pixel& exist, const Pixel & other);
char operator|(const Pixel& exist, const Pixel & other);
char operator|=(Pixel& exist, const Pixel & other);
char operator&(const Pixel& exist, const Pixel & other);
char operator&=(Pixel& exist, const Pixel & other);