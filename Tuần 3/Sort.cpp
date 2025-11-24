#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void bubbleSort(vector<int>& a) {
    int n = a.size();
    for (int i = 0; i < n - 1; ++i)
        for (int j = 0; j < n - i - 1; ++j)
            if (a[j] > a[j+1]) swap(a[j], a[j+1]);
}

void selectionSort(vector<int>& a) {
    int n = a.size();
    for (int i = 0; i < n - 1; ++i) {
        int mini = i;
        for (int j = i+1; j < n; ++j)
            if (a[j] < a[mini]) mini = j;
        swap(a[i], a[mini]);
    }
}

void insertionSort(vector<int>& a) {
    int n = a.size();
    for (int i = 1; i < n; ++i) {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j+1] = a[j];
            --j;
        }
        a[j+1] = key;
    }
}

void printMedian(const vector<int>& a, const string& name) {
    int n = a.size();
    if (n == 0) {
        cout << name << ": empty\n";
        return;
    }
    if (n % 2 == 1) {
        cout << name << " median = " << a[n/2] << '\n';
    } else {
        double avg = (a[n/2 - 1] + a[n/2]) / 2.0;
        cout << name << " medians = " << a[n/2 - 1] << " and " << a[n/2]
             << " (avg = " << avg << ")\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cout << "Nhap so phan tu: ";
    if (!(cin >> n)) {
        cerr << "Nhap n khong hop le\n";
        return 1;
    }
    if (n <= 0) {
        cerr << "n phai la so duong\n";
        return 1;
    }

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        if (!(cin >> arr[i])) {
            cerr << "Input phan tu thu " << i << " khong hop le\n";
            return 1;
        }
    }

    // Nếu n lớn, tránh O(n^2) sorts
    const int O2_LIMIT = 5000;
    if (n <= O2_LIMIT) {
        auto b1 = arr; bubbleSort(b1); printMedian(b1, "Bubble Sort");
        auto b2 = arr; selectionSort(b2); printMedian(b2, "Selection Sort");
        auto b3 = arr; insertionSort(b3); printMedian(b3, "Insertion Sort");
    } else {
        // dùng std::sort nhanh hơn cho n lớn
        auto b = arr;
        sort(b.begin(), b.end());
        printMedian(b, "std::sort (used for large n)");
    }

    return 0;
}
