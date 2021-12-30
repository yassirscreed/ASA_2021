#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;


int problema1();
int problema2();
int find_smaller_map(map<int, vector<int> > comp_val, int comp, int value);
int binarySearch(vector<int> aux, int low, int high, int key);

int main(){
    int nprob;
    cin >> nprob;
    if(nprob == 1){
        problema1();
    }
    else if (nprob == 2){
        problema2();
    }
    return 0;
}

int problema1(){
    vector<int> s(0);
    int i,j;
    // ler o input 
    while(cin >> i){
        s.push_back(i);
        if (cin.get() == '\n'){
            break;
        }
    }
    //algoritmo
    int size_s = s.size();
    // caso base
    if (size_s == 1){
        cout << "1 1" << endl;
        return 0;
    }
    vector<int> comps(size_s);
    vector<int> numbersubs(size_s,1);
    comps[0] = 1;    
    for(i=1 ; i < size_s; i++){
        //ir metendo a entrada do vetor comp a 1
        comps[i] = 1;
        for(j = 0; j < i; j++){
            if(s[j] < s[i]){
                if(comps[i] < comps[j] + 1){
                    comps[i] = comps[j] + 1; 
                    numbersubs[i] = numbersubs[j];
                }
                // caso em que existe masi uma subsequencia
                else if(comps[i] == comps[j] + 1)
                    numbersubs[i] += numbersubs[j];
            }
        }
    }
    int lenght = 0;
    //descobrir o comprimento maximo
    for(i = 0; i < size_s; i++){
        if(comps[i] > lenght)
            lenght = comps[i];
    }
    int num_subs = 0;
    //descobrir o numero de subsequencias
    for(i = 0; i < size_s; i++){
        if(comps[i] == lenght)
            num_subs += numbersubs[i];
    }
    cout << lenght << " " << num_subs << endl;
    return 0;
}

int problema2(){
    vector<int> x(0);
    vector<int> aux(0);
    vector<int> y(0);
    int i;
    //ler o input 
    while(cin >> i){
        x.push_back(i);
        aux.push_back(i);
        if (cin.get() == '\n'){
            break;
        }
    }
    sort(aux.begin(), aux.end());
    
    while(cin >> i){
        if(binarySearch(aux,0,aux.size(),i) != -1)
            y.push_back(i);

        if (cin.get() == '\n'){
            break;
        }
    }

    //algoritmo
    int size_x = x.size(), size_y = y.size();
    for(i=0; i< size_y; i++){
        cout << y[i]<<endl; 
    }
    vector<vector<int>> matrix;

    //coluna 0 a 0's
    for(int i=0; i <= size_x; i++){
        matrix.push_back(vector<int>());
        matrix[i].push_back(0);    
    }

    //linha 0 a 0's
    for(i=0;i<=size_y;i++){
        matrix[0].push_back(0);
    }

    map<int, vector<int> > comp_val;
    comp_val[0].push_back(0);

    //preencher a matriz com o algoritmo
    for(int i=1; i <= size_x; i++){
        for(int j=1; j <= size_y; j++){
            if(x[i-1] == y[j-1]){
                if(find_smaller_map(comp_val,matrix[i-1][j-1],x[i-1]) == 1){
                    matrix[i].push_back(matrix[i-1][j-1] + 1);
                    //meter no mapa com key = comp, o numero
                    comp_val[matrix[i][j]].push_back(x[i-1]);
                }
                else
                    matrix[i].push_back(max(matrix[i][j-1], matrix[i-1][j]));
            }
            else
                matrix[i].push_back(max(matrix[i][j-1], matrix[i-1][j]));
        }
    }

    /*for(int i = 0; i<=size_x; i++){
        for(int j = 0; j<=size_y; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }*/

    cout << matrix[size_x][size_y] << endl;

    return 0;
}

int find_smaller_map(map<int, vector<int> > comp_val, int comp, int value){
    //se existe no map vamos ver se ha valor menor
    if (comp_val.count(comp) == 1){
        int i = *min_element(comp_val[comp].begin(), comp_val[comp].end());
        if(i < value)
            return 1;
        else return 0;
    }
    return 1;
}


int binarySearch(vector<int> aux , int low, int high, int key)
{
    if (high < low)
        return -1;
    int mid = (low + high) / 2; 
    if (key == aux[mid])
        return mid;
    if (key > aux[mid])
        return binarySearch(aux, (mid + 1), high, key);
    return binarySearch(aux, low, (mid - 1), key);
}