// Runtime: 904 ms, faster than 5.04% of JavaScript online submissions for Multiply Strings.
// Memory Usage: 41.7 MB, less than 13.49% of JavaScript online submissions for Multiply Strings.

let multipleTable;
let addTable;
/**
 * @param {string} num1
 * @param {string} num2
 * @return {string}
 */
var multiply = function (num1, num2) {
  generateTable();

  let result = "0";
  for (let i = 0; i < num1.length; i++) {
    if (num1[i] == 0) continue;
    for (let j = 0; j < num2.length; j++) {
      if (num2[j] == 0) continue;
      let multiTimes = num1.length - 1 - i + num2.length - 1 - j;
      let a = num1[i], b = num2[j];
      let multipleResult = multipleTable[a][b] || multipleTable[b][a];
      let zero = new Array(multiTimes + 1);
      multipleResult += zero.join('0');
      result = add(result, multipleResult);
    }
  }
  return result;
};

/**
 * @param {string} num1
 * @param {string} num2
 * @return {string}
 */
function add(num1, num2) {
  if (num2 == "0")
    return num1;
  if (num1 == "0")
    return num2;
  
  let iterateCount = 0, carryNext = false, result = "";
  while (iterateCount < num1.length && iterateCount < num2.length) {

    let a = num1[num1.length - 1 - iterateCount];
    let b = num2[num2.length - 1 - iterateCount];
    if (a == "0" || b == "0") {
      let answer = a == "0" ? b : a;
      
      if (carryNext) {
        if (answer == "0") answer = "1";
        else
          answer = addTable[1][answer];
        carryNext = false;
      }
      result = answer + result;
      iterateCount++;
      continue;
    }
    let singleResult = addTable[a][b] || addTable[b][a];
    let nextCarryNext = singleResult.length > 1;
    singleResult = nextCarryNext ? singleResult[1] : singleResult[0];

    if (carryNext) {
      if (singleResult == '0')
        singleResult = '1';
      else {
        singleResult = addTable[1][singleResult];
        nextCarryNext = singleResult.length > 1 ? true : nextCarryNext;
        singleResult = singleResult[singleResult.length - 1];
      }
    }

    carryNext = nextCarryNext;
    result = singleResult + result;
    iterateCount++;
  }

  while (iterateCount < num1.length) {
    let singleResult = num1[num1.length - 1 - iterateCount];
    if (carryNext) {
      if (singleResult != "0") {
        singleResult = addTable[1][singleResult];
        carryNext = singleResult.length > 1;
        singleResult = singleResult[singleResult.length - 1];
      } else {
        singleResult = "1";
        carryNext = false;
      }
    }
    result = singleResult + result;
    iterateCount++;
  }
  while (iterateCount < num2.length) {
    let singleResult = num2[num2.length - 1 - iterateCount];
    if (carryNext) {
      if (singleResult != "0") {
        singleResult = addTable[1][singleResult];
        carryNext = singleResult.length > 1;
        singleResult = singleResult[singleResult.length - 1];
      } else {
        singleResult = "1";
        carryNext = false;
      }
    }
    result = singleResult + result;
    iterateCount++;
  }
  if (carryNext)
    result = "1" + result;
  return result;
}


function generateTable() {
  if (multipleTable) return;
  let multipleResult = {};
  let addResult = {};
  for (let i = 1; i <= 9; i++) {
    for (let j = i; j <= 9; j++) {
      if (multipleResult[i]) multipleResult[i][j] = `${i * j}`;
      else multipleResult[i] = { [j]: `${i * j}` };

      if (addResult[i]) addResult[i][j] = `${i + j}`;
      else addResult[i] = { [j]: `${i + j}` };
    }
  }
  multipleTable = multipleResult;
  addTable = addResult;
  return multipleResult;
}
generateTable();
// console.log(add("121932543211386000", "14000"));
console.log(multiply("123456789",
  "987654321"));