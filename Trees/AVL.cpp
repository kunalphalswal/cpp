#include<bits/stdc++.h>
using namespace std;
class node{
    private:
    int key;
    node* left;
    node* right;
    node* parent;
    int height;
    public:
    node(int val){
        this->key=val;
        this->left=nullptr;
        this->right=nullptr;
        this->parent=nullptr;
        this->height=0;
    }
    friend class AVLTree;
};
class AVLTree{
    private:
    node* root;
    public:
    AVLTree(int rootVal){
        this->root = new node(rootVal);
    }
    AVLTree(){
        this->root=nullptr;
    }
    void insert(int key){
        auto newNode=new node(key);
        insert(this->root,newNode);
    }
    int insert(node*ptr,node* newNode){
        if(newNode->key<ptr->key){
            if(ptr->left){
                insert(ptr->left,newNode);
            }else{
                ptr->left=newNode;
                newNode->parent=ptr;
            }
        }else if(newNode->key==ptr->key){
            cout<<"A node with given key already exists!\n";
            return -1;//returns -1 in this case.
        }else{
            if(ptr->right){
                insert(ptr->right,newNode);
            }else{
                ptr->right=newNode;
                newNode->parent=ptr;
            }
        }
        balance(ptr);
    }
    int balance(node*ptr){
        if(abs(height(ptr->right)-height(ptr->left))>1){
            if(height(ptr->right)>height(ptr->left)){
                return lRotate(ptr);
            }else{
                return rRotate(ptr);
            }
        }
        return ptr->height=max(height(ptr->left),height(ptr->right))+1;
    }
    int lRotate(node* ptr){
        // cout<<"L Rotating:"<<ptr->key<<"with "<<ptr->right->key<<"\n";
        if(isLeftHeavy(ptr->right)){
            rRotate(ptr->right);
        }
        node* rChild=ptr->right;
        ptr->right=rChild->left;
        rChild->left=ptr;
        auto par=ptr->parent;
        ptr->parent=rChild;
        rChild->parent=par;
        if(par==nullptr){
            root=rChild;
            ptr->height=max(height(ptr->left),height(ptr->right))+1;
            rChild->height=max(height(rChild->left),height(rChild->right))+1;
            return rChild->height;
        }
        if(par->left && par->left->key==ptr->key){
            par->left=rChild;
        }else par->right=rChild;
        ptr->height=max(height(ptr->left),height(ptr->right))+1;
        rChild->height=max(height(rChild->left),height(rChild->right))+1;
        return rChild->height;
    }
    int rRotate(node*ptr){
        // cout<<"R Rotating:"<<ptr->key<<"\n";
        if(isRightHeavy(ptr->left)){
            lRotate(ptr->left);
        }
        //what if the above action balances the subtree from ptr.
        //may never happen, so confirm it, but until then, this rotation returns the new height of the subtree.
        //Rotating in an eligible case decreases height of one subtree by one and increases of other by 1. That's how it balances a differential
        // of two.
        // So if we try to rotate a node whose subtrees only have a differential in height of 1, then the differential will stay one but
        // will be transferred to the other side. Say we do LR because right sub is 1 more, then after LR left sub will be one more than right.
        // If the original differential was 2, then only the height of the tree will decrease by one but if the differential was just one, so 
        // one sub was heavy instead of being imbalanced, it will not affect the height.
        // And we will never encounter an imbalanced node down the tree because we act on the very first imbalance.
        //1. reshuffle the pointers.
        auto lChild=ptr->left;
        ptr->left=lChild->right;
        lChild->right=ptr;
        auto par=ptr->parent;
        lChild->parent=par;
        ptr->parent=lChild;
        if(par==nullptr){
            root=lChild;
            ptr->height=max(height(ptr->left),height(ptr->right))+1;
            lChild->height=max(height(lChild->left),height(lChild->right))+1;
            return lChild->height;
        }
        if(par->left && par->left->key==ptr->key){
            par->left=lChild;
        }else par->right=lChild; 
        //2. reassign the new heights
        ptr->height=max(height(ptr->left),height(ptr->right))+1;
        lChild->height=max(height(lChild->left),height(lChild->right))+1;
        return lChild->height;
        
    }
    bool isLeftHeavy(node *ptr){
        return height(ptr->left)>height(ptr->right);
    }
    bool isRightHeavy(node* ptr){
        return height(ptr->right)>height(ptr->left);
    }
    int height(node*ptr){
        if(ptr==nullptr)return -1;
        else return ptr->height;
    }
    void remove(int key){
        remove(root,key);
    }
    void remove(node*ptr,int key){
        if(ptr->key>key){
            if(ptr->left==nullptr){
                cout<<"Given key "<<key<<" doesn't exist\n";
                return;
            }else{
                remove(ptr->left,key);
                balance(ptr);    
            }
        }else if(ptr->key==key){
            //after removing this node, it's parent still points to that node's location which is no longer being used by the program.
            auto par=ptr->parent;
            reshuffle(ptr);
            return;
        }else{
            if(ptr->right==nullptr){
                cout<<"Given key "<<key<<" doesn't exist\n";
                return;
            }else{
                remove(ptr->right,key);
                balance(ptr);
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
            balance(par);//if you need to call it again, call in the balance function itself after performing checks of balance.
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
                ptr->key=succ->key;
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
        if(this->root)ans.push_back(this->root->key);
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
    auto avl=new AVLTree(5);
    avl->insert(2);
    avl->insert(3);
    avl->insert(6);
    avl->insert(8);
    avl->insert(1);
    avl->remove(3);
    avl->remove(2);
    auto inorder=avl->inorderTraversal();
    for(auto & a:inorder)cout<<a<<" ";
    cout<<"\n";
    avl->remove(5);
    inorder=avl->inorderTraversal();
    for(auto & a:inorder)cout<<a<<" ";
    cout<<"\n";
    avl->insert(19);
    inorder=avl->inorderTraversal();
    for(auto & a:inorder)cout<<a<<" ";
    cout<<"\n";
    avl->remove(8);
    inorder=avl->inorderTraversal();
    for(auto & a:inorder)cout<<a<<" ";
    cout<<"\n";
    avl->insert(10);
    inorder=avl->inorderTraversal();
    for(auto & a:inorder)cout<<a<<" ";
    cout<<"\n";
    avl->insert(23);
    inorder=avl->inorderTraversal();
    for(auto & a:inorder)cout<<a<<" ";
    cout<<"\n";
    avl->remove(6);
    inorder=avl->inorderTraversal();
    for(auto & a:inorder)cout<<a<<" ";
    cout<<"\n";
    avl->insert(41);
    inorder=avl->inorderTraversal();
    for(auto & a:inorder)cout<<a<<" ";
    cout<<"\n";
    return 0;
}