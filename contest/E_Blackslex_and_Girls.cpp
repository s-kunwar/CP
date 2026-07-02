#include <iostream>
#include <vector>

using namespace std;


int main(){

    long long t;
    cin>>t;
    
    while(t--){
        long long n,xtot=0,ytot=0;

        cin>>n>>xtot>>ytot;

        string winners;
        cin>>winners;

        vector <long long> minvotes(n);
        long long totvotneeded=0;

        for(int i=0;i<n;i++){
            cin>>minvotes[i];
            totvotneeded+=minvotes[i];
        }

        long long xused=0,yused=0;
        bool awon=false,bwon=false;


        for(int j=0;j<n;j++){
            long long winingvotes=(minvotes[j]/2)+1;
            long long othervotes=minvotes[j]-winingvotes;
        
            if(winners[j]=='0'){
                xused+=winingvotes;
                yused+=othervotes;
                awon=true;
            }
            else{
                yused+=winingvotes;
                xused+=othervotes;
                bwon=true;;
            }
        
        }


        if((xtot+ytot)<totvotneeded || xused>xtot || yused>ytot){
            cout<<"NO\n";
            continue;
        }

        long long extA=xtot-xused,extB=ytot-yused;

        if( (extA>0 && !awon) || ( extB>0 && !bwon) ){
            cout<<"NO\n";
        }
        else{
            cout<<"YES\n";
        }




    }

    return 0;
}