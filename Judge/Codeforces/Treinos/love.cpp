# include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
 
	ll n;
	cin >> n;
 
	vector<int> love(n +1); // segmentfault
 
	for(int i = 1; i <= n; i++){
	
		cin >> love[i];
	}
 
	for(int i = 1; i <= n; i++){
	
		int a = i;
		int b = love[a];
		int c = love[b];
 
		if(love[c] == a){
		
			cout << "YES" << endl;
			return 0;
		}
	}
 
	cout << "NO" << endl;
 
 
	return 0;
}
