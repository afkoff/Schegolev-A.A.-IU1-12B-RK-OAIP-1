#include <iostream>
#include <cstring>


using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
    int size;
    int sum = 0;
    cout << "Введите количество товаров: ";
    cin >> size;

    char** name = new char*[size];
    int* kol = new int[size];
    int* price = new int[size];

    cin.ignore();

    for (int i = 0; i < size; i++)
    {
        cout << "Введите название товара " << i + 1 << ": ";
        char buffer[100];
        cin.getline(buffer, 100);
        name[i] = new char[strlen(buffer) + 1];
        strcpy(name[i], buffer);

        cout << "Введите количство единиц товара " << i + 1 << ": ";
        cin >> kol[i];

        cout << "Введите цену за единицу товара" << i + 1 << ": ";
        cin >> price[i];


        sum += kol[i] * price[i];
        cout << "Общая стоимость данной позиции: " << kol[i] * price[i] << endl;
        cin.ignore();
    }

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; ++j)
        {
            if (strcmp(name[j], name[j + 1]) > 0)
            {
                swap(name[j], name[j + 1]);
                swap(kol[j], kol[j + 1]);
                swap(price[j], price[j + 1]);
            }
        }
    }

    for (int i = 0; i < size; ++i)
    {
        cout << name[i] << " - " << "Количество: " << kol[i] << ", Цена за единицу: " << price[i] << endl;
    }
    cout << "Общая сумма всех заказов: " << sum << endl;
    for (int i = 0; i < size; ++i)
    {
        delete[] name[i];
    }
    delete[] name;
    delete[] kol;
    delete[] price;

    return 0;
}
