#include <iostream>
#include <vector>

using namespace std;


int main(){

    int t;
    cin>>t;

    while(t--){



        long long n;
        cin>>n;
        
        long long minn,maxx;
        long long cnt=0, temp=n;

        if(n%2!=0 || n<4) {cout<<-1<<endl;continue;}
        
        //min
        if((n%6)%4==0){
            cnt=n/6 + (n%6)/4;
        }
        else if((n%6 + 6)%4==0){
            if(((n/6)-1)>=0)
                cnt= (n/6)-1 + (n%6 + 6)/4;
            else
                cnt=-1;
        }
        else{
            cnt=-1;
        }

        if(cnt==-1){cout<<-1<<endl;continue;}
        cout<<cnt<<' ';

        //max
        if(n%4==0){
            cnt=n/4;
        }
        else if((n%4 + 4)%6==0){
            if( ((n/4)-1) >=0 )
                cnt= (n/4)-1 + (n%4 + 4)/6;
            else
                cnt=-1;
        }
        else{
            cnt=-1;
        }     
        
        cout<<cnt<<endl;


    }
    

    return 0;
}