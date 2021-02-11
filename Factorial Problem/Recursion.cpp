#include <iostream>
using namespace std;
int fact(int n){
    if(n==1){
        return n;
    }
    else{
        int r=n*fact(n-1);
        //cout<<endl<<n<<" "<<(n-1)<<":"<<r;
        return r;
    }
}
int main(){
    int n;
    cin>>n;
    int r=fact(n);
    cout<<endl<<r;
    return 0;
}

/*output:
>>>4

24

*/
