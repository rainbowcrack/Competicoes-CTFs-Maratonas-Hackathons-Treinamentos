#include <iostream>
using namespace std;

int main(){
	int D, M;
	cin >> D >> M;

	if(D <= 12 && M <= 12 && D != M){
		cout << "DATA INCERTA" << '\n'; 
	}
	else{
		cout << "DATA SEGURA" << '\n';
	}

}
