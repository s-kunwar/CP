#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#include <climits>


int main(){
    /*
    Recently, Utkarsh has become obsessed with Powerful Numbers. However, he now has to go out and relax, so he leaves this simple problem for you to solve.

A powerful number is a positive integer n
 such that, for every prime factor p
 of n
, the square p2
 is also a divisor of n
. In other words, if p
 divides n
, then p2
 must divide n
 completely as well.

There are infinitely many powerful numbers. The first few powerful numbers are:
1, 4, 8, 9, 16, 25, 27, 32, 36, 49, 64, 72, 81, 100,…

Given a positive integer N
, count how many powerful numbers are ≤N
, and compute their sum.

Input
A single line containing an integer N
 (1≤N≤1011
).

Output
Output two integers:

the number of powerful numbers ≤N
,
the sum of all powerful numbers ≤N
.
Examples
InputCopy
10
OutputCopy
4
22
InputCopy
100
OutputCopy
14
524
Note
In the first test case

For N=10
, the powerful numbers not exceeding N
 are:
1, 4, 8, 9.
There are 4
 such numbers, and their sum is 22
.

In the second test case Refer to the main problem statement for the list of the first several powerful numbers. For N=100
, all powerful numbers not exceeding N
 are those appearing in that list and ≤100
. There are 14
 such numbers, and their sum is 524

    also iclude elements like 72 which are multiple prime powers multiplied together
    and remove dulplicates
    */

    
    long long N;
    cin>>N;
    //also include prime powers multiplied together like 72=8*9
    vector<long long> powerful_numbers;
    powerful_numbers.push_back(1); //1 is also a powerful number
    for(long long i=2; i*i<=N; i++){
        long long power=i*i;
        while(power<=N){
            powerful_numbers.push_back(power);
            power*=i;
        }
    }
    
    sort(powerful_numbers.begin(), powerful_numbers.end());
    powerful_numbers.erase(unique(powerful_numbers.begin(), powerful_numbers.end()), powerful_numbers.end());
    cout<<powerful_numbers.size()<<endl;
    long long sum=0;
    for(auto num: powerful_numbers){
        sum+=num;
        cout<<num<<" ";
    }
    cout<<sum<<endl;

    return 0;
}