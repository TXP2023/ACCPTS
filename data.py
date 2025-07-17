import random
import sys

def main():
    # 设置随机种子，确保可复现
    random.seed(0)
    
    # 生成n, m, g, q
    n = random.randint(2, 10)  # 城市数
    max_edges = n * (n - 1) // 2  # 最大边数
    m_upper = min(10, max_edges)  # m上限
    m = random.randint(n - 1, m_upper)  # 边数，至少n-1保证连通
    
    g = random.randint(1, 10)  # 工业产品种类数
    q = random.randint(1, 10)     # 询问数
    
    # 输出第一行: n m
    sys.stdout.write(f"{n} {m}\n")
    
    # 初始化位图（用于记录已添加的边）
    total_bits = max_edges
    if total_bits > 0:
        bit_arr = bytearray((total_bits + 7) // 8)
    else:
        bit_arr = bytearray()
    
    # 生成生成树（n-1条边）
    for u in range(1, n):  # u从1到n-1（0-indexed）
        v = random.randint(0, u - 1)  # 随机选择v（0-indexed，v < u）
        # 输出边（转换为1-indexed，小节点在前）
        sys.stdout.write(f"{v + 1} {u + 1}\n")
        # 更新位图（记录边(u, v)，u > v）
        pos = u * (u - 1) // 2 + v
        byte_index = pos // 8
        bit_index = pos % 8
        if byte_index < len(bit_arr):
            bit_arr[byte_index] |= (1 << bit_index)
    
    # 随机添加剩余边（m - (n-1)条）
    add_edge = m - (n - 1)
    while add_edge > 0:
        u = random.randint(0, n - 1)
        v = random.randint(0, n - 1)
        if u == v:
            continue
        if u < v:
            u, v = v, u  # 保证u > v
        pos = u * (u - 1) // 2 + v
        byte_index = pos // 8
        bit_index = pos % 8
        # 检查边是否已存在
        if byte_index < len(bit_arr) and (bit_arr[byte_index] & (1 << bit_index)):
            continue
        # 添加新边
        if byte_index < len(bit_arr):
            bit_arr[byte_index] |= (1 << bit_index)
        sys.stdout.write(f"{v + 1} {u + 1}\n")
        add_edge -= 1
    
    # 输出工业产品种类数g
    sys.stdout.write(f"{g}\n")
    
    # 生成g种产品的依赖关系
    dep = [0] * (g + 1)  # dep[0]未使用，dep[i]表示产品i的原材料
    for i in range(1, g + 1):
        if i == 1:
            dep[i] = 0  # 第一种产品无依赖
        else:
            if random.random() < 0.2:  # 20%概率无需原材料
                dep[i] = 0
            else:
                dep[i] = random.randint(1, i - 1)  # 依赖之前的产品
    
    # 输出依赖关系
    for i in range(1, g + 1):
        sys.stdout.write(f"{dep[i]}\n")
    
    # 输出询问数q
    sys.stdout.write(f"{q}\n")
    
    # 生成q个询问
    for _ in range(q):
        x = random.randint(1, n)      # 城市编号（1-indexed）
        s = random.randint(1, g)      # 生产的产品
        t = random.randint(1, g)      # 查询的产品
        sys.stdout.write(f"{x} {s} {t}\n")

if __name__ == "__main__":
    main()