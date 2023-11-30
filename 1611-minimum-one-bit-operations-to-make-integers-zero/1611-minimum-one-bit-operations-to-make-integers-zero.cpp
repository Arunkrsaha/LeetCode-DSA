class Solution {
public:
    int minimumOneBitOperations(int n) {
        if(n <= 1) return n;
        /*
        1 -> 0: 1
        10 -> 11 -> 01 -> ... : 2+1=3
        100 -> 101 -> 111 -> 110 -> 010: 4+2+1=7
        1000 -> 1001 -> 1011 -> 1010 -> 1110 -> 1111 -> 1101 -> 1100 -> 0100: 8+4+2+1=15
        turn 1<<n to 0 needs (1<<(n+1))-1
        */
        
        int bit = 0;
        while(1<<bit <= n){
            ++bit;
        }
        --bit;
        
        /*
        for n = 1000, 1<<bit = 1000
        for n = 1110, 1<<bit = 1000
        
        f(1000) = f(1110) + f(0110)
        f(1110) = f(1000) - f(0110)
        */
        
        //process the MSB first: from 0 to 1<<bit: (1<<bit+1)-1
        //then recursively process later bits
        return ((1<<bit+1)-1) - minimumOneBitOperations(n-(1<<bit));
    }
};