# function19.hpp description
This part offers multiple methods to find the roots of a polynomial function. Users can enter the polynomial's degree and coefficients, and select one of the root-finding methods implemented. The methods include Bisection Method, False Position Method, Newton-Raphson Method, and Secant Method.

# Features:
*Bisection Method:* Divides an interval in half to find the root.
*False Position Method (Regula Falsi):* Similar to the Bisection Method but uses a weighted average based on function values to estimate the root.
*Newton-Raphson Method:* Uses derivatives to converge more rapidly to a root.
*Secant Method:* Uses secant lines instead of derivatives, an alternative for functions with challenging derivatives.
Methods

## 1. Bisection Method:
The Bisection Method is a root-finding method based on the Intermediate Value Theorem. It requires two initial guesses x0 and x1 such that the function values at these points have opposite signs (f(x0)*f(x1) < 0). The method iteratively narrows down the interval by selecting the midpoint between x0 and x1 and evaluating the function at that midpoint.

*Process:*

Start with two points x0 and x1.
If f(x0) and f(x1) have opposite signs, calculate the midpoint (x0 + x1) / 2.
Determine whether to update x0 or x1 based on the sign of f(midpoint).
Repeat until f(midpoint) is within the tolerable error.
## 2. False Position Method (Regula Falsi):
The False Position Method, also known as Regula Falsi, is similar to the Bisection Method. Instead of using the midpoint, it calculates a new point based on a weighted average that considers the values of f(x0) and f(x1). This approach often converges more quickly than bisection in cases where the function is not symmetric around the root.

*Process:*

Start with two points x0 and x1 where f(x0)*f(x1) < 0.
Calculate a new point x using the formula (x0 * f(x1) - x1 * f(x0)) / (f(x1) - f(x0)).
Check if f(x) is within the tolerable error. If not, update either x0 or x1 based on the sign of f(x).
Repeat until the result meets the desired precision.
## 3. Newton-Raphson Method:
The Newton-Raphson Method is an efficient iterative method that uses the derivative of the function to converge to a root quickly. This method is particularly effective for functions that are smooth and have well-defined derivatives. It starts with an initial guess x0 and refines it by calculating f(x0) / f'(x0) until reaching the desired precision.

*Process:*

Start with an initial guess x0.
Compute the function value f(x0) and its derivative f'(x0).
Calculate the next guess x1 = x0 - f(x0) / f'(x0).
Repeat the process using x1 as the new x0 until f(x) is within the tolerable error.
## 4. Secant Method:
The Secant Method is similar to the Newton-Raphson Method but does not require calculating derivatives. Instead, it uses secant lines drawn through two points, x0 and x1, to approximate the root. This method is useful for functions that are difficult to differentiate.

*Process:*

Start with two initial guesses x0 and x1.
Calculate a new estimate for the root using x2 = x1 - (x1 - x0) * f(x1) / (f(x1) - f(x0)).
Update x0 and x1 to x1 and x2, respectively, and repeat until the function value at x2 is within the desired tolerance.
Usage:
Run the program and select the root-finding method.
Input the degree of the polynomial and coefficients.
Follow prompts to enter the initial guesses, desired precision, and tolerable error.
For Newton-Raphson and Secant methods, enter an initial guess.
