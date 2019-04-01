#include<stdint.h>
#include<vector>
#include<cmath>
#include"Point.h"
#include"PointsOps.h"
using namespace std;

double PointsOps::getXsum(std::vector<Point> &points,int start,int num_points)
{
	double sumX=0;
	for(int i=0;i<num_points;i++)
	{
		sumX+=points[start+i].getX();
	}
	return sumX;
}

double PointsOps::getYsum(std::vector<Point> &points,int start,int num_points)
{
	double sumY=0;
	for(int i=0;i<num_points;i++)
	{
		sumY+=points[start+i].getY();
	}
	return sumY;
}

double PointsOps::getXYsum(std::vector<Point> &points,int start,int num_points)
{
	double sumXY=0;
	for(int i=0;i<num_points;i++)
	{
		sumXY+=(points[start+i].getX()*points[start+i].getY());
	}
	return sumXY;
}


double PointsOps::getXsquaredsum(std::vector<Point> &points,int start,int num_points)
{
	double sumX2=0;
	for(int i=0;i<num_points;i++)
	{
		sumX2+=pow(points[start+i].getX(),2);
	}
	return sumX2;
}
