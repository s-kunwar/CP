#include <iostream>
#include <vector>

using namespace std;

/*
//int can store upto 10e9
//long long upto 10e18

conditon for the case when n and k are both odd
i.e to find if x and y exist when n and k are odd
n=2x+ky

for this, y should also be odd so that yk does not become even
so let y=2t+1 where t should also be a non-negative integer

n=2x+k(2t+1)

x=(n-k-2t)/2
for x to be a non negative integer, 
numerator should be even and numerator>=0

since n and k are odd, numerator will always be even
other cond, (n-k-2t)>=0
t <= (n-k)/2t

now t can only be non-neg int, if 
*****************(n-k)>=0**********************
*/

int main(){

    int t;
    cin>>t;

    while(t--){

        long long n,k;
        cin>>n>>k;

        if(n%2==0) cout<<"YES\n";
        else{
            if(k%2==0) cout<<"NO\n";
            else{
               if((n-k)>=0) cout<<"YES\n";
               else cout<<"NO\n"; 
            }
        }


    }

    return 0;
}