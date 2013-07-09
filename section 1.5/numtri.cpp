/*
ID: fzhpand1
PROG:numtri
LANG:C++
*/
#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<math.h>

using namespace std;

int main()
{
	ifstream d1("numtri.in");
	ofstream d2("numtri.out");

	int N;
	d1>>N;
	vector< vector<int> > data(N);
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<=i;j++)
		{
			int d;
			d1>>d;
			data[i].push_back(d);
		}
	}

	for(int i = N-2;i>=0; i--)
	{
		for( int j=0;j<=i;j++)
		{
			data[i][j] += max(data[i+1][j], data[i+1][j+1]);
		}
	}

	d2<<data[0][0]<<endl;
	d1.close();
	d2.close();
	return 0;
}

