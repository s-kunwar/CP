#include <iostream>
#include <vector>
using namespace std;

int m_bs(vector<int>arr,int n,int target);
int m_bs_duplicates(vector<int> arr, int n, int target);

    int main()
{

    //Search in a rotated sorted array (with unique elements)
    vector<int>arr={7,8,9,1,2,3,4,5,6};
    //Search in a rotated sorted array (with duplicate elements)
    vector<int> arrd = {6,7, 8, 9, 1, 2, 3, 4, 5, 6};
    
    int target=7, len=arr.size();
    int targetd = 0, lend = arrd.size();

    cout<<m_bs(arr,len-1,target)<<endl;
    cout << m_bs_duplicates(arrd, lend - 1, targetd) << endl;
}

int m_bs(vector<int> arr, int n, int target){
    int l=0,h=n;

    while(l<=h){
        int m=(l+h)/2;
        //check which side is sorted first
        //check if this sorted side has our number
        //eleminate the non-useful side(the side which dosnt have our number, even if its the sorted one)
        if(arr[m]==target){return m;}
        //is left side sorted
        else if((arr[m]-arr[l])>=0){
            if(target>=arr[l] && target<=arr[m]){ h=m-1; }
            else{ l=m+1; }
        }
        else{
            if (target >= arr[m] && target <= arr[h]){l=m+1;}
            else{h=m-1;}
        }
    }
    return -1;
}


int m_bs_duplicates(vector<int> arr, int n, int target){
    int l =0,h=n;

    while(l <= h){

        int m=(l+h)/2;
        // check which side is sorted first
        // check if this sorted side has our number
        // eleminate the non-useful side(the side which dosnt have our number, even if its the sorted one)
        //Since it has duplicates, you cant give just one index, you can say whether its found or not
        //The edge case for duplicates comes when, mid term=low term =high term, where you wont know which section is sorted
        //if mid term=low=high, and its equal to target, we can return found, else we can trim down our search space
        if (arr[m] == target){
            return 302;
        }
        //edge case for duplicates
        else if (arr[h]==arr[l]){
            if(arr[l]==target){return 302;}
            else{l++;h--;continue;}
        }
        // is left side sorted
        else if ((arr[m] - arr[l]) >= 0){
            if (target >= arr[l] && target <= arr[m]){
                h=m-1;
            }
            else{
                l=m+1;
            }
        }
        else{
            if (target >= arr[m] && target <= arr[h]){
                l=m+1;
            }
            else{
                h=m-1;
            }
        }
    }
    return -1;
}