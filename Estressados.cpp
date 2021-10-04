#include <iostream>

#define size 6
using namespace std;

//BUSCA

bool existe(int vet[])
{
    int i = 0;
    int valor = 0;

    cout << "Digite o valor: ";
    scanf("%d", &valor );

    for (i = 0; i < size; i++) {
        if (valor == vet[i]) {
            return true;
        }    
    }
    return false;
}

int contar(int vet[])
{
    int i = 0;
    int valor = 0;
    int contador = 0;

    cout << "Digite o valor: ";
    scanf("%d", &valor );

    for (i = 0; i < size; i++) {
        if (valor == vet[i])
            contador++;
    }
    return contador;
}

int procurar_valor(int vet[])
{
    int i = 0;
    int valor = 0;

    cout << "Digite o valor: ";
    scanf("%d", &valor );

    for (i = 0; i < size; i++) {
        if (valor == vet[i]){
            return (i + 1);
            break;
        }
    }
    return -1;
}

int procurar_valor_apos(int vet[])
{
    int i = 0;
    int valor = 0;

    cout << "Iniciar a busca pela posicao: ";
    scanf("%d", &i );

    cout << "Digite o valor: ";
    scanf("%d", &valor );

    for (i = (i - 1); i < size; i++) {
        if (valor == vet[i])
            return (i + 1);     
    }
    return -1;
}

// MELHOR CASO

int procurar_menor(int vet[])
{
    int i = 0;
    int menor = 99;

    for (i = 0; i < size; i++) {
        if (vet[i] < menor)
            menor = vet[i];                   
    }
    return menor;
}

int procurar_maior(int vet[])
{
    int i = 0;
    int maior = 0;

    for (i = 0; i < size; i++) {
        if (vet[i] > maior)
            maior = vet[i];       
    }
    return maior;
}

int procurar_menor_pos(int vet[])
{
    int i = 0;
    int menor = 99;
    int pos = 0;

    for (i = 0; i < size; i++) {
        if (vet[i] < 0)
            vet[i] = (vet[i] * -1);

        if (vet[i] <= menor ) {
            menor = vet[i];
            pos = i;
        }
    }
    return (pos + 1);
}

int posicao_menor_pos_apartir(int vet[])
{
    int i = 0;
    int j = 0;
    int pos = 0;
    int menor = 99;

    cout << "Iniciar a busca pela posicao: ";
    scanf("%d", &j );

    for (i = (j - 1); i < size; i++) {
        if (vet[i] < 0){
            vet[i] = (vet[i] * -1);
        }
        if (vet[i] < menor ) {
            menor = vet[i];
            pos = i;
        }       
    }
    return (pos + 1);
}

int procurar_melhor_pos_se(int vet[])
{
    int i = 0;
    int Menor_HMC = 99;
    for (i = 0; i < size; i++) {
        if(vet[i] > 0){
            if(vet[i] < Menor_HMC) {
                Menor_HMC = vet[i];
            }
        }
    }
    for (i = 0; i < size; i++) {
        if(vet[i] == Menor_HMC)
        return i;
    }
    return -1;
}

//CONTAGEM

float calcular_stress_medio(int vet[])
{
    int i = 0;
    float soma = 0;

    for (i = 0; i < size; i++) {
        if (vet[i] < 0) {
            soma = soma + (vet[i] * -1);
        }
        else {
            soma = soma + vet[i];
        }
    }
    return (soma/size);
}

string mais_homens_ou_mulheres(int vet[])
{
    int i = 0;
    int Conta_Mulheres = 0;
    int Conta_Homens = 0;

    for (i = 0; i < size; i++) {
        if (vet[i] < 0)
            Conta_Mulheres++;
        else
            Conta_Homens++;
    }
    if(Conta_Mulheres > Conta_Homens)
        return "Mulheres";
    else if(Conta_Homens > Conta_Mulheres)
        return "Homens";
    else 
        return "Empate";

}

string qual_metade_eh_mais_estressada(int vet[])
{
    int i = 0;
    int Primeira = 0;
    int Segunda = 0;

    for (i = 0; i < (size/2); i++) {
        if (vet[i] < 0)
            Primeira = Primeira + (vet[i] * -1); 
        else
            Primeira = Primeira + vet[i]; 
    }
    for (i = (size/2); i < size; i++) {
        if (vet[i] < 0)
            Segunda = Segunda + (vet[i] * -1); 
        else
            Segunda = Segunda + vet[i];
    }
    if (Primeira > Segunda)
        return "Primeira";
    else if (Primeira < Segunda)
        return "Segunda";
    else 
        return "Empate";
}

string homens_sao_mais_estressados_que_mulheres(int vet[])
{
    int i = 0;
    float Stress_homens = 0;
    float Stress_mulheres = 0;
    int Conta_homens = 0;
    int Conta_mulheres = 0;

    for (i = 0; i < size; i++) {
        if (vet[i] < 0) {
            Stress_mulheres = Stress_mulheres + (vet[i] * -1);
            Conta_mulheres++;
        }
        else {
            Stress_homens = Stress_homens + vet[i];
            Conta_homens++;
        }
    }
    if ((Stress_homens/Conta_homens) > (Stress_mulheres/Conta_mulheres))
        return "A media dos homens é maior";
    else if ((Stress_homens/Conta_homens) < (Stress_mulheres/Conta_mulheres))
        return "A media das mulhers é maior";
    else 
        return "Empate";
}

int main()
{
    int vet[size] = {-51, 99, 1, -50, -1, -99};

    cout << existe(vet);
}