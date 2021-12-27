#include <iostream>
using namespace std;
int main(){
    int k,s=0,p=1;
    cin>>k;
    while (s<=k){
        s+=p;
        p++;
    }
    cout<<p-2;
}