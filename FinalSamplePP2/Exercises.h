#pragma once
#include <iostream>
using namespace std;

//EX2 (a)
int	Fibonacci(int a,int b,int n) {
	if (n == 1) return a;
	if (n == 2) return b;
	if (n > 2) return Fibonacci(a, b, n - 1) + Fibonacci(a, b, n - 2);
	

}
int sum(int n) {
	if (n == 1) return 1;
	if (n > 1) return n + sum(n - 1);
}