#include <iostream>
using namespace std;
int main(){
    int n;
    int ans = 1;
    cin>>n;
    ans+=n;
    for (int i = 2; i < n/2+1; i++){
        if (n%i==0)ans+=i;
    }
    cout<<ans;
}