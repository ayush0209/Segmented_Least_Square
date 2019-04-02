#ifndef POINTSOPS_H
#define POINTSOPS_H
#include<stdio.h>
#include<vector>
#include"Point.h"

class PointsOps
{
	public:
		double getXsum(std::vector<Point> &points,int start,int num_points);
		double getYsum(std::vector<Point> &points,int start,int num_points);
		double getXYsum(std::vector<Point> &points,int start,int num_points);
		double getXsquaredsum(std::vector<Point> &points,int start,int num_points);
};

#endif
