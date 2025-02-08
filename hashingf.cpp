/* Following program is a C++ implementation of Rabin Karp
Algorithm given in the CLRS book */
#include <bits/stdc++.h>
using namespace std;

// d is the number of characters in the input alphabet
#define d 256

/* pat -> pattern
	s -> text
	q -> A prime number
*/
void checkpat(string pat,string s, long long q)
{
	long long m =  pat.length();
	long long n =   s.length();
	long long i, j;
	long long p = 0; // hash value for pattern
	long long t = 0; // hash value for s
	long long h = 1;

	// The value of h would be "pow(d, M-1)%q"
	for (i = 0; i < m - 1; i++)
		h = (h * d) % q;

	// Calculate the hash value of pattern and first
	// window of text
	for (i = 0; i < m; i++) {
		p = (d * p + pat[i]) % q;
		t = (d * t + s[i]) % q;
	}

	// Slide the pattern over text one by one
	for (i = 0; i <= n - m; i++) {

		// Check the hash values of current window of text
		// and pattern. If the hash values match then only
		// check for characters one by one
		if (p == t) {
			/* Check for characters one by one */
			for (j = 0; j < m; j++) {
				if (s[i + j] != pat[j]) {
					break;
				}
			}

			// if p == t and pat[0...m-1] = s[i, i+1,
			// ...i+m-1]

			if (j == m)
				cout << "Pattern found at index " << i
					<< endl;
		}

		// Calculate hash value for next window of text:
		// Remove leading digit, add trailing digit
		if (i < n - m) {
			t = (d * (t - s[i] * h) + s[i + m]) % q;

			// We might get negative value of t, converting
			// it to positive
			if (t < 0)
				t = (t + q);
		}
	}
}

/* Driver code */
int main()
{
	  string s = "chandansinghkoranga";
	 string pat = "singh";

	// we mod to avoid overflowing of value but we should
	// take as big q as possible to avoid the collison
	int q = INT_MAX;

	// Function Call
	checkpat(pat, s, q);
	return 0;
}

// This is code is contributed by rathbhupendra
