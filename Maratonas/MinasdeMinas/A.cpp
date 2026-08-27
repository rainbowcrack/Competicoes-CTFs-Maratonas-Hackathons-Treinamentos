#include <iostream>
using namespace std;

int main()
{
    int C, P;
    int value;
    
    cin >> C >> P;
    
    value = P/C; // aredonda
    
    value >= 2? value = 1 : value = 0;
    
    cout << value << endl;

    return 0;
}
