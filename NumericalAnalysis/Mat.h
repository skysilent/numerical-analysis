#pragma once
class Mat
{
private:
	
	int getIndex(int i, int j);
	double getItem(int i, int j);
public:
	Mat();
	~Mat();
	Mat(int width, int height);
	Mat(const Mat& a);
	void zeros(void);
	Mat operator+(const Mat &a);
	Mat operator-(const Mat &b);
	Mat operator*(const Mat &b);	
	double *data;
	int width; int height; int itemsum;
};

