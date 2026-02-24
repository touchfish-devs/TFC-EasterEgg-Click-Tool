#include <iostream>
#include <windows.h>

HANDLE hd = GetStdHandle(STD_OUTPUT_HANDLE);
HWND hwd = GetConsoleWindow();

#define hideW ShowWindow(hwd, SW_HIDE)
#define showW ShowWindow(hwd, SW_SHOW)
#define setC(color) SetConsoleTextAttribute(hd, color)
#define clC() SetConsoleTextAttribute(hd, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE)

const unsigned int MAX_CLICK_CNT = 1450;

using namespace std;

int main(int argc, char* argv[]) {
	cout << "请将您的鼠标指针移动到 TouchFish Client 的关于界面中的 TouchFish Client Logo 下的 “TouchFish Client” 文字上。\n注意：在程序运行过程中不要切换到其他页面.";
	system("pause");
	setC(FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << "\n您还有10秒的操作时间，然后本窗口将隐藏，点击过程中不可取消，请慎重考虑！\n此操作约7s左右，与您的电脑性能有关。\n如放弃点击，您可以直接关闭本窗口.";
	clC();
	Sleep(10200);
	printf("\n开始点击。共 %d 次，为了确保触发完整点击 %d 次。\n\n", MAX_CLICK_CNT, MAX_CLICK_CNT + 5);
	Sleep(500);
	hideW;
	for(unsigned i = 1; i <= MAX_CLICK_CNT + 5; i++) {
		if (i % 100 == 0) {
			printf("[DEBUG] 已点击 %d 次.\n", i);
		}
		mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
	}
	Sleep(1200);
	MessageBoxA(NULL, "已完成全部点击", "TouchFish Client 彩蛋速通", MB_ICONINFORMATION);
	showW;
	cout << "\n已完成全部点击";
	
	return 0;
}
