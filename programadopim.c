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
	char entrada_cheia[17]="ENTRADA INTEIRA", meia_entrada[14]="MEIA ENTRADA", insencao[10]="INSENÇÃO";
	char cem_anos_da_sem[40]="100 Anos da Semana de Arte Moderna", cento_e_cinquenta_anos[40]="150 Anos de Santos Dumont", jogos_olimpicos[40]="Jogos Olímpicos de Paris 2024", cultura_e_trad[50]="Cultura e Tradições Globais";
	char opcao_invalida[85]="\n[ERRO!] Ops! Parece que Voce Digitou uma Data Inválida, Selecione uma Data Válida.\n";
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
	printf("\nUm museu que combina Arte e Tecnologia para proporcionar uma experiência única.");
	printf("\nAqui você mergulhará em um mundo onde a criatividade encontra a inovação, e a beleza se funde com a tecnologia de ponta.");
	printf("\nNossas galerias são um santuário de expressão artística, onde obras de arte tradicionais ganham vida com elementos interativos e digitais.");
	printf("\nDe pinturas clássicas a instalações modernas, cada peça é cuidadosamente selecionada para encantar seus sentidos e desafiar sua percepção.");
	
	menu_principal:
	printf("\n\n\n\n\n\n\n---------------------------------------------------------------------");
	printf("\n[ATENÇÃO] Digite o Número Correspondente a Opção Que Deseja Acessar.");
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
    		printf("\n5. Conheça os Temas Disponíveis");
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
    				printf("\n(ATENÇÃO: Os Dados Informados são de sua Responsabilidade! Por favor Digite Corretamente.)\n");
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
    				printf("Digite seu Número para Contato (xx)xxxxx-xxxx:");
    				gets(cadpessoa.numero_tel);
    				fflush(stdin);
    				printf("\nInforme Seu Gênero: ");
    				gets(cadpessoa.genero);
    				fflush(stdin);
    				printf("\nSeus Dados Cadastrados:\n");
    				printf("Nome Completo: ");
    				puts(cadpessoa.nome_completo);
    				printf("Data de Nascimento: %d/%d/%d", cadpessoa.dia_nasc, cadpessoa.mes_nasc, cadpessoa.ano_nasc);
    				printf("\nE-mail: %s", cadpessoa.email);
    				printf("\nNúmero: %s", cadpessoa.numero_tel);
    				printf("\nGênero: %s", cadpessoa.genero);
    				printf("\nSeu Cadastro foi Finalizado! Suas Informações foram Salvas =)\n");
    				vamos_finalizar:
    				printf("\n1. Finalizar Cadastro e Retornar ao Início da Página:");
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
    				printf("\n(ATENÇÃO: Para Comprar um Bilhete, Primeiro é Necessario ter um Cadastro.\n");
    				printf("\nSe Você Ainda nao Possui Um Cadastro, Faça um em 'Menu Principal'/'Fazer Cadastro')");
    				printf("\nVocê só Conseguirá Comprar Ingressos Para um Tema de  Cada Vez!");
    				printf("\n\nEscolher Evento:\n");
    				printf("\n1. 100 Anos da Semana de Arte Moderna");
    				printf("\n2. 150 Anos de Santos Dumont");
    				printf("\n3. Jogos Olímpicos de Paris 2024");
    				printf("\n4. Cultura e Tradições Globais\n");
    				printf("\n5. VOLTAR AO INÍCIO DA PÁGINA\n");
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
							printf("\n(ATENÇÃO: OS IGRESSOS SÃO VÁLIDOS DURANTE TODO O DIA QUE VOCE DEFINIU, SEM UM HORÁRIO ESPECÍFICO PARA ENTRAR.");
							printf("\nVocê Pode Consultar o Horário Das Esposições no 'Menu Principal' na Opção 'Verificar Disponibilidade.')\n");
							printf("\nDefina o Tipo de Ingresso que Irá Comprar, Lembrando que só Pode Comprar um Tipo de Cada Vez:\n");
							printf("\n1. Inteira- 30,00");
							printf("\n2. Meia Entrada- 15,00");
							printf("\n3. Isenção- 00,00\n");
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
									printf("\nDIGITE 1 PARA RETORNAR AO INÍCIO DA PÁGINA:");
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
									printf("\nDIGITE 1 PARA RETORNAR AO INÍCIO DA PÁGINA:");
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
									printf("\nISENÇÃO\n");
									strcpy(bilhete_evento.ingresso_tipo, insencao);
									printf("\nDigite a Quantidade de Entradas que Deseja:\n");
									scanf("%f", &bilhete_evento.quantidade_ingresso);
									fflush(stdin);
									bilhete_evento.valor_total_ingresso = bilhete_evento.quantidade_ingresso*0;
									printf("Valor total: ");
									printf("%.2f\n", bilhete_evento.valor_total_ingresso);
									printf("\nDIGITE 1 PARA RETORNAR AO INÍCIO DA PÁGINA:");
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
    						printf("\n(ATENÇÃO: OS IGRESSOS SÃO VÁLIDOS DURANTE TODO O DIA QUE VOCE DEFINIU, SEM UM HORÁRIO ESPECÍFICO PARA ENTRAR.");
							printf("\nVocê Pode Consultar o Horário Das Esposições no 'Menu Principal' na Opção 'Verificar Disponibilidade.')\n");
							printf("\nDefina o Tipo de Ingresso que Irá Comprar, Lembrando que só Pode Comprar um Tipo de Cada Vez:\n");
							printf("\n1. Inteira- 30,00");
							printf("\n2. Meia Entrada- 15,00");
							printf("\n3. Isenção- 00,00\n");
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
									printf("\nDIGITE 1 PARA RETORNAR AO INÍCIO DA PÁGINA:");
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
									printf("\nDIGITE 1 PARA RETORNAR AO INÍCIO DA PÁGINA:");
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
									printf("\nISENÇÃO\n");
									strcpy(bilhete_evento.ingresso_tipo, insencao);
									printf("\nDigite a Quantidade de Entradas que Deseja:\n");
									scanf("%f", &bilhete_evento.quantidade_ingresso);
									fflush(stdin);
									bilhete_evento.valor_total_ingresso = bilhete_evento.quantidade_ingresso*0;
									printf("Valor total: ");
									printf("%.2f\n", bilhete_evento.valor_total_ingresso);
									printf("\nDIGITE 1 PARA RETORNAR AO INÍCIO DA PÁGINA:");
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
    						printf("\nJOGOS OLÍMPICOS DE PARIS 2024");
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
							printf("\n(ATENÇÃO: OS IGRESSOS SÃO VÁLIDOS DURANTE TODO O DIA QUE VOCE DEFINIU, SEM UM HORÁRIO ESPECÍFICO PARA ENTRAR.");
							printf("\nVocê Pode Consultar o Horário Das Esposições no 'Menu Principal' na Opção 'Verificar Disponibilidade.')\n");
							printf("\nDefina o Tipo de Ingresso que Irá Comprar, Lembrando que só Pode Comprar um Tipo de Cada Vez:\n");
							printf("\n1. Inteira- 30,00");
							printf("\n2. Meia Entrada- 15,00");
							printf("\n3. Isenção- 00,00\n");
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
									printf("\nDIGITE 1 PARA RETORNAR AO INÍCIO DA PÁGINA:");
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
									printf("\nDIGITE 1 PARA RETORNAR AO INÍCIO DA PÁGINA:");
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
									printf("\nISENÇÃO\n");
									strcpy(bilhete_evento.ingresso_tipo, insencao);
									printf("\nDigite a Quantidade de Entradas que Deseja:\n");
									scanf("%f", &bilhete_evento.quantidade_ingresso);
									fflush(stdin);
									bilhete_evento.valor_total_ingresso = bilhete_evento.quantidade_ingresso*0;
									printf("Valor total: ");
									printf("%.2f\n", bilhete_evento.valor_total_ingresso);
									printf("\nDIGITE 1 PARA RETORNAR AO INÍCIO DA PÁGINA:");
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
    						printf("\nCULTURA E TRADIÇÕES GLOBAIS");
					        if(finalizar_cadastro != 1){
    					    goto inicio_da_pagina;
					        }
    						cultura:
    						printf("\nCULTURA E TRADIÇÕES GLOBAIS");
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
							printf("\n(ATENÇÃO: OS IGRESSOS SÃO VÁLIDOS DURANTE TODO O DIA QUE VOCE DEFINIU, SEM UM HORÁRIO ESPECÍFICO PARA ENTRAR.");
							printf("\nVocê Pode Consultar o Horário Das Esposições no 'Menu Principal' na Opção 'Verificar Disponibilidade.')\n");
							printf("\nDefina o Tipo de Ingresso que Irá Comprar, Lembrando que só Pode Comprar um Tipo de Cada Vez:\n");
							printf("\n1. Inteira- 30,00");
							printf("\n2. Meia Entrada- 15,00");
							printf("\n3. Isenção- 00,00\n");
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
									printf("\nDIGITE 1 PARA RETORNAR AO INÍCIO DA PÁGINA:");
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
									printf("\nDIGITE 1 PARA RETORNAR AO INÍCIO DA PÁGINA:");
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
									printf("\nISENÇÃO\n");
									strcpy(bilhete_evento.ingresso_tipo, insencao);
									printf("\nDigite a Quantidade de Entradas que Deseja:\n");
									scanf("%f", &bilhete_evento.quantidade_ingresso);
									fflush(stdin);
									bilhete_evento.valor_total_ingresso = bilhete_evento.quantidade_ingresso*0;
									printf("Valor total: ");
									printf("%.2f\n", bilhete_evento.valor_total_ingresso);
									printf("\nDIGITE 1 PARA RETORNAR AO INÍCIO DA PÁGINA:");
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
    				printf("\nNúmero: %s", cadpessoa.numero_tel);
    				printf("\nGênero: %s", cadpessoa.genero);
    				
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
    				printf("\n2. Cartão de Crédito ou Débito\n");
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
    				printf("\n[ATENÇÃO]Leve o seu Comprovante de Pagamento do Ingresso Via Pix para Apresentar na Entrada!\n");
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
    				printf("\n\n1. Finalizar Pagamento e Retornar ao Início da Página:");
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
    						printf("\nCadastrar Cartão:\n");
    						printf("\nDigite o Nome Completo do Titular: ");
    						scanf(" %[^\n]99s", &pag_cartao.titular);
    						fflush(stdin);
    						printf("Digite o Número do Cartão (SEM PONTOS): \n");
    						printf("DIGITE A PRIMEIRA SEQUÊNCIA DE 4 DIGITOS:");
    						scanf("%d", &pag_cartao.numero_cartao_sum);
    						fflush(stdin);
    						printf("DIGITE A SEGUNDA SEQUÊNCIA DE 4 DIGITOS:");
    						scanf("%d", &pag_cartao.numero_cartao_sdois);
    						fflush(stdin);
    						printf("DIGITE A TERCEIRA SEQUÊNCIA DE 4 DIGITOS:");
    						scanf("%d", &pag_cartao.numero_cartao_stres);
    						fflush(stdin);
    						printf("DIGITE A QUARTA SEQUÊNCIA DE 4 DIGITOS:");
    						scanf("%d", &pag_cartao.numero_cartao_squatro);
    						fflush(stdin);
    						printf("Digite o Código de Segurança (CVV): ");
    						scanf("%d", &pag_cartao.cvv);
    						fflush(stdin);
    						data_de_validade:
    						printf("Digite a Data de Validade (SOMENTE NÚMEROS): ");
    						printf("\nMês: ");
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
							printf("\nCartão Cadastrado: ");
							printf("\nTitular: %s", pag_cartao.titular);
							printf("\nNúmero do Cartão: %d.", pag_cartao.numero_cartao_sum);
							printf("%d.", pag_cartao.numero_cartao_sdois);
							printf("%d.", pag_cartao.numero_cartao_stres);
							printf("%d", pag_cartao.numero_cartao_squatro);
							printf("\nCVV: %d", pag_cartao.cvv);
							printf("\nValidade: %d/%d", pag_cartao.mes_validade, pag_cartao.ano_validade);
							deb_ou_cred:
							printf("\n\nSelecione a Forma de Pagamento:");
							printf("\n1. Débito");
							printf("\n2. Crédito\n");
							scanf("%d", &credito_ou_debito);
							fflush(stdin);
							switch(credito_ou_debito){
								case 1:
								    printf("\nDébito");	
								    printf("\nDigite o Valor Total do Ingresso Para Realizar o Pagamento (%.2f): ", bilhete_evento.valor_total_ingresso);
								    scanf("%f", &pag_cartao.cartao_total);
								    fflush(stdin);
								    if(pag_cartao.cartao_total < bilhete_evento.valor_total_ingresso){
								    	printf("[ERRO!] O Valor que Você Digitou é Menor que o Valor do Ingresso, Por favor Digite o Valor Equivalente!");
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
    				                printf("\n\n1. Finalizar Pagamento e Retornar ao Início da Página:");
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
									printf("\nCrédito");
								    printf("\nDigite o Valor Total do Ingresso Para Realizar o Pagamento (%.2f): ", bilhete_evento.valor_total_ingresso);
								    scanf("%f", &pag_cartao.cartao_total);
								    fflush(stdin);
								    if(pag_cartao.cartao_total < bilhete_evento.valor_total_ingresso){
								    	printf("[ERRO!] O Valor que Você Digitou é Menor que o Valor do Ingresso, Por favor Digite o Valor Equivalente!");
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
    				                printf("\n\n1. Finalizar Pagamento e Retornar ao Início da Página:");
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
    				printf("\n\nBem-vindo ao Art&tech, o museu multitemático que combina arte e tecnologia! Aqui você encontrará uma experiência única e imersiva. Estamos abertos todos os dias da semana, incluindo fins de semana, das 09:00h às 18:00h.");
    				printf("\n\nNossa missão é oferecer um espaço onde a arte e a tecnologia se encontram, proporcionando uma jornada fascinante pelo mundo da criatividade e inovação. No Art&tech, você poderá explorar diversas exposições que abrangem desde pinturas clássicas até instalações interativas e obras digitais.");
    				printf("\nGraças ao nosso horário de funcionamento estendido, você tem flexibilidade para visitar o museu em qualquer dia da semana. \nSeja em uma tarde tranquila de domingo ou durante a agitação dos dias úteis, estaremos aqui para recebê-lo.");
    				printf("\nAlém disso, nossa equipe de curadores e guias está pronta para enriquecer a sua experiência, fornecendo informações detalhadas sobre as exposições e respondendo a todas as suas perguntas. Não perca a oportunidade de conhecer o Art&tech e mergulhar em um universo fascinante de arte e tecnologia. Esperamos vê-lo em breve!");
    				
    				printf("\n\n\n\n\n1. Retornar ao Início da Página:");
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
    			    printf("\n---CONHEÇA OS TEMAS DISPONÍVEIS---");
    				printf("\n----------------------------------\n");
    				printf("\n100 Anos da Semana de Arte Moderna\n");
    			    printf("\n1- Obra - Abaporu");
    			    printf("\n'Abaporu' icônica obra da pintora brasileira Tarsila do Amaral, criada em 1928, que é amplamente considerada uma das mais importantes do movimento modernista brasileiro. Esta pintura é conhecida por seu estilo único e sua representação surrealista de uma figura feminina.");
    			    printf("\n\n2- Obra - Georgina");
    			    printf("\nA criação de Anita Malfatti em 1914, intitulada 'Georgina', é uma obra de arte que se destaca pela sua representação de uma figura feminina. A pintura retrata uma mulher com uma expressão intrigante e enigmática.");
    				printf("\n\n3 - Obra - Mulher de cabelos verdes");
    				printf("\nA obra 'A Mulher de Cabelos Verdes', criada por Anita Malfatti em 1915, é uma pintura que chama a atenção por sua natureza ousada e expressiva. No centro da pintura temos a mulher com o cabelo verde, um cabelo não tão tradicional para aquela época que torna a atmosfera da obra única.");
    				
    				printf("\n\n\n\n150 Anos de Santos Dumont\n");
    				printf("\n4 - Obra - 14 Bis Santos Dumont");
    				printf("\nO 14-Bis desempenhou um papel crucial na história da aviação, marcando a primeira demonstração pública bem-sucedida de um voo em uma aeronave controlada, esempenhou um papel crucial na história da aviação, marcando a primeira demonstração pública bem-sucedida de um voo em uma aeronave controlada.");
    				printf("\n\n5 Obra - casa de Santos Dumont");
    				printf("\n'A Encantada' era a casa de verão de Alberto Santos Dumont, Pai da Aviação. Possui objetos, livros, cartas e mobiliário, além de um chuveiro e uma escada com degraus em forma de raquete que só podem ser alcançados com o pé direito. O local tem maquetes táteis para pessoas com necessidades especiais e é facilmente acessível.");
    				printf("\n\n6 - Obra - Relógio a invenção de Santos Dumont");
    				printf("\nAlberto Santos-Dumont, um pioneiro da aviação brasileiro e uma figura chave na história da aviação, desempenhou um papel crucial na popularização do relógio de pulso como uma peça de moda e funcionalidade.");
    			
    				printf("\n\n\n\nJogos Olímpicos de Paris 2024\n");
    				printf("\n7 - Obra - O campo de Tênis");
    				printf("\nRoland Garros Nomeado em memória do aviador francês Roland Garros, o local tem 12 hectares de área e 18 quadras de saibro, entre elas a Simonne Mathieu e a Suzanne Lenglen (palco dos eventos de tênis em Paris 2024), e a Philippe Chatrier Court (que sediará tênis e boxe)");
    				printf("\n\n8 - Obra - Parque dos Principes");
    				printf("\nCampo do Paris Saint-Germain, um dos clubes mais vitoriosos de Paris, o Parc des Princes receberá diversos jogos das seleções francesas de futebol e rugby.");
    				printf("\n\n9 - Obra - Estádio Vélodrome");
    				printf("\nCasa do Olympique de Marselha desde a construção do local, em 1937, o Estádio Vélodrome já recebeu partidas das seleções francesas de futebol e todas as principais cometições organizadas em solo francês.");
    				
    				printf("\n\n\n\nCultura e Tradições Globais\n");
    				printf("\n10 Obra - Semana da Arte Moderna");
    				printf("\nImagem representando os impactos que ela causou na cultura brasileira. Isso porque os artistas envolvidos propuseram uma visão renovada da arte e buscaram uma atualização social e artística do país.");
    				printf("\n\n11 Obra - Diversidade cultural");
    				printf("\nObra de arte representando a diversidade cultural no Brasil abrangem uma ampla gama de expressões artísticas que refletem a rica e variada cultura do país. ");
    				printf("\n\n12 Obra - Globalização");
    				printf("\nUma mão segurando o Mundo, com as conexões que a globalização pode trazer junto com as evoluções tecnologicas.");
    				
    				printf("\n\n\n\n\n1. Retornar ao Início da Página:");
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
    				printf("\n---RESPONDER QUESTIONÁRIO---");
    				printf("\n----------------------------");
    				
    				printf("\n\n1. Qual é o objetivo principal do museu? (Educação, entretenimento, preservação histórica, etc.)\n");
    				gets(p1);
    				printf("\n\n2. Quais são os principais temas ou tópicos que o museu irá cobrir?\n");
    				gets(p2);
    				printf("\n\n3. Quem é o público-alvo do museu? (Crianças, adultos, estudantes, turistas, etc.) \n");
    				gets(p3);
    				printf("\n\n4. Como será o layout físico do museu? (Layout, espaço expositivo, áreas interativas, etc.) \n");
    				gets(p4);
    				printf("\n\n5. Que tipos de exposições ou artefatos o museu exibirá?\n");
    				gets(p5);
    				printf("\n\n6. Como é que o museu planeja envolver os visitantes? (Atividades interativas, aplicativos móveis, guias de áudio, etc.)\n");
    				gets(p6);
    				printf("\n\n7. Quais tecnologias serão utilizadas nas exposições? (Realidade virtual, realidade aumentada, projeções, etc.)\n");
    				gets(p7);
    				printf("\n\n8. Como irá o museu educar os visitantes sobre os objetos expostos?\n");
    				gets(p8);
    				printf("\n\n9. Existem parcerias ou colaborações potenciais que possam melhorar as ofertas do museu?\n");
    				gets(p9);
    				printf("\n\n10. Como é que o museu planeia avaliar o sucesso e a satisfação dos visitantes? \n");
    				gets(p10);
    				
    				printf("\n\n\nRESPOSTAS:\n");
    				
    				printf("\n1. Qual é o objetivo principal do museu? (Educação, entretenimento, preservação histórica, etc.)\n");
    				puts(p1);
    				printf("\n\n2. Quais são os principais temas ou tópicos que o museu irá cobrir?\n");
    				puts(p2);
    				printf("\n\n3. Quem é o público-alvo do museu? (Crianças, adultos, estudantes, turistas, etc.) \n");
    				puts(p3);
    				printf("\n\n4. Como será o layout físico do museu? (Layout, espaço expositivo, áreas interativas, etc.) \n");
    				puts(p4);
    				printf("\n\n5. Que tipos de exposições ou artefatos o museu exibirá?\n");
    				puts(p5);
    				printf("\n\n6. Como é que o museu planeja envolver os visitantes? (Atividades interativas, aplicativos móveis, guias de áudio, etc.)\n");
    				puts(p6);
    				printf("\n\n7. Quais tecnologias serão utilizadas nas exposições? (Realidade virtual, realidade aumentada, projeções, etc.)\n");
    				puts(p7);
    				printf("\n\n8. Como irá o museu educar os visitantes sobre os objetos expostos?\n");
    				puts(p8);
    				printf("\n\n9. Existem parcerias ou colaborações potenciais que possam melhorar as ofertas do museu?\n");
    				puts(p9);
    				printf("\n\n10. Como é que o museu planeia avaliar o sucesso e a satisfação dos visitantes? \n");
    				puts(p10);
    				
    				printf("\n\n\n\nEstas são algumas perguntas iniciais para ajudá-lo a planejar a programação do museu. Lembre-se de adaptar as perguntas às necessidades e objetivos específicos do seu museu.");
    				
    				printf("\n\n\n\n\n1. Retornar ao Início da Página:");
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
