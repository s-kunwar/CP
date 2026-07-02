#include <iostream>
#include <vector>

using namespace std;


int main(){

    int t;
    cin>>t;

    while(t--){

        int n,k,x;
        cin>>n>>k>>x;

        if(x!=1){
            cout<<"YES\n";
            cout<<n<<endl;
            while(n--) cout<<1<<" ";
            cout<<endl;
            continue;
        }
        else if(x==1 && k==1) cout<<"NO\n";
        else{
            
            //cant use one
            if(n%2==0){
                cout<<"YES\n"<<n/2<<endl;
                for(int i=1;i<=n/2;i++) cout<<2<<' ';
                cout<<endl;
            }   

            //531
            else{
                if(k==2) cout<<"NO\n";
                else{
                    cout<<"YES\n"<<n/2<<endl;
                    for(int i=1;i<=(n/2-1);i++) cout<<2<<' ';
                    cout<<3<<endl;
                }
            }

        }
    

    }
    

    return 0;
}