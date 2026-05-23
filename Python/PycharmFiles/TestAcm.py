n = int(input())
ans = 0

# C 至少 1 位，B 至少 1 位，A = n - B//C
# 数字总长度 = len(A)+len(B)+len(C) = 9，且 1~9 各出现一次

for C in range(1, 10000):
    maxB = (n - 1) * C
    minB = C
    if len(str(minB)) + len(str(C)) >= 9:
        break
    for B in range(minB, maxB + 1):
        A = n - B // C
        if A <= 0:
            continue
        s = str(A) + str(B) + str(C)
        if len(s) != 9:
            continue
        if '0' in s:
            continue
        if len(set(s)) == 9:
            ans += 1

print(ans)