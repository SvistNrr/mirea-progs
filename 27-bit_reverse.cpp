#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n;
    vector <bool> bit;
    cin>>n;
    while (n>0){
        bit.push_back(n%2);
        n/=2;
    }
    int tmp=1,ans=0;
    for (int i = bit.size()-1; i >= 0; i--){
        ans+=tmp*bit[i];
        tmp*=2;
    }
    cout<<ans;
}