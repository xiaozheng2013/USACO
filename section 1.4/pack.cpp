/*
ID: fzhpand1
PROG: packrec
LANG: C++
*/
#include<iostream>
#include<math.h>
#include<algorithm>
#include<fstream>
#include<vector>
using namespace std;
static int num;

class square{
public:
	int w;
	int h;
	int area;

	square(){};

	square(int a,int b)
	{	w = a; h = b; area = a*b; }

	void specify()
	{
		if(w>h) this->rotate();
	}

	void rotate()
	{ w = w+h; h = w - h; w = w - h; }

	void display()
	{	cout<<w<<" "<<h; }

};

bool myfunction(square a, square b)
{
	return (a.area<b.area ||(a.area == b.area && a.w<b.w));
}

square& r_combine(square a, square b)
{
	square *tmp = new square(a.w+b.w, max(a.h, b.h));
	return *tmp;
}
	
square& d_combine(square a, square b)
{
	square *tmp = new square(max(a.w,b.w), a.h+b.h);
	return *tmp;
}

void swap(square& a, square& b)
{
	square s(a);
	a = b;
	b = s;
}

void result_gen(vector<square> rect,vector<square>& results)
{
	
	//case 1
	square *tmp1 = new square();
	*tmp1 = r_combine(r_combine(r_combine(rect[0],rect[1]),rect[2]),rect[3]);	
	results.push_back(*tmp1);
/*
	cout<<"results.size = "<<results.size()<<endl;
	cout<<"the new itme is :";
	results[results.size() - 1].display();
	tmp1->display();
	cout<<endl;
*/
	//case 2
	square *tmp2 = new square();
	*tmp2 = d_combine(r_combine(r_combine(rect[0],rect[1]),rect[2]),rect[3]);	
	results.push_back(*tmp2);

	//case 3
	square *tmp3 = new square();
	*tmp3 = r_combine(d_combine(r_combine(rect[0],rect[1]),rect[2]),rect[3]);	
	results.push_back(*tmp3);

	//case 4
	square *tmp4 = new square();
	*tmp4 = r_combine(r_combine(d_combine(rect[1],rect[2]),rect[0]),rect[3]);	
	results.push_back(*tmp4);

	//case 5
	square *tmp5 = new square();
	*tmp5 = r_combine(r_combine(d_combine(rect[0],rect[1]),rect[2]),rect[3]);	
	results.push_back(*tmp5);

	//case 6
	if(rect[0].w >= rect[1].w && rect[0].h <= rect[2].h)
	{
		int w,h;
		w = h = 0;
		w = max(rect[0].w + rect[2].w, rect[1].w + rect[3].w);
		h= max(rect[0].h + rect[1].h, rect[2].h + rect[3].h);
		square *tmp6 = new square(w,h);
		results.push_back(*tmp6);
	}

}
 
void DFS(vector<square> rect,int i,vector<square>& results)
{
	if(i==4)
	{
		result_gen(rect,results); // generate results in all these 6 situations	
	}
	else
	{
		DFS(rect,i+1,results);
		rect[i].rotate();
		DFS(rect,i+1,results);
	}
		
		
}

void perm(vector<square> rect, int i, int n, vector<square>& results)
{
	if(i==n) 
		DFS(rect,0,results);
	//for(int j=0;j<n;j++) DFS(rect,0);
	//{num++; rect[j].display(); cout<<endl; }
	else{
		for(int j=i;j<n;j++) // n is the length of rect
		{
			swap(rect[i],rect[j]);
			perm(rect,i+1,n,results);
			swap(rect[i],rect[j]);
		}
	}
}

int main()
{
	ifstream d1("packrec.in");
	ofstream d2("packrec.out");

	vector<square> rect;
	for(int i=0;i<4;i++)
	{	
		int s1,s2;
		d1>>s1>>s2;
		square *tmp = new square(s1,s2);
		rect.push_back(*tmp);
	}

	vector<square> results;
	perm(rect,0,4,results);

	for(int i=0;i<results.size();i++)
	{
		results[i].specify();
	}	

	sort(results.begin(),results.end(),myfunction);
	int area = results[0].area;
	//cout<<area<<endl;
	d2<<area<<endl;

	for(int i=0;i<results.size(),results[i].area == area;i++)
	{
		if(i == 0)
		{
			//results[i].display();
			//cout<<endl;
			d2<<results[i].w<<" "<<results[i].h<<endl;
		}
		else if(results[i].w > results[i-1].w)
		{
			//results[i].display();
			//cout<<endl;
			d2<<results[i].w<<" "<<results[i].h<<endl;
		}
	}
/*
*/
	return 0;
}	
