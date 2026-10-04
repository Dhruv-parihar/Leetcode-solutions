class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0")
            return "0";

        int n = num1.size();
        int m = num2.size();

        // Maximum possible length is n + m
        vector<int> result(n + m, 0);

        // Multiply digit by digit
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                int a = num1[i] - '0';
                int b = num2[j] - '0';

                int product = a * b;

                int pos1 = i + j;
                int pos2 = i + j + 1;

                result[pos2] += product;

                // Carry
                result[pos1] += result[pos2] / 10;
                result[pos2] %= 10;
            }
        }

        // Convert result array to string
        string ans;
        int i = 0;

        // Skip leading zeros
        while (i < result.size() && result[i] == 0)
            i++;

        while (i < result.size())
            ans += char(result[i++] + '0');

        return ans.empty() ? "0" : ans;
    }
};