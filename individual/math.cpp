#include <iostream>
#include <cmath>
#include <vector>
using namespace std;


bool isprime_rootn(int n){
    //  O(root n)
    //check from 2 to root of n
    if(n==0||n==1) return false;
    for(int x=2; x<=sqrt(n); x++){
        if(n%x==0) return false;
    }
    return true;
}

bool isprime_sieve(int s, int n){
    //sieve algo is used to find primes in a range of numbers
    //O(rangelenght*log2log2rangelenght)
    /*to find all primes between 1 to 50, 1and0 are primes, then 2 is a prime so all multiples of 2 from 2sq upto 50 will not be primes, then 
    3 is a prime so we'll mark all the multiples of 3 from 3sq upto 50 as not primes, and repeat this process
    */
    vector<bool>primecount(n-s+1,true);

    for(int x=s; x<=n; x++){
        if(x==0||x==1) primecount[x]=false;
        if(primecount[x]==true &&  isprime_rootn(x)==true){
            for(int y=x*x; y<=n; y+=x) primecount[y]=false;
        }
    }

    //print or return array of primes
    for(int i=0; i<n-s+1; i++){
        if(primecount[i]==true) cout<<s+i<<endl;
    }
}




int main(){
    isprime_sieve(0,101);
    return 0;
}