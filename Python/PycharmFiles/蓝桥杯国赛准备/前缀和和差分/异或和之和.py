import sys

input = lambda: sys.stdin.readline().strip()


def test_xor_sum():
  '''
  拆位法 + 前缀异或和
  题目描述：给定一个数组A，求其每个子段的异或和，并求出它们的和。
  输入：第一行n，第二行n个数。
  '''
  n = int(input())
  a = list(map(int, input().split()))
  for k in range(21):
    for x in a:
      bit = (x >> k) & 1
      print(bit,end=' ')
    print('_')


if __name__ == '__main__':
  test_xor_sum()