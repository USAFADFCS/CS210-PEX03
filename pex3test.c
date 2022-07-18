/** pex3test.h
 * =============================================================
 * Name: Your Name
 * Section:  Your Section
 * Project:  FILL IN
 * Purpose:  FILL IN
 * ============================================================= */

void testCreateBoard() {
    char** board = createBoard(5, 5);

    // Checks the Edges
    assert(board[0][0] == '_');
    assert(board[4][4] == '_');
    
    // Replaces everything with *'s
    for (int r=0; r<5; r++) {
        for (int c=0; c<5; c++) {
            board[r][c] = '*';        
        }
    }

    for (int r=0; r<5; r++) {
        for (int c=0; c<5; c++) {
            assert(board[r][c] == '*');
        }
    }

    printf("PASSED ALL TESTS!\n\n");
}

void testCopyBoard() {
    char** board1 = createBoard(5, 5);

    // Put some stuff in the board
    board1[0][0] = '*';
    board1[1][1] = '*';
    board1[2][2] = '*';
    board1[3][3] = '*';
    board1[4][4] = '*';

    // Make a copy
    char** copyOfBoard = copyBoard(board1, 5, 5);

    // Check every cell to make sure it matches
    for (int r=0; r<5; r++) {
        for (int c=0; c<5; c++) {
            assert(board1[r][c] == copyOfBoard[r][c]);
        }
    }

    // Modify the original board
    board1[0][2] = '*';

    // Make sure that the copy doesn't have the same change
    assert(board1[0][2] != copyOfBoard[0][2]);
    
    printf("PASSED ALL TESTS!\n\n");
}

void testCompareBoards() {
    char** board1 = createBoard(5, 5);
    char** board2 = createBoard(5, 5);

    board1[2][3] = '*';
    board2[2][3] = '*';
    assert(compareBoards(board1, board2, 5, 5) == 0);

    board1[3][3] = 'c';
    board2[3][3] = 'b';
    assert(compareBoards(board1, board2, 5, 5) == 1);

    printf("PASSED ALL TESTS!\n\n");
}

void testUpdateBoard() {
    char** board = createBoard(5, 5);

    // Puts a character in the correct spot
    board[0][2] = 'x';

    // Updates the board a few times
    board = updateBoard(board, 94, 5, 5);
    board = updateBoard(board, 94, 5, 5);
    board = updateBoard(board, 94, 5, 5);

    // printBoard(board, 5, 5);

    // Spot Checks the Board
    assert(board[1][1] == 'x');
    assert(board[2][2] == '_');
    assert(board[4][4] == '_');

    printf("PASSED ALL TESTS!\n\n");
}

void runAllTests() {
    printf("Test 1:  testCreateBoard:\n");
    testCreateBoard();

    printf("Test 2:  testCopyBoard:\n");
    testCopyBoard();

    printf("Test 3:  testCompareBoards:\n");
    testCompareBoards();

    printf("Test 4:  testUpdateBoard:\n");
    testUpdateBoard();
}