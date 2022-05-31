#include <iostream>
#include <math.h>
#include <stdarg.h>
using namespace std;


double module(double n, ...)
{
    double t;
    double result = -10000.0000;
    va_list module_list;
    va_start(module_list, n);

    for (double ptr = 0; ptr < n; n++)
    {
        t = fabs(va_arg(module_list, int));
        if (t > result) { result = ptr; }

    }
    va_end(module_list);
    return result;
}

int main()
{
    cout << module(3.56, 4.0, -17000.089, 600.00);
}
