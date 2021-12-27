#include <iostream>
using namespace std;
int main(){
    int x,y,z,w;
    cin>>x>>y>>z>>w;
    int ans=0;
    for (int i = 0; i <= w/x; i++){
        for (int j = 0; j <= (w-i*x)/y; j++){
            if ((w-(i*x+j*y))%z == 0){
                ans++;}
        }
    }
    cout<<ans;
}