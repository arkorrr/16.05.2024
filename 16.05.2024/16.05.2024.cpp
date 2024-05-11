//Написать аналогичную программу(см.ниже) для пузырьковой сортировки.
//Третим параметром в функции сортировки обязательно должен быть указатель на функцию.

#include <iostream>
using namespace std;


bool ascending(int a, int b)
{
    return a > b;     // возвращает «истину»,
    // если первый элемент
    // оказывается больше второго
}



bool descending(int a, int b) // функция для сортировки 
{                        // по убыванию
    return a < b;
}

void SelectionSort(int* array, int size, bool (*comparisonFcn)(int, int))
{
    for (int startIndex = 0; startIndex < size; ++startIndex) // Перебираем                                   // каждый элемент массива
    { // smallestIndex - это индекс наименьшего элемента,
      // который мы обнаружили до этого момента
        int smallestIndex = startIndex;
        // Ищем наименьший элемент среди оставшихся в массиве (начинаем со startIndex+1)
        for (int currentIndex = startIndex + 1; currentIndex < size; ++currentIndex)
        {
            // Если текущий элемент меньше нашего предыдущего найденного наименьшего элемента
            if (comparisonFcn(array[smallestIndex], array[currentIndex])) // СРАВНЕНИЕ
                smallestIndex = currentIndex;        // то это наш новый                             // наименьший элемент в этой итерации
        }
        // Меняем местами наш стартовый элемент с найденным наименьшим элементом
        swap(array[startIndex], array[smallestIndex]);
    }
}

void BubbleSort(int* array, int size, bool (*comparisonFcn)(int, int))
{
    int buffer;
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1; j++)
        {
            if (comparisonFcn(array[j], array[j + 1]))
            {
                buffer = array[j];
                array[j] = array[j + 1];
                array[j + 1] = buffer;
            }
        }
    }
}

void printArray(int* array, int size)
{
    for (int index = 0; index < size; ++index)
        cout << array[index] << " ";
    cout << '\n';
}

int main()
{
    int array[8] = { 4, 8, 5, 6, 2, 3, 1, 7 };
    BubbleSort(array, 8, descending); // сортируем массив 
    printArray(array, 8);   // выводим массив на экран
}