#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int k5=-0,k3=0;
    while (n%5!=0){
        n-=3;
        k3++;
    }
    k5=n/5;
    cout<<k5<<" "<<k3;
}