#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>


typedef struct musicas{
    char Artista[100];

    char Musica[100];

    int idMusica;

    struct musicas *anteriorMusica;

    struct musicas *proximaMusica;

} musicas;

void cleanCaractere () {
    int limp; 
    while ((limp = getchar()) != '\n' && limp != EOF);
}

void iniciarLista(musicas listaMusicas[], int *posicaoMusica) {
    FILE *arquivo = fopen("musicas.txt", "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.");
        return;
    }

    char linhaTxt[200];
    while (fgets(linhaTxt, sizeof(linhaTxt), arquivo)) {
        listaMusicas[*posicaoMusica].idMusica = *posicaoMusica;
        char *separador = strtok(linhaTxt, ";");
        if (separador != NULL) {
            strcpy(listaMusicas[*posicaoMusica].Artista, separador);
            separador = strtok(NULL, "\n");
            if (separador != NULL) {
                strcpy(listaMusicas[*posicaoMusica].Musica, separador);
                (*posicaoMusica)++;
            }

        }
    }

    fclose(arquivo);
}


void limparString(char *str) {
    char *end;

    while (isspace((unsigned char)*str)) {
        str++;
    }
    if (*str == 0) { 
        return;
    }

    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) {
        end--;
    }
    *(end + 1) = '\0';
}

void reescreverLista(musicas listaMusicas[], int quantidadeMusicas) {
    int primeiraMusica = 0;

    FILE *arquivo = fopen("musicas.txt", "w+");

    if(arquivo == NULL) {
        printf("Erro ao abrir o arquivo.");
        exit(1);
    }

    fseek(arquivo, 0, SEEK_SET);

    for(int cont = 0; cont < quantidadeMusicas; cont++) {

        limparString(listaMusicas[cont].Artista);
        limparString(listaMusicas[cont].Musica);

        if((cont == 0)) {
            listaMusicas[cont].anteriorMusica = &listaMusicas[quantidadeMusicas-1]; 
            primeiraMusica = cont;
        } else { 
            listaMusicas[cont].anteriorMusica = &listaMusicas[cont-1];
        }

        if(cont == quantidadeMusicas-1) {
            listaMusicas[cont].proximaMusica = &listaMusicas[primeiraMusica]; 
        } else { 
            listaMusicas[cont].proximaMusica = &listaMusicas[cont+1];
        }

        fprintf(arquivo, "%s", listaMusicas[cont].Artista);
        fprintf(arquivo, "%s", ";");
        fprintf(arquivo, "%s\n", listaMusicas[cont].Musica);
    } 

    fclose(arquivo);
} 

void exibirPlaylistCadastro (musicas listaMusicas[], int quantidadeMusicas) {
    for(int cont = 0; cont < quantidadeMusicas; cont++) {
            printf("\n%d. %s, %s",cont+1, listaMusicas[cont].Artista, listaMusicas[cont].Musica);
        }
    }

void inserirMusica(musicas listaMusicas[], int *posicaoMusica) {

    printf("\nDigite o nome do artista: ");
    fgets(listaMusicas[*posicaoMusica].Artista, sizeof(listaMusicas[*posicaoMusica].Artista), stdin);
    listaMusicas[*posicaoMusica].Artista[strcspn(listaMusicas[*posicaoMusica].Artista, "\n")] = '\0';

    printf("\nDigite o nome da música: ");
    fgets(listaMusicas[*posicaoMusica].Musica, sizeof(listaMusicas[*posicaoMusica].Musica), stdin);
    listaMusicas[*posicaoMusica].Musica[strcspn(listaMusicas[*posicaoMusica].Musica, "\n")] = '\0';

    printf("\nMúsica inserida com sucesso.");

    (*posicaoMusica)++;
}

void removerMusica(musicas listaMusicas[], int *posicaoMusica, char nomeMusica[100]) {
    int indice = -1;

    for(int c = 0; c < *posicaoMusica; c++) {
        if(strcmp(nomeMusica, listaMusicas[c].Musica) == 0) {
            indice = c;
            break;
        }
    }

    if (indice != -1) {
        for (int i = indice; i < *posicaoMusica - 1; i++) {
            listaMusicas[i] = listaMusicas[i + 1];
        }
        (*posicaoMusica)--;

        reescreverLista(listaMusicas, *posicaoMusica);
        
        printf("Musica removida com sucesso.\n");
    } else {
        printf("Musica não encontrada.\n");
    }
}

void buscarMusica(musicas listaMusicas[], int quanMusicas, char nomeMusica[200]) {

    int encontro = 0;

    for(int cont = 0; cont < quanMusicas; cont++) {
        if(strcmp(listaMusicas[cont].Musica, nomeMusica) == 0) { 
            printf("\nMusica encontrada ");
            printf("\nArtista: %s", listaMusicas[cont].Artista);
            printf("\nMúsica: %s", listaMusicas[cont].Musica);

            encontro = 1;
        }
    }

    if(encontro == 0) {
        printf("\nNenhuma música encontrada.");
    }
}

int compararMusicas(const void *a, const void *b) {
    musicas *musicaA = (musicas *)a;
    musicas *musicaB = (musicas *)b;
    return strcasecmp(musicaA->Musica, musicaB->Musica);
}

void mostrarPlaylistPorOrdemDeCadastro(musicas listaMusicas[], int quantidadeMusicas) {

    musicas listaMusicasCopia[500];

    for(int cont = 0; cont < quantidadeMusicas; cont++) {
        strcpy( listaMusicasCopia[cont].Artista, listaMusicas[cont].Artista);
        strcpy( listaMusicasCopia[cont].Musica, listaMusicas[cont].Musica);
        listaMusicasCopia[cont].idMusica = listaMusicas[cont].idMusica;
        listaMusicasCopia[cont].anteriorMusica = listaMusicas[cont].anteriorMusica;
        listaMusicasCopia[cont].proximaMusica = listaMusicas[cont].proximaMusica;
    }

    qsort(listaMusicasCopia, quantidadeMusicas, sizeof(musicas), compararMusicas);

    printf("\nPlaylist ordenada pelo nome das músicas:");
    for (int cont = 0; cont < quantidadeMusicas; cont++) {
        printf("\n%d. %s, %s", cont+1, listaMusicasCopia[cont].Artista, listaMusicasCopia[cont].Musica);
    }
}

void proximaMusica(musicas **musicaAtual) {
    *musicaAtual = (*musicaAtual)->proximaMusica;
     printf("\nPróxima música: %s - %s\n", (*musicaAtual)->Artista, (*musicaAtual)->Musica);
}

void musicaAnterior(musicas **musicaAtual) {
    *musicaAtual = (*musicaAtual)->anteriorMusica;
     printf("\nMúsica anterior: %s - %s\n", (*musicaAtual)->Artista, (*musicaAtual)->Musica);
}

int main () {
    musicas listaMusicas[500];
    int posicaoMusica = 0;
    int esc;
    char nomeMusica[100];
    int resp = 0;
    musicas *musicaAtual = NULL;

    iniciarLista(listaMusicas, &posicaoMusica);
    reescreverLista(listaMusicas, posicaoMusica);

    if (posicaoMusica > 0) {
        musicaAtual = &listaMusicas[0];
    }

    do{
        system("clear");

        if (musicaAtual != NULL) {
            printf("\n ------> MÚSICA ATUAL <------ ");
            printf("\n%s de %s", musicaAtual->Musica, musicaAtual->Artista);
        }

        printf("\n------> PLAYLISTMENU <------");
        printf("\n (1) Mostrar a playlist na ordem em que as músicas foram adicionadas \n");
        printf(" (2) Monstrar playlist ordenada pelo nome das músicas\n");
        printf(" (3) Adicionar nova música\n");
        printf(" (4) Remover uma musica\n");
        printf(" (5) Buscar por uma musica\n");
        printf(" (6) Avançar para próxima música\n");
        printf(" (7) Retornar a música anterior\n");
        printf(" (8) Encerrar\n");
        printf("------ FIM ------");
        printf("\nO que deseja fazer? ");
        scanf("%d", &esc);

        switch(esc) {
            case 1:
                mostrarPlaylistPorOrdemDeCadastro(listaMusicas, posicaoMusica);
            break;

            case 2:
                mostrarPlaylistPorOrdemDeCadastro(listaMusicas, posicaoMusica);
            break;

            case 3:
                cleanCaractere();
                
                inserirMusica(listaMusicas, &posicaoMusica);
                
                reescreverLista(listaMusicas, posicaoMusica);
                
            break;

            case 4:
                cleanCaractere();
                
                printf("Nome da música que você deseja remover: ");
                
                fgets(nomeMusica, sizeof(nomeMusica), stdin);
                
                nomeMusica[strcspn(nomeMusica, "\n")] = '\0';
                
                removerMusica(listaMusicas, &posicaoMusica, nomeMusica);
            break;

            case 5:
                cleanCaractere();
                
                printf("Digite o nome da música: ");
                
                fgets(nomeMusica, sizeof(nomeMusica), stdin);
                
                nomeMusica[strcspn(nomeMusica, "\n")] = '\0';
                
                buscarMusica(listaMusicas, posicaoMusica, nomeMusica);
                
            break;

            case 6:
                proximaMusica(&musicaAtual);
            break;

            case 7:
                musicaAnterior(&musicaAtual);
            break;

            case 8:
                printf("Muito Obrigado por Utilizar o PLAYLISTMENU!");
            break;

            default:
                printf("Comando incorreto");
            break;
        }

        if(esc != 8) {
            printf("\n\nVocê quer realizar outra interação? SIM [0] / NÃO [1] ");
            
            scanf("%d", &resp);
            
        } else {
            resp = 1;
        }
    } while (resp != 1);

    return 0; 
}
