#include "Pixel.h"
#include <iostream>
#include <algorithm>

//=========================================
//		C-tor							
//=========================================
Pixel::Pixel()
{
}


//=========================================
//		D-tor							
//=========================================
Pixel::~Pixel()
{
}


//=========================================
//		Get Color							
//=========================================
//@Func. descr.: This func. returns a char 
//of the member Pixel m_color.
//@Params: non.
//@Return: char.
char Pixel::getColor() const
{
	return m_color;
}


//=========================================
//		Set Color							
//=========================================
//@Func. descr.: This func. sets a color 
//to the member Pixel m_color.
//@Params: char.
//@Return: non.
int Pixel::setColor(char c)
{
	return m_color = c;
}


//=========================================
//		Operator ==							
//=========================================
//@Func. descr.: This func. returns true if 
//thise->m_color == other->color otherwise it returns 
//false
//@Params: Pixel.
//@Return: bool.
bool operator==(const Pixel& exist, const Pixel & other)
{
	return (exist.getColor() == other.getColor());
}


//=========================================
//		Operator !=							
//=========================================
//@Func. descr.: This func. returns true if 
//thise->m_color != other->color otherwise it returns 
//false
//@Params: Pixel.
//@Return: bool.
bool operator!=(const Pixel& exist, const Pixel & other)
{
	return !(exist.getColor() == other.getColor());
}


//=========================================
//		Operator |							
//=========================================
//@Func. descr.: This func. returns a new Pixel with the 
//max between the colors
//@Params: Pixel.
//@Return: new Pixel.
char operator|(const Pixel& exist, const Pixel & other)
{
	return (std::max(exist.getColor(), other.getColor()));
}


//=========================================
//		Operator |=							
//=========================================
//@Func. descr.: This func. returns the *this Pixel with the 
//max between the colors
//@Params: Pixel.
//@Return: *this Pixel.
char operator|=(Pixel & exist, const Pixel & other)
{ 
	return exist.setColor(exist | other);
}


//=========================================
//		Operator &							
//=========================================
//@Func. descr.: This func. returns a new Pixel with the 
//min between the colors
//@Params: Pixel.
//@Return: new Pixel.
char operator&(const Pixel& exist, const Pixel & other)
{
	return (std::min(exist.getColor(), other.getColor()));
}


//=========================================
//		Operator &=							
//=========================================
//@Func. descr.: This func. returns the *this Pixel with the 
//min between the colors
//@Params: Pixel.
//@Return: *this Pixel.
char operator&=(Pixel& exist, const Pixel & other)
{
	return exist.setColor(exist & other);
}


//=========================================
//		Operator Cout							
//=========================================
//@Func. descr.: This func. makes the cout.
//@Params: ostream and Pixel.
//@Return: ostream.
std::ostream & operator<<(std::ostream & os, const Pixel & pixel)
{
	return os << pixel.m_color/* << std::endl*/;
}