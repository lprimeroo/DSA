#include<iostream>
#include<stack>
#include<string>
using namespace std;
bool Arepair(char open,char close)
{
    if(open=='(' && close==')')
        return true;
    else if(open=='{' && close=='}')
        return true;
    else if(open=='['&& close==']')
        return true;
        return false;

}
bool Areparntbal(string exp)
{
    stack<char> s;
    for(int i=0;i<exp.length();i++)
    {
        if(exp[i]=='(' || exp[i]=='{' || exp[i]=='[')
            {
                s.push(exp[i]);
            }
            else if(exp[i]==')' || exp[i]=='}' || exp[i]==']')
            {
                if(s.empty()||!Arepair(s.top(),exp[i]))
                    return false;
                else
                    s.pop();
            }
    }
    return s.empty() ? true:false;
}
int main()
{
    string exp;
    cout<<"Enter the expression "<<endl;
    cin>>exp;
    if(Areparntbal(exp))
        cout<<"BALANCED"<<endl;
    else
        cout<<"NOT BALANCED"<<endl;

}

