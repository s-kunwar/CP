#include <iostream>
#include <vector>
using namespace std;

//To find the first and last occurenece using Bs
//1: using lower bound and upper bound
//2: using basic binary search

int lb(vector<int>arr,int len,int target);
int ub(vector<int> arr, int len, int target);
int m_bs_first(vector<int> arr, int len, int target);
int m_bs_last(vector<int> arr, int len, int target);


int main()
{

    vector<int> arr={1, 5, 6, 8, 8, 8, 10, 13,20,20,21,24}; //ind=0to11
    int len=arr.size(), target=2;

    //Using LB AND UP
    // For 8, LB gives us ind=3, UP gives us ind=6
    // If a number is not there in arr, we just give -1,-1

    int first=lb(arr,len-1,target);
    if(first==-1 || arr[first]!=target){cout<<-1<<','<<-1<<endl;}
    else{
        int last = ub(arr, len - 1, target) - 1;
        cout<<first<<','<<last<<endl;
    }

    //By tweaking the base Binary search
    first = m_bs_first(arr, len - 1, target);
    if(first==-1){
        cout << -1<<','<<-1;
    }
    else
    {
        int last = m_bs_last(arr, len - 1, target);
        cout << first << ',' << last<<endl;
    }

    return 0;
}



int lb(vector<int> arr, int len, int target){
    int l=0,h=len;
    int ans=-1;

    while(l<=h){
        int m=(l+h)/2;

        if(arr[m]>=target){
            ans=m;
            h=m-1;
        }
        else{
            l=m+1;
        }
    }
    return ans;
}

int ub(vector<int> arr, int len, int target)
{
    int l = 0, h = len;
    int ans = len+1;

    while (l <= h)
    {
        int m = (l + h) / 2;
        if (arr[m] > target)
        {
            ans = m;
            h = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }
    return ans;
}



int m_bs_first(vector<int> arr, int len, int target){

    int l=0,h=len;
    int ans=-1;

    while(l<=h){

        int m=(l+h)/2;

        if(arr[m]==target){
            ans=m;
            h=m-1;
        }
        else if(arr[m]>target){
            h=m-1;
        }
        else{
            l=m+1;
        }
    }

    return ans;

}

int m_bs_last(vector<int> arr, int len, int target)
{

    int l = 0, h = len;
    int ans = -1;

    while (l <= h)
    {

        int m = (l + h) / 2;

        if (arr[m] == target)
        {
            ans = m;
            l = m + 1;
        }
        else if (arr[m] > target)
        {
            h = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }

    return ans;
}