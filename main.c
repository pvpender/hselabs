#include <stdio.h>

int main() {
    system("chcp 65001");
    int n, m, flag, i, j, z, all_numbers_z, number_z;
    printf("Задание 1\n");
    printf("Введите n и m \n");
    scanf("%d %d", &n, &m);
    while (!((n > 0) && (n < 200) && (m > 0) && (m < 200))){
        printf("Введите n и m \n");
        scanf("%d %d", &n, &m);
    }
    printf("Вводите массив построчно\n");
    int mas[n+1][m];
    for(j=0;j<m;j++){
        mas[n][j] = 0;
    }
    for(i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d", &mas[i][j]);
        }
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
                    mas[i][j] = mas[i+1][j];
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
    printf("Задание 2\n");
    printf("Введите длинну массива\n");
    scanf("%d", &n);
    printf("Введите массив\n");
    int massive[n];
    for(i = 0; i < n; i++){
        scanf("%d", &massive[i]);
    }
    printf("Введите Z\n");
    scanf("%d", &z);
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
