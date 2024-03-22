/**
 * @file mathematics.h
 * @author Goldfish1295
 * @brief Solving Multiple Linear Regression with Gradient Descent.
 * @version v1.0
*/
#ifndef RENESAS_GDLR_MATHEMATICS_H_
#define RENESAS_GDLR_MATHEMATICS_H_

/**
 * @brief Exception handling function
*/
void excep();

/**
 * @brief Vector structure
*/
struct vector
{
    int dim;    ///< Dimension
    double *val;///< Values
};

/**
 * @brief Enumeration of photovoltaic parameters
*/
enum PARAM
{
    cnt = 8,    ///< How many params are there
    cnst = 0,   ///< The const is named theta_0
    Weather_Temperature_Celsius = 1,    ///< theta_1
    Weather_Relative_Humidity = 2,      ///< theta_2
    Global_Horizontal_Radiation = 3,    ///< theta_3
    Diffuse_Horizontal_Radiation = 4,   ///< theta_4
    Radiation_Global_Tilted = 5,        ///< theta_5
    Radiation_Diffuse_Tilted = 6,       ///< theta_6
    Weather_Daily_Rainfall = 7          ///< theta_7
} param;

/**
 * @brief Vector Addition
 * @param a The first vector
 * @param b The second vector
 * @param ret Pointer to the storage location of the return value
 * @exception The dimension of two vectors are different
*/
void VectorAdd(struct vector a, struct vector b, struct vector *ret);

/**
 * @brief Vector Subtraction
 * @param a Subtracted vector
 * @param b Subtrahend vector
 * @param ret Pointer to the storage location of the return value
 * @exception The dimension of two vectors are different
*/
void VectorMinus(struct vector a, struct vector b, struct vector *ret);

/**
 * @brief Vector Dot Product
 * @param a The first vector
 * @param b The second vector
 * @param ret Pointer to the storage location of the return value
 * @exception The dimension of two vectors are different
*/
void VectorDotProduct(struct vector a, struct vector b, double *ret);

/**
 * @brief MeanSquaredError calculation function
 * @param x An array for storing independent variable statistics data
 * @param y An array for storing dependent variables statistics data
 * @param theta Pointer to the linear regression coefficient
 * @return Double precision K-squared error
*/
double MeanSquaredError(struct vector *x, double *y, struct vector *theta, double *epsilon);

double Predict(struct vector x, struct vector theta, double epsilon);

void StepGradientDescent(struct vector *x, double *y, struct vector *current_theta, double *current_epsilon, double learning_rate, struct vector *ret_theta, double *ret_epsilon);

/**
 * @brief Implementing Multiple Linear Regression with Gradient Descent Algorithm
 * @param x An array for storing independent variable statistics data
 * @param y An array for storing dependent variables statistics data
 * @param decent_origin Gradient descent starting point, usually using pre trained models or the results of the previous regression
 * @param learning_rate Learning step size
 * @param final_error_limit When the final error falls below this limit, it can be considered as reaching the endpoint
 * @param theta Pointer to the storage location of the return value of the fitting coefficient
 * @exception The number of elements in the x and y arrays is different
*/
void LinearRegression(struct vector *x, double *y, struct vector decent_origin, double learning_rate, double final_error_limit, struct vector *theta, double *epsilon);

#endif