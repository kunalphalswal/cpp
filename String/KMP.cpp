#include<bits/stdc++.h>
using namespace std;

class KMP{
    private:

    public:
    static vector<int>findOccurences(string & s,string & t){
        //build lps table
        int m=s.size();
        int n=t.size();
        //the values of positions used throughout the algo is carefully chosen for every scenario of the algo.
        vector<int>lps(m,0);
        int j=0;
        for(int i=1;i<m;i++){
            if(s[i]==s[j]){
                j+=1;
            }else j=0;
            lps[i]=j;
        }

        //start the algo
        vector<int>ans;
        j=0;
        for(int i=0;i<n;i++){
            if(t[i]==s[j]){
                j++;
            }else{
                j=(j>0)?(lps[j-1]):0;
            }
            if(j==m){
                ans.push_back(i-m+1);
                j=lps[m-1];
            }
        }
        return ans;
    }
};

int main(){
    string s="abxa";
    string t="abxabxabxabxa";
    auto res=KMP::findOccurences(s,t);
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
    return 0;
}