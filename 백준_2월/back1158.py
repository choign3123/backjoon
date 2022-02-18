n, k = input().split(" ")
n = int(n)
k = int(k)
k -= 1

#print(n, k)

lst = []
for i in range(n):
    lst.append(i+1)

#print(lst)

print("<", end="")
idx = k
for i in range(n-1):
    print(lst[idx], end=", ")
    del lst[idx]
    
    idx += k
    idx %= len(lst)
    


print(lst[0], ">", sep="")
