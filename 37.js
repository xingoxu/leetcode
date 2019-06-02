/**
 * @param {character[][]}  board
 * @return {boolean}
 */
// Maybe there is a more efficient algorithm
let possibleAnswerMap = {};
var solveSudoku = function(board) {
  possibleAnswerMap = {};
  let lineAvailableCache = {};
  let columnAvailableCache = {};
  for (let xi = 0; xi < 9; xi += 3) {
    for (let yi = 0; yi < 9; yi += 3) {
      let boxAvailable = getBoxAvailable(board, xi, yi);
      for (let x = 0; x < 3; x++) {
        for (let y = 0; y < 3; y++) {
          let realX = x + xi;
          let realY = y + yi;
          let lineAvailable = lineAvailableCache[realX] || (lineAvailableCache[realX] = getLineAvailable(board, realX));
          let columnAvailable = columnAvailableCache[realY] || (columnAvailableCache[realY] = getColumnAvailable(realY));
          
          if (board[realX][realY] == '.') {
            solvePossibleAnswerForOneBlank(lineAvailable, columnAvailable, boxAvailable, realX, realY);
          }
        }
      }
    }
  }
  _solveSudoku(board, 0, 0);
  return board;
};

var _solveSudoku = function (board, x, y) {
  if (board[x][y] != '.') {
    return goNext(board, x, y);
  }
  let possibleAnswer = possibleAnswerMap[`${x}-${y}`];
  for (let i = 0; i < possibleAnswer.length; i++) {
    board[x][y] = String(possibleAnswer[i]);
    if (!isLineValid(board, x)) continue;
    if (!isColumnValid(board, y)) continue;
    if (!isBoxValid(board, x, y)) continue;
    if (goNext(board, x, y)) return true;
  }
  board[x][y] = '.';
  return false;
}
var goNext = function (board, x, y) {
  if (x == 8 && y == 8) {
    // solved;
    return true;
  }
  if (y >= 8) {
    y = 0;
    x += 1;
  } else {
    y++;
  }
  return _solveSudoku(board, x, y);
}

var getLineAvailable = function (board, x) {
  let t = new Array(10);
  for (let i = 0; i < board[x].length; i++) {
    let content = board[x][i];
    if (content == '.') continue;
    t[content] = true;
  }
  let result = [];
  for (let i = 1; i < 10; i++) {
    (!t[i]) && result.push(i);
  }
  return result;
}

var getColumnAvailable = function (board, y) {
  let t = new Array(10);
  for (let i = 0; i < board.length; i++) {
    let content = board[i][y];
    if (content == '.') continue;
    t[content] = true;
  }
  let result = [];
  for (let i = 1; i < 10; i++) {
    (!t[i]) && result.push(i);
  }
  return result;
}

var getBoxAvailable = function (board, x, y) {
  x = Math.floor(x / 3) * 3;
  y = Math.floor(y / 3) * 3;
  let t = new Array(10);
  for (let i = 0; i < 3; i++) {
    for (let j = 0; j < 3; j++) {
      let accessX = x + i;
      let accessY = y + j;
      let content = board[accessX][accessY];
      if (content == '.') continue;
      t[content] = true;
    }
  }
  let result = [];
  for (let i = 1; i < 10; i++) {
    (!t[i]) && result.push(i);
  }
  return result;
}

var solvePossibleAnswerForOneBlank = function (lineAvailable, columnAvailable, boxAvailable, x, y) {
  let t = new Array(10);
  for (let i = 0; i < lineAvailable.length; i++){
    if (t[lineAvailable[i]]) t[lineAvailable[i]]++;
    else t[lineAvailable[i]] = 1;
  }
  for (let i = 0; i < columnAvailable.length; i++){
    if (t[columnAvailable[i]]) t[columnAvailable[i]]++;
    else t[columnAvailable[i]] = 1;
  }
  for (let i = 0; i < boxAvailable.length; i++){
    if (t[boxAvailable[i]]) t[boxAvailable[i]]++;
    else t[boxAvailable[i]] = 1;
  }
  let result = [];
  for (let i = 1; i < 10; i++) {
    t[i] >= 3 && result.push(i);
  }
  possibleAnswerMap[`${x}-${y}`] = result;
}

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

console.log(solveSudoku([
  ["5","3",".",".","7",".",".",".","."],
  ["6",".",".","1","9","5",".",".","."],
  [".","9","8",".",".",".",".","6","."],
  ["8",".",".",".","6",".",".",".","3"],
  ["4",".",".","8",".","3",".",".","1"],
  ["7",".",".",".","2",".",".",".","6"],
  [".","6",".",".",".",".","2","8","."],
  [".",".",".","4","1","9",".",".","5"],
  [".",".",".",".","8",".",".","7","9"]
]))
