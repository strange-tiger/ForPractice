#include <stdio.h>

// 파일 입출력
int main(void)
{
	// 1. 파일을 다루기 위한 객체 생성
	FILE* fp = NULL;

	// 2. 파일을 연다.
	// 파일의 종류
	// 1) 텍스트 파일 : 텍스트 에디터로 열 수 있는 파일로, 우리가 읽을 수 있는 문자로 구성
	// 2) 바이너리 파일 : 그 외의 모든 파일
	if (0 != fopen_s(&fp, "Metaverse", "w"))	//	Metaverse라는 이름을 가진 텍스트 파일을 연다.
	{
		printf("오류 발생함.");	// 파일을 열 때는 항상 예외 처리에 주의할 것.

		return 1;
	}

	// 3. 파일을 조작한다.
	// 텍스트 파일에 사용할 수 있는 함수 : fputs() / fputc() / fprintf()
	// 바이너리 파일에 사용할 수 있는 함수 : fwrite()
	fputs("Hello File!", fp);
	fputc('J', fp);
	fprintf(fp, "\nThe name of the queen : %s\n", "퀸균지");

	// 4. 파일을 닫는다.
	fclose(fp);

	if (0 != fopen_s(&fp, "Metaverse", "r"))	//	Metaverse라는 이름을 가진 텍스트 파일을 연다.
	{
		printf("오류 발생함.");	// 파일을 열 때는 항상 예외 처리에 주의할 것.

		return 1;
	}

	// 텍스트 파일에서 읽어들일 수 있는 함수 : fgets() / fgetc() / fscanf()
	// 바이너리 파일에서 읽어들일 수 있는 함수 : fread()

	char ch = fgetc(fp);
	char str[128] = "";
	fgets(str, sizeof(str), fp);	//	개행 문자까지 받아들인다.
	char str2[128] = "";
	fscanf_s(fp, "The name of the queen : %s\n", str2, sizeof(str2));

	printf("읽어들인 문자 : %c\n", ch);
	printf("읽어들인 문자열 : %s\n", str);
	printf("퀸은 누구? : %s\n", str2);

	fclose(fp);

	// ----------------------------
	// 바이너리 파일
	// ----------------------------
	if (0 != fopen_s(&fp, "Metaverse2", "wb"))	//	Metaverse2라는 이름을 가진 바이너리 파일을 연다. // wb 모드
	{
		printf("오류 발생함.");	// 파일을 열 때는 항상 예외 처리에 주의할 것.

		return 1;
	}

	struct Student
	{
		int Age;	// 4바이트
		enum { A, B, O, AB } BloodType;
		char Name[24];
	};

	struct Student s = { 20, A, "최선문"};

	if (1 != fwrite(&s, sizeof(s), 1, fp))
	{
		printf("오류 발생함.");

		fclose(fp);

		return 1;
	}

	fclose(fp);

	if (0 != fopen_s(&fp, "Metaverse2", "rb"))	//	Metaverse2라는 이름을 가진 바이너리 파일을 연다. // rb 모드
	{
		printf("오류 발생함.");	// 파일을 열 때는 항상 예외 처리에 주의할 것.

		fclose(fp);

		return 1;
	}

	struct Student s2 = { 0 };
	if (1 != fread(&s2, sizeof(s2), 1, fp))
	{
		printf("오류 발생함.");

		fclose(fp);

		return 1;
	}

	printf("나이 : %d, 혈액형 : %c, 이름 : %s\n", s2.Age, s2.BloodType, s2.Name);

	fclose(fp);

	return 0;
}