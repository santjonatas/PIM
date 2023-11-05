#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <locale.h>
#include <time.h>

typedef struct{
	char nome_completo[99];
	//data de nascimento
	int ano_nasc, mes_nasc, dia_nasc;
	char email[50];
	char numero_tel[20];
	char genero[20];
}cadastro;

typedef struct{
	char tema[75];
	//data do bilhete
	int ano, mes, dia;
	char ingresso_tipo[30];
	float quantidade_ingresso;
	float valor_total_ingresso;
}compra_de_bilhete;

typedef struct{
	char titular[99];
	int numero_cartao_sum, numero_cartao_sdois, numero_cartao_stres, numero_cartao_squatro;
	int cvv;
	int mes_validade, ano_validade;
	float cartao_total;
	int i;
	int pix[50];
}pagamento;

int main(){
	setlocale(LC_ALL,"Portuguese");
	setlocale(LC_ALL,"");
	setlocale(LC_ALL,NULL);
	
	FILE *cadastros;
	
	cadastro cadpessoa;
	compra_de_bilhete bilhete_evento;
	pagamento pag_cartao;
	
	cadpessoa.ano_nasc=0, cadpessoa.mes_nasc=0, cadpessoa.dia_nasc=0;
	bilhete_evento.ano=0, bilhete_evento.mes=0, bilhete_evento.dia=0, bilhete_evento.quantidade_ingresso=0, bilhete_evento.valor_total_ingresso=0;
	int menu_principal, opcoes_do_menu_principal, compra_de_bilhetes, escolher_evento, tipo_de_ingresso, ingresso_adicionado;
	char entrada_cheia[17]="ENTRADA INTEIRA", meia_entrada[14]="MEIA ENTRADA", insencao[10]="INSEN��O";
	char cem_anos_da_sem[40]="100 Anos da Semana de Arte Moderna", cento_e_cinquenta_anos[40]="150 Anos de Santos Dumont", jogos_olimpicos[40]="Jogos Ol�mpicos de Paris 2024", cultura_e_trad[50]="Cultura e Tradi��es Globais";
	char opcao_invalida[85]="\n[ERRO!] Ops! Parece que Voce Digitou uma Data Inv�lida, Selecione uma Data V�lida.\n";
	int finalizar_cadastro;
	int forma_de_pagamento, credito_ou_debito, sair_da_compra;
	char sttspag[70]="Status: Aguardando Pagamento";
	char sttspag2[50]="Status: PAGO";
	int sair_dos_temas;
	int sair_disp;
	
	char p1[99], p2[99], p3[99], p4[99], p5[99], p6[99], p7[99], p8[99], p9[99], p10[99];
	
	int sair_pgt;
	
	cadastros = fopen("cadastros.txt", "a");
	
	inicio_da_pagina:
	system("cls");
	printf("\nSEJA BEM-VINDO\n");
	printf("AO MUSEU Art&Tech !!!\n"); 
	printf("\nUm museu que combina Arte e Tecnologia para proporcionar uma experi�ncia �nica.");
	printf("\nAqui voc� mergulhar� em um mundo onde a criatividade encontra a inova��o, e a beleza se funde com a tecnologia de ponta.");
	printf("\nNossas galerias s�o um santu�rio de express�o art�stica, onde obras de arte tradicionais ganham vida com elementos interativos e digitais.");
	printf("\nDe pinturas cl�ssicas a instala��es modernas, cada pe�a � cuidadosamente selecionada para encantar seus sentidos e desafiar sua percep��o.");
	
	menu_principal:
	printf("\n\n\n\n\n\n\n---------------------------------------------------------------------");
	printf("\n[ATEN��O] Digite o N�mero Correspondente a Op��o Que Deseja Acessar.");
	printf("\n\n1. Menu Principal");
	printf("\n2. Sair do Programa\n");
    scanf("%d", &menu_principal);
    fflush(stdin);
    switch(menu_principal){
    	case 1:
    		printf("\n---MENU PRINCIPAL---\n");
    		printf("--------------------\n");
    		printf("\n1. Fazer Cadastro");
    		printf("\n2. Compra de Bilhetes");
    		printf("\n3. Finalizar Compra");
    		printf("\n4. Verificar Disponibilidade");
    		printf("\n5. Conhe�a os Temas Dispon�veis");
    		printf("\n6. Responder Questionario");
    		printf("\n7. Sair do Menu Principal\n");
    		
    		scanf("%d", &opcoes_do_menu_principal);
    		fflush(stdin);
    		switch(opcoes_do_menu_principal){
    			fazer_cadastro:
    			case 1:
    				system("cls");
    				printf("\n---FAZER CADASTRO---");
    				printf("\n--------------------");
    				printf("\n(ATEN��O: Os Dados Informados s�o de sua Responsabilidade! Por favor Digite Corretamente.)\n");
    				printf("\nDigite seu Nome Completo: ");
    				gets(cadpessoa.nome_completo);
    				fflush(stdin);
    				ano_de_nascimento:
    				printf("\nInforme sua Data de Nascimento");
    				printf("\nInforme o Ano: ");
    				scanf("%d", &cadpessoa.ano_nasc);
    				fflush(stdin);
    				if(cadpessoa.ano_nasc > 2023){
    					puts(opcao_invalida);
    					goto ano_de_nascimento;
					}
					mes_de_nascimento:
    				printf("Informe o Mes: ");
    				scanf("%d", &cadpessoa.mes_nasc);
    				fflush(stdin);
    				if(cadpessoa.mes_nasc > 12){
    					puts(opcao_invalida);
    					goto mes_de_nascimento;
					}
					dia_de_nascimento:
    				printf("Informe o Dia: ");
    				scanf("%d", &cadpessoa.dia_nasc);
    				fflush(stdin);
    				if(cadpessoa.dia_nasc > 31){
    					puts(opcao_invalida);
    					goto dia_de_nascimento;
					}
    				printf("\nInforme seu E-mail: ");
    				gets(cadpessoa.email);
    				fflush(stdin);
    				printf("Digite seu N�mero para Contato (xx)xxxxx-xxxx:");
    				gets(cadpessoa.numero_tel);
    				fflush(stdin);
    				printf("\nInforme Seu G�nero: ");
    				gets(cadpessoa.genero);
    				fflush(stdin);
    				printf("\nSeus Dados Cadastrados:\n");
    				printf("Nome Completo: ");
    				puts(cadpessoa.nome_completo);
    				printf("Data de Nascimento: %d/%d/%d", cadpessoa.dia_nasc, cadpessoa.mes_nasc, cadpessoa.ano_nasc);
    				printf("\nE-mail: %s", cadpessoa.email);
    				printf("\nN�mero: %s", cadpessoa.numero_tel);
    				printf("\nG�nero: %s", cadpessoa.genero);
    				printf("\nSeu Cadastro foi Finalizado! Suas Informa��es foram Salvas =)\n");
    				vamos_finalizar:
    				printf("\n1. Finalizar Cadastro e Retornar ao In�cio da P�gina:");
    				scanf("%d", &finalizar_cadastro);
    				fflush(stdin);
    				switch(finalizar_cadastro){
    					case 1:
    						goto inicio_da_pagina;
    					break;
    					default:
    						goto vamos_finalizar;
    					break;
					}
    			break;
    			
    			compra_de_bilhetes:
    			case 2:
    				system("cls");
    			    printf("\n---COMPRA DE BILHETES---");
    				printf("\n------------------------");
    				printf("\n(ATEN��O: Para Comprar um Bilhete, Primeiro � Necessario ter um Cadastro.\n");
    				printf("\nSe Voc� Ainda nao Possui Um Cadastro, Fa�a um em 'Menu Principal'/'Fazer Cadastro')");
    				printf("\nVoc� s� Conseguir� Comprar Ingressos Para um Tema de  Cada Vez!");
    				printf("\n\nEscolher Evento:\n");
    				printf("\n1. 100 Anos da Semana de Arte Moderna");
    				printf("\n2. 150 Anos de Santos Dumont");
    				printf("\n3. Jogos Ol�mpicos de Paris 2024");
    				printf("\n4. Cultura e Tradi��es Globais\n");
    				printf("\n5. VOLTAR AO IN�CIO DA P�GINA\n");
    				scanf("%d", &escolher_evento);
    				fflush(stdin);
    				switch(escolher_evento){
    					case 1:
    						if(finalizar_cadastro != 1){
    					    goto inicio_da_pagina;
					        }
    						cem_anos_da_semana_de_arte_moderna:
    						printf("\n100 ANOS DA SEMANA DE ARTE MODERNA\n");
    						strcpy(bilhete_evento.tema, cem_anos_da_sem);
    						printf("\nSelecione a Data do seu Ingresso\n");
    						printf("\nDefina o Ano:");
    						scanf("%d", &bilhete_evento.ano);
    						fflush(stdin);
    						if(bilhete_evento.ano != 2023){
    							puts(opcao_invalida);
    							goto cem_anos_da_semana_de_arte_moderna;
							}
							printf("Defina o Mes:");
							scanf("%d", &bilhete_evento.mes);
							fflush(stdin);
							if(bilhete_evento.mes < 9){
							    puts(opcao_invalida);	
							    goto cem_anos_da_semana_de_arte_moderna;
							}
							if(bilhete_evento.mes > 12){
								puts(opcao_invalida);
								goto cem_anos_da_semana_de_arte_moderna;
							}
							    printf("Defina o dia:");
							scanf("%d", &bilhete_evento.dia);
							if(bilhete_evento.dia > 31){
							    puts(opcao_invalida);
								goto cem_anos_da_semana_de_arte_moderna;	
							}
							if(bilhete_evento.dia > 30 && bilhete_evento.mes == 11){
								puts(opcao_invalida);
								goto cem_anos_da_semana_de_arte_moderna;	
							}
							if(bilhete_evento.dia < 1){
								puts(opcao_invalida);
								goto cem_anos_da_semana_de_arte_moderna;
							}
							printf("\n(ATEN��O: OS IGRESSOS S�O V�LIDOS DURANTE TODO O DIA QUE VOCE DEFINIU, SEM UM HOR�RIO ESPEC�FICO PARA ENTRAR.");
							printf("\nVoc� Pode Consultar o Hor�rio Das Esposi��es no 'Menu Principal' na Op��o 'Verificar Disponibilidade.')\n");
							printf("\nDefina o Tipo de Ingresso que Ir� Comprar, Lembrando que s� Pode Comprar um Tipo de Cada Vez:\n");
							printf("\n1. Inteira- 30,00");
							printf("\n2. Meia Entrada- 15,00");
							printf("\n3. Isen��o- 00,00\n");
							scanf("%d", &tipo_de_ingresso);
							fflush(stdin);
							switch(tipo_de_ingresso){
								case 1:
									printf("\nENTRADA INTEIRA\n");
									strcpy(bilhete_evento.ingresso_tipo, entrada_cheia);
									printf("\nDigite a Quantidade de Entradas que Deseja:\n");
									scanf("%f", &bilhete_evento.quantidade_ingresso);
									fflush(stdin);
									bilhete_evento.valor_total_ingresso = bilhete_evento.quantidade_ingresso*30;
									printf("Valor total: ");
									printf("%.2f\n", bilhete_evento.valor_total_ingresso);
									printf("\nDIGITE 1 PARA RETORNAR AO IN�CIO DA P�GINA:");
									scanf("%d", &ingresso_adicionado);
									fflush(stdin);
									switch(ingresso_adicionado){
										case 1:
											goto inicio_da_pagina;
										break;
										default:
											goto inicio_da_pagina;
										break;
									}
								break;
								case 2:
									printf("\nMEIA ENTRADA\n");
									strcpy(bilhete_evento.ingresso_tipo, meia_entrada);
									printf("\nDigite a Quantidade de Entradas que Deseja:\n");
									scanf("%f", &bilhete_evento.quantidade_ingresso);
									fflush(stdin);
									bilhete_evento.valor_total_ingresso = bilhete_evento.quantidade_ingresso*15.00;
									printf("Valor total: ");
									printf("%.2f\n", bilhete_evento.valor_total_ingresso);
									printf("\nDIGITE 1 PARA RETORNAR AO IN�CIO DA P�GINA:");
									scanf("%d", &ingresso_adicionado);
									fflush(stdin);
									switch(ingresso_adicionado){
										case 1:
											goto inicio_da_pagina;
										break;
										default:
											goto inicio_da_pagina;
										break;
									}
								break;
								case 3:
									printf("\nISEN��O\n");
									strcpy(bilhete_evento.ingresso_tipo, insencao);
									printf("\nDigite a Quantidade de Entradas que Deseja:\n");
									scanf("%f", &bilhete_evento.quantidade_ingresso);
									fflush(stdin);
									bilhete_evento.valor_total_ingresso = bilhete_evento.quantidade_ingresso*0;
									printf("Valor total: ");
									printf("%.2f\n", bilhete_evento.valor_total_ingresso);
									printf("\nDIGITE 1 PARA RETORNAR AO IN�CIO DA P�GINA:");
									scanf("%d", &ingresso_adicionado);
									fflush(stdin);
									switch(ingresso_adicionado){
										case 1:
											goto inicio_da_pagina;
										break;
										default:
											goto inicio_da_pagina;
										break;
									}
							    break;
							    default:
							    	goto compra_de_bilhetes;
							    break;
							}	
    					break;
    					case 2:
    						if(finalizar_cadastro != 1){
    					    goto inicio_da_pagina;
					        }
    						cento_e_cinquenta_anos_de_santos_dumont:
    						printf("\n150 ANOS DE SANTOS DUMONT\n");
    						strcpy(bilhete_evento.tema, cento_e_cinquenta_anos);
    						printf("\nSelecione a Data do seu Ingresso\n");
    						printf("\nDefina o Ano:");
    						scanf("%d", &bilhete_evento.ano);
    						fflush(stdin);
    						if(bilhete_evento.ano != 2023){
    							puts(opcao_invalida);
    							goto cento_e_cinquenta_anos_de_santos_dumont;
							}
							printf("Defina o Mes:");
							scanf("%d", &bilhete_evento.mes);
							fflush(stdin);
							if(bilhete_evento.mes < 9){
							    puts(opcao_invalida);	
							    goto cento_e_cinquenta_anos_de_santos_dumont;
							}
							if(bilhete_evento.mes > 12){
								puts(opcao_invalida);
								goto cento_e_cinquenta_anos_de_santos_dumont;
							}
							    printf("Defina o dia:");
							scanf("%d", &bilhete_evento.dia);
							if(bilhete_evento.dia > 31){
							    puts(opcao_invalida);
								goto cento_e_cinquenta_anos_de_santos_dumont;	
							}
							if(bilhete_evento.dia > 30 && bilhete_evento.mes == 11){
								puts(opcao_invalida);
								goto cento_e_cinquenta_anos_de_santos_dumont;	
							}
							if(bilhete_evento.dia < 1){
								puts(opcao_invalida);
								goto cento_e_cinquenta_anos_de_santos_dumont;
							}
    						printf("\n(ATEN��O: OS IGRESSOS S�O V�LIDOS DURANTE TODO O DIA QUE VOCE DEFINIU, SEM UM HOR�RIO ESPEC�FICO PARA ENTRAR.");
							printf("\nVoc� Pode Consultar o Hor�rio Das Esposi��es no 'Menu Principal' na Op��o 'Verificar Disponibilidade.')\n");
							printf("\nDefina o Tipo de Ingresso que Ir� Comprar, Lembrando que s� Pode Comprar um Tipo de Cada Vez:\n");
							printf("\n1. Inteira- 30,00");
							printf("\n2. Meia Entrada- 15,00");
							printf("\n3. Isen��o- 00,00\n");
							scanf("%d", &tipo_de_ingresso);
							fflush(stdin);
							switch(tipo_de_ingresso){
								case 1:
									printf("\nENTRADA INTEIRA\n");
									strcpy(bilhete_evento.ingresso_tipo, entrada_cheia);
									printf("\nDigite a Quantidade de Entradas que Deseja:\n");
									scanf("%f", &bilhete_evento.quantidade_ingresso);
									fflush(stdin);
									bilhete_evento.valor_total_ingresso = bilhete_evento.quantidade_ingresso*30;
									printf("Valor total: ");
									printf("%.2f\n", bilhete_evento.valor_total_ingresso);
									printf("\nDIGITE 1 PARA RETORNAR AO IN�CIO DA P�GINA:");
									scanf("%d", &ingresso_adicionado);
									fflush(stdin);
									switch(ingresso_adicionado){
										case 1:
											goto inicio_da_pagina;
										break;
										default:
											goto inicio_da_pagina;
										break;
									}
								break;
								case 2:
									printf("\nMEIA ENTRADA\n");
									strcpy(bilhete_evento.ingresso_tipo, meia_entrada);
									printf("\nDigite a Quantidade de Entradas que Deseja:\n");
									scanf("%f", &bilhete_evento.quantidade_ingresso);
									fflush(stdin);
									bilhete_evento.valor_total_ingresso = bilhete_evento.quantidade_ingresso*15.00;
									printf("Valor total: ");
									printf("%.2f\n", bilhete_evento.valor_total_ingresso);
									printf("\nDIGITE 1 PARA RETORNAR AO IN�CIO DA P�GINA:");
									scanf("%d", &ingresso_adicionado);
									fflush(stdin);
									switch(ingresso_adicionado){
										case 1:
											goto inicio_da_pagina;
										break;
										default:
											goto inicio_da_pagina;
										break;
									}
								break;
								case 3:
									printf("\nISEN��O\n");
									strcpy(bilhete_evento.ingresso_tipo, insencao);
									printf("\nDigite a Quantidade de Entradas que Deseja:\n");
									scanf("%f", &bilhete_evento.quantidade_ingresso);
									fflush(stdin);
									bilhete_evento.valor_total_ingresso = bilhete_evento.quantidade_ingresso*0;
									printf("Valor total: ");
									printf("%.2f\n", bilhete_evento.valor_total_ingresso);
									printf("\nDIGITE 1 PARA RETORNAR AO IN�CIO DA P�GINA:");
									scanf("%d", &ingresso_adicionado);
									fflush(stdin);
									switch(ingresso_adicionado){
										case 1:
											goto inicio_da_pagina;
										break;
										default:
											goto inicio_da_pagina;
										break;
									}
							    break;
							    default:
							    	goto compra_de_bilhetes;
							    break;
							}
    					break;
    					case 3:
    						if(finalizar_cadastro != 1){
    					    goto inicio_da_pagina;
					        }
    						jogos_olimpicos_de_paris_dois_mil_e_vinte_e_quatro:
    						printf("\nJOGOS OL�MPICOS DE PARIS 2024");
    						strcpy(bilhete_evento.tema, jogos_olimpicos);
    						printf("\nSelecione a Data do seu Ingresso\n");
    						printf("\nDefina o Ano:");
    						scanf("%d", &bilhete_evento.ano);
    						fflush(stdin);
    						if(bilhete_evento.ano != 2023){
    							puts(opcao_invalida);
    							goto jogos_olimpicos_de_paris_dois_mil_e_vinte_e_quatro;
							}
							printf("Defina o Mes:");
							scanf("%d", &bilhete_evento.mes);
							fflush(stdin);
							if(bilhete_evento.mes < 9){
							    puts(opcao_invalida);
							    goto jogos_olimpicos_de_paris_dois_mil_e_vinte_e_quatro;
							}
							if(bilhete_evento.mes > 12){
								puts(opcao_invalida);
								goto jogos_olimpicos_de_paris_dois_mil_e_vinte_e_quatro;
							}
							    printf("Defina o dia:");
							scanf("%d", &bilhete_evento.dia);
							if(bilhete_evento.dia > 31){
							    puts(opcao_invalida);
								goto jogos_olimpicos_de_paris_dois_mil_e_vinte_e_quatro;	
							}
							if(bilhete_evento.dia > 30 && bilhete_evento.mes == 11){
								puts(opcao_invalida);
								goto jogos_olimpicos_de_paris_dois_mil_e_vinte_e_quatro;	
							}
							if(bilhete_evento.dia < 1){
								puts(opcao_invalida);
								goto jogos_olimpicos_de_paris_dois_mil_e_vinte_e_quatro;
							}
							printf("\n(ATEN��O: OS IGRESSOS S�O V�LIDOS DURANTE TODO O DIA QUE VOCE DEFINIU, SEM UM HOR�RIO ESPEC�FICO PARA ENTRAR.");
							printf("\nVoc� Pode Consultar o Hor�rio Das Esposi��es no 'Menu Principal' na Op��o 'Verificar Disponibilidade.')\n");
							printf("\nDefina o Tipo de Ingresso que Ir� Comprar, Lembrando que s� Pode Comprar um Tipo de Cada Vez:\n");
							printf("\n1. Inteira- 30,00");
							printf("\n2. Meia Entrada- 15,00");
							printf("\n3. Isen��o- 00,00\n");
							scanf("%d", &tipo_de_ingresso);
							fflush(stdin);
							switch(tipo_de_ingresso){
								case 1:
									printf("\nENTRADA INTEIRA\n");
									strcpy(bilhete_evento.ingresso_tipo, entrada_cheia);
									printf("\nDigite a Quantidade de Entradas que Deseja:\n");
									scanf("%f", &bilhete_evento.quantidade_ingresso);
									fflush(stdin);
									bilhete_evento.valor_total_ingresso = bilhete_evento.quantidade_ingresso*30;
									printf("Valor total: ");
									printf("%.2f\n", bilhete_evento.valor_total_ingresso);
									printf("\nDIGITE 1 PARA RETORNAR AO IN�CIO DA P�GINA:");
									scanf("%d", &ingresso_adicionado);
									fflush(stdin);
									switch(ingresso_adicionado){
										case 1:
											goto inicio_da_pagina;
										break;
										default:
											goto inicio_da_pagina;
										break;
									}
								break;
								case 2:
									printf("\nMEIA ENTRADA\n");
									strcpy(bilhete_evento.ingresso_tipo, meia_entrada);
									printf("\nDigite a Quantidade de Entradas que Deseja:\n");
									scanf("%f", &bilhete_evento.quantidade_ingresso);
									fflush(stdin);
									bilhete_evento.valor_total_ingresso = bilhete_evento.quantidade_ingresso*15.00;
									printf("Valor total: ");
									printf("%.2f\n", bilhete_evento.valor_total_ingresso);
									printf("\nDIGITE 1 PARA RETORNAR AO IN�CIO DA P�GINA:");
									scanf("%d", &ingresso_adicionado);
									fflush(stdin);
									switch(ingresso_adicionado){
										case 1:
											goto inicio_da_pagina;
										break;
										default:
											goto inicio_da_pagina;
										break;
									}
								break;
								case 3:
									printf("\nISEN��O\n");
									strcpy(bilhete_evento.ingresso_tipo, insencao);
									printf("\nDigite a Quantidade de Entradas que Deseja:\n");
									scanf("%f", &bilhete_evento.quantidade_ingresso);
									fflush(stdin);
									bilhete_evento.valor_total_ingresso = bilhete_evento.quantidade_ingresso*0;
									printf("Valor total: ");
									printf("%.2f\n", bilhete_evento.valor_total_ingresso);
									printf("\nDIGITE 1 PARA RETORNAR AO IN�CIO DA P�GINA:");
									scanf("%d", &ingresso_adicionado);
									fflush(stdin);
									switch(ingresso_adicionado){
										case 1:
											goto inicio_da_pagina;
										break;
										default:
											goto inicio_da_pagina;
										break;
									}
							    break;
							    default:
							    	goto compra_de_bilhetes;
							    break;
							}
    					break;
    					case 4:
    						printf("\nCULTURA E TRADI��ES GLOBAIS");
					        if(finalizar_cadastro != 1){
    					    goto inicio_da_pagina;
					        }
    						cultura:
    						printf("\nCULTURA E TRADI��ES GLOBAIS");
    						strcpy(bilhete_evento.tema, cultura_e_trad);
    						printf("\nSelecione a Data do seu Ingresso\n");
    						printf("\nDefina o Ano:");
    						scanf("%d", &bilhete_evento.ano);
    						fflush(stdin);
    						if(bilhete_evento.ano != 2023){
    							puts(opcao_invalida);
    							goto cultura;
							}
							printf("Defina o Mes:");
							scanf("%d", &bilhete_evento.mes);
							fflush(stdin);
							if(bilhete_evento.mes < 9){
							    puts(opcao_invalida);
							    goto cultura;
							}
							if(bilhete_evento.mes > 12){
								puts(opcao_invalida);
								goto cultura;
							}
							    printf("Defina o dia:");
							scanf("%d", &bilhete_evento.dia);
							if(bilhete_evento.dia > 31){
							    puts(opcao_invalida);
								goto cultura;	
							}
							if(bilhete_evento.dia > 30 && bilhete_evento.mes == 11){
								puts(opcao_invalida);
								goto cultura;	
							}
							if(bilhete_evento.dia < 1){
								puts(opcao_invalida);
								goto cultura;
							}
							printf("\n(ATEN��O: OS IGRESSOS S�O V�LIDOS DURANTE TODO O DIA QUE VOCE DEFINIU, SEM UM HOR�RIO ESPEC�FICO PARA ENTRAR.");
							printf("\nVoc� Pode Consultar o Hor�rio Das Esposi��es no 'Menu Principal' na Op��o 'Verificar Disponibilidade.')\n");
							printf("\nDefina o Tipo de Ingresso que Ir� Comprar, Lembrando que s� Pode Comprar um Tipo de Cada Vez:\n");
							printf("\n1. Inteira- 30,00");
							printf("\n2. Meia Entrada- 15,00");
							printf("\n3. Isen��o- 00,00\n");
							scanf("%d", &tipo_de_ingresso);
							fflush(stdin);
							switch(tipo_de_ingresso){
								case 1:
									printf("\nENTRADA INTEIRA\n");
									strcpy(bilhete_evento.ingresso_tipo, entrada_cheia);
									printf("\nDigite a Quantidade de Entradas que Deseja:\n");
									scanf("%f", &bilhete_evento.quantidade_ingresso);
									fflush(stdin);
									bilhete_evento.valor_total_ingresso = bilhete_evento.quantidade_ingresso*30;
									printf("Valor total: ");
									printf("%.2f\n", bilhete_evento.valor_total_ingresso);
									printf("\nDIGITE 1 PARA RETORNAR AO IN�CIO DA P�GINA:");
									scanf("%d", &ingresso_adicionado);
									fflush(stdin);
									switch(ingresso_adicionado){
										case 1:
											goto inicio_da_pagina;
										break;
										default:
											goto inicio_da_pagina;
										break;
									}
								break;
								case 2:
									printf("\nMEIA ENTRADA\n");
									strcpy(bilhete_evento.ingresso_tipo, meia_entrada);
									printf("\nDigite a Quantidade de Entradas que Deseja:\n");
									scanf("%f", &bilhete_evento.quantidade_ingresso);
									fflush(stdin);
									bilhete_evento.valor_total_ingresso = bilhete_evento.quantidade_ingresso*15.00;
									printf("Valor total: ");
									printf("%.2f\n", bilhete_evento.valor_total_ingresso);
									printf("\nDIGITE 1 PARA RETORNAR AO IN�CIO DA P�GINA:");
									scanf("%d", &ingresso_adicionado);
									fflush(stdin);
									switch(ingresso_adicionado){
										case 1:
											goto inicio_da_pagina;
										break;
										default:
											goto inicio_da_pagina;
										break;
									}
								break;
								case 3:
									printf("\nISEN��O\n");
									strcpy(bilhete_evento.ingresso_tipo, insencao);
									printf("\nDigite a Quantidade de Entradas que Deseja:\n");
									scanf("%f", &bilhete_evento.quantidade_ingresso);
									fflush(stdin);
									bilhete_evento.valor_total_ingresso = bilhete_evento.quantidade_ingresso*0;
									printf("Valor total: ");
									printf("%.2f\n", bilhete_evento.valor_total_ingresso);
									printf("\nDIGITE 1 PARA RETORNAR AO IN�CIO DA P�GINA:");
									scanf("%d", &ingresso_adicionado);
									fflush(stdin);
									switch(ingresso_adicionado){
										case 1:
											goto inicio_da_pagina;
										break;
										default:
											goto inicio_da_pagina;
										break;
									}
							    break;
							    default:
							    	goto compra_de_bilhetes;
							    break;
							}     
    					break;
    					case 5:
    						goto inicio_da_pagina;
    					break;
    					default:
    						goto compra_de_bilhetes;
    					break;
					}
    			break;
    			case 3:
    				finalizar_a_compra:
    				system("cls");
    				printf("\n---FINALIZAR COMPRA---");
    				printf("\n----------------------");
    				printf("\nSeus Dados Cadastrados:\n");
    				printf("Nome Completo: ");
    				puts(cadpessoa.nome_completo);
    				printf("Data de Nascimento: %d/%d/%d", cadpessoa.dia_nasc, cadpessoa.mes_nasc, cadpessoa.ano_nasc);
    				printf("\nE-mail: %s", cadpessoa.email);
    				printf("\nN�mero: %s", cadpessoa.numero_tel);
    				printf("\nG�nero: %s", cadpessoa.genero);
    				
    				printf("\n\n______________________________________________________________________________");
    				printf("\n| Ingresso- MUSEU ArtTech                                               "); 
    				printf("\n|                                                                       ");
    				printf("\n| Dados da Compra:                                                      ");
    				printf("\n| Tema: %s                                                               ", bilhete_evento.tema);
    				printf("\n| Data do Ingresso: %d/%d/%d", bilhete_evento.dia, bilhete_evento.mes, bilhete_evento.ano);
    				printf("          Tipo de Ingresso: %s            ", bilhete_evento.ingresso_tipo);
    				printf("\n| Quantidade de Ingressos: %.0f", bilhete_evento.quantidade_ingresso);
    				printf("           Valor Total da Compra: %.2f      ", bilhete_evento.valor_total_ingresso);
    				printf("\n| %s", sttspag);
    				printf("\n------------------------------------------------------------------------------");
    				printf("\n\nFormas de Pagamento:\n");
    				printf("\n1. Pix Copia e Cola");
    				printf("\n2. Cart�o de Cr�dito ou D�bito\n");
    				scanf("%d", &forma_de_pagamento);
    				fflush(stdin);
    				switch(forma_de_pagamento){
    					case 1:
    						printf("\nPix Copia e Cola");
    						printf("\nSua Chave:\n");
    						srand(time(NULL));
    				                for (pag_cartao.i = 0; pag_cartao.i < 50; pag_cartao.i++)
    					                pag_cartao.pix[pag_cartao.i] = rand() % 100;
    					      
    						        for (pag_cartao.i = 0; pag_cartao.i < 50; pag_cartao.i++)
    				                    printf("%d", pag_cartao.pix[pag_cartao.i]);
    				            
    				printf("\n\nPor favor, Apresente seu Ingresso Digital ou Impresso na Entrada no dia do Evento! :)");
    				printf("\n[ATEN��O]Leve o seu Comprovante de Pagamento do Ingresso Via Pix para Apresentar na Entrada!\n");
								printf("\n\n______________________________________________________________________________");
    				            printf("\n| Ingresso- MUSEU ArtTech                                               "); 
    				            printf("\n|                                                                       ");
    				            printf("\n| Dados da Compra:                                                      ");
    				            printf("\n| Tema: %s                                                               ", bilhete_evento.tema);
    				            printf("\n| Data do Ingresso: %d/%d/%d", bilhete_evento.dia, bilhete_evento.mes, bilhete_evento.ano);
    				            printf("          Tipo de Ingresso: %s            ", bilhete_evento.ingresso_tipo);
    				            printf("\n| Quantidade de Ingressos: %.0f", bilhete_evento.quantidade_ingresso);
    				            printf("           Valor Total da Compra: %.2f      ", bilhete_evento.valor_total_ingresso);
    				            printf("\n| %s", sttspag);
    				            printf("\n------------------------------------------------------------------------------");
    				printf("\n\n1. Finalizar Pagamento e Retornar ao In�cio da P�gina:");
    				scanf("%d", &sair_da_compra);
    				fflush(stdin);
    				switch(sair_da_compra){
    				    case 1:
    				        goto inicio_da_pagina;
    				    break;
    				    default:
    				        goto inicio_da_pagina;
    				    break;
						}
    					break;
    					case 2:
    						printf("\nCadastrar Cart�o:\n");
    						printf("\nDigite o Nome Completo do Titular: ");
    						scanf(" %[^\n]99s", &pag_cartao.titular);
    						fflush(stdin);
    						printf("Digite o N�mero do Cart�o (SEM PONTOS): \n");
    						printf("DIGITE A PRIMEIRA SEQU�NCIA DE 4 DIGITOS:");
    						scanf("%d", &pag_cartao.numero_cartao_sum);
    						fflush(stdin);
    						printf("DIGITE A SEGUNDA SEQU�NCIA DE 4 DIGITOS:");
    						scanf("%d", &pag_cartao.numero_cartao_sdois);
    						fflush(stdin);
    						printf("DIGITE A TERCEIRA SEQU�NCIA DE 4 DIGITOS:");
    						scanf("%d", &pag_cartao.numero_cartao_stres);
    						fflush(stdin);
    						printf("DIGITE A QUARTA SEQU�NCIA DE 4 DIGITOS:");
    						scanf("%d", &pag_cartao.numero_cartao_squatro);
    						fflush(stdin);
    						printf("Digite o C�digo de Seguran�a (CVV): ");
    						scanf("%d", &pag_cartao.cvv);
    						fflush(stdin);
    						data_de_validade:
    						printf("Digite a Data de Validade (SOMENTE N�MEROS): ");
    						printf("\nM�s: ");
    						scanf("%d", &pag_cartao.mes_validade);
    						fflush(stdin);
    						if(pag_cartao.mes_validade > 12 || pag_cartao.mes_validade <1){
    							puts(opcao_invalida);
    							goto data_de_validade;
							}
    						printf("Ano: ");
    						scanf("%d", &pag_cartao.ano_validade);
    						fflush(stdin);
    						if(pag_cartao.ano_validade < 2023){
    							puts(opcao_invalida);
    							goto data_de_validade;
							}
							printf("\nCart�o Cadastrado: ");
							printf("\nTitular: %s", pag_cartao.titular);
							printf("\nN�mero do Cart�o: %d.", pag_cartao.numero_cartao_sum);
							printf("%d.", pag_cartao.numero_cartao_sdois);
							printf("%d.", pag_cartao.numero_cartao_stres);
							printf("%d", pag_cartao.numero_cartao_squatro);
							printf("\nCVV: %d", pag_cartao.cvv);
							printf("\nValidade: %d/%d", pag_cartao.mes_validade, pag_cartao.ano_validade);
							deb_ou_cred:
							printf("\n\nSelecione a Forma de Pagamento:");
							printf("\n1. D�bito");
							printf("\n2. Cr�dito\n");
							scanf("%d", &credito_ou_debito);
							fflush(stdin);
							switch(credito_ou_debito){
								case 1:
								    printf("\nD�bito");	
								    printf("\nDigite o Valor Total do Ingresso Para Realizar o Pagamento (%.2f): ", bilhete_evento.valor_total_ingresso);
								    scanf("%f", &pag_cartao.cartao_total);
								    fflush(stdin);
								    if(pag_cartao.cartao_total < bilhete_evento.valor_total_ingresso){
								    	printf("[ERRO!] O Valor que Voc� Digitou � Menor que o Valor do Ingresso, Por favor Digite o Valor Equivalente!");
								    	goto deb_ou_cred;
									}
									if(pag_cartao.cartao_total >= bilhete_evento.valor_total_ingresso){
										strcpy(sttspag, sttspag2);
									}
									printf("\nOk! Pagamento Realizado :)");
									printf("\nPor favor, Apresente seu Ingresso Digital ou Impresso na Entrada no dia do Evento! :)\n");
									printf("\n\n______________________________________________________________________________");
    				                printf("\n| Ingresso- MUSEU ArtTech                                               "); 
    				                printf("\n|                                                                       ");
    				                printf("\n| Dados da Compra:                                                      ");
    				                printf("\n| Tema: %s                                                               ", bilhete_evento.tema);
    				                printf("\n| Data do Ingresso: %d/%d/%d", bilhete_evento.dia, bilhete_evento.mes, bilhete_evento.ano);
    				                printf("          Tipo de Ingresso: %s            ", bilhete_evento.ingresso_tipo);
    				                printf("\n| Quantidade de Ingressos: %.0f", bilhete_evento.quantidade_ingresso);
    				                printf("           Valor Total da Compra: %.2f      ", bilhete_evento.valor_total_ingresso);
    				                printf("\n| %s", sttspag);
    				                printf("\n------------------------------------------------------------------------------");
    				                printf("\n\n1. Finalizar Pagamento e Retornar ao In�cio da P�gina:");
    				                scanf("%d", &sair_da_compra);
    				                fflush(stdin);
    				                switch(sair_da_compra){
    				                	case 1:
    				                		goto inicio_da_pagina;
    				                	break;
    				                	default:
    				                		goto inicio_da_pagina;
    				                	break;
									}
								break;
								case 2:
									printf("\nCr�dito");
								    printf("\nDigite o Valor Total do Ingresso Para Realizar o Pagamento (%.2f): ", bilhete_evento.valor_total_ingresso);
								    scanf("%f", &pag_cartao.cartao_total);
								    fflush(stdin);
								    if(pag_cartao.cartao_total < bilhete_evento.valor_total_ingresso){
								    	printf("[ERRO!] O Valor que Voc� Digitou � Menor que o Valor do Ingresso, Por favor Digite o Valor Equivalente!");
								    	goto deb_ou_cred;
									}
									if(pag_cartao.cartao_total >= bilhete_evento.valor_total_ingresso){
										strcpy(sttspag, sttspag2);
									}
									printf("\nOk! Pagamento Realizado :)");
									printf("\nPor favor, Apresente seu Ingresso Digital ou Impresso na Entrada no dia do Evento! :)\n");
									printf("\n\n______________________________________________________________________________");
    				                printf("\n| Ingresso- MUSEU ArtTech                                               "); 
    				                printf("\n|                                                                       ");
    				                printf("\n| Dados da Compra:                                                      ");
    				                printf("\n| Tema: %s                                                               ", bilhete_evento.tema);
    				                printf("\n| Data do Ingresso: %d/%d/%d", bilhete_evento.dia, bilhete_evento.mes, bilhete_evento.ano);
    				                printf("          Tipo de Ingresso: %s            ", bilhete_evento.ingresso_tipo);
    				                printf("\n| Quantidade de Ingressos: %.0f", bilhete_evento.quantidade_ingresso);
    				                printf("           Valor Total da Compra: %.2f      ", bilhete_evento.valor_total_ingresso);
    				                printf("\n| %s", sttspag);
    				                printf("\n------------------------------------------------------------------------------");
    				                printf("\n\n1. Finalizar Pagamento e Retornar ao In�cio da P�gina:");
    				                scanf("%d", &sair_da_compra);
    				                fflush(stdin);
    				                switch(sair_da_compra){
    				                	case 1:
    				                		goto inicio_da_pagina;
    				                	break;
    				                	default:
    				                		goto inicio_da_pagina;
    				                	break;
									}
								break;
								default:
									goto deb_ou_cred;
								break;
							}
    					break;
    					default:
						goto finalizar_a_compra;
    		        	break;
					}
					break;
    			case 4:
    				system("cls");
    				printf("\n---VERIFICAR DISPONIBILIDADE---");
    				printf("\n-------------------------------");
    				printf("\n\nBem-vindo ao Art&tech, o museu multitem�tico que combina arte e tecnologia! Aqui voc� encontrar� uma experi�ncia �nica e imersiva. Estamos abertos todos os dias da semana, incluindo fins de semana, das 09:00h �s 18:00h.");
    				printf("\n\nNossa miss�o � oferecer um espa�o onde a arte e a tecnologia se encontram, proporcionando uma jornada fascinante pelo mundo da criatividade e inova��o. No Art&tech, voc� poder� explorar diversas exposi��es que abrangem desde pinturas cl�ssicas at� instala��es interativas e obras digitais.");
    				printf("\nGra�as ao nosso hor�rio de funcionamento estendido, voc� tem flexibilidade para visitar o museu em qualquer dia da semana. \nSeja em uma tarde tranquila de domingo ou durante a agita��o dos dias �teis, estaremos aqui para receb�-lo.");
    				printf("\nAl�m disso, nossa equipe de curadores e guias est� pronta para enriquecer a sua experi�ncia, fornecendo informa��es detalhadas sobre as exposi��es e respondendo a todas as suas perguntas. N�o perca a oportunidade de conhecer o Art&tech e mergulhar em um universo fascinante de arte e tecnologia. Esperamos v�-lo em breve!");
    				
    				printf("\n\n\n\n\n1. Retornar ao In�cio da P�gina:");
    				scanf("%d", &sair_disp);
    				fflush(stdin);
    				switch(sair_disp){
    					case 1:
    						goto inicio_da_pagina;
    					break;
    					default:
    						goto vamos_finalizar;
    					break;
    			}
    			break;
    			case 5:	
    			    system("cls");
    			    printf("\n---CONHE�A OS TEMAS DISPON�VEIS---");
    				printf("\n----------------------------------\n");
    				printf("\n100 Anos da Semana de Arte Moderna\n");
    			    printf("\n1- Obra - Abaporu");
    			    printf("\n'Abaporu' ic�nica obra da pintora brasileira Tarsila do Amaral, criada em 1928, que � amplamente considerada uma das mais importantes do movimento modernista brasileiro. Esta pintura � conhecida por seu estilo �nico e sua representa��o surrealista de uma figura feminina.");
    			    printf("\n\n2- Obra - Georgina");
    			    printf("\nA cria��o de Anita Malfatti em 1914, intitulada 'Georgina', � uma obra de arte que se destaca pela sua representa��o de uma figura feminina. A pintura retrata uma mulher com uma express�o intrigante e enigm�tica.");
    				printf("\n\n3 - Obra - Mulher de cabelos verdes");
    				printf("\nA obra 'A Mulher de Cabelos Verdes', criada por Anita Malfatti em 1915, � uma pintura que chama a aten��o por sua natureza ousada e expressiva. No centro da pintura temos a mulher com o cabelo verde, um cabelo n�o t�o tradicional para aquela �poca que torna a atmosfera da obra �nica.");
    				
    				printf("\n\n\n\n150 Anos de Santos Dumont\n");
    				printf("\n4 - Obra - 14 Bis Santos Dumont");
    				printf("\nO 14-Bis desempenhou um papel crucial na hist�ria da avia��o, marcando a primeira demonstra��o p�blica bem-sucedida de um voo em uma aeronave controlada, esempenhou um papel crucial na hist�ria da avia��o, marcando a primeira demonstra��o p�blica bem-sucedida de um voo em uma aeronave controlada.");
    				printf("\n\n5 Obra - casa de Santos Dumont");
    				printf("\n'A Encantada' era a casa de ver�o de Alberto Santos Dumont, Pai da Avia��o. Possui objetos, livros, cartas e mobili�rio, al�m de um chuveiro e uma escada com degraus em forma de raquete que s� podem ser alcan�ados com o p� direito. O local tem maquetes t�teis para pessoas com necessidades especiais e � facilmente acess�vel.");
    				printf("\n\n6 - Obra - Rel�gio a inven��o de Santos Dumont");
    				printf("\nAlberto Santos-Dumont, um pioneiro da avia��o brasileiro e uma figura chave na hist�ria da avia��o, desempenhou um papel crucial na populariza��o do rel�gio de pulso como uma pe�a de moda e funcionalidade.");
    			
    				printf("\n\n\n\nJogos Ol�mpicos de Paris 2024\n");
    				printf("\n7 - Obra - O campo de T�nis");
    				printf("\nRoland Garros Nomeado em mem�ria do aviador franc�s Roland Garros, o local tem 12 hectares de �rea e 18 quadras de saibro, entre elas a Simonne Mathieu e a Suzanne Lenglen (palco dos eventos de t�nis em Paris 2024), e a Philippe Chatrier Court (que sediar� t�nis e boxe)");
    				printf("\n\n8 - Obra - Parque dos Principes");
    				printf("\nCampo do Paris Saint-Germain, um dos clubes mais vitoriosos de Paris, o Parc des Princes receber� diversos jogos das sele��es francesas de futebol e rugby.");
    				printf("\n\n9 - Obra - Est�dio V�lodrome");
    				printf("\nCasa do Olympique de Marselha desde a constru��o do local, em 1937, o Est�dio V�lodrome j� recebeu partidas das sele��es francesas de futebol e todas as principais cometi��es organizadas em solo franc�s.");
    				
    				printf("\n\n\n\nCultura e Tradi��es Globais\n");
    				printf("\n10 Obra - Semana da Arte Moderna");
    				printf("\nImagem representando os impactos que ela causou na cultura brasileira. Isso porque os artistas envolvidos propuseram uma vis�o renovada da arte e buscaram uma atualiza��o social e art�stica do pa�s.");
    				printf("\n\n11 Obra - Diversidade cultural");
    				printf("\nObra de arte representando a diversidade cultural no Brasil abrangem uma ampla gama de express�es art�sticas que refletem a rica e variada cultura do pa�s. ");
    				printf("\n\n12 Obra - Globaliza��o");
    				printf("\nUma m�o segurando o Mundo, com as conex�es que a globaliza��o pode trazer junto com as evolu��es tecnologicas.");
    				
    				printf("\n\n\n\n\n1. Retornar ao In�cio da P�gina:");
    				scanf("%d", &sair_dos_temas);
    				fflush(stdin);
    				switch(sair_dos_temas){
    					case 1:
    						goto inicio_da_pagina;
    					break;
    					default:
    						goto vamos_finalizar;
    					break;
    			}
    			break;
    			case 6:
    				system("cls");
    				printf("\n---RESPONDER QUESTION�RIO---");
    				printf("\n----------------------------");
    				
    				printf("\n\n1. Qual � o objetivo principal do museu? (Educa��o, entretenimento, preserva��o hist�rica, etc.)\n");
    				gets(p1);
    				printf("\n\n2. Quais s�o os principais temas ou t�picos que o museu ir� cobrir?\n");
    				gets(p2);
    				printf("\n\n3. Quem � o p�blico-alvo do museu? (Crian�as, adultos, estudantes, turistas, etc.) \n");
    				gets(p3);
    				printf("\n\n4. Como ser� o layout f�sico do museu? (Layout, espa�o expositivo, �reas interativas, etc.) \n");
    				gets(p4);
    				printf("\n\n5. Que tipos de exposi��es ou artefatos o museu exibir�?\n");
    				gets(p5);
    				printf("\n\n6. Como � que o museu planeja envolver os visitantes? (Atividades interativas, aplicativos m�veis, guias de �udio, etc.)\n");
    				gets(p6);
    				printf("\n\n7. Quais tecnologias ser�o utilizadas nas exposi��es? (Realidade virtual, realidade aumentada, proje��es, etc.)\n");
    				gets(p7);
    				printf("\n\n8. Como ir� o museu educar os visitantes sobre os objetos expostos?\n");
    				gets(p8);
    				printf("\n\n9. Existem parcerias ou colabora��es potenciais que possam melhorar as ofertas do museu?\n");
    				gets(p9);
    				printf("\n\n10. Como � que o museu planeia avaliar o sucesso e a satisfa��o dos visitantes? \n");
    				gets(p10);
    				
    				printf("\n\n\nRESPOSTAS:\n");
    				
    				printf("\n1. Qual � o objetivo principal do museu? (Educa��o, entretenimento, preserva��o hist�rica, etc.)\n");
    				puts(p1);
    				printf("\n\n2. Quais s�o os principais temas ou t�picos que o museu ir� cobrir?\n");
    				puts(p2);
    				printf("\n\n3. Quem � o p�blico-alvo do museu? (Crian�as, adultos, estudantes, turistas, etc.) \n");
    				puts(p3);
    				printf("\n\n4. Como ser� o layout f�sico do museu? (Layout, espa�o expositivo, �reas interativas, etc.) \n");
    				puts(p4);
    				printf("\n\n5. Que tipos de exposi��es ou artefatos o museu exibir�?\n");
    				puts(p5);
    				printf("\n\n6. Como � que o museu planeja envolver os visitantes? (Atividades interativas, aplicativos m�veis, guias de �udio, etc.)\n");
    				puts(p6);
    				printf("\n\n7. Quais tecnologias ser�o utilizadas nas exposi��es? (Realidade virtual, realidade aumentada, proje��es, etc.)\n");
    				puts(p7);
    				printf("\n\n8. Como ir� o museu educar os visitantes sobre os objetos expostos?\n");
    				puts(p8);
    				printf("\n\n9. Existem parcerias ou colabora��es potenciais que possam melhorar as ofertas do museu?\n");
    				puts(p9);
    				printf("\n\n10. Como � que o museu planeia avaliar o sucesso e a satisfa��o dos visitantes? \n");
    				puts(p10);
    				
    				printf("\n\n\n\nEstas s�o algumas perguntas iniciais para ajud�-lo a planejar a programa��o do museu. Lembre-se de adaptar as perguntas �s necessidades e objetivos espec�ficos do seu museu.");
    				
    				printf("\n\n\n\n\n1. Retornar ao In�cio da P�gina:");
    				scanf("%d", &sair_pgt);
    				fflush(stdin);
    				switch(sair_pgt){
    					case 1:
    						goto inicio_da_pagina;
    					break;
    					default:
    						goto vamos_finalizar;
    					break;
    			}
    			break;
    			case 7:
    				goto inicio_da_pagina;
    			break;
    			default:
    				goto inicio_da_pagina;
    			break;
			}
    	break;
    	case 2:
    		goto fim_do_programa;
    	break;
    default:
    	goto inicio_da_pagina;
    break;
	}
	fim_do_programa:
	return 0;
}
