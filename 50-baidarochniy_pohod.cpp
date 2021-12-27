#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n,d,m, k = 0;
    cin >> n >> d;
    bool b = 1, t = 1;
    vector<int> a;
    for(int i = 0; i < n; ++i){
        cin >> m;
        a.push_back(m);
    }
    sort(a.begin(),a.end());
    while(b){
        t = true;
        for(int i = a.size() - 1; i > 0; --i)
            if(a[i] + a[0] <= d){
                a.erase(a.begin());
                --i;
                a.erase(a.begin() + i);
                ++k;
                t = false;
            }
        if(a.size() < 2 || t)
            b = false;
        }
    if(a.size())
        k+=a.size();
    cout << k;
    return 0;
}