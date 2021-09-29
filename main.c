#include <stdio.h>

int main() {
    system("chcp 65001");
    int n, m, flag, i, j, z, all_numbers_z, number_z, k;
    printf("Лабоарторная работа №2\n");
    printf("Задание 1\n");
    do{
        printf("Введите n и m \n");
        k = scanf("%d %d", &n, &m);
        while(getchar()!='\n');
    }while (!((n > 0) && (n < 200) && (m > 0) && (m < 200)) || (k!=2));
    printf("Вводите массив построчно\n");
    int mas[n+1][m];
    for(j=0;j<m;j++){
        mas[n][j] = 0;
    }
    for(i = 0; i < n; i++){
        do {
            k = 0;
            for (int j = 0; j < m; j++) {
                k += scanf("%d", &mas[i][j]);
            }
            while(getchar()!='\n');
        } while (k != m);
    }
    printf("\n");
    printf("Введённый массив:\n");
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            printf("%d ", mas[i][j]);
        }
        printf("\n");
    }
    i = 0, j = 0, flag= 0;
    while (i != n){
        for(j=0; j < m; j++){
            if (mas[i][j] % 2 != 0){
                flag = 1;
            }
        }
        if (flag == 0){
            for (j = 0; j < m; j ++){
                for (int c = i; c < n; c++){
                    mas[c][j] = mas[c+1][j];
                }
            }
            n -= 1;
        } else{
            i ++;
            flag = 0;
        }
    }
    printf("\n");
    printf("Новый массив:\n");
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            printf("%d ", mas[i][j]);
        }
        printf("\n");
    }
    printf("\nЗадание 2\n");

    do{
        printf("Введите длинну массива\n");
        k = scanf("%d", &n);
        while(getchar()!='\n');
    } while (k != 1);

    int massive[n];
    do {
        printf("Введите массив\n");
        k = 0;
        for(i = 0; i < n; i++){
            k += scanf("%d", &massive[i]);
        }
        while(getchar()!='\n');
    } while (k != n);
    do {
        printf("Введите Z\n");
        k = scanf("%d", &z);
        while(getchar()!='\n');
    } while ((k != 1) && (z < 10) && (z > -1));
    int new_mas[10000];
    int numbers = 0;
    all_numbers_z = 0;
    for(i = 0; i < n; i++){
        int k = massive[i];
        number_z = 0;
        while (k > 0){
            if (z == k % 10){
                number_z += 1;
            }
            k /= 10;
        }
        if (number_z > 0){
            all_numbers_z += number_z;
            new_mas[numbers] = massive[i];
            numbers ++;
        }
    }
    printf("Количество встречаемых цифр %d : %d\n", z, all_numbers_z);
    printf("Новый массив\n");
    for(i =0; i < numbers; i++) {
    printf("%d ", new_mas[i]);
    }
}
