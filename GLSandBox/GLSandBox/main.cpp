/**
 * @file main.cpp
 * @brief main�t�@�C��
 *
 * glut�ɂ��OpenGL�T���h�{�b�N�X
 * OpenGL, �E��ny-up
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

// �v���g�^�C�v�錾
void InitWindow(const char* const winName);
void Init();
void display();
void update();
void keyboard(unsigned char key, int x, int y);
void specialKey(int key, int x, int y);

/**
 * @brief ���C���֐�
 *
 * @param [in] argc �R�}���h���C�������̌�
 * @param [in] argv �e�����̓��͕�����
 * @return �X�e�[�^�X
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
 * @brief �E�B���h�E�̏�����
 *
 * @param [in] winName �쐬����E�B���h�E�̖��O
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
 * @brief ������
 *
 */
void Init()
{
}

/**
 * @brief �A�C�h���R�[���o�b�N
 *
 */
void update()
{
	glutPostRedisplay();
}

/**
 * @brief �f�B�X�v���C�R�[���o�b�N
 *
 */
void display()
{
  // �r���[�|�[�g�ݒ�
	glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
	// �w�i�N���A�A�`�揀��
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glEnable(GL_DEPTH_TEST);

	// ���e�ϊ�
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(35.0, (double)WINDOW_WIDTH / (double)WINDOW_HEIGHT, 1.0, 3000.0);

	// ���f���r���[�ϊ�
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
 * @brief �L�[�{�[�h�R�[���o�b�N
 *
 */
void keyboard(unsigned char key, int x, int y)
{
	switch(key){
	case '\033':	// ESC�L�[
		exit(0);
		break;

	default:
		break;
	}
}

/**
 * @brief ����L�[�R�[���o�b�N
 *
 */
void specialKey(int key, int x, int y)
{
}

