import sys

def xor_range(arr, l, r):
    xor_result = 0
    for i in (x for x in range(l-1, r)):
        xor_result ^= arr[i]
    return xor_result

def xor_update(arr, idx, val):
    arr[idx-1] ^= val

def main():
    n = int(sys.stdin.readline())
    arr = list(map(int, sys.stdin.readline().split()))

    q = int(sys.stdin.readline())
    for _ in range(q):
        query = list(map(int, sys.stdin.readline().split()))
        if query[0] == 1:
            a, b = query[1], query[2]
            print(xor_range(arr, a, b))
        elif query[0] == 2:
            a, d = query[1], query[2]
            xor_update(arr, a, d)
        elif query[0] == 3:
            a, b, d = query[1], query[2], query[3]
            arr[a-1:b] = [x ^ d for x in arr[a-1:b]]

if __name__ == "__main__":
    main()
