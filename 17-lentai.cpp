#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a,b,mn=32,mx=-1;
    for (int i = 0; i < n; i++){
        cin>>a>>b;
        mx=max(mx,a);
        mn=min(mn,b);
    }
    if (mx>mn){
        cout<<"NO";
    }
    else{
        cout<<"YES";
    }
}