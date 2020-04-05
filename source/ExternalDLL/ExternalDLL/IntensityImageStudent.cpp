#include "IntensityImageStudent.h"

void IntensityImageStudent::_fill_image_container(const IntensityImageStudent &other, const int &width, const int &height ) {
	for (int row = 0; row < height; ++row) {
		for (int col = 0; col < width; ++col) {
			image_container[row][col] = other.getPixel(col, row);
		}
	}
}

void IntensityImageStudent::_init_image_container(const int &width, const int &height) {
	image_container = new Intensity*[height];
	for (int i = 0; i < height; ++i) {
		image_container[i] = new Intensity[width];
	}
}

IntensityImageStudent::IntensityImageStudent() : IntensityImage() {
	//TODO: Nothing
}

IntensityImageStudent::IntensityImageStudent(const IntensityImageStudent &other) :
	IntensityImage( other.getWidth(), other.getHeight() )
{
	int width = other.getWidth();
	int height = other.getHeight();
	_init_image_container(width, height);
	_fill_image_container(other, width, height);
}

IntensityImageStudent::IntensityImageStudent(const int width, const int height) : 
	IntensityImage( width, height )
{
	//TODO: Initialize pixel storage
	_init_image_container(width, height);
}

IntensityImageStudent::~IntensityImageStudent() {
	//TODO: delete allocated objects
	for (int i = 0; i < getHeight(); ++i) {
		delete[] image_container[i];
	}
	delete[] image_container;
}

void IntensityImageStudent::set(const int width, const int height) {
	IntensityImage::set(width, height);
	_init_image_container(width, height);
	//TODO: resize or create a new pixel storage (Don't forget to delete the old storage)
}

void IntensityImageStudent::set(const IntensityImageStudent &other) {
	int width = other.getWidth();
	int height = other.getHeight();
	IntensityImage::set(width, height );
	_init_image_container(width, height);
	_fill_image_container(other, width, height);
	//TODO: resize or create a new pixel storage and copy the object (Don't forget to delete the old storage)
}

void IntensityImageStudent::setPixel(int x, int y, Intensity pixel) {
	image_container[y][x] = pixel;
	//TODO: no comment needed :)
}

void IntensityImageStudent::setPixel(int i, Intensity pixel) {
	int width = getWidth();
	image_container[(int)std::floor(i / width)][i % width] = pixel;
	//TODO: no comment needed :)
}

Intensity IntensityImageStudent::getPixel(int x, int y) const {
	//TODO: no comment needed :)
	return image_container[y][x];
}

Intensity IntensityImageStudent::getPixel(int i) const {
	int width = getWidth();
	return image_container[(int)std::floor(i / width)][i % width];
}

Intensity IntensityImageStudent::get_intentensity_value(RGB & value) {
	Intensity new_value = (int)(0.2126 * value.r + 0.7152 * value.g + 0.0722 * value.b);
	return new_value;
}

Intensity IntensityImageStudent::get_intentensity_value(RGB & value, const int & shades_of_grey) {
	const int factor = 255 / (shades_of_grey - 1);
	const int average = (value.r + value.g, value.b) / 3;
	Intensity new_value = ((average / factor) + 0.5) * factor;
	return new_value;
}

IntensityImageStudent IntensityImageStudent::parse_rgb_image(RGBImage & other) {
	int width = other.getWidth();
	int height = other.getHeight();
	IntensityImageStudent temp(width, height);
	for (int x = 0; x < width; ++x) {
		for (int y = 0; y < height; ++y) {
			temp.setPixel(x, y, get_intentensity_value(other.getPixel(x, y)));
		}
	}
	return temp;
}

void IntensityImageStudent::parse_rgb_image(RGBImage & input, IntensityImageStudent & output) {
	if (output.getWidth() <= 0 || output.getHeight() <= 0) {
		output.set( input.getWidth(), input.getHeight() );
	}
	for (int x = 0; x < input.getWidth(); ++x) {
		for (int y = 0; y < input.getHeight(); ++y) {
			output.setPixel(x, y, get_intentensity_value(input.getPixel(x, y)));
		}
	}
}

IntensityImageStudent IntensityImageStudent::parse_rgb_image(RGBImage & other, const int & shades_of_grey) {
	int width = other.getWidth();
	int height = other.getHeight();
	IntensityImageStudent temp(width, height);
	for (int x = 0; x < width; ++x) {
		for (int y = 0; y < height; ++y) {
			temp.setPixel(x, y, get_intentensity_value(other.getPixel(x, y), shades_of_grey));
		}
	}
	return temp;
}

void IntensityImageStudent::parse_rgb_image(RGBImage & input, IntensityImageStudent & output, const int & shades_of_grey) {
	if (output.getWidth() <= 0 || output.getHeight() <= 0) {
		output.set(input.getWidth(), input.getHeight());
	}
	for (int x = 0; x < input.getWidth(); ++x) {
		for (int y = 0; y < input.getHeight(); ++y) {
			output.setPixel(x, y, get_intentensity_value(input.getPixel(x, y), shades_of_grey));
		}
	}
}

