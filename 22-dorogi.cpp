#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int d[n][n];
    float ans=0;
    float tmp;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin>>tmp;
            if (i!=j){
               ans+=tmp/2; 
            }
            else{
                ans+=tmp;
            }
        }
    }
    cout<<int(ans);
}