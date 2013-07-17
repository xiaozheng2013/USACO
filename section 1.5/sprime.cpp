/*
ID: fzhpand1
PROG: sprime
LANG:C++
*/
#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<math.h>


using namespace std;

int isPrime(int val)
{
	int s = sqrt(val);
//	if(3>s)	return 1;
	for(int i=2;i<=s;i++)
	{
		if(val%i == 0)
			return 0;
	}
	return 1;
}

void sprime(int t, int N, int s, vector<int>& r)
{
		
	for(int i=1;i<10;i++)
	{
		int tmp = 10*t + i;
		if(isPrime(tmp) == 1)
		{
			if(N == s) r.push_back(tmp);
			else sprime(tmp,N,s+1,r);
		}
	}
	return;	
}

int main()
{
	ifstream d1("sprime.in");
	ofstream d2("sprime.out");

	int N;
	d1>>N;
	if(N == 1)
	{
		d2<<2<<endl<<3<<endl<<5<<endl<<7<<endl;
		d2.close();
		return 0;
	}
		
	vector<int> results;
	sprime(2,N,2,results);
	sprime(3,N,2,results);
	sprime(5,N,2,results);
	sprime(7,N,2,results);
	
	for(int i=0;i<results.size();i++)
		d2<<results[i]<<endl;
	d1.close();
	d2.close();
	return 0;
}

