#include<bits/stdc++.h>
using namespace std;

void merge(vector<int>&arr, int left, int right){
    vector<int>sortedArray;
    int i=left;
    int mid=(left+right)/2;
    int j=mid+1;
    while(i<=mid && j<=right){
        if(arr[i]<arr[j]){
            sortedArray.push_back(arr[i++]);
        }
        else sortedArray.push_back(arr[j++]);
    }
    while(i<=mid)sortedArray.push_back(arr[i++]);
    while(j<=right)sortedArray.push_back(arr[j++]);
    for(int i=left;i<=right;i++){
        arr[i]=sortedArray[i-left];
    }
}
void mergeSort(vector<int>&arr,int left, int right){
    if(left>=right)return;
    int mid=(left+right)/2;
    mergeSort(arr,left,mid);
    mergeSort(arr,mid+1,right);
    merge(arr,left,right);
}
bool checkSort(vector<int>&arr){
    for(int i=0;i<arr.size()-1;i++){
        if(arr[i]>arr[i+1])return false;
    }
    return true;
}
int main(){
    vector<int>arr={72, 15, 59, 42, 84, 31, 6, 95, 23, 50, 3, 68, 11, 89, 37, 76, 19, 54, 2, 97, 63, 40, 8, 82, 29, 70, 45, 13, 91, 57, 25, 78, 34, 66, 9, 48, 87, 20, 61, 93};
    mergeSort(arr,0,arr.size()-1);
    if(checkSort(arr))cout<<"Sorted";
    else cout<<"Not Sorted";
    return 0;
}