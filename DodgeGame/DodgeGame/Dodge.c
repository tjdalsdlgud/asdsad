// ���� 1 �ϼ�����. �ڵ� �Ϻ� ����, ������ ����
// ������ ���� ���� �Ұ��� ����� ��.
#include<stdio.h>       
#include<conio.h>
#include<Windows.h>          
#include<time.h> 
#include<stdlib.h> 


#define nemomax 30
#define wally 24
#define wallx 2
#define wall2x 42
#define wall3x 20
// ���̵����ھ� 
#define lv2 3500
#define lv3 7000
#define lv4 10500
#define lv5 14000



struct nemo1 {//�׸� ����ü
	int x, y;
	int speed;
	int bkspeed;
	int color;
};



struct ningen1 { //�÷��̾� ����ü
	int x, y;
};

typedef struct nemo1 nemo; //�׸� �̸� ����
typedef struct ningen1 nins; //��ĳ���� �̸� ����


void gotoxy(int x, int y); // ��ǥ�̵��Լ�
void textcolor(int color); // �÷� �Լ�
void dos_size(); // â ������
void nemo_spawnpos(nemo *ne); // �׸� ������ġ,�÷�
void nemo_speed(nemo *ne, int le, int le2); // �׸� ���ǵ�
void showmain(); // ���θ޴� 
void showcredit(); // ũ�����޴�
void maps(); // ������
void showend(); //���ӿ��� �޽���





void gotoxy(int x, int y) // ��ǥ�̵��Լ�

{

	COORD pos = { x, y };

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

}

void textcolor(int color) // �÷� �Լ� 

{

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);

}

void dos_size() // â ������

{

	system("mode con: cols=46 lines=25");

}



void nemo_spawnpos(nemo *ne) // �׸� ������ġ,�÷�

{

	// ne->x= (rand()%(wallx+61))+(wallx+2);

	ne->x = ((rand() % 19) * 2) + 4;

	ne->y = rand() % 4;

	ne->color = (rand() % 15) + 1;

}



void nemo_speed(nemo *ne, int le, int le2) // �׸� ���ǵ�

{

	ne->speed = rand() % le + le2;

}



void showmain() // ���θ޴� 

{

	// ���θ޴�

	gotoxy(16, 10);

	printf("���� ���� : 1�� \n");

	gotoxy(18, 12);

	printf("���� : 2�� \n");

	gotoxy(17, 14);

	printf("������ : 3�� \n");

	gotoxy(20, 22);

	printf("����Ű \n");

	gotoxy(14, 24);

	printf("���� : �� , ������: �� \n");

}



void showcredit() // ũ�����޴�

{

	gotoxy(15, 10);

	printf(" I�� ��������\n");

	gotoxy(10, 12);

	printf(" ���� : ���ƹ�, ǥ����, ����ȯ \n");


	gotoxy(8, 16);

	printf("�ƹ� ��ư�̳� Ŭ���� ���Ӹ޴��� \n");

}



void maps() // ������

{

	int i, j;

	int map[26][22] =

	{

		{ 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },

	{ 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },

	{ 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },

	{ 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },

	{ 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },

	{ 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },

	{ 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },

	{ 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },

	{ 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },

	{ 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },

	{ 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },

	{ 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },

	{ 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },

	{ 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },

	{ 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },

	{ 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },

	{ 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },

	{ 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },

	{ 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },

	{ 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },

	{ 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },

	{ 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },

	{ 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },

	{ 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },

	{ 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },

	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }

	};

	for (i = 0; i < 25; i++) {

		for (j = 0; j < 22; j++)
		{
			textcolor(7);
			if (map[i][j] == 1) {
				printf("��");
			}

			else {

				printf("  ");

			}

		}
		printf("\n");
	}

}

void showend()

{

	gotoxy(18, 8);

	printf("Game Over \n");

}


int main() {

	int i; //for���� ����
	int regame = 1; // ������ ����
	int music = 0;
	int tx; // ��ư ����
	int levels = 0; // ���ӳ��̵� ���� 
	int clo = 0, bkcl = 0; // ���ھ� ���� , ���ھ� ��� ����
	int lvlcolor = 10; // ���ھ�,���̵� �������� ���� 
	int level[5] = { 60, 22, 15, 5, 1 };
	int level2[5] = { 30, 3, 2, 1, 1 };
	char *levelname[5] = { "Easy", "Normal", "Hard  ", "Nightmare", "HELL     " }; // ���̵� �̸�����
	char move; // ĳ���� �̵�����

	dos_size(); //����â������ �Լ�
	srand(time(NULL)); // �����Լ�
	system("title �׸� ���ϱ� ��������");  // ���� Ÿ��Ʋ �̸�

	nins nin; // �÷��̾� ����ü 
	nemo nem[nemomax]; // �׸� ����ü 

	nin.x = 22; // �÷��̾� ���� x��ǥ
	nin.y = wally - 2; // �÷��̾� ���� y��ǥ
	showmain(); // ���θ޴� ���
	tx = _getch(); // ��ư

	while (1) // ���Ӹ��θ޴� 
	{
		if (tx == 49) {

			system("cls");
			bkcl = clock();
			break;
		}

		else if (tx == 50) {
			system("cls");
			showcredit();
			if (_getch()) {
				system("cls");
				showmain();
				tx = _getch();
			}

		}

		else if (tx == 51) // ������ 

			exit(0);

		else // �� �� Ŭ���� ���۵�

			tx = _getch();
	}



	while (1) // ���ӽ����� 
	{

		if (regame) {

			maps(); // ������
			for (i = 0; i < nemomax; ++i) {
				nemo_spawnpos(&nem[i]);
				nemo_speed(&nem[i], level[levels], level2[levels]);
				nem[i].bkspeed = nem[i].speed;
				gotoxy(nem[i].x, nem[i].y);
				textcolor(nem[i].color);
				printf("��");
			}

			regame = 0;

		}
		clo = (clock() - bkcl) / 10; // ���ھ�� ���α׷�������� ���ӵǴ� �ð����� ���Ӹ޴����ִ� �ð��� ���� 10���� ������.

		if (clo >= lv2 && levels == 0) // ���̵��� ����.
		{

			lvlcolor = 14;
			levels = 1;
		}
		else if (clo >= lv3 && levels == 1) {
			lvlcolor = 12;
			levels = 2;
		}

		else if (clo >= lv4 && levels == 2) {
			lvlcolor = 9;
			levels = 3;

		}

		else if (clo >= lv5 && levels == 3) {

			lvlcolor = 13;
			levels = 4;

		}

		gotoxy(2, 24);
		textcolor(lvlcolor);
		printf("Score : %d - Level : %s", clo, levelname[levels]); // ���ھ� ���̵���

		for (i = 0; i < nemomax; ++i) {

			if (nem[i].y == nin.y && nem[i].x == nin.x) //              ���ӿ���
			{

				showend();
				gotoxy(10, 12);
				printf("���� : %d  - ���� : %s \n", clo, levelname[levels]);
				gotoxy(12, 14);
				printf("Re  (1)  -  Exit  (2) \n");
				while (1) // ���� ����Ű�� ������� ����Ű�� ��������츦 ���� while�� 
				{
					switch (_getch())
					{
					case 49: // 1�� Ŭ����
						regame = 1;
						bkcl = clock();
						clo = (clock() - bkcl) / 10;
						levels = 0;
						lvlcolor = 10;
						break;

					case 50:
						exit(0);
						break;
					default:
						continue;
					}

					break;

				}

			}

		}

		gotoxy(nin.x, nin.y);

		textcolor(15);

		printf("��");

		Sleep(45);

		for (i = 0; i < nemomax; i++) // �׸� �̵��κ�

		{

			if (nem[i].speed>0)
				nem[i].speed -= 1;

			else

			{

				if (nem[i].y < wally - 2) // ���� ���˽� �ٽ� ���� �ö���� �Ǵ� �κ�

				{

					gotoxy(nem[i].x, nem[i].y);
					printf(" ");
					nem[i].y += 1;
					gotoxy(nem[i].x, nem[i].y);
					textcolor(nem[i].color);
					printf("��");

				}

				else

				{
					gotoxy(nem[i].x, nem[i].y);
					printf(" ");
					nemo_spawnpos(&nem[i]);
					nemo_speed(&nem[i], level[levels], level2[levels]);
					nem[i].bkspeed = nem[i].speed;

					gotoxy(nem[i].x, nem[i].y);

				}

			}

		}

		if (_kbhit())  // �÷��̾� �̵��κ�

		{

			gotoxy(nin.x, nin.y);

			move = _getch();

			printf(" ");



			switch (move)

			{

			case 75:

				nin.x -= 2;

				if (nin.x<wallx + 2)

					nin.x = wallx + 2;

				break;

			case 77:

				nin.x += 2;

				if (nin.x>wall2x - 2)

					nin.x = wall2x - 2;

				break;

			}

		}

	}

}
