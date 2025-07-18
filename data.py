import random
import sys

def main():
    
    #random.seed(time())
    
    
    n = random.randint(2, 10000)  # 
    max_edges = n * (n - 1) // 2  # 
    m_upper = min(20000, max_edges)  
    m = random.randint(n - 1, m_upper)  
    
    g = random.randint(1, 1000)  # 
    q = random.randint(1, 100)     # 
    
    
    sys.stdout.write(f"{n} {m}\n")
    
    
    total_bits = max_edges
    if total_bits > 0:
        bit_arr = bytearray((total_bits + 7) // 8)
    else:
        bit_arr = bytearray()
    
    
    for u in range(1, n): 
        v = random.randint(0, u - 1) 
        
        sys.stdout.write(f"{v + 1} {u + 1}\n")

        pos = u * (u - 1) // 2 + v
        byte_index = pos // 8
        bit_index = pos % 8
        if byte_index < len(bit_arr):
            bit_arr[byte_index] |= (1 << bit_index)
    
    
    add_edge = m - (n - 1)
    while add_edge > 0:
        u = random.randint(0, n - 1)
        v = random.randint(0, n - 1)
        if u == v:
            continue
        if u < v:
            u, v = v, u  # 
        pos = u * (u - 1) // 2 + v
        byte_index = pos // 8
        bit_index = pos % 8
    
        if byte_index < len(bit_arr) and (bit_arr[byte_index] & (1 << bit_index)):
            continue
        
        if byte_index < len(bit_arr):
            bit_arr[byte_index] |= (1 << bit_index)
        sys.stdout.write(f"{v + 1} {u + 1}\n")
        add_edge -= 1
    
    
    sys.stdout.write(f"{g}\n")
    
    
    dep = [0] * (g + 1)  #
    for i in range(1, g + 1):
        if i == 1:
            dep[i] = 0  # 
        else:
            if random.random() < 0.2:  # 
                dep[i] = 0
            else:
                dep[i] = random.randint(1, i - 1)  # 
    
    
    for i in range(1, g + 1):
        sys.stdout.write(f"{dep[i]}\n")
    
    
    sys.stdout.write(f"{q}\n")
    
    
    for _ in range(q):
        x = random.randint(1, n)      
        s = random.randint(1, g)      
        t = random.randint(1, g)     
        sys.stdout.write(f"{x} {s} {t}\n")

if __name__ == "__main__":
    main()