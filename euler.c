#include <stdio.h>
//Charles Weng
//Systems Period 4
//HW2 -- If you're feeling rust, apply eul.
//2017-9-15

int problem1(){
  int sum = 0;
  int a = 1;
  for(;a < 1000; ++a){
    if(a % 3 == 0 || a % 5 == 0)
      sum += a;
  }
}

int main(){
  printf(problem1());
  return 1;
}
