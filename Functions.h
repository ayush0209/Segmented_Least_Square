#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include<stdint.h>
#include<vector>
#include"Point.h"

class Functions
{
	public:
		double getBeta(std::vector<Point> &points,int num_points);
		double getAplha(std::vector<Point> &points,int num_points,double beta);
		double leastsquareError(std::vector<Point> &points,int size);
};

#endif
