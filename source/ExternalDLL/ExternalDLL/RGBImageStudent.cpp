#include "RGBImageStudent.h"

void RGBImageStudent::_fill_image_container(const RGBImageStudent &other, const int &width, const int &height ) {
	for (int row = 0; row < height; ++row) {
		for (int col = 0; col < width; ++col) {
			image_container[row][col] = other.getPixel(col, row);
		}
	}
}

void RGBImageStudent::_init_image_container(const int &width, const int &height) {
	image_container = new RGB*[height];
	for (int i = 0; i < height; ++i) {
		image_container[i] = new RGB[width];
	}
}

RGBImageStudent::RGBImageStudent() : RGBImage() {
	//TODO: Nothing
}

RGBImageStudent::RGBImageStudent(const RGBImageStudent &other) :
	RGBImage( other.getWidth(), other.getHeight() )
{
	int width = other.getWidth();
	int height = other.getHeight();
	_init_image_container(width, height);
	_fill_image_container(other, width, height);
}

RGBImageStudent::RGBImageStudent(const int width, const int height) : 
	RGBImage( width, height )
{
	//TODO: Initialize pixel storage
	_init_image_container(width, height);
}

RGBImageStudent::~RGBImageStudent() {
	//TODO: delete allocated objects
	for (int i = 0; i < getHeight(); ++i) {
		delete[] image_container[i];
	}
	delete[] image_container;
}

void RGBImageStudent::set(const int width, const int height) {
	RGBImage::set(width, height);
	_init_image_container(width, height);
	//TODO: resize or create a new pixel storage (Don't forget to delete the old storage)
}

void RGBImageStudent::set(const RGBImageStudent &other) {
	int width = other.getWidth();
	int height = other.getHeight();
	RGBImage::set(width, height );
	_init_image_container(width, height);
	_fill_image_container(other, width, height);
	//TODO: resize or create a new pixel storage and copy the object (Don't forget to delete the old storage)
}

void RGBImageStudent::setPixel(int x, int y, RGB pixel) {
	image_container[y][x] = pixel;
	//TODO: no comment needed :)
}

void RGBImageStudent::setPixel(int i, RGB pixel) {
	int width = getWidth();
	image_container[ (int)std::floor( i / width ) ][ i % width ] = pixel;
}

RGB RGBImageStudent::getPixel(int x, int y) const {
	//TODO: no comment needed :)
	return image_container[y][x];
}

RGB RGBImageStudent::getPixel(int i) const {
	int width = getWidth();
	return image_container[(int)std::floor(i / width)][i % width];
}

//IntensityImageStudent RGBImageStudent::to_intensity(RGBImage & other) {
//	IntensityImageStudent temp;
//	return temp.parse_rgb_image(other);
//}

//IntensityImageStudent RGBImageStudent::to_intensity(RGBImage & other, int shades_of_grey) {
//	IntensityImageStudent temp;
//	return temp.parse_rgb_image(other, shades_of_grey);
//}

