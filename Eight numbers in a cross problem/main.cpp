#include <iostream>
#include <cmath>
using namespace std;

bool ok(int q[],int c,int helper[][5]){
    for (int i = 0;i<c;i++)
        if (q[c]==q[i]) return false;
    
        for (int i = 0;i<5;i++){
            if (helper[c][i] ==-1) return true;
            if(abs(q[c]-q[helper[c][i]])==1) return false;
    }
    return true;
}
void print(int q[]){
                   for(int i=0; i<8; i++){
                       cout<<q[i] << " ";
                   }
                   cout<<endl;
                   cout << endl;
               }
int main () {
    int q[8], c = 0;
    int count = 0;
    int helper [8][5] = {
                        {-1,-1,-1,-1,-1},
                        {0,-1,-1,-1,-1},
                        {1,-1,-1,-1-1},
                        {0,1,2,-1,-1},
                        {1,2,3,-1,-1},
                        {2,4,-1,-1,-1},
                        {0,3,4,-1,-1},
                        {3,4,5,6,-1}
                        };
    
    q[c] =1;   
    while(c<8){
        if(c==7){
            count++;
            cout<< "This is solution: " << count << endl;
            print(q);
            c--;
        }
        else q[++c]=0;
        while(q[c]<9){
            q[c]++;
            if(q[c]==9)
                c--;
            else if(ok(q,c,helper))
                break;
        }
    }
    return 0;
}

    

