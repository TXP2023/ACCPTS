print(5)
import random

for _ in range(5):
    n = random.randint(2, 10)
    print(n)
    a = [random.randint(1, 20) for _ in range(n)]
    print(' '.join(map(str, a)))