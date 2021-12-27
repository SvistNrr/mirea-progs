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
    int summ = 0;
    for (int i=1; i < n+1; i++){
        if (a[i]>0){
            summ += a[i];
        }
    }
    int mx = -101, mn = 101;
    int imax, imin;
    for (int i=1; i < n+1; i++){
        if (a[i]>mx){
            mx=a[i];
            imax=i;
        }
        if (a[i]<mn){
            mn=a[i];
            imin=i;
        }
    }
    int pr=1;
    for (int i = min(imin,imax)+1; i < max(imin,imax); i++){
        pr*=a[i];
    }
    cout<<summ<<" "<<pr;
}