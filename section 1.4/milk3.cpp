/*
ID: fzhpand1
PROG: milk3
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<vector>
#include<queue>

using namespace std;
class state_board{
public:
	vector< state > state_list;
	int size;
	state_board()
	{ size = 0; }
	int contain( state a)
	{
		if(size == 0) return 0;
		else{
		for(int i=0;i<size;i++)
		{
			if(state_list[i] == a) return 1;
		}
		return 0;
	}
			
	void add(state a)
	{
		state *tmp = new state(a);
		state_list.push_back(*tmp);
		size++;
	}
		
};

class state{
public:
	int A;
	int B;
	int C;
	int a;
	int b;
	int c;
	state(int i,int j, int k)
	{
		A = i; B = j; C = k;
		a = 0; b = 0; c = k;
	}
		
	friend ostream& operator<<(ostream& os, const state& t)
	{
		os<<t.a<<" "<<t.b<<" "<<t.c<<" "<<endl;
	}

	int operator==(const state& b)
	{
		return (a == b.a)&&(b == b.b)&&(c == b.c)
	}
	
	
};


int main()
{
	ifstream d1("milk3.in");
	ofstream d2("milk3.out");

	int a,b,c;
	d1>>a>>b>>c;
	
	state *init;
	init = new state(a,b,c);

	queue< state > state_q;
	state_q.push(*init);
	
	stateboard all_state;
	


	d1.close();
	d2.close();
}

