// TRABALHO 1 - LISTAS SEQUENCIAIS E LISTAS LIGADAS//
// Aluno: Elienai Benevides da Cruz. RA: 2413914
// Turma s73 Estruturas de dados1 //
//#include "node_list.h"
#include "head.h"
//#include "seq_list.h"
//#include "head_node.h"
//#include "head_seq.h"
//#include "systema.h"
#include <iostream>
#include <fstream>
#define  vfork fork
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#define MAX_SIZE 100000
using namespace std;

int main()
{
    head::node_list node, *ptr_node;
    head::seq_list *ptr_seq;
    string name = "NomeRG1K.txt";
    int options;
    string name_;
    string rg_;
    int index;
    head::node_list *p;
    head::seq_list *a;
    int tam;
    int ultimo = 0;
    string rg_wanted;
    head HEAD;
    head::head_node HEAD_NODE;
    head::head_seq HEAD_SEQ;
    head::seq_list sequencial_elemento[MAX_SIZE];
    HEAD_NODE.txt_node(name,p);
    HEAD_SEQ.txt_seq(name, sequencial_elemento, &tam);

        int flag = 0;
        options = 0;
        int i = 0;
        cout << "ENTRE COM A OPCAO"  << endl;
        cout << "********************************************************"  << endl;
        cout << "1)Inserção de um nó no início da lista                 *"  << endl;
        cout << "2)Inserção de um nó no fim da lista                    *"  << endl;
        cout << "3)Inserção de um nó no fim da lista seq                *"  << endl;
        cout << "4)Inserção de um nó na posição N                       *"  << endl;
        cout << "5)Inserção de um nó na posição N seq                   *"  << endl;
        cout << "6)Retirar um nó do início da lista                     *"  << endl;
        cout << "7)Retirar um nó no fim da lista                        *"  << endl;
        cout << "8)Retirar um nó no fim da lista seq                    *"  << endl;
        cout << "9)Retirar um nó na posição N                           *"  << endl;
        cout << "10)Retirar um nó na posição N seq                      *"  << endl;
        cout << "11)Procurar um nó com o campo RG                       *"  << endl;
        cout << "12)ordenacao por merge sort                            *"  << endl;
        cout << "13)ordenacao por insertion sort                        *"  << endl;
        cout << "14)ordenacao por bubble sort                           *"  << endl;
        cout << "15)ordenacao por selection sort                        *"  << endl;
        cout << "16)ordenacao por quick sort                            *"  << endl;
        cout << "17)ordenacao por shell sort                            *"  << endl;
        cout << "18)Mostrar a lista na tela.                            *"  << endl;
        cout << "19)Salvar a lista em um arquivo.                      *"  << endl;
        cout << "20)Ler a lista de um arquivo, colocar na lista         *"  << endl;
        cout << "21)Sair do sistema.                                    *"  << endl;
        cout << "********************************************************"  << endl;

        while ((options) != -1) {

            cin >> options;
            switch(options)
            {
                case 1:
                 cout << "Entre com nome e rg" << endl;
                 cin >> name_;
                 cin >> rg_;
                 cout << "Lista ligada :" << endl;
                 cout << "*****************************" << endl;
                 HEAD_NODE.insert_begin_node(name_,rg_,p);
                 cout << " sequencial :" << endl;
                 cout << "*****************************" << endl;
                 HEAD_SEQ.inserirNoInicio(name_, rg_);
                break;
                case 2:
                 cout << "Entre com nome e rg" << endl;
                 cin >> name_;
                 cin >> rg_;
                 cout << "Lista ligada :" << endl;
                 cout << "*****************************" << endl;
                 HEAD_NODE.end_node(name_ , rg_, p);
                 HEAD_SEQ.insertar(name_, rg_, sequencial_elemento, &tam);
                 //ptr_node->set_afiliate(&HEAD1);
                 //ptr_seq->afiliate(&HEAD1);
                break;
                case 3:
                 cout << "Entre com nome e rg sequencial" << endl;
                 cin >> name_;
                 cin >> rg_;
                 cout << "Lista sequencial: " << endl;
                 cout << "*****************************" << endl;
                break;
                case 4:
                 cout << "Entre com nome e rg e indice" << endl;
                 cin >> name_;
                 cin >> rg_;
                 cin >> index;
                 cout << "Lista ligada :" << endl;
                 cout << "*****************************" << endl;
                 HEAD_NODE.middle_node(name_ , rg_,index, p);
                break;
                case 5:
                 cout << "Entre com nome e rg e indice da sequencial" << endl;
                 cin >> name_;
                 cin >> rg_;
                 cin >> index;
                 cout << "Lista sequencial: " << endl;
                 cout << "*****************************" << endl;
                 HEAD_SEQ.inserirNoMeio(name_, rg_, index);
                break;
                case 6:
                 cout << "Lista ligada :" << endl;
                 cout << "*****************************" << endl;
                 HEAD_NODE.remov_node_begin();
                 cout << "Lista sequencial: " << endl;
                 cout << "*****************************" << endl;
                 HEAD_SEQ.removerNoInicio();
                break;
                case 7:
                 cout << "Lista ligada : " << endl;
                 cout << "*****************************" << endl;
                 HEAD_NODE.remov_node_end();
                break;
                case 8:
                 cout << "Lista sequencial: " << endl;
                 cout << "*****************************" << endl;
                 HEAD_SEQ.removerNoFim();
                break;
                case 9:
                 cout << "Entre com o indice da remocao" << endl;
                 cin >> index;
                 cout << "Lista ligada :" << endl;
                 cout << "*****************************" << endl;
                 HEAD_NODE.remov_node_middle(index);
                break;
                case 10:
                cout << "Entre com o indice da remocao sequencial" << endl;
                cin >> index;
                cout << "Lista sequencial: " << endl;
                cout << "*****************************" << endl;
                HEAD_SEQ.removerNoMeio(index);
                break;
                case 11:
                head::seq_list *ptrS;
                head::node_list *ptrN;
                 cout << "Entre com o rg desejado" << endl;
                 cin >> rg_wanted;
                 cout << "--------------" << endl;
                 ptrN = HEAD_NODE.search_node(rg_wanted);
                 ptrS = HEAD_SEQ.search_node(rg_wanted);
                // HEAD_SEQ.search_node(a, rg_wanted);
                  //cout << "retorno seq" << ptr_seq->rg << endl;
                 //search_node_main_1(rg_wanted, &HEAD_NODE);
                //search_node_main(rg_wanted, &HEAD_SEQ);
                 cout << "--------------" << endl;
                 //a->search_node(rg_wanted, &HEAD_SEQ);
                break;
                case 12:
                HEAD_NODE.Sort();
                break;
                case 13:
                 HEAD_NODE.Insertion();
                break;
                case 14:
                 HEAD_NODE.Bubble();
                break;
                case 15:
                 HEAD_NODE.Selection();
                break;
                case 16:
                 HEAD_NODE.QuickSort();
                break;
                case 17:
                 HEAD_NODE.Shell();
                break;
                case 18:
                 cout << "Lista ligada :" << endl;
                 cout << "*****************************" << endl;
                 //HEAD1.listar_seq_list(ptr_seq);
                 HEAD_NODE.listar();
                 cout << "Lista sequencial: " << endl;
                 cout << "*****************************" << endl;
                 HEAD_SEQ.listar_seq_list(sequencial_elemento);
                break;
                case 19:
                 //salvar lista em um arquivo
                 HEAD_NODE.listar_nodes_up();
                break;
                case 20:
                 //ler a lista de um arq e colocar no sistema
                break;
                case 21:
                 options = -1;
                break;
                default:
                if(options != -1) {
                    cout << "opcao invalida" << endl;
                }
            }
        }
    return 0;
}

