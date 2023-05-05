// Plotting k(v)
#include <iostream>
#include <vector>
#include "fstream"

using namespace std;

#define GNUPLOT_NAME "C:\\gnuplot\\bin\\gnuplot.exe -persist"
FILE *pipe = _popen(GNUPLOT_NAME, "w");

int main() {
    int n;
    double x, y;
    ifstream in("C:\\Users\\mitya\\CLionProjects\\AGLAassig2Ex\\points.txt");
    in >> n;
    fprintf(pipe, "set xrange [%d:%d]\n", 150, 225);
    fprintf(pipe, "set yrange [%d:%d]\n", 150, 225);
    fprintf(pipe, "%s\n", "plot '-' using 1:2 title 'k(v)' with lines");
    for (int i = 0; i < n + 1; i++) {
        in >> x >> y;
        fprintf(pipe, "%f %f\n", x, y);
    }
    fprintf(pipe, "%s\n", "e");
    fflush(pipe);
    _pclose(pipe);
    in.close();
    return 0;
}
