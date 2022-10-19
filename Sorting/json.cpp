#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack<char> br;
    bool flag = true;
    string line;
    int i=1;
    while (getline(cin, line))
    {
    
        stack<char> st;
        
        for (char c : line)
        {
            if (c == '[' || c == '{')
            {
                br.push(c);
                continue;
            }
           
            if (br.empty() == false && ((c == ']' && br.top() == '[') || (c == '}' && br.top() == '{')))
            {
                br.pop();
                continue;
            }
            else if (br.empty() || ((c == ']' && br.top() != '[') || (c == '}' && br.top() != '{')))
            {
                flag = false;
                break;
            }             
            if (c == '(')
            {
                st.push(c);
                continue;
            }
            
            if (st.empty() == false && (c == ')' && st.top() == '('))
            st.pop();
            else if (st.empty() || ((c == ')' && st.top() != '(')))
            {
                flag = false;
                break;
            }


        }

        if (st.empty() == false)
        {
            flag = false;
            break;
        }
        
            if (flag == false)
            break;
            i++;
    }
    
        if (br.empty() == false)
         flag = false;
      

        cout << (flag ? "valid" : "invalid") << "\n";
        return 0;
}