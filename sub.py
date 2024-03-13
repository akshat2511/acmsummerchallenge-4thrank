from collections import defaultdict, deque

def count_set_bits(n):
    count = 0
    while n:
        count += n & 1
        n >>= 1
    return count

def find_highest_set_bits_level(tree, n, node_values):
    levels = [-1] * (n + 1)  # Store the level of each node
    level_set_bits = defaultdict(int)  # Store the set bits count for each level
    
    queue = deque([(1, 1)])  # Start BFS from root node
    while queue:
        node, level = queue.popleft()
        levels[node] = level
        level_set_bits[level] += node_values[node]
        
        for neighbor in tree[node]:
            if levels[neighbor] == -1:
                queue.append((neighbor, level + 1))
    
    max_set_bits = -1
    max_set_bits_level = -1
    for level, set_bits_count in level_set_bits.items():
        if set_bits_count > max_set_bits:
            max_set_bits = set_bits_count
            max_set_bits_level = level
    
    return max_set_bits_level

# Read input and process each test case
t = int(input())
for _ in range(t):
    n = int(input())
    tree = defaultdict(list)
    node_values = [0]  # Initialize with a dummy value
    for _ in range(n - 1):
        u, v = map(int, input().split())
        tree[u].append(v)
        tree[v].append(u)
    node_values += [count_set_bits(i) for i in range(1, n + 1)]
    result = find_highest_set_bits_level(tree, n, node_values)
    print(result)
