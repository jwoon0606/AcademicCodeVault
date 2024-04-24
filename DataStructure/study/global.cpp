#include <iostream>

namespace Space_A{
    int num = 20;
    int get_num(int n){
        return n+1;
    }
}

using namespace std;
using namespace Space_A;

int num(30);

int main(){
    int num = 10;
    cout << "main: " << num << endl;
    cout << "Global: " << ::num << endl;    // How to use global variable
    cout << "Space_A: " << Space_A::get_num(100) << endl;
    return 0;
}
