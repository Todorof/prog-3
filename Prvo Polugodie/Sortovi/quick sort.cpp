#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;

int par(int a[],int l,int h) {
    int m=a[h];
    int i=l-1;
    for (int j=l; j<=h-1; j++) {
        if (a[j]<m) {
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[h]);
    return i+1;
}

void quicksort(int a[], int l, int h) {
    if (l < h) {
        int m=par(a,l,h);
        quicksort(a,l,m-1);
        quicksort(a,m+1,h);
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
    quicksort(a,0,n-1);
    auto kraj = high_resolution_clock::now();
    auto vreme = duration_cast<milliseconds>(kraj - pocetok).count();

    cout<<"Vreme:"<<vreme<<"ms"<<endl;
    return 0;
}