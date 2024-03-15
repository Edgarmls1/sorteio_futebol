#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void sort(int array[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (array[j] > array[j+1]) {
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}

//printa os minutos em que os gols aconteceram
void printArray(int array[], int n) {
    for (int i = 0; i < n; i++) {
        printf("(%d)", array[i]);
    }
}

int main(){
    int golcasa = 0, golfora = 0, tempo = 0, area;
    int tmpgc[100], tmpgf[100];
    char timecasa[100], timefora[100];

    printf("Qual o times da casa? ");
    fgets(timecasa, 100, stdin);

    printf("Qual o time vizitante? ");
    fgets(timefora, 100, stdin);

    srand(time(NULL));

    //divide o campo em 20 partes, entao sorteia uma delas; caso seja 0 ou 1, gol do time da casa, caso seja 19 ou 20, gol do time visitante
    //a divisao dos 90 minutos foi testada varias vezes, 18 foi o que gerou resultados mais "realistas"
    do{
        tempo++;

        area = rand() % 21;

        if(area == 0 || area == 1){
            tmpgc[golcasa] = rand() % 91;
            golcasa++;
        }else if(area == 19 || area == 20){
            tmpgf[golfora] = rand() % 91;
            golfora++;
        }
    }while(tempo <= 18);

    sort(tmpgc, golcasa);
    sort(tmpgf, golfora);

    //determina se o jogo terminou empatado ou se teve vencedor
    if(golcasa > golfora){
        printf("\n");
        printf("vitoria do %s", timecasa);
    }else if(golfora > golcasa){
        printf("\n");
        printf("vitoria do %s", timefora);
    }else{
        printf("\n");
        printf("empate");
    }

    printf("\n");


    // exibiçao do placar
    timecasa[strcspn(timecasa, "\n")] = 0;
    printf("%s ", timecasa);
    printf("%d", golcasa);
    

    printf(" x ");

    printf("%d", golfora);
    
    printf(" %s", timefora);
    
    printArray(tmpgc, golcasa);
    
    if(golcasa == 0){
        for(int x = 0; x <= strlen(timecasa); x++){
            printf(" ");
        }
        printf("      ");
    }else if(golfora == 0){
        printf(" ");
    }else{
        printf(" || ");
    }
    
    printArray(tmpgf, golfora);

    return 0;
}
