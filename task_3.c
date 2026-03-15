#include <stdio.h>
#include <string.h>

int main() {
    char str[256];           
    char compressed[512];    
    int i, j, pos;
    int len;

   
    printf("Введите строку из латинских букв: ");
    fgets(str, sizeof(str), stdin);
    
    // Удаляем символ перевода строки, если есть
    len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
        len--;  // обновляем длину
    }

    // Если строка пустая
    if (len == 0) {
        printf("Строка пуста.\n");
        return 0;
    }

    // Сжатие
    pos = 0;   
    for (i = 0; i < len; ) {
        char current_char = str[i];
        int count = 1;
        
        // Считаем повторения
        while (i + count < len && str[i + count] == current_char) {
            count++;
        }
        
        // Записываем символ
        compressed[pos++] = current_char;
        
        // Временный буфер для числа
        char num_buf[12];  // достаточно для многозначного числа
        sprintf(num_buf, "%d", count);
        for (j = 0; num_buf[j] != '\0'; j++) {
            compressed[pos++] = num_buf[j];
        }
        
        i += count;  // переходим к следующей группе символов
    }
    compressed[pos] = '\0';  // завершаем строку

    // Сравниваем длины
    int compressed_len = strlen(compressed);
    if (compressed_len > len) {
        printf("Результат: %s\n", str);
    } else {
        printf("Результат: %s\n", compressed);
    }

    return 0;
}
