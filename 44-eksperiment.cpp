#include <bits\stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> flasks_volumes(n);
    vector<int>flasks_content(n);
    for (int i = 0; i < n; ++i) {
        cin>>flasks_volumes[i];
        flasks_content[i]=i;
    }
    int first,second;
    for (int i = 0; i < m; ++i){
        cin>>first>>second;
        --first;
        --second;
        int first_cont = flasks_content[first];
        int second_cont = flasks_content[second];
        clog << first_cont << ' ' << second_cont << '\n';
        if (first_cont<second_cont){
            for (int i = 0; i < n; ++i){
                if (flasks_content[i] == first_cont) flasks_content[i]=second_cont;
            }
        }
        else{
            flasks_content[second] = first_cont;
            for (int i = 0; i < n; ++i){
                if (flasks_content[i]==second_cont)flasks_content[i]=first_cont;
            }
        }
    }
    vector<int> ans(n,0);
    for (int c : flasks_content) clog << c << '\n';
    for (int i = 0; i < n; ++i) ans[flasks_content[i]]+=flasks_volumes[i];
    for (int i = 0; i < n; ++i) if (ans[i] !=0) cout << i+1 << ' ' << ans[i] << '\n';
}