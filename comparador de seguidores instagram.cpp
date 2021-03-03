#include <fstream>
#include <string>
#include <iostream>
#include <locale.h>
#include <string.h>

//Programa para informar os novos seguidores de uma pessoa no instagram.
//Para isso, você precisa pegar uma lista de seguidores antiga e uma atual,
//o programa vai comparar as duas e dizer quem está na atual e não esta na antiga, ou seja, quem são os novos seguidores

using namespace std;

int main()
{
    string nomes[10000];
    string nomesNovos[10000];
    std::ifstream file("seguidoresAntigos.txt"); //Coloque a lista de seguidores antigos
    std::ifstream file2("seguidoresAtuais.txt"); //Coloque a lista de seguidores antuais
    std::fstream txt_saida;
    std::string str;
    std::string descarta;
    long int contador = 0, limite = 0, limite2 = 0;
    bool encontrou = false;


    //compatibilidade de caracteres
    setlocale(LC_ALL, "Portuguese");

    txt_saida.open("saida_formatada.txt", ios::out | ios::app);

    //Enquanto tiver linha le arquivo 1
    while (std::getline(file, str))
    {
        nomes[contador].append(str);

        contador++;

        // cout << nomes[contador-1] << endl;

        //txt_saida << "\n";

    }

    limite = contador; //definiu o final do vetor de nomes

    contador = 0;
    //Enquanto tiver linha le arquivo 2
    while (std::getline(file2, str))
    {
        nomesNovos[contador].append(str);
        contador++;

        //cout << nomesNovos[contador-1] << endl;

        //txt_saida << "\n";

    }
    limite2 = contador; //definiu o final do vetor de nomes do arquivo 2

    for (long int contador2 = 0; contador2 < limite2; contador2++)
    {
        // cout <<"Comparando: "<< nomesNovos[contador2].substr(0, 5 ) << " Com: "<< endl;
        encontrou = false;

        for (contador = 0; contador < limite; contador++)
        {
            // cout << nomes[contador] << endl;
            if (strstr( nomes[contador].c_str(), nomesNovos[contador2].substr(0, 5 ).c_str()))
            {
                //cout << "Encontrou!" << endl;
                encontrou = true;
                break;
            }
        }
        if (!encontrou)
        {
            //cout << nomesNovos[contador2] << "Não encontrado!" << endl;//printa nome nao encontrado
            txt_saida << nomesNovos[contador2];
            txt_saida << "\n";
        }
    }
    txt_saida.close();
}
