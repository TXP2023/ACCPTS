// 对拍.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <Windows.h>

#define _LPCWSTR (LPCWSTR)

int main() {
    system("g++ \"D:\\bobi2\\development\\work spaces\\test\\my_code.cpp\" -o \"D:\\bobi2\\development\\work spaces\\test\\my_code.exe\"");
    system("g++ \"D:\\bobi2\\development\\work spaces\\test\\correct_code.cpp\" -o \"D:\\bobi2\\development\\work spaces\\test\\correct_code.exe\"");
    //system("g++ correct_code.cpp -o correct_code.exe");
    printf("Proceed with run?[Y:N]");
    char ch = getchar();
    while (true) {
        if (ch == 'N') {
            exit(0);
        }
        if (ch == 'Y') {
            break;
        }
        printf("Proceed with run?[Y:N]");
        ch = getchar();
    }
    while (true) {
        system("python \"D:\\bobi2\\development\\work spaces\\test\\data.py\"");
        system("\"D:\\bobi2\\development\\work spaces\\test\\correct_code.exe\"");
        system("\"D:\\bobi2\\development\\work spaces\\test\\my_code.exe\"");
        if (system("fc /W \"D:\\bobi2\\development\\work spaces\\test\\output.txt\" \"D:\\bobi2\\development\\work spaces\\test\\ans.txt\"")) {
            MessageBox(NULL, _LPCWSTR "End of Test\n There are differences in the output file", _LPCWSTR "message", NULL);
            exit(0);
        }
    }

}
