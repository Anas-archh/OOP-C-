#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;



int main() {
    int val1, val2, val3, val4, valnum_int;

    // cout << "Enter value 1: ";
    // cin >> val1;
    // cout << "Enter value 2: ";
    // cin >> val2;
    // cout << "Enter value 3: ";
    // cin >> val3;
    // cout << "Enter value 4: ";
    // cin >> val4;
    // cout << "Enter value num_int: ";
    // cin >> valnum_int;
    cout << "Enter number of values: " << endl;
    int num_int;
    cin >> num_int;
    int input[num_int];
    int max, min, sumSquaredDiffs, standard;
    int sum;
    int mean;

    for (int i = 0; i < num_int; i++) {
        cout << "Enter value: ";
        cin >> *(input+i);
        sum += *(input+i);
        if (i == 0) {
            max = *(input+0);
            min = *(input+0);
        }
        else {
            if (*(input+i) > max) max = *(input+i);
            if (*(input+i) < min) min = *(input+i);
            }
        }
        // if (*(input+i) > *(input+(i+1))) {
        //     if (*(input+i) > max) {
        //     max = *(input+i);

        // if (*(input+i) < *(input+(i+1))) {
        //     if (*(input+i) < min) {
        //     min = *(input+i);
        //     }
        // }
    mean = sum/num_int;
    for (int i = 0; i < num_int; i++) {
        sumSquaredDiffs += pow(*(input + i) - mean, 2);
    standard = sqrt(sumSquaredDiffs/num_int); 

        }   
    cout << "Minimum: " << min << "\nMaximum: " << max << "\nAverage: " << mean << "\nStandard Deviation: " << standard << endl;
}
