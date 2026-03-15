#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;

void merge(int a[],int l,int m,int r) {
    int n1=m-l+1;
    int n2=r-m;
    int L[n1],R[n2];
    for(int i=0;i<n1;i++) {
        L[i]=a[l+i];
    }
    for(int i=0;i<n2;i++) {
        R[i]=a[m+1+i];
    }

    int i=0,j=0,k=l;

    while(i<n1 && j<n2) {
        if(L[i]<=R[j]) {
            a[k++]=L[i++];
        }
        else {
            a[k++]=R[j++];
        }
    }
    while(i<n1) {
        a[k++]=L[i++];
    }
    while(j<n2) {
        a[k++]=R[j++];
    }
}
void mergesort(int a[],int l,int r) {
    if(l<r) {
        int m=l+(r-l)/2;
        mergesort(a,l,m);
        mergesort(a,m+1,r);
        merge(a,l,m,r);
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
    mergesort(a,0,n-1);
    auto kraj = high_resolution_clock::now();
    auto vreme = duration_cast<milliseconds>(kraj - pocetok).count();

    cout<<"Vreme:"<<vreme<<"ms"<<endl;
    return 0;
}