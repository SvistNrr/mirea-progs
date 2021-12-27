#include <iostream>
using namespace std;
int main(){
    int n,tmp;
    cin>>n;
    int a[n+2];
    cin>>tmp;
    a[1]=tmp;
    a[n+1]=tmp;
    for (int i = 2; i < n; i++){
        cin>>a[i];
    }
    cin>>tmp;
    a[0]=tmp;
    a[n]=tmp;
    int max=0;
    for (int i = 1; i < n+1; i++){
        if ((a[i-1]+a[i]+a[i+1])>max){
            max=a[i-1]+a[i]+a[i+1];
        }
    }
    cout<<max;
}