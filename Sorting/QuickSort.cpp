#include<bits/stdc++.h>
using namespace std;

//find an element which is greater than pivot, because whatever is traversed through by i must be less than or equal to pivot element.
void findGreaterElement(vector<int>&arr, int& i, int high, int pivot){
    while(i<=high && arr[i]<=pivot){
        i++;
    }
}

//find an element which is less than pivot, because whatever is traversed through by j must be greater than or equal to pivot.
void findNonGreaterElement(vector<int>&arr,int& j,int low,int pivot){
    while(j>=low && arr[j]>pivot){
            j--;
        }
}

int partition (vector<int>&arr, int low, int high)
{
    int pivot=arr[low];
    int i=low+1;
    int j=high;
    findGreaterElement(arr,i,high,pivot);
    findNonGreaterElement(arr,j,low,pivot);
    
    //this while loop helps in positioning i and j such that when it ends:
    //to the left of i we'll have all elements smaller or equal to than pivot and on the right of j, we'll have all elements greater than pivot
    //Now we know that j will only stop at an element less than equal to pivot, and after that position, all the elements are greater than 
    //pivot and because the while loop has ended, it means that i>j and all elements left to j are less than equal to pivot.
    //hence j is the position that pivot would be in, if the array was sorted. So we swap, whatever was at j, with pivot's position. 
    //and return j
    //and in this case, because the pivot was also to the left of i, and j is also stopped at a position less than equal to pivot, swapping
    //both these positions does not affect the relative sorting of array.
    while(i<j){
        swap(arr[i],arr[j]);
        findGreaterElement(arr,i,high,pivot);
        findNonGreaterElement(arr,j,low,pivot);
    }
    swap(arr[j],arr[low]);
    return j;
}
void quickSort(vector<int>&arr, int low, int high)
    {
        if(low>=high)return;
        int pivot=partition(arr,low,high);
        //pivot is at its sorted position.

        //similarly we sort all the elements by calling this quick Sort func recursively.
        quickSort(arr,low,pivot-1);
        quickSort(arr,pivot+1,high);
    }

int main(){
    vector<int>arr={4,1,3,9,7};
    quickSort(arr,0,4);
    return 0;

}