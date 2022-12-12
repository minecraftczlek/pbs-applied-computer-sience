from datetime import datetime

x = datetime.now()

print(x)
print(x.year)
print(x.month)
print(x.weekday()+1)
print(x.timetuple().tm_yday)
print(x.day)