#include<stdio.h>
#include<math.h>
#define lmax 99999
int main(){
    system("chcp 65001");
    float mas[100000];
    int n, i, j,  flag, first_min_index, last_positive_index, min_border, max_border, last_negative_index;
    float first_min, a, x, h, average = 0;
    printf("Лабароторная работа №1\n");
    printf("Задание 1\n");
    flag = 0;
    while (flag != 1){
        printf("Введите длину массива от 1 до %d\n", lmax);
        scanf("%d", &n);
        if ((n < lmax + 1) && (n >= 1)){
            flag = 1;
        }
    }
    printf("Введите a x h через пробел в одну строку\n");
    scanf("%f %f %f", &a, &x, &h);
    for (i=1; i <= n; i++){
        mas[i] = 6 * cos((a * x + i * h));
    }
    printf("R = {");
    for(i = 1; i <= n; i++){
        printf("%f ; ", mas[i]);
    }
    printf("} \n");
    printf("Задание 2 \n");
    flag = 0;
    for (i = 1; i <= n; i++){
        if (mas[i] > 0){
            last_positive_index = i;
            flag = 1;
        }
    }
    if (flag != 1){
        printf("Нет положительного элемента\n");
    }
    else{
        first_min = 99999;
        for (i=1; i<=n; i++){
            if (mas[i] < first_min){
                first_min = mas[i];
                first_min_index = i;
            }
        }
        if (abs(last_positive_index - first_min_index) < 2){
            printf("Элементы расположены рядом или совпадают\n");
        }
        else{

            min_border = (first_min_index < last_positive_index) ? first_min_index:last_positive_index;
            max_border = (first_min_index < last_positive_index) ? last_positive_index:first_min_index;
            i = min_border + 1;
            while(i != max_border){
                if (mas[i] < 0){
                    for(j = i; j <= n; j ++){
                        mas[j] = mas[j + 1];
                    }
                    n --;
                    max_border --;
                }    
                else{
                    i ++;
                }
            }   
            printf("R = {");
            for (i = 1; i <= n; i++){
                printf("%f ; ", mas[i]);
            }
            printf("} \n");
        }
    }
    printf("Задание 3 \n");
    flag = 0;
    for(i = 1; i <= n; i ++){
        if (mas[i] < 0){
            last_negative_index = i;
            flag = 1;
        }
    }
    if (flag != 1){
        printf("Нет отрицательного числа, невозможно посчитать среднее");
    }
    else{
        first_min = 99999;
        for (i = 1; i <=n; i++){
            if (first_min > fabsf(mas[i])){
                first_min = fabsf(mas[i]);
                first_min_index = i;
            }
        }
        if (abs(last_negative_index - first_min_index) < 2){
            printf("Нет среднего");
        }
        else{
            min_border = (last_negative_index < first_min_index) ? last_negative_index : first_min_index;
            max_border = (last_negative_index < first_min_index) ? first_min_index : last_negative_index;
            for (i = min_border + 1; i < max_border; i ++){
                average += mas[i];
            }
            average /= (max_border - min_border - 1);
            printf("Среднее равно: %f", average);
        }
    }
}
