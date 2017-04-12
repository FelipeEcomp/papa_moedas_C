#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    
int menu, tabuleiro, retorno, jogador=1, i=0, j=0, i_marcacao=0, j_marcacao=0, i_jogada1=0, j_jogada1=0, i_jogada2=0, j_jogada2=0;
int pontuacao_j1=0, pontuacao_j2=0, pontuacao_atual=0, tam, jogadasj1=0, jogadasj2=0, i_anterior1=0, j_anterior1=0;
int i_anterior2=0, j_anterior2=0, pont_minima, linha=0, coluna=0, teste=0, tam2, linha2, coluna2, count=0;
char matriz5_gabarito[10][10],matriz5_gabarito2[10][10], matriz5_marcacao[10][10], matriz5_marcacao_j2[10][10];


do {//RETORNO DO MENU INSTRUÇOES DO JOGO
do {
system("cls");
printf ("\t\t\t²²²²²²²²²²²²²²²²²²²²²²²²²²²\n");
printf ("\t\t\t²²      PAPA-MOEDAS      ²²\n");
printf ("\t\t\t²²²²²²²²²²²²²²²²²²²²²²²²²²²\n\n\n");

// =========================MENU===============================

    pontuacao_j1=0;
    pontuacao_j2=0;
    pontuacao_atual=0;
printf ("BEM VINDOS AO JOGO PAPA-MOEDAS\n");
printf ("[1] JOGAR\n");
printf ("[2] INSTRUCOES\n");
printf ("[3] SAIR\n");
scanf ("%d", &menu);
system("cls");
}while (menu>3); //CASO ESCOLHA UMA OPÇAO QUE NAO FAZ PARTE DO MENU



//========================== ESCOLHA DO TAMANHO DO TABULEIRO ==============================================
switch(menu) {
             
       case 1: //JOGO
       system("cls");
            printf ("ESCOLHA O TAMANHO DO TABULEIRO\n\n");
            printf ("[1] TABULEIRO 5X5 = 20 PONTOS\n"); 
            printf ("[2] TABULEIRO 7X7 = 35 PONTOS\n");
            printf ("[3] TABULEIRO 10X10 = 50 PONTOS\n");
            scanf("%d", &tabuleiro);
                        
            
            if (tabuleiro==1) {
                              tam =4;
                              pont_minima=20;
                              }
            if (tabuleiro==2){
                              tam =6;
                              pont_minima=35;}    
            if (tabuleiro==3) {
                              tam =9;
                              pont_minima=50;}
          
// ===========================TABULEIROS=====================
 /*SETEI AS MATRIZES GABARITOS COM O CARACTER ' ' POIS SEU VALOR EH ZERO, E CASO NÃO SEJA ESCOLHIDA A MATRIZ DE MAIOR TAMANHO
         E O JOGADOR ESCOLHA UMA POSIÇÃO FORA DESSA MATRIZ, PODERÁ VIR UM LIXO INDESEJÁVEL*/
for (i=0;i<=10;i++) {
    for (j=0;j<=10;j++) {
        matriz5_gabarito[i][j]=' ';        
        }}
for (i=0;i<=10;i++) {
    for (j=0;j<=10;j++) {
        matriz5_gabarito2[i][j]=' ';              
        }}

//-----------------MATRIZ GABARITO 1 COM SRAND------------------
for (i=0;i<=tam;i++) {
    for (j=0;j<=tam;j++) {
        matriz5_gabarito[i][j]=' ';        
        }}
        
    srand(time(NULL));
    do{
                      linha=rand()%((tam+1));
                      coluna=rand()%((tam+1));
                      teste=1;
                      do {
                          if (matriz5_gabarito[linha][coluna]==' ') {
                                                        if(count<tam+1) matriz5_gabarito[linha][coluna]='#';   
                                                        if(count<(tam+1)*2 && count>=tam+1) matriz5_gabarito[linha][coluna]='O';   
                                                        if(count<(tam+1)*3 && count>=(tam+1)*2) matriz5_gabarito[linha][coluna]='B'; 
                                                        if(count<(tam+1)*4 && count>=(tam+1)*3) matriz5_gabarito[linha][coluna]='P';                                                   
                                                        
                                                                                                            
                                                        teste=0;
                                                        count++;
                                                        }
                                                        else {
                                                             linha=rand()%(tam+1);
                                                             coluna=rand()%(tam+1);
                                                             }
                                                         
                                                             }while (teste);
                                                             }while(count!=(tam+1)*4);
                                                             
      
    count=0;                                                       
    
tam2=tam; //PASSA O TAMANHO DA MATRIZ GABARITO 1 PARA A 2 POIS SEMPRE ELAS TERÃO O MESMO TAMANHO

//-----------------MATRIZ GABARITO 2 COM SRAND------------------
for (i=0;i<=tam2;i++) {
    for (j=0;j<=tam2;j++) {
        matriz5_gabarito2[i][j]=' ';        
        }}
        
    srand(time(NULL));
    do{
                      linha2=rand()%((tam2+1));
                      coluna2=rand()%((tam2+1));
                      teste=1;
                      do {
                          if (matriz5_gabarito2[linha2][coluna2]==' ') {
                                                        if(count<tam2+1) matriz5_gabarito2[linha2][coluna2]='O';   
                                                        if(count<(tam2+1)*2 && count>=tam2+1) matriz5_gabarito2[linha2][coluna2]='#';   
                                                        if(count<(tam2+1)*3 && count>=(tam2+1)*2) matriz5_gabarito2[linha2][coluna2]='P'; 
                                                        if(count<(tam2+1)*4 && count>=(tam2+1)*3) matriz5_gabarito2[linha2][coluna2]='B';                                                   
                                                        
                                                                                                            
                                                        teste=0;
                                                        count++;
                                                        }
                                                        else {
                                                             linha2=rand()%(tam2+1);
                                                             coluna2=rand()%(tam2+1);
                                                             }
                                                         
                                                             }while (teste);
                                                             }while(count!=(tam2+1)*4);
  //================================================================================================
 
 //SETA AS POSIÇOES DO TABULEIRO MARCAÇAO COM "*"
  for (i=0;i<=tam;i++){
    for (j=0 ;j<=tam;j++) {       //SETANDO O TABULEIRO DO JOGADOR 1 COM "*"
matriz5_marcacao[i][j]='*';
}}           

for (i=0;i<=tam;i++){
    for (j=0 ;j<=tam;j++) {       //SETANDO O TABULEIRO DO JOGADOR 2 COM "*"
matriz5_marcacao_j2[i][j]='*';
}}                    
 //================================================================================================                        
        /*       // DESENHA O TABULEIRO-GABARITO DO JOGADOR 1
                for(i=0;i<=tam;i++) {
                   for (j=0;j<=tam;j++) {
                     printf ("[%c]", matriz5_gabarito[i][j]);      
                     }
                     printf ("\n");
                     
                     }
                    printf ("\n\n\n"); 
                // DESENHA O TABULEIRO-GABARITO DO JOGADOR 2
                for(i=0;i<=tam;i++) {
                    for (j=0;j<=tam;j++) {
                     printf ("[%c]", matriz5_gabarito2[i][j]);      
                     }
                     printf ("\n");
                     
                     }
  system ("pause");  */
                      
//=========================== TABULEIRO JOGADOR 1 ==================================            
                   do {                              
                    if (jogador==1){
                                    jogadasj1++; //CONTADOR DE JOGADAS DO JOGADOR 1     
   
                system("cls");   
                          
             pontuacao_atual= 0;
              
                              
               printf ("\t\t\t²²²²²²²²²²²²²²²²²²²²²²²²²²²\n");
               printf ("\t\t\t²²      JOGADOR %d        ²²\n", jogador);
               printf ("\t\t\t²²²²²²²²²²²²²²²²²²²²²²²²²²²\n\n\n");    
               if(jogadasj1>1)  printf ("\t\t  SUA POSICAO ATUAL EH: LINHA %d E COLUNA %d\n", i_anterior1, j_anterior1);
               // DEFINE O NUMERO DAS COLUNAS A DEPENDER DO TAMANHO DO TABULEIRO 
              if (tam==4) printf(" \t\t\t\t  0  1  2  3  4\n");
              if (tam==6) printf(" \t\t\t\t  0  1  2  3  4  5  6\n");     
              if (tam==9) printf(" \t\t\t\t  0  1  2  3  4  5  6  7  8  9\n");
              
                    
               for(i=0 ;i<=tam;i++) {
                                 printf ("\t\t\t\t%d", i);                       
                   for (j=0 ;j<=tam;j++) {
                        printf ("[%c]", matriz5_marcacao[i][j]);                      
                        
                     }
                     
                     printf ("\n");
                     }
                     printf ("\n\n\tLEGENDA\n");
                     printf ("\t[O] - MOEDA DE OURO = 5 PONTOS\n");           
                     printf ("\t[P] - MOEDA DE PRATA = 3 PONTOS\n");
                     printf ("\t[B] - MOEDA DE BRONZE = 1 PONTO\n");
                     printf ("\t[#] - PAREDE = -1 PONTO\n");
                     printf ("\t[ ] - VAZIO = 0 PONTOS\n");
                     
                
                //==================MENSAGENS DE ALERTA AO JOGADOR====================
                 if ((matriz5_marcacao[i_anterior1+1][j_anterior1]!='*')&&(matriz5_marcacao[i_anterior1-1][j_anterior1]!='*')&&(matriz5_marcacao[i_anterior1][j_anterior1+1]!='*')&&(matriz5_marcacao[i_anterior1][j_anterior1-1]!='*')){
                 printf ("\nVOCE ESTA PRESO, ESCOLHA QUALQUER CASA DO TABULEIRO\n");}
                 if (matriz5_marcacao[i_jogada1][j_jogada1]== '#')printf ("\nVOCE ENCONTROU UMA PAREDE, JOGUE NOVAMENTE\n");
                 else {            
                 if (jogadasj1!=1 && (i_jogada1 != i_anterior1+1 && j_jogada1 != j_anterior1) || (i_jogada1 != i_anterior1-1 && j_jogada1 != j_anterior1) || (i_jogada1 != i_anterior1 && j_jogada1 != j_anterior1+1) || (i_jogada1 != i_anterior1 && j_jogada1 != j_anterior1-1)){  
                                  printf ("\nJOGADA INVALIDA\n");}}
                                  
                     printf ("\nPONTUACAO ATUAL = %d\n", pontuacao_j1); //PONTUAÇAO ATUAL DO JOGADOR 1
              
            printf ("\nDIGITE O NUMERO DA LINHA: ");
            scanf ("%d", &i_jogada1);
            printf ("DIGITE O NUMERO DA COLUNA: ");
            scanf ("%d", &j_jogada1);

//CASO ESTEJA CERCADO E NÃO TENHA PARA ONDE SE MOVIMENTAR, O JOGADOR TEM DIREITO A REALIZAR UMA NOVA JOGADA EM OUTRA CASA 
if ((matriz5_marcacao[i_anterior1+1][j_anterior1]!='*')&&(matriz5_marcacao[i_anterior1-1][j_anterior1]!='*')&&(matriz5_marcacao[i_anterior1][j_anterior1+1]!='*')&&(matriz5_marcacao[i_anterior1][j_anterior1-1]!='*')){
                                                                                                                                        jogadasj1=1;}


       /*CONDIÇAO PARA QUE A CASA ESCOLHIDA NÃO SEJA DISTANTE, CASO SEJA, NAO CONTABILIZAR O PONTO*/
if (jogadasj1==1 || (i_jogada1 == i_anterior1+1 && j_jogada1 == j_anterior1) || (i_jogada1 == i_anterior1-1 && j_jogada1 == j_anterior1) || (i_jogada1 == i_anterior1 && j_jogada1 == j_anterior1+1) || (i_jogada1 == i_anterior1 && j_jogada1 == j_anterior1-1)){ 

// CASO ENCONTRE UMA PAREDE, RETORNAR A POSIÇAO ANTERIOR
if (matriz5_marcacao[i_jogada1][j_jogada1]=='*' && matriz5_gabarito[i_jogada1][j_jogada1]!='#'){

i= i_jogada1;
i_anterior1 = i;                                                                         
j=j_jogada1;
j_anterior1 = j; 

            //PASSAGEM DO VALOR DO TABULEIRO-GABARITO PARA O TABULEIRO DO JOGADOR 1
            matriz5_marcacao[i][j] = matriz5_gabarito[i][j];
            
}
else {
       if (matriz5_marcacao[i_jogada1][j_jogada1]=='#') pontuacao_j1=pontuacao_j1 +1;   // CASO A CASA TENHA PAREDE E ELA JA TENHA SIDO ESCOLHIDA ANTERIORMENTE, A PONTUAÇÃO PERMANECE A MESMA
     //PASSAGEM DO VALOR DO TABULEIRO-GABARITO PARA O TABULEIRO DO JOGADOR 1
     matriz5_marcacao[i_jogada1][j_jogada1] = matriz5_gabarito[i_jogada1][j_jogada1];
 
     }

  
       //ATRIBUIÇÃO DE VALORES AOS CARACTERES                  
if (matriz5_gabarito[i][j]=='O') pontuacao_atual=5;
if (matriz5_gabarito[i][j]=='P') pontuacao_atual=3;
if (matriz5_gabarito[i][j]=='B') pontuacao_atual=1;                     
if (matriz5_gabarito[i][j]==' ') pontuacao_atual= 0;
  
if (matriz5_gabarito[i_jogada1][j_jogada1]=='#'){     
                                                        
pontuacao_j1=pontuacao_j1 -1;     //CALCULO PARA PONTUAÇAO SE FOR PAREDE                                                                                        
                                                   }
  else {
       pontuacao_j1=pontuacao_j1 + pontuacao_atual;}//CALCULO PARA PONTUAÇAO NORMAL  
       

//------------------------------------------------------------------------            
 
}

system("cls");


 jogador++;           //ALTERNA PARA O JOGADOR 2


if (matriz5_gabarito[i][j]== '#'){ //CASO O JOGADOR ENCONTRE UMA PAREDE
jogador--;
jogadasj1--;

} 
//CONDIÇOES PARA A CASA ESCOLHIDA NÃO PERTENÇA AO TABULEIRO OU A CASA ESCOLHIDA NAO SEJA VALIDA, MESMO SE ESCOLHER UMA POSIÇÃO NEGATIVA OCORRE COMO O ESPERADO
if (i > tam || j > tam){
jogador--;
jogadasj1--;
} 
else{
    
if (jogadasj1>1){ // CASO NÃO SEJA A PRIMEIRA JOGADA                                          
if (matriz5_marcacao[i_jogada1][j_jogada1]!= '*' &&(i_jogada1 != i_anterior1+1 && j_jogada1 != j_anterior1) || (i_jogada1 != i_anterior1-1 && j_jogada1 != j_anterior1) || (i_jogada1 != i_anterior1 && j_jogada1 != j_anterior1+1) || (i_jogada1 != i_anterior1 && j_jogada1 != j_anterior1-1)){
jogador--;
jogadasj1--;}}
}
             
if (jogador==2){system ("cls");  

                       //EXIBE O TABULEIRO PARA O JOGADOR APÓS SUA JOGADA
               printf ("\t\t\t²²²²²²²²²²²²²²²²²²²²²²²²²²²\n");
               printf ("\t\t\t²²      JOGADOR 1        ²²\n");
               printf ("\t\t\t²²²²²²²²²²²²²²²²²²²²²²²²²²²\n\n\n");    
               if(jogadasj1>1)  printf ("\t\t  SUA POSICAO ATUAL EH: LINHA %d E COLUNA %d\n", i_anterior1, j_anterior1);
               // DEFINE O NUMERO DAS COLUNAS A DEPENDER DO TAMANHO DO TABULEIRO 
              if (tam==4) printf(" \t\t\t\t  0  1  2  3  4\n");
              if (tam==6) printf(" \t\t\t\t  0  1  2  3  4  5  6\n");     
              if (tam==9) printf(" \t\t\t\t  0  1  2  3  4  5  6  7  8  9\n");
              
                    
               for(i=0 ;i<=tam;i++) {
                                 printf ("\t\t\t\t%d", i);                       
                   for (j=0 ;j<=tam;j++) {
                        printf ("[%c]", matriz5_marcacao[i][j]);                      
                        
                     }
                     
                     printf ("\n");
                     }      
            printf ("\nPONTUACAO ATUAL = %d\n", pontuacao_j1); //PONTUAÇAO ATUAL DO JOGADOR 1
            printf ("MUDANCA DE JOGADOR:\n");      //COLOCA UMA TELA INTERMEDIARIA ENTRE OS 2 TABULEIROS PARA QUE UM JOGADOR NÃO VEJA O TABULEIRO DO ADVERSARIO         
            system ("pause");}


                     
            }//JOGADOR
            
//=========================== TABULEIRO JOGADOR 2 ==================================            
           
                    if (jogador==2 && pontuacao_j1<pont_minima){     // A CONDIÇÃO "pontuacao_j1<pont_minima" FOI COLOCADA PARA QUE NAO SEJA NECESSARIA A JOGADA DO JOGADOR DOIS QUANDO A PONTUAÇAO MINIMA DO JOGADOR 1 SEJA ALCANÇADA
                                         jogadasj2++;
                system("cls");   
              
              pontuacao_atual= 0;             
               
               printf ("\t\t\t²²²²²²²²²²²²²²²²²²²²²²²²²²²\n");
               printf ("\t\t\t²²      JOGADOR %d        ²²\n", jogador);
               printf ("\t\t\t²²²²²²²²²²²²²²²²²²²²²²²²²²²\n\n\n");
                if(jogadasj2>1)  printf ("\t\t   SUA POSICAO ATUAL EH: LINHA %d E COLUNA %d\n", i_anterior2, j_anterior2);    
                // DEFINE O NUMERO DAS COLUNAS A DEPENDER DO TAMANHO DO TABULEIRO 
              if (tam==4) printf(" \t\t\t\t  0  1  2  3  4\n");
              if (tam==6) printf(" \t\t\t\t  0  1  2  3  4  5  6\n");     
              if (tam==9) printf(" \t\t\t\t  0  1  2  3  4  5  6  7  8  9\n");
                    
               for(i=0 ;i<=tam;i++) {
                                 printf ("\t\t\t\t%d", i);                       
                   for (j=0 ;j<=tam;j++) {
                        printf ("[%c]", matriz5_marcacao_j2[i][j]);                      
                        
                     }
                     
                     printf ("\n");
                     }
                     printf ("\n\n\tLEGENDA\n");
                     printf ("\t[O] - MOEDA DE OURO = 5 PONTOS\n");           
                     printf ("\t[P] - MOEDA DE PRATA = 3 PONTOS\n");
                     printf ("\t[B] - MOEDA DE BRONZE = 1 PONTO\n");
                     printf ("\t[#] - PAREDE = -1 PONTO\n");
                     printf ("\t[ ] - VAZIO = 0 PONTOS\n");
                     
                     //==================MENSAGENS DE ALERTA AO JOGADOR====================
                 if ((matriz5_marcacao_j2[i_anterior2+1][j_anterior2]!='*')&&(matriz5_marcacao_j2[i_anterior2-1][j_anterior2]!='*')&&(matriz5_marcacao_j2[i_anterior2][j_anterior2+1]!='*')&&(matriz5_marcacao_j2[i_anterior2][j_anterior2-1]!='*')){
                 printf ("\nVOCE ESTA PRESO, ESCOLHA QUALQUER CASA DO TABULEIRO\n");}
                 if (matriz5_marcacao_j2[i_jogada2][j_jogada2]== '#')printf ("\nVOCE ENCONTROU UMA PAREDE, JOGUE NOVAMENTE\n");
                 else {            
                 if (jogadasj2!=1 && (i_jogada2 != i_anterior2+1 && j_jogada2 != j_anterior2) || (i_jogada2 != i_anterior2-1 && j_jogada2 != j_anterior2) || (i_jogada2 != i_anterior2 && j_jogada2 != j_anterior2+1) || (i_jogada2 != i_anterior2 && j_jogada2 != j_anterior2-1)){  
                                  printf ("\nJOGADA INVALIDA\n");}}
                    
                     printf ("\nPONTUACAO ATUAL = %d\n", pontuacao_j2); //PONTUAÇAO ATUAL DO JOGADOR 2
                     
            printf ("\nDIGITE O NUMERO DA LINHA: ");
            scanf ("%d", &i_jogada2);
            printf ("DIGITE O NUMERO DA COLUNA: ");
            scanf ("%d", &j_jogada2); 
            
//CASO ESTEJA CERCADO E NÃO TENHA PARA ONDE SE MOVIMENTAR, O JOGADOR TEM DIREITO A REALIZAR UMA NOVA JOGADA EM OUTRA CASA 
if ((matriz5_marcacao_j2[i_anterior2+1][j_anterior2]!='*')&&(matriz5_marcacao_j2[i_anterior2-1][j_anterior2]!='*')&&(matriz5_marcacao_j2[i_anterior2][j_anterior2+1]!='*')&&(matriz5_marcacao_j2[i_anterior2][j_anterior2-1]!='*')){
                                                                                                                                        jogadasj2=1;}

/*CONDIÇAO PARA QUE A CASA ESCOLHIDA NÃO SEJA DISTANTE, CASO SEJA, NAO CONTABILIZAR O PONTO*/
if (jogadasj2==1 || (i_jogada2 == i_anterior2+1 && j_jogada2 == j_anterior2) || (i_jogada2 == i_anterior2-1 && j_jogada2 == j_anterior2) || (i_jogada2 == i_anterior2 && j_jogada2 == j_anterior2+1) || (i_jogada2 == i_anterior2 && j_jogada2 == j_anterior2-1)){ 
 
// CASO ENCONTRE UMA PAREDE, RETORNAR A POSIÇAO ANTERIOR
if (matriz5_marcacao_j2[i_jogada2][j_jogada2]=='*' && matriz5_gabarito2[i_jogada2][j_jogada2]!='#'){
i= i_jogada2;
i_anterior2 = i;                                                                         
j=j_jogada2;
j_anterior2 = j; 

            //PASSAGEM DO VALOR DO TABULEIRO-GABARITO PARA O TABULEIRO DO JOGADOR 2
            matriz5_marcacao_j2[i][j] = matriz5_gabarito2[i][j];
            
               
            
}
else {     
     if (matriz5_marcacao_j2[i_jogada2][j_jogada2]=='#') pontuacao_j2=pontuacao_j2 +1;   // CASO A CASA TENHA PAREDE E ELA JA TENHA SIDO ESCOLHIDA ANTERIORMENTE, A PONTUAÇÃO PERMANECE A MESMA
     //PASSAGEM DO VALOR DO TABULEIRO-GABARITO PARA O TABULEIRO DO JOGADOR 2
     matriz5_marcacao_j2[i_jogada2][j_jogada2] = matriz5_gabarito2[i_jogada2][j_jogada2];
     
    
     }

      //ATRIBUIÇÃO DE VALORES AOS CARACTERES                  
if (matriz5_gabarito2[i][j]=='O') pontuacao_atual=5;
if (matriz5_gabarito2[i][j]=='P') pontuacao_atual=3;
if (matriz5_gabarito2[i][j]=='B') pontuacao_atual=1;                    
if (matriz5_gabarito2[i][j]==' ') pontuacao_atual=0;  

if (matriz5_gabarito2[i_jogada2][j_jogada2]=='#'){       
pontuacao_j2=pontuacao_j2 -1;     //CALCULO PARA PONTUAÇAO SE FOR PAREDE                                                                                        
                          }
  else {
       pontuacao_j2=pontuacao_j2 + pontuacao_atual;}//CALCULO PARA PONTUAÇAO NORMAL 
           

                               
//------------------------------------------------------------------------            
     

 
}




          
system("cls");     
       
jogador--;       // ALTERNA PARA O JOGADOR 1     

if (matriz5_gabarito2[i][j]== '#'){ //CASO O JOGADOR ENCONTRE UMA PAREDE
jogador++;
jogadasj2--;
} 

//CONDIÇOES PARA A CASA ESCOLHIDA NÃO PERTENÇA AO TABULEIRO OU A CASA ESCOLHIDA NAO SEJA VALIDA OU A CASA ESCOLHIDA SEJA UMA PAREDE, MESMO SE ESCOLHER UMA POSIÇÃO NEGATIVA OCORRE COMO O ESPERADO 
if (i > tam || j > tam){
jogador++;
jogadasj2--;
} 
else{
 if (jogadasj2>1){  // CASO NÃO SEJA A PRIMEIRA JOGADA      
if ((i_jogada2 != i_anterior2+1 && j_jogada2 != j_anterior2) || (i_jogada2 != i_anterior2-1 && j_jogada2 != j_anterior2) || (i_jogada2 != i_anterior2 && j_jogada2 != j_anterior2+1) || (i_jogada2 != i_anterior2 && j_jogada2 != j_anterior2-1)){
jogador++;
jogadasj2--;}}
}
            
            
if (jogador==1){system ("cls");   
                       //EXIBE O TABULEIRO PARA O JOGADOR APÓS SUA JOGADA
               printf ("\t\t\t²²²²²²²²²²²²²²²²²²²²²²²²²²²\n");
               printf ("\t\t\t²²      JOGADOR 2        ²²\n");
               printf ("\t\t\t²²²²²²²²²²²²²²²²²²²²²²²²²²²\n\n\n");
                if(jogadasj2>1)  printf ("\t\t   SUA POSICAO ATUAL EH: LINHA %d E COLUNA %d\n", i_anterior2, j_anterior2);    
                // DEFINE O NUMERO DAS COLUNAS A DEPENDER DO TAMANHO DO TABULEIRO 
              if (tam==4) printf(" \t\t\t\t  0  1  2  3  4\n");
              if (tam==6) printf(" \t\t\t\t  0  1  2  3  4  5  6\n");     
              if (tam==9) printf(" \t\t\t\t  0  1  2  3  4  5  6  7  8  9\n");
                    
               for(i=0 ;i<=tam;i++) {
                                 printf ("\t\t\t\t%d", i);                       
                   for (j=0 ;j<=tam;j++) {
                        printf ("[%c]", matriz5_marcacao_j2[i][j]);                      
                        
                     }
                     
                     printf ("\n");
                     }     
           printf ("\nPONTUACAO ATUAL = %d\n", pontuacao_j2); //PONTUAÇAO ATUAL DO JOGADOR 2
            printf ("MUDANCA DE JOGADOR:\n");      //COLOCA UMA TELA INTERMEDIARIA ENTRE OS 2 TABULEIROS PARA QUE UM JOGADOR NÃO VEJA O TABULEIRO DO ADVERSARIO         
            system ("pause");}            
            
            
            
            }//JOGADOR
  
            }while(pontuacao_j1<pont_minima && pontuacao_j2<pont_minima);
            
            system("cls");
if (pontuacao_j1>=pont_minima) {
                              printf ("\t\t\t²²²²²²²²²²²²²²²²²²²²²²²²²²²²²\n");
                              printf ("\t\t\t²²O JOGADOR 1 EH O VENCEDOR²²\n");
                              printf ("\t\t\t²²²²²²²²²²²²²²²²²²²²²²²²²²²²²\n\n\n");
                                }
                                      
                                            
            
if (pontuacao_j2>=pont_minima) {
                              printf ("\t\t\t²²²²²²²²²²²²²²²²²²²²²²²²²²²²²\n");
                              printf ("\t\t\t²²O JOGADOR 2 EH O VENCEDOR²²\n");
                              printf ("\t\t\t²²²²²²²²²²²²²²²²²²²²²²²²²²²²²\n\n\n");
                                   }
                                      
                                      
                                      
                              printf ("\t\tOS TABULEIROS-GABARITO ENCONTRAM-SE ABAIXO:\n\n");
                              printf ("\t\t\tTABULEIRO-GABARITO DO JOGADOR 1\n");
                              if (tam==4) printf(" \t\t\t\t  0  1  2  3  4\n");
                              if (tam==6) printf(" \t\t\t\t  0  1  2  3  4  5  6\n");     
                              if (tam==9) printf(" \t\t\t\t  0  1  2  3  4  5  6  7  8  9\n");
                              for (i=0;i<=tam;i++){
                                   printf ("\t\t\t\t%d", i);
                                  for (j=0;j<=tam;j++) {
                                      printf ("[%c]", matriz5_gabarito[i][j]);
                                      }
                                      printf ("\n");}        
                                      
                              printf ("\n\n\t\t\tTABULEIRO-GABARITO DO JOGADOR 2\n");
                              if (tam==4) printf(" \t\t\t\t  0  1  2  3  4\n");
                              if (tam==6) printf(" \t\t\t\t  0  1  2  3  4  5  6\n");     
                              if (tam==9) printf(" \t\t\t\t  0  1  2  3  4  5  6  7  8  9\n");
                              for (i=0;i<=tam;i++){
                                   printf ("\t\t\t\t%d", i);
                                  for (j=0;j<=tam;j++) {
                                      printf ("[%c]", matriz5_gabarito2[i][j]);
                                      }
                                      printf ("\n");}          
                                      
                                      
                                      printf ("\nO JOGO TERMINOU\n");
                                      system("pause"); 
             
            break;
            
 
           
       case 2: //INSTRUÇÕES
            system("cls");
            printf ("\t\t\t²²²²²²²²²²²²²²²²²²²²²²²²²²²\n");
            printf ("\t\t\t²²      INSTRUCOES       ²²\n");
            printf ("\t\t\t²²²²²²²²²²²²²²²²²²²²²²²²²²²\n\n\n");
            
            printf ("ESSE JOGO NECESSITA A PARTICIPACAO DE 2 JOGADORES\n");
            printf ("SEU OBJETIVO EH ALCANCAR A PONTUACAO MINIMA NECESSARIA CORRESPONDENTE\nA CADA TABULEIRO\n\n");
            printf ("TABULEIRO 5X5 = 20 PONTOS\n"); 
            printf ("TABULEIRO 7X7 = 35 PONTOS\n");
            printf ("TABULEIRO 10X10 = 50 PONTOS\n\n");
            printf ("PARA CONSEGUIR PONTOS VOCE DEVE ENCONTRAR MOEDAS ESCONDIDAS NO TABULEIRO\n");
            printf ("CADA MOEDA CORRESPONDE A UMA PONTUACAO DIFERENTE\n\n");
            printf ("\tMOEDA DE OURO(O) = 5 PONTOS\n");
            printf ("\tMOEDA DE PRATA(P) = 3 PONTOS\n");
            printf ("\tMOEDA DE BRONZE(B) = 1 PONTOS\n\n");
            printf ("1- CASO ENCONTRE ALGUMA MOEDA, A CASA EH MARCADA COMO JA VISITADA, O JOGADOR AVANCA PARA ESTA CASA E RECEBE O PONTO CORRESPONDETE A MOEDA\n");
            printf ("2- CASO ENCONTRE UMA PAREDE(#), A CASA EH MARCADA COMO JA VISITADA, O JOGADOR MANTEM SUA POSICAO E PERDE 1 PONTO\n");
            printf ("3- CASO A CASA ESTEJA VAZIA, O JOGADOR AVANCA PARA ESTA CASA E MARCA COMO VISITADA\n");
            printf ("4- VOCE NAO PODE JOGAR EM UMA CASA JA ESCOLHIDA ANTERIORMENTE\n"); 
            printf ("5- SO EH POSSIVEL LOCOMOVER-SE UMA CASA\n");
            printf ("6- SE O JOGADOR NAO TIVER PARA ONDE AVANCAR, ELE PODE ESCOLHER UMA NOVA CASA\n");
            
            printf ("\n[1] RETORNAR AO MENU\n");
            scanf ("%d", &retorno);
            break;
            
       case 3:
            
            break;
            
}
}while(retorno==1);
}
