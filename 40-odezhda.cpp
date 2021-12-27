#include <iostream>
using namespace std;
int main(){
    int arr[100],n,tmp;
    cin>>n;
    for (int i=0;i<100;i++){
        arr[i]=0;
    }
    for (int i=0;i<n;i++){
        cin>>tmp;
        arr[tmp-1]+=1;
    }
    int max=0;
    int color;
    for (int i=0;i<100;i++){
        if (arr[i]==max){
            color=0;
            }
        if (arr[i]>max){
            max=arr[i];
            color=i+1;}
        
    }
    cout<<color;
}