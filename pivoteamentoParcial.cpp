#include <iostream>
#include <math.h>
#define precisao 1000000
using namespace std;

int calcularMDC(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return calcularMDC(b, a % b);
    }
}

void encontrarFracaoGeradora(float numero)
{
    long int numerador = (int)(numero * precisao);
    long int denominador = precisao;
    long int mdc = calcularMDC(numerador, denominador);
    numerador /= mdc;
    denominador /= mdc;
    if (denominador == 1)
    {
        cout << numerador << "    ";
    }
    else
    {
        if (numerador == 0)
        {
            denominador = 0;
            cout << 0 << "    ";
        }
        else
        {
            cout << numerador << '/' << denominador << "    ";
        }
    }
}

void trocarLinhas(double **matriz, int tamanhoMatriz, int linha, int linha2)
{
    cout << "Trocando linha " << linha << " por linha " << linha2 << endl;
    double aux = 0.00;
    for (int i = 0; i <= tamanhoMatriz; i++)
    {
        aux = matriz[linha][i];
        matriz[linha][i] = matriz[linha2][i];
        matriz[linha2][i] = aux;
    }
}

void mostrarMatrizAumentada(double **matriz, int tamanhoMatriz)
{
    cout << "Matriz aumentada " << endl;
    for (int i = 0; i < tamanhoMatriz; i++)
    {
        for (int j = 0; j <= tamanhoMatriz; j++)
        {
            encontrarFracaoGeradora(matriz[i][j]);
        }
        cout << endl;
    }
}

void preencherMatriz(double **matriz, int tamanhoMatriz)
{
    double valor = 0.0;
    for (int i = 0; i < tamanhoMatriz; i++)
    {
        for (int j = 0; j < tamanhoMatriz; j++)
        {
            cout << "Insira os valores do termo  A" << i + 1 << j + 1 << " linha na matriz " << endl;
            cin >> valor;
            matriz[i][j] = valor;
        }
    }
}

void eliminacaoGaussAumentadaUmaColuna(double **matriz, int tamanhoMatriz, int linhaPivo)
{
    double multiplicador = 1.0;
    for (int i = (linhaPivo + 1); i < tamanhoMatriz; i++)
    {
        multiplicador = matriz[i][linhaPivo] / matriz[linhaPivo][linhaPivo];
        for (int j = 0; j <= tamanhoMatriz; j++)
        {
            matriz[i][j] = matriz[i][j] - multiplicador * matriz[linhaPivo][j];
        }
    }
}

double determinanteLaplace(int tamanhoMatriz, double **matriz)
{
    if (tamanhoMatriz == 1)
    {
        return matriz[0][0];
    }
    else
    {
        double determinante = 0.0;
        int j, k, jAux, iAux;

        for (int i = 0; i < tamanhoMatriz; i++)
        {
            if (matriz[0][i] != 0)
            {
                double **aux;
                aux = new double *[tamanhoMatriz];
                for (int i = 0; i < tamanhoMatriz; i++)
                {
                    aux[i] = new double[tamanhoMatriz];
                }
                int iAux = 0;
                int jAux = 0;
                for (j = 1; j < tamanhoMatriz; j++)
                {
                    for (k = 0; k < tamanhoMatriz; k++)
                    {
                        if (k != i)
                        {
                            aux[iAux][jAux] = matriz[j][k];
                            jAux++;
                        }
                    }
                    iAux++;
                    jAux = 0;
                }
                double fator = (i % 2 == 0) ? matriz[0][i] : -matriz[0][i];
                determinante = determinante + fator * determinanteLaplace(tamanhoMatriz - 1, aux);
            }
        }
        return determinante;
    }
}

void preenchervetorTermoIndependente(double *vetorTermoIndependente, int tamanhoMatriz)
{
    double valor = 0;
    cout << "Insira os termos independentes " << endl;
    for (int i = 0; i < tamanhoMatriz; i++)
    {
        cin >> valor;
        vetorTermoIndependente[i] = valor;
    }
}

void checarPivoMatriz(double **matriz, int tamanhoMatriz, int colunaPivo)
{
    double pivo;
    int linhaPivo;

    for (int i = colunaPivo; i <= (tamanhoMatriz - 1); i++)
    {
        pivo = matriz[colunaPivo][colunaPivo];
        linhaPivo = colunaPivo;
        if ((fabs(matriz[i][colunaPivo])) > (fabs(pivo)))
        {
            pivo = matriz[i][colunaPivo];
            linhaPivo = i;
            cout << "pivo ";
            encontrarFracaoGeradora(pivo);
            cout << "linha pivo " << linhaPivo << endl;
            trocarLinhas(matriz, tamanhoMatriz, colunaPivo, linhaPivo);
            cout << endl;
        }
    }
}

void preencheMatrizAumentada(double **MatrizAumentada, double **matriz2, double *vetorTermoIndependente, int tamanhoMatriz)
{
    for (int j = 0; j < tamanhoMatriz; j++)
    {
        for (int i = 0; i < tamanhoMatriz; i++)
        {
            MatrizAumentada[j][i] = matriz2[j][i];
            MatrizAumentada[j][i + 1] = vetorTermoIndependente[j];
        }
    }
}

void solucionaSistema(double **matriz, int tamanhoMatriz, double *vetorResultado)
{
    for (int i = 1; i <= tamanhoMatriz; ++i)
    {
        double numerador = matriz[tamanhoMatriz - i][tamanhoMatriz];
        for (int j = 1; j < i; ++j)
        {
            numerador -= (matriz[tamanhoMatriz - i][tamanhoMatriz - j] * vetorResultado[tamanhoMatriz - j]);
        }
        vetorResultado[tamanhoMatriz - i] = numerador / matriz[tamanhoMatriz - i][tamanhoMatriz - i];
    }
    for (int i = 0; i < tamanhoMatriz; ++i)
    {
        cout << "x" << i + 1 << "º = ";
        encontrarFracaoGeradora(vetorResultado[i]);
    }
    cout << endl;
}

int main()
{
    int i, j, k, lin, col, tamanhoMatriz = 0;
    cout << "Tamanho da matriz" << endl;
    cin >> tamanhoMatriz;
    double *vetorResultado, *vetorTermoIndependente;
    double **matriz, **matrizAumentada;

    matriz = new double *[tamanhoMatriz];
    for (int i = 0; i < tamanhoMatriz; i++)
    {
        matriz[i] = new double[tamanhoMatriz];
    }

    matrizAumentada = new double *[tamanhoMatriz];
    for (int i = 0; i <= tamanhoMatriz; i++)
    {
        matrizAumentada[i] = new double[tamanhoMatriz];
    }

    vetorResultado = new double[tamanhoMatriz];
    vetorTermoIndependente = new double[tamanhoMatriz];

    preencherMatriz(matriz, tamanhoMatriz);

    if (determinanteLaplace(tamanhoMatriz, matriz) == 0)
    {
        cout << endl;
        cout << "Determinante = " << determinanteLaplace(tamanhoMatriz, matriz) << endl;
        return -1;
    }
    else
    {
        system("clear");
        cout << endl;
        cout << "Determinante =  " << determinanteLaplace(tamanhoMatriz, matriz) << endl;
        preenchervetorTermoIndependente(vetorTermoIndependente, tamanhoMatriz);
        preencheMatrizAumentada(matrizAumentada, matriz, vetorTermoIndependente, tamanhoMatriz);
        cout << endl;
        system("clear");
        for (int i = 0; i < tamanhoMatriz; i++)
        {
            mostrarMatrizAumentada(matrizAumentada, tamanhoMatriz);
            checarPivoMatriz(matrizAumentada, tamanhoMatriz, i);
            cout << endl;
            eliminacaoGaussAumentadaUmaColuna(matrizAumentada, tamanhoMatriz, i);
            cout << endl;
            cout << endl;
        }
        solucionaSistema(matrizAumentada, tamanhoMatriz, vetorResultado);
        cout << endl;
    }
}
