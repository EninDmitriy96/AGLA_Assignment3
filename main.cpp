// Plotting v(t) and k(t)
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
    FILE *pipe = _popen(R"(C:\gnuplot\bin\gnuplot -persist)", "w");
    cin >> v0 >> k0 >> a1 >> b1 >> a2 >> b2 >> t >> n;
    step = t / n;
    v0 -= a2 / b2;
    k0 -= a1 / b1;
    for (double i = 0; i <= t; i += step) {
        cout << v(i) << ' ' << k(i) << endl;
    }
    fprintf(pipe, "plot '-' using 1:2 with lines title 'preys', "
            " '-' using 1:2 with lines title 'predators'\n");
    for (double i = 0; i <= t; i += step)
        fprintf(pipe, "%f %f\n", (double) i, v(i));
    fprintf(pipe, "e\n");
    fprintf(pipe, "plot [0 : 100] [150 : 250] '+' with lines\n");
    for (double i = 0; i <= t; i += step)
        fprintf(pipe, "%f %f\n", (double) i, k(i));
    fprintf(pipe, "e\n");
    _pclose(pipe);
    cout << '\n';
    return 0;
}
