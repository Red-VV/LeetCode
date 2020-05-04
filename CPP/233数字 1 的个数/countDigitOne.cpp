class Solution {
public:
    int countDigitOne(int n) {
        if(n <= 0)
            return 0;
        else if(n <= 9)
            return 1;
        int res = 0;
        stringstream stream;
        stream << n;
        string str;
        stream >> str;
        for(int i = 0; i < str.size(); i++)
        {
            int xyz = get_num(str.substr(0, i));
            int abc = get_num(str.substr(i + 1));
            res += xyz * pow10(str.size() - i - 1);
            if(str[i] == '0')
            {
               continue;
            } else if(str[i] == '1')
            {
                res += abc + 1;
            } else {
                res += pow10(str.size() - i - 1);
            }
        }
        return res;
    }
private:
    int pow10(int x)
    {
        if(x == 0)
            return 1;
        if(x % 2 == 0)
        {
            int temp = pow10(x/2);
            return temp * temp;
        } else {
            return pow10(x-1) * 10;
        }
    }
    int get_num(string num)
    {
        if(num.size() == 0)
            return 0;
        stringstream stream;
        stream << num;
        int res;
        stream >> res;
        return res;
    }
};