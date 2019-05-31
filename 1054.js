// var rearrangeBarcodes = function (barcodes) {
//   return _rearrangeBarcodes(barcodes, true);
// };

// var _rearrangeBarcodes = function (barcodes, twice) {
//   let length = barcodes.length;
//   for (let i = 0; i < length - 1; i++) {
//     let now = barcodes[i];
//     let j = i + 1;
//     while (barcodes[j] == now && j !== length - 1) {
//       j = Math.floor(Math.random() * (length - i - 1)) + i + 1;
//     }
//     if (barcodes[j] == now && (j === length - 1)) {
//       let temp = barcodes[j];
//       barcodes[j] = barcodes[0];
//       barcodes[0] = temp;
//       break;
//     }
//     if (j !== i + 1) {
//       let temp = barcodes[j];
//       barcodes[j] = barcodes[i + 1];
//       barcodes[i + 1] = temp;
//     }

//   }

//   if (twice)
//     barcodes = _rearrangeBarcodes(barcodes, false);
//   return barcodes;
// }

// console.log(rearrangeBarcodes([1,1,1,1,2,2,3]));