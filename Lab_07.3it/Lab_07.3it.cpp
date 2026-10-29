#include <iostream>
#include <iomanip>

using namespace std;

// введення з клавіатури значень елементів матриці a (rowCount x colCount)
void Input(int** a, const int rowCount, const int colCount)
{
    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < colCount; j++)
        {
            cout << "a[" << i << "][" << j << "] = ";
            cin >> a[i][j];
        }
        cout << endl;
    }
}

// виводить матрицю a у вигляді таблиці
void Print(int** a, const int rowCount, const int colCount)
{
    cout << endl;
    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < colCount; j++)
            cout << setw(5) << a[i][j];
        cout << endl;
    }
    cout << endl;
}

// перевіряє, чи стовпчик colNo містить хоча б один нульовий елемент
bool ColHasZero(int** a, const int rowCount, const int colNo)
{
    bool hasZero = false;           // ознака наявності нуля у стовпчику
    for (int i = 0; i < rowCount; i++)
        if (a[i][colNo] == 0)
            hasZero = true;
    return hasZero;
}

// 1. int-функція: кількість стовпців, що не містять жодного нульового елементу
int CountColsWithoutZero(int** a, const int rowCount, const int colCount)
{
    int count = 0;
    for (int j = 0; j < colCount; j++)
        if (!ColHasZero(a, rowCount, j))
            count++;
    return count;
}

// характеристика рядка rowNo - сума його додатних парних елементів
int RowCharacteristic(int** a, const int rowNo, const int colCount)
{
    int S = 0;
    for (int j = 0; j < colCount; j++)
        if (a[rowNo][j] > 0 && a[rowNo][j] % 2 == 0)
            S += a[rowNo][j];
    return S;
}

// міняє місцями рядки row1 та row2 (обмін вказівниками на рядки)
void ChangeRows(int** a, const int row1, const int row2)
{
    int* tmp = a[row1];
    a[row1] = a[row2];
    a[row2] = tmp;
}

// 2. void-функція: переставляє рядки матриці відповідно до зростання
// характеристик (метод обміну, "бульбашка")
void SortRowsByCharacteristic(int** a, const int rowCount, const int colCount)
{
    for (int i0 = 0; i0 < rowCount - 1; i0++)
        for (int i1 = 0; i1 < rowCount - i0 - 1; i1++)
            if (RowCharacteristic(a, i1, colCount) >
                RowCharacteristic(a, i1 + 1, colCount))
                ChangeRows(a, i1, i1 + 1);
}

int main()
{
    int rowCount, colCount;     // розмірності матриці (k x n)
    cout << "k = "; cin >> rowCount;
    cout << "n = "; cin >> colCount;
    cout << endl;

    int** a = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        a[i] = new int[colCount];

    Input(a, rowCount, colCount);
    Print(a, rowCount, colCount);

    cout << "1.): "
        << CountColsWithoutZero(a, rowCount, colCount) << endl;

    cout << "   Row characteristics: ";
    for (int i = 0; i < rowCount; i++)
        cout << RowCharacteristic(a, i, colCount) << " ";
    cout << endl;

    SortRowsByCharacteristic(a, rowCount, colCount);
    cout << "2.):" << endl;
    Print(a, rowCount, colCount);

    cout << "   Row characteristics: ";
    for (int i = 0; i < rowCount; i++)
        cout << RowCharacteristic(a, i, colCount) << " ";
    cout << endl;

    for (int i = 0; i < rowCount; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}
