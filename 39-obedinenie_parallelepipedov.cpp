#include <bits\stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<vector<vector<bool>>> space(100, vector(100, vector(100,false)));
    int ans = 0;
    for (int i = 0; i < n; ++i){
        int x1, x2, y1, y2, z1, z2;
        cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
        for (int x = x1; x < x2; ++x){
            for (int y = y1; y < y2; ++y){
                for (int z = z1; z < z2; ++z){
                    if(!space[x][y][z]) ++ans;
                    space[x][y][z]=true;
                }
            }
        }
    }
    cout << ans;
}