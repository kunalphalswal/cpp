#include<bits/stdc++.h>
using namespace std;
#define ll long long
// struct node{
//     ll key;
//     ll value;

// };
//how to use templates in cpp
class HashTable{//assuming we already have numeric representations of keys. and values are integers too.
    public:
    vector<vector<pair<int,int>>>hashTable;
    int n;
    int m;
    ll a;
    HashTable(){
        this->a=1ll*rand()+INT_MAX;
        while(!isPrime(this->a)){
            this->a++;
        }
        this->n=0;
        this->m=8;
        this->hashTable.resize(8);
    }
    void insert(ll key, ll value){
        if(n==m){
            doubleTable();
        }
        this->n++;
        this->hashTable[hash(key)].push_back({key,value});
    }
    bool isPrime(ll num){
        for(ll i=2;i*i<=num;i++){
            if(num%i==0){
                return false;
            }
        }
        return true;
    }
    void remove(int key){//assuming each key only corresponds to one value. ie. not the case of multi map
        auto value=hash(key);
        auto it=hashTable[value].begin();
        for(;it!=hashTable[value].end();it++){
            if(it->first==key){
                break;
            }
        }
        if(it==hashTable[value].end()){
            cout<<key<<" doesn't exist for it to be deleted.\n";
        }
        this->n--;
        hashTable[value].erase(it);
        if(n==m/4){
            //note that this is not m/2 and if it was we would be going back and forth with resizing and rehashing at the point 2^k and 2^k+1.
            halfTable();
        }
    }
    void doubleTable(){
        auto temp=hashTable;
        this->m*=2;
        for(auto & a:hashTable)a.clear();
        hashTable.resize(m);
        //rehashing
        for(auto & t:temp){
            for(auto &a:t){
                hashTable[hash(a.first)].push_back({a.first,a.second});
            }
        }
    }
    void halfTable(){
        auto temp=hashTable;
        this->m/=2;
        for(auto & a:hashTable)a.clear();
        hashTable.resize(m);
        //rehashing
        for(auto & t:temp){
            for(auto &a:t){
                hashTable[hash(a.first)].push_back({a.first,a.second});
            }
        }
    }
    int hash(ll key){
        return (((this->a%m)*(key%m))%this->m);
    }
    void printTable(){
        for(auto & t:hashTable){
            for(auto & a:t){
                cout<<a.second<<" ";
            }
            cout<<"\n";
        }
    }
};

int main(){
    srand(time(0));
    auto hashTable=new HashTable();
    hashTable->insert(4,16);
    hashTable->insert(3,9);
    hashTable->insert(12,144);
    hashTable->insert(16,256);
    hashTable->insert(30,900);
    hashTable->insert(21,441);
    hashTable->insert(31,961);
    hashTable->insert(121,14344);
    hashTable->insert(1613,25314216);
    hashTable->insert(31340,45130);
        hashTable->printTable();

    hashTable->remove(1612);
    hashTable->remove(121);
    hashTable->remove(12);
    hashTable->remove(16);
    hashTable->remove(30);
    hashTable->remove(21);
    hashTable->remove(31);
    hashTable->printTable();
    return 0;
}