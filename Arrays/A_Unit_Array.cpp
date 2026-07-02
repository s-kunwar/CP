#include <iostream>
#include <vector>

using namespace std;


int main(){

    int t;
    cin>>t;

    while(t--){

        int n,neg=0,pos=0,temp;
        cin>>n;
        while(n--){
            cin>>temp;
            if(temp==-1) neg++;
            else pos++;
        }

        if(neg==pos || pos>neg){
            if(neg%2==0) cout<<0<<endl;
            else{
                cout<<1<<endl;
            }
        }
        else{
            int cnt=((neg-pos)%2+(neg-pos)/2);
            if((neg-cnt)%2==0) cout<<cnt<<endl;
            else cout<<cnt+1<<endl;
        }


    }

    return 0;
}