#include <stdio.h>

#define N 9

void writeMatrix() {
  int count = 0;
  int mas[N][N];
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      mas[i][j] = ++count;
      //Добавлено условие для красивого вывода квадратных матриц до размера 10*10
      if (mas[i][j] < 10) {
      	printf("%d  ", mas[i][j]);
      } else {
      	printf("%d ", mas[i][j]);
      }
    }
    printf("\n");
  }
}

void writeReversedMas() {
  int mas[N];
  printf("Write %d numbers: \n", N);
  for (int i = 0; i < N; ++i) {
    scanf("%d", &mas[i]);
  }
  printf("Normal view:\n");
  for (int i = 0; i < N; ++i) {
  	printf("%d ", mas[i]);
  }
  printf("\nReversed view:\n");
  for (int i = N - 1; i >= 0; --i) {
  	printf("%d ", mas[i]);
  }
  printf("\n");
}

//Эта процедура выводит 0-и выше побочной диагонали квадратной матрицы и 1-ы от побочной диагонали и ниже
void writeTriangles() {
  int mas[N][N];
  for (int i = 0; i < N; ++i) {
  	for (int j = 0; j < N; ++j) {
  	  if (N - i - 1 > j) {
        mas[i][j] = 0;
  	  } else {
  	  	mas[i][j] = 1;
  	  }
  	  printf("%d ", mas[i][j]);
  	}
  	printf("\n");
  }
}

//Так как тут возможно несильно очевидный алгоритм, решил добавить несколько комментариев с:
void writeSnail() {
  int count = 0;  //Счётчик для текущего значения в массиве
  int x = 0;      //Координата х в массиве
  int y = 0;      //Координата у в массиве
  int mas[N][N];  

//Заполняем массив 0-ми
  for (int i = 0; i < N; ++i) {
  	for (int j = 0; j < N; ++j) {
  	  mas[i][j] = 0;
  	}
  }

//Заполняем массив по спирали "улиткой" от верхнего левого края по часовой стрелке
  while (count < N * N) {
  	//Ползём вправо
  	while (mas[y][x + 1] == 0 && x < N - 1) {
      mas[y][x] = ++count;
      x++;
  	}
  	//Ползём вниз
  	while (mas[y + 1][x] == 0 && y < N - 1) {
  	  mas[y][x] = ++count;
  	  y++;
  	}
  	//Ползём влево
  	while (mas[y][x - 1] == 0 && x > 0) {
  	  mas[y][x] = ++count;
  	  x--;
  	}
  	//Ползём вверх
  	while (mas[y][x] == 0 && y > 0) {
  	  mas[y][x] = ++count;
  	  y--;
  	}
  	//Делаем сдвиг во внутренний круг
    x++;
    y++;
  }
  //Выводим массив
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      if (mas[i][j] < 10) {
      	printf("%d  ", mas[i][j]);
      } else {
      	printf("%d ", mas[i][j]);
      }
    }
    printf("\n");
  }
}

int main() {
  int task = 0;
  printf("Choose the number of task from 1 to 4: ");
  scanf("%d", &task);
  switch (task) {
  	case 1: {
      writeMatrix();
      break;
  	}
  	case 2: {
      writeReversedMas();
      break;
  	}
  	case 3: {
      writeTriangles();
      break;
  	}
  	case 4: {
      writeSnail();
      break;
  	}
  	default: {
  	  printf("Wrong input!");
  	}
  }

  return 0;
}