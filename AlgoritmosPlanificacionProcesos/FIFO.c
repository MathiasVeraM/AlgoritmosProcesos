#include <stdio.h>

void FIFO(int processes[], int burst_time[], int arrival_time[], int n) {
    int waiting_time[n], total_waiting_time = 0, total_turnaround_time = 0;

    waiting_time[0] = 0;
    printf("Proceso\tTiempo de Llegada\tTiempo de Ejecucion\tTiempo de Espera\tTiempo de Retorno\n");
    for (int i = 1; i < n; i++) {
        waiting_time[i] = burst_time[i - 1] + waiting_time[i - 1] - arrival_time[i];
        total_waiting_time += waiting_time[i];
    }

    for (int i = 0; i < n; i++) {
        printf("%d\t\t\t%d\t\t\t%d\t\t\t\t%d\t\t\t\t%d\n", processes[i], arrival_time[i], burst_time[i], waiting_time[i], waiting_time[i] + burst_time[i]);
        total_turnaround_time += waiting_time[i] + burst_time[i];
    }

    printf("Tiempo medio de espera: %.2f\n", (float)total_waiting_time / n);
    printf("Tiempo medio de retorno: %.2f\n", (float)total_turnaround_time / n);
}

int main() {
    int n;
    printf("Ingrese el numero de procesos: ");
    scanf("%d", &n);

    int processes[n], burst_time[n], arrival_time[n];

    for (int i = 0; i < n; i++) {
        printf("Ingrese el tiempo de llegada para el proceso %d: ", i + 1);
        scanf("%d", &arrival_time[i]);
        printf("Ingrese el tiempo de ejecucion para el proceso %d: ", i + 1);
        scanf("%d", &burst_time[i]);
        processes[i] = i + 1;
    }

    FIFO(processes, burst_time, arrival_time, n);

    return 0;
}