# 41443109
#### homework 1
## 解題說明
本作業包含兩問題：  
1.Problem 1:實現Ackermann's function的遞迴與非遞迴版本。  
2.Problem 2:使用一遞迴函式，印出大小為n的集合的所有子集合。

### Problem 1:
## 解題策略
1.Recursive: 依照數學定義進行判斷與呼叫  
> when m=0, return n+1  
> when n=0, return  $A(m-1,1)$    
> when m>0 and n>0, return $A(m-1,A(m,n-1))$   
> 
2.non-Recursive:使用陣列模擬堆疊，將m值推入陣列內 透過迴圈呼叫取代遞迴呼叫。  
## 程式實作
```cpp
//Problem 1:Ackermann's function
//Recursive version
#include<iostream>
using namespace std;

int A(int m,int n){
    if(m==0){
        return n+1;
    }
    else if(n==0){
        return A(m-1,1);
    }
    else{
        return A(m-1,A(m,n-1));
    }
}
int main(){
    int m,n;
    while(cin>>m>>n){
    cout<<A(m,n)<<endl;
    }
}
```  
```cpp
 //Problem 1:Arkermann's function
//non-Recursive version
#include<iostream>
using namespace std;

//使用陣列模擬stack
int A(int m,int n){
    int arr[10000];
    int top=0;//透過變數top控制目前層數 
    arr[top]=m;
    while(top>=0){
        int mm=arr[top]; //將目前的m放到最後面
        top--; 
        if(mm==0){ 
            n+=1;
        }
        else if(n==0){
            top++;
            arr[top]=mm-1; //n=0時 A(m-1,1),將m-1放到arr最後面
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
``` 
## 效能分析
1.時間複雜度:$\Theta(A(m,n))$  
2.空間複雜度:
>遞迴版本:$\Theta(A(m,n))$,取決於系統call stack深度  
>非遞迴版本:$O(N)$,$N$為暫存陣列大小



### Problem 2:
## 解題策略
1.二元數:每個元素都有選與不選兩種決定  
2.使用索引從0遞增至n  
3.對於每個元素進行不選的遞迴呼叫，再將索引值計入暫存陣列後遞迴呼叫。  

## 程式實作
```cpp
//Problem 2:Powerset
#include<iostream>
using namespace std;

//n:總數
//i:目前尋找數
//a:集合列印暫存
//size:暫存區大小
void set(int n,int i,int a[],int size){
    //n=i,本次挑選完畢 列印
    if(n==i){ 
        cout<<'{';
        for(int j=0;j<size;j++){
            cout<<(char)('a'+a[j]);
        }

        cout<<'}'<<endl;
        return;
    }
    
    //不挑選目前元素
    set(n,i+1,a,size);
    //挑選目前元素
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

```  
## 效能分析
1.時間複雜度: $O(2^n)$ ,大小n的集合共有$2^n$個子集合  
2.空間複雜度:$O(n)$,遞迴呼叫最大深度與暫存陣列最大空間為$n$


## 測試與驗證
|測試問題 |輸入參數|預期輸出|實際輸出|  
|:---:|:---:|:---:|:---:|
|Recursive|m=1 n=2|4|4|
|Recursive|m=2 n=2|7|7|
|non-Recursive|m=1 n=2|4|4|
|non-Recursive|m=2 n=2|7|7|
|Problem2|n=2|() (b) (a) (a,b)|() (b) (a) (a,b)|
|Problem2|n=3|() (c) (b) (b,c) (a) (a,c) (a,b) (a,b,c)|() (c) (b) (b,c) (a) (a,c) (a,b) (a,b,c)|  
### 編譯與執行指令
#### Problem1_Recursive
```shell
$ g++ -std=c++17 -o main src/problem1_Recursive/main.cpp
$ ./main
1 2
4
```
#### Problem1_non_Recursive
```shell
$ g++ -std=c++17 -o main src/problem1_non_Recursive/main.cpp
$ ./main
2 2
7
```
#### Problem2
```shell
$ g++ -std=c++17 -o main src/problem2/main.cpp
$ ./main
3
() (c) (b) (b,c) (a) (a,c) (a,b) (a,b,c)
```

## 申論及開發報告
### Problem 1:遞迴與非遞迴的優缺
1.遞迴的優勢與侷限    
遞迴直接還原Ackermann函式的數學定義，簡潔直觀。但遞迴次數成長極快，容易造成Stack Overflow  
2.非遞迴寫法改善  
使用自訂陣列儲存$ m $的數據，減少Stack Overflow的機會，可改善為使用vector stack利用push_back和pop_back避免自訂陣列大於資料數造成的記憶體浪費。
### Problem2:遞迴決策與二進制解法
1.使用二元樹進行搜尋:本題核心思維為二元樹的搜尋，每一元素有挑選與不挑選兩種選擇，完整搜尋即可找出所有子集合。  
2.改善程式使用二進制:子集合數量為$2^n$可剛好使用2進制代表，若為1則將元素列印，為0則不做任何動作。 
