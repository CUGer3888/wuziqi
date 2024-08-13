#include<stdio.h>
#include<time.h>
#include<math.h>
#include "tools.h"
#include<windows.h>
IMAGE img_Bg;
IMAGE qipan;
IMAGE img_black;
IMAGE img_white;
//1,ѡ���ս�Ѷ�
//2,ѡ�����ֺ���
//3,��ʼ����
//4,�ж���Ӯ
//5,���¿�ʼ

#define WIDTH    900
#define HEIGHT	 900

bool start = false;

struct Chess {
	BOOL if_click = false;
	BOOL isBlack = false;
	BOOL isWhite = false;
};
struct Chess chess[14][14];
void init() {
	initgraph(WIDTH, HEIGHT);
	loadimage(&img_Bg, "res/�󱳾�.png");
	loadimage(&qipan, "res/����.jpg");
	loadimage(&img_black, "res/black1.jpg");
	loadimage(&img_white, "res/white1.jpg");

}
void updateWindow() {
	BeginBatchDraw();
	putimage(0, 0, &img_Bg);
	putimage(0, 0, &qipan);
	for (int i = 0; i < 14; i++) {
		for (int j = 0; j < 14; j++) {
			if (chess[i][j].if_click != false) {
				if (chess[i][j].isBlack == true) {
					putimagePNG((i - 1) * 68 + 19, (j - 1) * 68 + 19, &img_black);
				}
				else {
					putimagePNG((i - 1) * 68 + 19, (j - 1) * 68 + 19, &img_white);
				}
			}
		}
	}
	EndBatchDraw();
}
int x, y;
int white_black = 1;
bool ifover;
void user_start_click() {
	ExMessage msg;
	if (peekmessage(&msg) && msg.message == WM_LBUTTONDOWN) {
		x = 1 + msg.x / 68;
		y = 1 + msg.y / 68;
		//printf("%d,%d\n", x, y);


		if (chess[x][y].if_click == false) {
			white_black = 1 - white_black;
			chess[x][y].if_click = true;
			if (white_black == 1) {
				chess[x][y].isBlack = true;
			}
			else {
				chess[x][y].isWhite = true;
			}
		}
	}

}
void if_over() {
	for (int i = 0; i <= 14; i++) {
		for (int j = 0; j <= 10; j++) {
			// ��
			if (chess[i][j].isBlack && chess[i][j + 1].isBlack && chess[i][j + 2].isBlack && chess[i][j + 3].isBlack && chess[i][j + 4].isBlack) {
				MessageBox(NULL, "����ʤ��", "��ʾ", MB_OK);
				ifover = true;
			}
			if (chess[i][j].isWhite && chess[i][j + 1].isWhite && chess[i][j + 2].isWhite && chess[i][j + 3].isWhite && chess[i][j + 4].isWhite) {
				MessageBox(NULL, "����ʤ��", "��ʾ", MB_OK);
				ifover = true;
			}
		}
	}

	for (int i = 0; i <= 10; i++) {
		for (int j = 0; j <= 14; j++) {
			// ��
			if (chess[i][j].isBlack && chess[i + 1][j].isBlack && chess[i + 2][j].isBlack && chess[i + 3][j].isBlack && chess[i + 4][j].isBlack) {
				MessageBox(NULL, "����ʤ��", "��ʾ", MB_OK);
				ifover = true;
			}
			if (chess[i][j].isWhite && chess[i + 1][j].isWhite && chess[i + 2][j].isWhite && chess[i + 3][j].isWhite && chess[i + 4][j].isWhite) {
				MessageBox(NULL, "����ʤ��", "��ʾ", MB_OK);
				ifover = true;
			}
		}
	}

	for (int i = 0; i <= 10; i++) {
		for (int j = 0; j <= 10; j++) {
			// ���Խ��� 
			if (chess[i][j].isBlack && chess[i + 1][j + 1].isBlack && chess[i + 2][j + 2].isBlack && chess[i + 3][j + 3].isBlack && chess[i + 4][j + 4].isBlack) {
				MessageBox(NULL, "����ʤ��", "��ʾ", MB_OK);
				ifover = true;
			}
			if (chess[i][j].isWhite && chess[i + 1][j + 1].isWhite && chess[i + 2][j + 2].isWhite && chess[i + 3][j + 3].isWhite && chess[i + 4][j + 4].isWhite) {
				MessageBox(NULL, "����ʤ��", "��ʾ", MB_OK);
				ifover = true;
			}
		}
	}

	for (int i = 14; i >= 4; i--) { // ����ѭ����������ȷ����Խ��
		for (int j = 0; j <= 10; j++) {
			// ���Խ��� /
			if (chess[i][j].isBlack && chess[i - 1][j + 1].isBlack && chess[i - 2][j + 2].isBlack && chess[i - 3][j + 3].isBlack && chess[i - 4][j + 4].isBlack) {
				MessageBox(NULL, "����ʤ��", "��ʾ", MB_OK);
				ifover = true;
			}
			if (chess[i][j].isWhite && chess[i - 1][j + 1].isWhite && chess[i - 2][j + 2].isWhite && chess[i - 3][j + 3].isWhite && chess[i - 4][j + 4].isWhite) {
				MessageBox(NULL, "����ʤ��", "��ʾ", MB_OK);
				ifover = true;
			}
		}
	}
}
int main() {
	init();
	updateWindow();
	while (1) {
		user_start_click();
		updateWindow();
		if_over();
		if (ifover) {
			break;
		}
	}

	system("pause");
	return 0;
}