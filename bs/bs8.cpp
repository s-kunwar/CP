#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool checkcfg(vector<int>arr,int len,int dist,int cows);
int cows_bs(vector<int> arr,int len,int cows);
int book_bs(vector<int>arr,int len,int std);
int checkpagecfg(vector<int> arr,int len ,int pages); //check page config,returns number of students applicable 

int main()
{

    //AGRESSIVE COWS
    /*
    You are given an array with unique elements of stalls[], which denote the positions of stalls.
    You are also given an integer k which denotes the number of aggressive cows.
    The task is to assign stalls to k cows such that the minimum distance between any two of them is
    the maximum possible.

    Examples:

    Input: stalls[] = [1, 2, 4, 8, 9], k = 3
    Output: 3
    Explanation: The first cow can be placed at stalls[0],
    the second cow can be placed at stalls[2] and
    the third cow can be placed at stalls[3].
    The minimum distance between cows in this case is 3, which is the largest among all possible ways.

    Input: stalls[] = [10, 1, 2, 7, 5], k = 3
    Output: 4
    Explanation: The first cow can be placed at stalls[0],
    the second cow can be placed at stalls[1] and
    the third cow can be placed at stalls[4].
    The minimum distance between cows in this case is 4, which is the largest among all possible ways.
    */

    /*
    solution
    we first sort the array
    check function- takes arr, minimum distance, no of cows, return whether the config is possible or not
    bs on ans which from 1 to arr[len-1]-arr[0]
    */

    vector<int> arr = {10, 1, 2, 7, 5};
    sort(arr.begin(),arr.end());
    cout<<cows_bs(arr,arr.size(),3);
    




    //******************************************************************************************************





    /*

    Given an array arr[] of integers, where each element arr[i] represents the number of pages in the i-th book. You also have an integer k representing the number of students. The task is to allocate books to each student such that:

    Each student receives atleast one book.
    Each student is assigned a contiguous sequence of books.
    No book is assigned to more than one student.
    The objective is to minimize the maximum number of pages assigned to any student. In other words, out of all possible allocations, find the arrangement where the student who receives the most pages still has the smallest possible maximum.

    Note: If it is not possible to allocate books to all students, return -1.

    Examples:

    Input: arr[] = [12, 34, 67, 90], k = 2
    Output: 113
    Explanation: Allocation can be done in following ways:
    => [12] and [34, 67, 90] Maximum Pages = 191
    => [12, 34] and [67, 90] Maximum Pages = 157
    => [12, 34, 67] and [90] Maximum Pages = 113.
    The third combination has the minimum pages assigned to a student which is 113.


    Input: arr[] = [15, 17, 20], k = 5
    Output: -1
    Explanation: Since there are more students than total books, it's impossible to allocate a book to each student.


    solution-->

    make a func- which takes arr,pages,students allowed, tells whether this config is possible or not
    run a binary search on (low=highest(this is the least max if all students only get 1 book)) term 
    to (high=sum of all terms(possible when there is only 1 student)) term

    */

    vector<int> arr2 = { 12, 34, 67, 90 };
    cout<<endl<<book_bs(arr2,arr2.size(),2);

    return 0;
}




int cows_bs(vector<int> arr, int len,int cows){
    int l=0, h=arr[len-1]-arr[0], ans=-1;

    while(l<=h){
        int mid=(l+h)/2;
        
        if(checkcfg(arr,len,mid,cows)==true){ ans=mid; l=mid+1; }
        else{ h=mid-1; }
    }
    return ans;
}

bool checkcfg(vector<int> arr, int len, int dist, int cows){
    int cowcount=1,last=arr[0];

    for(int i=1; i<len; i++){
        if(arr[i]-last>=dist){
            cowcount++;
            last=arr[i];
        }
        if(cowcount>=cows){
            return true;
        }
    }
    return false;
}

int book_bs(vector<int> arr, int len ,int std){
    int sum=0;
    for(int x=0;x<len;x++){sum+=arr[x];}
    int l=arr[len-1],h=sum;

    while(l<=h){
        int m=(l+h)/2;
        int currentstd=checkpagecfg(arr,len,m);
        if(currentstd>std){
            l=m+1;
        }
        else{
            h=m-1;
        }
    }
    return l;
}

int checkpagecfg(vector<int> arr, int len,int pages){
    int cntpage=0,stud=1;

    for(int x=0;x<len;x++){
        if((cntpage+arr[x])<=pages){
            cntpage+=arr[x];
        }
        else{
            cntpage=arr[x];
            stud++;
        }
    }
    return stud;
}