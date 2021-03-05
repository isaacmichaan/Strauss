#include "ImageDataStructure.h"
#include <iostream>
#include <string>

//=========================================
//		C-tor							
//=========================================
ImageDataStructure::ImageDataStructure()
{
}

ImageDataStructure::ImageDataStructure(int height, int width)
{
	m_H = height;
	m_W = width;
}

ImageDataStructure::ImageDataStructure(const ImageDataStructure & other)
{
	setPixel(other.m_pixel);
}


//=========================================
//		D-tor								
//========================================
ImageDataStructure::~ImageDataStructure()
{
}


//=========================================
//		Get H								
//=========================================
//@Func. descr.: This func. returns the height.
//@Params: non.
//@Return: int.
int ImageDataStructure::getH() const
{
	return m_H;
}


//=========================================
//		Get W								
//=========================================
//@Func. descr.: This func. returns the width.
//@Params: non.
//@Return: int.
int ImageDataStructure::getW() const
{
	return m_W;
}


//=========================================
//		Get Pixel								
//=========================================
//@Func. descr.: This func. returns a char.
//m_pixel[][] -> getColor() -> m_color
//@Params: int, int.
//@Return: char.
char ImageDataStructure::getPixel(int i, int j) const
{
	return m_pixel[i][j].getColor();
}


//=========================================
//		Set Pixel								
//=========================================
//@Func. descr.: //need
//@Params: Pixel.
//@Return: non.
void ImageDataStructure::setPixel(Pixel** pixel)
{
	m_pixel = pixel;
}


//=========================================
//		set H								
//========================================
//@Func. descr.: This func. set the height.
//@Params: int.
//@Return: non.
void ImageDataStructure::setH(int height) 
{
	m_H = height;
}


//=========================================
//		set W								
//========================================
//@Func. descr.: This func. set the height.
//@Params: int.
//@Return: non.
void ImageDataStructure::setW(int width)
{
	m_W = width;
}


//=========================================
//		Set Pixel								
//=========================================
//@Func. descr.: This func. set Pixel.
//@Params: int, int.
//@Return: non.
void ImageDataStructure::setPixel(int i, int j, char c)
{
	m_pixel[i][j].setColor(c);
}


//=========================================
//		operator ==								
//========================================
bool operator==(const ImageDataStructure & exist, const ImageDataStructure& other)
{
	if (exist.getH() != other.getH() || exist.getW() != other.getW()) return false;
	
	for (int i = 0; i < other.getH(); i++)
	{
		for (int j = 0; j < other.getW(); j++)
		{
			if (exist.getPixel(i,j) != other.getPixel(i,j))
				return false;
		}
	}
	return true;
}


//=========================================
//		operator =								
//========================================
ImageDataStructure ImageDataStructure::operator=(const ImageDataStructure & other)
{
	Pixel** temp = new Pixel*[other.getH()];

	for (int i = 0; i < other.getH(); i++)
	{
		temp[i] = new Pixel[other.getW()];
		for (int j = 0; j < other.getW(); j++)
		{
			temp[i][j].setColor(other.getPixel(i,j));
		}
	}

	for (int i = 0; i < getH(); i++)
		delete[] m_pixel[i];

	setH(other.getH());
	setW(other.getW());

	delete[] m_pixel;
	m_pixel = temp;
	return *this;
}


//=========================================
//		operator ()								
//=========================================
//@Func. descr.: //need
//@Params: int, int.
//@Return: char.
char & ImageDataStructure::operator()(int i, int j)
{
	char c = getPixel(i,j);
	return c;
}


//=========================================
//		operator ()								
//=========================================
//@Func. descr.: //need
//@Params: int, int.
//@Return: char.
const char & ImageDataStructure::operator()(unsigned int i, unsigned int j)
{
	return getPixel(i, j);
}


//=========================================
//		Operator +								
//=========================================
//@Func. descr.: This func. //need
//@Params: const ImageDataStructure &, const ImageDataStructure &
//@Return: ImageDataStructure
ImageDataStructure operator+(const ImageDataStructure & exist, const ImageDataStructure & other)
{
	int H = (exist.getH() > other.getH() ? exist.getH() : other.getH());
	Pixel** pixel = new Pixel*[H];
	int W = exist.getW() + other.getW();

	int j;
	
	for (int i = 0; i < other.getH(); i++)
	{
		pixel[i] = new Pixel[W];
		for (j = 0; j < other.getW(); j++)
			pixel[i][j].setColor(other.getPixel(i, j));
	}

	for (int i = 0; i < exist.getH(); i++)
	{
		int k = j + 1;
		for (j = 0; j < exist.getW(); j++, k++)
			pixel[i][k].setColor(exist.getPixel(i, j));
	}

	ImageDataStructure imageDataStructure;
	imageDataStructure.setH(H);
	imageDataStructure.setW(W);
	imageDataStructure.setPixel(pixel);
	return imageDataStructure;
}


//=========================================
//		Operator +=								
//=========================================
//@Func. descr.: This func. //need
//@Params: const ImageDataStructure &, const ImageDataStructure &
//@Return: ImageDataStructure
ImageDataStructure operator+=(ImageDataStructure & exist, const ImageDataStructure & other)
{
	return exist = (exist + other);
}


//=========================================
//		Operator |								
//=========================================
//@Func. descr.: This func. //need
//@Params: const ImageDataStructure &, const ImageDataStructure &
//@Return: ImageDataStructure
ImageDataStructure operator|(const ImageDataStructure & exist, const ImageDataStructure & other)
{
	int H = (exist.getH() > other.getH() ? exist.getH() : other.getH());
	Pixel** pixel = new Pixel*[H];
	int W = (exist.getW() > other.getW() ? exist.getW() : other.getW());

	bool othe = true;
	bool exis = true;
	for (int i = 0; i < H; i++)
	{
		pixel[i] = new Pixel[W];
		if (i >= other.getH()) othe = false;
		if (i >= exist.getH()) exis = false;
		for (int j = 0; j < W; j++)
		{
			if (othe)
				if (j < other.getH() && j >= exist.getH()) pixel[i][j].setColor(other.getPixel(i, j));
			if (exis)
				if (j >= other.getH() && j < exist.getH()) pixel[i][j].setColor(exist.getPixel(i, j));
			else if (othe && exis) pixel[i][j].setColor(exist.getPixel(i, j) > other.getPixel(i, j) ? exist.getPixel(i, j) : other.getPixel(i, j));
		}
	}

	ImageDataStructure imageDataStructure;
	imageDataStructure.setH(H);
	imageDataStructure.setW(W);
	imageDataStructure.setPixel(pixel);
	return imageDataStructure;
}


//=========================================
//		Operator |=								
//=========================================
//@Func. descr.: This func. //need
//@Params: const ImageDataStructure &, const ImageDataStructure &
//@Return: ImageDataStructure
ImageDataStructure operator|=(ImageDataStructure & exist, const ImageDataStructure & other)
{
	return exist = (exist | other);
}


//=========================================
//		Operator &=							
//=========================================
//@Func. descr.: This func. //need
//@Params: const ImageDataStructure &, const ImageDataStructure &
//@Return: ImageDataStructure
ImageDataStructure operator&(const ImageDataStructure & exist, const ImageDataStructure & other)
{
	int H = (exist.getH() > other.getH() ? exist.getH() : other.getH());
	Pixel** pixel = new Pixel*[H];
	int W = (exist.getW() > other.getW() ? exist.getW() : other.getW());

	bool othe = true;
	bool exis = true;
	for (int i = 0; i < H; i++)
	{
		pixel[i] = new Pixel[W];
		if (i >= other.getH()) othe = false;
		if (i >= exist.getH()) exis = false;
		for (int j = 0; j < W; j++)
		{
			if (othe)
				if (j < other.getH() && j >= exist.getH()) pixel[i][j].setColor(other.getPixel(i, j));
			if (exis)
				if (j >= other.getH() && j < exist.getH()) pixel[i][j].setColor(exist.getPixel(i, j));
				else if (othe && exis) pixel[i][j].setColor(exist.getPixel(i, j) < other.getPixel(i, j) ? exist.getPixel(i, j) : other.getPixel(i, j));
		}
	}

	ImageDataStructure imageDataStructure;
	imageDataStructure.setH(H);
	imageDataStructure.setW(W);
	imageDataStructure.setPixel(pixel);
	return imageDataStructure;
}


//=========================================
//		Operator &=								
//=========================================
//@Func. descr.: This func. //need
//@Params: const ImageDataStructure &, const ImageDataStructure &
//@Return: ImageDataStructure
ImageDataStructure operator&=(ImageDataStructure & exist, const ImageDataStructure & other)
{
	return exist = (exist & other);
}


//=========================================
//		Operator *								
//=========================================
//@Func. descr.: This func. //need
//@Params: const ImageDataStructure &, int
//@Return: ImageDataStructure
ImageDataStructure operator*(ImageDataStructure & exist, int x)
{
	ImageDataStructure imageDataStructure;
	for (int i = 0; i < x; i++)
		imageDataStructure += exist;
	return imageDataStructure;
}


//=========================================
//		Operator *								
//=========================================
//@Func. descr.: This func. //need
//@Params: const ImageDataStructure &, int
//@Return: ImageDataStructure
ImageDataStructure operator*(int x, ImageDataStructure & exist)
{
	return (exist * x);
}


//=========================================
//		Operator *=								
//=========================================
//@Func. descr.: This func. //need
//@Params: const ImageDataStructure &, int
//@Return: ImageDataStructure
ImageDataStructure operator*=(ImageDataStructure & exist, int x)
{
	return exist = (exist * x);
}


//=========================================
//		++Operator 								
//=========================================
//@Func. descr.: This func. //need
//@Params: const ImageDataStructure &
//@Return: ImageDataStructure
ImageDataStructure operator++(ImageDataStructure & exist)
{
	int H = exist.getH();
	Pixel** pixel = new Pixel*[H];
	int W = (exist.getW() * 2);
	
	for (int i = 0; i < H; i++)
	{
		pixel[i] = new Pixel[W];
		
		for (int j = 0, k = 0; k < W; j++, k+=2)
		{
			pixel[i][k].setColor(exist.getPixel(i, j));
			pixel[i][k+1].setColor(exist.getPixel(i, j));
		}
	}

	ImageDataStructure imageDataStructure;
	imageDataStructure.setH(H);
	imageDataStructure.setW(W);
	imageDataStructure.setPixel(pixel);
	return exist = imageDataStructure;
}


//=========================================
//		--Operator 								
//=========================================
//@Func. descr.: This func. //need
//@Params: const ImageDataStructure &
//@Return: ImageDataStructure
ImageDataStructure operator--(ImageDataStructure & exist)
{
	int H = exist.getH();
	Pixel** pixel = new Pixel*[H];
	int W = (exist.getW() / 2);

	for (int i = 0; i < H; i++)
	{
		pixel[i] = new Pixel[W];

		for (int j = 0; j < W; j+=2)
		{
			pixel[i][j].setColor(exist.getPixel(i, j));
		}
	}

	ImageDataStructure imageDataStructure;
	imageDataStructure.setH(H);
	imageDataStructure.setW(W);
	imageDataStructure.setPixel(pixel);
	return exist = imageDataStructure;
}


//=========================================
//		Operator ++								
//=========================================
//@Func. descr.: This func. //need
//@Params: const ImageDataStructure &
//@Return: ImageDataStructure
ImageDataStructure operator++(ImageDataStructure & exist, int)
{
	ImageDataStructure imageDataStructure;
	imageDataStructure = exist;
	++exist;
	return imageDataStructure;
}


//=========================================
//		Operator --								
//=========================================
//@Func. descr.: This func. //need
//@Params: const ImageDataStructure &
//@Return: ImageDataStructure
ImageDataStructure operator--(ImageDataStructure & exist, int)
{
	ImageDataStructure imageDataStructure;
	imageDataStructure = exist;
	--exist;
	return imageDataStructure;
}


//=========================================
//		Operator Cout								
//=========================================
//@Func. descr.: This func. makes the cout.
//@Params: ostream and Image.
//@Return: ostream.
std::ostream& operator<<(std::ostream& os, const ImageDataStructure& image)
{
	for (int i = 0; i < image.m_H; i++)
	{
		for (int j = 0; j < image.m_W; j++)
		{
			os << image.m_pixel[i][j];
		}
		os << std::endl;
	}
	return os;
}


//=========================================
//		Operator Cin								
//=========================================
//@Func. descr.: This func. makes the cin.
//@Params: ostream and Image.
//@Return: ostream.
std::istream& operator>>(std::istream& os, ImageDataStructure& image)
{
	std::string c;
	std::getline(os, c);
	
	image.m_pixel = new Pixel*[image.m_H];

	for (int i = 0; i < image.m_H; ++i)
	{
		image.m_pixel[i] = new Pixel[image.m_W];
		std::getline(os, c);
		for (int j = 0; j < c.size(); ++j)
			image.m_pixel[i][j].setColor(c[j]);
	}
	return os;
}
