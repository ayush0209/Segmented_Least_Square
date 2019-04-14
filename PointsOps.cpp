#include<stdio.h>
#include<vector>
#include<cmath>
#include"Point.h"
#include"PointsOps.h"
using namespace std;

/*!
This function returns summation of x-coordinate values for the input set of points for a line segment
*/
double PointsOps::getXsum(std::vector<Point> &points,int start,int num_points)
{
	double sumX=0;
	for(int i=0;i<num_points;i++)
	{
		sumX+=points[start+i].getX();
	}
	return sumX;
}

/*!
This function returns summation of y-coordinate values for the input set of points for a line segment
*/
double PointsOps::getYsum(std::vector<Point> &points,int start,int num_points)
{
	double sumY=0;
	for(int i=0;i<num_points;i++)
	{
		sumY+=points[start+i].getY();
	}
	return sumY;
}

/*!
This function returns summation of product of x-coordinate and y-coordinate values for the input set of points for a line segment
*/
double PointsOps::getXYsum(std::vector<Point> &points,int start,int num_points)
{
	double sumXY=0;
	for(int i=0;i<num_points;i++)
	{
		sumXY+=(points[start+i].getX()*points[start+i].getY());
	}
	return sumXY;
}

/*!
This function returns summation of square of x-coordinate values for the input set of points for a line segment
*/
double PointsOps::getXsquaredsum(std::vector<Point> &points,int start,int num_points)
{
	double sumX2=0;
	for(int i=0;i<num_points;i++)
	{
		sumX2+=pow(points[start+i].getX(),2);
	}
	return sumX2;
}
