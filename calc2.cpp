/*
Valeria Munoz Calderon
Calc2 Extra credit
*/
#include <iostream>
#include <cmath>

/*
All three of my functions contains three parameters, start, end, and n.
Start is the start of the integral. End is the end of the integral. N is the 
way we are breaking it up.

These functions aren't as general to use for any function. They are specified
for the function of sin(x^2). But they are general enough to be able to change parameter
values.
*/
double midpoint_rule(double start, double end, double n){
    double deltax = (end-start) / n; //gets the length of the interval
    double sum = 0;
    for(int i = 0; i < n; i++){
        double mid = start + (i+0.5) * deltax;  //get the values of the midpoints between two x values. As it loops will update new midpoint.
        sum += sin(pow(mid,2)); // using mid from previous line to put it into the function, sin(x^2). As this loops it will add all the midpoint values of sin(x^2) from 0 to 4.
    }
    sum *=deltax; //midpoint rule needs to multiply the sum by deltax
    return sum; //returns final result
}

double trapezoid_rule(double start, double end, double n){
    double deltax = ((end - start) / n); //gets the height value of the trapezoid
    double sum = 0;
    //next 2 lines just adds start and end of sin(x^2) to sum since it only occurs once unlike the others.
    sum += sin(pow(start, 2));
    sum += sin(pow(end,2));

    for(int i = 1; i < n; i++){
       double value = (deltax*i) + start; //gets the value of each value of x from 1 to (n-1)
       sum += 2*(sin(pow(value,2))); //sum contains the addition of f(x) as x is found in value and multiplied by 2 since it occurs twice.
    }

    double final_result = (deltax/2)*sum;//to get final result of the area of all trapezoids is by diving by the height
    return final_result;
}

double simpson_rule(double start, double end, int n){
    if(n%2 !=0 ){
        throw std::runtime_error("can't use a odd n value");
    }
    double deltax = ((end - start)/n);
    double sum = 0;
    double value = 0;
    sum += sin(pow(start,2));
    sum += sin(pow(end,2));
    for(int i = 1; i < n; i++){
        double value = (i * deltax) + start; //gets x values needed as the loop increases.
        if (((i % 2) != 0)){
            sum += (4*(sin(pow(value,2))));//functions that are odd is multiplied by 4
        }
        else{
            sum += (2*(sin(pow(value,2))));//functions that are even is multipliled by 2.
        }
    }
    double final_result = (deltax/3)*sum; 
    return final_result;
}


int main(){
    /*
    following just uses the function from above to be able to project the values
    asked which was n = 10, n = 100, and n = 100 from each rule.
    */

    std::cout << "The problem is taking the approximation of the integral of sin(x^2) from 0 to 4." << std::endl;
    std::cout << std::endl;
   
    double result_1m = midpoint_rule(0,4,10);
    double result_2m = midpoint_rule(0,4,100);
    double result_3m = midpoint_rule(0,4,1000);



    std::cout << "Using the midpoint rule, using n = 10 is " << result_1m << std::endl;
    std::cout << "Using the midpoint rule, using n = 100 is " << result_2m << std::endl;
    std::cout << "Using the midpoint rule, using n = 100 is " << result_3m << std::endl;
    std::cout << std::endl;
    double result_1t = trapezoid_rule(0,4,10);
    double result_2t = trapezoid_rule(0,4,100);
    double result_3t = trapezoid_rule(0,4,1000);
    std::cout << "Using trapezoid rule, using n = 10 is " << result_1t << std::endl;
    std::cout << "Using trapezoid rule, using n = 100 is " << result_2t << std::endl;
    std::cout << "Using trapezoid rule, using n = 1000 is " << result_3t <<  std::endl;
    std::cout << std::endl;
    double result_1s = simpson_rule(0,4,10);
    double result_2s = simpson_rule(0,4,100);
    double result_3s = simpson_rule(0,4,1000);
    std::cout << "Using simpson's rule, using n = 10 is " << result_1s << std::endl;
    std::cout << "Using simpson's rule, using n = 100 is " << result_2s << std::endl;
    std::cout << "Using simpson's rule, using n = 1000 " << result_3s << std::endl;
    
}
