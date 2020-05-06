import pandas as pd
import matplotlib.pyplot as plt

# Read csv file into a pandas dataframe
df = pd.read_csv("5cbf0beff26ee650_2020-04-29--14-23-54.csv", index_col=0)
df = df.sort_index(axis = 0)

#df['Time'] = pd.to_datetime(df['logMonoTime'])

segment = df.query("logMonoTime > 280441193234 and logMonoTime < 326441193234")
#segment = df.query("logMonoTime > 320441193234 and logMonoTime < 330441193234")

segment = segment.ffill()
segment['Abs'] = segment['Steer_Torque_Output'].abs()
segment['Rolling_Std'] = segment['Steer_Torque_Output'].rolling(50).std()
segment['Rolling_Sum'] = segment['Steer_Torque_Output'].rolling(50).sum()
segment['Rolling_Mean'] = segment['Steer_Torque_Output'].rolling(50).mean()
segment['Rolling_Diff'] = segment['Steer_Torque_Output'].diff(periods=50)
#segment['Rolling_Diff'] = segment['Steering_Angle'].diff(periods=50)
#segment['Rolling_Abs_Diff'] = segment['Abs'].diff(periods=50)

print(segment.head())

# LKAS_Output,Steer_Error_1,Steer_Warning,Steering_Angle
plt.figure()
plt.subplot(211)
#segment["Steer_Torque_Output"].plot.line(legend=True)
#segment["Steering_Angle"].plot.line(legend=True)
segment["Signal3"].plot.line(legend=True)
#segment["LKAS_Output"].plot.line(legend=True)
#segment["Time"].plot.line(legend=True)
#segment["Rolling_Std"].plot.line(legend=True)
#segment["Rolling_Sum"].plot.line(legend=True)
#segment["Rolling_Mean"].plot.line(legend=True)
#segment["Rolling_Diff"].plot.line(legend=True)
#segment["Rolling_Abs_Diff"].plot.line(legend=True)
#segment["Steering_Angle"].plot.line(legend=True)
#segment["logMonoTime"].plot.line(legend=True)
plt.subplot(212)
segment["Steer_Error_1"].plot.line(legend=True)
segment["Steer_Warning"].plot.line(legend=True)
segment["Cruise_Activated"].plot.line(legend=True)
plt.show()
