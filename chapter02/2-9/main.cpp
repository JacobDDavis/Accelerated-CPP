#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {
    cout << "Please enter a number: ";
    int a;
    cin >> a;
    
    cout << "Please enter another number: ";
    int b;
    cin >> b;

    cout << endl;
    
    int larger = a;
    if (larger < b)
        larger = b;
    
    cout << "larger number: " << larger << endl;
    
    return 0;
}



