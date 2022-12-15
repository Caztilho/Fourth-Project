#include<stdio.h>
#include<locale.h>

char disciplinas[3];
float MediasBimestrais[3][4], TotalPontosAno[3], NotaNoExameFinal[3];
int x, y, cont;

void lerdisciplinas(){
	for(cont=0;cont<=2;cont++){
		printf("Digite a %d° disciplina do seu curso técnico: ", cont+1);
		scanf("%s", &disciplinas[cont]);
	}
}

void lermedias(char d, int a){
  
	    for(cont=0;cont<=3;cont++){
		printf("Digite a %d° média da disciplina de %c: ", cont+1, d);
		scanf("%f", &MediasBimestrais[a][cont]);
	
		while ((MediasBimestrais[a][cont] < 0 ) || (MediasBimestrais[a][cont] > 10)){
		printf("Digite uma nota válida!!\n");
		scanf("%f", &MediasBimestrais[a][cont]);
		}
	}	
	}
	

float pontosAoAno(int a){
	float tpa;
	
	for(cont=0;cont<=3;cont++){
		tpa= tpa + MediasBimestrais[a][cont];
	}
	
	return tpa;
}

void examefinal(float &notanecessaria, int a){
	if((notanecessaria >= 15) && (notanecessaria < 24)){
		notanecessaria = 10 - (notanecessaria / 4);
    }

}

main(){
	setlocale(LC_ALL, "Portuguese");
	
	lerdisciplinas();
	for(x = 0; x <= 2; x++){
		lermedias(disciplinas[x], x);
		
	}
	
	for(x = 0; x <= 2; x++){
		TotalPontosAno[x] = pontosAoAno(x);
		if(TotalPontosAno[x] >= 24){
			printf("Aprovado em: %c\n", disciplinas[x]);
		}
		if(TotalPontosAno[x] < 15){
			printf("Retido em: %c\n", disciplinas[x]);
		}
		if((TotalPontosAno[x] >= 15) && (TotalPontosAno[x] < 24)){
			printf("Exame final em: %c\n", disciplinas[x]);
		}
	}
	
	for(x = 0; x <= 2; x++){
		if((TotalPontosAno[x] >= 15) && (TotalPontosAno[x] < 24)){
			
			printf("DIgite a nota obtida no exame final em %c:", disciplinas[x]);
             scanf( "%f", &NotaNoExameFinal[x]);
             
             while((NotaNoExameFinal[x] < 0) || (NotaNoExameFinal[x] > 10)){
             	printf("Digite uma nota válida!!\n");
             	
             	
				scanf("%f", &NotaNoExameFinal[x]);
			 }
		}
    }
	
	for(x = 0; x <= 2; x++){
		if((TotalPontosAno[x] >= 15) && (TotalPontosAno[x] < 24)){
			 examefinal(TotalPontosAno[x], x);
			 if(NotaNoExameFinal[x] >= TotalPontosAno[x]){
			 	printf("Resultado após exame final: Aprovado em %c\n", disciplinas[x]);
			 	
			 }else{
			 	printf("Resultado após exame final: Retido em %c\n", disciplinas[x]);
			}
		}
	}
	
}
