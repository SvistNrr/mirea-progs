#include <iostream>
using namespace std;
int main(){
    int k,tmp;
    bool a=true;
    cin>>k;
    for (int i=0;i<k;i++){
        cin>>tmp;
        if (tmp<=437 && a==true){
            cout<<"Crash "<<i+1;
            a=false;
        }
    }
    if (a==true){
        cout<<"No crash";
    }
}