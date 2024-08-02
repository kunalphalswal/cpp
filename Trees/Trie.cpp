#include<bits/stdc++.h>
using namespace std;
struct node{
    int size;
    int prefixCount;
    int endOfWord;
    vector<node*> nextNodes;
    node(int size=26){
        this->size=size;
        this->prefixCount=0;
        this->endOfWord=0;
        this->nextNodes.resize(size,nullptr);
    }
};
class Trie{//needs to be generic
    public:
    vector<node*>nodes;
    int size;
    Trie(int size){
        this->size=size;
        this->nodes.resize(size,new node());
    }
    Trie(vector<string>strings){
        this->size=size;
        this->nodes.resize(size,new node());
        for(auto & a:strings){
            this->insert(a);
        }
    }
    void insert(string word){
        auto ptr=this->nodes[word[0]-'a'];
        int n=word.size();
        for(int i=0;i<n;i++){
            ptr->prefixCount+=1;
            if(i<n-1){
                if(ptr->nextNodes[word[i+1]-'a']){
                    ptr=ptr->nextNodes[word[i+1]-'a'];
                }else{
                    auto newNode=new node(this->size);
                    ptr->nextNodes[word[i+1]-'a']=newNode;
                    ptr=newNode;
                }
            }else{
                ptr->endOfWord+=1;
            }
        }
    }
    void remove(string word){
        //spl case: word does not exist.
        auto ptr=this->nodes[word[0]-'a'];
        int n=word.size();
        if(n==1){
            ptr->prefixCount-=1;
            ptr->endOfWord-=1;
        }
        bool success = remove(ptr,0,word,n);
        if(!success){
            cout<<word<<" does not exist in the first place for it to be removed.\n";
        }else{
            //not needed right now
            // if(ptr->prefixCount==0){
            //     this->nodes[word[0]-'a']=nullptr;
            //     delete(ptr);
            // }
        }
    }
    bool remove(node* ptr,int ind, string& word,int n){
        if(!ptr || ptr->prefixCount==0)return false;
        if(ind==n-1){
            ptr->prefixCount-=1;
            ptr->endOfWord-=1;
            return true;
        }
        auto nxtPtr=ptr->nextNodes[word[ind+1]-'a'];
        bool success=remove(nxtPtr,ind+1,word,n);
        if(success){
            if(nxtPtr->prefixCount==0){
                ptr->nextNodes[word[ind+1]-'a']=nullptr;
                delete(nxtPtr);
            }
            ptr->prefixCount-=1;
            return true;
        }
        else return false;
    }
    int countPrefix(string pref){
        node* ptr=this->nodes[pref[0]-'a'];
        return countPrefix(ptr,0,pref,pref.size());
    }
    int countPrefix(node*ptr,int ind,string & pref,int n){
        if(!ptr)return 0;
        if(ind==n-1){
            return ptr->prefixCount;
        }else return countPrefix(ptr->nextNodes[pref[ind+1]-'a'],ind+1,pref,n);
    }
    int countExact(string pref){
        node* ptr=this->nodes[pref[0]-'a'];
        return countExact(ptr,0,pref,pref.size());
    }
    int countExact(node*ptr,int ind,string & pref,int n){
        if(!ptr)return 0;
        if(ind==n-1){
            return ptr->endOfWord;
        }else return countExact(ptr->nextNodes[pref[ind+1]-'a'],ind+1,pref,n);
    }
};

int main(){
    vector<string>strings={"hulk","hulkane","hulkayerie","halak","ironman", "thor","thala"};
    auto trie=new Trie(strings);
    cout<<trie->countPrefix("th")<<"\n"<<trie->countExact("hul");
    return 0;
}