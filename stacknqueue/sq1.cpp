#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;


class circQueue{

    private:
    int*arr;
    int start;
    int end;
    int crtsize;
    int limit;

    public:
    circQueue(int len){
        limit=len;
        arr=new int[len];
        start=-1;
        end=-1;
        crtsize=0;

    }
    void push(int val){
        if(crtsize==0){
            start=0;
            end=0;
            crtsize++;
            this->arr[start]=val;
        }
        else if(crtsize==limit){
            cout<<"Overflow\n";
        }
        else{
            end=(end+1)%(this->limit);
            this->arr[end]=val;
            crtsize++;
        }
    }
    void pop(){
        if(crtsize==0){
            cout<<"Empty queue\n";
        }
        else if(crtsize==1){
            start=-1;
            end=-1;
            crtsize=0;
        }
        else{
            start=(start+1)%limit;
            crtsize--;
        }
    }
    void top(){
        if(crtsize==0){
            cout<<"Empty queue\n";
        }
        else{
            cout<<this->arr[start]<<"\n";
        }
    }
    void size(){
        cout<<crtsize<<"\n";
    }

};


class arrStack{
    private:
    int* arr;
    int ind;
    int limit;

    public:

    arrStack(int len){
        arr = new int[len];
        ind = -1;
        limit = len;
    }
    void push(int val){
        if(ind + 1 >= limit){
            cout<<"Overflow\n";
            return;
        }
        this->arr[(this->ind)+1] = val;
        ind++;
    }
    void pop(){
        if(ind < 0){
            cout<<"Empty stack\n";
            return;
        }
        ind--;
    }
    void top(){
        if(ind < 0){
            cout<<"Empty stack\n";
        }
        else{
            cout<<this->arr[this->ind]<<"\n";
        }
    }
    void size(){
        cout << (this->ind) + 1 << "\n";
    }
    void show(){
        for(int x=0;x<=this->ind; x++){
            cout<<this->arr[x]<<' ';
        }
        cout << '\n';
    }
};


int main(){

    /*
    STACKS - LIFO (Last In First Out)
    Functions-Push,Pop,Top,Size

    QUEUE - FIFO (First In First Out)
    Functions-Push,Pop,Top,Size
    
    */

    // Implementing stack using arrays
    stack<int>sarr;
    auto st =arrStack(5);
    st.push(5);
    st.push(7);
    st.size();
    st.show();
    st.pop();
    st.show();

    cout<<endl;
    // Implementing queue using arrays
    circQueue qarr(5);
    qarr.push(10);
    qarr.push(20);
    qarr.push(30);
    qarr.push(40);
    qarr.push(50);
    qarr.top();
    qarr.size();
    qarr.pop();
    qarr.top();
    qarr.size();
    qarr.push(60);
    qarr.push(70);
    qarr.size();
    qarr.top();

    return 0;

}