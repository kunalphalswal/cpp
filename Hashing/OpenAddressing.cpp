#include<bits/stdc++.h>
using namespace std;
#define ll long long
class HashFunction{
    private:
    ll a;
    ll m;
    bool isPrime(ll num){
        for(ll i=2;i*i<=num;i+=1){
            if(num%i==0)return false;
        }
        return true;
    }
    void initialize(){
        a=rand();
        m=rand()+INT_MAX;
        if(m&1){

        }else m+=1;
        while(!isPrime(m)){
            m+=2;
        }
    }
    public:
    HashFunction(){
        initialize();
    }
    ll hash(ll key){
        return (a*key)%m;
    }
    
};
class Hashing{
    private:
    HashFunction* h1;
    HashFunction* h2;
    public:
    Hashing(){
        h1=new HashFunction();
        h2=new HashFunction();
    }
    ll doubleHash(ll key,ll trial, ll m){
        auto ans= (h1->hash(key)+(trial*h2->hash(key))%m)%m;
        return ans;
    }
};

class OpenAddressing{
    private:
        vector<vector<int>>hashTable;
        //first element of each index is flag: 0 means empty, 1 means occupied, 2 means deleted
        ll m;
        ll n;
        Hashing* hasher;
        void add(int key,int value){
            for(int trial=0;trial<m;trial+=1){
                int ind=hasher->doubleHash(key,trial,m);
                if(hashTable[ind][0]==0 || hashTable[ind][0]==2){
                    hashTable[ind]={1,key,value};
                    break;
                }
            }
        }
        void doubleTable(){
            auto temp=hashTable;
            m*=2;
            hashTable.clear();
            hashTable.resize(m,{0,0,0});
            for(auto & val:temp){
                if(val[0]==1){
                    add(val[1],val[2]);
                }
            }
        }
        void halfTable(){
            auto temp=hashTable;
            m/=2;
            hashTable.clear();
            hashTable.resize(m,{0,0,0});
            for(auto & val:temp){
                if(val[0]==1){
                    add(val[1],val[2]);
                }
            }
        }
    public:
        OpenAddressing(){
            m=8;
            n=0;
            hasher=new Hashing();
            hashTable.resize(m,{0,0,0});
        }
        
        void insert(int key,int value){
            add(key,value);
            n+=1;
            if(n>=m/2){
                doubleTable();
            }
        }
        ll search(int key){
            for(int trial=0;trial<m;trial+=1){
                int ind=hasher->doubleHash(key,trial,m);
                if(hashTable[ind][0]==1 && hashTable[ind][1]==key){
                    return hashTable[ind][2];
                }
                else if(hashTable[ind][0]==0){
                    break;
                }
            }
        }
        void remove(int key){
            for(int trial=0;trial<m;trial+=1){
                int ind=hasher->doubleHash(key,trial,m);
                if(hashTable[ind][0]==1 && hashTable[ind][1]==key){
                    hashTable[ind][0]=2;
                    break;
                }
                else if(hashTable[ind][0]==0){
                    cout<<"Given key: "<<key<<" doesn't exist for it to be removed.\n";
                    return;
                }
            }
            n-=1;
            if(n<=m/5){
                //half the table
                halfTable();
            }
        }
        void printTable(){
            cout<<"Table size: "<<m<<"\n";
            for(auto & a:hashTable){
                cout<<a[0]<<" "<<a[1]<<"\n";
            }
        }
};
int main(){
    srand(time(0));
    OpenAddressing * mapping= new OpenAddressing();
    mapping->insert(2,4);
    mapping->insert(3,9);
    mapping->insert(4,16);
    mapping->printTable();
    mapping->insert(5,25);
    mapping->insert(6,4);
    mapping->insert(7,9);
    mapping->printTable();
    mapping->insert(9,16);
    mapping->remove(2);
    mapping->remove(3);
    mapping->remove(4);
    mapping->printTable();
    mapping->remove(5);
    mapping->remove(6);
    mapping->remove(7);
    mapping->remove(8);
    mapping->printTable();
    return 0;
}