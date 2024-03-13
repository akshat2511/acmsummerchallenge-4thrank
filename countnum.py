def factorial(n):
    if n >1:
        return n *factorial(n-1)
num =int(input())    
for i in range(num+1):
    count=0
    str=input()
    k=input()
    for j in range(len(str)):
        if str[j]==k:
            count=count+1
    print(factorial(count))        
