#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

#define ROOM_WIDTH 5
#define HME_POS    1
#define BWL_PO     (ROOM_WIDTH - 2)

int rollDice() {
    return rand() % 6 + 1;  // 1~6 주사위
}

void printMood(int mood) {
    switch (mood) {
    case 0: printf("기분이 매우 나쁩니다.\n"); break;
    case 1: printf("심심해합니다.\n"); break;
    case 2: printf("식빵을 굽습니다.\n"); break;
    case 3: printf("골골송을 부릅니다.\n"); break;
    }
}

int getInteractionInput(int toyMouseExists, int toyLaserExists) {
    int choice = -1;

    while (1) {
        printf("어떤 상호작용을 하시겠습니까?\n");
        printf(" 0. 아무것도 하지 않음\n");
        printf(" 1. 긁어 주기\n");

        int optionNumber = 2;
        if (toyMouseExists && toyLaserExists) {
            printf(" 2. 장난감 쥐로 놀아 주기\n");
            printf(" 3. 레이저 포인터로 놀아 주기\n");
        }
        else if (toyMouseExists) {
            printf(" 2. 장난감 쥐로 놀아 주기\n");
        }
        else if (toyLaserExists) {
            printf(" 2. 레이저 포인터로 놀아 주기\n");
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

        printf("잘못된 입력입니다. 다시 입력해 주세요.\n");
    }

    return choice;
}



int main(void) {
    srand((unsigned int)time(NULL));


    printf("****야옹이와 수프****\n");
    printf("      /\\_/\\ \n");
    printf(" /\\  / o o \\ \n");
    printf("//\\\\ \\~(*)~/\n");
    printf("`  \\/     /\n");
    printf("   | \\|| ||\n");
    printf("   \\ '|| ||\n");
    printf("    \\)()-())\n");

    char str[100];
    printf("야옹이의 이름을 지어 주세요: ");
    scanf_s("%s", str, 100);
    printf("야옹이의 이름은 %s입니다\n", str);

    Sleep(1000);
    system("cls");

    int a = 0; // 수프 개수
    int b = 2; // 친밀도
    int mood = 3; //기분 (0~3)
    int potatosoup = 0, mushroomsoup = 0, broccolisoup = 0;
    int position = 2; // 처음 위치는 가운데
    int toy_exists = 1; // 놀이기구가 있다고 가정
    int cp = 0;//cp 누적값


    // CP 계산
    int cpProduced = 0;
    if (mood - 1 > 0) {
        cpProduced = (mood - 1) + b;
    }
    else {
        cpProduced = b;  // mood - 1 <= 0이면 0 + b
    }

    // 누적 CP에 더하기
    cp += cpProduced;

    // 출력
    printf("쫀떡의 기분(0~3): %d\n", mood);
    printf("집사와의 친밀도(0~4): %d\n", b);
    printf("쫀떡의 기분과 친밀도에 따라서 CP가 %d 포인트 생산되었습니다.\n", cpProduced);
    printf("보유 CP: %d 포인트\n", cp);



    while (1) {
        printf(" ==================== 현재 상태 ===================\n");
        printf(" 현재까지 만든 수프: %d개\n", a);
        printf("CP: 0 포인트\n");
        printf("쫀떡이 기분(0~3): %d\n", mood);
        printMood(mood);
        printf("  골골송을 부릅니다.\n");
        printf(" 집사와의 관계(0~4): %d\n", b);
        if (b == 0) printf("  곁에 오는 것조차 싫어합니다.\n");
        else if (b == 1) printf("  간식 자판기 취급입니다.\n");
        else if (b == 2) printf("  그럭저럭 쓸 만한 집사입니다.\n");
        else if (b == 3) printf("  훌륭한 집사로 인정 받고 있습니다.\n");
        else if (b == 4) printf("  집사 껌딱지 입니다.\n");
        printf(" ==================================================\n");

        Sleep(500);


        // 이동 처리
        if (mood == 0) {
            printf("기분이 매우 나쁜 %s은(는) 집으로 향합니다.\n", str);
            if (position > HME_POS) position--;
        }
        else if (mood == 1) {
            if (toy_exists) {
                printf("%s은(는) 심심해서 스크래처 쪽으로 이동합니다.\n", str);
                if (position > 0) position--;
            }
            else {
                printf("놀거리가 없어서 기분이 매우 나빠집니다.\n");
                if (mood > 0) mood--;
            }
        }
        else if (mood == 2) {
            printf("%s은(는) 기분 좋게 식빵을 굽고 있습니다.\n", str);
        }
        else if (mood == 3) {
            printf("%s은(는) 골골송을 부르며 수프를 만들러 갑니다.\n", str);
            if (position < BWL_PO) position++;
        }



        // 수프 생성 (냄비 도착 시)
        if (position == BWL_PO && mood == 3) {
            int soup = rand() % 3;
            printf("%s이(가) ", str);
            switch (soup) {
            case 0: printf("감자수프"); potatosoup++; break;
            case 1: printf("양송이수프"); mushroomsoup++; break;
            case 2: printf("브로콜리수프"); broccolisoup++; break;
            }
            printf("를 만들었습니다!\n");
            a++;
        }

        // 오브젝트 상호작용 (이동 후 or 정지 시)


        int stayedAtHome = 0;
       
            if (position == HME_POS && mood != 0) {
                static int stayedAtHome = 0;
                if (stayedAtHome) {
                    int prevMood = mood;
                    if (mood < 3) mood++;
                    printf("%s은(는) 집에서 푹 쉽니다.\n", str);
                    printf("기분이 좋아졌습니다: %d -> %d\n", prevMood, mood);
                }
                else {
                    printf("%s은(는) 집에 도착했습니다. 다음 턴부터 쉴 수 있습니다.\n", str);
                    stayedAtHome = 1;
                }
            }
            else {
                stayedAtHome = 0; // 집이 아닌 곳이면 초기화
            }

            if (position == 2) { // 스크래처 위치
                int prevMood = mood;
                if (mood < 3) mood++;
                printf("%s은(는) 스크래처를 긁고 놀았습니다.\n", str);
                printf("기분이 조금 좋아졌습니다: %d -> %d\n", prevMood, mood);
            }

            if (position == 3) { // 캣타워 위치 (예: 너비 5에서 한 칸 띄운 곳)
                int prevMood = mood;
                int gain = (mood <= 1) ? 2 : 3 - mood; // 최대 mood 3까지만
                mood += gain;
                printf("%s은(는) 캣타워를 뛰어다닙니다.\n", str);
                printf("기분이 제법 좋아졌습니다: %d -> %d\n", prevMood, mood);
            }
        








        // 맵 출력
        printf("###############\n");
        printf("#H     S    B#\n#");
        for (int i = 0; i < ROOM_WIDTH; i++) {
            if (i == position) printf("C");
            else printf(".");
        }
        printf("       #\n");
        printf("###############\n");








        int d = 0; // 주사위
        int soup = rand() % 3;

        printf("\n%s 이동: 집사와 친밀할수록 냄비 쪽으로 갈 확률이 높아집니다.\n", str);
        printf(" 주사위 눈이 3 이상이면 냄비쪽으로 이동합니다.\n");
        srand((unsigned int)time(NULL));

        d = rand() % 6 + 1;
        printf(" 주사위를 굴립니다. 또르륵...\n");
        printf(" %d이(가) 나왔습니다!\n", d);

        if (d >= 6 - b) {
            printf("냄비 쪽으로 이동합니다.\n");
            printf("%s이(가) ", str);

            switch (soup) {
            case 0:
                printf("감자수프");
                potatosoup++;
                break;
            case 1:
                printf("양송이수프");
                mushroomsoup++;
                break;
            case 2:
                printf("브로콜리수프");
                broccolisoup++;
                break;
            }
            printf("를 만들었습니다!\n");
            a++;
        }
        else {
            printf("집 쪽으로 이동합니다.\n");
        }

        if (d <= 4) {
            int prevMood = mood;
            if (mood > 0) mood--;
            printf("쫀떡의 기분이 나빠집니다: %d -> %d\n", prevMood, mood);
            printf("아무 이유 없이 기분이 나빠집니다. 고양이니까?\n");
            printMood(mood);

            // 추가 주사위 굴림(6 - 친밀도 이하이면 또 기분 나빠짐)
            int d2 = rollDice();
            printf("추가 주사위를 굴립니다. 또르륵...\n");
            printf("%d이(가) 나왔습니다!\n", d2);
            if (d2 <= 6 - b) {
                prevMood = mood;
                if (mood > 0) mood--;
                printf("쫀떡의 기분이 또 나빠집니다: %d -> %d\n", prevMood, mood);
                printMood(mood);
            }
        }








        printf("현재까지 만든 수프: %d개 (감자:%d, 양송이:%d, 브로콜리:%d)\n", a, potatosoup, mushroomsoup, broccolisoup);







        Sleep(500);

        // 상호작용 입력 받기
        int toyMouseExists = 1;  // 예시
        int toyLaserExists = 0;  // 예시
        int c = getInteractionInput(toyMouseExists, toyLaserExists);

        if (c == 0) {  // 아무것도 하지 않음
            printf("아무것도 하지 않습니다.\n");

            // 기분 -1
            int prevMood = mood;
            if (mood > 0) mood--;
            printf("%s의 기분이 나빠졌습니다: %d -> %d\n", str, prevMood, mood);

            // 친밀도 주사위 5 이하이면 1 감소
            d = rollDice();
            printf("주사위를 굴립니다. 또르륵...\n");
            printf("%d이(가) 나왔습니다!\n", d);
            if (d <= 5) {
                printf("집사와의 관계가 나빠집니다.\n");
                if (b > 0) b--;
            }
            else {
                printf("친밀도는 그대로입니다.\n");
            }
        }
        else if (c == 1) {  // 긁어주기
            printf("%s의 턱을 긁어주었습니다.\n", str);

            // 기분 그대로
            printf("%s의 기분은 그대로입니다: %d\n", str, mood);

            // 친밀도 주사위 5 이상이면 1 증가
            d = rollDice();
            printf("주사위를 굴립니다. 또르륵...\n");
            printf("%d이(가) 나왔습니다!\n", d);
            if (d >= 5) {
                printf("집사와의 관계가 좋아집니다.\n");
                if (b < 4) b++;
            }
            else {
                printf("친밀도는 그대로입니다.\n");
            }
        }
        else if (c == 2) {  // 장난감 쥐로 놀아주기
            if (toyMouseExists) {
                printf("장난감 쥐로 %s와 놀아주었습니다.\n", str);

                // 기분 +1
                int prevMood = mood;
                if (mood < 3) mood++;
                printf("%s의 기분이 조금 좋아졌습니다: %d -> %d\n", str, prevMood, mood);

                // 친밀도 주사위 4 이상이면 1 증가
                d = rollDice();
                printf("주사위를 굴립니다. 또르륵...\n");
                printf("%d이(가) 나왔습니다!\n", d);
                if (d >= 4) {
                    printf("집사와의 관계가 좋아집니다.\n");
                    if (b < 4) b++;
                }
                else {
                    printf("친밀도는 그대로입니다.\n");
                }
            }
            else if (toyLaserExists) {
                printf("레이저 포인터로 %s와 놀아주었습니다.\n", str);

                // 기분 +2
                int prevMood = mood;
                mood += 2;
                if (mood > 3) mood = 3;
                printf("%s의 기분이 꽤 좋아졌습니다: %d -> %d\n", str, prevMood, mood);

                // 친밀도 주사위 2 이상이면 1 증가
                d = rollDice();
                printf("주사위를 굴립니다. 또르륵...\n");
                printf("%d이(가) 나왔습니다!\n", d);
                if (d >= 2) {
                    printf("집사와의 관계가 좋아집니다.\n");
                    if (b < 4) b++;
                }
                else {
                    printf("친밀도는 그대로입니다.\n");
                }
            }
        }
        else if (c == 3 && toyMouseExists && toyLaserExists) {  // 레이저 포인터 놀아주기
            printf("레이저 포인터로 %s와 신나게 놀아주었습니다.\n", str);

            // 기분 +2
            int prevMood = mood;
            mood += 2;
            if (mood > 3) mood = 3;
            printf("%s의 기분이 꽤 좋아졌습니다: %d -> %d\n", str, prevMood, mood);

            // 친밀도 주사위 2 이상이면 1 증가
            d = rollDice();
            printf("주사위를 굴립니다. 또르륵...\n");
            printf("%d이(가) 나왔습니다!\n", d);
            if (d >= 2) {
                printf("집사와의 관계가 좋아집니다.\n");
                if (b < 4) b++;
            }
            else {
                printf("친밀도는 그대로입니다.\n");
            }
        }


        printf(" 현재 친밀도: %d\n", b);

        
              
        // 상태
        int cp = 5;  // 예시 CP
        int toy1 = 0, toy2 = 0, toy3 = 0, toy4 = 0; // 구매 여부
        int scratcher_x = -1, scratcher_y = -1;
        int tower_x = -1, tower_y = -1;

        // 맵: 기존 가구 위치 예시
        int obj1_x = 1, obj1_y = 1; // 예: 집
        int obj2_x = 3, obj2_y = 1; // 예: 냄비

        // 놀이기구 배치 함수
        void place_item_randomly(int* x, int* y) {
            int px, py;
            do {
                px = rand() % 5;
                py = rand() % 4;
            } while ((px == obj1_x && py == obj1_y) ||
                (px == obj2_x && py == obj2_y) ||
                (px == scratcher_x && py == scratcher_y) ||
                (px == tower_x && py == tower_y));
            *x = px;
            *y = py;
        }



        void show_store() {
            int choice;
            while (1) {
                printf("상점에서 물건을 살 수 있습니다.\n");
                printf("어떤 물건을 구매할까요?\n");
                printf(" 0. 아무 것도 사지 않는다.\n");
                printf(" 1. 장난감 쥐: 1 CP %s\n", toy1 ? "(품절)" : "");
                printf(" 2. 레이저 포인터: 2 CP %s\n", toy2 ? "(품절)" : "");
                printf(" 3. 스크래처: 4 CP %s\n", toy3 ? "(품절)" : "");
                printf(" 4. 캣 타워: 6 CP %s\n", toy4 ? "(품절)" : "");
                printf(" >> ");
                scanf("%d", &choice);

                if (choice < 0 || choice > 4) {
                    printf("잘못된 입력입니다. 다시 입력하세요.\n");
                    continue;
                }

                if (choice == 0) break;

                if ((choice == 1 && toy1) || (choice == 2 && toy2) ||
                    (choice == 3 && toy3) || (choice == 4 && toy4)) {
                    printf("이미 구매한 물건입니다.\n");
                    continue;
                }

                int cost = 0;
                char* item = "";

                switch (choice) {
                case 1: cost = 1; item = "장난감 쥐"; break;
                case 2: cost = 2; item = "레이저 포인터"; break;
                case 3: cost = 4; item = "스크래처"; break;
                case 4: cost = 6; item = "캣 타워"; break;
                }

                if (cp < cost) {
                    printf("CP가 부족합니다.\n");
                    continue;
                }

                // 구매 처리
                cp -= cost;
                if (choice == 1) toy1 = 1;
                if (choice == 2) toy2 = 1;
                if (choice == 3) {
                    toy3 = 1;
                    place_item_randomly(&scratcher_x, &scratcher_y);
                }
                if (choice == 4) {
                    toy4 = 1;
                    place_item_randomly(&tower_x, &tower_y);
                }

                printf("%s를 구매했습니다.\n", item);
                printf("보유 CP: %d 포인트\n", cp);
            }
        }


               

        int turn = 0;  // main 함수 맨 위에 선언 추가

        // while (1) 루프 안 가장 윗부분에 아래 코드 추가:
        turn++;

        if (turn == 3) {
            printf("\n[돌발 퀘스트 발생! - 쫀떡이의 숨은 발톱을 찾아라!]\n");
            printf("쫀떡이가 발톱을 잃어버렸습니다. 숨은 장소는 어딜까요?\n");
            printf("1. 스크래처 밑\n2. 수프 냄비 뒤\n3. 캣타워 위\n");

            int answer = rand() % 3 + 1; // 정답 위치
            int guess = 0;
            while (1) {
                printf("당신의 선택은? (1~3): ");
                scanf_s("%d", &guess);
                if (guess >= 1 && guess <= 3) break;
                printf("잘못된 입력입니다. 다시 선택하세요.\n");
            }

            if (guess == answer) {
                printf("정답입니다! 쫀떡이의 기분이 좋아졌습니다!\n");
                if (mood < 3) mood++;
                cp++;
            }
            else {
                printf("틀렸습니다... 쫀떡이의 기분이 나빠졌습니다.\n");
                if (mood > 0) mood--;
            }

            Sleep(1500);
            system("cls");
        }








       

        Sleep(2500);
        system("cls");
    }

        return 0;
    }
    
   