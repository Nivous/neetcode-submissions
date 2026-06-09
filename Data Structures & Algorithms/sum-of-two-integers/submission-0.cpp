class Solution {
public:
    int getSum(int a, int b) {
        int and_res = (a & b) << 1;
        int xor_res = a ^ b;
        if ((and_res & xor_res) == 0)
            return and_res | xor_res;
        else
            return getSum(and_res, xor_res);

        
    }
};
