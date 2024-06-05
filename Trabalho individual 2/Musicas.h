#ifndef MUSICAS_H
#define MUSICAS_H

typedef struct musicas{
    char Artista[100];
    char Musica[100];
    int idMusica;
    struct musicas *anteriorMusica;
    struct musicas *proximaMusica;
} musicas;

void limparString(char *str);

void reescreverLista(musicas listaMusicas[], int quantidadeMusicas);

void iniciarLista(musicas listaMusicas[], int *posicaoMusica);

void cleanCaractere ();

int compararMusicas(const void *a, const void *b);

void buscarMusica(musicas listaMusicas[], int quanMusicas, char nomeMusica[200]);

void removerMusica(musicas listaMusicas[], int *posicaoMusica, char nomeMusica[100]);

void exibirPlaylistCadastro (musicas listaMusicas[], int quantidadeMusicas);

void mostrarPlaylistPorOrdemDeCadastro(musicas listaMusicas[], int quantidadeMusicas);

void inserirMusica(musicas listaMusicas[], int *posicaoMusica);

void proximaMusica(musicas **musicaAtual);

void musicaAnterior(musicas **musicaAtual);

int main ();

#endif
