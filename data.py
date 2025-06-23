import random
import string
import sys

def generate_random_string(min_len=1, max_len=3):
    length = random.randint(min_len, max_len)
    return ''.join(random.choice(string.ascii_lowercase) for _ in range(length))

def main():
    N = random.randint(1, 5)  
    Q = 5  
    
    print(f"{N} {Q}")
    
    for _ in range(Q):
        t = random.randint(1, 3) 
        p = random.randint(1, N) 
        if t == 1:
            print(f"1 {p}")
        elif t == 2:
            s = generate_random_string()
            print(f"2 {p} {s}")
        else:  # t == 3
            print(f"3 {p}")

if __name__ == "__main__":
    main()