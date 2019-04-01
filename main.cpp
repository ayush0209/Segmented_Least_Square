#include<stdint.h>
#include<vector.h>
#include"Point.h"
#include"PointOps.h"
#include"Functions.h"
using namespace std;

Functions functionsAPI;

void SegementedLeastSquares(std::vector<Point> points)
{
	int i,j,size;
	num_points=points.size();
	double error[num_points][num_points];

	for(i=0;i<num_points;i++)
	{
		for(j=i;j<num_points;j++)
		{
			size=j-i+1;
			error[i][j]=functionsAPI.leastsquareError(points.begin()+i,size);
		}
	}
}

int main(int argc,char** argv)
{
	std::vector<Point> points;
	//read the points
	SegementedLeastSquares(points);
}
