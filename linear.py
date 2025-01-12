import numpy as np
import matplotlib.pyplot as plt
from sklearn.linear_model import LinearRegression
from sklearn.model_selection import train_test_split
from sklearn.metrics import mean_squared_error

# Sample dataset: Hours of study vs Exam score
X = np.array([1, 2, 3, 4, 5, 6, 7, 8, 9, 10]).reshape(-1, 1)  # Input: Hours of study
y = np.array([35, 38, 45, 50, 55, 60, 65, 70, 75, 80])        # Output: Exam scores

# Split the dataset into training and testing sets
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

# Create a linear regression model
model = LinearRegression()

# Train the model
model.fit(X_train, y_train)

# Predict on the test set
y_pred = model.predict(X_test)

# Calculate the Mean Squared Error of the predictions
mse = mean_squared_error(y_test, y_pred)
print(f"Mean Squared Error: {mse}")

# Plot the results
plt.scatter(X, y, color='blue')  # original data points
plt.plot(X, model.predict(X), color='red')  # regression line
plt.title("Linear Regression: Hours vs Exam Scores")
plt.xlabel("Hours of Study")
plt.ylabel("Exam Score")
plt.show()
