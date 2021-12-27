#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    vector <int64_t> a;
    int64_t n,l,tmp;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>l>>n;
    for (int i = 0; i < n; i++){
        cin>>tmp;
        a.push_back(tmp);
    }
    sort(a.begin(),a.end());
    int64_t i = 0, j, ans = 0;
    while (i<n){
        j=i+1;
        while (j<=n&&((a[j]-a[i])<=2*l)){
            j++;
        }
        ans++;
        i=j;
    }
    cout<<ans;
}