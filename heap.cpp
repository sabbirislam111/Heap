#include<bits/stdc++.h>
using namespace std;
void swape(int*a, int*b){
    int temp = *a;
    *a=*b;
    *b = temp;
}


void heapify(int arr[], int n, int current){
    int largest = current;
    int leftchild = 2*current +1;
    int rightchild = 2*current+2;

    if(leftchild < n && arr[leftchild] > arr[largest]){
        largest = leftchild;
    }
    if(rightchild < n && arr[rightchild] > arr[largest]){
        largest = rightchild;
    }
    if(largest != current){
        swape(&arr[current], &arr[largest]);
        heapify(arr, n, largest);
    }

}

void printArr(int arr[], int n){
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}


void heapSort(int arr[], int siz){
    for(int i = siz-1; i >= 0; i--){
        swape(&arr[0], &arr[i]);
        heapify(arr, i,0);
    }
}

void heapSort2(int arr[], int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // One by one extract an element from heap
    for (int i = n - 1; i >= 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);

        // call min heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i; i < n; i++){
        cin>>arr[i];
    }
    // Heapify
    int noneLefeStart = (n/2)-1;
    //printArr(arr, n);
    for(int i = noneLefeStart; i >= 0; i--){
        heapify(arr, n, i);
    }

    printArr(arr, n);
    heapSort(arr,n);
    printArr(arr, n);

    heapSort2(arr,n);
    printArr(arr, n);



 return 0;
}

/*
9
2 10 1 5 4 8 3 6 8
*/
