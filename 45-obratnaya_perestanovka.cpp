#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n],tmp;
    for (int i=1;i<n+1;++i){
        cin>>tmp;
        arr[tmp-1]=i;
    }
    for (int i = 0; i < n; ++i){
        cout<<arr[i]<<" ";
    }
}