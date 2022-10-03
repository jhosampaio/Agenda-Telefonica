/* AGENDA DE CONTATOS EM C*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#define tam 100

typedef struct {

    int dia;
    int mes;
    int ano;

} Data_Nascimento;

typedef struct Pessoa {

    char nome[50];
    char email[50];
    char numero[12];  
	Data_Nascimento data;  
    
} Contato;

void enter (void);
void cadastro (void);
int valida_email (char email[50]);
int valida_telefone (char numero[13]);
int valida_dia (int day);
int valida_mes (int month);
int valida_ano (int year);
void consulta (char busca);
void exibir (int contador);
void buscaDDD (char busca2);

// VARIAVEIS GLOBAIS E DE ARMAZENAMENTO.

int i;
Contato agenda[tam];


	int main(){
		
		int opc = 0;
//		char busca[13];
//		char busca2[13];
		
		do{
        puts("+----------------------------------+");
        puts("|************* Agenda *************|");
        puts("|----------------------------------|");
        puts("|       :ESCOLHA UMA OPÇÃO:        |");
        puts("|- - - - - - - - - - - - - - - - - |");
        puts("| 1) Cadastrar Contatos            |");
        puts("| 2) Buscar Contato.               |");
        puts("| 3) Exibir Todos os Contatos.     |");
        puts("| 4) Quantidade por DDD informado. |");
        puts("| 5) Sair.                         |");
        puts("+----------------------------------+");
        
        enter();

        scanf("%d", &opc);
        
        switch (opc){
        
			case 1:
	        	
	        	puts("Cadastrar novo contato.");
	        	i++;
	        	cadastro();
	        	break;
	        
/*	        case 2:
	        	
	        	puts("Buscar contato pelo numero de telefone.");
	        	puts("Digite o numero:");
				enter();
				gets(busca);
				consulta();
				break;
			
			case 3:
				
				puts("Exibir todos os contatos: ");
				exibir();
				break;
			
			case 4:
				
				puts("Buscar contato por DDD: ");
				puts("Digite o DDD:");
				enter();
				gets(busca2);
				buscaDDD();
*/				break;
			}
			
		}while(opc != 5);			
		
		
		return 0;
	}
// Fun��es.

// Fun��o Limpar ENTER.

void enter(void) { fflush(stdin); }

// Fun��o para cadastrar contato.

void cadastro (void){

    int validacao;

    puts ("Digite o NOME:");
    enter();
    gets (agenda[i].nome);
    puts ("");

   do{
        validacao = 0;
        puts ("Digite o E-MAIL:");
        enter();
        scanf("%s", agenda[i].email);
		validacao = valida_email(agenda[i].email);        

    }while (validacao == 0);
    
    do{
        validacao = 0;
        puts ("Digite o TELEFONE com o DDD:");
        enter();
        scanf("%s", agenda[i].numero); 		
		validacao = valida_telefone(agenda[i].numero);     

    }while (validacao == 0);

    do{
        validacao = 0;
        printf ("\nDigite a data de nascimento\n");
        printf ("Dia: ");
        scanf ("%d", &agenda[i].data.dia);
        validacao = valida_dia(agenda[i].data.dia);

    }while (validacao == 0);

    do{
        validacao = 0;
        printf ("\nDigite a data de nascimento\n");
        printf ("Mes: ");
        scanf ("%d", &agenda[i].data.mes);
        validacao = valida_mes(agenda[i].data.mes);

    }while (validacao == 0);

     do{
        validacao = 0;
        printf ("\nDigite a data de nascimento\n");
        printf ("Ano: ");
        scanf ("%d", &agenda[i].data.ano);
        validacao = valida_ano(agenda[i].data.ano);

    }while (validacao == 0);    
}

// Fun��o para buscar contato.

/*void consulta (char busca[13]){




}

// Fun��o para Exibir todos os contatos cadastrados.

void consulta (char busca){
	
	
	
	
	
}

// Fun��o para buscar contato pelo DDD informado.

void buscaDDD (int busca2){
	
	
	
	
}
*/
	
// Fun��o para validar E-mail
// Ex: sequ�ncia maior que 2 caracteres; seguido de um @; terminado com o sufixo .COM

int valida_email (char email[50]){
	
	int k = 0;
	int logica = 0;
	int emailsize = 0;
	int arroba = 0, ponto = 0, antesP = 0, aposP = 0;
	char c;
	
	emailsize = strlen(email);
	
	
	for (k = 0; k < emailsize; k++){
    	c = email[k];
    	if(c == '@'){
			if (arroba)
       	    break; 
			arroba = 1;
		if (i < 3)
			break; 
		}
    	else if (arroba){ 
			if (ponto){ 
        		aposP++;
			}
			else if(c == '.'){
				ponto = 1;
			if (antesP < 3) {
				break; 
			}
			}
			else{
				antesP++;
			}
		}
	}

	if (k == emailsize && aposP > 1){	
    	logica = 1;
	}else{
    	logica = 0;
	}
	if (logica == 0){ 
        printf("email invalido\n\n");
        return 0;
    } else { 
    	printf("email valido\n\n");
        return 1;
    }

}
	
// Fun��o para validar numero de telefone -
// Ex. deve come�ar com 0; deve conter 11 ou 12 d�gitos num�ricos (valores entre 0-9).

int valida_telefone (char numero[13]){
	
	int j = 0;
	int logica = 0;
	int telsize = 0;
	
	telsize = strlen(numero);
	
	for (j = 0; j < telsize; j++){
		if (numero[0] = '0' && telsize == 12){
			logica = 1;
		}else{
            logica = 0;
        }
        
	}
	if (logica == 0){ 
        printf("Numero invalido\n\n");
        return 0;
    } else { 
    	printf("Numero valido\n\n");
        return 1;
    }		
}
	
// Fun��o para validar dia.

int valida_dia (int day){

    int logica = 0;

    if ((day >= 1) && (day <= 30)){
        logica = 1;
    }else{
        logica = 0;
    }

    if ( logica == 0){ //invalido
        printf ("\nDia invalido\n");
        return 0;
    }else{ // valido
        return 1;
    }
}

//Fun��o para validar m�s.

int valida_mes (int month){

    int logica = 0;

    if ((month >= 1) && (month <= 12)){
        logica = 1;
    }else{
        logica = 0;
    }

    if ( logica == 0){ //invalido
        printf ("\nMes invalido\n");
        return 0;
    }else{ // valido
        return 1;
    }
}

//Fun��o para validar ano.

int valida_ano (int year){

    int logica = 0;

    if ((year >= 1900) && (year <= 2019)){
        logica = 1;
    }else{
        logica = 0;
    }

    if ( logica == 0){ //invalido
        printf ("\nAno invalido\n");
        return 0;
    }else{ // valido
        return 1;
    }
}