/*
ID: fzhpand1
PROG: ariprog
LANG: C++
*/
#include<iostream>
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


int find(vector<int>& a, int i, int j, int val)
{
	if(i>j) return -1;
	else if(i == j) 
	{
		if(a[i] == val) return i;
		else return -1;
	}
	else
	{
		int k = (i+j)/2;
		if(a[k] == val) return k;
		else if(a[k] > val)
		{
			j = k-1;
			return find(a,i,j,val);
		}
		else if(a[k]<val)
		{	
			i = k+1;
			return find(a,i,j,val);
		}	

	}

}



int contain(vector<int>& a, int i, int j,int N)
{
	int val = a[i] + j;
	int size = a.size() - 1;
	for(int k=0;k<N-1;k++)
	{
		int s = find(a,i,min(size,i+j),val);
		if( s != -1)
		{	val += j;	i=s+1;	}
		else	return 0; 

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
	for(int i=0;i<=M;i++)
		for(int j=0;j<=i;j++)
		{
			int k = i*i + j*j;
			bis.push_back(k);

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
	for(int i=0;i<bis.size()-1;i++)
	{
		int range = (bis[bis.size() - 1] - bis[i])/(N - 1);
		//for(int j = 1;j<=range;j++)
		int j = i+1;
		int k = bis[j] - bis[i];
		while(k<=range)
		{
			if(contain(bis,i,k,N) == 1)
			result.push_back(Pair(bis[i],k));
			j++;
			if(j<bis.size())
			k = bis[j] - bis[i];
				

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

