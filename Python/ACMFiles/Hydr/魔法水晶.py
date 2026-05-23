n = int(input())
a = list(map(int, input().split()))

def cal(length, s):
    if length == 1:
        return 0
    else:           # 注意它的分法：偶数：分成(n,n) 奇数：分成(n+1,n)
        mid = (length - 1) // 2
        left = s[:mid + 1]
        right = s[mid + 1:]
        return cal(len(left), left) + cal(len(right), right) + max(left) * min(right)

print(cal(n, a))