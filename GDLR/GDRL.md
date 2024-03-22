# 多元线性回归梯度下降算法

## 数学原理

$$
X = \left ( \begin{matrix}
    x_1 \\
    x_2 \\
    \vdots \\
    x_n
\end{matrix} \right )  
\beta = \left ( \begin{matrix}
    \beta _1 \\
    \beta _2 \\
    \vdots \\
    \beta _n
\end{matrix} \right) \\
\hat y = \hat \beta ^ T \cdot X + \epsilon \\

\begin{align*}
    error
    &= \sum{(y_i - \hat y_i)^2} \\
    &= \sum{(y_i - \hat \beta ^T \cdot X_i - \hat \epsilon)^2} \\

    \frac{\partial error}{\partial \epsilon}
    &= \sum{(-2)(y_i - \hat \beta ^T \cdot X_i - \hat \epsilon)} = 0 \\

    \epsilon
    &= \overline y - \overline{\hat \beta ^T \cdot X} \\
    &= \overline y - \hat \beta ^T \cdot \overline X \\

    \nabla error
    &= \sum \frac{\partial error}{\partial \beta _i} \boldsymbol{e_i} \\

    \frac{\partial error}{\partial \beta_i}
    &= \frac{\partial \sum{(y_j - (\beta_1 + \beta_2))}}{}
\end{align*}
$$
