import random

def generate_random_data():
    # 生成N和Q
    N = random.randint(10, 15)
    Q = random.randint(1, 10)  # Q的范围没有指定，这里设为1-10
    
    # 生成N个1-20的随机正整数
    a = [random.randint(1, 20) for _ in range(N)]
    
    # 生成Q个操作
    operations = []
    for _ in range(Q):
        op_type = random.choice(['M', 'A'])
        L = random.randint(1, N)
        R = random.randint(L, N)
        W = random.randint(5, 40)
        operations.append(f"{op_type} {L} {R} {W}")
    
    # 写入文件
    with open("input.txt", "w") as f:
        # 第一行写N和Q
        f.write(f"{N} {Q}\n")
        # 第二行写数组a
        f.write(" ".join(map(str, a)) + "\n")
        # 写入操作
        for op in operations:
            f.write(op + "\n")

if __name__ == "__main__":
    generate_random_data()
    print("随机数据已生成到input.txt")