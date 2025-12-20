#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int epow(int x, int n){

    static float ans=1;
    static int term=0;
    
    if(term>=n){
        return ans;
    }

    term++;
    ans = ans + ((float)pow(x, term) / term);
    epow(x,n);

}

int main(){

    // Taylor series
    cout<<epow(3,3);

    return 0;
}