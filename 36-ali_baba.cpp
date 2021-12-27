#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n,m,tmp;
    cin>>n>>m;
    vector <int> c;
    for (int i = 0; i < n; i++){
        cin>>tmp;
        c.push_back(tmp);
    }
    sort(c.begin(),c.end());
    int ans = 0;
    for (int i = n-1; i >= 0; i--){
        if (m>0){
            if (c[i]>0)
                ans+=c[i];
                m--;
        }
        else{
            break;
        }
    }
    cout<<ans;
}