#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <unordered_map>
using namespace std;

int problema1();
int problema2();
void insertSorted(vector<int> &v, int n, int key);

int main()
{
    int nprob;
    cin >> nprob;
    if (nprob == 1)
    {
        problema1();
    }
    else if (nprob == 2)
    {
        problema2();
    }
    return 0;
}

int problema1()
{
    vector<int> s(0);
    int i, j;
    // ler o input
    while (cin >> i)
    {
        s.push_back(i);
        if (cin.get() == '\n')
        {
            break;
        }
    }
    // algoritmo
    int size_s = s.size();
    // caso base
    if (size_s == 1)
    {
        cout << "1 1" << endl;
        return 0;
    }
    vector<int> comps(size_s);
    vector<int> numbersubs(size_s, 1);
    comps[0] = 1;
    for (i = 1; i < size_s; i++)
    {
        // ir metendo a entrada do vetor comp a 1
        comps[i] = 1;
        for (j = 0; j < i; j++)
        {
            if (s[j] < s[i])
            {
                if (comps[i] < comps[j] + 1)
                {
                    comps[i] = comps[j] + 1;
                    numbersubs[i] = numbersubs[j];
                }
                // caso em que existe mais uma subsequencia
                else if (comps[i] == comps[j] + 1)
                    numbersubs[i] += numbersubs[j];
            }
        }
    }
    int lenght = 0;
    // descobrir o comprimento maximo
    for (i = 0; i < size_s; i++)
    {
        if (comps[i] > lenght)
            lenght = comps[i];
    }
    int num_subs = 0;
    // descobrir o numero de subsequencias
    for (i = 0; i < size_s; i++)
    {
        if (comps[i] == lenght)
            num_subs += numbersubs[i];
    }
    cout << lenght << " " << num_subs << endl;
    return 0;
}

int problema2()
{
    vector<int> x(0);
    vector<int> y(0);
    unordered_map<int, int> aux;
    int i, j;

    // ler o input

    while (cin >> i)
    {
        aux[i] = 1;
        x.push_back(i);
        if (cin.get() == '\n')
        {
            break;
        }
    }

    while (cin >> i)
    {
        int flag = 0;
        if (aux.find(i) == aux.end())
            flag = 1;
        if (flag == 0)
            y.push_back(i);
        if (cin.get() == '\n')
        {
            break;
        }
    }

    int size_x = x.size(), size_y = y.size();

    int vec_res[size_y];
    for (i = 0; i < size_y; i++)
        vec_res[i] = 0;

    // para cada elemento de x, vai percorrer o vetor de y
    for (i = 0; i < size_x; i++)
    {
        int cur = 0;
        for (j = 0; j < size_y; j++)
        {
            if (x[i] == y[j])
                vec_res[j] = max(vec_res[j], cur + 1);
            if (y[j] < x[i] && vec_res[j] > cur)
                cur = vec_res[j];
        }
    }
    // ir buscar ao vetor o maior comprimento
    int max_len = 0;
    for (i = 0; i < size_y; i++)
    {
        max_len = max(max_len, vec_res[i]);
    }

    cout << max_len << endl;
    return 0;
}