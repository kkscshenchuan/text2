// text2.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include "opencv.hpp"
using namespace std;
using namespace cv;


int main()
{
	Mat image(5, 5, CV_8UC1);  
	for (int i = 0; i < image.rows; i++)
	{
		uchar *p = image.ptr<uchar>(i);
		for (int j = 0; j < image.cols; j++)
		{
			if (i==j)      
			{
				p[j] = 255;
			}
			else
			{
				p[j] = 0;
			}

		}
	}
	image.at<uchar>(1, 2) = 255;
	image.at<uchar>(2, 3) = 255;
	image.at<uchar>(3, 4) = 255;
	//namedWindow("原图", 1);
	imshow("原图", image);
	imwrite("c.png", image);   

	int height = image.rows;
	int width = image.cols;

	vector<vector<int>> state(height, vector<int>(width, 0));

	for (int i = 0; i < height; i++)
	{
		uchar *p = image.ptr<uchar>(i);  //指向原图
		for (int j = 0; j < width; j++)
		{
			if (p[j] ==0)
			{
				state[i][j] = 0;
			}
			else
			{
				state[i][j] = 1;
			}
		}
	}

	int x = 0;//记录下一个出发点的坐标
	int y = 0;

	//找出显著性最大的点作为种子点
	bool seed = false;
	for (int i = 0; i < height; i++)
	{
		if (seed) break;
		for (int j = 0; j < width; j++)
		{
			if (state[i][j] == 1)
			{
				y = i;
				x = j;
				seed = true;
				break;
			}
			else
			{
				seed = false;
			}

		}
	}

	//测试数据
	/*x = 52;
	y = 30;*/


	cout << y << " " << x << endl;
	waitKey(0);
    return 0;
}

