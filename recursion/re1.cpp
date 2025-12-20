#include <iostream>
#include <vector>
using namespace std;

int pow(int n,int num){
    if(n==0){
        return 1;
    }
    return (num*pow(n-1,num));
}


int pow2(int n,int num){
    if(n==0){
        return 1;
    }
    if(n%2==0){
        return (pow2(n/2,num*num));
    }
    else{
        return (num*pow2((n-1)/2,num*num));
    }
}


int main(){
    int i=10;

    cout << pow(i, 2)<<'\n';


    /* optimised recursion ( )
        for n power 8, we wont return n power 7,
        we will return n*n*power 4
        for odd like n power 7, we will return n*power 6    
    */
    cout << pow2(i, 2) << '\n';


    return 0;
}