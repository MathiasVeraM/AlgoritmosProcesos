#include <stdio.h>

void PRIORIDAD(int processes[], int burst_time[], int priority[], int arrival_time[], int n) {
    int waiting_time[n], total_waiting_time = 0, total_turnaround_time = 0;

    // Ordenar los procesos por prioridad
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (priority[j] > priority[j + 1]) {
                int temp = arrival_time[j];
                arrival_time[j] = arrival_time[j + 1];
                arrival_time[j + 1] = temp;

                temp = burst_time[j];
                burst_time[j] = burst_time[j + 1];
                burst_time[j + 1] = temp;

                temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;

                temp = priority[j];
                priority[j] = priority[j + 1];
                priority[j + 1] = temp;
            }
        }
    }

    waiting_time[0] = 0;
    for (int i = 1; i < n; i++) {
        waiting_time[i] = burst_time[i - 1] + waiting_time[i - 1] - arrival_time[i];
        total_waiting_time += waiting_time[i];
    }

    printf("Proceso\tTiempo de Llegada\tTiempo de Ejecucion\tPrioridad\tTiempo de Espera\tTiempo de Retorno\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t\t%d\t\t\t%d\t\t\t\t%d\t\t\t\t%d\t\t\t\t%d\n", processes[i], arrival_time[i], burst_time[i], priority[i], waiting_time[i], waiting_time[i] + burst_time[i]);
    }

    printf("Tiempo medio de espera: %.2f\n", (float)total_waiting_time / n);
    printf("Tiempo medio de retorno: %.2f\n", (float)(total_waiting_time + total_turnaround_time) / n);
}

int main() {
    int n;
    printf("Ingrese el numero de procesos: ");
    scanf("%d", &n);

    int processes[n], burst_time[n], priority[n], arrival_time[n];

    for (int i = 0; i < n; i++) {
        printf("Ingrese el tiempo de llegada para el proceso %d: ", i + 1);
        scanf("%d", &arrival_time[i]);
        printf("Ingrese el tiempo de ejecucion para el proceso %d: ", i + 1);
        scanf("%d", &burst_time[i]);
        printf("Ingrese la prioridad para el proceso %d: ", i + 1);
        scanf("%d", &priority[i]);
        processes[i] = i + 1;
    }

    PRIORIDAD(processes, burst_time, priority, arrival_time, n);

    return 0;
}