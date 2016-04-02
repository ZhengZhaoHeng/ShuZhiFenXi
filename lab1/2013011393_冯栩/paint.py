import matplotlib.pyplot as plt

n = 10  
x = []
for i in range(-5000, 5001):
	x.append(float(i)/1000)
y_init = []
for i in x :
	y_init.append(float(1.0)/(1+16*i*i))
	if i == 4.8 :
		print y_init[-1]

'''plt.plot(x, y_init)  
plt.ylabel('Y')
plt.xlabel('X')  
plt.show()'''

#Lagrange 10
'''n = 10
x_spot_1 = []
for i in range(0, n+1):
	x_spot_1.append(float(-5) + i)
y_spot_1 = []
for i in x_spot_1:
	y_spot_1.append(1/(1+16*i*i))
y_l_10 = []
for i in x:
	y_now = 0.0;
	for j in range(0, n+1):
		y_cal = y_spot_1[j];
		for k in range(0, n+1):
			if k <> j :
				y_cal = y_cal*(i - x_spot_1[k])/(x_spot_1[j] - x_spot_1[k])
		y_now = y_now + y_cal;
	y_l_10.append(y_now)
	if i == 4.8:
		print y_now
plt.plot(x, y_init, x, y_l_10)  
plt.ylabel('Y')
plt.xlabel('X')  
plt.show()'''

#Lagrange 20
'''n = 20
x_spot_2 = []
for i in range(0, n+1):
	x_spot_2.append(float(-5) + 0.5*i)
y_spot_2 = []
for i in x_spot_2:
	y_spot_2.append(1/(1+16*i*i))
y_l_20 = []
for i in x:
	y_now = 0.0;
	for j in range(0, n+1):
		y_cal = y_spot_2[j];
		for k in range(0, n+1):
			if k <> j :
				y_cal = y_cal*(i - x_spot_2[k])/(x_spot_2[j] - x_spot_2[k])
		y_now = y_now + y_cal;
	y_l_20.append(y_now)
	if i == 4.8:
		print y_now
plt.plot(x, y_init, x, y_l_20)  
plt.ylabel('Y')
plt.xlabel('X')  
plt.show()'''

#Spline 10
'''n = 10
x_spot_3 = []
for i in range(0, n+1):
	x_spot_3.append(float(-5) + i)
y_spot_3 = []
for i in x_spot_3:
	y_spot_3.append(1/(1+16*i*i))
m_1 = [0.012301, -0.044377, 0.174856, -0.622153, 2.52346, -4.08526, 2.52346, -0.622153, 0.174856, -0.044377, 0.012301]
y_s_10 = []
label_1 = 0
for i in x :
	if i >= x_spot_3[label_1+1] and label_1 < 9:
		label_1 = label_1 + 1
	sus_1 = m_1[label_1]/6*(x_spot_3[label_1+1]-i)**3
	sus_2 = m_1[label_1+1]/6*(i-x_spot_3[label_1])**3
	sus_3 = (y_spot_3[label_1] - m_1[label_1]/6)*(x_spot_3[label_1+1] - i)
	sus_4 = (y_spot_3[label_1+1] - m_1[label_1+1]/6)*(i-x_spot_3[label_1])
	y_s_10.append(sus_1+sus_2+sus_3+sus_4)
	if i == 4.8 :
		print y_s_10[-1]
plt.plot(x, y_init, x, y_s_10)  
plt.ylabel('Y')
plt.xlabel('X')  
plt.show()'''

#Spline 20
n = 20
x_spot_4 = []
for i in range(0, n+1):
	x_spot_4.append(float(-5) + 0.5*i)
y_spot_4 = []
for i in x_spot_4:
	y_spot_4.append(1/(1+16*i*i))
m_2 = [0.000782114, 0.000982653, 0.000830557, 0.00459825, -0.00397594, 0.0397222, -0.0954123, 0.489738, -1.37984, 7.65474, -13.4274, 7.65474, -1.37984, 0.489738, -0.0954123, 0.0397222, -0.00397594, 0.00459826, 0.000830557, 0.000982653, 0.000782114]
y_s_20 = []
label_2 = 0
for i in x :
	if i >= x_spot_4[label_2+1] and label_2 < 19:
		label_2 = label_2 + 1
	sus_1 = m_2[label_2]/6/0.5*(x_spot_4[label_2+1]-i)**3
	sus_2 = m_2[label_2+1]/6/0.5*(i-x_spot_4[label_2])**3
	sus_3 = (y_spot_4[label_2] - m_2[label_2]*0.25/6)*(x_spot_4[label_2+1] - i)*2
	sus_4 = (y_spot_4[label_2+1] - m_2[label_2+1]*0.25/6)*(i-x_spot_4[label_2])*2
	y_s_20.append(sus_1+sus_2+sus_3+sus_4)
	if i == 4.8 :
		print y_s_20[-1]
plt.plot(x, y_init, x, y_s_20)  
plt.ylabel('Y')
plt.xlabel('X')  
plt.show()
