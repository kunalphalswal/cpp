#include<bits/stdc++.h>
using namespace std;

class SegmentTree{//needs to be generic.
    public:
    vector<int>vec;
    int size;
    SegmentTree(vector<int>&arr){
        int n=arr.size();
        size=n;
        vec.resize(3*n);
        build(arr,0,n-1,0);
    }
    int build(vector<int>&arr, int l, int r,int ind){
        if(l>r)return 0;
        if(l==r){
            return vec[ind]=arr[l];
        }
        int mid=(l+r)/2;
        return vec[ind]=build(arr,l,mid,2*ind+1)+build(arr,mid+1,r,2*ind+2);
    }
    int sum(int l, int r){
        return sum(l,r,0,0,size-1);
    }
    int sum(int l,int r, int ind, int nl,int nr){
        if(l>r)return 0;
        int mid=(nl+nr)/2;
        if(l==nl && r==nr){
            return vec[ind];
        }
        // cout<<l<<" "<<r<<" "<<nl<<" "<<nr<<"\n";
        if(l<=mid){
            if(r<=mid){
                return sum(l,r,2*ind+1,nl,mid);
            }else{
                return sum(l,mid,2*ind+1,nl,mid)+sum(mid+1,r,2*ind+2,mid+1,nr);
            }
        }else{
            if(r<=mid){
                return 0;
            }else{
                return sum(l,r,2*ind+2,mid+1,nr);
            }
        }
    }
    void update(int ind, int newVal){
        update(0,0,size-1,ind,newVal);
    }
    int update(int node,int nl, int nr,int ind,int newVal){
        if(nl==nr){
            int diff=-vec[node]+newVal;
            vec[node]+=diff;
            return diff;
        }
        int mid=(nl+nr)/2;
        if(ind<=mid){
            int diff=update(2*node+1,nl,mid,ind,newVal);
            vec[node]+=diff;
            return diff;
        }else{
            int diff=update(2*node+2,mid+1,nr,ind,newVal);
            vec[node]+=diff;
            return diff;
        }
    }
    void viewTree(){
        for(auto & a:vec){
            cout<<a<<" ";
        }
        cout<<"\n";
    }
};

int main(){
    vector<int>arr={2,13,5,5,2,4,1,6,7};
    auto seg= new SegmentTree(arr);
    seg->viewTree();
    cout<<seg->sum(3,6)<<"\n";
    seg->update(1,-4);
    seg->viewTree();
    cout<<seg->sum(1,4)<<"\n";
    return 0;
}