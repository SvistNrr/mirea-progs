#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    vector <int64_t> a;
    int64_t n,tmp;
    ios::sync_with_stdio(false);
    cin>>n;
    for (int i = 0; i < n; i++){
        cin>>tmp;
        a.push_back(tmp);
    }
    sort(a.begin(),a.end());
    int64_t q = a[0]*a[1]*a[n-1];
    int64_t w = a[n-1]*a[n-2]*a[n-3];
    if (q>w) cout<<q;
    else cout<<w;
}