#include <stdio.h>
#include <stdbool.h>

#define N 5

// Struct to represent a position in the grid
typedef struct position {
  int x;
  int y;
} position;

// List of C coin positions
position coins[N*N];
int num_coins = 0;

// Function to perform flood fill algorithm
bool flood_fill(char grid[N][N], int x, int y) {
  // Check if the current position is out of bounds or if it is a wall
  if (x < 0 || x >= N || y < 0 || y >= N || grid[x][y] == '1') {
    return false;
  }

  // Check if the current position is a C coin
  for (int i = 0; i < num_coins; i++) {
    if (coins[i].x == x && coins[i].y == y) {
      return true;
    }
  }

  // Mark the current position as visited
  grid[x][y] = '1';

  // Explore the four neighboring cells
  if (flood_fill(grid, x+1, y) || flood_fill(grid, x-1, y) || flood_fill(grid, x, y+1) || flood_fill(grid, x, y-1)) {
    return true;
  }

  return false;
}

int main(void) {
  // Test the flood fill algorithm
  char grid[N][N] = {
    {'1', '1', '1', '1', '1'},
    {'1', 'E', '1', '1', 'C'},
    {'1', '1', 'C', '0', '0'},
    {'1', 'P', '1', '0', '1'},
    {'1', '1', '1', '1', '1'}
  };

  // Add the positions of the C coins to the list
  coins[num_coins++] = (position){3, 3};
  coins[num_coins++] = (position){4, 4};

  // Check if the player can reach any of the C coins
  if (flood_fill(grid, 3, 1)) {
    printf("Player can reach a C coin.\n");
  } else {
    printf("Player cannot reach any C coins.\n");
  }

  return 0;
}
