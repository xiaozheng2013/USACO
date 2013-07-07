/*
ID: fzhpand1
PROG: milk3
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;
int A,B,C;

class state{
public:
	int a;
	int b;
	int c;
	state(int i,int j, int k)
	{
		a = i; b = j; c = k;
	}

	state(const state& s)
	{
		a = s.a;
		b = s.b;
		c = s.c;
	}
		
	friend ostream& operator<<(ostream& os, const state& t)
	{
		os<<t.c;
	}
	void display()
	{
		cout<<"a = "<<a<<" b = "<<b<<" c ="<<c<<endl;
	}

	int operator==(const state& bb)
	{
		return (a == bb.a)&&(b == bb.b)&&(c == bb.c);
	}
	void op(int i);
	
	
};


class state_board{
public:
	vector< state > state_q;
	int size;
	state_board()
	{ size = 0; }
	int contain( state a)
	{
		if(size == 0) return 0;
		else{
		for(int i=0;i<size;i++)
		{
			if(state_q[i] == a) return 1;
		}
		}
		return 0;
	}
			
	void push(state a)
	{
		state *tmp = new state(a);
		state_q.push_back(*tmp);
		size++;
	}
	state& operator[](int i)
	{
		if(i>=0 & i<size) 
		return state_q[i];
	
	}

/*
	void pop()
	{
		if(size != 0)
		{
			int i = state_q.size()-1;
			state_q.remove(state_q.begin() + i);
			size--;
		}
	}
*/
};

bool myfun(state aa, state bb)
{
	return aa.c<bb.c;
} 

void state::op(int i)
{
	int c1,c2,c3,tmp;
	c1 = A -a;
	c2 = B -b;
	c3 = C -c;
	switch(i)
	{
		case 1:
			tmp = min(a,c2);
			a = a -tmp;
			b = b +tmp;		
			break;
		case 2:
			tmp = min(c1,b);
			a = a + tmp;
			b = b - tmp;
			break;
		case 3:
			tmp = min(a,c3);
			a = a -tmp;
			c = c +tmp;		
			break;
		case 4:
			tmp = min(c1,c);
			a = a +tmp;
			c = c -tmp;		
			break;
		case 5:
			tmp = min(b,c3);
			b = b -tmp;
			c = c +tmp;		
			break;
		case 6:
			tmp = min(c2,c);
			b = b +tmp;
			c = c -tmp;		
			break;

	}
	return;
}


void milk_r( state_board *board, vector< state >& result, int d)
{
	if(board->size == d) return;

	for(int i=1;i<7;i++)
	{
		state *temp = new state( (*board)[d] );	
		temp->op(i);
		if(board->contain(*temp) == 0)
		{
			board->push(*temp);
			if(temp->a == 0) 
			result.push_back(*temp);
		}
		else delete temp;
	}
	milk_r( board, result, d+1);
						
}
 
int main()
{
	ifstream d1("milk3.in");
	ofstream d2("milk3.out");

	d1>>A>>B>>C;
	
	state *init;
	init = new state(0,0,C);

	state_board *all_state = new state_board();
	all_state->push(*init);

	vector< state > result;
	result.push_back(*init);

	milk_r( all_state, result,0 );
	for(int i=0;i<all_state->size;i++)
	{
		(*all_state)[i].display();
	}

	sort(result.begin(),result.end(),myfun);
	int j = 0;
	for(int i=1;i<result.size()-j;i++)
	{
		if(result[i].c == result[i-1].c)
		{
			result.erase(result.begin() + i);
			i--;
			j++;
		}
	}		
		
		
	for(int i=0;i<result.size();i++)
	{
		d2<<result[i];
		if(i!= result.size() - 1) d2<<" ";
	}
	d2<<endl;
	d1.close();
	d2.close();
}

