#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

#define ROOM_WIDTH 5
#define HME_POS    1
#define BWL_PO     (ROOM_WIDTH - 2)

int rollDice() {
    return rand() % 6 + 1;  // 1~6 �ֻ���
}

void printMood(int mood) {
    switch (mood) {
    case 0: printf("����� �ſ� ���޴ϴ�.\n"); break;
    case 1: printf("�ɽ����մϴ�.\n"); break;
    case 2: printf("�Ļ��� �����ϴ�.\n"); break;
    case 3: printf("������ �θ��ϴ�.\n"); break;
    }
}

int getInteractionInput(int toyMouseExists, int toyLaserExists) {
    int choice = -1;

    while (1) {
        printf("� ��ȣ�ۿ��� �Ͻðڽ��ϱ�?\n");
        printf(" 0. �ƹ��͵� ���� ����\n");
        printf(" 1. �ܾ� �ֱ�\n");

        int optionNumber = 2;
        if (toyMouseExists && toyLaserExists) {
            printf(" 2. �峭�� ��� ��� �ֱ�\n");
            printf(" 3. ������ �����ͷ� ��� �ֱ�\n");
        }
        else if (toyMouseExists) {
            printf(" 2. �峭�� ��� ��� �ֱ�\n");
        }
        else if (toyLaserExists) {
            printf(" 2. ������ �����ͷ� ��� �ֱ�\n");
        }

        printf(">> ");

        scanf_s("%d", &choice);

        if (toyMouseExists && toyLaserExists) {
            if (choice >= 0 && choice <= 3) break;
        }
        else if (toyMouseExists || toyLaserExists) {
            if (choice >= 0 && choice <= 2) break;
        }
        else {
            if (choice == 0 || choice == 1) break;
        }

        printf("�߸��� �Է��Դϴ�. �ٽ� �Է��� �ּ���.\n");
    }

    return choice;
}



int main(void) {
    srand((unsigned int)time(NULL));


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
    int mood = 3; //��� (0~3)
    int potatosoup = 0, mushroomsoup = 0, broccolisoup = 0;
    int position = 2; // ó�� ��ġ�� ���
    int toy_exists = 1; // ���̱ⱸ�� �ִٰ� ����
    int cp = 0;//cp ������


    // CP ���
    int cpProduced = 0;
    if (mood - 1 > 0) {
        cpProduced = (mood - 1) + b;
    }
    else {
        cpProduced = b;  // mood - 1 <= 0�̸� 0 + b
    }

    // ���� CP�� ���ϱ�
    cp += cpProduced;

    // ���
    printf("�˶��� ���(0~3): %d\n", mood);
    printf("������� ģ�е�(0~4): %d\n", b);
    printf("�˶��� ��а� ģ�е��� ���� CP�� %d ����Ʈ ����Ǿ����ϴ�.\n", cpProduced);
    printf("���� CP: %d ����Ʈ\n", cp);



    while (1) {
        printf(" ==================== ���� ���� ===================\n");
        printf(" ������� ���� ����: %d��\n", a);
        printf("CP: 0 ����Ʈ\n");
        printf("�˶��� ���(0~3): %d\n", mood);
        printMood(mood);
        printf("  ������ �θ��ϴ�.\n");
        printf(" ������� ����(0~4): %d\n", b);
        if (b == 0) printf("  �翡 ���� ������ �Ⱦ��մϴ�.\n");
        else if (b == 1) printf("  ���� ���Ǳ� ����Դϴ�.\n");
        else if (b == 2) printf("  �׷����� �� ���� �����Դϴ�.\n");
        else if (b == 3) printf("  �Ǹ��� ����� ���� �ް� �ֽ��ϴ�.\n");
        else if (b == 4) printf("  ���� ������ �Դϴ�.\n");
        printf(" ==================================================\n");

        Sleep(500);


        // �̵� ó��
        if (mood == 0) {
            printf("����� �ſ� ���� %s��(��) ������ ���մϴ�.\n", str);
            if (position > HME_POS) position--;
        }
        else if (mood == 1) {
            if (toy_exists) {
                printf("%s��(��) �ɽ��ؼ� ��ũ��ó ������ �̵��մϴ�.\n", str);
                if (position > 0) position--;
            }
            else {
                printf("��Ÿ��� ��� ����� �ſ� �������ϴ�.\n");
                if (mood > 0) mood--;
            }
        }
        else if (mood == 2) {
            printf("%s��(��) ��� ���� �Ļ��� ���� �ֽ��ϴ�.\n", str);
        }
        else if (mood == 3) {
            printf("%s��(��) ������ �θ��� ������ ���鷯 ���ϴ�.\n", str);
            if (position < BWL_PO) position++;
        }



        // ���� ���� (���� ���� ��)
        if (position == BWL_PO && mood == 3) {
            int soup = rand() % 3;
            printf("%s��(��) ", str);
            switch (soup) {
            case 0: printf("���ڼ���"); potatosoup++; break;
            case 1: printf("����̼���"); mushroomsoup++; break;
            case 2: printf("����ݸ�����"); broccolisoup++; break;
            }
            printf("�� ��������ϴ�!\n");
            a++;
        }

        // ������Ʈ ��ȣ�ۿ� (�̵� �� or ���� ��)


        int stayedAtHome = 0;
       
            if (position == HME_POS && mood != 0) {
                static int stayedAtHome = 0;
                if (stayedAtHome) {
                    int prevMood = mood;
                    if (mood < 3) mood++;
                    printf("%s��(��) ������ ǫ ���ϴ�.\n", str);
                    printf("����� ���������ϴ�: %d -> %d\n", prevMood, mood);
                }
                else {
                    printf("%s��(��) ���� �����߽��ϴ�. ���� �Ϻ��� �� �� �ֽ��ϴ�.\n", str);
                    stayedAtHome = 1;
                }
            }
            else {
                stayedAtHome = 0; // ���� �ƴ� ���̸� �ʱ�ȭ
            }

            if (position == 2) { // ��ũ��ó ��ġ
                int prevMood = mood;
                if (mood < 3) mood++;
                printf("%s��(��) ��ũ��ó�� �ܰ� ��ҽ��ϴ�.\n", str);
                printf("����� ���� ���������ϴ�: %d -> %d\n", prevMood, mood);
            }

            if (position == 3) { // ĹŸ�� ��ġ (��: �ʺ� 5���� �� ĭ ��� ��)
                int prevMood = mood;
                int gain = (mood <= 1) ? 2 : 3 - mood; // �ִ� mood 3������
                mood += gain;
                printf("%s��(��) ĹŸ���� �پ�ٴմϴ�.\n", str);
                printf("����� ���� ���������ϴ�: %d -> %d\n", prevMood, mood);
            }
        








        // �� ���
        printf("###############\n");
        printf("#H     S    B#\n#");
        for (int i = 0; i < ROOM_WIDTH; i++) {
            if (i == position) printf("C");
            else printf(".");
        }
        printf("       #\n");
        printf("###############\n");








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

        if (d <= 4) {
            int prevMood = mood;
            if (mood > 0) mood--;
            printf("�˶��� ����� �������ϴ�: %d -> %d\n", prevMood, mood);
            printf("�ƹ� ���� ���� ����� �������ϴ�. ����̴ϱ�?\n");
            printMood(mood);

            // �߰� �ֻ��� ����(6 - ģ�е� �����̸� �� ��� ������)
            int d2 = rollDice();
            printf("�߰� �ֻ����� �����ϴ�. �Ǹ���...\n");
            printf("%d��(��) ���Խ��ϴ�!\n", d2);
            if (d2 <= 6 - b) {
                prevMood = mood;
                if (mood > 0) mood--;
                printf("�˶��� ����� �� �������ϴ�: %d -> %d\n", prevMood, mood);
                printMood(mood);
            }
        }








        printf("������� ���� ����: %d�� (����:%d, �����:%d, ����ݸ�:%d)\n", a, potatosoup, mushroomsoup, broccolisoup);







        Sleep(500);

        // ��ȣ�ۿ� �Է� �ޱ�
        int toyMouseExists = 1;  // ����
        int toyLaserExists = 0;  // ����
        int c = getInteractionInput(toyMouseExists, toyLaserExists);

        if (c == 0) {  // �ƹ��͵� ���� ����
            printf("�ƹ��͵� ���� �ʽ��ϴ�.\n");

            // ��� -1
            int prevMood = mood;
            if (mood > 0) mood--;
            printf("%s�� ����� ���������ϴ�: %d -> %d\n", str, prevMood, mood);

            // ģ�е� �ֻ��� 5 �����̸� 1 ����
            d = rollDice();
            printf("�ֻ����� �����ϴ�. �Ǹ���...\n");
            printf("%d��(��) ���Խ��ϴ�!\n", d);
            if (d <= 5) {
                printf("������� ���谡 �������ϴ�.\n");
                if (b > 0) b--;
            }
            else {
                printf("ģ�е��� �״���Դϴ�.\n");
            }
        }
        else if (c == 1) {  // �ܾ��ֱ�
            printf("%s�� ���� �ܾ��־����ϴ�.\n", str);

            // ��� �״��
            printf("%s�� ����� �״���Դϴ�: %d\n", str, mood);

            // ģ�е� �ֻ��� 5 �̻��̸� 1 ����
            d = rollDice();
            printf("�ֻ����� �����ϴ�. �Ǹ���...\n");
            printf("%d��(��) ���Խ��ϴ�!\n", d);
            if (d >= 5) {
                printf("������� ���谡 �������ϴ�.\n");
                if (b < 4) b++;
            }
            else {
                printf("ģ�е��� �״���Դϴ�.\n");
            }
        }
        else if (c == 2) {  // �峭�� ��� ����ֱ�
            if (toyMouseExists) {
                printf("�峭�� ��� %s�� ����־����ϴ�.\n", str);

                // ��� +1
                int prevMood = mood;
                if (mood < 3) mood++;
                printf("%s�� ����� ���� ���������ϴ�: %d -> %d\n", str, prevMood, mood);

                // ģ�е� �ֻ��� 4 �̻��̸� 1 ����
                d = rollDice();
                printf("�ֻ����� �����ϴ�. �Ǹ���...\n");
                printf("%d��(��) ���Խ��ϴ�!\n", d);
                if (d >= 4) {
                    printf("������� ���谡 �������ϴ�.\n");
                    if (b < 4) b++;
                }
                else {
                    printf("ģ�е��� �״���Դϴ�.\n");
                }
            }
            else if (toyLaserExists) {
                printf("������ �����ͷ� %s�� ����־����ϴ�.\n", str);

                // ��� +2
                int prevMood = mood;
                mood += 2;
                if (mood > 3) mood = 3;
                printf("%s�� ����� �� ���������ϴ�: %d -> %d\n", str, prevMood, mood);

                // ģ�е� �ֻ��� 2 �̻��̸� 1 ����
                d = rollDice();
                printf("�ֻ����� �����ϴ�. �Ǹ���...\n");
                printf("%d��(��) ���Խ��ϴ�!\n", d);
                if (d >= 2) {
                    printf("������� ���谡 �������ϴ�.\n");
                    if (b < 4) b++;
                }
                else {
                    printf("ģ�е��� �״���Դϴ�.\n");
                }
            }
        }
        else if (c == 3 && toyMouseExists && toyLaserExists) {  // ������ ������ ����ֱ�
            printf("������ �����ͷ� %s�� �ų��� ����־����ϴ�.\n", str);

            // ��� +2
            int prevMood = mood;
            mood += 2;
            if (mood > 3) mood = 3;
            printf("%s�� ����� �� ���������ϴ�: %d -> %d\n", str, prevMood, mood);

            // ģ�е� �ֻ��� 2 �̻��̸� 1 ����
            d = rollDice();
            printf("�ֻ����� �����ϴ�. �Ǹ���...\n");
            printf("%d��(��) ���Խ��ϴ�!\n", d);
            if (d >= 2) {
                printf("������� ���谡 �������ϴ�.\n");
                if (b < 4) b++;
            }
            else {
                printf("ģ�е��� �״���Դϴ�.\n");
            }
        }


        printf(" ���� ģ�е�: %d\n", b);

        
              

               

       







       

        Sleep(2500);
        system("cls");
    }

        return 0;
    }
    
   