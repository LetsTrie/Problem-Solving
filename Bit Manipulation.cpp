// x ^ x = 0, x ^ x ^ x = x 
// Problem: https://www.hackerrank.com/challenges/one-month-preparation-kit-lonely-integer/problem

// Flip one bit: num ^= (1 << i); // flip i'th bit
// Flip all bits in 32 bit number: for(int i = 0; i < 32; i++) num ^= (1 << i)
// Problem: https://www.hackerrank.com/challenges/one-month-preparation-kit-flipping-bits/problem

// most_significant_bit: 1 << count_bits(n)
int count_bits (int n) {
   int count = 0;
   while (n) {
        count++;
        n >>= 1;
    }
    return count;
    // log2(n) + 1
}

bool is_power_of_two(int x) {
    return x && (!(x & (x - 1)));
}

// n & (n-1) == 0 [power of two]

// n = n & (n-1) [Removes last 1 everytime. Can be useful for finding "number of 1" in n.]

// __builtin_popcount(n) - number of 1 in "n".. __builtin_popcount(4) == 1
// for long (__builtin_popcountl(x)) and for long long (__builtin_popcountll(x))
// power of two

// __builtin_parity(n) - if "number of 1" is even, return 0 otherwise 1

// __builtin_clz(n) - #leading_zero

// __builtin_ctz(x) - #trailing_zero
// Problem: https://leetcode.com/problems/power-of-four
