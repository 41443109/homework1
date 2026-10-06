#include<iostream>
using namespace std;
int A(int m,int n){
    int arr[10000];
    int top=0;
    arr[top]=m;
    while(top>=0){
        int mm=arr[top];
        top--;
        if(mm==0){
            n+=1;
        }
        else if(n==0){
            top++;
            arr[top]=mm-1;
            n=1;
        }
        else{
            top++;
            arr[top]=mm-1;
            top++;
            arr[top]=mm;
            n-=1;

        }
    }
    return n;
}

int main(){
    int m,n;
    while(cin>>m>>n){
    cout<<A(m,n)<<endl;
    }
}
