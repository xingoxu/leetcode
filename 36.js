/**
 * @param {character[][]}  board
 * @return {boolean}
 */

var isValidSudoku = function (board) {
  for (let x = 0; x < board.length; x++) {
    if (!isLineValid(board, x)) return false;
    if (!isColumnValid(board, x)) return false;
    for (let y = 0; y < board[x].length; y = y + 3) {
      if (x % 3 == 0) {
        if (!isBoxValid(board, x, y)) return false;
      }
    }
  }
  return true;
};

var isLineValid = function (board, x) {
  let t = new Array(10);
  for (let i = 0; i < board[x].length; i++) {
    let content = board[x][i];
    if (content == '.') continue;
    if (t[content]) return false;
    else t[content] = true;
  }
  return true;
}

var isColumnValid = function (board, y) {
  let t = new Array(10);
  for (let i = 0; i < board.length; i++) {
    let content = board[i][y];
    if (content == '.') continue;
    if (t[content]) return false;
    else t[content] = true;
  }
  return true;
}

var isBoxValid = function (board, x, y) {
  x = Math.floor(x / 3) * 3;
  y = Math.floor(y / 3) * 3;
  let t = new Array(10);
  for (let i = 0; i < 3; i++) {
    for (let j = 0; j < 3; j++) {
      let accessX = x + i;
      let accessY = y + j;
      let content = board[accessX][accessY];
      if (content == '.') continue;
      if (t[content]) return false;
      else t[content] = true;
    }
  }
  return true;
}

console.log(isValidSudoku([
  ["8","3",".",".","7",".",".",".","."],
  ["6",".",".","1","9","5",".",".","."],
  [".","9","8",".",".",".",".","6","."],
  ["8",".",".",".","6",".",".",".","3"],
  ["4",".",".","8",".","3",".",".","1"],
  ["7",".",".",".","2",".",".",".","6"],
  [".","6",".",".",".",".","2","8","."],
  [".",".",".","4","1","9",".",".","5"],
  [".",".",".",".","8",".",".","7","9"]
]))
