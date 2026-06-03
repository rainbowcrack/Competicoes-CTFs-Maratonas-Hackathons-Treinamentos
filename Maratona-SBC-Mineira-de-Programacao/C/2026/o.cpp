#include <iostream>

using namespace std;
using ll = long long;

const ll MOD = 1000000007LL;

// f(x) = ax + b
// f(x) = ax + b + num in case sum
// f(x) = (ax * mul) + (b * mul) in case mul

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll ans, N;
	cin >> N;

	ll sum = 0;
	ll mul = 1;

	for(int i = 0; i < N; i++){
		char s;
		ll num;

		cin >> s >> num;

		if(s == '+'){
			sum = (sum + num) % MOD;

		}
		else if(s == '*'){
			mul = (mul * num) % MOD;
			sum = (sum * num) % MOD;
		
		}
		else{
			ans = (mul * num + sum) % MOD;
			cout << ans << '\n';
		
		}
	}

}
