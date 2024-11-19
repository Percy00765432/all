import numpy as np
import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.naive_bayes import GaussianNB
from sklearn.metrics import accuracy_score
import matplotlib.pyplot as plt
import seaborn as sns

# Load data
df = pd.read_csv("NBD.csv")
df.head()

# Separate features and target variable
x = df.drop('diabetes', axis=1)
y = df['diabetes']

# Split data into train and test sets
x_train, x_test, y_train, y_test = train_test_split(x, y, test_size=0.25, random_state=42)

# Initialize and train model
model = GaussianNB()
model.fit(x_train, y_train)

# Make predictions
y_pred = model.predict(x_test)
y_pred