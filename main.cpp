#include <cstdlib>
#include <iostream>
using namespace std;
double g(double x){
    x = x - 0.245 * (x * x - 5 * sin(x));
    return x;
}
double g2(double x){
    x = x + 1.9 * (sin(x) - x + 0.15);
    return x;
}
double g3(double x){
    x = x + 0.2 * (x  - sqrt(9 + x) + x * x - 4); //
    return x;
}
double find(double eps, double(*fn)(double),double x0, double x1) {
    int count = 0;
    while (fabs(x0 - x1) > eps) {
        count++;
        x1 = x0;
        x0 = fn(x0);
        cout << "x = " << x0 << endl;
    }
    cout << "count = " << count << endl;
    return x0;
}
int main() {
    double e;
    cin >> e;
    cout << "first function:\n";
    cout << "x for g1 = " << find(e,g,2,0) << endl;
    cout << "second function:\n";
    cout << "x for g2 = " << find(e,g2,0.5,0) << endl;
    cout << "third function:\n";
    cout << "x for g3 = " << find(e,g3,-4,0) << endl;
    return 0;
}