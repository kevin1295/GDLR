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

void StepGradientDescent(struct vector *x, double *y, struct vector *current_theta, double *current_epsilon, double learning_rate, struct vector *ret_theta, double *ret_epsilon)
{
    double gradients[x->dim];
    memset(gradients, (double)0.0, sizeof(gradients));

    int cnt = sizeof(x)/sizeof(struct vector);
    for (int j = 0; j < cnt; j++)
    {
        double error = 0.0, product = 0.0;
        VectorDotProduct(x[j], *current_theta, &product);
        error = y[j] - product - *current_epsilon;

        for (int i = 0; i < x->dim; i++)
        {
            gradients[i] += error * x[j].val[i];
        }
    }
    
    for (int i = 0; i < x->dim; i++)
    {
        gradients[i] = gradients[i] / cnt * (-2.0);
        ret_theta->val[i] = current_theta->val[i] + learning_rate * gradients[i];
    }
}

void LinearRegression(struct vector *x, double *y, struct vector *decent_origin_theta, double *decent_origin_epsilon, double learning_rate, double iter_limit, int patience, int *ret_iteration, double *ret_loss, struct vector *ret_theta, double *ret_epsilon)
{
    if (sizeof(x)/sizeof(struct vector) != sizeof(y)/sizeof(double))
    {
        excep();
    }

    double best_validation_loss = __INT32_MAX__, alpha = learning_rate;
    int patience_counter = 0;
    int best_iteration = 0;

    struct vector theta = *decent_origin_theta, theta_temp;
    double epsilon = *decent_origin_epsilon, epsilon_temp;

    for (int iter = 0; iter < iter_limit; ++iter)
    {
        StepGradientDescent(x, y, &theta, &epsilon, alpha, &theta_temp, &epsilon_temp);
        theta = theta_temp;
        epsilon = epsilon_temp;
        double validation_loss = MeanSquaredError(x, y, &theta, &epsilon);

        if (validation_loss < best_validation_loss)
        {
            best_validation_loss = validation_loss;
            best_iteration = iter;
            patience_counter = 0;
        }
        else
        {
            patience_counter++;

            if (patience <= patience_counter)
            {
                *ret_iteration = iter;
                break;
            }
        }
    }

    *ret_loss = MeanSquaredError(x, y, ret_theta, ret_epsilon);

}
