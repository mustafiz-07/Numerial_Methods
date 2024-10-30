# function58.hpp Description
 
This file contains some numerical methods for solving linear equation system and differential equation.It includes:
 
- Gaussian Elimination
 
- Gauss-Jordan Elimination
 
- Matrix Invertion using Gauss-Jordan Elimination
 
- Runge-Kutta method 
## Features
**Gaussian Elimination:**  Solves a system of linear equations using forword Elimination and back substitution
 
**Proccess:**
 
       Step 1:Read the number of variable
       Step 2:Read the coeffecients(A) and Constants(B)
       Step 3:Transform the Matrixs to Upper Trainagular Matrix by row operations
       Step 4:Get Solution by back substitution
       Step 5:Show the result
**Input Format**

        Get the coeffecients and constant of each equation one by one

        Example:
        2x+3y+2z=5
        3x+3y+5z=8
        3x+7y+2z=10
        
       { 2 3 2 5
        3 3 5 8
        3 7 2 10 } 
        
**Gauss-Jordan Elimination:** Solve a system of linear equations using forward and Backword Elimination

**Proccess:**
 
       Step 1:Read the number of variable
       Step 2:Read the coeffecients(A) and Constants(B)
       Step 3:Transform the Matrixs to Identity matrix using forword and backword Elimination
       Step 4:The result will stored in Constants' Matrix(B)
       Step 5:Show the result

**Input Format**

        Get the coeffecients and constant of each equation one by one
        
        Example:
        2x+3y+2z=5
        3x+3y+5z=8
        3x+7y+2z=10
        
       { 2 3 2 5
        3 3 5 8
        3 7 2 10 } 

**Matrix Invertion :** Matrix Invertion can easily solved by using gauss-jordan elimination 

**Proccess:**
 
       Step 1:Read the elements of Matrix(A)
       Step 2:Augment a identity matrix(I) with A matrix
       Step 3:Transform the Matrix(A) to Identity matrix using forword and backword Elimination
       Step 4:The I automatically become the inverse of Matrix A
       Step 5:Show the result

**Input Format**
         Give the elements of Matrix Row-wise  
         
         Example:

           2 3 2 5
           3 3 5 8
           3 7 2 10   

**Runge-Kutta Method :** This method is use to solve the differential equation.

**Proccess:**

       1. Start

       2. Define function f(x,y)

       3. Take the  initial value(x0 and y0), number of steps (n) and calculation point (xn)
   
       4. Calculate step size (h) = (xn - x0)/n
       
       5. Set i=0
       6. Loop 
      
             k1 = h * f(x0, y0)
             k2 = h * f(x0+h/2, y0+k1/2)
             k3 = h * f(x0+h/2, y0+k2/2)
             k4 = h * f(x0+h, y0+k3)
      
             k = (k1+2*k2+2*k3+k4)/6
      
             yn = y0 + k
      
             i = i + 1
             x0 = x0 + h
             y0 = yn
      
          While i < n


       7. Display yn as result




