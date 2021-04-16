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

void print(int q[]) {
    int i, j, k, l;
    typedef char box[5][7];
    box bb, wb, *board[8][8];
    
    for (i=0; i<5; i++)
    for (j=0; j<7; j++) {
        wb[i][j] = ' ';
        bb[i][j] = char(219);
    }
    
    static box bq = { {char(219),char(219),char(219),char(219),char(219),char(219),char(219)},
        {char(219),' '      ,char(219),' '      ,char(219),' '      ,char(219)},
        {char(219),' '      ,' '      ,' '      ,' '      ,' '      ,char(219)},
        {char(219),' '      ,' '      ,' '      ,' '      ,' '      ,char(219)},
        {char(219),char(219),char(219),char(219),char(219),char(219),char(219)} };
    
    static box wq = { {' '      ,' '      ,' '      ,' '      ,' '      ,' '      ,' '      },
        {' '      ,char(219),' '      ,char(219),' '      ,char(219),' '      },
        {' '      ,char(219),char(219),char(219),char(219),char(219),' '      },
        {' '      ,char(219),char(219),char(219),char(219),char(219),' '      },
        {' '      ,' '      ,' '      ,' '      ,' '      ,' '      ,' '      } };
    
    for(i=0; i<8; i++)
    for(j=0; j<8; j++)
    if((i+j)%2 == 0)
    board[i][j] = &wb;
    else
    board[i][j] = &bb;
    
    for(i=0;i<8;i++){
        if(board[q[i]][i]==&wb)
        board[q[i]][i]= &wq;
        else
        board[q[i]][i]=&bq;
    }
    
    cout << " ";
    for (i=0; i<7*8; i++)
    cout << '_';
    cout << endl;
    
    for (i=0; i<8; i++)
    for (k=0; k<5; k++) {
        cout << " " <<char(179);
        for (j=0; j<8; j++)
        for (l=0; l<7; l++)
  
        cout << (*board[i][j])[k][l];
        cout << char(179);
    }
    
    cout << " ";
    for (i=0; i<7*8; i++)
    cout << char(196);
    cout << endl;
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
