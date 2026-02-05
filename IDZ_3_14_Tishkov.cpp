#include <iostream>
using namespace std;

int main() {
    double V0, V1, V2, V3;
    double S1, S2, S3;

    cin >> V0 >> S1 >> V1 >> S2 >> V2 >> S3 >> V3;

    V0 *= 1000;
    V1 *= 1000;
    V2 *= 1000;
    V3 *= 1000;

    double S = S1 + S2 + S3;

    double t1 = S1 / V1;
    double t2 = S2 / V2;

    double T, X;

    if ((V0 + V1) * t1 >= S) {
        T = S / (V0 + V1);
        X = V0 * T;
    }
    else if (V0 * t1 + (V0 + V2) * t2 >= S) {
        double S_rem = S - (V0 * t1 + S1);
        T = t1 + S_rem / (V0 + V2);
        X = V0 * T;
    }
    else {
        double S_rem = S - (V0 * (t1 + t2) + S1 + S2);
        T = t1 + t2 + S_rem / (V0 + V3);
        X = V0 * T;
    }

    cout << "Время встречи: " << T << " ч\n";
    cout << "Расстояние от пункта A: " << X << " м\n";

    return 0;
}