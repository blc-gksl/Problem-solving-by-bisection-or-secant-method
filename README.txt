With taking initial guesses,tolerance value and coefficients of a function this code solves the function  if there is one, and write its value and also when doing that
it uses bisection and secant method and show how many iteration is needed. Also there is a hybrid method that consists of bisection and secant methods

The code take inputs from commend line arguments =>
First and second commend line arguments is the low initial value and high initial value respectively
The third commend line argument is the tolerans value 
The other inputs should be coefficients of the function, with starting from leftmost side(when writing the function)
Not: write coefficient even if it is zero

If there is any error program will show what the error is with error code

--> PROCESS STEPS:
1 - Check if there is enough commend line arguments
2 - Assign the commend line arguments to needed variables(for initial guesses and tolerance) and a dynamic vector(for coefficients) with 'atof' function
3 - Form the class and place the variables into it
4 - Find result of initial values for bisection and hybrid method
5 - Perform Bisection Method
6 - Perform Secant Method
7 - Perform Hybrid Method
8 - Delete dynamically formed vector and finish
