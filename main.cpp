#include <iostream>
#include <cmath>
using namespace std;

class Rat{
private:
    int n;
    int d;
    
public:
    //Default constructor
    Rat(){
        n=0;
        d=1;
    }
    
    // 2 parameter constructor
    Rat(int i, int j){
        n=i;
        d=j;
    }
    
    // conversion constructor
    Rat(int i){
        n=i;
        d=1;
    }
    
    //accessor functions
    int getN(){ return n;}
    int getD(){ return d;}
    
    void setN(int i){ n=i;}
    void setD(int i){ d=i;}
    
    //arithmetic operators
    Rat operator+(Rat r){
        Rat t;
        t.n = n*r.d + d*r.n;
        t.d = d*r.d;
        t.reduce();
        return t;
    }
    
    Rat operator-(Rat r){
        Rat t;
        t.n = n*r.d - d*r.n;
        t.d = d*r.d;
        t.reduce();
        return t;
    }
    
    Rat operator*(Rat r){
        Rat t;
        t.n = n*r.n;
        t.d = d*r.d;
        t.reduce();
        return t;
    }
    
    Rat operator/(Rat r){
        Rat t;
        t.n = n*r.d;
        t.d = d*r.n;
        t.reduce();
        return t;
    }
    
    // Reduce the Rat to lowest terms
    void reduce(){
        int gcd_ = gcd(n, d);
        n /= gcd_;
        d /= gcd_;
        if (d < 0) {
            d = -d;
            n = -n;
        }
    }
    
    // Calculate the GCD (Euclid's algorithm)
    int gcd(int n, int d){
        return d == 0 ? n : gcd(d, n%d);
    }
    
    // 2 overloaded i/o operators
    friend ostream& operator<<(ostream& os, Rat r);
    friend istream& operator>>(istream& is, Rat& r);
};


ostream& operator<<(ostream& os, Rat r){
    r.reduce();
    if (abs(r.n) >= r.d || r.n == 0)
        os << r.n/r.d << " ";
    if (r.d != 1)
        os << (r.n/r.d <= -1 ? abs(r.n%r.d) : r.n%r.d) << "/" << r.d;
    return os;
}


istream& operator>>(istream& is, Rat& r){
    is >> r.n >> r.d;
    r.reduce();
    return is;
}

int main() {
    Rat r1(5, 2), r2(3, 2);
    
    cout << "r1: " << r1 << endl;
    cout << "r2: " << r2 << endl;
    cout << "r1 + r2: " << r1 + r2 << endl;
    cout << "r1 - r2: " << r1 - r2 << endl;
    cout << "r1 * r2: " << r1 * r2 << endl;
    cout << "r1 / r2: " << r1 / r2 << endl;
    cout << endl;
    
    r1 = r2;
    r2 = r1 * r2;
    
    cout << "r1: " << r1 << endl;
    cout << "r2: " << r2 << endl;
    cout << "r1 + r2: " << r1 + r2 << endl;
    cout << "r1 - r2: " << r1 - r2 << endl;
    cout << "r1 * r2: " << r1 * r2 << endl;
    cout << "r1 / r2: " << r1 / r2 << endl;
    cout << endl;
    
    r1 = r2 + r1 * r2 / r1;
    r2 = r2 + r1 * r2 / r1;
    
    cout << "r1: " << r1 << endl;
    cout << "r2: " << r2 << endl;
    cout << "r1 + r2: " << r1 + r2 << endl;
    cout << "r1 - r2: " << r1 - r2 << endl;
    cout << "r1 * r2: " << r1 * r2 << endl;
    cout << "r1 / r2: " << r1 / r2 << endl;
    
    return 0;
}
