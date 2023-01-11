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
