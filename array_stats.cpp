#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;



// int main() {
//     int val1, val2, val3, val4, valnum_int;

//     // cout << "Enter value 1: ";
//     // cin >> val1;
//     // cout << "Enter value 2: ";
//     // cin >> val2;
//     // cout << "Enter value 3: ";
//     // cin >> val3;
//     // cout << "Enter value 4: ";
//     // cin >> val4;
//     // cout << "Enter value num_int: ";
//     // cin >> valnum_int;
//     cout << "Enter number of values: " << endl;
//     int num_int;
//     cin >> num_int;
//     int input[num_int];
//     int max, min, sumSquaredDiffs, standard;
//     int sum;
//     int mean;

//     for (int i = 0; i < num_int; i++) {
//         cout << "Enter value: ";
//         cin >> *(input+i);
//         sum += *(input+i);
//         if (i == 0) {
//             max = *(input+0);
//             min = *(input+0);
//         }
//         else {
//             if (*(input+i) > max) max = *(input+i);
//             if (*(input+i) < min) min = *(input+i);
//             }
//         }
//         // if (*(input+i) > *(input+(i+1))) {
//         //     if (*(input+i) > max) {
//         //     max = *(input+i);

//         // if (*(input+i) < *(input+(i+1))) {
//         //     if (*(input+i) < min) {
//         //     min = *(input+i);
//         //     }
//         // }
//     mean = sum/num_int;
//     for (int i = 0; i < num_int; i++) {
//         sumSquaredDiffs += pow(*(input + i) - mean, 2);
//     standard = sqrt(sumSquaredDiffs/num_int); 

//         }   
//     cout << "Minimum: " << min << "\nMaximum: " << max << "\nAverage: " << mean << "\nStandard Deviation: " << standard << endl;
// }


#include <iostream>
#include <string>
using namespace std;

int main() {
    int int_num;
    float median;
    int sum = 0, max = 0;
    float mean = 0;
    string mode;
    bool check;
    bool meanPresent = false, medianPresent = false, modePresent = false;

    cout << "Enter the num of integers: " << endl;
    cin >> int_num;

    int input[int_num];
    for (int i = 0; i < int_num; i++) {
        cout << "Enter Value: ";
        cin >> *(input+i);
        sum += *(input+i);
    }

    for (int i = 0; i < int_num; i++) {
        for (int r = 1; r < (int_num - i); r++) {
            if (*(input+r) > *(input+(r-1))) {
                int temp = *(input + r);
                *(input + r) = *(input + r - 1);
                *(input + r - 1) = temp;
            }
        }
    }

    mean = (float)sum/int_num; 

    if (int_num % 2 == 0) {
        median = (*(input+(int_num/2)) + *(input+((int_num/2) - 1))) / 2.0;
    }
    else {
        median = *(input + (int_num/2));
    }

    int another[int_num] = {};
    for (int i = 0; i < int_num; i++) {
        for (int r = 0; r < int_num; r++) {
            if (*(input+r) == *(input+i)) {
                (*(another+i))++;
            }
        }
    }

    check = true;
    for (int l = 1; l < int_num; l++) {
        if (another[l] != another[0]) check = false;
    }

    if (check == true) {
        mode = "No mode";
    }
    else {
        max = *(another+0);
        for (int k = 1; k < int_num; k++) {
            if (*(another+k) > max) max = *(another+k);
        }
        for (int k = int_num-1; k >= 0; k--) {
            if (*(another+k) == max) {
                mode = to_string(*(input+k));
                break;
            }
        }
    }

    for (int i = 0; i < int_num; i++) {
        if (*(input+i) == mean) meanPresent = true;
        if (*(input+i) == median) medianPresent = true;
    }
    if (mode != "No mode") modePresent = true;

    cout << "The mode is: " << mode << (modePresent ? " (present)" : " (not present)") 
         << "\nThe median is: " << median << (medianPresent ? " (present)" : " (not present)") 
         << "\nThe mean is: " << mean << (meanPresent ? " (present)" : " (not present)") << endl;
}
