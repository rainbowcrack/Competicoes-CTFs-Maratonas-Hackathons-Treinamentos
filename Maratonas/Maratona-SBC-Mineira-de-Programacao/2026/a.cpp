#include <iostream>

using ll = long long;
using namespace std;

int main(){
	
	int X; cin >> X; 
	ll sum = 0;

	for(int i = 1; i <= X; i++){
	
		sum += i + 2;
	}

	cout << sum << '\n';

}
