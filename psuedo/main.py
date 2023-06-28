import random


def update_grid(row, col, options):
    rand_num = random.randint(0, len(options) - 1)
    GRID[row][col] = options[rand_num]

def collapse():
    for i in range(0, len(GRID)):
        for j in range(0, len(GRID[i])):

            # gen random at GRID[0][0]
            if (i == 0  and j == 0):
                start();
                continue
            if (i == 0):
                valid_opts = left_collapse(GRID[i][j - 1])
                update_grid(i, j, valid_opts)
                continue
            if (j == 0):
                valid_opts = roof_collapse(GRID[i - 1][j])
                update_grid(i, j, valid_opts)
                continue
            if (i != 0 and j != 0):
                valid_opts_up = set(roof_collapse(GRID[i - 1][j]))
                valid_opts_left = set(left_collapse(GRID[i][j - 1]))
                valid_opts = valid_opts_up.intersection(valid_opts_left)
                update_grid(i, j, list(valid_opts))
                continue


def roof_collapse(ch):
    possible_connections = {
        'd': ['l', 'r', 'u'],
        'u': ['b', 'd'],
        'l': ['l', 'r', 'u'],
        'r': ['l', 'r', 'u'],
        'b': ['b', 'd']
    }

    options = []

    for tile in possible_connections:
        if (tile == ch):
            options = possible_connections[tile]
            break

    return options

def start():
    options = ['d', 'u', 'l', 'r', 'b']

    rand_index = random.randint(0, len(options) - 1)
    GRID[0][0] = options[rand_index]

def left_collapse(ch):
    possible_connections = {
        'd': ['l', 'd', 'u'],
        'u': ['l', 'd', 'u'],
        'l': ['b', 'r'],
        'r': ['l', 'd', 'u'],
        'b': ['b', 'r']
    }

    options = []

    for tile in possible_connections:
        if (tile == ch):
            options = possible_connections[tile]
            break

    return options

def printboard():
    for i in range (0, len(GRID)):
        for j in range(0, len(GRID[i])):
            print(GRID[i][j] + " ", end='')
        print("\n")

def main():
    collapse()
    printboard()

GRID = [
    [' ', ' ', ' '],
    [' ', ' ', ' '],
    [' ', ' ', ' ']
]

main()
