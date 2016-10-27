#include<iostream>
#include<math.h>
#include<vector>

using namespace std;

int count_digits(int num)
{
	int ctr=0,i;
	while(num>0)
	{
		++ctr;
		num/=10;
	}
	return ctr;
}

int main()
{
	int a,b,i,j,ctr,num,n;
	vector<int> digits;
	cout<<"enter a number which you want to check : ";
	cin>>num;
	n=num;
	ctr=count_digits(n);
	for(i=0;i<ctr;++i)
	{
		digits.push_back(n%10);
		n/=10;
	}
	for(i=0;i<ctr;++i)
		n+=pow(digits[i],ctr);
	if(n==num)
	{
		cout<<"\n\n\tArmstrong number\n";
		return 0;
	}	
	cout<<"\n\n\tNot an Armstrong!\n";
	return 0;
}
