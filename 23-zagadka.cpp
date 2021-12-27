#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int a,b,s,p;
    cin>>s>>p;
    b=int((s+sqrt(s*s-4*p))/2);
    a=s-b;
    cout<<a<<" "<<b;
}