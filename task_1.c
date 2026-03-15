#include <stdio.h>
#include <string.h>
#include <ctype.h>  

int get_roman_value(char ch) {
    switch (ch) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return -1;   
    }
}

int main() {
    char roman[100];      // Ввод римского числа
    int values[100];      // Храним значение римского числа
    int result = 0;       // Преобразования
    int i, length;
    int valid = 1;        // Корректный ввод
    
    // Ввод римского числа
    printf("Введите римское число: ");
    scanf("%s", roman);
    
    // Делаем регистр одинаковым
    for (i = 0; roman[i] != '\0'; i++) {
        roman[i] = toupper(roman[i]);
    }
    
    length = strlen(roman);
    
    // Проверяем значения и заполняем массив values
    for (i = 0; i < length; i++) {
        int val = get_roman_value(roman[i]);
        if (val == -1) {
            valid = 0;  // Не корректный ввод
            break;
        }
        values[i] = val;
    }
    
    // Сообщение об ошибке
    if (!valid) {
        printf("Ошибка: введены недопустимые символы!\n");
        printf("Допустимы только: I, V, X, L, C, D, M\n");
        return 1;
    }
    
    // Переводим
    for (i = 0; i < length; i++) {
        if (i < length - 1) {
            // Если текущее значение меньше следующего, вычитаем его
            if (values[i] < values[i + 1]) {
                result -= values[i];
            } 
            // Иначе прибавляем
            else {
                result += values[i];
            }
        } 
        // Для последнего символа всегда прибавляем
        else {
            result += values[i];
        }
    }
    
    // Выводим результат
    printf("Римское число: %s\n", roman);
    printf("Арабское число: %d\n", result);
    
    return 0;
}
