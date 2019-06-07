// Runtime: 68 ms, faster than 52.76% of JavaScript online submissions for N-Queens II.
// Memory Usage: 35.5 MB, less than 54.37% of JavaScript online submissions for N-Queens II.
// There should be a faster method than this?

let result = 0;
/**
 * @param {number} n
 * @return {string[][]}
 */
var totalNQueens = function (n) {
  result = 0;
  let solutionMatrix = [...new Array(n)];
  solutionMatrix = solutionMatrix.map(x => [...(new Array(n + 1)).join('.')]);
  _solveNQueens(0, solutionMatrix);
  return result;
};
/**
 * 
 * @param {number} rowNow 
 * @param {string[][]} solutionMatrix 
 */
function _solveNQueens(rowNow, solutionMatrix) {
  if (rowNow >= solutionMatrix.length) {
    result++;
    return true;
  }
  for (let i = 0; i < solutionMatrix.length; i++) {
    solutionMatrix[rowNow][i] = 'Q';
    if (!validateColumn(solutionMatrix, i) || !validateOblique(solutionMatrix, rowNow, i)) {
      solutionMatrix[rowNow][i] = '.';
      continue;
    }
    _solveNQueens(rowNow + 1, solutionMatrix);
    solutionMatrix[rowNow][i] = '.';
  }
  return false;
}

/**
 * @param {string[]} solutionMatrix 
 * @param {number} column 
 * @returns {boolean}
 */
function validateColumn(solutionMatrix, column) {
  let hasAppeared = false;
  for (let i = 0; i < solutionMatrix.length; i++) {
    if (solutionMatrix[i][column] == 'Q') {
      if (hasAppeared) return false;
      else hasAppeared = true;
    }
  }
  return true;
}


/**
 * @param {string[]} solutionMatrix 
 * @param {number} row 
 * @param {number} column 
 * @returns {boolean}
 */
function validateOblique(solutionMatrix, row, column) {
  let rowIterator = row;
  let columnIterator = column;
  let hasAppeared = false;
  while (rowIterator >= 0 && columnIterator >= 0) {
    if (solutionMatrix[rowIterator][columnIterator] == 'Q') {
      if (hasAppeared) return false;
      else hasAppeared = true;
    }
    rowIterator--;
    columnIterator--;
  }
  rowIterator = row - 1;
  columnIterator = column + 1;
  while (rowIterator >= 0 && columnIterator < solutionMatrix.length) {
    if (solutionMatrix[rowIterator][columnIterator] == 'Q') {
      if (hasAppeared) return false;
      else hasAppeared = true;
    }
    rowIterator--;
    columnIterator++;
  }
  rowIterator = row + 1;
  columnIterator = column - 1;
  while (rowIterator < solutionMatrix.length && columnIterator >= 0) {
    if (solutionMatrix[rowIterator][columnIterator] == 'Q') {
      if (hasAppeared) return false;
      else hasAppeared = true;
    }
    rowIterator++;
    columnIterator--;
  }
  rowIterator = row + 1;
  columnIterator = column + 1;
  while (rowIterator < solutionMatrix.length && columnIterator < solutionMatrix.length) {
    if (solutionMatrix[rowIterator][columnIterator] == 'Q') {
      if (hasAppeared) return false;
      else hasAppeared = true;
    }
    rowIterator++;
    columnIterator++;
  }

  return true;
}


console.log(totalNQueens(5));