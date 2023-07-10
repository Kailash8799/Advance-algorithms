#include <iostream>
#include<bits/stdc++.h>
#include <cstdlib>
#include <time.h>
#include <iostream>
using namespace std;

int partition(int A[],int p, int r,int &count){
    int pivot = A[r];
    int i = p-1;
    for(int j = p; j <= r-1; j++){
        count++;
        if(A[j] <= pivot){
            i++;
            swap(A[i],A[j]);
        }
    }
    swap(A[i+1],A[r]);
    return i+1;
}

int randomized_partition(int A[],int p, int r,int &count){
    srand(time(NULL));
    int random = p + rand() % (r-p);
    swap(A[random],A[r]);
    return partition(A,p,r,count);
}

void quick_sort(int A[],int p, int r,int &count){
    if(p < r){
        int q = randomized_partition(A,p,r,count);
        quick_sort(A,p,q-1,count);
        quick_sort(A,q+1,r,count);
    }
}

int main() {
    int arr[] = {1,3,4,1,45,6,63};  //3    5     11-13     //15
    int arr_sort[] = {1,2,3,4,5,6,7}; //3   3    11-15     //21
    int arr_rev[] = {7,6,5,4,3,2,1}; //4    5    11-14     //21
    int count = 0;
    int n = sizeof(arr) / sizeof(arr[0]);
    quick_sort(arr,0,n-1,count);
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl << count<< endl;
    return 0;
}



