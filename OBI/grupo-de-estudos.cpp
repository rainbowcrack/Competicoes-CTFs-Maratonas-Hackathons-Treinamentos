#include <bits/stdc++.h>

using namespace std;

int main(){
    int N;
    cin >> N;
    
    set<int> grupos;
    
    // pega elementos unicos no grupo com SET
    for(int i = 0; i < N; i++){
        int num;
        cin >> num;
        grupos.insert(num);
    }
    
    cout << grupos.size() << endl;
    
    return 0;
}
