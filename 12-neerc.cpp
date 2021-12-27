#include <iostream>
using namespace std;
int main(){
    int k,n,tmp;
    cin>>k;
    int arr[k];
    for (int i = 0; i < k; i++){
        cin>>arr[i];
    }
    cin>>n;
    int s=0;
    for (int i = 0; i < k; i++){
        if (arr[i]>n){
            s+=n;
        }
        else{
            s+=arr[i];
        }
    }
    cout<<s;
}