/*
* Copyright (c) 2015 DottedEye Designs, Alexander Hustinx, NeoTech Software, Rolf Smit - All Rights Reserved
* Unauthorized copying of this file, via any medium is strictly prohibited
* Proprietary and confidential
*/

#pragma once
#include "RGBImage.h"
#include "IntensityImageStudent.h"
#include <cmath>

class RGBImageStudent : public RGBImage {
private:
	RGB **image_container;
	void _fill_image_container(const RGBImageStudent &other, const int &width, const int &height );
	void _init_image_container(const int &width, const int &height);

public:
	RGBImageStudent();
	RGBImageStudent(const RGBImageStudent &other);
	RGBImageStudent(const int width, const int height);
	~RGBImageStudent();

	void set(const int width, const int height);
	void set(const RGBImageStudent &other);

	void setPixel(int x, int y, RGB pixel);
	void setPixel(int i, RGB pixel);

	RGB getPixel(int x, int y) const;
	RGB getPixel(int i) const;

	//IntensityImageStudent to_intensity(RGBImage & other);
	//IntensityImageStudent to_intensity(RGBImage & other, int shades_of_grey);
};
