#include <iostream>
#include <cmath>
using namespace std;
int main(){
    cin.tie(0);
    int n, bx, by, l;
    cin>>n>>bx>>by>>l;
    int x,y;
    bool fl = true;
    for (int i = 1; i < n + 1; i++){
        cin >> x >> y;
        if (sqrt(pow((x-bx),2)+pow((y-by),2))<=l){
            cout<<i;
            fl = false;
            break;
        }
    }
    if (fl) cout<<"Yes";
}