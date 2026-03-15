#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;

void selectionsort(int a[], int n) {
    for (int i=0;i<n-1;i++) {
        int min=i;
        for (int j=i+1;j<n;j++){
            if (a[j]<a[min]) {
                min=j;
            }
        }
        if (min!=i) {
            swap(a[i],a[min]);
        }
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
    selectionsort(a,n);
    auto kraj = high_resolution_clock::now();
    auto vreme = duration_cast<milliseconds>(kraj - pocetok).count();

    cout<<"Vreme:"<<vreme<<"ms"<<endl;
    return 0;
}