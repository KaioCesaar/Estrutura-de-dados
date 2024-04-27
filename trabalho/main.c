#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "artistas.h"

int main() {
    Artista artistas[100]; 
    int total_artistas = 0;
    int opcao;
    
    lerArtistasDoArquivo(artistas, &total_artistas);

    do {
    	setlocale(LC_ALL, "Portuguese");
        printf("\nMenu de opcoes:\n");
        printf("1. Insercao ordenada de novos artistas\n");
        printf("2. Remocao de um artista\n");
        printf("3. Edicao de um artista\n");
        printf("4. Busca binaria por um artista\n");
        printf("5. Busca sequencial por um album\n");
        printf("0. Sair\n");

        printf("Digite a opcao desejada: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: {
                Artista novoArtista;
                printf("Digite o nome do novo artista: ");
                scanf(" %[^\n]", novoArtista.nome);
                // Preencha os demais campos do novoArtista se necessário
                inserirArtistaOrdenado(artistas, &total_artistas, novoArtista);
                printf("Novo artista inserido com sucesso.\n");
                break;
            }
            case 2: {
                char nomeArtistaRemocao[100];
                printf("Digite o nome do artista a ser removido: ");
                scanf(" %[^\n]", nomeArtistaRemocao);
                removerArtista(artistas, &total_artistas, nomeArtistaRemocao);
                break;
            }
            case 3: {
            	
			    char nomeArtistaEdicao[100];
			    Artista dadosNovos; 
			    
			    printf("Digite o nome do artista a ser editado: ");
			    scanf(" %[^\n]", nomeArtistaEdicao);
			    
			    printf("Digite o novo nome do artista: ");
			    scanf(" %[^\n]", dadosNovos.nome);
			    
			    editarArtista(artistas, total_artistas, nomeArtistaEdicao, dadosNovos);
			    
			    printf("Artista '%s' atualizado com sucesso.\n", nomeArtistaEdicao);
			    break;
			}
            case 4: {
                char nomeArtistaBusca[100];
                printf("Digite o nome do artista a ser buscado: ");
                scanf(" %[^\n]", nomeArtistaBusca);
                buscarArtistaBinario(artistas, total_artistas, nomeArtistaBusca);
                break;
            }
            case 5: {
                char nomeAlbumBusca[100];
                printf("Digite o nome do album a ser buscado: ");
                scanf(" %[^\n]", nomeAlbumBusca);
                buscarAlbumSequencial(artistas, total_artistas, nomeAlbumBusca);
                break;
            }
            case 0:
                printf("Saindo do programa. Ate mais!\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }

    } while (opcao != 0);

    return 0;
}
