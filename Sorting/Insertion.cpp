#include<bits/stdc++.h>
using namespace std;
void insertionSort(vector<int>&arr){
    int n=arr.size();
    for(int i=1;i<n;i++){
        for(int j=i;j>0;j--){
            if(arr[j]<arr[j-1]){
                swap(arr[j],arr[j-1]);
            }
        }
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
    insertionSort(arr);
    if(checkSort(arr))cout<<"Sorted";
    else cout<<"Not Sorted";
    return 0;
}