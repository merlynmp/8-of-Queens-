// Merlyn Pothen
// 2d array, backtracking, goto
#include <iostream>
using namespace std;

int main() {

  // number of times
  int counter = 1;

  // array used to store the queens
  int b[8][8];

  // row is 0, coloumn is 0.
  int r = 0;
  int c = 0;

  // place the queen at the first row and coloumn, lets start finding the places
  b[0][0] = 1;

nc:

  // go to next coloum
  c++;

  // if we reach the 8th coloumn, then print the results
  if (c == 8) {
    goto print;
  }

  // to find the next set of solutions, change the row back to -1
  r = -1;

nr:

  // go to next row to see if we can place a queen there(current coloumn
  // checking)
  r++;

  // if the row reaches 8, then there is no place for that queen in the coloumn,
  // go to the previous coloumn and remove the queen to find the next best
  // possible solution for the PREVIOUS COLOUMN (WHICH WILL BE DONE IN
  // BACKTRACK).
  if (r == 8) {
    goto backtrack;
  }

  // row test to check if there is any queens in the same row. if there is, go
  // to nr, and increase row by 1.
  for (int i = 0; i < c; i++) {
    if (b[r][i] == 1) {
      goto nr;
    }
  }

  // up diagonal test to check if there is any queens in the same diagonal
  // upwards. if there is, go to nr, and increase row by 1.
  for (int i = 1; (r - i) >= 0 && (c - i) >= 0; i++) {
    if (b[r - i][c - i] == 1) {
      goto nr;
    }
  }

  // down diagonal test to check if there is any queens in the same diagonal
  // downwards. if there is, go to nr, abd increase row by 1.
  for (int i = 1; (r + i) >= 7 && (c - i) >= 0; i++) {
    if (b[r + i][c - i] == 1) {
      goto nr;
    }
  }

  // passed the tests, place the queen!!! woooooo
  b[r][c] = 1;

  // go to next coloumn to place the next queen
  goto nc;

backtrack:

  // if we cant find a place to store the queen, go to the PREVIOUS coloumn.
  c--;

  // if we reached all 92 solutions, end the program
  if (c < 0) {
    return 0;
  }

  // to check where the queen is placed in the PREVIOUS coloumn. when we find
  // the queen by checking each row, that queen would be equal to 0.
  r = 0;
  while (b[r][c] != 1) {
    r++;
  }
  b[r][c] = 0;

  // go to next row to find the next best solution for the PREVIOUS coloumn.
  goto nr;

print:

  cout << "Solution #: " << counter++ << endl;

  // loop to print the results
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (b[i][j] == 1) {
        cout << "Row: " << i << " ";
        cout << "Coloumn: " << j << " ";
      }
    }
    cout << endl;
  }

  cout << endl;

  // there are only 92 solutions
  if (counter <= 92) {
    goto backtrack;
  }

  return 0;
}