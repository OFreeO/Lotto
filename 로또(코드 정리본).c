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
	printf("�ڡٺ��� ��ȣ ������١�\n");
	printf("��� �����Ͻðڽ��ϱ�? : ");
	count = Clotto(count);//Ƚ�� ������ �Լ�
	csave = count;//������� ���� ī��Ʈ���� ����
	while (count > 0) {
	Plotto(lotto, save, num, count2, count1);//�ζ� ��ȣ ���� �Լ�
	count--;
	}
	re = replay(re, lotto, save, num, count, csave, count1, count2);
	return 0;
}
int  Clotto(int count)
{
	count = 0;
	scanf_s("%d", &count);
	printf("%d�� �����մϴ�.\n\n", count);
	return count;
}
int Plotto(int lotto[6], int save, int num, int count2,int count1)
{
	for (int i = 0; i <= 5; i++) {
		lotto[i] = rand() % 45 + 1;//���� ���� ����
		if (lotto[i] % 2 == 0) {//¦��ī����
			count2++;
			if (count2 == 6) {//��� ¦���Ͻ� Ż��
				break;
				count2 = 0;
				i = 0;
			}
		}
		if (lotto[i] % 2 != 0) {//Ȧ��ī����
			count1++;
			if (count1 == 6) {//��� Ȧ���Ͻ� Ż��
				break;
				count1 = 0;
				i = 0;
			}
		}
		for (int j = 0; j < i; j++) {
			if (lotto[i] == lotto[j]) {//�ߺ��� ����
				i--;
				break;
			}
		}
	}

	for (int i = 0; i <= 5; i++) {
		if (lotto[i] % 2 == 0) {//¦�� ī����
			num++;

		}
	}
	count1 = 0;
	count2 = 0;
	for (int i = 0; i <= 5; i++) {//������ �� �迭
		for (int j = 0; j <= 4; j++) {
			if (lotto[j] > lotto[j + 1]) {
				save = lotto[j];
				lotto[j] = lotto[j + 1];
				lotto[j + 1] = save;
			}
		}
	}
	for (int i = 0; i <= 5; i++) {//��ȣ ���
		printf("%2d�� ", lotto[i]);
	}
	if (num == 3 || num == 2){
		printf("����õ��");
	}
	printf("\n\n");

}
int replay(int re,int lotto,int save,int num,int count,int csave,int count2,int count1)
{
	printf("�̰ɷ� ����Ͻðڽ��ϱ�?\n1. ��\n2. �ƴϿ�\n");
	scanf_s("%d", &re);
	if (re == 2) {
		printf("\n����� ���\n\n");
		count = csave;//�����ߴ� ī��Ʈ ���� ī��Ʈ�� �־���
		while (count > 0) {
			Plotto(lotto, save, num,count2, count1);//�ζ� ��ȣ ���� �Լ�
			count--;
		}
		replay(re, lotto, save, num, count, csave, count2, count1);
	}
	if (re == 1) {
		printf("\n1�� ��÷�� �����մϴ�!!!");
	}
	
	if (re > 2) {
		printf("�߸� �Է��ϼ̽��ϴ�.\n");
		replay(re, lotto, save, num, count, csave, count2, count1);
	}
}