public class Solution {

    public static void main(String[] args) {
        // write your code here
        Solution x = new Solution();
        System.out.println(x.intToRoman(58));
    }

    public String intToRoman(int num) {
        String symbol[][] = {
                {"I", "V"},
                {"X", "L"},
                {"C", "D"},
                {"M"}
        };

        StringBuilder sb = new StringBuilder();

        int count = 0;
        while (num >= 1) {
            int number = num % 10;

            if (number == 4) {
                sb.insert(0, symbol[count][0] + symbol[count][1]);
            } else if (number == 9) {
                sb.insert(0, symbol[count][0] + symbol[count + 1][0]);
            } else {
                boolean isOver5 = number >= 5;
                StringBuilder t = new StringBuilder();
                if (isOver5)
                    number -= 5;

                for (int i = 1; i <= number; i++) {
                    t.append(symbol[count][0]);
                }

                if (isOver5)
                    t.insert(0, symbol[count][1]);
                sb.insert(0, t);
            }

            num /= 10;
            count++;
        }
        return sb.toString();
    }
}