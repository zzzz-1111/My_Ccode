#include <cstdio>
#include <Windows.h>

// argv[1]���ļ�������������֣�������׺��
// argv[2]�Ƕ��ĵĴ���
// argv[3]������������������
int main(int argc, char* argv[])
{
	int N; // ����N��
	sscanf(argv[2], "%d", &N);
	const char* file_name = argv[1]; // �ļ���
	const char* maxn = argv[3]; // ����������������
	char str[100];
	do
	{
		// ����������ݵĳ�����Ϊrand.exe
		// t�����ݷ�Χ
		sprintf(str, "echo %s > t && rand < t > %s.in", maxn, file_name);
		system(str);
		// ȷ������ȷ�ĳ�����Ϊcorrect.exe
		sprintf(str, "correctac < %s.in > ac%s.out", file_name, file_name);
		system(str);
		// ��ȷ���Ƿ���ȷ�ĳ�����Ϊunknown.exe
		sprintf(str, "unknown < %s.in > uk%s.out", file_name, file_name);
		system(str);
		sprintf(str, "fc ac%s.out uk%s.out", file_name, file_name);
	} while (not system(str) and N--);
	system("del t");
	if (N == 0)
	{
		printf("You are right.");
		sprintf(str, "del %s.out ac%s.in uk%s.out", file_name, file_name, file_name);
		system(str);
	}
	else printf("You are wrong.");
	return 0;
}