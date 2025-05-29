import random
import os

CHARSET = [  
    'a', 'b', 'c'  
]
STRING_LENGTH = 10
OUTPUT_PATH = "input.txt"  
def generate_new_string():
    secure_random = random.SystemRandom()
    new_string = ''.join([secure_random.choice(CHARSET) for _ in range(STRING_LENGTH)])

    # ԭ�ӻ�д�����
    temp_file = OUTPUT_PATH + ".tmp"
    with open(temp_file, 'w') as f:
        f.write(new_string)
        f.flush()
        os.fsync(f.fileno())

    # �滻���ļ�
    os.replace(temp_file, OUTPUT_PATH)
    return new_string


if __name__ == '__main__':
    result = generate_new_string()

    print(f"{STRING_LENGTH}  {os.path.abspath(OUTPUT_PATH)}")
    print(f"{result[:4]}...{result[-4:]}")  
    