import pandas as pd
x=[[4.0],[5.0],[6.0],[7.0],[8.0],[9.0],[10.0]]
y=[  16, 25 , 36, 49,64,81, 100]
# Step 2 - Fitting Linear Regression
from sklearn.linear_model import LinearRegression
lin_reg = LinearRegression()
lin_reg.fit(x,y)

# Step 4 Linear Regression prediction
print(lin_reg.predict([[11]]))
from sklearn.pipeline import make_pipeline
from sklearn.preprocessing import PolynomialFeatures

polynomial_regression = make_pipeline(
    PolynomialFeatures(degree=1, include_bias=False),
    LinearRegression(),
)
polynomial_regression.fit(x,y)
X_height=[[20.0]]
target_predicted = polynomial_regression.predict(X_height)
print(target_predicted)