#include <iostream>
using namespace std;
int main(){
    int n,q=0;
    cin>>n;
    int tmp=n;
    while (tmp>=1){
        if (tmp%2==1){
            q++;
        }
        tmp/=2;
    }
    cout<<n+q;
}