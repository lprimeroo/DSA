/*
		git user name-> DravitLochan 
		
		problem description->
		for those who are not aware about the problem, here it goes. 
		while playing chess, If your pawn reaches the last row (row in which the king of opponent is placed initially),
		then you have a chance to bring one player back(which maybe dead or not). Now find a possible solution to place 
		the n queens revived assuming that all your (n) pawns reaches the opposite end and you have total n queens .
		
		Bellow is a backtracking based implementation of the famous 
		n-queen chess board problem.
		
		Backtracking is supposed to be on such algorithm where the 
		time complexity may be high but the results obtained will be accurate
		100% (only if no error has been commited by the programmer in realising a test case).
		
		variable description->
		board is a 2-D bit array representing the chess board. 
		1 in a cell denotes presence of queen and 0 denotes the abbsence.
		There may be multiple solutions, but the below code finds any one of 
		them and displays it if possible.
		No case is possible if the number of rows(and columns obviously) are less than 4. 
*/

#include<iostream>

using namespace std;

int sol_poss(int **board,int r,int c,int n)
{
	int i,j;
	for(i=r;i>=0;--i)
		if(*(*(board+i)+c))
			return 0;
	for(i=r,j=c;i>=0&&j>=0;--i,--j)
		if(*(*(board+i)+j))
			return 0;
	for(i=0;i<n;++i)
	{
		for(j=0;j<n;++j)
		{
			if(*(*(board+i)+j)&&i+j==r+c)
			return 0;
		}
	}		
	return 1;
}

int solution(int **board,int row,int n)
{
	if(row>=n)
	return 1;
	int i,j;
	for(j=0;j<n;++j)
	if(sol_poss(board,row,j,n))
	{
		*(*(board+row)+j)=1;
		if(solution(board,row+1,n))
		return 1;
		*(*(board+row)+j)=0;
	}
	return 0;
}

void print_board(int **board,int n)
{
	int i,j;
	for(i=0;i<n;++i)
	{
		for(j=0;j<n;++j)
		{
			cout<<*(*(board+i)+j)<<" ";
		}
		cout<<"\n";
	}
}

int main()
{
	int n;
	cout<<"Enter the value of n (number of rows in the chess board) : ";
	cin>>n;
	int **board;
	board=new int *[n];
	for(int i=0;i<n;++i)
	board[i]=new int[n];
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<n;++j)
		*(*(board+i)+j)=0;
	}
	if(solution(board,0,n))
	print_board(board,n);
	else
	cout<<"no possible solution\n";
	return 0;
}
