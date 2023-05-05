// Submission on Yandex Constest
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double v0, k0, a1, b1, a2, b2, t, n, step;

double v(double t) {
    return v0 * cos(sqrt(a1 * a2) * t) - (k0 * sqrt(a2) * b1 * sin(sqrt(a1 * a2) * t)) / (b2 * sqrt(a1)) + a2 / b2;
}

double k(double t) {
    return (v0 * sqrt(a1) * b2 * sin(sqrt(a1 * a2) * t)) / (b1 * sqrt(a2)) + k0 * cos(sqrt(a1 * a2) * t) + a1 / b1;
}

int main() {

    cin >> v0 >> k0 >> a1 >> b1 >> a2 >> b2 >> t >> n;
    step = t / n;
    v0 -= a2 / b2;
    k0 -= a1 / b1;
    cout << "t:\n";
    for (double i = 0; i <= t; i += step) {
        cout << fixed << setprecision(2) << i << ' ';
    }
    cout << "\nv:\n";
    for (double i = 0; i <= t; i += step) {
        cout << v(i) << ' ';
    }
    cout << '\n' << "k:\n";
    for (double i = 0; i <= t; i += step) {
        cout << k(i) << ' ';
    }
    cout << '\n';
    return 0;
}
