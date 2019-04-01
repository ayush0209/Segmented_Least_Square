#include<stdint.h>
#include<vector.h>
#include<cmath.h>
#include"Point.h"
#include"PointOps.h"
#include"Functions.h"
using namespace std;

PointsOps pointsopsAPI;

double Functions::getBeta(std::vector<Point> &points,int num_points)
{
	double mean_X,mean_Y,beta,sum_XY,sum_Xsquared;
	mean_X=pointsopsAPI.getXsum(std::vector<Point> &points,int num_points)/num_points;
	mean_Y=pointsopsAPI.getYsum(std::vector<Point> &points,int num_points)/num_points;
	sum_XY=pointsopsAPI.getXYsum(std::vector<Point> &points,int num_points);
	sum_Xsquared=pointsopsAPI.getXsquaredsum(std::vector<Point> &points,int num_points);
	beta=(sum_XY-(num_points*mean_X*mean_Y))/(sum_Xsquared-(num_points*pow(mean_X),2))
	return beta;
}

double Functions::getAplha(std::vector<Point> &points,int num_points,double beta)
{
	double mean_X,mean_Y,alpha;
	mean_X=pointsopsAPI.getXsum(std::vector<Point> &points,int num_points)/num_points;
	mean_Y=pointsopsAPI.getYsum(std::vector<Point> &points,int num_points)/num_points;
	alpha=mean_Y-(beta*mean_X);
	return alpha;
}

double Functions::leastsquareError(std::vector<Point> &points,int num_points)
{
	int i;
	double alpha,beta,predicted_value,difference,error=0.0;

	std::vector<double> predictions;

	beta=this->getBeta(std::vector<Point> &points,int num_points);
	alpha=this->getAlpha(std::vector<Point> &points,int num_points,beta);
	
	
	for(i=0;i<num_points;i++)
	{
		predicted_value=alpha+(beta*points[i].getX())
		predictions.push_back(predicted_value);
	}

	for(i=0;i<num_points;i++)
	{
		difference=points[i].getY()-predictions[i]
		error+=pow(difference,2)
	}

	return error;
}
