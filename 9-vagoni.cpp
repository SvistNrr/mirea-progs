#include <iostream>
using namespace std;
int main(){
    int k,arr[100],tmp,p=0;
    cin>>k;
    for (int i = 0; i < k; i++){
        cin>>arr[i];
    }
    for (int i = 1; i < k; i++){
        if(arr[i-1]>arr[i]||arr[i]-arr[i-1]!=1){
            p++;
        }
    }
    cout<<p;
}