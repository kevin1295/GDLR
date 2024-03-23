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
        free(ret->val);
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
        free(ret->val);
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
        *ret = 0;
        for (int i = 0; i < a.dim; i++)
        {
            *ret += a.val[i] * b.val[i];
        }
    }
}

double MeanSquaredError(struct vector *x, double *y, int *train_size, struct vector *theta, double *epsilon) {
    if (theta->dim != x->dim)
    {
        excep();
    }
    double product = 0;
    double loss = 0;
    int cnt = *train_size;
    
    for (int i = 0; i < cnt; i++) {
        VectorDotProduct(*(x+i), *theta, &product);
        loss += (*(y+i) - product - *epsilon) * (*(y+i) - product - *epsilon);
    }

    return loss / cnt;
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

void StepGradientDescent(struct vector *x, double *y, int *train_size, struct vector *current_theta, double *current_epsilon, double learning_rate, struct vector *ret_theta, double *ret_epsilon)
{
    double gradients[x->dim], gradient_epsilon = 0.0, aver_error = 0;
    for (int i = 0; i < x->dim; i++)
    {
        gradients[i] = 0.0;
    }

    int cnt = *train_size;
    for (int j = 0; j < cnt; j++)
    {
        double error = 0.0, product = 0.0;
        VectorDotProduct(x[j], *current_theta, &product);
        error = y[j] - product - *
        current_epsilon;
        aver_error += error;

        gradient_epsilon += error;
        for (int i = 0; i < x->dim; i++)
        {
            gradients[i] += error * x[j].val[i];
        }
    }
    
    gradient_epsilon = gradient_epsilon / cnt;
    *ret_epsilon = *current_epsilon + learning_rate * gradient_epsilon;
    ret_theta->dim = x->dim;
    for (int i = 0; i < x->dim; i++)
    {
        gradients[i] = gradients[i] / cnt;
        ret_theta->val[i] = current_theta->val[i] + learning_rate * gradients[i] * (1.0);
    }
}

void LinearRegression(struct vector *x, double *y, int train_size, struct vector *decent_origin_theta, double *decent_origin_epsilon, double learning_rate, double iter_limit, int triger, int patience, int *ret_iteration, double *ret_loss, struct vector *ret_theta, double *ret_epsilon)
{
    if (sizeof(x)/sizeof(x[0]) != sizeof(y)/sizeof(double))
    {
        excep();
    }

    double best_validation_loss = __INT32_MAX__, best_epsilon = 0;
    int best_iteration;
    struct vector best_theta;
    double alpha = learning_rate;
    int patience_counter = 0, iter;

    struct vector theta = *decent_origin_theta, theta_temp;
    theta_temp.dim = theta.dim;
    theta_temp.val = (double*)malloc(theta.dim * sizeof(double));
    double epsilon = *decent_origin_epsilon, epsilon_temp;

    for (iter = 0; iter < iter_limit; ++iter)
    {
        /*
        printf("epoch %d:----------\n    epsilon = %lf\n    theta =\n", iter, epsilon);
        for (int i = 0; i < theta.dim; i++) {
            printf("        theta_%d = %lf\n", i, theta.val[i]);
        }
        printf("    loss = %lf\n", MeanSquaredError(x, y, &train_size, &theta, &epsilon));
        */

        StepGradientDescent(x, y, &train_size, &theta, &epsilon, alpha, &theta_temp, &epsilon_temp);
        theta = theta_temp;
        epsilon = epsilon_temp;
        double validation_loss = MeanSquaredError(x, y, &train_size, &theta, &epsilon);

        if (validation_loss - best_validation_loss < -1e-6)
        {
            best_validation_loss = validation_loss;
            best_iteration = iter;
            best_theta = theta;
            best_epsilon = epsilon;
            patience_counter = 0;
        }
        else
        {
            patience_counter++;

            if (patience_counter > triger)
            {
                learning_rate = learning_rate * 0.7;
            }

            if (patience_counter > patience)
            {
                break;
            }
        }
    }

    *ret_iteration = iter;
    *ret_theta = best_theta;
    *ret_epsilon = best_epsilon;
    *ret_loss = MeanSquaredError(x, y, &train_size, ret_theta, ret_epsilon);
}
