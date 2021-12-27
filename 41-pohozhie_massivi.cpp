#include <iostream>
#include <set>
using namespace std;
int main(){
    set <int> a;
    set <int> b;
    int n,k,tmp;
    cin>>n>>k;
    for (int i = 0; i < n; i++){
        cin>>tmp;
        a.insert(tmp);
    }
    for (int i = 0; i < k; i++){
        cin>>tmp;
        b.insert(tmp);
    }
    if (a==b){
        cout<<"1";
    }
    else cout<<"0";
}