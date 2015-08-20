//saru95
#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
#include <complex>
#include <math.h>
#include <utility>
#include <cmath>
#include <set>
#include <vector>
#include <map>
#include <cctype>
#include <queue>
#include <stdio.h>
#include <cstdio>
#include <stack>
#include <algorithm>
#include <list>
#include <ctime>
#include <numeric>
#include <memory.h>
 
#define all(a) (a).begin(),(a).end()
#define gcd __gcd
#define bitcount __builtin_popcount
 
using namespace std;
 
typedef std::vector<int> vi;
typedef std::vector<std::string> vs;
typedef std::pair<int, int> pii;
typedef std::set<int> si;
typedef std::map<std::string, int> msi;

vi PrefixFunction(string pattern){
	int PatternLength = pattern.length() ;
	vi PrefixTable(PatternLength) ;
	PrefixTable[0] = 0 ;
	int i = 0 ;
	for(int j=1; j<PatternLength; j++){
		while(i>0&&pattern[i]!=pattern[j]){
			i = PrefixTable[i] ;
		}
		if(pattern[i]==pattern[j]){
			i = i + 1 ;
		}
		PrefixTable[j] = i ;
	}
	return PrefixTable ;
}



void KMP(string text, string pattern){
	vi PrefixTable = PrefixFunction(pattern) ;
	int PatternLength = pattern.length() ;
	int TextLength = text.length() ;
	int j = 0 ;
	for(int i=0; i<TextLength; i++) {
		while(j>0&&pattern[j]!=text[i]){
			j = PrefixTable[j] ;
		}
		if(pattern[j]==text[i]){
			j = j + 1;
		}
		if(j==PatternLength){
			cout<<"Found at position (index 0): "<< (i-PatternLength)+1 << endl ;
			j = PrefixTable[j] ;
		}
	}
}



int main(int argc, char const *argv[]){
	string text, pattern ;
	cin >> text >> pattern ;
	KMP(text, pattern) ;
	return 0;
}