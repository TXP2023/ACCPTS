import random

def generate_random_data():
   
    N = random.randint(10, 15)
    Q = random.randint(1, 5) 
    
    a = [random.randint(1, 20) for _ in range(N)]
    
    
    operations = []
    for _ in range(Q):
        op_type = random.choice(['M', 'A'])
        L = random.randint(1, N)
        R = random.randint(L, N)
        W = random.randint(5, 40)
        operations.append(f"{op_type} {L} {R} {W}")
    
    
    with open("input.txt", "w") as f:
        
        f.write(f"{N} {Q}\n")
        
        f.write(" ".join(map(str, a)) + "\n")
        
        for op in operations:
            f.write(op + "\n")

if __name__ == "__main__":
    generate_random_data()
    print("input.txt")