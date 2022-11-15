#include <iostream>
#include <Windows.h>

using namespace std;

void LR5_Zadanie_1()
{
    cout << "------------------------------------------->ЛР5 №1<-------------------------------------------" << endl;
    float V[8][14];
    int minR = 0, minC=0;
    int maxR = 0, maxC = 0;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 14; j++)
        {
            V[i][j] = rand() % 101-50 + round(((float)rand() / RAND_MAX) * 100) / 100;
            cout << V[i][j] << "\t";
        }
        cout << endl;
    }
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 14; j++)
        {
            if (V[i][j] < V[minR][minC])
            {
                minR = i;
                minC = j;
            }
            if (V[i][j] > V[maxR][maxC])
            {
                maxR = i;
                maxC = j;
            }
        }
    }
    V[maxR][maxC] = V[minR][minC] = 0;
    cout << "Новый массив" << endl;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 14; j++)
            cout << V[i][j] << "\t";
        cout << endl;
    }
}

void LR5_Zadanie_2()
{
    cout << "------------------------------------------->ЛР5 №2<-------------------------------------------" << endl;
    float Z[5][8];
    float tempMin = 9999;
    float sum = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            Z[i][j] = rand() % 101 - 50 + round(((float)rand() / RAND_MAX) * 100) / 100;
            cout << Z[i][j] << "\t";
        }
        cout << endl;
    }
    for (int i = 0; i < 8; i++)
    {
        tempMin = 9999;
        for (int j = 0; j < 4; j++)
        {
            if (Z[j][i] < tempMin)
                tempMin = Z[j][i];
        }
        Z[4][i] = tempMin;
    }
    cout << "Новый массив" << endl;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 8; j++)
            cout << Z[i][j] << "\t";
        cout << endl;
    }
}

void LR5_Zadanie_3()
{
    cout << "------------------------------------------->ЛР5 №3<-------------------------------------------" << endl;
    int array[100][50];
    int n, m;
    cout << "Введите кол-во строк и столбцом через пробел(100, 50): ";
    cin >> n >> m;
    int temparr[5000];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            array[i][j] = rand() % 101 - 50;
            temparr[i * m + j] = array[i][j];
            cout << array[i][j] << "\t";
        }
        cout << endl;
    }
    for (int i = 0; i < m * n;i++)
    {
        for (int b = i + 1; b < m * n; b++)
        {
            if (temparr[i] < temparr[b])
            {
                int temp = temparr[b];
                temparr[b] = temparr[i];
                temparr[i] = temp;
            }
        }
    }
    int id = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            if (j + i <= min(n, m))
                array[i][j] = temparr[id++];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            if (j + i > min(n, m))
                array[i][j] = temparr[id++];
    }
    cout << "Новый массив" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << array[i][j] << "\t";
        cout << endl;
    }
}

void LR6_Zadanie_1()
{
    cout << "------------------------------------------->ЛР6 №1<-------------------------------------------" << endl;
    char array[50];
    cout << "Введите строку: ";
    cin.getline(array, 50);
    int quantityL = 0;
    int quantityR = 0;
    for (int i = 0; i < strlen(array); i++)
    {
        if (array[i] == '(')
            quantityL++;
        else if (array[i] == ')')
            quantityR++;
    }
    if(quantityL > quantityR)
        cout << "Нехватает " << quantityL- quantityR << " )" << endl;
    else if (quantityL < quantityR)
        cout << "Нехватает " << quantityR - quantityL << " (" << endl;
    else
        cout << "Порядок" << endl;
}

void LR6_Zadanie_2()
{
    cout << "------------------------------------------->ЛР6 №2<-------------------------------------------" << endl;
    char array[50];
    bool p = true;
    for (int c = 0; c < 5; c++)
    {
        p = true;
        cout << "Введите строку: ";
        cin.getline(array, 50);
        for (int i = 0; i < strlen(array); i++)
        {
            if (array[i] != array[strlen(array) - i - 1])
            {
                p = false;
                break;
            }   
        }
        if (p)
            cout << "Строка является палиндромом" << endl;
        else 
            cout << "Строка не является палиндромом" << endl;
    }
}

void LR7_Zadanie_1()
{
    cout << "------------------------------------------->ЛР7 №1<-------------------------------------------" << endl;
    int rows = 13;
    int columns = 15;
    int** array = new int* [rows];
    for (int i = 0; i < rows; i++)
    {
        array[i] = new int[columns];
        for (int j = 0; j < columns; j++)
        {
            array[i][j] = rand() % 100;
            cout << array[i][j] << "\t";
        }
        cout << endl;
    }
    int rowNum;
    int colNum;
    cout << "Какую строку удалить? ";
    cin >> rowNum;
    cout << "Какой столбец удалить? ";
    cin >> colNum;
    rows--;
    columns--;
    int** array1 = new int* [rows];

    for (int i = 0; i < rows; i++)
    {
        array1[i] = new int[columns];
        for (int j = 0; j < columns; j++)
        {
            if (i < rowNum - 1)
                if (j < colNum - 1)
                    array1[i][j] = array[i][j];
                else
                    array1[i][j] = array[i][j+1];
            else
                if (j < colNum - 1)
                    array1[i][j] = array[i+1][j];
                else
                    array1[i][j] = array[i + 1][j+1];
        }
    }

    array = array1;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
            cout << array[i][j] << "\t";
        cout << endl;
    }
    for (int i = 0; i < rows;i++)
        delete[] array[i];
    delete[] array;
}

#pragma region ЛР8 1 Задание
double func(int start, int end, double h)
{
    double p = 1;
    double temp;
    for (double i = start; i < end; i += h)
    {
        temp = 4 * sin(i) - cos(7 * i);
        if (temp > 0)
            p *= temp;
    }

    return p;
}

void LR8_Zadanie_1()
{
    cout << "------------------------------------------->ЛР8 №1<-------------------------------------------" << endl;
    double Y1 = func(13, 20, 0.2);
    double Y2 = func(-1, 5, 0.25);
    double Y3 = func(3, 8, 0.1);
    double min = min(min(Y1, Y2), Y3);
    if (min == Y1) cout << "При значениях [13,20] h = 0.2";
    if (min == Y2) cout << "При значениях [-1,5] h = 0.25";
    if (min == Y3) cout << "При значениях [3,8] h = 0.1";
    cout << endl;
}
#pragma endregion

#pragma region ЛР8 2 Задание
int* GetMassive(int n)
{
    int* array = new int[n];

    for (int i = 0; i < n; i++)
        array[i] = rand() % 41 - 20;

    return array;
}

void ShowMassive(int array[], int n)
{
    for (int i = 0; i < n; i++)
        cout << array[i] << " ";
    cout << endl;
}

double* GetPozitiveProcent(int array[], int n)
{
    double poz = 0, neg=0;
    for (int i = 0; i < n; i++)
    {
        if (array[i] > 0) poz++;
        if (array[i] < 0) neg++;
    }

    return new double[2] { poz / n * 100, neg / n * 100};
}

void LR8_Zadanie_2()
{
    cout << "------------------------------------------->ЛР8 №2<-------------------------------------------" << endl;
    int n1 = 20, n2=30;
    int* U1 = GetMassive(n1);
    int* U2 = GetMassive(n2);
    ShowMassive(U1, n1);
    double* result = GetPozitiveProcent(U1, n1);
    cout << "Положительных: " << result[0] << "%, Отрицательных: " << result[1] << "%" << endl;
    ShowMassive(U2, n2);
    result = GetPozitiveProcent(U2, n2);
    cout << "Положительных: " << result[0] << "%, Отрицательных: " << result[1] << "%" << endl;
    delete[] U1;
    delete[] U2;
}
#pragma endregion


int main()
{
    srand(time(NULL));
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Rus");
    while (true)
    {
        int n;
        cout << "----------------------------------------------------------------------------------------------" << endl;
        cout << "Номер лабораторки: ";
        cin >> n;
        switch (n)
        {
        case(5):
            LR5_Zadanie_1();
            LR5_Zadanie_2();
            LR5_Zadanie_3();
            break;
        case(6):
            LR6_Zadanie_1();
            LR6_Zadanie_2();
            break;
        case(7):
            LR7_Zadanie_1();
            break;
        case(8):
            LR8_Zadanie_1();
            LR8_Zadanie_2();
            break;
        default:
            break;
        }
    }
}
