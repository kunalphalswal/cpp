#include<bits/stdc++.h>
using namespace std;

vector<int>countingSort(vector<int>&arr){
    //array only contains non-negative numbers and max element is less than 1e5
    int mx=*max_element(arr.begin(),arr.end()); 
    vector<int>count(mx+1,0);
    for(auto &a:arr){
        count[a]+=1;
    }
    int j=0;
    for(int i=0;i<=mx;i++){
        while(count[i]--){
            arr[j++]=i;
        }
    }
    return arr;
}

int main(){
    vector<int>arr={134,1234,561,61,6314,65,1,61,616,1,6,1,87,45,84,2,45};
    countingSort(arr);
    for(auto &a:arr)cout<<a<<" ";
    return 0;
}