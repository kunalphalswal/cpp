#include<bits/stdc++.h>
using namespace std;
#define ll long long
    ll mod_pow(int a, int b, int mod){
        if(b==0)return 1;
        if(b&1){
            return (a*(mod_pow(a,b-1,mod)))%mod;
        }
        else{
            ll half_power=mod_pow(a,b/2,mod);
            return (half_power*half_power)%mod;
        }
    }
    void preComputeFactorials(int maxn,vector<ll>&factorials,vector<ll>&inverses, int mod){
        factorials.resize(maxn+1);
        factorials[0]=1;
        factorials[1]=1;
        for(ll i=2;i<=maxn;i++){
            factorials[i]=(factorials[i-1]*i)%mod;
        }
        inverses.resize(maxn+1);
        /*
        Modular Multiplicative Inverse: 1/a: a^-1=a^(mod-2)%mod if mod is prime.
        Because acc to fermat's little theorum: (a^(m-1))%mod = 1 if mod is prime. and a^(m-2)=(a^(m-1))*(a^-1)
        https://en.wikipedia.org/wiki/Modular_multiplicative_inverse
        */
        inverses[maxn]=mod_pow(factorials[maxn],mod-2,mod);
        for(ll i=maxn-1;i>=2;i--){
            inverses[i]=(inverses[i+1]*(i+1))%mod;
        }
        inverses[1]=1;
        inverses[0]=1;
    }
    int permutation(int m,int m1, int m2,vector<ll>&factorials,vector<ll>&inverses,int mod){
        return (((factorials[m]*inverses[m1])%mod)*inverses[m2])%mod;
    }
    int main(){
        vector<ll>inverses,factorials;
        int mod=1e9+7;
        preComputeFactorials(10,factorials,inverses,mod);
        // cout<<permutation(5,3,2,factorials,inverses,mod);
        for(int i=1;i<=10;i++){
            cout<<factorials[i]<<" "<<inverses[i]<<"\n";
        }
        return 0;
    }