#ifndef ARTISTAS_H
#define ARTISTAS_H

#define MAX_ALBUNS 50

typedef struct {
    char nome[100];
} Album;

typedef struct {
    char nome[100];
    char genero[50];
    int qtd_albuns;
    Album albuns[MAX_ALBUNS];
    char local[100];
} Artista;

void lerArtistasDoArquivo(Artista artistas[], int *total_artistas);
void inserirArtistaOrdenado(Artista artistas[], int *total_artistas, Artista novoArtista);
void removerArtista(Artista artistas[], int *total_artistas, char *nomeArtista);
void editarArtista(Artista artistas[], int total_artistas, char *nomeArtista, Artista dadosNovos);
void buscarArtistaBinario(Artista artistas[], int total_artistas, char *nomeArtista);
void buscarAlbumSequencial(Artista artistas[], int total_artistas, char *nomeAlbum);


#endif 
