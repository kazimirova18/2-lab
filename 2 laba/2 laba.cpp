#include<iostream>
#include<ctime>

using namespace std;

void heapify(int Arr[], const int SIZE, int i) {
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < SIZE && Arr[l] < Arr[smallest]) {
        smallest = l;
    }
    if (r < SIZE && Arr[r] < Arr[smallest]) {
        smallest = r;
    }
    if (smallest != i) {
        swap(Arr[i], Arr[smallest]);
        heapify(Arr, SIZE, smallest);
    }
}



void Heapsort(int Arr[], const int SIZE) {
    for (int i = SIZE / 2 - 1; i >= 0; i--) {
        heapify(Arr, SIZE, i);

    }
    for (int i = SIZE - 1; i >= 1; i--) {
        swap(Arr[0], Arr[i]);
        heapify(Arr, i, 0);
    }
}


int main() {
    srand(time(0));
    const int r = 4, c = 8;
    int Arr[r][c];
    int maxMod;
    int indMaxCol;
    int* array = new int[8];

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            Arr[i][j] = -20 + rand() % 30;
            cout << Arr[i][j] << "\t";
        }
        cout << endl;
    }
    maxMod = Arr[0][0];

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (fabs(maxMod) < fabs(Arr[i][j])) {
                maxMod = Arr[i][j];
                indMaxCol = j;
            }
        }
    }
    cout << endl;
    for (int i = 0; i < r; i++) {
        array[i] = Arr[i][indMaxCol];
        cout << array[i] << " ";

    }

    Heapsort(array, r);

    cout << endl << endl;
    for (int i = 0; i < r; i++) {
        cout << array[i] << " ";

    }

    delete[] array;
    system("pause");
    return 0;
}
