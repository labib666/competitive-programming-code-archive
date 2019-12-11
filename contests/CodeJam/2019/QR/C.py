import math
    
t = int(input())
tc = 0

while tc<t:
    tc += 1
    
    [p,n] = [int(x) for x in input().split()]
    
    a = [int(x) for x in input().split()]
    
    b = []
    b.append(a[0])
    
    for x in a:
        b.append(x)

    for i in range(n-1):
        if a[i] != a[i+1]:
            b[i+1] = math.gcd(a[i], a[i+1])
            for j in reversed(range(i+1)):
                b[j] = b[j] / b[j+1]
            for j in range(i+1,n):
                b[j+1] = b[j+1] / b[j]
            break
    
    c = list(set(b))
    c.sort()
    
    res = ''
    for i in b:
        res += chr(c.index(i)+65)
    print("Case #%d: %s" % (tc, res))

