
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>
#include <string.h>
#include "menu.h"
#include <locale.h>
#include <stdbool.h>
    int Mainmenu (){
        setlocale(LC_ALL, "");
        int escolha;// operador que vamos utilizar no while
        do {
            escolha = 0;
            MenuP();//chamando a funçao menu principal, que vai aparecer na tela.
            printf("Escolha uma opção [1/2/3/4]\t");
            scanf("%i", &escolha);// le a opção do usuario

            switch(escolha){ //identifica a opção selecionada
                case 1://jogar
                    jogar(escolha);
                    break;

                case 2://rank
                    exec_rank(escolha);
                    break;
                case 3:
                    Sobre(escolha);
                    break;
                case 4://sair
                    sair(escolha);
                    break;
                default://opção invalida
                    system("cls");
                    printf("\n     DIGITE UMA OPÇÂO VALIDA !");
                    sleep(1);
                    system("cls");
                    break;
        }

    }while(true);
}
    void Ranking() {//função do ranking
        FILE* pt_file; // ponteiro responsavel por apontar ao arquivo log.txt
        char op_ranking[5]; // opcao (w = inserir dados / r = ler dados)
        char leitura[1000]; // vai ler oque esta escrito no arquivo
        char nome[10][100]; // nome do jogadores
        int pont[1000]; // pontuacao dos jogadores
        char tempChar[100];
        int i, tempInt;
        printf("       _______________________________________________\n\n");
        printf("       |             MENU-RANKING                    |\n\n");
        printf("       |    [1]PARA INSERIR OS JOGADORES             |\n\n");
        printf("       |    [2]VIZUALIZAR O RANKING DOS JOGADORES    |\n\n");
        printf("       |_____________________________________________|\n");
        scanf("%s", op_ranking);

    /* ARQUIVO "log.txt" DO JOGO */
        if (strcmp(op_ranking, "1")== 0) {
            system("cls");
            int n;
            int maior;int j;
            printf("\n   JOGADORES A SEREM INSERIDOS:\t");
            scanf("%d", &n);
            for (i = 0; i < n; i++) {
            system("cls");
            printf("Informe nome e pontuacao [%d](Use space):  ", i + 1);
            scanf("%s %d", &nome[i], &pont[i]);
            }
            for (i = 0; i < n - 1; i++) {
                maior = i;
                for (j = i + 1; j < n; j++){
                    if (pont[j] > pont[maior]) {
                    maior = j;

                    }
                }
                tempInt = pont[i];
                pont[i] = pont[maior];
                pont[maior] = tempInt;

                strcpy(tempChar, nome[i]);
                strcpy(nome[i], nome[maior]);
                strcpy(nome[maior], tempChar);
            }
        system("cls");
        pt_file = fopen("rankingLog.txt", "w"); // escreve no arquivo e apaga oque ja estava escrito
        fprintf(pt_file, "    -------------------------------\n" );
        fprintf(pt_file, "              TABELA\n\n");

        for (i = 0; i < n; i++) {
            fprintf(pt_file, "      TOP %d: %s com %d pontos\n\n", i + 1, nome[i], pont[i]);
        }
        fprintf(pt_file, "    -------------------------------\n" );
        printf("\n         DADOS SALVOS COM SUCESSO !\n");
        fclose(pt_file);

    }
    else if (strcmp(op_ranking, "2") == 0) {
        system("cls");
        pt_file = fopen("rankingLog.txt", "r"); // faz a leitura do arquivo

        if (pt_file == NULL) { // verifica se o arquivo existe na maquina
            printf("---> ERRO: arquivo nao existente!\n");
            system("pause");
            exit(1);
        }

        while (fgets(leitura, 1000, pt_file) != NULL) {
            printf("%s", leitura);
        }
        Sleep(1000);
    }
    else {
        system("cls");
        printf("\n---> DIGITE UMA OPCAO VALIDA !\n");
        Sleep(1000);
    }
}
    void jogar(int escolha){//função para jogar
        while(true){
            system("cls");
            printf("     _______________________________\n");
            printf("                                    \n");
            printf("               EM BREVE...          \n\n");
            printf("        (opção em desenvolvimento)  \n");
            printf("     _______________________________\n");
            printf("     -------------------------------\n\n");
            printf("     *     [1] Voltar ao menu      *\n\n");
            printf("     -------------------------------\n");
            scanf("%i", &escolha);
            if (escolha == 1){//volta pro menu
                system("cls");
                break;
            }
            else{
                system("cls");
                printf("Digite uma opção valida!\n");
                sleep(1);
                system("cls");
            }
        }
    }
    void MenuP(){ //função do menu
        system("color 0A");
        printf("___________________________________\n");
        printf("|                                 |\n");
        printf("|            JOB RUN              |\n");
        printf("|    -------------------------    |\n\n");
        printf("|           [1]JOGAR              |\n\n");
        printf("|                                 |\n");
        printf("|           [2]RANKING            |\n\n");
        printf("|                                 |\n");
        printf("|           [3]SOBRE              |\n\n");
        printf("|                                 |\n");
        printf("|           [4]SAIR               |\n\n");
        printf("|     ------------------------    |\n\n");
        printf("|         Made by : JLG²          |\n");
        printf("|_________________________________|\n\n");

    }
    void Sobre(int escolha){//função sobre
        while(true){
            system("cls");
            system("Color 0D");
            printf("---------------------------------------\n\n");
            printf("|     [1]História                     |\n\n");
            printf("|     [2]Créditos                     |\n\n");
            printf("|     [3]Voltar Ao Menu Principal     |\n\n");
            printf("---------------------------------------\n");
            scanf("%i", &escolha);
            if (escolha == 1){//exibe a história
                while(true){
                    system("cls");
                    historia();
                    Subopcao();//exibe as subopções
                    scanf("%i", &escolha);
                    if(escolha == 1){
                        system("cls");
                        break;
                    }
                    else{
                        system("cls");
                        printf("Digite uma opção valida!\n");
                        sleep(1);
                        system("cls");
                        }
                    }
                }
                    else if (escolha == 2) {
                        while(true){
                            system("cls");
                            JLG();//função que mostra nosso time
                            printf("\n\n");
                            Subopcao();//função que mostra as opções após exibir o time.
                            scanf("%i", &escolha);
                            if(escolha == 1){
                                system("cls");
                                break;
                            }
                            else{
                                system("cls");
                                printf("Digite uma opção valida!\n");
                                sleep(1);
                                system("cls");
                            }
                        }
                    }
                    else if(escolha == 3){
                        system("cls");
                        break;
                    }
                    else{
                        system("cls");
                        printf("Digite uma opção valida!\n");
                        sleep(1);
                        system("cls");
                    }
            }
    }
    void Subopcao(){//subopção q aparece no menu sobre
        printf("    -----------------------------------\n");
        printf("    *           [1]Voltar             *\n");
        printf("    -----------------------------------\n");
    }
    void JLG(){ //função para exibir o nosso time
        setlocale(LC_ALL, "");
        system("color 0E");
        printf("    ___________________________________\n\n");
        printf("    |            JLG TEAM             |\n");
        printf("    |        ------------------       |\n");
        printf("    |         GABRIEL FIDELIS         |\n\n");
        printf("    |         JOÃO PEDRO BEKER        |\n\n");
        printf("    |         LUCAS HENRIQUE          |\n\n");
        printf("    |         GABRIEL MIGLIORINI      |\n");
        printf("    |_________________________________|\n");

    }
    void exec_rank(int escolha){//executa o rank
        while(true){
            // ranking
            system("cls");
            system("color 0C");
            Ranking();
            printf("   ___________________________________________\n");
            printf("    \n   Pressione [1] para voltar ao menu principal\n");
            printf("    \n   Pressione [2] para voltar ao menu ranking\n");
            printf("   ____________________________________________\n");
            scanf("%d", &escolha);
            if (escolha == 1) {
                system("cls");
                break;
            }
            else if (escolha == 2) {
                system("cls");
            }
            else {
                system("cls");
                printf("Digite uma opção valida!\n");
                sleep(2);
            }
        }
    }
    void sair(int escolha){
        while(escolha != 2){
            system("cls");
            printf("\nDeseja mesmo sair ? [1 para sim/2 para nao]\n\n");// verifica se o usuario realmente quer sair
            scanf("%i", &escolha);
            if (escolha == 1 ){ //caso seja 1, finalizamos o programa
                system("cls");
                system("color 0C");
                printf("\nZé precisava de você...\n");
                sleep(3);
                exit(0);
            }
            else if (escolha == 2) { //voltamos para o inicio ou seja, o menu.
                system("cls");

            }
            else{
                system("cls");
                printf("Digite uma opção valida!\n");
                sleep(1);
                system("cls");
            }
        }
    }
    void historia(){
        printf("       ----------------------------------------------------------------------------\n");
        printf("\t Zé é um funcionário de uma loja de tecnologia, certo dia ele recebe a\n");
        printf("\t oportunidade de sua vida, uma promoção para gerente em seu trabalho.\n");
        printf("\t Porém, para a infelicidade de Zé, a inveja reina na empresa em que ele\n ");
        printf("\t trabalha , e um funcionário chamado Ricardo, contratou sabotadores para\n  ");
        printf("\t impedir que Zé chegue ao trabalho no dia de sua promoção, assim à perdendo.\n ");
        printf("\t Zé não pode deixar essa promoção escapar, ajude-o !\n");
        printf("        ----------------------------------------------------------------------------\n\n");


    }
