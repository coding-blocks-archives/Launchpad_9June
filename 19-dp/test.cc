#include <bits/stdc++.h>
using namespace std;
class X
{
public:
    int val;
    X(){
        val = 123;
    }

    friend ostream& operator<<(ostream& printer, X &obj){
        printer << obj.val;
        return printer;
    }
};

int main() {
    // std::vector<std::auto_ptr<X> > vecX;
    // vecX.push_back(auto_ptr<X>(new X));
    // cout << *vecX[0] << " " << endl;
    // std::auto_ptr<X> pX = vecX[0];  // vecX[0] is assigned NULL.
    // cout << *vecX[0] << " ";
    // shared_ptr<int> p = nullptr;
    int *p = new int;
    p = nullptr;
    delete p;
}