#include <iostream>
using namespace std;

int main () {
    for (int i = 1;i>0;i++){
        unsigned int k = i*i;
        
            if (((k%10)/2==0) && (((k/10)%10)/2==0)){
            break;
        }
        cout << k << endl;
    }
    cout << "This number does not exist" << endl;
    //This number does not exist.
    return 0;
}



