import numpy as np

x1=np.array([1,2,3,1,3,2,1,3])
x2=np.array([800,900,1000,1200,1300,1500,1700,1800])
x3=np.array([1,3,2,4,1,2,3,4])
y=np.array([67,81,89,93,102,109,116,133])

a1=sum(x1*x1)
a2=sum(x1*x2)
a3=sum(x1*x3)

b1=sum(x1*x2)
b2=sum(x2*x2)
b3=sum(x3*x2)

c1=sum(x1*x3)
c2=sum(x2*x3)
c3=sum(x3*x3)

d1=sum(x1*y)
d2=sum(x2*y)
d3=sum(x3*y)

A=np.array([[a1,a2,a3],
            [b1,b2,b3],
            [c1,c2,c3]])

D=np.array([d1,
            d2,
            d3])

print(A)
print(D)

A_inv = np.linalg.inv(A)

print(A_inv)

B=A_inv@D
print(B)

B1=B[0]
B2=B[1]
B3=B[2]

print(B1)

y_mean=sum(y)/len(y)
x1_mean=sum(x1)/len(x1)
x2_mean=sum(x2)/len(x2)
x3_mean=sum(x3)/len(x3)

B0 = y_mean - (B1*x1_mean) - (B2*x2_mean) - (B3*x3_mean)

loc=int(input("Enter the value of location\n"))
size=int(input("Enter the value of size\n"))
Ame=int(input("Enter the value of aminities\n"))

Y=B0+(B1*loc)+(B2*size)+(B3*Ame)
print(Y)