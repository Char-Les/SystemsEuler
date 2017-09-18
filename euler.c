#include <stdio.h>
#include <math.h>
//Charles Weng
//Systems Period 4
//HW2 -- If you're feeling rust, apply eul.
//2017-9-15

//sum of multiples of 3 or 5 up to 1000
int problem1(){
	//set up variables; one for sum; one for the number we're checking
	int sum = 0;
	int a = 1;
	//loop through all the numbers
	for(;a < 1000; ++a){
		if(a % 3 == 0 || a % 5 == 0)
		sum += a;
	}
	return sum;
}

//sum of even fib numbers up to 4 mil
int problem2(){
	//set up variables; one for sum (answer); three for keeping track of the fib sequence
	//i can't add fibH to fib and set it as fib at the same time
	int sum = 0;
	int fib = 1;
	int fibH = 0;
	int fibH2 = 0;
	//loop through
	for(;fib < 4000000; fib = fibH + fibH2){
		//check if fib is even
		if (fib % 2 == 0)
		sum += fib;
		fibH2 = fibH;
		fibH = fib;
	}
	return sum;
}

//find largest prime factor
int problem3(){
	//idk why but long wouldn't work for me()
	//blame this error: overflow in implicit constant conversion [-Woverflow]
	//consequently i needed the function fmod from <math.h> to help mod the numbers
	long number = 600851475143;
	int factor = 2;
	int biggest = 1;
	//keep dividing until it's 1
	while (number != 1){
		//check if the factor can divide the number
		if(number % factor == 0){
			//printf("%d / %d\n", number, factor);
			//check if biggest is the biggest factor so far
			if(biggest < factor){
				biggest = factor;
			}
			//reset factor and take it out
			number /= factor;
			factor = 2;
		}
		factor ++;
	}
	return biggest;
}

//atempt
//idk why it's not matching up at 10^6, but it does at the begining of the sequence :/
int sumDigits();
int problem551(){
	int sumdigits = 1;
	int i = 2;
	for(;i <= 1000000; i++){
		sumdigits += sumDigits(sumdigits);
	}
	return sumdigits;
}
int sumDigits(int x){
	int ans = 0;
	while(x > 10){
		ans += x % 10;
		x /= 10;
	}
	return ans + x;
}


int main(){
	printf("problem 1: %d\nproblem 2: %d\nproblem 3: %d\nproblem 551(attempt): %d\n", problem1(), problem2(), problem3(), problem551());
	return 1;
}
