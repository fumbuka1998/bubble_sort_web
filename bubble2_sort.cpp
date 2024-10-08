// #include < iostream >
//   using namespace std;

// void bubbleSort(int a[]) {
//   for (int i = 0; i < 5; i++) {
//     for (int j = 0; j < (5 - i - 1); j++) {
//       if (a[j] > a[j + 1]) {
//         int temp = a[j];
//         a[j] = a[j + 1];
//         a[j + 1] = temp;
//       }
//     }
//   }
// }

// int main() {
//   int myarray[5];
//   int size;
//   cout << "Enter 5 integers in any order: " << endl;
//   for (int i = 0; i < 5; i++) {
//     cin >> myarray[i];
//   }
//   cout << "Before Sorting" << endl;
//   for (int i = 0; i < 5; i++) {
//     cout << myarray[i] << " ";
//   }

//   bubbleSort(myarray); // sorting

//   cout << endl << "After Sorting" << endl;
//   for (int i = 0; i < 5; i++) {
//     cout << myarray[i] << " ";
//   }

//   return 0;
// }

#include <iostream>
#include <emscripten/bind.h>

using namespace std;

void bubbleSort(int* a, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < (size - i - 1); j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

// This function will be exported
extern "C" {
    void sortNumbers(int* arr, int size) {
        bubbleSort(arr, size);
    }
}

// Binding the function to JavaScript
EMSCRIPTEN_BINDINGS(my_module) {
    emscripten::function("sortNumbers", &sortNumbers, emscripten::allow_raw_pointer<int*>());
}
