from math import *
from itertools import *
import sys

input = lambda: sys.stdin.readline().strip()

def test01():
    '''
    算法核心思想标签：数学、因数分解、平方差公式
    题目描述：求出所有满足 (n + 10120300500) 且 (n - 10120300500) 均为完全平方数的整数 n 的总和
    输入格式：无输入，结果填空题
    '''
    x = 10120300500
    target = 2 * x
    ans = 0
    
    # 只需要枚举到 target 的平方根即可
    limit = int(target ** 0.5)
    
    # 因为 u 和 v 必须同为偶数，所以我们可以直接以 2 为步长枚举偶数 v
    for v in range(2, limit + 1, 2):
        if target % v == 0:
            u = target // v
            
            # 检查 u 和 v 是否同为偶数
            if u % 2 == v % 2:
                a = (u + v) // 2
                n = a * a - x
                ans += n
                
    print(ans)

test01()