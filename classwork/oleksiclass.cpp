#include <iostream>

unsigned long int factorial(int n, int i){
 
 
 unsigned long int result = 1;
 
 for (i++; i <= n; i++ ){
  result = result * i;
 }
 

 return result;
}


unsigned long int formulabin(int n, int k){
 
 unsigned long int f_result = 0;
 
 int f = n - k;
 
 if (k >= f){
  f_result = factorial(n, k) / factorial(f, 0);
  
 }

 else if (k < f) {
  f_result = factorial(n, f) / factorial(k, 0);

 }



return f_result;
}


int main(){
 int n ;
 int k ;
 
 std::cout << "n = ";
 std::cin >> n;
 std::cout << "k = ";
 std::cin >> k;

 std::cout << formulabin(n, k) <<std::endl;
 
 
 
return 0;
}