#include <iostream>
using namespace std;
int main(){
    int n,tmp;
    cin>>n;
    int f[n];
    for (int  i = 0; i < n; i++){
        cin>>f[i];
    }
    int k,a,b;
    cin>>k;
    for (int j = 0; j < k; j++){
        cin>>a>>b;
        for (int i = a-1; i < b; i++){
            cout<<f[i]<<" ";
        }
        cout<<"\n";
    }
}