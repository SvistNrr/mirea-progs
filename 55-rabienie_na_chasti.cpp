#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n, m, s = 0;
    cin >> n >> m;
    vector<int> a;
    if(n < m){
        for(int i = 0; i < m - n; ++i)
            cout << 0 << " ";
        for(int i = 0; i < n; ++i)
            cout << 1 << " ";
        return 0;
    }
    for(int i = 0; i < m; ++i){
        a.push_back(n / m);
    }
 
    for(int i = 0; i < a.size(); ++i){
        for(int j = 0; j < a.size(); ++j)
            s+=a[j];
        if(s==n)
            break;
        else
            s = 0;
        a[i]+=1;
    }
    sort(a.begin(), a.begin() + a.size());
    for(int i = 0; i < a.size(); ++i)
        cout << a[i] << " ";
    return 0;
}