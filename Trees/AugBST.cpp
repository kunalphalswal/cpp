#include<bits/stdc++.h>
using namespace std;
class node{
    private:
    int key;
    node* left;
    node* right;
    node* parent;
    //augmentation: modifying/adding to the above basic structure of a bst node to serve some new purpose.
    int subSize;
    // the no of nodes in the tree starting from this node.
    //can be used to calculate where this node lies in the sorted order or rank.
    public:
    node(int val){
        this->key=val;
        this->left=nullptr;
        this->right=nullptr;
        this->parent=nullptr;
        this->subSize=1;
    }
    friend class BST;
};
class BST{
    private:
    node* root;
    public:
    BST(int rootVal){
        this->root = new node(rootVal);
    }
    BST(){
        this->root=nullptr;
    }
    void insert(int key){
        node* newNode=new node(key);
        if(root==nullptr){
            root=newNode;
            return;
        }
        if(!insert(this->root,newNode)){
            cout<<"Given Key "<<key<<" Already exists\n";//how to output this in red
        }
    }
    bool insert(node*ptr,node*newNode){//whether the insert was successful or not
        if(ptr->key>newNode->key){
            if(ptr->left==nullptr){
                ptr->left=newNode;
                newNode->parent=ptr;
                ptr->subSize+=1;
            }else {
                bool success=insert(ptr->left,newNode);
                if(success)ptr->subSize+=1;
            }
        }else if(ptr->key==newNode->key){
            return false;
        }else{
            if(ptr->right==nullptr){
                newNode->parent=ptr;
                ptr->right=newNode;
                ptr->subSize+=1;
            }else{
                bool success=insert(ptr->right,newNode);
                if(success)ptr->subSize+=1;
            }
        }
        return true;
    }
    int rank(int key){//where that key would lie
        //even if that node exists or doesn't exist.
        return rank(root,key);
    }
    int rank(node*ptr,int key){
        if(ptr==nullptr){
            return 0;//in case key isn't present, where it would be present.
        }
        if(ptr->key==key){
            if(ptr->left){
                return ptr->left->subSize+1;
            }else return 1;
        }else if(ptr->key<key){
            if(ptr->left){
                return ptr->left->subSize+1+rank(ptr->right,key);
            }else{
                return 1+rank(ptr->right,key);
            }
        }else{
            return rank(ptr->left,key);
        }
    }
    void remove(int key){
        auto ptr=root;
        while(ptr){
            if(ptr->key>key){
                if(ptr->left==nullptr){
                    cout<<"Given key doesn't exist";
                    return;
                }else ptr=ptr->left;
            }else if(ptr->key==key){
                //after removing this node, it's parent still points to that node's location which is no longer being used by the program.
                auto par=ptr->parent;
                reshuffle(ptr);
                break;
            }else{
                if(ptr->right==nullptr){
                    cout<<"Given key doesn't exist";
                    return;
                }else{
                    ptr=ptr->right;
                }
            }
        }
    }
    //should return the new node that takes old one's place. we just exchange keys instead
    void reshuffle(node*ptr){
        //just have to replace by predecessor whatever node you take, like if you take s as predecessor, then find predecessor of s too and so on.
        //see how much randomness you can add to the selection of predecessor and successor.  
        // cout<<"Reshufflling"<<ptr->key<<"\n";  
        if(ptr->left==nullptr && ptr->right==nullptr){
            if(ptr->key==root->key){
                root=nullptr;
            }
            auto par=ptr->parent;
            if(par->left && par->left->key==ptr->key){
                par->left=nullptr;
            }
            else par->right=nullptr;
            delete(ptr);
            return;
        }
        int toss=rand();
        //to add randomnes on which to choose between successor and predecessor, in an effort to try and preserve the balance of tree.
        // no point of this if the tree was forced to be unbalanced in the first place.
        if(toss&1){
            auto pred=predecessor(ptr);
            if(pred){
                int temp=ptr->key;
                ptr->key=pred->key;
                pred->key=temp;
                reshuffle(pred);
            }else{
                auto succ=successor(ptr);
                int temp=ptr->key;
                succ->key=temp;
                reshuffle(succ);
            } 
        }else{
            auto succ=this->successor(ptr);
            if(succ){
                int temp=ptr->key;
                ptr->key=succ->key;
                succ->key=temp;
                reshuffle(succ);
            }else{
                auto pred=predecessor(ptr);
                int temp=ptr->key;
                ptr->key=pred->key;
                pred->key=temp;
                reshuffle(pred);
            }
        }
    }
    int predecessor(int key){//really means predecessor
        auto ptr=root;
        int ans=-1;
        while(ptr!=nullptr){
            if(ptr->key<key){
                ans=ptr->key;
                ptr=ptr->right;
            }else if(ptr->key==key){
                ptr=ptr->left;
            }   
            else
            {
                ptr=ptr->left;
            }
        }
        return ans;
    }
    int successor(int key){
        auto ptr=root;
        int ans=-1;
        while(ptr){
            if(ptr->key<key){
                ptr=ptr->right;
                
            }else if(ptr->key==key){
                ptr=ptr->left;
            }   
            else
            {
                ans=ptr->key;
                ptr=ptr->left;
            }
        }
        return ans;
    }
    bool binarySearch(int key){
        auto ptr=root;
        while(ptr){
            if(ptr->key<key){
                ptr=ptr->right;
            }else if(ptr->key==key){
                return true;
            }   
            else{
                ptr=ptr->left;
            }
        }
        return false;
    }
    node* predecessor(node * ptr){
        if(ptr->left==nullptr){
            return nullptr;
        }
        ptr=ptr->left;
        while(ptr){
            if(ptr->right){
                ptr=ptr->right;
            }else{
                break;
            }
        }
        return ptr;
    }
    node* successor(node * ptr){
        if(!ptr->right){
            return nullptr;
        }
        ptr=ptr->right;
        while(ptr){
            if(ptr->left){
                ptr=ptr->left;
            }
            else{
                break;
            }
        }
        return ptr;
    }   
    vector<int> inorderTraversal(){
        vector<int>ans;
        queue<node*>q;
        q.push(this->root);
        ans.push_back(this->root->key);
        while(!q.empty()){
            auto ptr=q.front();q.pop();
            if(ptr->left){
                ans.push_back(ptr->left->key);
                q.push(ptr->left);
            }else{
                ans.push_back(0);
            }
            if(ptr->right){
                q.push(ptr->right);
                ans.push_back(ptr->right->key);
            }
            else{
                ans.push_back(0);
            }
        }
        return ans;
    }
};

int main(){
    //to set new seed for rand(), which is used in bst->remove() to generate randomness in replacing the removed node with its predecessor or 
    // //successor
    // srand(time(NULL)); //this somehow keeps the objects the same.
    auto bst=new BST();
    bst->insert(3);
    bst->insert(1);
    bst->insert(4);
    bst->insert(5);
    bst->insert(2);
    bst->remove(3);
    bst->insert(-1);
    auto inorder=bst->inorderTraversal();
    for(auto & a:inorder)cout<<a<<" ";
    cout<<'\n'<<bst->rank(3)<<"\n";
    return 0;
}