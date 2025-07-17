import random

def generate_map():
    # 随机生成地图大小（2到10之间）
    n = random.randint(2, 100)
    m = random.randint(2, 100)
    
    # 创建地图网格
    grid = []
    land_positions = []
    
    for i in range(n):
        row = []
        for j in range(m):
            # 60%概率生成陆地，40%概率生成水域
            if random.random() < 0.6:
                # 随机海拔高度0-9
                elevation = random.randint(0, 9)
                row.append(str(elevation))
                land_positions.append((i + 1, j + 1))  # 记录陆地位置(1-based)
            else:
                row.append('#')
        grid.append(row)
    
    # 确保至少有一个陆地格子
    if not land_positions:
        i = random.randint(0, n - 1)
        j = random.randint(0, m - 1)
        elevation = random.randint(0, 9)
        grid[i][j] = str(elevation)
        land_positions.append((i + 1, j + 1))
    
    # 随机选择起始位置（必须是陆地）
    start_x, start_y = random.choice(land_positions)
    
    # 构建输出字符串
    output = []
    output.append(f"{n} {m}")
    for row in grid:
        output.append(''.join(row))
    output.append(f"{start_x} {start_y}")
    
    return '\n'.join(output)

# 生成并输出随机地图数据
print(generate_map())