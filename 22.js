/**
 * @param {number} n
 * @return {string[]}
 */

let temp = {};
var generateParenthesis = function(n) {

};

var goDeep = function () {
  
}

console.log(generateParenthesis(5));

// want to use Recursive to do this
// but like failed
// var generateParenthesis = function(n) {
//   if (n == 1)
//     return ["()"];
//   if (n == 2)
//     return ["()()", "(())"];
//   if (temp[n])
//     return temp[n];
//   let result = generateParenthesis(n - 1);
//   let a = result.map(s => s + '()');
//   let b = result.map(s => '()' + s);
//   b = b.filter((val, index) => a.indexOf(val) < 0);
//   let c = result.map(s => `(${s})`);
//   // c.filter((val, index) => a[index] !== c[index]);
//   // let d = new Array(n + 1).join('()');
//   result = a.concat(b).concat(c);
//   if (n % 2 == 0) {
//     let evenResult = generateParenthesis(n / 2);
//     evenResult = evenResult.map(x => `${x}${x}`).filter(val => result.indexOf(val));
//     result = result.concat(evenResult);
//   }
//   // result.unshift(d)
//   temp[n] = result;
//   return result;
// };