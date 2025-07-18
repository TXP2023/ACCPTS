// 对拍.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <Windows.h>
#include <tchar.h>

#define _LPCWSTR (LPCWSTR)
#define AUTO_PATH     true

int main() {
#if AUTO_PATH
    //编译C++源代码并试运行随机数据Python文件
    system("g++ my_code.cpp -o my_code.exe");
    system("g++ correct_code.cpp -o correct_code.exe");
    system("python data.py > input.txt");
#else
    system("g++ \"D:\\bobi2\\development\\work spaces\\test\\my_code.cpp\" -o \"D:\\bobi2\\development\\work spaces\\test\\my_code.exe\"");
    system("g++ \"D:\\bobi2\\development\\work spaces\\test\\correct_code.cpp\" -o \"D:\\bobi2\\development\\work spaces\\test\\correct_code.exe\"");
#endif // AUTO_PATH


    //system("g++ correct_code.cpp -o correct_code.exe");
    printf("Proceed with run?[Y:N]");
    char ch = getchar();
    while (true) {
        if (ch == 'N' || ch == 'n') {
            exit(0);
        }
        if (ch == 'Y' || ch == 'y') {
            break;
        }
        printf("Proceed with run?[Y:N]");
        ch = getchar();
    }
    while (true) {
#if AUTO_PATH
        //system("python \"data.py\"");
        system("python data.py > input.txt");
        system("correct_code.exe < input.txt > ans.txt");
        system("my_code.exe < input.txt > output.txt");


        if (system("fc /W \"output.txt\" \"ans.txt\"")) {
            system("correct_code.exe < input.txt > ans.txt");
            system("my_code.exe < input.txt > output.txt");
            Sleep(10000);
            if (system("fc /W \"output.txt\" \"ans.txt\"")) {
                if (MessageBox(NULL, _T("测试暂停 出现异常数据. 是否结束对拍？"), _T("Message"), MB_YESNO | MB_ICONASTERISK) == IDYES) {
                    exit(0);
                }
            }
        }
#else
        system("python \"D:\\bobi2\\development\\work spaces\\test\\data.py\"");
        system("\"D:\\bobi2\\development\\work spaces\\test\\correct_code.exe\"");
        system("\"D:\\bobi2\\development\\work spaces\\test\\my_code.exe\"");
        if (system("fc /W \"D:\\bobi2\\development\\work spaces\\test\\output.txt\" \"D:\\bobi2\\development\\work spaces\\test\\ans.txt\"")) {
            MessageBox(NULL, _LPCWSTR "End of Test\n There are differences in the output file", _LPCWSTR "message", NULL);
            exit(0);
        }
#endif // AUTO_PATH

    }

}
