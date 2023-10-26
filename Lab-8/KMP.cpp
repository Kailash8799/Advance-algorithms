#include <bits/stdc++.h>

using namespace std;

class KMP
{
    string pattern, text;
    vector<int> prefix;

public:
    void takeInput()
    {
        cout << "Enter pattern :" << endl;
        cin >> pattern;
        cout << "Enter text :" << endl;
        cin >> text;
        prefix = vector<int>(pattern.length() +1, 0);
    }

    void preProcess()
    {
        int m = pattern.length();
        int k = 0;
        int cnt = 0;
        for (int q = 2; q <= m; q++)
        {
            while (k > 0 and ++cnt and pattern[k] != pattern[q-1])
            {
                k = prefix[k];
            }
            if (++cnt and pattern[k] == pattern[q-1])
            {
                k++;
            }
            prefix[q] = k;
        }

        for (int i = 1; i <= m; i++)
        {
            cout<<prefix[i]<< " ";
        }
        cout<<endl;
        // cout<<cnt<<endl;
    }

    void run()
    {
        preProcess();
        int n = text.length();
        int m = pattern.length();
        cout<<pattern<<" "<<text<<endl;

        int q = 0;
        for (int i = 0; i < n; i++)
        {
            while (q > 0 and pattern[q] != text[i])
            {
                q = prefix[q];
            }
            if (pattern[q] == text[i])
            {
                q++;
            }

            if (q == m)
            {
                cout << "Pattern occurs at " << i - m + 1 << endl;
                q = prefix[q];
            }
        }
    }
};

int main()
{
    KMP k;
    k.takeInput();
    
    k.run();
    return 0;
}
