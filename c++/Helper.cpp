#include <cmath>
#include <sstream>
#include <string>
#include <stack>
#include "Helper.h"
using namespace std;

string Helper::convertInt(int number) {
    stringstream ss;
    ss << number;
    return ss.str();
}

long long Helper::convertStr(string str) {
    stringstream ss;
    long long newint;
    ss << str;
    ss >> newint;
    return newint;
}

int Helper::numDigits(int num) {
    int digits = 0;
    if(num < 0)
        num = -num;
    while(num > 0) {
        digits++;
        num /= 10;
    }
    return digits;
}

int Helper::concat(int ary[], int size) {
    int answer = ary[size-1];
    for(int i = size-2; i >= 0; i--)
        answer += (ary[i] * pow((double)10, numDigits(answer)));
    return answer;
}

int Helper::factorial(int num) {
    if (num > 1)
        return (num * factorial(num - 1));
    else
        return 1;
}

int* Helper::reduce(int* frac) {
    for(int i = *(frac+1); i > 0; i--) {
        if(*frac % i == 0 && *(frac+1) % i == 0) {
            *frac /= i;
            *(frac+1) /= i;
            return frac;
        }
    }
    return 0;
}

int Helper::sumOfDivs(int num) {
    int sum = 0;
    int root = (int) sqrt((double)num);
    for(int i = root; i >= 1; i--) {
        if(num % i == 0) {
            if(i > 1 && (i * i != num))
                sum += i + (num / i);
            else
                sum += i;
        }
    }
    return sum;
}

bool Helper::isPrime(int num) {
    if(num == 2)
        return true;
    if(num % 2 == 0 || num < 2)
        return false;
    int root = (int) sqrt((double)num) + 1;
    for(int i = root; i >= 2; i--) {
        if (num % i == 0)
            return false;
    }
    return true;
}

bool Helper::isPandigital(int num, int digit) {
    int sum = 0;
    int ary[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    //zero the digits we're not checking
    for(int i = digit; i < 9; i++)
        ary[i] = 0;
    //find digits in num
    for(int i = 0; num > 0; i++, num /= 10)
        ary[(num % 10)- 1] = 0;
    //check if all array slots are 0
    for(int i = 0; i < 9; i++)
        sum += ary[i];
    if(sum == 0)
        return true;
    else
        return false;
}

bool Helper::isPalindrome(string str) {
    stack<char> numStack;
    unsigned int j;
	if(str.length() < 1)
		return false;
	else if(str.length() == 1)
		return true;
    else if(str.length() % 2 == 0) {
        for(unsigned int i = 0; i <= ((str.length() - 1) / 2); i++) 
            numStack.push(str.at(i));
        j = str.length() / 2;
    } else {
        for(unsigned int i = 0; i <= ((str.length() - 2) / 2); i++)
            numStack.push(str.at(i));
        j = (str.length() / 2) + 1;
    }
    for( ; j < str.length(); j++) {
        if(numStack.top() != str.at(j))
            return false;
        numStack.pop();
    }
    return true;
}
