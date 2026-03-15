#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;

void insertionsort(int a[], int n) {
    for (int i=1;i<n;i++) {
        int b=a[i];
        int j=i-1;
        while (j>=0 && a[j]>b) {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=b;
    }
}

int main() {
    int n=100000;
    int a[n];

    srand(time(0));

    for (int i=0;i<n;i++) {
        a[i]=rand();
    }
    auto pocetok = high_resolution_clock::now();
    insertionsort(a,n);
    auto kraj = high_resolution_clock::now();
    auto vreme = duration_cast<milliseconds>(kraj - pocetok).count();

    cout<<"Vreme:"<<vreme<<"ms"<<endl;
    return 0;
}