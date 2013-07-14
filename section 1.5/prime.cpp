/*
ID: fzhpand1
PROG: pprime
LANG: C++
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

void pal_gen(int i, int j, int a, int b, vector<int> s, vector<int>& r)
{
	if(j > i-1-j)  
	{
		int tmp=0;
		for( int k=0;k<i;k++)
			tmp = 10*tmp + s[k];
//		cout<<"tmp = "<<tmp<<endl;
		if( tmp>=a && tmp<=b && isPrime(tmp) == 1)
		{
			r.push_back(tmp);
			//cout<<"tmp = "<<tmp<<endl;
		}
	}

	else{
	for(int k = 0;k<10;k++)
	{
		if(k == 0 && j ==0) continue;
		s[j] = k;
		s[i - 1 - j] = k;
		vector<int> s_c = s;
		pal_gen(i,j+1,a,b,s_c,r);
		
	}
	}
}
		

void palindrom_gen(int i,int a,int b, vector<int>& r)
{
	if(i == 1)
	{
		for( int ii =0;ii<10;ii++)
		{
			if(ii>=a && ii<=b)
			{
				if(isPrime(ii) == 1)
				{
					r.push_back(ii);
					//cout<<"ii = "<<ii<<endl;
				}
			}
		}
	}

	else// here I wanna use an array to store those palindrome candidates, and use recursive algorithm to generate all of them.
	{
		vector<int> s(i);
		pal_gen(i,0,a,b,s,r);
	}
			
		

}

int main()
{
	ifstream d1("pprime.in");
	ofstream d2("pprime.out");
	int a,b;
	d1>>a>>b;

	vector<int> results;
	for(int i=1;i<9;i++)
	{
		palindrom_gen(i,a,b,results);
	}

	for(int i=0;i<results.size();i++)
		d2<<results[i]<<endl;	

	d1.close();
	d2.close();
	return 0;
}

