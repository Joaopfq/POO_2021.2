#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

//MANIPULAÇÃO

bool unicos(vector<int>& fila, int num){ 
    int contador{0};

    for(int valor : fila){
        if(abs(valor) == abs(num))
            contador++;
        if(contador > 1)
            return false;
    }
    return true;
}

vector<int> sozinhos(vector<int>& fila){

    vector<int> sozinhos{};
    for(int valor : fila){
        if(unicos(fila, valor)){
            sozinhos.push_back(abs(valor));
        }
    }
    return sozinhos;
}

int contar_ocorrencia(vector<int> fila, int num){
    int contador{0};

    for(int stress : fila){
        if(abs(stress) == abs(num))
        contador++;
    }
    return contador;
}

int maior_ocorrencia(vector<int> fila){
    int maior_ocorre{0};

    for(int stress : fila){
        if(contar_ocorrencia(fila, stress) >  maior_ocorre){
             maior_ocorre = contar_ocorrencia(fila, stress);
        }
    }
    return  maior_ocorre;
}

vector<int> exclusivos(const vector<int> &vet)
{
	vector<int> exclusivos{};

	for (int i = 0; i < (int) vet.size(); i++) {
		if (find(exclusivos.begin(), exclusivos.end(), vet[i]) == exclusivos.end())
			exclusivos.push_back(vet[i]);
	}	
	return exclusivos;
}

vector<int> mais_recorrentes(vector<int> fila){
    int  maior_ocorre {maior_ocorrencia(fila)};
    vector<int> recorrente{};

    for(auto i = fila.begin(); i!= fila.end(); i++){
        if(contar_ocorrencia(fila, *i) == maior_ocorre)
            recorrente.push_back(abs(*i));
    }
    return exclusivos(recorrente);
}

// PROXIMIDADE

int briga(const vector<int>& fila){
    int conta_brigas{};
    
    for(int i = 1; i < ((int)fila.size() - 1); i++){
        if(fila[i] > 50 && (fila[i-1] > 30 && fila[i+1] > 30))
            conta_brigas++;
    }
    return conta_brigas;
}

int apaziguado(const vector<int>& fila){
    int brigas_apaziguadas{};
    
    for(int i = 1; i < ((int)fila.size() - 1); i++){
        if(fila[i] > 80 && (fila[i-1] < 10 || fila[i+1] < 10))
            brigas_apaziguadas++;
    }
    return brigas_apaziguadas;
}

//SEQUÊNCIAS: NÂO CONSEGUI FAZER

int tamanho_time(std::vector<int> &aux, int tamanho_atual, Sexo sexo_time);

int quantos_times(const std::vector<int> &fila);

vector<int> maior_time();

int abandonados();

//GRUPOS

int casais(vector<int>& fila){ 

    int conta_casais{0};
    int homens{0};
    int mulheres{0};

    for(int i = 0; i < (int)fila.size(); i++){
        if (fila[i] < 0)
            mulheres++;
        else
            homens++;
        if(mulheres >= 1 && homens >= 1){
            conta_casais++;
            mulheres--;
            homens--;
        }
            
    }
    return conta_casais;
}

int conta_trios(vector<int>& fila); // NÂO CONSEGUI FAZER

//ALTERAÇÃO 


void remove(vector<int>& fila){
    int remover;
    cin >> remover;

    fila.erase(fila.begin() + remover);
}

void insert(vector<int>& fila){

    int pos;
    int stress;
    cin >> stress >> pos;

    fila.insert(fila.begin() + pos, stress);  
}

vector<int> dance(vector<int>& fila){

    for(int i = 0; i < (int)fila.size() - 1; i++){
        if(abs(fila[i]) == abs(fila[i+1])){
            fila.erase(fila.begin() + i);
            fila.erase(fila.begin() + i);
            i = 0;
        }
        else if (abs(fila[i]) ==  abs(fila[i-1])){
            fila.erase(fila.begin() + i);
            fila.erase(fila.begin() + i-1);
            i = 0;
        }
    }
    return fila;
}

int main(){
    vector<int> fila {90, -90, -90, 90, 1, 1, 1, 1, 91};
    //vector<int> fila_test = mais_recorrentes(fila);
    cout << quantos_times(fila);

    //for(int i = 0; i < (int)fila_test.size(); i++)
    //cout << fila_test[i] << ' ';
    
}