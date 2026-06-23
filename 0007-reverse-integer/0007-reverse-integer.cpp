class Solution {
public:
    int reverse(int x) {
        int cpy = x;
        int num=0;
        while(cpy !=0){
            int digit = cpy % 10;
             if (num > INT_MAX / 10 || 
               (num == INT_MAX / 10 && digit > 7))
                return 0;

            if (num < INT_MIN / 10 || 
               (num == INT_MIN / 10 && digit < -8))
                return 0;
            num = num*10 + digit; 
            cpy = cpy /10;
        }
        return num;
    }
};