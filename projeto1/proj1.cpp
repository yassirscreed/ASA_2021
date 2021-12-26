#include <iostream>
#include <vector>
#include <iterator>
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
    cout << 1 << endl;
    
}