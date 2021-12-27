#include <iostream>
using namespace std;
int main(){
    int l,w,h;
    cin>>l>>w>>h;
    int p=2*l*h+2*w*h;
    cout<<p/16+bool(p%16);
}