#include<iostream>
using namespace std;

class Heap {
public:
    int *arr;
    int capacity;
    int size;

    Heap(int capacity) {
        this->arr = new int(capacity);
        this->capacity = capacity;
        this->size = 0;
    }

    void insert(int val) {
        //hume 1 index se insert krna chalu krna h
        size++;
        int index = size;
        arr[index] = val;

        //ab check krna h ki jo insertion hua h wo sahi jagah pr hua h ki nhi
        while(index > 1) {
            int parentIndex = index/2;
            if(arr[index] > arr[parentIndex]) {
                // agar bada h toh swap krna pdega kyuki child ki value bada h
                swap(arr[index], arr[parentIndex]);
                index = parentIndex;
            }
            else{
                //mtlb sahi position pr h 
                //heapify nhi krna h, loop se bahar aao
                break;
            }
        }
    }

    void printing() {
        for(int i=1; i<=size; i++) {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

    int deleteFromHeap() {
        //deletion humesha top se hoga , root node delete hoga
        int answer = arr[1];
        //delete krunga toh uske badle sabse last element ko uske position pr rakh dunga kyuki last element safest h
        //phir last element ko last se remove kr dunga
        arr[1] = arr[size];
        size--; //last element removal
        int index = 1;
        while(index < size) {
            int leftIndex = 2*index;
            int rightIndex = 2*index + 1;
            int largestKaIndex = index;

            if(leftIndex <= size && arr[largestKaIndex] < arr[leftIndex]) {
                largestKaIndex = leftIndex;
            }
            if(rightIndex <= size && arr[largestKaIndex] < arr[rightIndex]) {
                largestKaIndex = rightIndex;
            }

            if(index == largestKaIndex) {
                //no change
                break;
            }
            else {
                //taaki apne sahi position pr aa jaye
                swap(arr[index], arr[largestKaIndex]);
            }
            //ab wo niche aa gya thoda but still uski position check krte krte sahi position pr daalna hi hoga
            index = largestKaIndex; //ye krne se wo pohoch jayega apni correct position mai loop krte krte
        }
        return answer;
    }
};

void heapify(int arr[], int n, int index) {
    int leftIndex = 2*index;
    int rightIndex = 2*index+1;
    int largestKaIndex = index;

    if(leftIndex <= n && arr[largestKaIndex] < arr[leftIndex]) {
        largestKaIndex = leftIndex;
    }
    if(rightIndex <= n && arr[largestKaIndex] < arr[rightIndex]) {
        largestKaIndex = rightIndex;
    }

    if(index != largestKaIndex) {
        swap(arr[index], arr[largestKaIndex]);
        //ab recursion samhal lega
        index = largestKaIndex;
        heapify(arr,n,index);
    }
}

void buildHeap(int arr[], int n) {
    for(int i=n/2; i>0; i--) {
        heapify(arr, n, i);
    }
}

void heapSort(int arr[], int n) {
    while(n != 0) {
        // arr[n] se kr rha hu arr[n-1] se nhi kyuki 1 based indexing hoti h heap mai toh last index 'n' hai
        swap(arr[1], arr[n]); 
        n--;
        heapify(arr, n, 1);
    }
}


int main() {

    // Heap h(20);
    // h.insert(5);
    // h.insert(10);
    // h.insert(15);
    // h.insert(6);
    // h.insert(25);
    // h.insert(50);
    // h.printing();

    // int ans = h.deleteFromHeap();
    // cout<<"Deleting: "<<ans<<endl;
    // h.printing();

    int arr[] = {-1,5,10,15,20,25,12};
    int n = 6;

    buildHeap(arr, n);
    cout<<"Printing Heap"<<endl;
    for(int i=1; i<=n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    heapSort(arr, n);

    cout<<"Printing Heap"<<endl;
    for(int i=1; i<=n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}