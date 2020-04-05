/*
* Copyright (c) 2015 DottedEye Designs, Alexander Hustinx, NeoTech Software, Rolf Smit - All Rights Reserved
* Unauthorized copying of this file, via any medium is strictly prohibited
* Proprietary and confidential
*/

#pragma once
#include "IntensityImage.h"
#include "RGBImageStudent.h"
#include <cmath>
#include <algorithm>
#include <vector>

class IntensityImageStudent : public IntensityImage {
private:
	Intensity ** image_container;
	void _fill_image_container(const IntensityImageStudent &other, const int &width, const int &height);
	void _init_image_container(const int &width, const int &height);

public:
	IntensityImageStudent();
	IntensityImageStudent(const IntensityImageStudent &other);
	IntensityImageStudent(const int width, const int height);
	~IntensityImageStudent();

	void set(const int width, const int height);
	void set(const IntensityImageStudent &other);

	void setPixel(int x, int y, Intensity pixel);
	void setPixel(int i, Intensity pixel);

	Intensity getPixel(int x, int y) const;
	Intensity getPixel(int i) const;

	Intensity get_intentensity_value(RGB & value);
	Intensity get_intentensity_value(RGB & value, const int & shades_of_grey);

	IntensityImageStudent parse_rgb_image(RGBImage & other);
	void parse_rgb_image(RGBImage & input, IntensityImageStudent & output);

	IntensityImageStudent parse_rgb_image(RGBImage & other, const int & shades_of_grey);
	void parse_rgb_image(RGBImage & input, IntensityImageStudent & output, const int & shades_of_grey);
	
};