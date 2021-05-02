// S006_Mikhaylova.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

int main()
{
	char string[255];
	char findStr[255];

	char f[] = "%s";
	char fd[] = "%d\n";

	char outFirstString[256] = "Enter your main string: ";
	char outSecondString[256] = "Enter your find string: ";
	char outPut[256] = "Result is ";


	__asm {

		lea edx, outFirstString
		push edx

		lea ecx, f
		push ecx

		call printf
		add esp, 8


		lea eax, string
		push eax

		lea ecx, f
		push ecx

		call scanf
		add esp, 8


		lea edx, outSecondString
		push edx

		lea ecx, f
		push ecx

		call printf
		add esp, 8


		lea eax, findStr
		push eax

		lea ecx, f
		push ecx

		call scanf
		add esp, 8


		lea edx, outPut
		push edx

		lea ecx, f
		push ecx

		call printf
		add esp, 8


		lea eax, string
		dec eax

		mov ecx, 0
		dec ecx

		Count :
		inc eax
			inc ecx
			cmp[eax], 0
			jnz Count

			lea ebx, findStr
			dec ebx

			mov edx, 0
			dec edx


			CountSub :
		inc ebx
			inc edx
			cmp[ebx], 0
			jnz CountSub


			push edx
			cmp edx, ecx
			jg NoMatch
			cmp edx, 0
			jz NoMatch

			dec eax
			dec ebx

			Cycle :

		cmp edx, 0
			jz OutPutResult
			cmp ecx, 0

			jz NoMatch
			push ecx

			mov ch, [eax]
			mov cl, [ebx]

			cmp ch, cl
			pop ecx

			jz skip
			pop edx

			lea ebx, findStr
			add ebx, edx

			push edx
			dec ebx

			push ecx
			mov ch, [eax]
			mov cl, [ebx]
			cmp ch, cl
			pop ecx
			jz skip
			dec eax
			dec ecx
			jmp Cycle


			skip :
		dec eax
			dec ebx
			dec ecx
			dec edx
			jmp Cycle

			NoMatch :

		mov ecx, -1
			OutPutResult :
			push ecx

			lea ecx, fd
			push ecx

			call printf
			add esp, 12
	}
}


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
