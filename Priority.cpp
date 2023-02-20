#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    int tot_wt = 0;
    int tot_tat = 0;
    cout << "Enter the number of processes: ";
    cin >> n;
    int bt[n], wt[n], tat[n], pr[n];
    cout << "Enter the burst time of all processes: ";
    for (int i = 0; i < n; i++)
    {
        cin >> bt[i];
    }
    cout << "Enter the priority of all processes: ";
    for (int i = 0; i < n; i++)
    {
        cin >> pr[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (pr[i] > pr[j])
            {
                int temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;
            }
        }
    }
    wt[0] = 0;
    for (int i = 1; i < n; i++)
        wt[i] = wt[i - 1] + bt[i - 1];
    for (int i = 0; i < n; i++)
        tat[i] = bt[i] + wt[i];
    cout << "Processes Burst time Waiting time Turn around time\n";
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << " "
             << bt[i] << " "
             << wt[i] << " "
             << tat[i] << endl;
        tot_wt = tot_wt + wt[i];
        tot_tat = tot_tat + tat[i];
    }
    float s = (float)tot_wt / (float)n;
    float t = (float)tot_tat / (float)n;
    cout << "Average waiting time = " << s << endl;
    cout << "Average turn around time = " << t << endl;
    return 0;
