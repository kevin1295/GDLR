#include <stdio.h>
#include <stdlib.h>
#include "GDLR\mathematics.h"

int main() {
    struct vector x[4];
    x[0].dim = x[1].dim = x[2].dim = x[3].dim = 1;
    for (int i = 0; i < 4; i++) {
        x[i].val = (double *)malloc(sizeof(double) * 1);
    }
    x[0].val[0] = 1;
    
    x[1].val[0] = 2;
    
    x[2].val[0] = 3;
    
    x[3].val[0] = 4;

    double y[4] = {1, 2, 3, 4};

    struct vector theta_o;
    theta_o.dim = 1;
    theta_o.val = (double*)malloc(1*sizeof(double));
    theta_o.val[0] = 100;

    double epsilon_o = 10;

    int iter;
    double loss;
    struct vector theta;
    double epsilon;

    printf("---debug---\n");

    LinearRegression(x, y, 4, &theta_o, &epsilon_o, 0.0002, 1000, 10, 100, &iter, &loss, &theta, &epsilon);
    printf("iter : %d \nloss : %llf \ntheta:", iter, loss);
    for (int i = 0; i < 1; i++) {
        printf("  %llf\n", theta.val[i]);
    }
    printf("epsilon: %llf\n", epsilon);
    return 0;
}