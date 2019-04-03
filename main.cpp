#include<stdio.h>
#include<iostream>
#include <fstream>
#include <sstream>
#include<vector>
#include"Point.h"
#include"PointsOps.h"
#include"Functions.h"
using namespace std;

Functions functionsAPI;

void SegementedLeastSquares(std::vector<Point> points,double C)
{
	int i,j,size,tempIndex;
	int num_points=points.size();
	double alpha,beta,error[num_points][num_points],Opt[num_points+1];
	Opt[0]=0;
	int startIndex[num_points+1];	

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

	for(j=1;j<=num_points;j++)
	{
		Opt[j]=error[0][j-1]+C+Opt[0];
		startIndex[j]=1;
		for(i=1;i<=j;i++)
		{
			if(error[i-1][j-1]+C+Opt[i-1]<Opt[j])
			{
				Opt[j]=error[i-1][j-1]+C+Opt[i-1];
				startIndex[j]=i;
			}
		}
	}

	std::ofstream output("./output/outputSegments.txt");
	std::ofstream output2("./output/outputLines.txt");
	tempIndex=num_points;
	while(tempIndex!=0)
	{
		output<<startIndex[tempIndex]<<" "<<tempIndex<<"\n";
		size=tempIndex-startIndex[tempIndex]+1;
		beta=functionsAPI.getBeta(points,startIndex[tempIndex]-1,size);
		alpha=functionsAPI.getAlpha(points,startIndex[tempIndex]-1,size,beta);
		output2<<alpha<<" "<<beta<<"\n";
		tempIndex=startIndex[tempIndex]-1;
	}
		
}

int main(int argc,char** argv)
{
	std::ifstream input("./input/input1.txt");
	vector<Point> points;
	string line_data;
	int Flag=0;
	int num_points;
	while(getline(input,line_data))
	{
		if(Flag==0)
		{
			Flag++;
			stringstream line_stream(line_data);
			line_stream>>num_points;
			continue;
		}
		istringstream line_stream(line_data);
		double x,y;
		line_stream>>x>>y;
		points.push_back(Point(x,y));
	}
	SegementedLeastSquares(points,3);
}
