#include<iostream>

using namespace std;

void TaskOne();
void TaskTwo();
void TaskThree();


int main() 
{
	TaskOne();
	TaskTwo();
	TaskThree();
}

//����� ��������: ������ 6 ������� ������� y=(2500*x - 8)/(3*x^2 + 20)
//� ��������� �� 2 �� ������ 3
void TaskOne() 
{
	long x = 2;
	long result[6];

	__asm
	{
		lea EBX, result				; ������������ ������ ������� ������ ���������� � EBX

		mov ECX, 6					; ������������ �������� ��������� ������� ��������

	main_loop :						; ������� ��������� ����� ��������

		mov EAX, 3					; EAX = x
		mul x
		mul x
		add EAX, 20					; EAX = 3 * x ^ 2 + 20

		mov EDI, EAX				; ��������� �������� ��������� � EDI, EDI = 3 * x ^ 2 + 20

		mov EAX, 2500
		mul x
		sub EAX, 8					; EAX = 2500 * x - 8

		div EDI						; EAX = (2500x - 8) / (3 * x ^ 2 + 20)

		mov dword ptr[EBX], EAX		; ���������� �������� ���������� � ��������� ������� ������ ����������
		add EBX, 4					; ��������� �������� EBX, �� �� ������������� �� �������� �� �������� ������� ������
		add x, 3					; ���� ���������� �� ����� 3

		loop main_loop				; ����� ��������� ����� ��������

	}
	cout << "task 1: find six values of y=(2500*x - 8)/(3*x^2 + 20)\n"
		 << "x is starting with 2 and step is equel to 3\n";
	for (int i = 0; i < 6; ++i) {
		cout << "x=" << 2 + i*3 << ", y=" << result[i] << endl;
	}
	cout << endl;
}


//����� ��������: ������ ���� �������� �, ��� ������� �=1000/(6*�^2+21) ���� ����� 4
void TaskTwo() 
{
	long x = 0;

	_asm
	{	
	main_loop:

		inc x			; ������������ ��������

		mov EAX, 6
		mul x
		mul x
		add EAX, 21		; EAX = 6 * x ^ 2 + 21

		mov EDI, EAX	; ���������� �������� ��������� �� � EDI, EDI = > 6 * x ^ 2 + 21

		mov EAX, 1000
		div EDI			; EAX = 1000 / (6 * x ^ 2 + 21)

		sub EAX, 4
		add EAX, 0h	
		js end_loop		; ���� EAX < 0, �� ������� js �������� ������� �� ���� end_loop, �� � ������� � �����

		jmp main_loop

	end_loop:
	}
	cout << "task 2: find such x that y=1000/(6*x^2 + 21) is less than 4\n";
	cout << "result: y is less than 4 when x=" << x << "\n\n";

}

//���� ��������: � ���'�� ������� ����� � 9 ��������
//����������� � �������� � ���'�� �������� ������, 
//����� �������� Y = n^2 + n + 4 (��� n �� 1 �� 9)
void TaskThree() 
{
	long n=0, result[9];

	_asm 
	{
		mov ECX, 9					; ����� ������� �������� � ECX
		lea EBX, result				; ����� ������ ������� ������ � EBX

		main_loop:					; ������� ��������� ����� �������

		inc n						; ������������ ��������

		mov EAX, n
		mul n						; EAX = n ^ 2

		mov EDI, EAX
		add EDI, n
		add EDI, 4					; EDI = n ^ 2 + n + 4, �������� ��������

		mov dword ptr[EBX], EDI		; ���������� ���������� �� �������� ������
		add EBX, 4					; ���������� ��������� EBX �� ��������� ������� ������

		loop main_loop				; ����� ��������� ����� �������
	}

	cout << "task 3: find elements of array described with function\n"
		 << "y=n^2 + n + 4 (for n in 1 to 9)\n"
		 << "array: ";
	for (auto res : result) 
	{
		cout << res << " ";
	}
	cout << endl;
}