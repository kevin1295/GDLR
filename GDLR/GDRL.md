# 多元线性回归梯度下降算法

## 数学原理

$$
X = \left ( \begin{matrix}
    x_1 \\
    x_2 \\
    \vdots \\
    x_n
\end{matrix} \right )  
\theta = \left ( \begin{matrix}
    \theta _1 \\
    \theta _2 \\
    \vdots \\
    \theta _n
\end{matrix} \right) \\
\hat y = \hat \theta ^ T \cdot X + \epsilon \\

\begin{align*}
    MSE
    &= \frac{\sum{(y_i - \hat y_i)^2}}{n} \\
    &= \frac{\sum{(y_i - \hat \theta ^T \cdot X_i - \hat \epsilon)^2}}{n} \\

    \frac{\partial MSE}{\partial \epsilon}
    &= \frac 1 n \sum{(-2)(y_i - \hat \theta ^T \cdot X_i - \hat \epsilon)} = 0 \\

    \epsilon
    &= \overline y - \overline{\hat \theta ^T \cdot X} \\
    &= \overline y - \hat \theta ^T \cdot \overline X \\

    \nabla MSE
    &= \frac 1 n \sum \frac{\partial MSE}{\partial \theta _i} \boldsymbol{e_i} \\

    \frac{\partial MSE}{\partial \theta_i}
    &= \frac 1 n \frac{\partial \sum{(y_j - (\theta_1 x_{j1}+ \theta_2 x_{j2} + \dots + \theta_n x_{jn} + \epsilon))^2}}{\partial \theta _i} \\
    &= (-\frac 2 n)x_{ji} \sum (y_j - (\theta_1 x_{j1} + \theta_2 x_{j2} + \dots +\theta_n x_{jn} + \epsilon)) \\
    &= (-\frac 2 n)x_{ji} \cdot \sum error_j
\end{align*}
$$
