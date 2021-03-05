#pragma once
#include <iostream>
#include "ImageDataStructure.h"

class Image
{
private:
	int m_H;
	int m_W;
	ImageDataStructure* m_imageDataStructure;

public:
	Image();
	Image(int height, int width);
	Image(const Image & other);
	~Image();
	int GetHeight() const;
	int GetWidth() const;
	ImageDataStructure& getImageDataStructure() const;
	ImageDataStructure operator=(const Image& other);
	char& operator()(int, int);
	const char& operator()(unsigned int, unsigned int);
	friend std::ostream& operator<<(std::ostream& os, const Image& image);
	friend std::istream& operator>>(std::istream& os, Image& image);
};

bool operator==(const Image& exist, const Image& other);
bool operator!=(const Image& exist, const Image& other);
ImageDataStructure operator+(const Image& exist, const Image& other);
ImageDataStructure operator+=(const Image& exist, const Image& other);
ImageDataStructure operator|(const Image& exist, const Image& other);
ImageDataStructure operator|=(const Image& exist, const Image& other);
ImageDataStructure operator&(const Image& exist, const Image& other);
ImageDataStructure operator&=(const Image& exist, const Image& other);
ImageDataStructure operator*(const Image& exist, int x);
ImageDataStructure operator*(int x,const Image& exist);
ImageDataStructure operator*=(const Image& exist, int x);
ImageDataStructure operator++(const Image& exist);
ImageDataStructure operator--(const Image& exist);
ImageDataStructure operator++(const Image& exist, int);
ImageDataStructure operator--(const Image& exist, int);

