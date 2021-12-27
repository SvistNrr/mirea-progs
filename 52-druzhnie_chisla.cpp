#include <iostream>
#include <set>
using namespace std;
int main(){
    int k;
    cin>>k;
    string q,w;
    for (int _ = 0; _ < k; _++){
        set <int> a;
        set <int> b;
        cin>>q>>w;
        for (char c : q) {
            a.insert(int(c));
        }
        for (char c : w) {
            b.insert(int(c));
        }
        if (a==b){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }
}