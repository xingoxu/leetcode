// Runtime: 76 ms, faster than 60.70% of JavaScript online submissions for N-Queens.
// Memory Usage: 36.6 MB, less than 85.89% of JavaScript online submissions for N-Queens.

let result = [];
/**
 * @param {number} n
 * @return {string[][]}
 */
var solveNQueens = function (n) {
  result = [];
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
    let replica = solutionMatrix.slice();
    replica = solutionMatrix.map(x => x.join(''));
    result.push(replica);
    return true;
  }
  for (let i = 0; i < solutionMatrix.length; i++) {
    solutionMatrix[rowNow][i] = 'Q';
    if (!validateColumn(solutionMatrix, i) || !validateOblique(solutionMatrix, rowNow, i)) {
      solutionMatrix[rowNow][i] = '.';
      continue;
    }
    if (_solveNQueens(rowNow + 1, solutionMatrix)) {
      solutionMatrix[rowNow] = solutionMatrix[rowNow].slice();
      solutionMatrix[rowNow][i] = '.';
    } else {
      solutionMatrix[rowNow][i] = '.';
    }
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


console.log(solveNQueens(5));