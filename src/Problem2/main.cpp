#include<iostream>
using namespace std;

void set(int n,int i,int a[],int size){
    
    if(n==i){
        cout<<'{';
        for(int j=0;j<size;j++){
            cout<<(char)('a'+a[j]);
        }

        cout<<'}'<<endl;
        return;
    }
    
    set(n,i+1,a,size);

    a[size]=i;
    set(n,i+1,a,size+1);
}

int main(){
    int n;
    while(cin>>n){
        int a[100];
        set(n,0,a,0);
    }
}

