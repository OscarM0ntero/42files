#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define UP 'w'
#define DOWN 's'
#define LEFT 'a'
#define RIGHT 'd'
#define QUIT 'q'

#define WALL '#'
#define PACMAN 'C'
#define BLANK ' '
#define PELLET '.'

#define HEIGHT 12
#define WIDTH 40

// Estructura para almacenar la posición de Pac-Man y los puntos
struct pacman {
  int x;
  int y;
  int points;
};

// Imprime la pantalla del juego
void printScreen(char screen[HEIGHT][WIDTH], struct pacman pacman) {
  system("clear");
  int i, j;
  for (i = 0; i < HEIGHT; i++) {
    for (j = 0; j < WIDTH; j++) {
      if (i == pacman.y && j == pacman.x) {
        printf("%c", PACMAN);
      } else {
        printf("%c", screen[i][j]);
      }
    }
    printf("\n");
  }
  printf("Puntos: %d\n", pacman.points);
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Uso: pacman mapa.ber\n");
    return 1;
  }

  // Abre el archivo .ber con el mapa
  char *filename = argv[1];
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    printf("Error al abrir el archivo %s\n", filename);
    return 1;
  }

  char screen[HEIGHT][WIDTH];
  int i, j;
  for (i = 0; i < HEIGHT; i++) {
    for (j = 0; j < WIDTH; j++) {
      screen[i][j] = fgetc(file);
    }
    fgetc(file); // Salta el carácter de nueva línea
  }
  fclose(file);

  // Posición inicial de Pac-Man
  struct pacman pacman = {.x = 1, .y = 1, .points = 0};

  char input;
  while (1) {
    // Lee la entrada del usuario
    input = getchar();
    if (input == UP) {
      // Mueve Pac-Man hacia arriba
      if (screen[pacman.y - 1][pacman.x] != WALL) {
        pacman.y--;
      }
    } else if (input == DOWN) {
      // Mueve Pac-Man hacia abajo
      if (screen[pacman.y + 1][pacman.x] != WALL) {
        pacman.y++;
      }
    } else if (input == LEFT) {
      // Mueve Pac-Man hacia la izquierda
      if (screen[pacman.y][pacman.x - 1] != WALL) {
        pacman.x--;
      }
    } else if (input == RIGHT) {
      // Mueve Pac-Man hacia la derecha
      if (screen[pacman.y][pacman.x + 1] != WALL) {
        pacman.x++;
      }
    } else if (input == QUIT) {
      break;
    }

    // Detecta la colisión con las píldoras y las elimina del mapa
    if (screen[pacman.y][pacman.x] == PELLET) {
      screen[pacman.y][pacman.x] = BLANK;
      pacman.points++;
    }

    // Imprime la pantalla del juego
    printScreen(screen, pacman);
  }

  return 0;
}