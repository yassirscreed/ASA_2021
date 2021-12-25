#include <iostream>
#include <vector>
#include <map>
using namespace std;


int problema1();
void problema2();

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
    // meter todas as entradas do vetor a 1
    for(i = 0; i < size_s; i++)
        comps[i] = 1;
    map<int, int> quant;
    quant[1] = 1;    
    for(i=1 ; i < size_s; i++){
        for(j = 0; j < i; j++){
            if(s[j] < s[i]){
                if(comps[i] < comps[j] + 1)
                    comps[i] = comps[j] + 1; 
            }
        }
        //verifica se o tamanho ja existe no mapa de quantidade de tamanhos
        if (quant.find(comps[i]) == quant.end())
            quant[comps[i]] = 1;
        else
            quant[comps[i]]++;
    }
    int lenght = 0, num_subs = 1;
    for(auto const &x : quant){
        num_subs *= x.second;
        if (x.first > lenght)
            lenght = x.first;
    }
    cout << lenght << " " << num_subs << endl;
    return 0;
}

void problema2(){
    vector<int> x(0);
    vector<int> y(0);
    int i;
    //ler o input 
    while(cin >> i){
        x.push_back(i);
        if (cin.get() == '\n'){
            break;
        }
    }
    while(cin >> i){
        y.push_back(i);
        if (cin.get() == '\n'){
            break;
        }
    }
    //algoritmo
    
}
