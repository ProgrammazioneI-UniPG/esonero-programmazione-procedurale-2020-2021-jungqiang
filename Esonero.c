#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


int main() //menù
{
int selezione ;
char messaggio[128];
printf("Digita 1 per criptare il messaggio con una propria chiave,\n");
printf("altrimenti si utilizza una chiave generata automaticamente\n");

scanf("%d", &selezione);

while(getchar() != '\n');//pezzo di codice che mi risolve il problema dei doppi fgets

if (selezione==1){ //funzione 1
char chiave[128];
char codice[128];
char decifratura[128];

printf("inserisci il messaggio (massimo 127 caratteri):\n");
fgets(messaggio,128,stdin);
printf("inserisci la chiave (la chiave deve avere la stessa lunghezza del messaggio):\n");
fgets(chiave,128,stdin);

while(strlen(chiave)!=strlen(messaggio)){
  printf("chiave non valida, reinserisci:\n");
  fgets(chiave,128,stdin);
}
printf("il codice in esadecimale è:\n");
for(int i=0;i<strlen(messaggio)-1;i++){
codice[i]=(chiave[i]^messaggio[i]);
decifratura[i]=(chiave[i]^codice[i]);
printf("%X ",codice[i]);
}
printf("\nil codice è (se leggibile dovrebbe comparire qualcosa):\n%s\n",codice);
printf("mentre il codice decifrato è:\n%s\n",decifratura);//per vedere se lo XOR è andato bene o meno

}

else{ //funzione 2
char messaggio[128];
char chiave[128];
char codice[128];
char decifratura[128];

printf("inserisci il messaggio (massimo 127 caratteri):\n");
fgets(messaggio,128,stdin);

time_t t;//generatore di chiave
srand((unsigned) time(&t));
for (int i=0; i<strlen(messaggio)-1;i++){
chiave[i]= (rand() % 94)+33;//l'ASCII va da 33 a 126 compresi per preferenza personale
}

printf("la chiave generata è:\n%s\n",chiave);//inizio copia incolla
printf("il codice in esadecimale è:\n");
for(int i=0;i<strlen(messaggio)-1;i++){
codice[i]=(chiave[i]^messaggio[i]);
decifratura[i]=(chiave[i]^codice[i]);
printf("%X ",codice[i]);
}
printf("\nil codice è (se leggibile dovrebbe comparire qualcosa):\n%s\n",codice);
printf("mentre il codice decifrato è:\n%s\n",decifratura);
}

return 0;
}
