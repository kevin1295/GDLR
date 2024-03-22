#include <stdio.h>
#include <stdlib.h>
#include "GDLR/mathematics.h"

int main() {
    struct vector x[4];
    x[0].dim = x[1].dim = x[2].dim = x[3].dim = 3;
    for (int i = 0; i < 4; i++) {
        x[i].val = (double *)malloc(sizeof(double) * 3);
    }
    x[0].val[0] = 1;
    x[0].val[1] = 2;
    x[0].val[2] = 3;
    
    x[1].val[0] = 2;
    x[1].val[1] = 3;
    x[1].val[2] = 4;
    
    x[2].val[0] = 3;
    x[2].val[1] = 4;
    x[2].val[2] = 5;
    
    x[3].val[0] = 4;
    x[3].val[1] = 5;
    x[3].val[2] = 6;

    double y[4] = {1, 2, 3, 4};

    struct vector theta_o;
    theta_o.dim = 3;
    theta_o.val[0] = 1;
    theta_o.val[1] = 2;
    theta_o.val[2] = 3;

    double epsilon_o = 0.0;

    int iter;
    double loss;
    struct vector theta;
    double epsilon;

    LinearRegression(x, y, &theta_o, &epsilon_o, 1, 100, 3, &iter, &loss, &theta, &epsilon);
    printf("iter : %d \n loss : %llf \n");
    for (int i = 0; i < 3; i++) {

    }
    return 0;
}