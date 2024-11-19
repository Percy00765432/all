import plotly.express as px
import pandas as pd
weekly_temps= pd.DataFrame({
    'day':[ 'monday','tuesday','wednesday','thursday','friday','saturday','sunday'],
    'temp':[28,27,25,31,32,35,36]})
fig=px.bar(data_frame=weekly_temps ,x='day',y='temp')
fig.show()
