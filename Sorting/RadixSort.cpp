#include<bits/stdc++.h>
using namespace std;

vector<int> radixSort(vector<int>&arr){
    int base=arr.size();
    vector<vector<int>>count(base,vector<int>());
    int mx=*max_element(arr.begin(),arr.end());
    int maxPow = log2(mx)/log2(base);
    for(int i=0;i<=maxPow;i++){
        count=vector<vector<int>>(base);
        for(auto & a:arr){
            int x=a;
            for(int j=0;j<i;j++){
                x/=base;
            }
            count[x%base].push_back(a);
        }
        arr.clear();
        for(auto & c:count){
            for(auto & a:c)arr.push_back(a);
        }
    }
    return arr;
    
}

int main(){
    vector<int>arr={1,4,3,135,5,15,15,13,34,5,1,1,616,61,613,134,135,65,16,16,12334,134};
    radixSort(arr);
    for(auto & a:arr)cout<<a<<" ";
    cout<<"\n";
    return 0;
}