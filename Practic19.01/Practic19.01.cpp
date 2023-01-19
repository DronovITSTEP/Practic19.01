#include <iostream>

using namespace std;

/*
В одномерном массиве, состоящем из N вещественных
чисел вычислить:
■ Сумму отрицательных элементов.
■ Произведение элементов, находящихся между min и max
элементами.
■ Произведение элементов с четными номерами.
■ Сумму элементов, находящихся между первым и последним 
отрицательными элементами.
*/
int N = 0;

double* createArr() {
	cout << "Введите размер массива: "; cin >> N;
	double* arr = new double[N];
	for (int i = 0; i < N; i++) {
		arr[i] = (double)(rand() % 100) / 10;
		arr[i] = (rand() % 2) ? -arr[i] : arr[i];
		cout << arr[i] << " ";
	}
	return arr;
}
void sumNegative(double* arr) {
	double sum = .0;
	for (int i = 0; i < N; i++) {
		if (arr[i] < 0) sum += arr[i];
	}
	cout << "Сумма отрицательных чисел = " << sum << endl;
}
void multBetweenMaxMin(double* arr) {
	double mult = 1;
	int max_index = 0, min_index = 0;
	for (int i = 1; i < N; i++) {
		if (arr[max_index] < arr[i]) max_index = i;
		if (arr[min_index] > arr[i]) min_index = i;
	}
	for (int i = min(max_index, min_index); i <= max(max_index, min_index); i++) {
		mult *= arr[i];
	}
	cout << "Произведение между min и max элементами = " << mult << endl;
}
void multEvenIndex(double* arr) {
	double mult = 1;
	/*for (int i = 0; i < N; i++) {
		if (i % 2 == 0) mult *= arr[i];
	}*/
	for (int i = 0; i < N; i += 2) {
		mult *= arr[i];
	}
	cout << "Произведение элементов с четными номерами = " << mult << endl;
}
void sumPositiveIndex(double* arr) {
	int min_index, max_index, sum = .0;
	for (int i = 0; i < N; i++) {
		if (arr[i] < 0) {
			min_index = i;
			break;
		}
	}
	for (int i = N-1; i >= 0; i--) {
		if (arr[i] < 0) {
			max_index = i;
			break;
		}
	}
	for (int i = min_index + 1; i < max_index; i++) {
		sum += arr[i];
	}
	cout << "Сумму элементов, находящихся между первым и последним"
		<< " отрицательными элементами = " << sum << endl;
}

/*
Создайте приложение Калькулятор. Нужно
поддерживать операции +, –, *, /.
Реализовать меню без использования операторов if
и switch при помощи массива указателей на функции.
*/

double add(double a, double b) {
	return a + b;
}
double sub(double a, double b) {
	return a - b;
}
double mult(double a, double b) {
	return a * b;
}
double div(double a, double b) {
	if (b != 0)
		return a / b;
}

void operation(double(*op)(double, double), double a, double b) {
	cout << op(a, b) << endl;
}

/*
Написать программу, которая содержит функцию, 
принимающую в качестве аргумента, указатели
на три массива и размер массивов, Заносит в массив
C суммы элементов массивов А и В. Размер массивов
одинаковый.
*/
void sumArr(int* A, int* B, int* &C, int s) {
	C = new int[s];
	for (int i = 0; i < s; i++) {
		*(C + i) = *(A + i) + *(B + i);
	}
}

int main()
{
	setlocale(LC_ALL, "");
	/*double* arr = createArr();
	cout << endl;
	sumNegative(arr);
	multBetweenMaxMin(arr);
	multEvenIndex(arr);
	sumPositiveIndex(arr);*/

	/*cout << "Введите значения a и b\n";
	double a, b;
	cin >> a >> b;
	while (1) {
		cout << "1 - сложение\n"
			<< "2 - разность\n"
			<< "3 - умножение\n"
			<< "4 - деление\n";

		double(*choice[4])(double, double) { add, sub, mult, div };
		int n; cin >> n;
		operation(choice[n-1], a, b);
	}*/
	int s = 5;
	int* A = new int[s] {5, 6, 9, 7, 8};
	int* B = new int[s] {3, 2, 1, 4, 5};
	int* C = nullptr;
	sumArr(A, B, C, s);

	for (int i = 0; i < s; i++) {
		cout << C[i] << " ";
	}


}
