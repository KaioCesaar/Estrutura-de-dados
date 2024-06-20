Torre de hanói
==================
A Torre de Hanói é um quebra-cabeça matemático que envolve três pinos e um número de discos de tamanhos diferentes que podem deslizar para cima e para baixo em qualquer um dos pinos. O jogo começa com todos os discos empilhados em ordem decrescente de tamanho em um dos pinos, com o maior disco na base e o menor no topo.

Passo a Passo
==================
Configuração Regional: setlocale(LC_ALL, "Portuguese"); configura programa para usar o idioma português.
Início do Jogo:
Exibe as regras do jogo e pede ao usuário para iniciar.

Se o usuário optar por jogar (resposta == 1), o programa limpa a tela e pede o número de discos.

Validação do Número de Discos:
Verifica se o número de discos é válido (entre 1 e MAX_DISCOS).

Inicialização das Torres:
Inicializa as três torres e empilha os discos na primeira torre.

Loop Principal:
Exibe o estado atual das torres.
Solicita ao usuário a origem e o destino do disco a ser movido.
Verifica e realiza o movimento se for válido.
Se o usuário digitar "0 0", reinicia o jogo.

Reinicialização do Jogo:
Se o comando "0 0" for inserido, as torres são reinicializadas com o mesmo número de discos.

Resumo 
==================
Este programa implementa uma versão interativa do jogo da Torre de Hanói, permitindo ao usuário mover discos entre três torres seguindo regras específicas. O programa gerencia a inicialização, exibição e movimentação dos discos, além de permitir a reinicialização do jogo a qualquer momento.


