#include <iostream>
using namespace std;

bool equivlaent (int a[],int b[],int n) {
    for (int i = 0; i<n;i++){
        for (int j =0;j<n;j++){
            if (a[i]==b[j]){
                return true;
            }
        }
    }
    return false;
}


int main () {
    int a[5] = {1,2,3,4,5};
    int b[5] = {3,4,5,1,2};
    if (equivlaent (a,b,5))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}
