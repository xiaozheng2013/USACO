/*
ID: fzhpand1
PROG: gift1
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<map>
#include<string>
#include<vector>
using namespace std;

class person{
public:
	string name;
	int money_original;
	int money_give;
	int money_receive;
	int money_balence;
	int friends_num;
	vector<person*> friends_list;

	void set_money_original(int a)
	{
	   money_original = a;
	   money_balence = money_original - money_give + money_receive;

	}
	person(string na) 
	{
	   name = na;
	   money_original = money_give = money_receive = money_balence = 0;
	}
	void add_to_friend(person* a) {friends_list.push_back(a);}	
	void give_money();
	void receive_money(int num)
	{
	   money_receive += num;
	   money_balence = money_original - money_give + money_receive;
	}
	void display()
	{
	   cout<<name<<" "<<money_balence - money_original<<endl;
	}
	friend ostream& operator<<(ostream& os, const person* a)
	{
	   int tmp = a->money_balence - a->money_original;
	   os<<a->name<<" "<<tmp<<endl;

	}
};

void person::give_money()
{
	if(friends_num != 0)
	{
	   int money_amount = money_original/friends_num;
	   money_give = money_amount*friends_num;
	   money_balence = money_original - money_give + money_receive;

	   for(int i=0;i<friends_num;i++)
	   {

		friends_list[i]->receive_money(money_amount);

	   }	   
	}
}

int main()
{
	ifstream d1("gift1.in");
	int num;
	d1>>num;	
	string name_;
	vector<person*> group;
	map<string,person*> M;
	for(int i=0;i<num;i++)
	{
	   d1>>name_;
	   person *temp = new person(name_);
	   group.push_back(temp);
	   M[name_] = temp; 

	}

	int n1,n2;	
	for(int i=0;i<num;i++)
	{
	   d1>>name_;
	   person *temp = M[name_];
	   d1>>n1;d1>>n2;
	   temp->set_money_original(n1);
	   //temp->money_balence = n1;
	   temp->friends_num = n2;	    
	   for(int j=0;j<n2;j++)
	   {
		d1>>name_;
		temp->add_to_friend(M[name_]);
	   }
	   temp->give_money();

	}

	ofstream d2("gift1.out");
	for(int i=0;i<group.size();i++)
	{
	   d2<<group[i];
	   group[i]->display();

	}

}
