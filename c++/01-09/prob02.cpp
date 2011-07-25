/* URL: http://projecteuler.net/index.php?section=problems&id=2

Each new term in the Fibonacci sequence is generated by adding the previous two terms. By starting with 1 and 2, the first 10 terms will be:

1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...

By considering the terms in the Fibonacci sequence whose values do not exceed four million, find the sum of the even-valued terms.

Answer: 4613732 */

#include <iostream>
using namespace std;

int main() {
    int answer = 2;
    int a = 1;
    int b = 2;
    int c = a + b;
    while(c < 4000000) {
        if (c % 2 == 0)
            answer += c;
        a = b;
        b = c;
        c = a + b;     
    }
    cout << answer << endl;
    return 0;
}

