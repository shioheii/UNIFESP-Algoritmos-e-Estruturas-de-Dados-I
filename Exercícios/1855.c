#include <stdio.h>

int isArrow(char c) {
  return c == '>' || c == 'v' || c == '<' || c == '^';
}

int setDirection(char c) {
  if (c == '>') return 1;
  if (c == 'v') return 2;
  if (c == '<') return 3;
  
  return 4;
}

int setX(int x, int d) {
  if (d == 2) return x + 1;
  if (d == 4) return x - 1;

  return x;
}

int setY(int y, int d) {
  if (d == 1) return y + 1;
  if (d == 3) return y - 1;
  
  return y;
}

int main() {
  int x, y;

  scanf("%d", &y);
  scanf("%d", &x);

  getchar();

  char map[x][y];
  int pass[x][y];

  for (int i = 0; i < x; i++) {
    for (int j = 0; j < y; j++) {
      pass[i][j] = 0;
    }
  }

  for (int i = 0; i < x; i++) {
    for (int j = 0; j < y; j++) {
      scanf("%c", &map[i][j]);
    }
    getchar();
  }

  int i = 0, j = 0, direction, win = 0;
  while (pass[i][j] == 0 && !win) {
    char c = map[i][j];

    if (isArrow(c)) {
      pass[i][j] = 1;
      direction = setDirection(c);
    }

    if (c == '*') {
        win = 1;
        break;
    }

    int new_i = setX(i, direction);
    int new_j = setY(j, direction);

    if (new_i == x || new_i < 0 || new_j == y || new_j < 0) {
      break;
    }

    i = new_i;
    j = new_j;
  }

  if (win) {
    printf("*\n");
  } else {
    printf("!\n");
  }
}