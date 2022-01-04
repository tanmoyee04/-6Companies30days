/*  Given an unsorted array Arr of size N of positive integers. One number 'A' from set {1, 2, …N} is missing and one number 'B' occurs twice in array. Find these two numbers. */



// there are multiple methods by which we can solve this question.
        // Method-1: sorting
        // Method-2: Hashing-> The index in the hash table which will be having 0 will be the missing value and index with >1 will be the repeating value.
        // Method-3: Negation of index-> This will modify the array which is not acceptable
        // Method-4: 1+2+3+4+....+n = n*(n+1)/2 = S
        // 1^2 + 2^2 + 3^2 +.....+ n^2 = n*(n+1)*(2n+1)/6 = S^2
        // S - (sum of all the digits of the given number) = X - Y; where X is the missing value and Y is the repeating value
        // Similarly we will get X^2 - Y^2 = S^2 - (sum of squares of all the digits of the no.)
        // Solve the two equations 
        
        // Most optimal approach: use XOR property: Initialize XOR as 0 and traverse through the array and keep on XORing each element
        // Step-1: XOR all arr[i] -> x
        // Step-2: x ^ (1^2^3^...^n)
        // Step-3: x^y = n
        // Step-4: separate into two buckets
        // Step-5: separate (1...n) in two buckets
        // Step-6: XOR both the buckets to fing the number
        
        /* Will hold xor of all elements and numbers from 1 to n */
    int xor1;

    /* Will have only single set bit of xor1 */
    int set_bit_no;

    int i;
    int x = 0; // missing
    int y = 0; // repeated
    int n = arr.size();

    xor1 = arr[0];

    /* Get the xor of all array elements */
    for (i = 1; i < n; i++)
        xor1 = xor1 ^ arr[i];

    /* XOR the previous result with numbers from 1 to n */
    for (i = 1; i <= n; i++)
        xor1 = xor1 ^ i;

    /* Get the rightmost set bit in set_bit_no */
    set_bit_no = xor1 & ~(xor1 - 1);

    /* Now divide elements into two sets by comparing a rightmost set bit
       of xor1 with the bit at the same position in each element.
       Also, get XORs of two sets. The two XORs are the output elements.
       The following two for loops serve the purpose */

    for (i = 0; i < n; i++) {
        if (arr[i] & set_bit_no)
            /* arr[i] belongs to first set */
            x = x ^ arr[i];

        else
            /* arr[i] belongs to second set */
            y = y ^ arr[i];
    }

    for (i = 1; i <= n; i++) {
        if (i & set_bit_no)
            /* i belongs to first set */
            x = x ^ i;

        else
            /* i belongs to second set */
            y = y ^ i;
    }

    // NB! numbers can be swapped, maybe do a check ?
    int x_count = 0;
    for (int i=0; i<n; i++) {
        if (arr[i]==x)
            x_count++;
    }
    
    if (x_count==0)
        return {y, x};
    
    return {x, y};
    }
