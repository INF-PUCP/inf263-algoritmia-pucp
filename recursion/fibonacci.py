dp = []
is_done = []

def f(n):
    if n <= 2:
        return 1
    if is_done[n]:
        return dp[n]
    dp[n] = f(n - 1) + f(n - 2)
    is_done[n] = True
    return dp[n]

n = 100
for i in range(0, n + 1):
    dp.append(0)
    is_done.append(False)
print(f(n))
