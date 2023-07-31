#ifndef _HEAD_H_
#define _HEAD_H_
#include <string>
#include <cstddef>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#define MAX_SIZE 100000
//#include "systema.h"
//#include "head_node.h"
//#include "head_seq.h"
#include <vector>
using namespace std;
//class node_list;
//class seq_list;
//class systema;
//class head_node;
//class head_seq;
class head
{
  public:

  /**************HEAD_NODE************************/
   /**************NODE_LIST************************/
class node_list
{
  public:
  string name;
  string rg;
  head *a;
  head *head_afiliate = nullptr;
  node_list *p = nullptr;
  int n;
  node_list *pInfo;

  int conta;
  int n_node = 0;
  int comp = 0;
  int moviment = 0;

  public:
  node_list *p_next;
  node_list *p_previous;
  node_list(string namecur, string rgcur, node_list *p);
  node_list();
  ~node_list();
  void start(string namecur, string rgcur);
  string *getname();
  string *getrg();
  void return_values();
  int acres();

  void insert(node_list *p);
  void teste (head *p, string name, string rg);
  void set_afiliate(head *pointer, string name, string rg);
  void listar();
  void return_values1();
  void setaname(string nome);
  //node_list* search_node(head_node *head, string rg_wanted);
  void partner(node_list *p);
  int count();
  void setInfo(node_list *pi);
  //void setar_address(head_node *p, string name, string rg);
};

  /**************NODE_LIST************************/
 class head_node
{
  public:
  //node_list *afiliate;
  vector<string> lista_node_name;
  vector<string> lista_node_rg;
  node_list *previous;
  node_list *cont;
  node_list *first = nullptr;
  node_list *second = nullptr;
  string name;

  int n_node = 0;
  int comp = 0;
  int moviment = 0;

  double time_ex = 0.0;

  public:
  head_node();
  ~head_node();

  void set_name(string n);
  void seta_lista_up(node_list *p, string name, string rg);

  void remov_node_begin();
  void remov_node_middle(int index);
  void remov_node_end();
  void listar_nodes_up();
  void listar_nodes_down();
  void swap_info(node_list* node1, node_list* node2);
  void QuickSort();
  node_list* search_node(const string &rg_wanted);

  void txt_node(const string &name, node_list *ptr_node);

  void insert_end_node(string name_, string rg_, node_list *node1);
  void insert_begin_node(string name_, string rg_, node_list *node2);
  void insert_middle_node(string name_, string rg_,int index, node_list *node3);

  void end_node(string name, string rg, node_list *p);
  void begin_node(string name, string rg, node_list *p);
  void middle_node(string name, string rg,int index, node_list *p);
  void Selection();
  void Insertion();
  void Bubble();
  void Shell();
  void Quick(node_list *low, node_list *high);
  node_list* merge(node_list* list1, node_list* list2);
  void split(node_list* head, node_list** front, node_list** back);
  void Sort();
  void MergeSort(node_list** head);
  int* swap_node(node_list *one, node_list *two, node_list *curr);
  void swap_selection(node_list* current, node_list* minNode);
  void particiona(node_list *p, int low, int high, int pivot);
  int* partition(node_list *low, node_list *high);


  void menu();
  void insert(int size, string name_, string rg_, node_list *p);
  void loop();
  void find();
  void deleted();
  void trig();
  void listar();
  void file_node(node_list *p);
  bool inclui_info(node_list *p, string name, string rg);
 };
  /**************HEAD_NODE************************/

  //////******************SEQ_LIST**********************//
  class seq_list {
    public:
    string name;
    string rg;
    head *a;
    seq_list *pInfo;
    //head_seq *head_afiliate;
    int N;

    int n_seq = 0;

    int comp_seq = 0;
    int moviment_seq = 0;
    public:
    seq_list *next = NULL;
    seq_list *previous = NULL;
    seq_list(string name_, string rg_, seq_list *p);
    seq_list();
    ~seq_list();
    void start_seq(string name_, string rg_);
   // void afiliate(head_seq *p, string name, string rg);
    int increase();
    void tam_zero();
    int get_tam();
    void return_values();

    void insert(seq_list *p);
    void teste(head *p);
    string *getname();
    string *getrg();
    void return_values1();
    void setInfo(seq_list *pi);

    //seq_list* search_node(head_seq *head, string rg_wanted);
};
//////******************SEQ_LIST**********************//

  /**************HEAD_SEQ************************/
  class head_seq
{
  public:

  vector<string> lista_seq_name;
  vector<string> lista_seq_rg;
  seq_list *afiliate1;
  string name;
  seq_list *sequencial_elemento;
  int tamanho;
  int capacidade;
  //seq_list *sequencial_s = nullptr;
  int n_seq = 0;

  int comp_seq = 0;
  int moviment_seq = 0;
  double time_ex_seq = 0.0;

  public:
  head_seq(int capacidadeInicial = 100) {
    //sequencial_elemento = new seq_list[capacidade];
    tamanho = 0;
    capacidade = capacidadeInicial;
    sequencial_elemento = NULL;
  }
  ~head_seq() {
    //delete[] sequencial_elemento;
  }
  void seta_lista_seq(seq_list *p, string name, string rg);

  void txt_seq(const string &name, seq_list *ptr_seq, int *tam);
  void buscanode(seq_list *b);

  void inserirNoInicio(string name, string rg) {
   time_ex_seq = 0.0;
    clock_t startTime = clock();
    //seq_list *var;
    int pos = 1;
    comp_seq = 0;
    if (tamanho == capacidade){
    comp_seq = (comp_seq) + 1;
        redimensionar();
    }
    for (int i = tamanho; i > 0; i--) {
        sequencial_elemento[i] = sequencial_elemento[i - 1];
    }
    sequencial_elemento[0].name = name;
    sequencial_elemento[0].rg = rg;
    n_seq = (n_seq) + 1;
    moviment_seq = 5;
    cout << "comparacoes " << comp_seq << endl;
    cout << "movimentacoes " << moviment_seq << endl;
    cout << "posic " << pos << endl;
    clock_t endTime = clock();
    clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    double time_ex_seq = timeInSeconds; // analisar aqui
    cout << "time de execucao lista sequencial " << time_ex_seq << endl;
    tamanho++;
  }
  void inserirNoMeio(string name, string rg, int index) {
   time_ex_seq = 0.0;
    clock_t startTime = clock();
     comp_seq = 0;
     if (index < 0 || index > tamanho){
        cout << "ERROR IN POSITION" << endl;
        return;
     }
     if (tamanho == capacidade) {
        redimensionar();
     }

      for (int i = tamanho; i > index; i--) {
        sequencial_elemento[i] = sequencial_elemento[i - 1];
      }
     sequencial_elemento[index].name = name;
     sequencial_elemento[index].rg = rg;
     moviment_seq = 6;
    cout << "comparacoes " << comp_seq << endl;
    cout << "movimentacoes " << moviment_seq << endl;
    cout << "posic " << index << endl;
    n_seq = (n_seq) + 1;
    clock_t endTime = clock();
    clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    double time_ex_seq = timeInSeconds;
    cout << "time de execucao lista sequencial " << time_ex_seq << endl;
    tamanho++;
  }

  void insertar(string name, string rg, seq_list *ptr, int *tam) {
   time_ex_seq = 0.0;
    clock_t startTime = clock();
    comp_seq = 0;
    if (tamanho >= MAX_SIZE) {
        cout << "FULL LISTa" << endl;
    }
    if (tamanho == capacidade) {
        redimensionar();
    }
    sequencial_elemento = ptr;
    /*ptr->name = name;
    ptr->rg = rg;
    sequencial_elemento[tamanho] = ptr[tamanho];*/
    sequencial_elemento[tamanho].name = name;
    sequencial_elemento[tamanho].rg = rg;
    n_seq += n_seq + 1;
    tamanho = tamanho + 1;
    *tam = tamanho;
  }
     void inserirNoFim(string name, string rg, seq_list *ptr, int *tam) {
        this->insertar(name, rg, ptr, tam);
        ptr->return_values();
    }
  void removerNoInicio() {
  time_ex_seq = 0.0;
    clock_t startTime = clock();
    seq_list *aux;
    seq_list *var_ant;
    comp_seq = 0;
    int pos = 1;
    if (tamanho == 0) {
        cout << "Empty List" << endl;
        return;
    }
    for (int i = 0; i < tamanho - 1; i++) {
        sequencial_elemento[i] = sequencial_elemento[i + 1];
    }
    moviment_seq = 5;
    cout << "comparacoes " << comp_seq << endl;
    cout << "movimentacoes " << moviment_seq << endl;
    cout << "posic " << pos << endl;
    n_seq = n_seq - 1;
    clock_t endTime = clock();
    clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    double time_ex_seq = timeInSeconds;
    cout << "time de execucao lista sequencial " << time_ex_seq << endl;
    tamanho = tamanho - 1;
  }
  void removerNoMeio(int index) {
   time_ex_seq = 0.0;
    clock_t startTime = clock();
    seq_list *var_curr, *aux, *var_ant;
    comp_seq = 0;
    if (index < 0 || index > tamanho) {
        cout << "ERROR IN INDEX" << endl;
        comp_seq = comp_seq + 1;
        return;
    }
    sequencial_elemento[index].return_values();
    for (int i = index; i < tamanho - 1; i++) {
        sequencial_elemento[i] = sequencial_elemento[i + 1];
    }
    moviment_seq = 7;
    cout << "comparacoes " << comp_seq << endl;
    cout << "movimentacoes " << moviment_seq << endl;
    cout << "posic " << index << endl;
    n_seq = n_seq - 1;
    clock_t endTime = clock();
    clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    double time_ex_seq = timeInSeconds;
    cout << "time de execucao lista sequencial" << time_ex_seq << endl;
    tamanho = tamanho - 1;
  }
  void removerNoFim() {
  time_ex_seq = 0.0;
    clock_t startTime = clock();
    seq_list *aux;
    seq_list *var_ant;
    int pos = 0;
    if (tamanho == 0) {
        cout << "Empty List" << endl;
        return;
    }
    sequencial_elemento[tamanho - 1] = sequencial_elemento[tamanho];
    moviment_seq = 5;
    cout << "comparacoes" << comp_seq << endl;
    cout << "movimentacoes" << moviment_seq << endl;
    cout << "posic" << n_seq << endl;
    n_seq = n_seq - 1;
    tamanho = tamanho - 1;
    clock_t endTime = clock();
    clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    time_ex_seq = timeInSeconds;
    cout << "time de execucao lista sequencial" << time_ex_seq << endl;
    /*if (tamanho <= capacidade / 2) {
        reduzirCapacidade();
    }*/

  }
  void reduzirCapacidade() {
        int new_size = capacidade / 2;
        seq_list *sequencial = new seq_list[new_size];
        for (int i = 0; i < tamanho; i++) {
            sequencial[i] = sequencial_elemento[i];
        }
       // delete[]sequencial_elemento;
        sequencial_elemento[0] = *sequencial;
        capacidade = new_size;
  }
  void remov_seq_end();

  void redimensionar() {
    int new_size = capacidade * 2;
    seq_list *new_Vetor = new seq_list[new_size];
    for(int i = 0; i < tamanho; i++) {
        new_Vetor[i] = sequencial_elemento[i];
    }
    //delete[]sequencial_elemento;
   // sequencial_elemento = new_Vetor;
    capacidade = new_size;
  }
  void listar_seq_list(seq_list *ptr) {
      int count = 1;
      seq_list *percorre;
      percorre = ptr;
      n_seq = 0;
      for(int i = 0; i < tamanho; i++, n_seq++) {
       cout << count++ << ")" ;
       cout << "name+: "<< percorre[i].name << endl;
       cout << "rg+: " << percorre[i].rg << endl;
        //cout << "name" << endl;
    }
     cout << "n_seq: " << n_seq << endl;
  }



  void end_seq(string name, string rg, seq_list *p);
  void begin_seq(string name, string rg, seq_list *p);
  void middle_seq(string name, string rg,int index, seq_list *p);

  void Selection();
  void Insertion();
  void Bubble();
  void Shell();
  void Quick(seq_list *p, int low, int high);
  void Merge();
  void swap(seq_list *one, seq_list *two);
  void particiona(seq_list *p, int low, int high, int pivot);

  seq_list* search_node(const string &rg_wanted);
  void menu();
  void set_name(string n);
  void loop();
  void find();
  void deleted();
  void realloca(seq_list *ptr, int new_size);
  void trig();
  void file_seq();
  bool inclui_info(seq_list *p, string name, string rg);
 };

  /**************HEAD_SEQ************************/
  node_list *afilia;
  node_list *afiliate;

  seq_list *afiliate1;
  node_list *previous;
  node_list *first = NULL;
  node_list *second = NULL;

  seq_list *sequencial_f = NULL;
  seq_list *sequencial_s = NULL;

  int n_seq = 0;
  int n_node = 0;

  int comp = 0;
  int moviment = 0;
  double time_ex = 0.0;

  int comp_seq;
  int moviment_seq;
  double time_ex_seq = 0.0;

  public:
  head();
  ~head();
  void reader();

  void display(string name);
  void display1(string name);










 };
#endif
