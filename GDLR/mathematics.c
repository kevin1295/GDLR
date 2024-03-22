#include "mathematics.h"

void excep()
{
}

void VectorAdd(struct vector a, struct vector b, struct vector *ret)
{
    if (a.dim != b.dim)
    {
        excep();
    }
    else
    {
        ret->val = (double *)malloc(a.dim * sizeof(double));
        for (int i = 0; i < a.dim; i++)
        {
            *(ret->val + i) = *(a.val + i) + *(b.val + i);
        }
    }
}

void VectorMinus(struct vector a, struct vector b, struct vector *ret)
{
    if (a.dim != b.dim)
    {
        excep();
    }
    else
    {
        ret->val = (double *)malloc(a.dim * sizeof(double));
        for (int i = 0; i < a.dim; i++)
        {
            *(ret->val + i) = *(a.val + i) - *(b.val + i);
        }
    }
}

void VectorDotProduct(struct vector a, struct vector b, double *ret)
{
    if (a.dim != b.dim)
    {
        excep();
    }
    else
    {
        ret = (double *)malloc(sizeof(double));
        *ret = 0;
        for (int i = 0; i < a.dim; i++)
        {
            *ret += *(a.val + i) * *(b.val + i);
        }
    }
}

double MeanSquaredError(struct vector *x, double *y, struct vector *theta, double *epsilon) {
    if (theta->dim != x->dim || sizeof(x)/sizeof(x[0]) != sizeof(y)/sizeof(double))
    {
        excep();
    }
    else
    {
        double product = 0;
        double loss = 0;
        int cnt = sizeof(y)/sizeof(double);
        
        for (int i = 0; i < cnt; i++) {
            VectorDotProduct(*(x+i), *theta, &product);
            loss += (*(y+i) - product - *epsilon) * (*(y+i) - product - *epsilon);
        }

        return loss / cnt;
    }
}

double Predict(struct vector *x, struct vector *theta, double *epsilon)
{
    if (x->dim != theta->dim)
    {
        excep();
    }
    else
    {
        double product = 0, ret = 0;
        VectorDotProduct(*x, *theta, &product);
        ret = product + *epsilon;
        return ret;
    }
}

void StepGradientDescent(struct vector *x, double *y, struct vector *current_theta, double *current_epsilon, double learning_rate, struct vector *ret_theta, double *ret_epsilon) {
    double gradients[x->dim];
    memset(gradients, (double)0.0, sizeof(gradients));

    int cnt = sizeof(x)/sizeof(struct vector);
    for (int i = 0; i < cnt; i++) {
        
    }
}

