#include<iostream>
#include<stack>
using namespace std;
int main(){
  stack<int> s;
  char choice='u';
  int temp;
  while(choice!='e'){
    cout<<"\nEnter choice(i-push, d-pop, t-top, s-size, e-exit): ";
    cin>>choice;
    switch(choice){
      case 'i':
        cout<<"Enter value to be inserted: ";
        cin>>temp;
        s.push(temp);
        break;
      case 'd':
        if(s.size()){
          cout<<s.top()<<endl;
          s.pop();
        }else{
          cout<<"Stack Underflow!\n";
        }
        break;
      case 't':
        if(s.size()){
          cout<<s.top()<<endl;
        }else{
          cout<<"Stack is empty!\n";
        }
        break;
      case 's':
        cout<<s.size()<<endl;
        break;
      case 'e':
        cout<<"Bye!\n";
        break;
      default:
        cout<<"Invalid Choice!\n";
        break;
    }
  }
  return 0;
}
