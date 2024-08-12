#include<bits/stdc++.h>
using namespace std;
#define ll long long
//ADT that supports: 1. hash of current string. 2. append char to back of current string. 3. remove the first element of the string.
//in simple words, it keeps a hash of a window sliding over the string.
//used in: finding the occurences of a smaller string s in a much larger string t in complexity O(|s|+|t|). Eg: finding word in mailbox
class RollingHash{
    private:
    ll hash;
    ll m;
    int base;
    int n;
    void initialize(){
        //choosing large m to minimize collisions. time consuming
        m=rand()+INT_MAX;
        if(m%2==0){
            m+=1;
        }
        while(!isPrime(m)){
            m+=2;
        }
        hash=0;
        base=256;
    }
    bool isPrime(ll num){
        for(ll i=2;i*i<=num;i+=1){
            if(num%i==0)return false;
        }
        return true;
    }
    ll calculateHash(char ch, int pos, int base){
        int val = int(ch);
        return ((val%m)*(mod_pow(base,pos)))%m;
    }
    ll mod_pow(ll base, ll power){
        if(power==0)return 1;
        if(power&1){
            return (base*mod_pow(base,power-1))%m;
        }
        else{
            ll res=mod_pow(base,power/2);
            return (res*res)%m;
        }
    }
    public:

    RollingHash(){
        initialize();
    }

    RollingHash(string & s){
        initialize();
        n=s.size();
        //hash(here, otherwise usually this is called prehash) of a given string would be its representation in another base. will be unique for each string
        //modulo is used to avoid overflow because results will get large. modulo reprn can be same for multiple nos, hence we manually check
        //if two strings are equal in case their hashes turn out to be equal.
        for(int i=0;i<n;i++){
            hash=(hash+calculateHash(s[i],n-1-i,base))%m;
        }
    }
    
    void append(char ch){
        //how adding another element to the back of string would reflect in its base representation or hash
        hash=((hash*base)%m+int(ch))%m;
        n+=1;
    }

    ll getHash(){//not sure about the returning datatype here.
        return hash;
    }
    void pop(char ch){
        //how removing the most significant no. will reflect in its base representation or hash
        hash=(hash-calculateHash(ch,n-1,base))%m;
        n-=1;
    }
};
class KarpRabin{
    public:
    static vector<int>findOccurences(string& s, string& t){
        int m=s.size(),n=t.size();
        if(m>n)return {};
        vector<int>ans;
        string subt=t.substr(0,m);
        RollingHash hs=RollingHash(s);
        RollingHash ht=RollingHash(subt);
        if(hs.getHash()==ht.getHash()){
            if(s==subt){
                ans.push_back(0);
            }else{
                //this should only happen with a probability of 1/|s|, then only the algorithm will be constant time.
            }
        }
        for(int i=1;i<=n-m;i++){
            ht.pop(t[i-1]);
            ht.append(t[i+m-1]);
            if(hs.getHash()==ht.getHash()){
                subt=t.substr(i,m);
                if(s==subt){
                    ans.push_back(i);
                }else{
                    //this should only happend with a probability of 1/|s|, then only the algorithm will be constant time.
                }
            }
        }
        return ans;
    }
};
int main(){
    string s="rama";
    string t="hare rama hare rama, rama rama hare hare";
    auto res=KarpRabin::findOccurences(s,t);
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
    return 0;
}