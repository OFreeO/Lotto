#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	srand(time(NULL));
	int lotto[6] = { 0, };
	int count = 0;
	int save = 0;
	int num = 0;
	int re = 0;
	int csave = 0;
	int count2 = 0;
	int count1 = 0;
	printf("★☆복권 번호 생성기☆★\n");
	printf("몇번 발행하시겠습니까? : ");
	count = Clotto(count);//횟수 지정용 함수
	csave = count;//재출력을 위해 카운트값을 저장
	while (count > 0) {
	Plotto(lotto, save, num, count2, count1);//로또 번호 생성 함수
	count--;
	}
	re = replay(re, lotto, save, num, count, csave, count1, count2);
	return 0;
}
int  Clotto(int count)
{
	count = 0;
	scanf_s("%d", &count);
	printf("%d번 발행합니다.\n\n", count);
	return count;
}
int Plotto(int lotto[6], int save, int num, int count2,int count1)
{
	for (int i = 0; i <= 5; i++) {
		lotto[i] = rand() % 45 + 1;//랜덤 난수 생성
		if (lotto[i] % 2 == 0) {//짝수카운터
			count2++;
			if (count2 == 6) {//모두 짝수일시 탈출
				break;
				count2 = 0;
				i = 0;
			}
		}
		if (lotto[i] % 2 != 0) {//홀수카운터
			count1++;
			if (count1 == 6) {//모두 홀수일시 탈출
				break;
				count1 = 0;
				i = 0;
			}
		}
		for (int j = 0; j < i; j++) {
			if (lotto[i] == lotto[j]) {//중복수 제거
				i--;
				break;
			}
		}
	}

	for (int i = 0; i <= 5; i++) {
		if (lotto[i] % 2 == 0) {//짝수 카운터
			num++;

		}
	}
	count1 = 0;
	count2 = 0;
	for (int i = 0; i <= 5; i++) {//오름차 순 배열
		for (int j = 0; j <= 4; j++) {
			if (lotto[j] > lotto[j + 1]) {
				save = lotto[j];
				lotto[j] = lotto[j + 1];
				lotto[j + 1] = save;
			}
		}
	}
	for (int i = 0; i <= 5; i++) {//번호 출력
		printf("%2d번 ", lotto[i]);
	}
	if (num == 3 || num == 2){
		printf("★추천★");
	}
	printf("\n\n");

}
int replay(int re,int lotto,int save,int num,int count,int csave,int count2,int count1)
{
	printf("이걸로 출력하시겠습니까?\n1. 예\n2. 아니오\n");
	scanf_s("%d", &re);
	if (re == 2) {
		printf("\n재출력 결과\n\n");
		count = csave;//저장했던 카운트 값을 카운트에 넣어줌
		while (count > 0) {
			Plotto(lotto, save, num,count2, count1);//로또 번호 생성 함수
			count--;
		}
		replay(re, lotto, save, num, count, csave, count2, count1);
	}
	if (re == 1) {
		printf("\n1등 당첨을 응원합니다!!!");
	}
	
	if (re > 2) {
		printf("잘못 입력하셨습니다.\n");
		replay(re, lotto, save, num, count, csave, count2, count1);
	}
}