#include "Mat.h"



int Mat::getIndex(int i, int j)
{
	return i *width + j;
}

double Mat::getItem(int i, int j)
{
	return data[getIndex(i,j)];
}

Mat::Mat()
{
}


Mat::~Mat()
{
}

Mat::Mat(int w, int h)
{
	 width=w;
	 height = h;
	 itemsum = w*h;
	 data = new double[itemsum];
}

Mat::Mat(const Mat & a)
{
	/*for (int i = 0; i < _width; i++) {
		for (int j = 0; j < _height; j++) {
			data[getIndex(i, j)] = a.data[getIndex(i, j)];
		}
	}*/
	data = new double[itemsum];
	for (int i = 0; i < itemsum; i++) {
		data[i] = a.data[i];
	}
}

void Mat::zeros(void)
{
	for (int i = 0; i < itemsum; i++)
		data[i] = 0.0;
}

Mat Mat::operator+(const Mat& a)
{
	Mat mat;
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			mat.data[getIndex(i, j)] = data[getIndex(i, j)] + a.data[getIndex(i, j)];
		}
	}
	return mat;
}
Mat Mat::operator-(const Mat& a)
{
	Mat mat;
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			mat.data[getIndex(i, j)] = data[getIndex(i, j)] - a.data[getIndex(i, j)];
		}
	}
	return mat;
}
Mat Mat::operator*(const Mat& a)
{
	Mat mat = Mat(width, a.height);
	mat.zeros();
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
		    for(int k=0;k<a.height;k++)
			mat.data[getIndex(i, k)] = data[getIndex(i, j)] - a.data[getIndex(j, k)];
		}
	}
	return mat;
}

Mat & operator+(const Mat & a, const Mat & b)
{
	Mat *ret=new Mat(a.width, a.height);
	for (int i = 0; i < a.itemsum; i++) {
		ret->data[i] = a.data[i] + b.data[i];
	}
	return *ret;
}
