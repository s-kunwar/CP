#include <iostream>
#include <vector>

using namespace std;


int main(){


    int n,k;
    int x,a,b,c;

    cin>>n>>k;
    cin>>x>>a>>b>>c;

    int len=n/k;
    int xorr=0;
    int temp=x;
    int prevtemp=x;
    int sum=0;
    bool ini=true;

    while(len--){
        if(ini) sum=temp;
        else{
            temp=(a*prevtemp + b)%c;
            sum+=temp;
            prevtemp=temp;
        }
        for(int i=1;i<k;i++){
            temp=(a*prevtemp + b)%c;
            sum+=temp;
            prevtemp=temp;
        }
        cout<<sum<<' ';
        xorr=xorr^sum;
        ini=false;
        sum=0;
    }

    cout<<xorr<<endl;
    

    return 0;
}