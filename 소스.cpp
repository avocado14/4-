#include<Bangtal.h>
#include <stdio.h>
#include <time.h>
#include <iostream>
#pragma comment(lib, "Bangtal.lib")
#pragma warning(disable:4996)

SceneID scene1, scene2;
ObjectID problem, startbutton, endbutton, restartbutton;
TimerID timer1;
ObjectID p[4][4];
clock_t startclock, endclock;
double result;

int cachex, cachey;

int locationX[4][4] = {
		{ 280, 460, 640, 820},
		{ 280, 460, 640, 820},
		{ 280, 460, 640, 820},
		{ 280, 460, 640, 820}
};
int locationY[4][4] = {
		{ 540, 540, 540, 540},
		{ 360, 360, 360, 360},
		{ 180, 180, 180, 180},
		{ 0,0, 0, 0}
};
int baseX[4][4] = {
		{ 280, 460, 640, 820},
		{ 280, 460, 640, 820},
		{ 280, 460, 640, 820},
		{ 280, 460, 640, 820}
};
int baseY[4][4] = {
		{ 540, 540, 540, 540},
		{ 360, 360, 360, 360},
		{ 180, 180, 180, 180},
		{ 0,0, 0, 0}
};

void change(int i, int j) {

	cachex = locationX[i][j];
	cachey = locationY[i][j];
	locationX[i][j] = locationX[3][3];
	locationY[i][j] = locationY[3][3];
	locationX[3][3] = cachex;
	locationY[3][3] = cachey;
	locateObject(p[i][j], scene1, locationX[i][j], locationY[i][j]);
	locateObject(p[3][3], scene1, locationX[3][3], locationY[3][3]);

}


void startGame1() {
	// ·£´ýÇÔ¼ö ÀÌ¿ëÇØ¼­
	enterScene(scene1);
	showObject(restartbutton);
	startclock = clock();
	int m = 0;
	
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {

			if (locationX[i][j] == baseX[i][j] && locationY[i][j] == baseY[i][j]) {
				int n = 40;
				int z = rand() % n;
				for (int i = 0; i < z; i++) {
					int n = 4;
					int a = rand() % n;
					if (a == 0) {
						for (int i = 0; i < 4; i++) {
							for (int j = 0; j < 4; j++) {
								if (locationY[i][j] + 180 == locationY[3][3] && locationX[i][j] == locationX[3][3]) {
									change(i, j);
								}
							}
						}
					}
					else if (a == 1) {
						for (int i = 0; i < 4; i++) {
							for (int j = 0; j < 4; j++) {
								if (locationX[i][j] - 180 == locationX[3][3] && locationY[i][j] == locationY[3][3]) {
									change(i, j);
								}
							}
						}
					}
					else if (a == 2) {
						for (int i = 0; i < 4; i++) {
							for (int j = 0; j < 4; j++) {
								if (locationY[i][j] - 180 == locationY[3][3] && locationX[i][j] == locationX[3][3]) {
									change(i, j);
								}
							}
						}
					}
					else if (a == 3) {
						for (int i = 0; i < 4; i++) {
							for (int j = 0; j < 4; j++) {
								if (locationX[i][j] + 180 == locationX[3][3] && locationY[i][j] == locationY[3][3]) {
									change(i, j);
								}
							}
						}
					}
				}

			}
			else {
				
			}
		}
		}
	

}
void end() {
	int m = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (locationX[i][j] == baseX[i][j] && locationY[i][j] == baseY[i][j]) {
				
			}
			else {
				startGame(scene1);
			}
			
		}
	}
	if (m == 0) {
		showMessage("³¡");
		endclock = clock();
		result = (double)(endclock - startclock);

		
		
		/*cout << "result : " << ((result) / CLOCKS_PER_SEC) << " seconds" << endl;
		printf("%f", result / CLOCKS_PER_SEC);*/
		char buf[256];
		sprintf_s(buf, "°É¸°½Ã°£ : %0.2fÃÊ          ", ((result) / CLOCKS_PER_SEC), scene1);
		showMessage(buf); 
		

		//endGame();
		
	}
	


}
void problemsolver() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			locationX[i][j] = baseX[i][j];
			locationY[i][j] = baseY[i][j];
			locateObject(p[i][j], scene1, locationX[i][j], locationY[i][j]);
			
		}
	}
}



void mouseCallback(ObjectID object, int x, int y, MouseAction action)
{
	// ÆÛÁñ
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (object == p[i][j]) {
				if (action == MOUSE_DRAG_LEFT) {
					if (locationX[i][j] - 180 == locationX[3][3] && locationY[i][j] == locationY[3][3]) {
						change(i, j);
						end();
					}
					else {
						showMessage("¿À·ù");
					}
				}
				else if (action == MOUSE_DRAG_RIGHT) {
					if (locationX[i][j] + 180 == locationX[3][3] && locationY[i][j] == locationY[3][3]) {
						change(i, j);
						end();
					}
					else {
						showMessage("¿À·ù");
					}
				}
				else if (action == MOUSE_DRAG_UP) {
					if (locationY[i][j] + 180 == locationY[3][3] && locationX[i][j] == locationX[3][3]) {
						change(i, j);
						end();
					}
					else {
						showMessage("¿À·ù");
					}
				}
				else if (action == MOUSE_DRAG_DOWN) {
					if (locationY[i][j] - 180 == locationY[3][3] && locationX[i][j] == locationX[3][3]) {
						change(i, j);
						end();
					}
					else {
						showMessage("¿À·ù");
					}
				}
				else if (action == MOUSE_CLICK) {
					if (locationX[i][j] - 180 == locationX[3][3] && locationY[i][j] == locationY[3][3]) {
						change(i, j);
						end();
					}
					else if (locationX[i][j] + 180 == locationX[3][3] && locationY[i][j] == locationY[3][3]) {
						change(i, j);
						end();
					}
					else if (locationY[i][j] + 180 == locationY[3][3] && locationX[i][j] == locationX[3][3]) {
						change(i, j);
						end();
					}
					else if (locationY[i][j] - 180 == locationY[3][3] && locationX[i][j] == locationX[3][3]) {
						change(i, j);
						end();
					}
					else {
						showMessage("¿À·ù");
					}
				}
			}

		}

	}
	if (object == startbutton) {
		startGame1();
	}
	else if (object == endbutton) {
		problemsolver();
		end();
	}
	else if (object == restartbutton) {
		startGame1();
		
	}
}

int main() {

	setMouseCallback(mouseCallback);


	scene1 = createScene("4°öÇÏ±â4", "¹è°æ.png");
	scene2 = createScene("4°öÇÏ±â4", "¿øº».png");

	/*problem = createObject("problem", "¹è°æ.png");
	locateObject(problem, scene1, 0, 0);
	showObject(problem);*/

	
	p[0][0] = createObject("ÆÛÁñ", "00.png");
	p[1][0] = createObject("ÆÛÁñ", "10.png");
	p[2][0] = createObject("ÆÛÁñ", "20.png");
	p[3][0] = createObject("ÆÛÁñ", "30.png");

	p[0][1] = createObject("ÆÛÁñ", "01.png");
	p[1][1] = createObject("ÆÛÁñ", "11.png");
	p[2][1] = createObject("ÆÛÁñ", "21.png");
	p[3][1] = createObject("ÆÛÁñ", "31.png");
	
	p[0][2] = createObject("ÆÛÁñ", "02.png");
	p[1][2] = createObject("ÆÛÁñ", "12.png");
	p[2][2] = createObject("ÆÛÁñ", "22.png");
	p[3][2] = createObject("ÆÛÁñ", "32.png");

	p[0][3] = createObject("ÆÛÁñ", "03.png");
	p[1][3] = createObject("ÆÛÁñ", "13.png");
	p[2][3] = createObject("ÆÛÁñ", "23.png");
	p[3][3] = createObject("ÆÛÁñ", "33.png");
	


	startbutton = createObject("½ÃÀÛ", "start.png");
	locateObject(startbutton, scene2, 90, 80);
	showObject(startbutton);

	endbutton = createObject("³¡", "answer.png");
	locateObject(endbutton, scene1, 90, 600);
	showObject(endbutton);
	
	restartbutton = createObject("Àç½ÃÀÛ", "restart.png");
	locateObject(restartbutton, scene1, 90, 380);

	
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			
			locateObject(p[i][j], scene1, locationX[i][j], locationY[i][j]);
			showObject(p[i][j]);
		}
	}
	
	char buf[256];
	sprintf_s(buf, "%d", scene1);
	showMessage(buf);

	showMessage("ÆÛÁñ Àß ¸ÂÃç º¸¼¼¿ä");

	startGame(scene2);
	
	
	




}


/*char buf[256];
sprintf_s(buf, "¾Æ¾ß", scene1);
showMessage(buf);*/