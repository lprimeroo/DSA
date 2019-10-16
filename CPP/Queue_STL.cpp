#include<iostream>
#include<queue>
using namespace std;
int main(){
  queue<int> q;
  char choice='u';
  int temp;
  while(choice!='e'){
    cout<<"\nEnter choice(i-enqueue, d-dequeue, t-front, s-size, e-exit): ";
    cin>>choice;
    switch(choice){
      case 'i':
        cout<<"Enter value to be inserted: ";
        cin>>temp;
        q.push(temp);
        break;
      case 'd':
        if(q.size()){
          cout<<q.front()<<endl;
          q.pop();
        }else{
          cout<<"Queue is empty!\n";
        }
        break;
      case 't':
        if(q.size()){
          cout<<q.front()<<endl;
        }else{
          cout<<"Queue is empty!\n";
        }
        break;
      case 's':
        cout<<q.size()<<endl;
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
