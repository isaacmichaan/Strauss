#include "Image.h"
#include <algorithm>

//=========================================
//		C-tor							
//=========================================
Image::Image()
{
	m_H = 0;
	m_W = 0;
	m_imageDataStructure = nullptr;
}

//=========================================
//		C-tor with H and W								
//=========================================
//@Func. descr.: This C-tor func. receives the height and width.
//@Params: height and width.
//@Return: non.
Image::Image(int height, int width)
{
	m_H = height;
	m_W = width;
	m_imageDataStructure = new ImageDataStructure(m_H, m_W);
}

//=========================================
//		Copy C-tor								
//=========================================
//@Func. descr.: This Copy C-tor func. copy their height and width.
//@Params: Image.
//@Return: non.
Image::Image(const Image & other)
	: m_H(other.m_H), m_W(other.m_W), m_imageDataStructure(new ImageDataStructure(*other.m_imageDataStructure))
{}

//=========================================
//		D-tor								
//=========================================
Image::~Image()
{}


//=========================================
//		Get Height								
//=========================================
//@Func. descr.: This func. returns height.
//@Params: non.
//@Return: int.
int Image::GetHeight() const
{
	return m_H;
}


//=========================================
//		Get Width								
//=========================================
//@Func. descr.: This func. returns width.
//@Params: non.
//@Return: int.
int Image::GetWidth() const
{
	return m_W;
}


//=========================================
//		Get Width								
//=========================================
//@Func. descr.: This func. returns a pointer.
//@Params: non.
//@Return: ImageDataStructure&.
ImageDataStructure & Image::getImageDataStructure() const
{
	return *m_imageDataStructure;
}


//=========================================
//		Operator ==							
//=========================================
//@Func. descr.: This func. returns true if 
//thise->m_imageDataStructure == other->m_imageDataStructure 
//otherwise it returns false
//@Params: Image.
//@Return: bool.
bool operator==(const Image& exist, const Image& other)
{
	return (exist.getImageDataStructure() == other.getImageDataStructure());
}


//=========================================
//		Operator !=							
//=========================================
//@Func. descr.: This func. returns true if 
//thise->m_imageDataStructure != other->m_imageDataStructure 
//otherwise it returns false
//@Params: Image.
//@Return: bool.
bool operator!=(const Image& exist, const Image& other)
{
	return !(exist.getImageDataStructure() == other.getImageDataStructure());
}


//=========================================
//		Assigment Operator(=)						
//=========================================
//@Func. descr.: This func. copy one image to another.
//@Params: Image.
//@Return: Image&.
ImageDataStructure Image::operator=(const Image & other)
{
	return (*m_imageDataStructure = *other.m_imageDataStructure);
}


//=========================================
//		Operator ()								
//=========================================
//@Func. descr.: This func. //need
//@Params: int, int .
//@Return: char.
char & Image::operator()(int i, int j)
{
	return (*m_imageDataStructure)(i,j);
}


//=========================================
//		Operator ()								
//=========================================
//@Func. descr.: This func. //need
//@Params: int, int .
//@Return: const char.
const char & Image::operator()(unsigned int i, unsigned int j)
{
	return (*m_imageDataStructure)(i, j);
}


//=========================================
//		Operator +								
//=========================================
//@Func. descr.: This func. //need
//@Params: const Image&, const Image& .
//@Return: Image.
ImageDataStructure operator+(const Image & exist, const Image & other)
{
	return (exist.getImageDataStructure() + other.getImageDataStructure());
}


//=========================================
//		Operator +=								
//=========================================
//@Func. descr.: This func. //need
//@Params: const Image&, const Image& .
//@Return: Image.
ImageDataStructure operator+=(const Image & exist, const Image & other)
{
	return (exist.getImageDataStructure() += other.getImageDataStructure());
}


//=========================================
//		Operator |								
//=========================================
//@Func. descr.: This func. //need
//@Params: const Image&, const Image& .
//@Return: ImageDataStructure.
ImageDataStructure operator|(const Image & exist, const Image & other)
{
	return (exist.getImageDataStructure() | other.getImageDataStructure());
}


//=========================================
//		Operator |=								
//=========================================
//@Func. descr.: This func. //need
//@Params: const Image&, const Image& .
//@Return: ImageDataStructure.
ImageDataStructure operator|=(const Image & exist, const Image & other)
{
	return (exist.getImageDataStructure() |= other.getImageDataStructure());
}


//=========================================
//		Operator &							
//=========================================
//@Func. descr.: This func. //need
//@Params: const Image&, const Image& .
//@Return: ImageDataStructure.
ImageDataStructure operator&(const Image & exist, const Image & other)
{
	return (exist.getImageDataStructure() & other.getImageDataStructure());
}


//=========================================
//		Operator |&=							
//=========================================
//@Func. descr.: This func. //need
//@Params: const Image&, const Image& .
//@Return: ImageDataStructure.
ImageDataStructure operator&=(const Image & exist, const Image & other)
{
	return (exist.getImageDataStructure() &= other.getImageDataStructure());
}


//=========================================
//		Operator *							
//=========================================
//@Func. descr.: This func. //need
//@Params: const Image&, int .
//@Return: ImageDataStructure.
ImageDataStructure operator*(const Image & exist, int x)
{
	return (exist.getImageDataStructure() * x);
}


//=========================================
//		Operator *								
//=========================================
//@Func. descr.: This func. //need
//@Params: const Image&, int .
//@Return: ImageDataStructure.
ImageDataStructure operator*(int x, const Image & exist)
{
	return ( x * exist.getImageDataStructure() );
}


//=========================================
//		Operator *=								
//=========================================
//@Func. descr.: This func. //need
//@Params: const Image&, int.
//@Return: ImageDataStructure.
ImageDataStructure operator*=(const Image & exist, int x)
{
	return (exist.getImageDataStructure() *= x);
}


//=========================================
//		 ++ Operator							
//=========================================
//@Func. descr.: This func. //need
//@Params: const Image&
//@Return: ImageDataStructure.
ImageDataStructure operator++(const Image & exist)
{
	return ++(exist.getImageDataStructure());
}


//=========================================
//		-- Operator 						
//=========================================
//@Func. descr.: This func. //need
//@Params: const Image&
//@Return: ImageDataStructure.
ImageDataStructure operator--(const Image & exist)
{
	return --(exist.getImageDataStructure());
}


//=========================================
//		Operator ++							
//=========================================
//@Func. descr.: This func. //need
//@Params: const Image&, int
//@Return: ImageDataStructure.
ImageDataStructure operator++(const Image & exist, int)
{
	return (exist.getImageDataStructure())++;
}


//=========================================
//		Operator --							
//=========================================
//@Func. descr.: This func. //need
//@Params: const Image&, int
//@Return: ImageDataStructure.
ImageDataStructure operator--(const Image & exist, int)
{
	return (exist.getImageDataStructure())--;
}


//=========================================
//		Operator Cout								
//=========================================
//@Func. descr.: This func. makes the cout.
//@Params: ostream and Image.
//@Return: ostream.
std::ostream& operator<<(std::ostream& os, const Image& image)
{
	return os << *(image.m_imageDataStructure);
}


//=========================================
//		Operator Cin								
//=========================================
//@Func. descr.: This func. makes the cout.
//@Params: ostream and Image.
//@Return: ostream.
std::istream& operator>>(std::istream& os, Image& image)
{
	int H, W;
	os >> H >> W;

	if (image.m_imageDataStructure == nullptr)
		image.m_imageDataStructure = new ImageDataStructure(H,W);

	return os >> *(image.m_imageDataStructure);
}