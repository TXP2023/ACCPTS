import random


print(5)


for _ in range(5):
    
    n = random.randint(2, 10)
    m = random.randint(2, 10)
    
    
    print(f"{m}")
    
    
    for __ in range(m):
        opt = random.randint(0, 1)  
        a = random.randint(1, n)    
        b = random.randint(1, n)    
        print(f"{a} {b} {opt}")