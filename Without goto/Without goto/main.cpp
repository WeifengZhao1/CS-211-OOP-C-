#include <iostream>
#include <cmath>
using namespace std;

bool ok(int q[], int c){
    for (int i = 0; i < c; i++){
        if((q[i]==q[c])|| (abs(q[c]-q[i]))==c-i) return false;
    }
    return true;
}

void backtrack(int &c){
    c--;
    if (c < 0) exit(0);
}

void print(int q[]){
    for(int r=0;r<8;r++){
        for(int c=0;c<8;c++){
            if(q[r]==c){
                cout<<1 << " ";
            } else {
                cout<<0 << " ";
            }
        }
        cout<<endl;
    }
}
int main(){
    int q[8], c = 0;
    int count = 0;
    q[0] = 0;
    
    while (c < 8){
        c++;
        if (c == 8){
            count++;
            cout << endl << "This is solution: " << count << endl;
            print(q);
            c--;
        }
        else {
            q[c] = -1;
        }
        
        while (c < 8){
            q[c]++;
            if (q[c] == 8){
                backtrack(c);
            }
            else{
                if (ok(q, c)) break;
            }
        }
    }
}





