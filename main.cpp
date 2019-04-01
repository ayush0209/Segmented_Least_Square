#include<stdint.h>
#include<vector>
#include"Point.h"
#include"PointsOps.h"
#include"Functions.h"
using namespace std;

Functions functionsAPI;

void SegementedLeastSquares(std::vector<Point> points)
{
	int i,j,size;
	int num_points=points.size();
	double error[num_points][num_points];

	for(i=0;i<num_points;i++)
	{
		for(j=i;j<num_points;j++)
		{
			size=j-i+1;
			error[i][j]=functionsAPI.leastsquareError(points,i,size);
		}
	}
}

int main(int argc,char** argv)
{
	std::vector<Point> points;
	//read the points
	SegementedLeastSquares(points);
}
