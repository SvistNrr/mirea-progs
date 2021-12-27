#include <iostream>
using namespace std;
int main(){
    int a,b;
    cin>>a>>b;
    cout<<max(a,b)/2+max(a,b)%2<<" "<<min(a,b);
}