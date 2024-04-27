#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "artistas.h"

void lerArtistasDoArquivo(Artista artistas[], int *total_artistas) {
    FILE *file = fopen("artistas.txt", "r");
    if (file == NULL) {
        printf("Falha ao abrir o arquivo.\n");
        return;
    }
    
    Artista artista;
    while (fscanf(file, "%[^;];%[^;];%[^;];%d\n", artista.nome, artista.genero, artista.local, &artista.qtd_albuns) != EOF) {
        for (int i = 0; i < artista.qtd_albuns; i++) {
            if (i < artista.qtd_albuns - 1) {
                fscanf(file, "%[^,],", artista.albuns[i]);
            } else {
                fscanf(file, "%[^\n]\n", artista.albuns[i]);
            }
        }
        artistas[*total_artistas] = artista;
        (*total_artistas)++;
    }
    fclose(file);
}

void inserirArtistaOrdenado(Artista artistas[], int *total_artistas, Artista novoArtista) {
    int i = *total_artistas - 1;
    while (i >= 0 && strcmp(artistas[i].nome, novoArtista.nome) > 0) {
        artistas[i + 1] = artistas[i];
        i--;
    }
    artistas[i + 1] = novoArtista;
    (*total_artistas)++;
}

int encontrarArtista(Artista artistas[], int total_artistas, char *nomeArtista) {
    for (int i = 0; i < total_artistas; i++) {
        if (strcmp(artistas[i].nome, nomeArtista) == 0) {
            return i;
        }
    }
    return -1;
}

void removerArtista(Artista artistas[], int *total_artistas, char *nomeArtista) {
    int posicao = encontrarArtista(artistas, *total_artistas, nomeArtista);
    if (posicao == -1) {
        printf("Artista '%s' nao encontrado.\n", nomeArtista);
        return;
    }

    for (int i = posicao; i < *total_artistas - 1; i++) {
        artistas[i] = artistas[i + 1];
    }
    (*total_artistas)--;
}

void editarArtista(Artista artistas[], int total_artistas, char *nomeArtista, Artista dadosNovos) {
    int posicao = encontrarArtista(artistas, total_artistas, nomeArtista);
    if (posicao == -1) {
        printf("Artista '%s' nao encontrado.\n", nomeArtista);
        return;
    }
    artistas[posicao] = dadosNovos;
}

void buscarArtistaBinario(Artista artistas[], int total_artistas, char *nomeArtista) {
    int inicio = 0, fim = total_artistas - 1, meio, cmp;
    while (inicio <= fim) {
        meio = inicio + (fim - inicio) / 2;
        cmp = strcmp(artistas[meio].nome, nomeArtista);
        if (cmp == 0) {
            printf("Artista '%s' encontrado na posiçao %d.\n", nomeArtista, meio);
            return;
        } else if (cmp < 0) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    printf("Artista '%s' nao encontrado.\n", nomeArtista);
}

void buscarAlbumSequencial(Artista artistas[], int total_artistas, char *nomeAlbum) {
	for (int i = 0; i < total_artistas; ++i) {
        for (int j = 0; j < artistas[i].qtd_albuns; ++j) {
            if (strcmp(artistas[i].albuns[j].nome, nomeAlbum) == 0) {
                printf("Álbum '%s' encontrado pelo artista: %s\n", nomeAlbum, artistas[i].nome);
                return;
            }
        }
    }
    printf("Álbum '%s' nao encontrado.\n", nomeAlbum);
}
