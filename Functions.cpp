#include<stdio.h>
#include<vector>
#include<cmath>
#include"Point.h"
#include"PointsOps.h"
#include"Functions.h"
using namespace std;

PointsOps pointsopsAPI;
/*! This function calculates beta for the equation of line of the form y=(beta)*x + (alpha)
\param points set of input points
\param start This is the starting index for points in a new line segment
\param num_points number of points
\return beta as a double value is returned
*/
double Functions::getBeta(std::vector<Point> &points,int start,int num_points)
{
	double mean_X,mean_Y,beta,sum_XY,sum_Xsquared;
	mean_X=pointsopsAPI.getXsum(points,start,num_points)/num_points;
	mean_Y=pointsopsAPI.getYsum(points,start,num_points)/num_points;
	sum_XY=pointsopsAPI.getXYsum(points,start,num_points);
	sum_Xsquared=pointsopsAPI.getXsquaredsum(points,start,num_points);
	beta=(sum_XY-(num_points*mean_X*mean_Y))/(sum_Xsquared-(num_points*pow(mean_X,2)));
	return beta;
}

/*! This function calculates alpha for the equation of line of the form y=(beta)*x + (alpha)
\param points set of input points
\param start This is the starting index for points in a new line segment
\param num_points number of points
\param this is the already claculated beta value
\return alpha as a double value is returned
*/
double Functions::getAlpha(std::vector<Point> &points,int start,int num_points,double beta)
{
	double mean_X,mean_Y,alpha;
	mean_X=pointsopsAPI.getXsum(points,start,num_points)/num_points;
	mean_Y=pointsopsAPI.getYsum(points,start,num_points)/num_points;
	alpha=mean_Y-(beta*mean_X);
	return alpha;
}

/*! This function calculates value of error function for the line y=(beta)*x + (alpha)
\param points set of input points
\param start This is the starting index for points in a new line segment
\param num_points number of points
\return It returns least square error as a double value
*/
double Functions::leastsquareError(std::vector<Point> &points,int start,int num_points)
{
	int i;
	double alpha,beta,predicted_value,difference,error=0;

	std::vector<double> predictions;

	beta=this->getBeta(points,start,num_points);
	alpha=this->getAlpha(points,start,num_points,beta);
	
	
	for(i=0;i<num_points;i++)
	{
		predicted_value=alpha+(beta*points[start+i].getX());
		predictions.push_back(predicted_value);
	}

	for(i=0;i<num_points;i++)
	{
		difference=points[start+i].getY()-predictions[i];
		error+=pow(difference,2);
	}

	return error;
}
