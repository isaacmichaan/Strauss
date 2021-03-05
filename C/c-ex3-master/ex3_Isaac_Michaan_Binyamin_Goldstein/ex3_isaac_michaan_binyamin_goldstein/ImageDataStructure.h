#pragma once
#include "Pixel.h"

class ImageDataStructure
{
private:
	int m_H;
	int m_W;
	Pixel **m_pixel;

public:
	ImageDataStructure();
	ImageDataStructure(int height, int width);
	ImageDataStructure(const ImageDataStructure& other);
	~ImageDataStructure();
	int getH() const;
	int getW() const;
	char getPixel(int, int) const;
	void setPixel(Pixel**);
	void setH(int);
	void setW(int);
	void setPixel(int, int, char);
	ImageDataStructure operator=(const ImageDataStructure& other);
	char& operator()(int, int);
	const char& operator()(unsigned int, unsigned int);
	friend std::ostream& operator<<(std::ostream& os, const ImageDataStructure& image);
	friend std::istream& operator>>(std::istream& os, ImageDataStructure& image);
};

bool operator==(const ImageDataStructure & exist, const ImageDataStructure& other);
ImageDataStructure operator+(const ImageDataStructure& exist, const ImageDataStructure& other);
ImageDataStructure operator+=(ImageDataStructure& exist, const ImageDataStructure& other);
ImageDataStructure operator|(const ImageDataStructure& exist, const ImageDataStructure& other);
ImageDataStructure operator|=(ImageDataStructure& exist, const ImageDataStructure& other);
ImageDataStructure operator&(const ImageDataStructure& exist, const ImageDataStructure& other);
ImageDataStructure operator&=(ImageDataStructure& exist, const ImageDataStructure& other);
ImageDataStructure operator*(ImageDataStructure& exist, int);
ImageDataStructure operator*(int, ImageDataStructure& exist);
ImageDataStructure operator*=(ImageDataStructure& exist, int);
ImageDataStructure operator++(ImageDataStructure& exist);
ImageDataStructure operator--(ImageDataStructure& exist);
ImageDataStructure operator++(ImageDataStructure& exist, int);
ImageDataStructure operator--(ImageDataStructure& exist, int);
