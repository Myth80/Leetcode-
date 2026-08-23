class Solution {
public:
    bool checkDivisibility(int n) {
        int digsum =0;
        int digprod=1;
        int orig = n;
        int digit=0;
        while(orig!=0){
            digit = orig % 10;
            digsum = digsum + digit;
            digprod = digprod * digit;
            orig = orig /10;
        }
        if(n % (digsum + digprod)==0){
            return true;
        }else{
            return false;
        }

    }
};