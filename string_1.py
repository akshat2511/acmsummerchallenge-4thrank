t = int(input())
test_cases = []
for _ in range(t):
    q = int(input())
    queries = []
    for _ in range(q):
        query = input().split()
        query_type = int(query[0])
        if query_type == 1:
            queries.append((query_type, query[1]))
        elif query_type == 2:
            x = int(query[1])
            for m in queries:
                for n in m:
                    if queries[m][0,x]==queries[n][0,x]:

                    
            

