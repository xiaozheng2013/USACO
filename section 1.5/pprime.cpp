/*
ID: fzhpand1
PROG:pprime
LANG:C++
*/
#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<math.h>

using namespace std;

class data{
public:
	int val;
	data(int j)
	{ val =j; }
	void inc(int j)
	{
		val += j;
	}
	int isEven() {
		if( val%2 == 0) return 1;
		else return 0;
	}
	int isPalindrome();
	int isPrime();
};

int data::isPalindrome()
{
	int tmp;
	int ind;
	int i=1;
	int n_val=0;
	//jvector<int> nums;
	do{
		tmp = val%int(pow(10,i));
		ind = val/int(pow(10,i));
		if(ind >= 1)	
		{
			tmp /= int(pow(10,i-1));
			//nums.push_back(tmp);
			n_val = 10*n_val + tmp;
		}
		else
		{
			//nums.push_back(val/pow(10,i-1));
			tmp = val/int(pow(10,i-1));
			n_val = 10*n_val + tmp;
			break;
		}
		i++;
	}while(ind>=1);
		
	if(val == n_val)	return 1;
	else return 0;
		 
}

int data::isPrime()
{
	int s = sqrt(val);
	if(3>s)	return 1;
	for(int i=3;i<=s;i++)
	{
		if(val%i == 0)
			return 0;
	}
	return 1;
}


int main()
{
	ifstream d1("pprime.in");
	ofstream d2("pprime.out");
	int a,b;
	d1>>a>>b;

	
	vector<int> results;
	data *Data = new data(a);	
	if(Data->isEven() == 1) Data->inc(1); 

	while(Data->val < b)
	{
		if(Data->isPalindrome() == 1)
		{
			if(Data->isPrime() == 1)
				results.push_back(Data->val);
		}	
		Data->inc(2);
	}


	for(int i=0;i<results.size();i++)
		d2<<results[i]<<endl;
	d1.close();
	d2.close();
	return 0;
}

