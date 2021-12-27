#include <iostream>
using namespace std;
int main(){
    int n,q,w,tmp;
    cin>>n>>q>>w;
    for (int i = n; i > 1; i--){
        tmp=w-q;
        w=q;
        q=tmp;
    }
    cout<<q<<" "<<w;
}