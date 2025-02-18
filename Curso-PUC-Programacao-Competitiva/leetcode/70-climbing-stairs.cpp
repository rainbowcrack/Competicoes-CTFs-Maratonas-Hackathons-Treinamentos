class Solution {
public:
    int climbStairs(int n) {
        int a = 1;
        int b = 1;
        int prox;

        if(n == 1){
            return 1;
            
        } else{
            for(int i = 2; i <= n; i++){

            prox = a + b;
            a = b;
            b = prox;
            }
        }
        
        return prox;
    }
};
