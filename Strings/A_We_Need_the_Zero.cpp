#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



/*

What xor does-

for the every bit of two integers x and y
if the bits are same->result bit is 0
if the bits are different->result bit is 1

eg: bits of 3 are 011 and of 6 is 110
    according to rules 3xor6 is-> 101 i.e 5

Properties of Xor operation
1:****Rearrange****
you can rearrage in any manner, remove brackets, rearrange any way possible
eg: a xor b xor (c xor d) can be written as (a xor b xor c xor d) or also as a xor d xor (c xor b) or any way possible

2:***Self Inverse***
a xor a = 0

3:*****Identity*****
a xor 0 = a

*/



int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin>>n;
        int res;
        vector <int> arr(n);

        for(int i=0;i<n;i++){cin>>arr[i];}

        if(n%2==0){
            res=arr[0];
            for(int j=1;j<n;j++){
                res=res^arr[j];
            }
            if(res==0) cout<<arr[n-1]<<endl;
            else cout<<-1<<endl;
        }
        else{
            res=arr[0];
            for(int j=1;j<n;j++){
                res=res^arr[j];
            }
            cout<<res<<endl;
        }

    }

    return 0;
}
