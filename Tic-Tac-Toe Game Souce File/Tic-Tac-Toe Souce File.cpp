#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int win = 0;
int lose = 0;
int none = 0;

void help(void) {
	printf("-------------------------------------------------\n");
	printf("�����ڴ� O, ��ǻ��/�Խ�Ʈ�� X�� ǥ���ϸ�\n");
	printf("�Է°� 'a b'�� a��° �� b��° ĭ�� �ǹ��մϴ�\n\n");
	printf("����");
	printf("\n   0   1   2\n");
	printf(" |---|---|---|\n");
	printf("0|   |   |   |\n");
	printf(" |---|---|---|\n");
	printf("1|   |   |   |\n");
	printf(" |---|---|---|\n");
	printf("2|   |   |   |\n");
	printf(" |---|---|---|\n\n");
	printf("a�� b�� 0���� 2 ���� �����Դϴ�\n");
	printf("��ǻ�Ϳ� �÷��� �� ���\n");
	printf("�����ڰ� ��ǥ�� �����ϴ� ���\n");
	printf("��ǻ�͵� ���� ��ǥ�� �����մϴ�\n");
	printf("-------------------------------------------------\n");
	printf("������������ ���ư����� '0'�� �Է��ϰ� Enter�� ���ּ���\n���� Zero �Դϴ�\n");
	int check = 1;
	scanf("%d", &check);
	while (check != 0) {
		printf("\n��ȿ���� ���� �����Դϴ�\n�ٽ� �Է����ּ���\n");
		scanf("%d", &check);
	}
}

void play_p2p(void) {
	printf("������ �����մϴ�\n");
	printf("Good Luck\n\n");

	char game[3][3];					//��ǥ�� ����

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			game[i][j] = ' ';
		}
	}									//�ʱ�ȭ

	int x, y;
	char mark;

	char checkwinner = 'n';//none,human,computer �ڵ庹��/����
	for (int i = 1; i <= 9; i++) {			//���ӽ���
														//��� ���� �Է�
		mark = (i % 2 == 0) ? 'X' : 'O';
		//OX�Է¼��� ���� �� �Է�

		printf("%c�� �����Դϴ�\n��ǥ�� �Է��� �ּ���\n", mark);
		scanf("%d %d", &y, &x);
		while (x < 0 || x>2 || y < 0 || y>2 || game[y][x] != ' ') {
			if (x < 0 || x>2 || y < 0 || y>2) {
				printf("���� ���� ��ǥ�Դϴ�\n�ٸ� ��ǥ�� �Է����ּ���\n");
				scanf("%d %d", &y, &x);
				continue;
			}
			if (game[y][x] != ' ') {
				printf("�̹� ������ ��ǥ�Դϴ�\n�ٸ� ��ǥ�� �Է����ּ���\n");
				scanf("%d %d", &y, &x);
				continue;
			}
		}

		game[y][x] = mark;

		printf("\n   0   1   2\n");
		printf(" |---|---|---|\n");
		printf("0| %c | %c | %c |\n", game[0][0], game[0][1], game[0][2]);
		printf(" |---|---|---|\n");
		printf("1| %c | %c | %c |\n", game[1][0], game[1][1], game[1][2]);
		printf(" |---|---|---|\n");
		printf("2| %c | %c | %c |\n", game[2][0], game[2][1], game[2][2]);
		printf(" |---|---|---|\n\n");		//���� �����Ȳ ���

		if (((game[0][0] == 88) && (game[0][1] == 88) && (game[0][2] == 88)) ||
			((game[1][0] == 88) && (game[1][1] == 88) && (game[1][2] == 88)) ||
			((game[2][0] == 88) && (game[2][1] == 88) && (game[2][2] == 88)) ||
			((game[0][0] == 88) && (game[1][0] == 88) && (game[2][0] == 88)) ||
			((game[0][1] == 88) && (game[1][1] == 88) && (game[2][1] == 88)) ||
			((game[0][2] == 88) && (game[1][2] == 88) && (game[2][2] == 88)) ||
			((game[0][0] == 88) && (game[1][1] == 88) && (game[2][2] == 88)) ||
			((game[0][2] == 88) && (game[1][1] == 88) && (game[2][0] == 88))) {
			checkwinner = 'c';
			break;
		}
		else if (((game[0][0] == 79) && (game[0][1] == 79) && (game[0][2] == 79)) ||
			((game[1][0] == 79) && (game[1][1] == 79) && (game[1][2] == 79)) ||
			((game[2][0] == 79) && (game[2][1] == 79) && (game[2][2] == 79)) ||
			((game[0][0] == 79) && (game[1][0] == 79) && (game[2][0] == 79)) ||
			((game[0][1] == 79) && (game[1][1] == 79) && (game[2][1] == 79)) ||
			((game[0][2] == 79) && (game[1][2] == 79) && (game[2][2] == 79)) ||
			((game[0][0] == 79) && (game[1][1] == 79) && (game[2][2] == 79)) ||
			((game[0][2] == 79) && (game[1][1] == 79) && (game[2][0] == 79))) {
			checkwinner = 'h';
			break;
		}								//���а���
	}									//��������
	switch (checkwinner) {
	case 'n':
		printf("�̹� ������ ���º� �Դϴ�\n");
		break;
	case 'h':
		printf("O�� �̰���ϴ�\n");
		break;
	case 'c':
		printf("X�� �̰���ϴ�\n");
		break;
	}
	printf("������ �����մϴ�\n\n");
}
//1. �θ��̼� �÷��� �ڵ�
//�ܼ��� ���� �����ư��鼭 �÷���
//�·��� ������� �ʴ� ���
void play_with_computer_easy(void) {

	char whoisfirst = 'n';
	printf("���� ���� �����Ұǰ���?\nHuman or Computer?(h/c)\n");
	scanf(" %c", &whoisfirst);
	while (!((whoisfirst == 'h') || (whoisfirst == 'c'))) {
		printf("�߸��� �Է��Դϴ�\n�ٽ� �Է����ּ���\n");
		scanf(" %c", &whoisfirst);
	}

	printf("������ �����մϴ�\n");
	printf("Good Luck\n\n");

	char game[3][3];					//��ǥ�� ����

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			game[i][j] = ' ';
		}
	}									//�ʱ�ȭ

	int x, y;
	char mark;

	char checkwinner = 'n';//none,human,computer
	for (int i = 1; i <= 9; i++) {			//���ӽ���
															//��ǻ�Ͷ� ���
		mark = (i % 2 == 0) ? 'X' : 'O';
		//OX�Է¼��� ���� �� �Է�

		int whoschance;
		switch (whoisfirst) {
		case 'h':whoschance = i % 2; break;
		case 'c':whoschance = (i + 1) % 2; break;
		}

		switch (whoschance) {
		case 1:
			printf("��ǥ�� �Է��� �ּ���\n");
			scanf("%d %d", &y, &x);
			while (x < 0 || x>2 || y < 0 || y>2 || game[y][x] != ' ') {
				if (x < 0 || x>2 || y < 0 || y>2) {
					printf("���� ���� ��ǥ�Դϴ�\n�ٸ� ��ǥ�� �Է����ּ���\n");
					scanf("%d %d", &y, &x);
					continue;
				}
				if (game[y][x] != ' ') {
					printf("�̹� ������ ��ǥ�Դϴ�\n�ٸ� ��ǥ�� �Է����ּ���\n");
					scanf("%d %d", &y, &x);
					continue;
				}
			}
			break;
		case 0:
			srand(time(0));
			x = rand() % 3;
			y = rand() % 3;
			while (game[y][x] != 32) {
				x = rand() % 3;
				y = rand() % 3;
			}
			break;
		}

		game[y][x] = mark;

		printf("\n   0   1   2\n");
		printf(" |---|---|---|\n");
		printf("0| %c | %c | %c |\n", game[0][0], game[0][1], game[0][2]);
		printf(" |---|---|---|\n");
		printf("1| %c | %c | %c |\n", game[1][0], game[1][1], game[1][2]);
		printf(" |---|---|---|\n");
		printf("2| %c | %c | %c |\n", game[2][0], game[2][1], game[2][2]);
		printf(" |---|---|---|\n\n");		//���� �����Ȳ ���

		if (((game[0][0] == 88) && (game[0][1] == 88) && (game[0][2] == 88)) ||
			((game[1][0] == 88) && (game[1][1] == 88) && (game[1][2] == 88)) ||
			((game[2][0] == 88) && (game[2][1] == 88) && (game[2][2] == 88)) ||
			((game[0][0] == 88) && (game[1][0] == 88) && (game[2][0] == 88)) ||
			((game[0][1] == 88) && (game[1][1] == 88) && (game[2][1] == 88)) ||
			((game[0][2] == 88) && (game[1][2] == 88) && (game[2][2] == 88)) ||
			((game[0][0] == 88) && (game[1][1] == 88) && (game[2][2] == 88)) ||
			((game[0][2] == 88) && (game[1][1] == 88) && (game[2][0] == 88))) {
			checkwinner = 'c';
			break;
		}
		else if (((game[0][0] == 79) && (game[0][1] == 79) && (game[0][2] == 79)) ||
			((game[1][0] == 79) && (game[1][1] == 79) && (game[1][2] == 79)) ||
			((game[2][0] == 79) && (game[2][1] == 79) && (game[2][2] == 79)) ||
			((game[0][0] == 79) && (game[1][0] == 79) && (game[2][0] == 79)) ||
			((game[0][1] == 79) && (game[1][1] == 79) && (game[2][1] == 79)) ||
			((game[0][2] == 79) && (game[1][2] == 79) && (game[2][2] == 79)) ||
			((game[0][0] == 79) && (game[1][1] == 79) && (game[2][2] == 79)) ||
			((game[0][2] == 79) && (game[1][1] == 79) && (game[2][0] == 79))) {
			checkwinner = 'h';
			break;
		}								//���а���
	}									//��������
	switch (checkwinner) {
	case 'n':
		printf("�̹� ������ ���º� �Դϴ�\n");
		none++;
		break;
	case 'h':
		printf("�����ڰ� �̰���ϴ�\n");
		win++;
		break;
	case 'c':
		printf("��ǻ�Ͱ� �̰����\n");
		lose++;
		break;
	}
	printf("������ �����մϴ�\n\n");
}
//2. ��ǻ�Ϳ� ���� / �ܼ� �����õ�� ��ǥ�� ����
void play_with_computer_hard(void) {

	char whoisfirst = 'n';
	printf("���� ���� �����Ұǰ���?\nHuman or Computer?(h/c)\n");
	scanf(" %c", &whoisfirst);
	while (!((whoisfirst == 'h') || (whoisfirst == 'c'))) {
		printf("�߸��� �Է��Դϴ�\n�ٽ� �Է����ּ���\n");
		scanf(" %c", &whoisfirst);
	}

	printf("������ �����մϴ�\n");
	printf("Good Luck\n\n");

	char game[3][3];					//��ǥ�� ����

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			game[i][j] = ' ';
		}
	}									//�ʱ�ȭ
	int x, y;
	char mark;

	char checkwinner = 'n';//none,human,computer
	for (int i = 1; i <= 9; i++) {			//���ӽ���
															//��ǻ�Ͷ� ���
		mark = (i % 2 == 0) ? 'X' : 'O';
		//OX�Է¼��� ���� �� �Է�

		if (whoisfirst == 'c') {
			if (mark == 'X') mark = 'O';
			else mark = 'X';
		}

		if (whoisfirst == 'h') {
			switch (i % 2) {
			case 1:
				printf("��ǥ�� �Է��� �ּ���\n");
				scanf("%d %d", &y, &x);
				while (x < 0 || x>2 || y < 0 || y>2 || game[y][x] != ' ') {
					if (x < 0 || x>2 || y < 0 || y>2) {
						printf("���� ���� ��ǥ�Դϴ�\n�ٸ� ��ǥ�� �Է����ּ���\n");
						scanf("%d %d", &y, &x);
						continue;
					}
					if (game[y][x] != ' ') {
						printf("�̹� ������ ��ǥ�Դϴ�\n�ٸ� ��ǥ�� �Է����ּ���\n");
						scanf("%d %d", &y, &x);
						continue;
					}
				}
				game[y][x] = mark;
				break;
			case 0:
				switch (game[1][1]) {
				case 32:
					game[1][1] = 'X';
					break;
				case 88:					//��ǻ�Ͱ� ��� �����ϰ� ������� ������ ��鼭 ��������
					if (((game[0][0] + game[2][0] == 158) && (game[1][0] == 32)) ||
						((game[0][2] + game[2][2] == 158) && (game[1][2] == 32)) ||
						((game[0][0] + game[0][2] == 158) && (game[0][1] == 32)) ||
						((game[2][0] + game[2][2] == 158) && (game[2][1] == 32))) {
						if ((game[0][0] + game[2][0] == 158) && (game[1][0] == 32)) {
							game[1][0] = 88;
						}
						else if ((game[0][2] + game[2][2] == 158) && (game[1][2] == 32)) {
							game[1][2] = 88;
						}
						else if ((game[0][0] + game[0][2] == 158) && (game[0][1] == 32)) {
							game[0][1] = 88;
						}
						else {
							game[2][1] = 88;
						}
					}
					else if (y == x) {									// \�ڰ� ä��������
						if (game[y][1] == ' ') {
							game[y][1] = 'X';
						}
						else if (game[1][x] == ' ') {
							game[1][x] = 'X';
						}
						else {
							srand(time(0));
							x = rand() % 3;
							y = rand() % 3;
							while (game[y][x] != 32) {
								x = rand() % 3;
								y = rand() % 3;
							}
							game[y][x] = mark;
						}
					}
					else if ((y % 2 == 0) && (x % 2 == 0)) {		// /�ڰ� ä��������
						if (game[y][1] == ' ') {
							game[y][1] = 'X';
						}
						else if (game[1][x] == ' ') {
							game[1][x] = 'X';
						}
						else {
							srand(time(0));
							x = rand() % 3;
							y = rand() % 3;
							while (game[y][x] != 32) {
								x = rand() % 3;
								y = rand() % 3;
							}
							game[y][x] = mark;
						}
					}
					else if ((y == 1) && (x % 2 == 0)) {			// -�ڰ� ä��������
						if (game[0][x] == ' ') {
							game[0][x] = 'X';
						}
						else if (game[2][x] == ' ') {
							game[2][x] = 'X';
						}
						else {
							srand(time(0));
							x = rand() % 3;
							y = rand() % 3;
							while (game[y][x] != 32) {
								x = rand() % 3;
								y = rand() % 3;
							}
							game[y][x] = mark;
						}
					}
					else if ((y % 2 == 0) && (x == 1)) {			// |�ڰ� ä��������
						if (game[y][0] == ' ') {
							game[y][0] = 'X';
						}
						else if (game[y][2] == ' ') {
							game[y][2] = 'X';
						}
						else {
							srand(time(0));
							x = rand() % 3;
							y = rand() % 3;
							while (game[y][x] != 32) {
								x = rand() % 3;
								y = rand() % 3;
							}
							game[y][x] = mark;
						}
					}
					break;
				case 79:			//����� �������� ��������
					if (i == 2) {
						game[0][0] = 'X';						//���Ƿ� 0,0�� �� �������
					}
					else if ((game[0][0] + game[1][0] + game[2][0] == 208) ||
						(game[0][0] + game[0][1] + game[0][2] == 208) ||
						(game[0][2] + game[1][2] + game[2][2] == 208) ||
						(game[2][0] + game[2][1] + game[2][2] == 208)) {
						for (int j = 0; j <= 2; j = j + 2) {
							if (game[0][j] + game[1][j] + game[2][j] == 208) {
								for (int n = 0; n < 3; n++) {
									game[n][j] = 'X';
								}
								break;
							}
							else if (game[j][0] + game[j][1] + game[j][2] == 208) {
								for (int n = 0; n < 3; n++) {
									game[j][n] = 'X';
								}
								break;
							}
						}										//��ǻ���� 2���� �� ��������� ���ϰ� ��������
					}
					else if ((game[0][1] + game[1][1] + game[2][1] == 190) ||
						(game[1][0] + game[1][1] + game[1][2] == 190) ||
						(game[0][2] + game[1][2] + game[2][2] == 190) ||
						(game[2][0] + game[2][1] + game[2][2] == 190) ||
						(game[0][2] + game[1][1] + game[2][0] == 190)) {
						if ((game[2][2] == 79) &&
							((game[2][0] + game[2][1] == 111) || (game[0][2] + game[1][2] == 111))) {
							if (game[2][0] + game[2][1] == 111) {
								if (game[2][0] == 79) {
									game[2][1] = 88;
								}
								else {
									game[2][0] = 88;
								}
							}
							else {
								if (game[0][2] == 79) {
									game[1][2] = 88;
								}
								else {
									game[0][2] = 88;
								}
							}
						}
						else if (game[1][1] == 79) {
							if (game[2][0] + game[0][2] == 111) {
								if (game[2][0] == 79) {
									game[0][2] = 88;
								}
								else {
									game[2][0] = 88;
								}
							}
							else if (game[0][1] + game[2][1] == 111) {
								if (game[0][1] == 79) {
									game[2][1] = 88;
								}
								else {
									game[0][1] = 88;
								}
							}
							else if (game[1][0] + game[1][2] == 111) {
								if (game[1][0] == 79) {
									game[2][1] = 88;
								}
								else {
									game[1][0] = 88;
								}
							}
						}
					}
					else if ((game[1][0] + game[2][0] == 64) || (game[0][1] + game[0][2] == 64)) {
						if (game[1][0] + game[2][0] == 64) {
							game[2][0] = 88;
						}
						else {
							game[0][2] = 88;
						}
					}
					else if ((game[2][2] == 32) && ((game[2][1] == 32) || (game[1][2] == 32))) {
						if (game[2][1] == 32) {
							game[2][1] = 88;
						}
						else {
							game[1][2] = 88;
						}
					}
					break;
				}
			default:
				break;
			}
		}
		else {
			switch (i % 2) {
			case 0:
				printf("��ǥ�� �Է��� �ּ���\n");
				scanf("%d %d", &y, &x);
				while (x < 0 || x>2 || y < 0 || y>2 || game[y][x] != ' ') {
					if (x < 0 || x>2 || y < 0 || y>2) {
						printf("���� ���� ��ǥ�Դϴ�\n�ٸ� ��ǥ�� �Է����ּ���\n");
						scanf("%d %d", &y, &x);
						continue;
					}
					if (game[y][x] != ' ') {
						printf("�̹� ������ ��ǥ�Դϴ�\n�ٸ� ��ǥ�� �Է����ּ���\n");
						scanf("%d %d", &y, &x);
						continue;
					}
				}
				game[y][x] = mark;
				break;
			case 1:
				if (game[1][1] == ' ') {
					game[1][1] = 'X';
				}									//����� �������
				else {
					if (y == x) {									// \�ڰ� ä��������
						if (game[y][1] == ' ') {
							game[y][1] = 'X';
						}
						else if (game[1][x] == ' ') {
							game[1][x] = 'X';
						}
						else {
							srand(time(0));
							x = rand() % 3;
							y = rand() % 3;
							while (game[y][x] != 32) {
								x = rand() % 3;
								y = rand() % 3;
							}
							game[y][x] = mark;
						}
					}
					else if ((y % 2 == 0) && (x % 2 == 0)) {		// /�ڰ� ä��������
						if (game[y][1] == ' ') {
							game[y][1] = 'X';
						}
						else if (game[1][x] == ' ') {
							game[1][x] = 'X';
						}
						else {
							srand(time(0));
							x = rand() % 3;
							y = rand() % 3;
							while (game[y][x] != 32) {
								x = rand() % 3;
								y = rand() % 3;
							}
							game[y][x] = mark;
						}
					}
					else if ((y == 1) && (x % 2 == 0)) {			// -�ڰ� ä��������
						if (game[0][x] == ' ') {
							game[0][x] = 'X';
						}
						else if (game[2][x] == ' ') {
							game[2][x] = 'X';
						}
						else {
							srand(time(0));
							x = rand() % 3;
							y = rand() % 3;
							while (game[y][x] != 32) {
								x = rand() % 3;
								y = rand() % 3;
							}
							game[y][x] = mark;
						}
					}
					else if ((y % 2 == 0) && (x == 1)) {			// |�ڰ� ä��������
						if (game[y][0] == ' ') {
							game[y][0] = 'X';
						}
						else if (game[y][2] == ' ') {
							game[y][2] = 'X';
						}
						else {
							srand(time(0));
							x = rand() % 3;
							y = rand() % 3;
							while (game[y][x] != 32) {
								x = rand() % 3;
								y = rand() % 3;
							}
							game[y][x] = mark;
						}
					}
				}
				break;
			}
		}

		printf("\n   0   1   2\n");
		printf(" |---|---|---|\n");
		printf("0| %c | %c | %c |\n", game[0][0], game[0][1], game[0][2]);
		printf(" |---|---|---|\n");
		printf("1| %c | %c | %c |\n", game[1][0], game[1][1], game[1][2]);
		printf(" |---|---|---|\n");
		printf("2| %c | %c | %c |\n", game[2][0], game[2][1], game[2][2]);
		printf(" |---|---|---|\n\n");		//���� �����Ȳ ���

		if (((game[0][0] == 88) && (game[0][1] == 88) && (game[0][2] == 88)) ||
			((game[1][0] == 88) && (game[1][1] == 88) && (game[1][2] == 88)) ||
			((game[2][0] == 88) && (game[2][1] == 88) && (game[2][2] == 88)) ||
			((game[0][0] == 88) && (game[1][0] == 88) && (game[2][0] == 88)) ||
			((game[0][1] == 88) && (game[1][1] == 88) && (game[2][1] == 88)) ||
			((game[0][2] == 88) && (game[1][2] == 88) && (game[2][2] == 88)) ||
			((game[0][0] == 88) && (game[1][1] == 88) && (game[2][2] == 88)) ||
			((game[0][2] == 88) && (game[1][1] == 88) && (game[2][0] == 88))) {
			checkwinner = 'c';
			break;
		}
		else if (((game[0][0] == 79) && (game[0][1] == 79) && (game[0][2] == 79)) ||
			((game[1][0] == 79) && (game[1][1] == 79) && (game[1][2] == 79)) ||
			((game[2][0] == 79) && (game[2][1] == 79) && (game[2][2] == 79)) ||
			((game[0][0] == 79) && (game[1][0] == 79) && (game[2][0] == 79)) ||
			((game[0][1] == 79) && (game[1][1] == 79) && (game[2][1] == 79)) ||
			((game[0][2] == 79) && (game[1][2] == 79) && (game[2][2] == 79)) ||
			((game[0][0] == 79) && (game[1][1] == 79) && (game[2][2] == 79)) ||
			((game[0][2] == 79) && (game[1][1] == 79) && (game[2][0] == 79))) {
			checkwinner = 'h';
			break;
		}								//���а���
	}									//��������
	switch (checkwinner) {
	case 'n':
		printf("�̹� ������ ���º� �Դϴ�\n");
		none++;
		break;
	case 'h':
		printf("�����ڰ� �̰���ϴ�\n");
		win++;
		break;
	case 'c':
		printf("��ǻ�Ͱ� �̰���ϴ�\n");
		lose++;
		break;
	}
	printf("������ �����մϴ�\n\n");
}
//3. ��� ���� ��ǻ�Ϳ� ���
//(1,1)�� ����� ���� �������� �ʾҴٸ�
//6�� �ڵ� ó�� (1,1) �����ϰ� ���������� �÷���
//������ ��� ���̽����� ������� ���̽��� ���ϱ⵵ ��
//������ (1,1)�� ����� �����ϸ� ���� ���� Ǯ��
void play_with_computer_hardcore(void) {
	printf("������ �����մϴ�\n");
	printf("Good Luck\n\n");

	char game[3][3];					//��ǥ�� ����

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			game[i][j] = ' ';
		}
	}									//�ʱ�ȭ
	int x, y;
	char mark;

	char checkwinner = 'n';//none,human,computer
	for (int i = 1; i <= 9; i++) {			//���ӽ���
															//��ǻ�Ͷ� ���
		mark = (i % 2 == 0) ? 'O' : 'X';
		//OX�Է¼��� ���� �� �Է�

		switch (i % 2) {
		case 0:
			printf("��ǥ�� �Է��� �ּ���\n");
			scanf("%d %d", &y, &x);
			while (x < 0 || x>2 || y < 0 || y>2 || game[y][x] != ' ') {
				if (x < 0 || x>2 || y < 0 || y>2) {
					printf("���� ���� ��ǥ�Դϴ�\n�ٸ� ��ǥ�� �Է����ּ���\n");
					scanf("%d %d", &y, &x);
					continue;
				}
				if (game[y][x] != ' ') {
					printf("�̹� ������ ��ǥ�Դϴ�\n�ٸ� ��ǥ�� �Է����ּ���\n");
					scanf("%d %d", &y, &x);
					continue;
				}
			}
			game[y][x] = mark;
			break;
		case 1:
			switch (game[1][1]) {
			case 32:
				game[1][1] = 'X';
				break;
			case 88:
				if ((game[1][0] + game[1][2] == 120) || (game[0][1] + game[2][1] == 120) ||
					(game[0][0] + game[2][2] == 120) || (game[0][2] + game[2][0] == 120)) {
					if (game[1][0] + game[1][2] == 120) {
						game[1][0] = 88;
						game[1][2] = 88;
					}
					else if (game[0][1] + game[2][1] == 120) {
						game[0][1] = 88;
						game[2][1] = 88;
					}
					else if (game[0][0] + game[2][2] == 120) {
						game[0][0] = 88;
						game[2][2] = 88;
					}
					else {
						game[0][2] = 88;
						game[2][0] = 88;
					}										//�߾� �������� 2���� ���� �ϳ��� �� ���
				}
				else if ((game[0][0] + game[2][0] + game[1][0] == 208) ||
					(game[0][2] + game[2][2] + game[1][2] == 208) ||
					(game[0][0] + game[0][2] + game[0][1] == 208) ||
					(game[2][0] + game[2][2] + game[2][1] == 208)) {
					if (game[0][0] + game[2][0] + game[1][0] == 208) {
						game[0][0] = 88;
						game[2][0] = 88;
						game[1][0] = 88;
					}
					else if (game[0][2] + game[2][2] + game[1][2] == 208) {
						game[0][2] = 88;
						game[2][2] = 88;
						game[1][2] = 88;
					}
					else if (game[0][0] + game[0][2] + game[0][1] == 208) {
						game[0][0] = 88;
						game[0][2] = 88;
						game[0][1] = 88;
					}
					else {
						game[2][0] = 88;
						game[2][2] = 88;
						game[2][1] = 88;
					}
				}											//�߾� ���� 2���� ���� �ϳ��� �� ���
				else if (((game[0][0] + game[2][0] + game[1][0] == 190)) ||
					((game[0][2] + game[2][2] + game[1][2] == 190)) ||
					((game[0][0] + game[0][2] + game[0][1] == 190)) ||
					((game[2][0] + game[2][2] + game[2][1] == 190))) {
					if (game[0][0] + game[2][0] + game[1][0] == 190) {
						if (game[0][0] == 32) game[0][0] = 88;
						else if (game[2][0] == 32) game[2][0] = 88;
						else if (game[0][0] == 32) game[1][0] = 88;
					}
					else if (game[0][2] + game[2][2] + game[1][2] == 190) {
						if (game[0][2] == 32) game[0][2] = 88;
						else if (game[2][2] == 32) game[2][2] = 88;
						else if (game[1][2] == 32) game[1][2] = 88;
					}
					else if (game[0][0] + game[0][2] + game[0][1] == 190) {
						if (game[0][0] == 32) game[0][0] = 88;
						else if (game[0][2] == 32) game[0][2] = 88;
						else if (game[0][1] == 32) game[0][1] = 88;
					}
					else {
						if (game[2][0] == 32) game[2][0] = 88;
						else if (game[2][2] == 32) game[2][2] = 88;
						else if (game[2][1] == 32) game[2][1] = 88;
					}
				}											//�����ڰ� 2���� �ΰ� �ϳ��� �� ��� ���
				else if ((game[1][0] + game[1][2] + game[0][1] + game[2][1] == 128) &&
					(game[0][0] + game[2][2] + game[0][2] + game[2][0] == 175)) {
					if (game[0][0] == 79)  game[1][0] = 88;
					else if (game[0][2] == 79) game[0][1] = 88;
					else if (game[2][0] == 79) game[2][1] = 88;
					else if (game[2][2] == 79) game[1][2] = 88;
				}										//�����ڰ� ù��°�� �밢���Ƚ� �ٷ� �� ����
				else if ((game[1][0] + game[1][2] + game[0][1] + game[2][1] == 175) &&
					(game[0][0] + game[2][2] + game[0][2] + game[2][0] == 128)) {
					if (game[1][0] == 79) game[2][0] = 88;
					else if (game[1][2] == 79) game[0][2] = 88;
					else if (game[0][1] == 79) game[0][0] = 88;
					else if (game[2][1] == 79) game[2][2] = 88;
				}										//�����ڰ� ù��°�� �������� ���� �� �ٷ� �� ����
				else if ((game[0][0] + game[2][0] + game[1][0] == 96) ||
					(game[0][2] + game[2][2] + game[1][2] == 96) ||
					(game[0][0] + game[0][2] + game[0][1] == 96) ||
					(game[2][0] + game[2][2] + game[2][1] == 96)) {
					if (game[0][0] + game[2][0] + game[1][0] == 96) {
						/////////////////////////////////////////////////////////////////////////
					}
				}


				////////////////////////////////////////////////////////////////////////////////


				else {
					srand(time(0));
					x = rand() % 3;
					y = rand() % 3;
					while (game[y][x] != 32) {
						x = rand() % 3;
						y = rand() % 3;
					}
					game[y][x] = mark;
				}
				break;
			}
		default:
			break;
		}

		printf("\n   0   1   2\n");
		printf(" |---|---|---|\n");
		printf("0| %c | %c | %c |\n", game[0][0], game[0][1], game[0][2]);
		printf(" |---|---|---|\n");
		printf("1| %c | %c | %c |\n", game[1][0], game[1][1], game[1][2]);
		printf(" |---|---|---|\n");
		printf("2| %c | %c | %c |\n", game[2][0], game[2][1], game[2][2]);
		printf(" |---|---|---|\n\n");		//���� �����Ȳ ���

		if (((game[0][0] == 88) && (game[0][1] == 88) && (game[0][2] == 88)) ||
			((game[1][0] == 88) && (game[1][1] == 88) && (game[1][2] == 88)) ||
			((game[2][0] == 88) && (game[2][1] == 88) && (game[2][2] == 88)) ||
			((game[0][0] == 88) && (game[1][0] == 88) && (game[2][0] == 88)) ||
			((game[0][1] == 88) && (game[1][1] == 88) && (game[2][1] == 88)) ||
			((game[0][2] == 88) && (game[1][2] == 88) && (game[2][2] == 88)) ||
			((game[0][0] == 88) && (game[1][1] == 88) && (game[2][2] == 88)) ||
			((game[0][2] == 88) && (game[1][1] == 88) && (game[2][0] == 88))) {
			checkwinner = 'c';
			break;
		}
		else if (((game[0][0] == 79) && (game[0][1] == 79) && (game[0][2] == 79)) ||
			((game[1][0] == 79) && (game[1][1] == 79) && (game[1][2] == 79)) ||
			((game[2][0] == 79) && (game[2][1] == 79) && (game[2][2] == 79)) ||
			((game[0][0] == 79) && (game[1][0] == 79) && (game[2][0] == 79)) ||
			((game[0][1] == 79) && (game[1][1] == 79) && (game[2][1] == 79)) ||
			((game[0][2] == 79) && (game[1][2] == 79) && (game[2][2] == 79)) ||
			((game[0][0] == 79) && (game[1][1] == 79) && (game[2][2] == 79)) ||
			((game[0][2] == 79) && (game[1][1] == 79) && (game[2][0] == 79))) {
			checkwinner = 'h';
			break;
		}								//���а���
	}									//��������
	switch (checkwinner) {
	case 'n':
		printf("�̹� ������ ���º� �Դϴ�\n");
		none++;
		break;
	case 'h':
		printf("�����ڰ� �̰���ϴ�\n");
		win++;
		break;
	case 'c':
		printf("��ǻ�Ͱ� �̰���ϴ�\n");
		lose++;
		break;
	}
	printf("������ �����մϴ�\n\n");
}
//4. ��ǻ�� ���� ��ǻ�Ϳ� ���
//��ǻ�� ������ �÷���
//��ǻ�ʹ� �̱�� ������ ������ �̱�µ��� ��Ŀ��
//(1,1)�� �����ϰ� (1,1)�� �����ϴ� ������ ����µ��� ��Ŀ��
//�ΰ��� ����� ���̽��� ã�Ҵٸ� ���ٿ� ������ ĭ�� �����ִ��� Ȯ��,
//������ ĭ�� ����ִٸ� ä��� ���� ����
void play_nbyn_p2p(void) {
	int vec = 3;
	printf("�� ĭ���� ������ ���� �Է����ּ��� : ");
	scanf("%d", &vec);
	while (vec < 3 || vec >= 100) {
		printf("���� ���� ĭ���Դϴ�\n3�̻� 100�̸��� ���ڸ� �Է��� �ּ���");
		scanf("%d", &vec);
	}
	printf("������ �����մϴ�\n");
	printf("Good Luck\n\n");

	char game[99][99];					//��ǥ�� ����

	for (int i = 0; i < vec; i++) {
		for (int j = 0; j < vec; j++) {
			game[i][j] = ' ';
		}
	}									//�ʱ�ȭ

	int x, y;
	char mark;

	char checkwinner = 'n';//none,human,computer �ڵ庹��/����
	for (int i = 1; i <= vec * vec; i++) {			//���ӽ���
														//��� ���� �Է�
		mark = (i % 2 == 0) ? 'X' : 'O';
		//OX�Է¼��� ���� �� �Է�

		printf("%c�� �����Դϴ�\n��ǥ�� �Է��� �ּ���\n", mark);
		scanf("%d %d", &y, &x);
		while (x < 0 || x >= vec || y < 0 || y >= vec || game[y][x] != ' ') {
			if (x < 0 || x >= vec || y < 0 || y >= vec) {
				printf("���� ���� ��ǥ�Դϴ�\n�ٸ� ��ǥ�� �Է����ּ���\n");
				scanf("%d %d", &y, &x);
				continue;
			}
			if (game[y][x] != ' ') {
				printf("�̹� ������ ��ǥ�Դϴ�\n�ٸ� ��ǥ�� �Է����ּ���\n");
				scanf("%d %d", &y, &x);
				continue;
			}
		}

		game[y][x] = mark;

		{
			printf("\n   ");
			for (int i = 0; i < vec; i++) printf(" %2d  ", i);
			printf("\n");
			for (int i = 0; i < vec; i++) {
				printf("  |");
				for (int j = 0; j < vec; j++) {
					printf("----|");
				}
				printf("\n");
				printf("%2d|", i);
				for (int j = 0; j < vec; j++) {
					printf("  %c |", game[i][j]);
				}
				printf("\n");
			}
			printf("  |");
			for (int j = 0; j < vec; j++) {
				printf("----|");
			}
			printf("\n");
		}					//���� �����Ȳ ���

		{
			for (int i = 0; i < vec; i++) {
				int checkvec = 0;
				{
					for (int j = 0; j < vec; j++) {
						checkvec = checkvec + game[i][j];
					}
					if (checkvec == 88 * vec) {
						checkwinner = 'c';
						break;
					}
					else if (checkvec == 79 * vec) {
						checkwinner = 'h';
						break;
					}
				}
				{
					checkvec = 0;
					for (int j = 0; j < vec; j++) {
						checkvec = checkvec + game[j][i];
					}
					if (checkvec == 88 * vec) {
						checkwinner = 'c';
						break;
					}
					else if (checkvec == 79 * vec) {
						checkwinner = 'h';
						break;
					}
				}
			}				// ���μ��� �߿� ä���� ���� �ִ��� Ȯ��
			if (checkwinner == 'n') {
				int checkvec = 0;
				for (int i = 0; i < vec; i++) {
					checkvec = checkvec + game[i][i];
				}
				if (checkvec == 88 * vec) {
					checkwinner = 'c';
					break;
				}
				else if (checkvec == 79 * vec) {
					checkwinner = 'h';
					break;
				}
			}				// \������ ä�������� Ȯ��
			if (checkwinner == 'n') {
				int checkvec = 0;
				for (int i = 0; i < vec; i++) {
					checkvec = checkvec + game[i][vec - 1 - i];
				}
				if (checkvec == 88 * vec) {
					checkwinner = 'c';
					break;
				}
				else if (checkvec == 79 * vec) {
					checkwinner = 'h';
					break;
				}
			}				// /������ ä�������� Ȯ��
		}														//���а���
		if (checkwinner != 'n') break;
	}									//��������
	switch (checkwinner) {
	case 'n':
		printf("�̹� ������ ���º� �Դϴ�\n");
		break;
	case 'h':
		printf("O�� �̰���ϴ�\n");
		break;
	case 'c':
		printf("X�� �̰���ϴ�\n");
		break;
	}
	printf("������ �����մϴ�\n\n");
}
//5. ĭ������ �� 1�� ����
void play_nbyn_with_computer_easy(void) {

	char whoisfirst = 'n';
	printf("���� ���� �����Ұǰ���?\nHuman or Computer?(h/c)\n");
	scanf(" %c", &whoisfirst);
	while (!((whoisfirst == 'h') || (whoisfirst == 'c'))) {
		printf("�߸��� �Է��Դϴ�\n�ٽ� �Է����ּ���\n");
		scanf(" %c", &whoisfirst);
	}

	int vec = 3;
	printf("�� ĭ���� ������ ���� �Է����ּ��� : ");
	scanf("%d", &vec);
	while (vec < 3 || vec >= 100) {
		printf("���� ���� ĭ���Դϴ�\n3�̻� 100�̸��� ���ڸ� �Է��� �ּ���");
		scanf("%d", &vec);
	}
	printf("������ �����մϴ�\n");
	printf("Good Luck\n\n");

	char game[99][99];					//��ǥ�� ����

	for (int i = 0; i < vec; i++) {
		for (int j = 0; j < vec; j++) {
			game[i][j] = ' ';
		}
	}									//�ʱ�ȭ

	int x, y;
	char mark;

	char checkwinner = 'n';//none,human,computer �ڵ庹��/����
	for (int i = 1; i <= vec * vec; i++) {			//���ӽ���
														//��� ���� �Է�
		int whoschance;
		switch (whoisfirst) {
		case 'h':whoschance = i % 2; break;
		case 'c':whoschance = (i + 1) % 2; break;
		}

		mark = (whoschance == 0) ? 'X' : 'O';
		//OX�Է¼��� ���� �� �Է�

		switch (whoschance) {
		case 1:
			printf("��ǥ�� �Է��� �ּ���\n");
			scanf("%d %d", &y, &x);
			while (x < 0 || x >= vec || y < 0 || y >= vec || game[y][x] != ' ') {
				if (x < 0 || x >= vec || y < 0 || y >= vec) {
					printf("���� ���� ��ǥ�Դϴ�\n�ٸ� ��ǥ�� �Է����ּ���\n");
					scanf("%d %d", &y, &x);
					continue;
				}
				if (game[y][x] != ' ') {
					printf("�̹� ������ ��ǥ�Դϴ�\n�ٸ� ��ǥ�� �Է����ּ���\n");
					scanf("%d %d", &y, &x);
					continue;
				}
			}
			break;
		case 0:
			srand(time(0));
			x = rand() % vec;
			y = rand() % vec;
			while (game[y][x] != 32) {
				x = rand() % vec;
				y = rand() % vec;
			}
			break;
		}

		game[y][x] = mark;

		{
			printf("\n   ");
			for (int i = 0; i < vec; i++) printf(" %2d  ", i);
			printf("\n");
			for (int i = 0; i < vec; i++) {
				printf("  |");
				for (int j = 0; j < vec; j++) {
					printf("----|");
				}
				printf("\n");
				printf("%2d|", i);
				for (int j = 0; j < vec; j++) {
					printf("  %c |", game[i][j]);
				}
				printf("\n");
			}
			printf("  |");
			for (int j = 0; j < vec; j++) {
				printf("----|");
			}
			printf("\n");
		}					//���� �����Ȳ ���

		{
			for (int i = 0; i < vec; i++) {
				int checkvec = 0;
				{
					for (int j = 0; j < vec; j++) {
						checkvec = checkvec + game[i][j];
					}
					if (checkvec == 88 * vec) {
						checkwinner = 'c';
						break;
					}
					else if (checkvec == 79 * vec) {
						checkwinner = 'h';
						break;
					}
				}
				{
					checkvec = 0;
					for (int j = 0; j < vec; j++) {
						checkvec = checkvec + game[j][i];
					}
					if (checkvec == 88 * vec) {
						checkwinner = 'c';
						break;
					}
					else if (checkvec == 79 * vec) {
						checkwinner = 'h';
						break;
					}
				}
			}				// ���μ��� �߿� ä���� ���� �ִ��� Ȯ��
			if (checkwinner == 'n') {
				int checkvec = 0;
				for (int i = 0; i < vec; i++) {
					checkvec = checkvec + game[i][i];
				}
				if (checkvec == 88 * vec) {
					checkwinner = 'c';
					break;
				}
				else if (checkvec == 79 * vec) {
					checkwinner = 'h';
					break;
				}
			}				// \������ ä�������� Ȯ��
			if (checkwinner == 'n') {
				int checkvec = 0;
				for (int i = 0; i < vec; i++) {
					checkvec = checkvec + game[i][vec - 1 - i];
				}
				if (checkvec == 88 * vec) {
					checkwinner = 'c';
					break;
				}
				else if (checkvec == 79 * vec) {
					checkwinner = 'h';
					break;
				}
			}				// /������ ä�������� Ȯ��
		}														//���а���
		if (checkwinner != 'n') break;
	}									//��������
	switch (checkwinner) {
	case 'n':
		printf("�̹� ������ ���º� �Դϴ�\n");
		none++;
		break;
	case 'h':
		printf("�����ڰ� �̰���ϴ�\n");
		win++;
		break;
	case 'c':
		printf("��ǻ�Ͱ� �̰����\n");
		lose++;
		break;
	}
	printf("������ �����մϴ�\n\n");
}
//6. ĭ������ �� 2�� ����
void play_nbyn_with_computer_hard(void) {

	char whoisfirst = 'n';
	printf("���� ���� �����Ұǰ���?\nHuman or Computer?(h/c)\n");
	scanf(" %c", &whoisfirst);
	while (!((whoisfirst == 'h') || (whoisfirst == 'c'))) {
		printf("�߸��� �Է��Դϴ�\n�ٽ� �Է����ּ���\n");
		scanf(" %c", &whoisfirst);
	}

	int vec = 3;
	printf("�� ĭ���� ������ ���� �Է����ּ��� : ");
	scanf("%d", &vec);
	while (vec < 3 || vec >= 100) {
		printf("���� ���� ĭ���Դϴ�\n3�̻� 100�̸��� ���ڸ� �Է��� �ּ���");
		scanf("%d", &vec);
	}
	printf("������ �����մϴ�\n");
	printf("Good Luck\n\n");

	char game[99][99];					//��ǥ�� ����

	for (int i = 0; i < vec; i++) {
		for (int j = 0; j < vec; j++) {
			game[i][j] = ' ';
		}
	}									//�ʱ�ȭ

	int x, y;
	char mark;

	char checkwinner = 'n';//none,human,computer �ڵ庹��/����
	for (int i = 1; i <= vec * vec; i++) {			//���ӽ���
														//��� ���� �Է�
		int whoschance;
		switch (whoisfirst) {
		case 'h':whoschance = i % 2; break;
		case 'c':whoschance = (i + 1) % 2; break;
		}

		mark = (whoschance == 0) ? 'X' : 'O';
		//OX�Է¼��� ���� �� �Է�

		switch (whoschance) {
		case 1:
			printf("��ǥ�� �Է��� �ּ���\n");
			scanf("%d %d", &y, &x);
			while (x < 0 || x >= vec || y < 0 || y >= vec || game[y][x] != ' ') {
				if (x < 0 || x >= vec || y < 0 || y >= vec) {
					printf("���� ���� ��ǥ�Դϴ�\n�ٸ� ��ǥ�� �Է����ּ���\n");
					scanf("%d %d", &y, &x);
					continue;
				}
				if (game[y][x] != ' ') {
					printf("�̹� ������ ��ǥ�Դϴ�\n�ٸ� ��ǥ�� �Է����ּ���\n");
					scanf("%d %d", &y, &x);
					continue;
				}
			}
			break;
		case 0:
			int checksum1 = 0;
			int checksum2 = 0;
			int check = 0;
			int checkx = 0;
			int checky = 0;

			for (int i = 0; i < vec; i++) {
				checksum1 = 0;
				checksum2 = 0;
				for (int j = 0; j < vec; j++) {
					checksum1 = checksum1 + game[i][j];
					checksum2 = checksum2 + game[j][i];
				}
				if (checksum1 == 88 * (vec - 1) + 32) {
					check = 1;
					checky = i;
					break;
				}
				else if (checksum2 == 88 * (vec - 1) + 32) {
					check = 2;
					checkx = i;
					break;
				}
			}
			if (check == 1) {
				for (int j = 0; j < vec; j++) {
					if (game[checky][j] == 32) {
						game[checky][j] = 88;
						break;
					}
				}
				break;
			}
			else if (check == 2) {
				for (int j = 0; j < vec; j++) {
					if (game[j][checkx] == 32) {
						game[j][checkx] = 88;
						break;
					}
				}
				break;
			}						// ���μ��η� ��ǻ�Ͱ� ������ ������ ���� �ִ��� �˻�
									// ��ǻ�Ͱ� ������ ������ ���� ������ ���� ����

			checksum1 = 0;
			checksum2 = 0;
			for (int i = 0; i < vec; i++) {
				checksum1 = checksum1 + game[i][i];
				checksum2 = checksum2 + game[i][vec - i - 1];
			}
			if (checksum1 == 88 * (vec - 1) + 32) {
				check = 1;
				checky = i;
				break;
			}
			else if (checksum2 == 88 * (vec - 1) + 32) {
				check = 2;
				checky = i;
				break;
			}
			if (check == 1) {
				game[checky][checky] = 88;
				break;
			}
			else if (check == 2) {
				game[checky][vec - checky - 1] = 88;
				break;
			}						//�밢������ ��ǻ�Ͱ� ������ ������ ���� �ִ��� �˻�
									//��ǻ�Ͱ� ������ �ִ� ���� ������ ���� ����

			for (int i = 0; i < vec; i++) {
				checksum1 = 0;
				checksum2 = 0;
				for (int j = 0; j < vec; j++) {
					checksum1 = checksum1 + game[i][j];
					checksum2 = checksum2 + game[j][i];
				}
				if (checksum1 == 79 * (vec - 1) + 32) {
					check = 1;
					checky = i;
					break;
				}
				else if (checksum2 == 79 * (vec - 1) + 32) {
					check = 2;
					checkx = i;
					break;
				}
			}
			if (check == 1) {
				for (int j = 0; j < vec; j++) {
					if (game[checky][j] == 32) {
						game[checky][j] = 88;
						break;
					}
				}
				break;
			}
			else if (check == 2) {
				for (int j = 0; j < vec; j++) {
					if (game[j][checkx] == 32) {
						game[j][checkx] = 88;
						break;
					}
				}
				break;
			}						// ���μ��η� ����� ������ ������ ���� �ִ��� �˻�
									// ����� ������ ������ ���� ������ ���

			checksum1 = 0;
			checksum2 = 0;
			for (int i = 0; i < vec; i++) {
				checksum1 = checksum1 + game[i][i];
				checksum2 = checksum2 + game[i][vec - i - 1];
			}
			if (checksum1 == 79 * (vec - 1) + 32) {
				check = 1;
				checky = i;
				break;
			}
			else if (checksum2 == 79 * (vec - 1) + 32) {
				check = 2;
				checky = i;
				break;
			}
			if (check == 1) {
				game[checky][checky] = 88;
				break;
			}
			else if (check == 2) {
				game[checky][vec - checky - 1] = 88;
				break;
			}						//�밢������ ����� ������ ������ ���� �ִ��� �˻�
									//����� ������ �ִ� ���� ������ ���

			for (int i = 0; i < vec; i++) {
				checksum1 = 0;
				checksum2 = 0;
				for (int j = 0; j < vec; j++) {
					checksum1 = checksum1 + game[i][j];
					checksum2 = checksum2 + game[j][i];
				}
				if (checksum1 == 88 * (vec - 2) + 32 * 2) {
					check = 1;
					checky = i;
					break;
				}
				else if (checksum2 == 88 * (vec - 2) + 32 * 2) {
					check = 2;
					checkx = i;
					break;
				}
			}
			if (check == 1) {
				for (int j = 0; j < vec; j++) {
					if (game[checky][j] == 32) {
						game[checky][j] = 88;
						break;
					}
				}
				break;
			}
			else if (check == 2) {
				for (int j = 0; j < vec; j++) {
					if (game[j][checkx] == 32) {
						game[j][checkx] = 88;
						break;
					}
				}
				break;
			}						// ���μ��η� ��ǻ�Ͱ� 2�� �� ������ ������ ���� �ִ��� �˻�
									// �ش�Ǹ� �ϳ� ä������

			checksum1 = 0;
			checksum2 = 0;
			for (int i = 0; i < vec; i++) {
				checksum1 = checksum1 + game[i][i];
				checksum2 = checksum2 + game[i][vec - i - 1];
			}
			if (checksum1 == 88 * (vec - 2) + 32 * 2) {
				check = 1;
				checky = i;
				break;
			}
			else if (checksum2 == 88 * (vec - 2) + 32 * 2) {
				check = 2;
				checky = i;
				break;
			}
			if (check == 1) {
				game[checky][checky] = 88;
				break;
			}
			else if (check == 2) {
				game[checky][vec - checky - 1] = 88;
				break;
			}						// �밢������ ��ǻ�Ͱ� 2�� �� ������ ������ ���� �ִ��� �˻�
									// �ش�Ǹ� �ϳ� ä������

			for (int i = 0; i < vec; i++) {
				checksum1 = 0;
				checksum2 = 0;
				for (int j = 0; j < vec; j++) {
					checksum1 = checksum1 + game[i][j];
					checksum2 = checksum2 + game[j][i];
				}
				if (checksum1 == 79 * (vec - 2) + 32 * 2) {
					check = 1;
					checky = i;
					break;
				}
				else if (checksum2 == 79 * (vec - 2) + 32 * 2) {
					check = 2;
					checkx = i;
					break;
				}
			}
			if (check == 1) {
				for (int j = 0; j < vec; j++) {
					if (game[checky][j] == 32) {
						game[checky][j] = 88;
						break;
					}
				}
				break;
			}
			else if (check == 2) {
				for (int j = 0; j < vec; j++) {
					if (game[j][checkx] == 32) {
						game[j][checkx] = 88;
						break;
					}
				}
				break;
			}						// ���μ��η� ����� �ΰ� �� ������ ������ ���� �ִ��� �˻�
									// �ش�Ǹ� ���

			checksum1 = 0;
			checksum2 = 0;
			for (int i = 0; i < vec; i++) {
				checksum1 = checksum1 + game[i][i];
				checksum2 = checksum2 + game[i][vec - i - 1];
			}
			if (checksum1 == 79 * (vec - 2) + 32 * 2) {
				check = 1;
				checky = i;
				break;
			}
			else if (checksum2 == 79 * (vec - 2) + 32 * 2) {
				check = 2;
				checky = i;
				break;
			}
			if (check == 1) {
				game[checky][checky] = 88;
				break;
			}
			else if (check == 2) {
				game[checky][vec - checky - 1] = 88;
				break;
			}						// �밢������ ����� �ΰ� �� ������ ������ ���� �ִ��� �˻�
									// �ش�Ǹ� ���




			///////////////////////////////////////////////////////////////////
		}

		game[y][x] = mark;

		{
			printf("\n   ");
			for (int i = 0; i < vec; i++) printf(" %2d  ", i);
			printf("\n");
			for (int i = 0; i < vec; i++) {
				printf("  |");
				for (int j = 0; j < vec; j++) {
					printf("----|");
				}
				printf("\n");
				printf("%2d|", i);
				for (int j = 0; j < vec; j++) {
					printf("  %c |", game[i][j]);
				}
				printf("\n");
			}
			printf("  |");
			for (int j = 0; j < vec; j++) {
				printf("----|");
			}
			printf("\n");
		}					//���� �����Ȳ ���

		{
			for (int i = 0; i < vec; i++) {
				int checkvec = 0;
				{
					for (int j = 0; j < vec; j++) {
						checkvec = checkvec + game[i][j];
					}
					if (checkvec == 88 * vec) {
						checkwinner = 'c';
						break;
					}
					else if (checkvec == 79 * vec) {
						checkwinner = 'h';
						break;
					}
				}
				{
					checkvec = 0;
					for (int j = 0; j < vec; j++) {
						checkvec = checkvec + game[j][i];
					}
					if (checkvec == 88 * vec) {
						checkwinner = 'c';
						break;
					}
					else if (checkvec == 79 * vec) {
						checkwinner = 'h';
						break;
					}
				}
			}				// ���μ��� �߿� ä���� ���� �ִ��� Ȯ��
			if (checkwinner == 'n') {
				int checkvec = 0;
				for (int i = 0; i < vec; i++) {
					checkvec = checkvec + game[i][i];
				}
				if (checkvec == 88 * vec) {
					checkwinner = 'c';
					break;
				}
				else if (checkvec == 79 * vec) {
					checkwinner = 'h';
					break;
				}
			}				// \������ ä�������� Ȯ��
			if (checkwinner == 'n') {
				int checkvec = 0;
				for (int i = 0; i < vec; i++) {
					checkvec = checkvec + game[i][vec - 1 - i];
				}
				if (checkvec == 88 * vec) {
					checkwinner = 'c';
					break;
				}
				else if (checkvec == 79 * vec) {
					checkwinner = 'h';
					break;
				}
			}				// /������ ä�������� Ȯ��
		}														//���а���
		if (checkwinner != 'n') break;
	}									//��������
	switch (checkwinner) {
	case 'n':
		printf("�̹� ������ ���º� �Դϴ�\n");
		none++;
		break;
	case 'h':
		printf("�����ڰ� �̰���ϴ�\n");
		win++;
		break;
	case 'c':
		printf("��ǻ�Ͱ� �̰����\n");
		lose++;
		break;
	}
	printf("������ �����մϴ�\n\n");
}
//7. ĭ������, ��� �·� 0%��ǥ�� ����
void cording_record(void) {
	printf("-------------------------------------------------\n");
	printf("2022 05 02 Mon : ���� ���� ����\n");
	printf("2022 05 03 Tue : ���� �⺻ ��� ����\n");
	printf("                 �ߺ���ǥ �Է½� ���Է� ����\n");
	printf("                 ��ǻ�� ������ǥ ����\n");
	printf("2022 05 04 Wed : ��ǻ�� ���� ��� �ڵ� ����\n");
	printf("2022 05 05 Thu : ���� ����\n");
	printf("2022 05 07 Sat : ���� �� ��ǥ �Է½� ���Է� ����\n");
	printf("                 ����� �Է� ��ǥ ũ�� ���� ����\n");
	printf("                 ���ۼ����� �ΰ��ӿ��� �����ϵ��� ����\n");
	printf("-------------------------------------------------\n");
	printf("������������ ���ư����� '0'�� �Է��ϰ� Enter�� ���ּ���\n���� Zero �Դϴ�\n");
	int check = 1;
	scanf("%d", &check);
	while (check != 0) {
		printf("\n��ȿ���� ���� �����Դϴ�\n�ٽ� �Է����ּ���\n");
		scanf("%d", &check);
	}
}

int main() {
	printf("Tic-Tac-Toe ���ӿ� ���Ű��� ȯ���մϴ�\n\n");

	while (1) {
		printf("���ο� ����\n\n");
		printf("��ǻ�Ϳ��� ������ ���и� ����մϴ�\n");
		printf("���� ���� : %d�� %d�� %d��\n", win, none, lose);
		float percent_h = (win == 0) ? 0 : (float)win / (win + none + lose) * 100;//�·�
		printf("������ ���� �·� : %.2f%% \n", percent_h);
		float percent_c = (lose == 0) ? 0 : (float)lose / (win + none + lose) * 100;
		printf("��ǻ�� ���� �·� : %.2f%% \n\n", percent_c);
		printf("�ɼ��� �������ּ���\n\n");
		printf(" 0. ����\n");
		printf("\n-----�⺻���-----\n");
		printf(" 1. �θ��̼� �÷���\n");
		//�ܼ��� ���� �����ư��鼭 �÷���
		printf(" 2. ��ǻ�Ϳ� �÷���(���̵� ��)\n");
		//�����õ�� ��ǥ ���� �� ����
		printf("\n-----��ȭ���-----\n");
		printf(" 3. ��ǻ�Ϳ� �÷���(���̵� �߻�)\n");
		//(1,1)�� ���� �����ϸ� ���������� ����
		printf(" 4 (������). ��ǻ�Ϳ� �÷���(���̵� �ֻ�/��ǻ�Ͱ� �����մϴ�/��ǻ�Ͱ� �·��� �е������� �����ϴ�)\n");
		//��ǻ�Ͱ� �������� ���������� �ٲ�, 2���� �̷���� ���� �ִٸ� üũ�ϰ� ���� ���Ḧ ����
		printf("\n-----ĭ������-----\n");
		printf(" 5. �θ��̼� ĭ������ �÷���(����ڰ� �Է��� ĭ���� ������ �����մϴ�/99*99ĭ���� �����մϴ�)\n");
		//�����ư��鼭 ������ ĭ���� �÷���
		printf(" 6. ��ǻ�Ϳ� ĭ������ �÷���(99*99ĭ���� �����մϴ�)\n");
		printf(" 7. (������)��ǻ�Ϳ� ĭ������ �÷���(���̵� ��/�̱� �� ������ �̰ܺ�����\n");
		printf("\n------------------\n");
		printf("8. ���� ����\n\n");
		printf("9. ���۱��\n\n");

		int o;//option
		scanf("%d", &o);
		while (o < 0 || o > 8) {
			printf("�߸��� �Է°��Դϴ�\n�ٽ� �Է����ּ���\n");
			scanf("%d", &o);
		}

		switch (o) {
		case 0:help(); break;
		case 1:play_p2p(); break;
		case 2:play_with_computer_easy(); break;
		case 3:play_with_computer_hard(); break;
		case 4:printf("�ڵ尡 �ϼ����� ���� ����Դϴ�\n������������ �̵��մϴ�\n\n"); break;
			//play_with_computer_hardcore(); break;
		case 5:play_nbyn_p2p(); break;
		case 6:printf("�ڵ尡 �ϼ����� ���� ����Դϴ�\n������������ �̵��մϴ�\n\n"); break;
			//play_nbyn_with_computer_easy(); break;
		case 7:play_nbyn_with_computer_hard(); break;
		case 9:cording_record(); break;
		default:break;
		}
		if (o == 8) {
			printf("������ �����մϴ�\n\n");
			break;
		}

	}
}