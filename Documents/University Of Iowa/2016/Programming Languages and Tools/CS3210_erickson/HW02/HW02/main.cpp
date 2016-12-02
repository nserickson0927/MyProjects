/*Homework 2-Math*/
//Nicholas Erickson
//CS3210

#include <iostream>

using namespace std;

//function for adding
int add(int a, int b){
 return a+b; 
}

//function for subtracting
int sub(int a, int b){
 return a-b; 
}

//function for multiplying
int mult(int a, int b){
 return a*b;
}

//function for dividing
int divide(int a, int b){
 return a/b;
}

//function to find the greatest Common Divisor
int gcd(int a, int b){
 return b==0 ? a : gcd(b, a%b);
}

//function for finding the Factorial
int fact(int a){
 return (a==1 ? a : a*fact(a-1));
}
//function for finding the square root
int square(int a){
 int x1=a/2;
 int x2=2;
 
 while(std::abs(x2-x1)>1){
  x2=(x1+x2)/2;
  x1=a/x2;
 }
 return x1;
}

int main(int argc, char **argv) {
  bool z=true;
  //start loop, won't exit loop until that option is selected
  while(z==true){
    int A;
    std::cout<<"Please enter integer A: ";
    std::cin>>A;
    
    if (A<1){
     std::cout<<"Please enter an integer greater than 0"<<std::endl;
     std::cin>>A;
    }
    
    int B;
    std::cout<<"Please enter integer B: ";
    std::cin>>B;
    
    if (B<1){
     std::cout<<"Please enter an integer greater than 0"<<std::endl;
     std::cin>>B;
    }
    
    int operation;
    std::cout<<"Please select an operation to run:"<< std::endl
             <<"1. Arithmetic"<< std::endl
             <<"2. GCD"<<std::endl
             <<"3. Factorial"<<std::endl
             <<"4. Square Root"<<std::endl
             <<"5. Exit"<<std::endl;
    
    std::cin>>operation;
    
    if (operation>5 or operation<1) {
      std::cout<<"Error: the number you entered is invalid!"<<std::endl
	       <<"Please enter an integer from 1 to 5."<<std::endl;
      std::cin>>operation;
    }
    
    
    switch(operation){
      case 1:
	std::cout<<"Arithmetic"<<std::endl;
	std::cout<<"Addition="<<add(A,B)<<std::endl
		 <<"Subtraction="<<sub(A,B)<<std::endl
		 <<"Multiplication="<<mult(A,B)<<std::endl
		 <<"Division="<<divide(A,B)<<std::endl;
	break;
      case 2:
	std::cout<<"Greatest Common Divisor"<<std::endl;
	std::cout<<"The GCD is: "<<gcd(A,B)<<std::endl;
	break;
      case 3:
	std::cout<<"Factorial"<<std::endl;
	std::cout<<"The factorial of "<< A <<" is "<<fact(A)<<std::endl;
	std::cout<<"The factorial of "<< B <<" is "<<fact(B)<<std::endl;
	break;
      case 4:
	std::cout<<"Square Root"<<std::endl;
	std::cout<<"The estimated square root of "<< A << " is "<<square(A)<<std::endl;
	std::cout<<"The estimated square root of "<< B << " is "<<square(B)<<std::endl;
	break;
      case 5:
	std::cout<<"Goodbye"<<std::endl;
	z=false;
    }
    //break;
  }
  
  
  
  
  return 0;
}
