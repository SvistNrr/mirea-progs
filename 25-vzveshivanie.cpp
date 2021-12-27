#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int n;
    cin>>n;
    int k=0;
    while (n>1){
        n=n/3+bool(n%3);
        k++;
    }
    cout<<k;
}