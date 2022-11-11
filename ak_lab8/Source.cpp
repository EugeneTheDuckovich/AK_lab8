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

//перше завдання: знайти 6 значень функції y=(2500*x - 8)/(3*x^2 + 20)
//х знінюється від 2 із кроком 3
void TaskOne() 
{
	long x = 2;
	long result[6];

	__asm
	{
		lea EBX, result				; завантаження адреси початку масиву результатів в EBX

		mov ECX, 6					; встановлюємо значення лічильника кількості ітерацій

	main_loop :						; початок основного циклу програми

		mov EAX, 3					; EAX = x
		mul x
		mul x
		add EAX, 20					; EAX = 3 * x ^ 2 + 20

		mov EDI, EAX				; переміщуємо поточний результат в EDI, EDI = 3 * x ^ 2 + 20

		mov EAX, 2500
		mul x
		sub EAX, 8					; EAX = 2500 * x - 8

		div EDI						; EAX = (2500x - 8) / (3 * x ^ 2 + 20)

		mov dword ptr[EBX], EAX		; переміщення кінцевого результату у відповідний елемент масиву результатів
		add EBX, 4					; збільшення значення EBX, що ми використовуємо як покажчик на поточний елемент масиву
		add x, 3					; зміна ааргументу із шагом 3

		loop main_loop				; кінець основного циклу програми

	}
	cout << "task 1: find six values of y=(2500*x - 8)/(3*x^2 + 20)\n"
		 << "x is starting with 2 and step is equel to 3\n";
	for (int i = 0; i < 6; ++i) {
		cout << "x=" << 2 + i*3 << ", y=" << result[i] << endl;
	}
	cout << endl;
}


//друге завдання: знайти таке значення х, при котрому у=1000/(6*х^2+21) буде менше 4
void TaskTwo() 
{
	long x = 0;

	_asm
	{	
	main_loop:

		inc x			; інкрементуємо аргумент

		mov EAX, 6
		mul x
		mul x
		add EAX, 21		; EAX = 6 * x ^ 2 + 21

		mov EDI, EAX	; пересилаємо поточний результат до б EDI, EDI = > 6 * x ^ 2 + 21

		mov EAX, 1000
		div EDI			; EAX = 1000 / (6 * x ^ 2 + 21)

		sub EAX, 4
		add EAX, 0h	
		js end_loop		; якщо EAX < 0, то команда js здійснить перехід до мітки end_loop, що є виходом з циклу

		jmp main_loop

	end_loop:
	}
	cout << "task 2: find such x that y=1000/(6*x^2 + 21) is less than 4\n";
	cout << "result: y is less than 4 when x=" << x << "\n\n";

}

//третє завдання: У пам'яті заданий масив з 9 елементів
//розрахувати і зберегти в пам'яті елементи масиву, 
//задані функцією Y = n^2 + n + 4 (для n від 1 до 9)
void TaskThree() 
{
	long n=0, result[9];

	_asm 
	{
		mov ECX, 9					; запис кількості ітерацій в ECX
		lea EBX, result				; запис адреси початку масива в EBX

		main_loop:					; початок основного циклу функції

		inc n						; інкрементуємо аргумент

		mov EAX, n
		mul n						; EAX = n ^ 2

		mov EDI, EAX
		add EDI, n
		add EDI, 4					; EDI = n ^ 2 + n + 4, фінальне значення

		mov dword ptr[EBX], EDI		; переміщення результату до елементу масиву
		add EBX, 4					; переміщення покажчика EBX на наступний елемент масиву

		loop main_loop				; кінець соновного циклу функції
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