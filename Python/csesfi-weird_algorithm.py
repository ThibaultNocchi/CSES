n = int(input())
l = [str(n)]

while(n != 1):
    if(n % 2 == 0):
        n = int(n/2)
    else:
        n = n*3+1
    l.append(str(n))

print(" ".join(l))
