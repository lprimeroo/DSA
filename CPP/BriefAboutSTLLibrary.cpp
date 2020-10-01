#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
using namespace std;

bool comparator(int x, int y)
{
    return x > y;
}

void vectorDemo()
{
    // The concept of vectors 
  // First lets make an list using vector function
  vector<int> a = {2,5,11,-1};
  // IN  the above we described a vector 
  //At first we have to lets say sort the list. The function for that 
  sort(a.begin(), a.end());   //Now this all will be done in o(NlogN) time
  // now the sorted array will be like
  //-1, 2, 5 ,11
  for(int x : a)
  cout<<x<<" ";
  cout<<endl;
  //Now lets say we have to find the element in the list for that we can use binary_search

  bool present =  binary_search(a.begin(), a.end(), 11); // for the element which is preset in the array 
  present  = binary_search(a.begin(), a.end(), 12); // So here it will return 0 because the condition is false

  //To print we use the * pointer to point at the exact location 
  cout<< present <<endl;

// Now to insert an element in the array/list we use the below function
a.push_back(5);
a.push_back(5);
a.push_back(5);
a.push_back(15);

for(int x : a)
cout<<x<<" ";
cout<<endl;
// Now to sort again
sort(a.begin(), a.end());

for(int x : a)
cout<<x<<" ";
cout<<endl;

// Now to find the first occurence of the element we can use lower_bound. We can use a function similar to the below function

vector<int>::iterator it = lower_bound(a.begin(), a.end(), 5); // It will give the number >=
// To find a number stricktly greater than one number, we use upper_bound
vector<int>::iterator it2 = upper_bound(a.begin(), a.end(), 5); // stricktly > 

cout<<*it<<" "<<*it2<<" "<<endl; // The pointer will point the location at which the lower/upper bound is..
cout<<it2 - it<< endl; // This difference will print the occurence of the number

// Now let's say we have to print the reverser of the list for that create a comparater in the sort function

sort(a.begin(), a.end(), comparator);
// Let's take a iterator which will iterate throughout the list and reverse it 

vector<int>::iterator it3;
for(it3 = a.begin(); it3!=a.end(); it3++)
{
    cout<<*it3<<" ";
}
cout<<endl;

// Now iterating by reference will make our for loop much smaller 
for(int &x : a) // & for reference
x++;    // will increase the value of every element in the list by 1
for(int x : a)
cout<<x<<" ";
cout<<endl;
}

void setDemo()
{
    /* Sets  = So sets are the basically enhanced form of the vectors they are much more efficiet than 
    vectors.
    IN vectors we have the time complexity for say sorting and function like upper/lower bound 
    TIME COMPLEXITY =>  O(NlogN) 
    But in sets we do not have that as the sets are much more efficient than vector the time complexitu in 
    sets is like O(logN) which is much more better than vectors */


    //like vectors in sets we use 
    set<int> s = {4,2, 22, -1};
    // In sets we don't need to sort the list/array because it is already sorted 
    // So it makes it a lot easy and it is done only in O(logN) time which is hell of time in competitive terms
    for(int x : s)
    cout<<x<<" ";
    cout<<endl;
    // To insert an element in the list simpley use the below function
    s.insert(5);
    for(int x : s)
    cout<<x<<" ";
    cout<<endl;
    // NOte that same element would not be inserted in the list so another beauty :D

    //Now let's find whether an element is present in the list or not for that use the below function
    auto it = s.find(7);
    if(it == s.end())
    cout<<"Element is not present in the list";
    else
    {
        cout<<"Element is present in the list";
    }
    cout<<endl;
    
    // Let's not calculate the lower and upper bound using sets
    auto it2 = s.upper_bound(5);    //>
    auto it3 = s.lower_bound(7);     //>=

    cout<<*it2<<" "<< *it3<<endl;

    //if we use the upperbound that is not preesnt in the list
    auto it4  = s.upper_bound(22);
    if(it4 == s.end())
    cout<<"No upper bound is present < To dekh ke dal be >";
    else
    {
        cout<<*it4;
    }
    cout<<endl;

    //Now to erase a number form the list

    s.erase(4);
    for(int x : s)
    cout<<x<<" ";
    cout<<endl;
    // Remember that in vectors the did things like sorting etc. in NlogN time where as in sets the same thing is dont in logN time so PEACE :D
}

void maps()
{
    // So maps are used to map something to something 
    // Maps are something like set in logN time we can perform functions 
    map<int, int > a ;
    a[1] = 2;
    a[2] = 5;
    a[3] = 6;
    a[32454] =62;

    map<char, int> count;
    string str = "Pulkit sings a song";
    // In the condition of for loop i am iterating char ch through every value of str (string) So keep calm and code :D
    // We can also find a key/elemnt in the list and also delete a key by using functions like in sets
    //a.find(key), a.erase(key)  
    for(char ch : str)
    {
        count[ch]++;
    }

    cout<< count['s']<< " " << count['g'] <<endl;

}

void PowerOfSTL()
{
    // Jabardast Question
    set< pair<int, int>> s;
    s.insert({2, 3});
    s.insert({201, 400});
    s.insert({10, 20});
    s.insert({30, 200});

    //it will become sorted automatically 
    // {2,3}
    // {10, 20}
    // {30, 200}
    // {201, 400}

    int point = 1;

    auto it = s.upper_bound({point, INT_MAX});
    if(it == s.begin())
    {
        cout<<"The point is not present in any pair/interval ";
        return;
    }
    it--;
    
    pair<int, int> current = *it;
    if(current.first<=point && point<=current.second)
    {
    cout<<"The point is present in this interval : "<<current.first<<" "<<current.second<<endl;
    }
    else
    cout<<"The point is not present in any interval";

}
int main()
{
    //vectorDemo();
  //setDemo();
  //maps();
  //PowerOfSTL();
  return 0;
}
//Trying to again commit this