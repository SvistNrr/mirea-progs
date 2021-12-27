#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int  n, b, s1 = 0, s2 = 0, max = 0, i = 0;;
    cin >> n;
    vector<int> a;
    for(int i = 0; i < n; ++i){
        cin >> b;
        a.push_back(b);
    }
    while(a.size()){
        if(a[0] < a[a.size() - 1]){
                max = a[a.size() - 1];
                a.pop_back();
        }
        else{
            max = a[0];
            a.erase(a.begin());
        }
        if(i % 2==0)
            s1+=max;
        else
            s2+=max;
        ++i;
    }
    cout << s1 << ":" << s2;
    return 0;
}