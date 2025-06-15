import random


n = 5

m = random.randint(3, 9)

possible_edges = []
for u in range(1, n + 1):
    for v in range(1, n + 1):
        if u != v:
            possible_edges.append((u, v))


selected_edges = random.sample(possible_edges, m)


edges_with_weights = []
for u, v in selected_edges:
    w = random.randint(1, 10)
    edges_with_weights.append((u, v, w))


q = random.randint(1, 5)


queries = []
for _ in range(q):
    while True:
        u = random.randint(1, n)
        v = random.randint(1, n)
        if u != v:  
            queries.append((u, v))
            break


print(f"{n} {m}")
for u, v, w in edges_with_weights:
    print(f"{u} {v} {w}")
print(q)
for u, v in queries:
    print(f"{u} {v}")