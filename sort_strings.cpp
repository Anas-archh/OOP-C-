#include <iostream>
#include <cstring>
using namespace std;

void sortStrings(char arr[][100], int n) {
    char temp[100];
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(*(arr+i), *(arr+j)) > 0) {   
                strcpy(temp, *(arr+i));
                strcpy(*(arr+i), *(arr+j));
                strcpy(*(arr+j), temp);
            }
        }
    }
}

int main() {
    int n;
    cout << "Enter size of the array: ";
    cin >> n;
    cin.ignore(); 

    char arr[n][100];
    for (int i = 0; i < n; i++) {
        cout << "Enter string: ";
        cin.getline(*(arr+i), 100);
    }

    sortStrings(arr, n);

    cout << "\nSorted strings: " << endl;
    for (int i = 0; i < n; i++) {
        cout << *(arr+i) << endl;
    }

    return 0;
}
