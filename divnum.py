def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a % b)

def lcm(start, end):
    lcm_value = start
    for i in range(start + 1, end + 1):
        lcm_value = (lcm_value * i) // gcd(lcm_value, i)
    return lcm_value

def find_factors(num, x):
    count = 0
    while num % x == 0 and num > 1:
        count += 1
        num = num // x
    return count

input_line = input("")
a, b, c = map(int, input_line.split())

num = lcm(a, b)

x=input().split()
for i in range(c):
    x[i]=int(x[i])
    print(find_factors(num, x[i]), end=" ")
