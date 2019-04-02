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
	double error[num_points][num_points],Opt[num_points+1];	

	for(i=0;i<num_points;i++)
	{
		for(j=i;j<num_points;j++)
		{
			size=j-i+1;
			if(size>1)
			{	
				error[i][j]=functionsAPI.leastsquareError(points,i,size);
			}
			else
			{
				error[i][j]=0;
			}
		}
	}

	Opt[0]=0;
	double C=3;
	int index[num_points+1];
	for(j=1;j<=num_points;j++)
	{
		Opt[j]=error[0][j-1]+C+Opt[0];
		index[j]=1;
		for(i=1;i<=j;i++)
		{
			if(error[i-1][j-1]+C+Opt[i-1]<Opt[j])
			{
				Opt[j]=error[i-1][j-1]+C+Opt[i-1];
				index[j]=i;
			}
		}
		// cout << Opt[j] << "\n";
		// cout << index[j] << "\n";
	}
	
}

int main(int argc,char** argv)
{
	std::vector<Point> points;
	//read the points
	// points.push_back(Point(1,2));
	// points.push_back(Point(2,4));
	// points.push_back(Point(3,6));
	// points.push_back(Point(9,38));
	// points.push_back(Point(10,42));
	// points.push_back(Point(11,46));
	SegementedLeastSquares(points);
}
