#include<iostream>
#include<vector>
using namespace std;

Merge(vector<int> &v, int l, int m, int r){
    vector<int> v1(&v.at(l),&v.at(m)+1), v2(&v.at(m+1), &v.at(r)+1);
    vector<int>::iterator i1 = v1.begin(), i2 = v2.begin();
    int i=l;
    while(i1!=v1.end() || i2!=v2.end()){
        //cout<<"Run for *i1="<<*i1<<" *i2="<<*i2<<endl;
        if(i1!=v1.end()){
            if(i2!=v2.end()){
                if(*i1<*i2){
                    v[i] = *i1;
                    i1++;
                }else{
                    v[i] = *i2;
                    i2++;
                }
            }else{
                v[i] = *i1;
                i1++;
            }
        }else{
            v[i] = *i2;
            i2++;
        }
        i++;
    }
}

Merge_Sort(vector<int> &v, int l, int r){
    if(l<r){
        int middle = (l+r)/2;
        Merge_Sort(v, l, middle);
        Merge_Sort(v, middle+1, r);
        Merge(v, l, middle, r);
    }
}

Partition(vector<int> &v, int l, int r){
    int pivot = v[r];
    int i = l-1;
    for(int j=l; j<r; j++){
        if(v[j]<pivot){
            i++;
            v[i] = v[i] + v[j] - (v[j]=v[i]);
        }
    }
    i++;
    v[i] = v[i] + v[r] - (v[r]=v[i]);
    return i;
}

Quick_Sort(vector<int> &v, int l, int r){
    if(l<r){
        int p = Partition(v, l, r);
        Quick_Sort(v, l, p-1);
        Quick_Sort(v, p+1, r);
    }
}

Insertion_Sort(vector<int> &v){
    for(vector<int>::iterator i=v.begin(); i!=v.end(); i++){
        for(vector<int>::iterator j=i+1; j!=v.end(); j++){
            if(*j<*i){
                *i = *i + *j - (*j=*i);
            }
        }
    }
}

Heapify(vector<int> &v, int n, int i){
    int largest = i, l = 2*i+1, r = 2*i+2;
    if(l<n && v[l]>v[largest]){
        largest = l;
    }
    if(r<n && v[r]>v[largest]){
        largest = r;
    }
    if(largest!=i){
        v[i] = v[i] + v[largest] - (v[largest]=v[i]);
        Heapify(v, n, largest);
    }
}

Create_Heap(vector<int> &v){
    for(int i = v.size()/2 - 1; i>=0; i--)
        Heapify(v, v.size(), i);
}

Heap_Sort(vector<int> &v){
    Create_Heap(v);
    for(int i=v.size()-1; i>=0; i--){
        v[i] = v[i] + v[0] - (v[0]=v[i]);
        Heapify(v, i, 0);
    }
}

int main(){
    int t;
    vector<int> v;
    cout<<"Enter values(-1 to end): ";
    while(cin>>t && t!=-1)
        v.push_back(t);
    for(int i=0; i<v.size(); i++)
        cout<<v[i]<<" ";
    cout<<endl;

    char c;
    cout<<"Choose sorting method: ";
    cin>>c;

    switch(c){
    case 'm':
        Merge_Sort(v, 0, v.size()-1);
        break;
    case 'q':
        Quick_Sort(v, 0, v.size()-1);
        break;
    case 'i':
        Insertion_Sort(v);
        break;
    case 'h':
        Heap_Sort(v);
        break;
    default:
        cout<<"Invalid Choice!";
    }

    vector<int>::iterator i = v.begin();
    for( ; i!=v.end(); ++i)
        cout<<*i<<" ";
}
