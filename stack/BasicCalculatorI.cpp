class Solution
{
public:
  int calculate(string s)
  {
    stack<int> st;
    long long number = 0;
    long long result = 0;
    int sign = 1;
    for (int i = 0; i < s.size(); i++)
    {
      if (isdigit(s[i])) //number banaao
      {
        number = 1LL * number * 10 + (s[i] - '0');
      }
      else if (s[i] == '-') //result mein number add kyuki ab naya number milega toh puraana result mein add
      {
        result += (number * sign);
        number = 0;
        sign = -1;
      }
      else if (s[i] == '+')
      {
        result += (number * sign);
        number = 0;
        sign = 1;
      }
      else if (s[i] == '(') // new calculations for inside bracket 
      {
        st.push(result);
        st.push(sign);
        result = 0;
        sign = 1;
      }
      else if (s[i] == ')') 
      {
        result += (number * sign);
        result = result * st.top();
        st.pop();
        result += st.top();
        st.pop();
        number = 0;
      }
      else
        continue; // handles spaces
    }
    result += number * sign; //if loop finishes but number remains to be added in result
    return result;
  }
};