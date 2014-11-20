/**
 * @file main.cpp
 * @brief mainファイル
 *
 * glutによるOpenGLサンドボックス
 * OpenGL, 右手系y-up
 * 
 * @author ashkeys
 */

// include
#include <iostream>
#include <gl/glut.h>

// define
#define WINDOW_X			100
#define WINDOW_Y			100
#define WINDOW_WIDTH	800
#define WINDOW_HEIGHT	600

// プロトタイプ宣言
void InitWindow(const char* const winName);
void Init();
void display();
void update();
void keyboard(unsigned char key, int x, int y);
void specialKey(int key, int x, int y);

/**
 * @brief メイン関数
 *
 * @param [in] argc コマンドライン引数の個数
 * @param [in] argv 各引数の入力文字列
 * @return ステータス
 */
int main(int argc, char* argv[])
{
  glutInit(&argc, argv);
	InitWindow(argv[0]);
	Init();

	std::cout << "Vendor: " << glGetString(GL_VENDOR) << std::endl;
  std::cout << "GPU: " << glGetString(GL_RENDERER) << std::endl;
  std::cout << "OpenGL ver. " << glGetString(GL_VERSION) << std::endl;

	glutIdleFunc(update);
  glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(specialKey);
  
	glutMainLoop();
  return 0;
}

/**
 * @brief ウィンドウの初期化
 *
 * @param [in] winName 作成するウィンドウの名前
 */
void InitWindow(const char* const winName)
{
	glutInitWindowPosition(WINDOW_X, WINDOW_Y);
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
	glutCreateWindow(winName);
	glClearColor(0.0, 0.0, 0.0, 1.0);
}

/**
 * @brief 初期化
 *
 */
void Init()
{
}

/**
 * @brief アイドルコールバック
 *
 */
void update()
{
	glutPostRedisplay();
}

/**
 * @brief ディスプレイコールバック
 *
 */
void display()
{
  // ビューポート設定
	glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
	// 背景クリア、描画準備
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glEnable(GL_DEPTH_TEST);

	// 投影変換
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(35.0, (double)WINDOW_WIDTH / (double)WINDOW_HEIGHT, 1.0, 3000.0);

	// モデルビュー変換
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0, 0.0, 500.0, 0.0, 0.0, -1000.0, 0.0, 1.0, 0.0);

	double x, y, z, pitch, yaw, roll;
	x = y = z = pitch = yaw = roll = 10.0;

	glPushMatrix();
	{
		glTranslated(x, y, z);
		glRotated(yaw, 0.0, 1.0, 0.0);
		glRotated(pitch, 1.0, 0.0, 0.0);
		glRotated(roll, 0.0, 0.0, 1.0);
		glutSolidCube(100.0);
	}
	glPopMatrix();

	glDisable(GL_DEPTH_TEST);

	glutSwapBuffers();
}

/**
 * @brief キーボードコールバック
 *
 */
void keyboard(unsigned char key, int x, int y)
{
	switch(key){
	case '\033':	// ESCキー
		exit(0);
		break;

	default:
		break;
	}
}

/**
 * @brief 特殊キーコールバック
 *
 */
void specialKey(int key, int x, int y)
{
}

