#ifndef POINTSOPS_H
#define POINTSOPS_H
#include<stdint.h>
#include<vector>
#include"Point.h"

class PointOps
{
	public:
		double PointsOps::getXsum(std::vector<Point> &points,int num_points);
		double PointsOps::getYsum(std::vector<Point> &points,int num_points);
		double PointsOps::getXYsum(std::vector<Point> &points,int num_points);
		double PointsOps::getXsquaredsum(std::vector<Point> &points,int num_points);
};

#endif
