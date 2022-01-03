/*  Ugly numbers are numbers whose only prime factors are 2, 3 or 5. The sequence 1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15, … shows the first 11 ugly numbers. By convention, 1 is included. Write a program to find Nth Ugly Number. */

class Solution{
public:	
	// #define ull unsigned long long
	/* Function to get the nth ugly number*/
	ull getNthUglyNo(int n) {
	    //If u = 2^a * 3^b * 5^c is an ugly no. then 2*u, 3*u and 5*u will also be ugly nos.
	    // The smallest ugly no. is 1 since ugly nos are positive.
	    //We will fix the smallest no among the possible ugly nos and further perform the same task
	    // Thus we need to solve this using Dynamic Programming
	    unsigned long long ar[n];
        ar[0]=1;        
        unsigned long long a=0,b=0,c=0,i=1;
        while(i<n)
        {
            ar[i]=min({ar[a]*2,ar[b]*3,ar[c]*5});
            if(ar[i]==ar[a]*2)
                a++;
            if(ar[i]==ar[b]*3)
                b++;
            if(ar[i]==ar[c]*5)
                c++;
            i++;
        }
        return ar[n-1];
	}
};
