#include <iostream>
#include <cmath>
using namespace std;

int main () {
    int q[8],c=0;
    int count = 0;
    q[0]= 0;
    
nc: c++;
    if (c==8) goto print;
    q[c] = -1;
    
nr: q[c]++;
    if(q[c]==8) goto backtrack;
    
    // row test
    for (int i=0;i<c;i++){
        if((q[i]==q[c])|| (abs(q[c]-q[i]))==c-i) goto nr;
    }
    goto nc;
    
backtrack: c--;
    if (c==-1) return 0;
    goto nr;
    
print: for(int r=0;r<8;r++){
    for(int c=0;c<8;c++){
        if(q[r]==c){
            cout<<1 << " ";
        } else {
            cout<<0 << " ";
        }
    }
    cout<<endl;
}
    count++;
    cout<<"This is solution "<< count <<endl;
    cout << endl;
    goto backtrack;
}
