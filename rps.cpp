#include <bits/stdc++.h>
using namespace std;

#define maxs 1000

// declaring vectors to store input
vector<vector<int>> ip;

vector<int> temp;

// declaring vectors to store output
vector<vector<int>> op;

int main()
{
    int i, j, n, states;

    // input character array
    char ch[maxs];

    // output character array
    char och[maxs];

    // giving input no. of states
    cin >> n;

    // then getting input from user in the given format
    for (i = 0; i < n; i++)
    {
        cin >> ch[i];
        for (j = 0; j < 3; j++)
        {
            cin >> states;
            temp.push_back(states);
        }
        ip.push_back(temp);
        temp.clear();
    }

    // storing exact input states to output state
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < 3; j++)
        {
            temp.push_back(ip[i][j]);
        }
        op.push_back(temp);
        temp.clear();
    }

    // changing states and their coordinates to win the input
    for (i = 0; i < n; i++)
    {
        if (ch[i] == 'R')
        {
            och[i] = 'P';

            // O(P,R) ----> I(R,P)
            op[i][0] = ip[i][1];

            // O(P,P) ----> I(P,P)
            for (j = i; j < n; j++)
            {
                if (ch[j] == 'P')
                {
                    op[i][1] = ip[j][1];
                    break;
                }
            }

            // O(P,S) ----> I(S,P)
            for (j = i; j < n; j++)
            {
                if (ch[j] == 'S')
                {
                    op[i][2] = ip[j][1];
                    break;
                }
            }
        }
        else if (ch[i] == 'P')
        {
            och[i] = 'S';

            // O(S,P) ----> I(P,S)
            op[i][1] = ip[i][2];

            // O(S,S) ----> I(S,S)
            for (j = i; j < n; j++)
            {
                if (ch[j] == 'S')
                {
                    op[i][2] = ip[j][2];
                    break;
                }
            }

            // O(S,R) ----> I(R,S)
            for (j = i; j < n; j++)
            {
                if (ch[j] == 'R')
                {
                    op[i][0] = ip[j][2];
                    break;
                }
            }
        }
        else if (ch[i] == 'S')
        {
            och[i] = 'R';

            // O(R,S) ----> I(S,R)
            op[i][2] = ip[i][0];

            // O(R,R) ----> I(R,R)
            for (j = i; j < n; j++)
            {
                if (ch[j] == 'R')
                {
                    op[i][0] = ip[j][0];
                    break;
                }
            }

            // O(R,P) ----> I(P,R)
            for (j = i; j < n; j++)
            {
                if (ch[j] == 'P')
                {
                    op[i][1] = ip[j][0];
                    break;
                }
            }
        }
    }

    // printing output in format
    cout << op.size() << endl;

    for (i = 0; i < op.size(); i++)
    {
        cout << och[i] << " ";
        for (j = 0; j < op[i].size(); j++)
            cout << op[i][j] << " ";
        cout << endl;
    }

    return 0;
}