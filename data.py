import random
import sys

def generate_data(output_file):
    # 生成随机序列长度n (1到20之间)
    n = random.randint(1, 20)
    
    # 生成长度为n的随机整数序列（-9到9之间）
    sequence = [random.randint(-9, 9) for _ in range(n)]
    
    # 生成满足条件的a和b
    a = random.randint(5, 29)
    b = random.randint(a + 1, 30)  # 确保a < b
    
    # 写入输出文件
    with open(output_file, 'w') as f:
        f.write(f"{n}\n")
        f.write(f"{a} {b}\n")
        f.write(" ".join(map(str, sequence)) + "\n")

if __name__ == "__main__":
    # 使用命令行参数指定输出文件，或默认为"output.txt"
    output_filename = sys.argv[1] if len(sys.argv) > 1 else "input.txt"
    generate_data(output_filename)
    print(f"数据已成功写入到 {output_filename}")