#include <iostream>
using namespace std;
int main(){
    int n,i,j;
    cin>>n>>i>>j;
    int q=abs(j-i)-1;
    int w=n-abs(j-i)-1;
    cout<<min(q,w);
}