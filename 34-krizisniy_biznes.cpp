#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n,s,tmp;
    cin>>n>>s;
    vector <int> a;
    for (int i = 0; i < n; i++){
        cin>>tmp;
        a.push_back(tmp);
    }
    int ans = 0;
    sort(a.begin(),a.end());
    for (int i = 0; i < n; i++){
        if (a[i]<=s){
            s-=a[i];
            ans++;
        }
        else{
            break;
        }
    }
    cout<<ans;
}