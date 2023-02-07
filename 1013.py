def mul(a,b,mod):
    n = len(a)
    result = []
    for i in range(n):
        result.append([0]*n)
    for i in range(n):
        for j in range(n):
            for k in range(n):
                result[i][j] = (result[i][j] + a[i][k]*b[k][j]%mod)%mod
    return result
def binpow(a,n,mod):
    if n==2:
        return mul(a,a,mod)
    if(n%2==1):
        return mul(binpow(a,n-1,mod),a,mod)
    x = binpow(a,n//2,mod)
    return mul(x,x,mod)
def check(n,k,mod):
    if n==2:
        return (k-1)*k%mod
    if n==1:
        return k-1
    return -1
n = int(input())
k = int(input())
mod = int(input())
if check(n,k,mod) != -1:
    print(check(n,k,mod))
    quit()
x = binpow([[0,k-1],[1,k-1]],n-2,mod)
print(((k-1)*x[0][1]%mod + (k-1)*k%mod*x[1][1])%mod)
