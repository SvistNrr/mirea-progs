#include <iostream>
#include <cmath>
#include <string>
using namespace std;
double sqr(int x)
{
return (x*x*1.0);
}
int main()
{
    int n,x,a[100010];
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        if (a[i] == 1)
            x=i;
        }
    for (int i = x; i <= n; i++)
    cout << a[i] <<" ";
    for (int i = 1; i < x; i++)
    cout << a[i] <<" ";
    return 0;
}