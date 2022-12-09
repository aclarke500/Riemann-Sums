#include <stdio.h>
#include <math.h>

double example_function(double x) { 

    return x * x * x + 4.0; 
}

double example_function_2(double x){

    return sin(x);
}

double left_riemann_sum(double a, double b) {
    // we need to define the width of the rectangles
    double width = 0.0001;
    double sum = 0;
    double position = a;  // we start at a double a
    double val = 0;

    while (position < b) {
        val = example_function_2(position);
        val *= width;
        sum += val;
        position += width;
    }
    return sum;
}

double right_riemann_sum(double a, double b) {
    // we need to define the width of the rectangles
    double width = 0.0001;
    double sum = 0;
    double position = a + width;  // we start at a double a
    double val = 0;

    while (position <= b) {
        val = example_function_2(position);
        val *= width;
        sum += val;
        position += width;
    }
    return sum;
}

double midpoint_riemann_sum(double a, double b){
    double width = 0.0001;
    double sum = 0;
    double position = a;  // we start at a double a
    double val = 0;

    while (position <= b){
        val = (example_function_2(position) + example_function_2(position+width))/2;
        val *= width;
        sum += val;
        position += width;
    }
    return sum;
}

int main(int argc, char *argv[]) {
    double val = left_riemann_sum(0, 5);
    double val2 = midpoint_riemann_sum(0, 5);
    double val3 = right_riemann_sum(0, 5);
    printf("%s %f\n%s %f\n%s %f\n", "Left reimann: ",val, "Midpoint: ", val2, "Right reimann", val3);

    for (int i = 0; i < 5; i++) {
        double val = example_function((double)i);
    }
    
    return 0;
}