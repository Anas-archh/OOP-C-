#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;


// int main() {


//     int int_num;
//     float median;
//     int sum = 0, max = 0;
//     float mean = 0;
//     string mode;
//     bool check;

//     cout << "Enter the num of integers: " << endl;
//     cin >> int_num;

//     int input[int_num];
//     for (int i = 0; i < int_num; i++) {
//         cout << "Enter Value: ";
//         cin >> *(input+i);
//         sum += *(input+i);
//         //* *(input+i) = input[i]
//         //* input+i = &input[i] 
//     }
//     for (int i = 0; i < int_num; i++) {
//         for (int r = 1; r < (int_num - i); r++) {
//             if (*(input+r) > *(input+(r-1))) {
//                 //! */ *(input+r), *(input+(r-1)) = *(input+(r-1)), *(input+r); // Only works in python.. doesnt work here
//                 int temp = *(input + r);
//                 *(input + r) = *(input + r - 1);
//                 *(input + r - 1) = temp;
//             }
//         }
//     }
//     mean = sum/int_num;
//     if (int_num % 2 == 0) {
//         median = (*(input+(int_num/2)) + *(input+((int_num/2) - 1))) / 2;
//     }
//     else {
//         median = *(input + (int_num/2));
//     }

//     int another[int_num] = {};

//     for (int i = 0; i < int_num; i++) {
//         for (int r = 0; r < int_num; r++) {
//             if (*(input+r) == *(input+i)) {
//                 (*(another+i))++;
//             }
//         }
//     }
//     check = true;
//     for (int l = 1; l < int_num; l++) {
//         if (another[l] != another[0]) check = false;
//     }
//     if (check == true) {
//         mode = "No mode";
//     }
//     else {
//         max = *(another+0);   // set once before the loop
//         for (int k = 1; k < int_num; k++) {
//         if (*(another+k) > max) max = *(another+k);
// }
//         for (int k = int_num-1; k >= 0; k--) {
//             if (*(another+k) == max) {
//                 mode = to_string(*(input+k));
//                 break;
//             }
//         }

//     }

//     cout << "The mode is: " << mode << "\nThe median is: " << median << "\nThe mean is: " << mean << endl;
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
