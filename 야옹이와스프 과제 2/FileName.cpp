#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

#define ROOM_WIDTH 5
#define HME_POS    1
#define BWL_PO     (ROOM_WIDTH - 2)

int main(void) {
    printf("****�߿��̿� ����****\n");
    printf("      /\\_/\\ \n");
    printf(" /\\  / o o \\ \n");
    printf("//\\\\ \\~(*)~/\n");
    printf("`  \\/     /\n");
    printf("   | \\|| ||\n");
    printf("   \\ '|| ||\n");
    printf("    \\)()-())\n");

    char str[100];
    printf("�߿����� �̸��� ���� �ּ���: ");
    scanf_s("%s", str, 100);
    printf("�߿����� �̸��� %s�Դϴ�\n", str);

    Sleep(1000);
    system("cls");

    int a = 0; // ���� ����
    int b = 2; // ģ�е�
    int potatosoup = 0, mushroomsoup = 0, broccolisoup = 0;

    while (1) {
        printf(" ==================== ���� ���� ===================\n");
        printf(" ������� ���� ����: %d��\n", a);
        printf(" ������� ����(0~4): %d\n", b);
        if (b == 0) printf("  �翡 ���� ������ �Ⱦ��մϴ�.\n");
        else if (b == 1) printf("  ���� ���Ǳ� ����Դϴ�.\n");
        else if (b == 2) printf("  �׷����� �� ���� �����Դϴ�.\n");
        else if (b == 3) printf("  �Ǹ��� ����� ���� �ް� �ֽ��ϴ�.\n");
        else if (b == 4) printf("  ���� ������ �Դϴ�.\n");
        printf(" ==================================================\n");

        Sleep(500);

        int d = 0; // �ֻ���
        int soup = rand() % 3;

        printf("\n%s �̵�: ����� ģ���Ҽ��� ���� ������ �� Ȯ���� �������ϴ�.\n", str);
        printf(" �ֻ��� ���� 3 �̻��̸� ���������� �̵��մϴ�.\n");
        srand((unsigned int)time(NULL));

        d = rand() % 6 + 1;
        printf(" �ֻ����� �����ϴ�. �Ǹ���...\n");
        printf(" %d��(��) ���Խ��ϴ�!\n", d);

        if (d >= 6 - b) {
            printf("���� ������ �̵��մϴ�.\n");
            printf("%s��(��) ", str);

            switch (soup) {
            case 0:
                printf("���ڼ���");
                potatosoup++;
                break;
            case 1:
                printf("����̼���");
                mushroomsoup++;
                break;
            case 2:
                printf("����ݸ�����");
                broccolisoup++;
                break;
            }
            printf("�� ��������ϴ�!\n");
            a++;
        }
        else {
            printf("�� ������ �̵��մϴ�.\n");
        }

        printf("������� ���� ����: %d�� (����:%d, �����:%d, ����ݸ�:%d)\n", a, potatosoup, mushroomsoup, broccolisoup);

        printf("\n #####\n");
        printf(" #H B#\n");
        printf(" #C  #\n");
        printf(" #####\n");

        Sleep(500);

        int c = 0;
        while (1) {
            printf("\n � ��ȣ�ۿ��� �Ͻðڽ��ϱ�?  0. �ƹ��͵� ���� ���� 1. �ܾ� �ֱ�\n >> ");
            scanf_s("%d", &c);
            if (c == 0 || c == 1) break;
            else printf("�ٽ� �Է��� �ּ��� (0 �Ǵ� 1)\n");
        }

        if (c == 0) {
            printf(" �ƹ��͵� ���� �ʽ��ϴ�.\n");
            printf(" 4/6�� Ȯ���� ģ�е��� �������ϴ�.\n");

            d = rand() % 6 + 1;
            printf(" �ֻ����� �����ϴ�. �Ǹ���...\n");
            printf(" %d��(��) ���Խ��ϴ�!\n", d);
            if (d <= 4) {
                printf(" ģ�е��� �������ϴ�.\n");
                if (b > 0) b--;
            }
            else {
                printf(" ������ ģ�е��� �������� �ʾҽ��ϴ�.\n");
            }
        }
        else if (c == 1) {
            printf(" %s�� ���� �ܾ��־����ϴ�.\n", str);
            printf(" 2/6�� Ȯ���� ģ�е��� �������ϴ�.\n");

            d = rand() % 6 + 1;
            printf(" �ֻ����� �����ϴ�. �Ǹ���...\n");
            printf(" %d��(��) ���Խ��ϴ�!\n", d);
            if (d >= 5) {
                printf(" ģ�е��� �������ϴ�.\n");
                if (b < 4) b++;
            }
            else {
                printf(" ģ�е��� �״���Դϴ�.\n");
            }
        }

        printf(" ���� ģ�е�: %d\n", b);

        Sleep(2500);
        system("cls");
    }

    return 0;
}
