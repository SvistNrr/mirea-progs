#include <iostream>
using namespace std;
int main(){
    int a,b;
    cin>>a>>b;
    int o=a,p=b;
    while (o>0 && p>0){
        if(o > p){
            o%=p;
        }
        else{
            p%=o;
        }
    }
    int nod=o+p;
    int nok=a*b/nod;
    cout<<nok;
}