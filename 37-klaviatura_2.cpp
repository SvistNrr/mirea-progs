#include <iostream>
using namespace std;
int main(){
    int n,c[100],k;
    bool mas[100];
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>c[i];
        mas[i]=false;
    }
    cin>>k;
    int tmp;
    for (int i=0;i<k;i++){
        cin>>tmp;
        c[tmp-1]-=1;
        if (c[tmp-1]<0){
            mas[tmp-1]=true;
        }
    }
    for (int i=0;i<n;i++){
        if (mas[i]){
            cout<<"yes\n";
        }
        else{
            cout<<"no\n";
        }
    }
}