#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> a={0,4,2,1,3};


    int steps=0;
    for(int i=0;i<a.size();i++){
        for(int j=i+1;j<a.size();j++){
            if(a[i]>a[j]){
                swap(a[i],a[j]);
                steps++;
            }
        }
    }
    cout<<steps<<endl;

    return 0;
}