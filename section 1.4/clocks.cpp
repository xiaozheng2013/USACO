/*
ID: fzhpand1
PROG: clocks
LANG: C++
*/
#include<iostream>
#include<algorithm>
#include<fstream>
#include<vector>

using namespace std;

class strategy{
public:
	vector<int> s;
	int length;
	int size;
	
	
	strategy():s(9,0)
	{}

	strategy(vector<int> a):s(a)
	{
		size = 0;
		length = 0;
		for(int i=0;i<9;i++)
		{
			if(a[i] != 0) 
			{
				length += 1;
				size += a[i];
			}
		}
	}

	void display()
	{
		for(int i=0;i<s.size();i++)
		cout<<s[i]<<" ";
		cout<<endl;
	}
};
	

class state{
public:

	vector<int> s;

	state():s(9)
	{
	}

	state(vector<int>& a);
	
	void move(vector<int> cls)
	{
		for(int i=0;i<cls.size();i++)
		{
			s[cls[i]] = (s[cls[i]] + 1)%4;
		}
	}

	int qualify()
	{
		for(int i=0;i<9;i++)
		if(s[i] != 0)
		return 0;

		return 1;
	}
	
	void display()
	{
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				cout<<s[i*3 + j]<<" ";
			}
			cout<<endl;
		}
	}

	int operator==(const state b)
	{
		for(int i=0;i<9;i++)
		{
			if(s[i] != b.s[i])
			return 0;
		}
		return 1;
	}
	
	void apply_strategy( vector<vector<int> > &move_table, strategy a)
	{
		for(int i=0;i< 9; i++)
		{
			for(int j = 0;j<a.s[i];j++)
			this->move(move_table[i]);
			this->display();
			cout<<endl;
		}
	}	

};

state::state(vector<int>& a):s(9)
{
	for(int i=0;i<9;i++)
	{
		switch (a[i])
		{
			case 3:
				s[i] = 1; break;
			case 6:
				s[i] = 2; break;
			case 9:
				s[i] = 3; break;
			case 12:
				s[i] = 0; break;
			default:
				cout<<"wrong time table"<<endl;
		}	
	}
}

void set_table(vector<vector<int> >& m)
{
	vector<int> t1(4);
	t1[0] = 'A' - 'A'; t1[1] = 'B' - 'A'; t1[2] = 'D' - 'A'; t1[3] = 'E' - 'A';
	m.push_back(t1);

	vector<int> t2(3);
	t2[0] = 'A' - 'A'; t2[1] = 'B' - 'A'; t2[2] = 'C' - 'A';
	m.push_back(t2);

	vector<int> t3(4);
	t3[0] = 'B' - 'A'; t3[1] = 'C' - 'A'; t3[2] = 'E' - 'A'; t3[3] = 'F' - 'A';
	m.push_back(t3);

	vector<int> t4(3);
	t4[0] = 'A' - 'A'; t4[1] = 'D' - 'A'; t4[2] = 'G' - 'A'; 
	m.push_back(t4);

	vector<int> t5(5);
	t5[0] = 'B' - 'A'; t5[1] = 'D' - 'A'; t5[2] = 'E' - 'A'; t5[3] = 'F' - 'A';
	t5[4] = 'H' - 'A';
	m.push_back(t5);

	vector<int> t6(3);
	t6[0] = 'C' - 'A'; t6[1] = 'F' - 'A'; t6[2] = 'I' - 'A'; 
	m.push_back(t6);

	vector<int> t7(4);
	t7[0] = 'D' - 'A'; t7[1] = 'E' - 'A'; t7[2] = 'G' - 'A'; t7[3] = 'H' - 'A';
	m.push_back(t7);
					
	vector<int> t8(3);
	t8[0] = 'G' - 'A'; t8[1] = 'H' - 'A'; t8[2] = 'I' - 'A'; 
	m.push_back(t8);

	vector<int> t9(4);
	t9[0] = 'E' - 'A'; t9[1] = 'F' - 'A'; t9[2] = 'H' - 'A'; t9[3] = 'I' - 'A';
	m.push_back(t9);

}

void find_result(state Init,const vector< vector<int> > & move_table, 
						int i,vector<int> current_move,vector<strategy>& result)	
{
	if(Init.qualify() == 1)
	{
		strategy *tmp = new strategy(current_move);
		result.push_back(*tmp);
	}
	else if(i<9)
	{
		current_move[i] = 0;		
		find_result(Init,move_table,i+1,current_move, result);

		current_move[i] = 1;
		Init.move(move_table[i]);
		find_result(Init,move_table,i+1,current_move, result);
		
		current_move[i] = 2;
		Init.move(move_table[i]);
		find_result(Init,move_table,i+1,current_move, result);
		
		current_move[i] = 3;
		Init.move(move_table[i]);
		find_result(Init,move_table,i+1,current_move, result);
	

	}
	else return;
		
}

bool my_func(strategy a, strategy b)
{
	return (a.length < b.length ||(a.length == b.length && a.size < b.size ));
}


int main()
{
	ifstream d1("clocks.in");
	ofstream d2("clocks.out");
	
	vector<int> init(9);
	int tmp;
	for(int i=0;i<9;i++)
	{
		d1>>tmp;
		init[i] = tmp;
		
	}
	state *Init = new state(init);
//	Init->display();

	vector<vector<int> > move_table;
	set_table(move_table);

	
	vector<strategy> result;
	vector<int> current_move(9,0);
	find_result(*Init,move_table,0,current_move,result);	
	
	for(int i=0;i<result.size();i++)
	{
		result[i].display();
	}
	if(result.size() == 0) cout<<"no result"<<endl;
	else 
	sort(result.begin(),result.end(),my_func);

	strategy *tmp1 = &(result[0]);
	

	int space_num = 0;
	for(int i=0;i<9;i++)
	{
		for(int k=0;k<tmp1->s[i];k++)
		{
			d2<<i+1;
			if(space_num<tmp1->size - 1) d2<<" ";
			space_num++;
		}
	}
	d2<<endl;	

	vector<int> test(9,0);
	for(int i=0;i<8;i++) test[i] = 2;
	test[3] = test[6] = 3;
	test[5] = test[8] = 1;

	strategy *test_tmp = new strategy(test);

	cout<<"Init is :"<<endl;
	Init->display();
//	Init->apply_strategy(move_table,result[0]);
	Init->apply_strategy(move_table,*test_tmp);
	cout<<"after the strategy, Init becomes :"<<endl;
//	Init->display();
	d1.close();
	d2.close();
	
	return 0;

}	

