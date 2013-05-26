/*
ID: fzhpand1
PROG: ariprog
LANG: C++
*/
#include<iostream>
#include<map>
#include<fstream>
#include<algorithm>
#include<vector>

using namespace std;

class Pair{
public:
	int a;
	int b;
	Pair(int x,int y)
	{	a = x; b = y; }
};

int compare(Pair m, Pair n)
{
	return (m.b<n.b)||(m.b==n.b && m.a<n.a); 
}


int contain(map<int,int>& M, int i, int j,int N)
{
	//int val = a[i] + j;
	//int size = a.size() - 1;
	for(int k=0;k<N;k++)
	{
		if(M.count(i) == 0) return 0;
		else	
		{
			i += j; 
		}

	}
	return 1;
}

int main()
{
	ifstream d1("ariprog.in");
	ofstream d2("ariprog.out");
	int M,N;
	d1>>N>>M;

	vector<int> bis;
	map<int,int> Map;
	for(int i=0;i<=M;i++)
		for(int j=0;j<=i;j++)
		{
			int k = i*i + j*j;
			bis.push_back(k);
			if(Map.count(k) == 0) Map[k] = 1;

		}
	sort(bis.begin(),bis.end());
	int k=0;
//	cout<<"before removing, size is "<<bis.size()<<endl;
	for(int i=1;i<bis.size() - k;i++)
	{
		if(bis[i] == bis[i-1])
		{
			k++;
			bis.erase(bis.begin() + i);
			i--;
		}
	}	

//	cout<<"before removing, size is "<<bis.size()<<endl;
//	for(int i=0;i<bis.size();i++) cout<<"bis["<<i<<"] = "<<bis[i]<<endl;
	vector<Pair> result;	
	for(int i=0;i<bis.size() - 2;i++)
	{
		
		int range = (bis[bis.size() - 1] - bis[i])/(N - 1);
		//for(int j = 1;j<=range;j++)
		int j = i+1;
		int k = bis[j] - bis[i];
		while(k<=range)
		{
			if(k == 0) { j++; 
				if(j<bis.size())
				{	
					k = bis[j] - bis[i]; continue;
				}
				else break;
			}
			else{
			if(contain(Map,bis[j] + k,k,N-2) == 1)
			result.push_back(Pair(bis[i],k));
			j++;
			k = bis[j] - bis[i];
			}
				

		}
	}
	if(result.size() == 0) d2<<"NONE"<<endl;
	else{
	sort(result.begin(),result.end(),compare);

		
	for(int i=0;i<result.size();i++)
	{
		d2<<result[i].a<<" "<<result[i].b<<endl;
		
	}
	}
	d1.close();
	d2.close();
	return 0;
}

