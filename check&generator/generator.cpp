#include <cstdio>
#include <Windows.h>

// argv[1]���ļ�������������֣�������׺��
// argv[2]���������ݵ���������s��t
// argv[3]������������������
int main(int argc, char* argv[])
{
	int s, t;
	sscanf(argv[2], "%d%d", &s, &t); // �������ݵ�����
	const char* file_name = argv[1]; // �ļ���
	const char* maxn = argv[3]; // ����������������
	char str[100];
	for (int i = s; i <= t; ++i)
	{
		// ��������������ݵĳ�����Ϊrand.exe
		// t�����ݷ�Χ
		sprintf(str, "echo %s > t && rand < t > %s%d.in ", maxn, file_name, i);
		system(str);
		// ���ɴ𰸵ĳ�����Ϊstd.exe
		sprintf(str, "std < %s%d.in > %s%d.out", file_name, i, file_name, i);
		system(str);
	}
	system("del t");
	return 0;
}