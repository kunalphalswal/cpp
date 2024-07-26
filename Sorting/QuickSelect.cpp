#include<bits/stdc++.h>
using namespace std;
int partition(vector<int>&arr,int left, int right){
    int pivot=arr[left];
    int i=left;
    int j=right;
    while(i<right && arr[i]<=pivot){
        i++;
    }
    while(left<j && arr[j]>pivot){
        j--;
    }
    while(i<j){
        swap(arr[i],arr[j]);
        while(i<right && arr[i]<=pivot){
            i++;
        }
        while(left<j && arr[j]>pivot){
            j--;
        }
    }
    return j;
}
int quickSelect(vector<int>&arr, int left, int right, int pos){
    if(left==right)return left;
    int pivot = partition(arr, left, right);
    if(pivot==pos){
        return pos;
    }else if(pivot<pos){
        return quickSelect(arr,pivot+1,right,pos);
    }else{
        return quickSelect(arr,left,pivot-1,pos);
    }

}
int main(){
    vector<int>arr={3,5,1,5,7,3,7,2,8,1,2,8,0,8,4,1,5,6,2,7};
    int n=arr.size();
    printf("Median of this array is: %d",quickSelect(arr,0,n-1,n/2));
    return 0;
}