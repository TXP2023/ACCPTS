import random
import sys

def main():
    # ����������ӣ�ȷ���ɸ���
    random.seed(0)
    
    # ����n, m, g, q
    n = random.randint(2, 10)  # ������
    max_edges = n * (n - 1) // 2  # ������
    m_upper = min(10, max_edges)  # m����
    m = random.randint(n - 1, m_upper)  # ����������n-1��֤��ͨ
    
    g = random.randint(1, 10)  # ��ҵ��Ʒ������
    q = random.randint(1, 10)     # ѯ����
    
    # �����һ��: n m
    sys.stdout.write(f"{n} {m}\n")
    
    # ��ʼ��λͼ�����ڼ�¼����ӵıߣ�
    total_bits = max_edges
    if total_bits > 0:
        bit_arr = bytearray((total_bits + 7) // 8)
    else:
        bit_arr = bytearray()
    
    # ������������n-1���ߣ�
    for u in range(1, n):  # u��1��n-1��0-indexed��
        v = random.randint(0, u - 1)  # ���ѡ��v��0-indexed��v < u��
        # ����ߣ�ת��Ϊ1-indexed��С�ڵ���ǰ��
        sys.stdout.write(f"{v + 1} {u + 1}\n")
        # ����λͼ����¼��(u, v)��u > v��
        pos = u * (u - 1) // 2 + v
        byte_index = pos // 8
        bit_index = pos % 8
        if byte_index < len(bit_arr):
            bit_arr[byte_index] |= (1 << bit_index)
    
    # ������ʣ��ߣ�m - (n-1)����
    add_edge = m - (n - 1)
    while add_edge > 0:
        u = random.randint(0, n - 1)
        v = random.randint(0, n - 1)
        if u == v:
            continue
        if u < v:
            u, v = v, u  # ��֤u > v
        pos = u * (u - 1) // 2 + v
        byte_index = pos // 8
        bit_index = pos % 8
        # �����Ƿ��Ѵ���
        if byte_index < len(bit_arr) and (bit_arr[byte_index] & (1 << bit_index)):
            continue
        # ����±�
        if byte_index < len(bit_arr):
            bit_arr[byte_index] |= (1 << bit_index)
        sys.stdout.write(f"{v + 1} {u + 1}\n")
        add_edge -= 1
    
    # �����ҵ��Ʒ������g
    sys.stdout.write(f"{g}\n")
    
    # ����g�ֲ�Ʒ��������ϵ
    dep = [0] * (g + 1)  # dep[0]δʹ�ã�dep[i]��ʾ��Ʒi��ԭ����
    for i in range(1, g + 1):
        if i == 1:
            dep[i] = 0  # ��һ�ֲ�Ʒ������
        else:
            if random.random() < 0.2:  # 20%��������ԭ����
                dep[i] = 0
            else:
                dep[i] = random.randint(1, i - 1)  # ����֮ǰ�Ĳ�Ʒ
    
    # ���������ϵ
    for i in range(1, g + 1):
        sys.stdout.write(f"{dep[i]}\n")
    
    # ���ѯ����q
    sys.stdout.write(f"{q}\n")
    
    # ����q��ѯ��
    for _ in range(q):
        x = random.randint(1, n)      # ���б�ţ�1-indexed��
        s = random.randint(1, g)      # �����Ĳ�Ʒ
        t = random.randint(1, g)      # ��ѯ�Ĳ�Ʒ
        sys.stdout.write(f"{x} {s} {t}\n")

if __name__ == "__main__":
    main()