#include<bits/stdc++.h>
using namespace std;

class Heap{
    private:
    vector<int>heap;
    int size;
    public:
    Heap(vector<int>&arr){
        int n=arr.size();
        this->heap=vector<int>(n,0);
        this->size=n;
        for(int i=n/2;i<n;i++){
            this->heap[i]=arr[i];
        }
        for(int i=n/2-1;i>=0;i--){
            this->heap[i]=arr[i];
            this->heapify(i);
        }
    }
    int leftChild(int ind){
        return (2*ind+1>=this->size)?(-1):(2*ind+1);
    }
    int rightChild(int ind){
        return (2*ind+2>=this->size)?(-1):(2*ind+2);
    }
    int parent(int ind){
        if(ind==0)return 0;
        return (ind-1)/2;
    }
    void heapify(int ind){
        //assuming left and right subtree are heaps, we go downwards
        int left=(leftChild(ind)==-1)?(-1):(heap[leftChild(ind)]);
        int right=(rightChild(ind)==-1)?(-1):(heap[rightChild(ind)]);
        if(left==-1 && right==-1){
            return;
        }
        if(left>right){
            if(heap[ind]>=left)return;//it's already a heap
            swap(heap[ind],heap[leftChild(ind)]);
            heapify(leftChild(ind));
        }else{
            if(heap[ind]>=right)return;
            swap(heap[ind],heap[rightChild(ind)]);
            heapify(rightChild(ind));
        }
    }
    int maxElement(){
        return heap[0];
    }
    void insertElement(int val){
        heap.push_back(val);
        size++;
        int ind=size-1;
        while(parent(ind)!=ind && heap[parent(ind)]<heap[ind]){
            int par=parent(ind);
            swap(heap[par],heap[ind]);
            ind=par;
        }
    }
    int extractMax(){
        int ans=heap[0];
        swap(heap[0],heap[size-1]);
        heap.pop_back();
        size--;
        heapify(0);
        return ans;
    }
};
void heapSort(vector<int>&arr){
    Heap heap(arr);
    int n=arr.size();
    for(int i=n-1;i>=0;i--){
        arr[i]=heap.extractMax();
    }
}
bool checkSort(vector<int>&arr){
    for(int i=0;i<arr.size()-1;i++){
        if(arr[i]>arr[i+1])return false;
    }
    return true;
}
int main(){
    vector<int>arr={72, 15, 59, 42, 84, 31, 6, 95, 23, 50, 3, 68, 11, 89, 37, 76, 19, 54, 2, 97, 63, 40, 8, 82, 29, 70, 45, 13, 91, 57, 25, 78, 34, 66, 9, 48, 87, 20, 61, 93};
    heapSort(arr);
    if(checkSort(arr))cout<<"Sorted";
    else cout<<"Not Sorted";
    return 0;
}