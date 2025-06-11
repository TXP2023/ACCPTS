import random

def generate_random_data():
    # ����N��Q
    N = random.randint(10, 15)
    Q = random.randint(1, 10)  # Q�ķ�Χû��ָ����������Ϊ1-10
    
    # ����N��1-20�����������
    a = [random.randint(1, 20) for _ in range(N)]
    
    # ����Q������
    operations = []
    for _ in range(Q):
        op_type = random.choice(['M', 'A'])
        L = random.randint(1, N)
        R = random.randint(L, N)
        W = random.randint(5, 40)
        operations.append(f"{op_type} {L} {R} {W}")
    
    # д���ļ�
    with open("input.txt", "w") as f:
        # ��һ��дN��Q
        f.write(f"{N} {Q}\n")
        # �ڶ���д����a
        f.write(" ".join(map(str, a)) + "\n")
        # д�����
        for op in operations:
            f.write(op + "\n")

if __name__ == "__main__":
    generate_random_data()
    print("������������ɵ�input.txt")