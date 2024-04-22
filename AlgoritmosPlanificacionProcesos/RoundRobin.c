#include <stdio.h>
#include <conio.h>

int main(){
    int i, NOP, sum = 0, count=0, y, quant, wt=0, tat=0, at[10], bt[10], temp[10];
    float avg_wt, avg_tat;
    printf("Ingrese el numero de procesos: ");
    scanf("%d", &NOP);
    y = NOP;

    for(i = 0; i<NOP; i++){
        printf("Ingrese el tiempo de llegada y tiempo de ejecucion del proceso [#%d]\n", i+1);
        printf("El tiempo de llegada es: \t");
        scanf("%d", &at[i]);
        printf("El tiempo de ejecucion es: \t");
        scanf("%d", &bt[i]);
        temp[i] = bt[i];
    }

    printf("Ingrese el Quantum del proceso: \t");
    scanf("%d", &quant);
    printf("\n Proceso \t\t Tiempo de ejecucion \t\t Tiempo de retorno \t\t Tiempo de espera ");

    for(sum=0, i=0; y!=0; ){
        if(temp[i] <= quant && temp[i]>0){
            sum = sum + temp[i];
            temp[i] = 0;
            count = 1;
        } else if(temp[i]>0){
            temp[i] = temp[i] - quant;
            sum = sum + quant;
        } 
        if(temp[i] == 0 && count == 1){
            y--;
            printf("\nProceso #[%d] \t\t %d\t\t\t\t %d\t\t\t %d", i+1, bt[i], sum-at[1], sum-at[i]-bt[i]);
            wt = wt + sum-at[i]-bt[i];
            tat = tat + sum-at[1];
            count = 0;
        }
        if(i==NOP-1){
            i=0;
        }else if(at[i+1]<=sum){
            i++;
        }else{
            i=0;
        }
    }

    avg_wt = wt * 1.0/NOP;
    avg_tat = tat * 1.0/NOP;
    printf("\n Tiempo medio de espera: \t%f", avg_wt);
    printf("\n Tiempo medio de respuesta: \t%f", avg_tat);
    getch();

    return 0;
}