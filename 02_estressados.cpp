#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <algorithm>

using namespace std;

//FILTER

vector<int> clonar_vetor(const vector<int> &vet)
{
	vector<int> vet_copy{};
	for (int i = 0; i < (int)vet.size(); i++)
		vet_copy.push_back(vet[i]);
	return vet_copy;
}

vector<int> pegar_homens(const vector<int> &vet)
{
	vector<int> homens{};
	for (int i = 0; i < (int)vet.size(); i++)
	{
		if (vet[i] > 0)
			homens.push_back(vet[i]);
	}
	return homens;
}

vector<int> pegar_calmos(const vector<int> &vet)
{
	vector<int> calmos{};
	for (int i = 0; i < (int)vet.size(); i++)
	{
		if (vet[i] < 10 && vet[i] > -10)
			calmos.push_back(vet[i]);
	}
	return calmos;
}

vector<int> pegar_mulheres_calmas(const vector<int> &vet)
{
	vector<int> mulheres_calmas{};
	for (int i = 0; i < (int)vet.size(); i++)
	{
		if (vet[i] > -10 && vet[i] < 0)
			mulheres_calmas.push_back(vet[i]);
	}
	return mulheres_calmas;
}

//ACESSO

vector<int> inverter_com_copia(vector<int> &vet)
{
	vector<int> invertido{};
	int j {(int)vet.size()};
	int aux{};

	invertido = vet;
	j--;

	for(int i = 0; i < (int) vet.size()/2; i++){
		
		aux = invertido[i];
		invertido[i] = invertido[j];
		invertido[j] =  aux;
		j = j - 1;
	}
	return invertido;
}

void inverter_inplace(vector<int> &vet)
{
	int j{(int)vet.size()};
	j--;

	for(int i = 0; i < ((int) vet.size()/2); i++){
		swap(vet[i], vet[j]);
		j--;
	}
}

int sortear(const vector<int> &vet)
{
	int posicao_sorteada{};
	srand(time(NULL));

	posicao_sorteada = rand() % (int)vet.size();

	return vet[posicao_sorteada];
}

void embaralhar(vector<int> &vet)
{
	srand(time(NULL));
	for(int i = 0; i < (int) vet.size(); i++){
		int posicao = rand() % vet.size();
		swap(vet[i], vet[posicao]);
	}
}

void ordenar(vector<int> &vet)
{
	for(int i = 0; i < (int) vet.size(); i++){
		for(int i = 0; i < (int) vet.size(); i++){
			if(vet[i] > vet[i + 1])
				swap(vet[i], vet[i + 1]);
		}
	}
}

//CONJUNTOS

vector<int> exclusivos(const vector<int> &vet)
{
	vector<int> exclusivos{};

	for (int i = 0; i < (int) vet.size(); i++) {
		if (find(exclusivos.begin(), exclusivos.end(), vet[i]) == exclusivos.end())
			exclusivos.push_back(vet[i]);
	}	
	return exclusivos;
}

vector<int> diferentes(const vector<int>& vet)
{
	vector<int> diferentes{};

	for (int i = 0; i < (int) vet.size(); i++) {
		if (find(diferentes.begin(), diferentes.end(), abs(vet[i])) == diferentes.end())
			diferentes.push_back(abs(vet[i]));
	}	
	return diferentes;
}

vector<int> abandonados(const vector<int>& vet)
{
	vector<int> abandonados{};
	vector<int> acolhidos{};

	for (int i = 0; i < (int) vet.size(); i++) {
		if (find(acolhidos.begin(), acolhidos.end(), (vet[i])) == acolhidos.end())
			acolhidos.push_back((vet[i]));
		else
			abandonados.push_back((vet[i]));
	}	
	return abandonados;
}


int main()
{
	vector<int> vet{6, 5, -6, -6, 6, 1};

	vector<int> vet_test = abandonados(vet);
	for(int i = 0; i < (int) vet_test.size(); i++)
		cout << vet_test[i] << ' ';
}