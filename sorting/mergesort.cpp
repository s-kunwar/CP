#include <iostream>
#include <vector>
using namespace std;

/*
MERGE SORT - BREAK AND MERGE
----------------------------
break the arr into chunks till its a single element array
then start merging them into a new array comparing each element
*/


// Merge two sorted subarrays
vector<int>merge(vector<int>left,vector<int>right){

    vector<int>result;
    int i = 0, j = 0;

    // Merge elements in sorted order
    while(i<left.size() && j<right.size()){
        if (left[i]<right[j]){
            result.push_back(left[i]);
            i++;
        }
        else{
            result.push_back(right[j]);
            j++;
        }
    }
    // Add remaining elements (if any)
    while (i<left.size()){
        result.push_back(left[i]);
        i++;
    }
    while (j<right.size()){
        result.push_back(right[j]);
        j++;
    }

    return result;
}



// Recursive merge sort function
vector<int> mergeSort(vector<int>&arr,int l,int h){
    if (l==h){
        return {arr[l]}; // return single-element vector
    }

    int m = (l+h)/2;
    vector<int> left = mergeSort(arr, l, m);
    vector<int> right = mergeSort(arr, m + 1, h);

    return merge(left, right);
}



int main()
{
    vector<int> arr = {56, 4, 5, 8, 2, 9};

    vector<int>sortedArr=mergeSort(arr, 0, arr.size() - 1);
    for(int x : sortedArr){
        cout<<x<<' ';
    }

    return 0;
}
