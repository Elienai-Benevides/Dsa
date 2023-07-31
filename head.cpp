#define CLOCKS_PER_SEC
#include "head.h"
//#include "node_list.h"
//#include "seq_list.h"
//#include "head_node.h"
//#include "head_seq.h"
//#include "systema.h"
#include <string.h>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <cstddef>
#include <time.h>
#include <cstring>
#include <bits/stdc++.h>
using namespace std;
head::head(){
    //head_node();
    //head_seq();
     sequencial_f = NULL;
     sequencial_s = NULL;
     first = NULL;
     second = NULL;
     afiliate = NULL;
}

head::~head(){
     sequencial_f = NULL;
     sequencial_s = NULL;
     first = NULL;
     second = NULL;
     afiliate = NULL;
}

void head::reader() {
    head_node *p;
    node_list *iterator;
    iterator = p->first;
    while((iterator != NULL)) {
        cout << "name: " << iterator->name << endl;
        cout << "rg: " << iterator->rg << endl;
        //afiliar(phead, iterator->name, iterator->rg, iterator);
       // phead->HEAD_NODE.push_back(iterator);
        iterator = iterator->p_next;
    }
    //iterator->p_next = NULL;
}
/************************************************************************************************************************************/
head::head_node::head_node(){
     first = NULL;
     second = NULL;
}

head::head_node::~head_node(){
     first = NULL;
     second = NULL;
     delete(second);
}
bool head::head_node::inclui_info(node_list *p, string name, string rg){
     if(p != NULL) {
        node_list *ptr = NULL;
        ptr = new node_list();
        ptr->start(name,rg);
        ptr->setInfo(p);
        seta_lista_up(ptr,name,rg);
        return true;
     }else {
        cout << "Error, informacao nula na lista" << endl;
        return false;
     }

}

void head::head_node::seta_lista_up(node_list *p, string name,string rg) {
        p = (node_list*)malloc(sizeof(node_list));
     if (first == NULL)
     {  
         first = p;
         second = first;
         first->p_previous = NULL;
         second->p_previous = NULL;
         p->start(name,rg);
         p->setInfo(p);
     }else {
         //node_list *aux;
         //aux = second;
         p->p_previous = second;
         second->p_next = p;
         second = p;
         //second->rg = rg;
         p->start(name,rg);
         p->setInfo(p);
         second->p_next = NULL;
         second->p_previous = NULL;
         //second->p_previous = aux;
         moviment = moviment + 3;
     }
      n_node = n_node + 1;
}
void head::head_node::remov_node_begin() {
    time_ex = 0.0;
    clock_t startTime = clock();
    node_list *aux;
    node_list *var_ant;
    comp = 0;
    int pos = 1;
    aux = first;

    aux->return_values1();
    var_ant = aux->p_next;
    var_ant->p_previous = NULL;
    first->p_previous = NULL;
    first = var_ant;

    n_node = n_node - 1;
    moviment = 5;
    cout << "comparacoes" << comp << endl;
    cout << "movimentacoes" << moviment << endl;
    cout << "posic" << pos << endl;
    clock_t endTime = clock();
    clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    double time_ex = timeInSeconds;
    printf("%f", time_ex);
}
void head::head_node::remov_node_middle(int index) {
    time_ex = 0.0;
    clock_t startTime = clock();
    int i = 2;
    node_list *aux;
    node_list *var_ant, *var_curr;
    comp = 0;
    aux = first;
    while (i < index) {
        aux = aux->p_next;
        i++;
    }
    var_ant = aux->p_next;
    var_ant->return_values();
    var_curr = var_ant;
    var_ant = var_ant->p_next;
    aux->p_next = var_ant;
    var_curr = var_ant;

    n_node = n_node - 1;
    moviment = 7;
    cout << "comparacoes" << comp << endl;
    cout << "movimentacoes" << moviment << endl;
    cout << "posic" << index << endl;
    clock_t endTime = clock();
    clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = (double)clockTicksTaken / (double) CLOCKS_PER_SEC;
    double time_ex = timeInSeconds;
    printf("%f", time_ex);
}
void head::head_node::remov_node_end(){
    time_ex = 0.0;
    clock_t startTime = clock();
    node_list *aux;
    node_list *var_ant;
    node_list *ult;
    node_list *var_curr;
    comp = 0;
    aux = second;

    if(aux != NULL) {
        aux->return_values();
        var_ant = aux->p_previous;
        //var_ant->p_next = NULL;
        second->p_next = NULL;
        second = var_ant;
    }

    moviment = 5;
    cout << "comparacoes" << comp << endl;
    cout << "movimentacoes" << moviment << endl;
    cout << "posic" << n_node << endl;
    n_node = n_node - 1;
    clock_t endTime = clock();
    clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    double time_ex = timeInSeconds;
    printf("%f", time_ex);
}
void head::head_node::listar_nodes_up(){
    node_list *iterator;
    string name_;
    string rg_;
    iterator = first;
    ofstream arq1("arq1.txt");
    while(iterator != NULL) {
        name_ = iterator->name;
        rg_ = iterator->rg;
        cout << "name: " << name_ << endl;
        cout << "rg: " << rg_ << endl;
        if (arq1.is_open(), ios::app) {
            arq1 << name_ << "," << rg_ << endl;
        }
        iterator = iterator->p_next;
    }
    arq1.close();
}
void head::head_node::listar_nodes_down() {
    node_list *iterator;
    iterator = first;
    while(iterator!= NULL)
    {
        cout << "name: " << iterator->name << endl;
        cout << "rg: " << iterator->rg << endl;
        iterator = iterator->p_next;
    }
}
void head::head_node::find() {
    cout << "aqui: " << first << endl;
}
void head::head_node::loop() {
    int i;
    node_list *iterator;
    iterator = first;
     for(i = 0; i < n_node; i++) {
        cout << "objs: " << iterator->name << endl;
        cout << "rg: " << iterator->rg << endl;
        iterator = iterator -> p_next;
    }
}
head::node_list* head::head_node::search_node(const string &rg_wanted) {
    clock_t startTime = clock();
    node_list *percorre, *no = NULL;
    int flag = 0;
    percorre = first;
    while((percorre != NULL) && !flag)
    {
        if (strcmp(percorre->rg.c_str(),rg_wanted.c_str()) == 0) {
            /*cout << "Nome do Rg encontrado: " << percorre->name << endl;
            cout << "Rg encontrado: " << percorre->rg << endl;*/

            percorre->return_values();
            no = percorre;
            return percorre;
            //return no;
            flag = 1;
        }
        percorre = percorre->p_next;
    }

    clock_t endTime = clock();
    clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    time_ex = timeInSeconds;

    cout << "time de execucao node_list" << time_ex << endl;
    return 0;
}
void head::head_node::insert_end_node(string name_, string rg_, node_list *node1){
    time_ex = 0.0;
    clock_t startTime = clock();
    node_list *percorre;
    comp = 0;
    //node_list *node1;
    node1 = (node_list*)malloc(10*sizeof(node_list));
    percorre = second;
    if((percorre->p_next) == NULL){
        comp = (comp) + 1;
        percorre->p_next = node1;
        node1->p_previous = percorre;
        second = node1;
    }
    node1->name = name_;
    node1->rg = rg_;
    moviment = 5;
    n_node = (n_node) + 1;
    cout << "comparacoes" << comp << endl;
    cout << "movimentacoes" << moviment << endl;
    cout << "posic" << n_node << endl;
    clock_t endTime = clock();
    clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    double time_ex = timeInSeconds;
    printf("%f", time_ex);
    free(node1);
}
void head::head_node::insert_begin_node(string name_, string rg_, node_list *node2) {
    time_ex = 0.0;
    clock_t startTime = clock();
    node_list *prim;
    //node_list *node2;
    int pos = 1;
    comp = 0;
    node2 = (node_list*)malloc(10*sizeof(node_list));
    prim = first;
    if ((prim->p_previous) == NULL) {
        comp = (comp) + 1;
        prim->p_previous = node2;
        node2->p_next = first;
        first = node2;
        first->p_previous = NULL;
    }
    n_node = (n_node) + 1;
    node2->name = name_;
    node2->rg = rg_;
    moviment = 5;
    //head_afiliate->seta_lista_up(node2);
    cout << "comparacoes" << comp << endl;
    cout << "movimentacoes" << moviment << endl;
    cout << "posic" << pos << endl;
    clock_t endTime = clock();
    clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    time_ex = timeInSeconds;
    printf("%f", time_ex);
}
void head::head_node::insert_middle_node(string name_, string rg_, int index, node_list *node3) {
    time_ex = 0.0;
    clock_t startTime = clock();
    int i = 2;
    comp = 0;
    node_list *aux;
    //node_list *node3;
    node_list *var_ant;
    node3 = (node_list*)malloc(10*sizeof(node_list));
    //node3->setar_address(this, name_, rg_);
    aux = first;
    while (i < index) {
        aux = aux->p_next;
        i++;
    }
    var_ant = aux->p_next;
    node3->p_previous = aux;
    aux->p_next = node3;
    node3->p_next = var_ant;
    aux = node3;
   // free(aux);
    //seta_lista_up(node3);

    node3->name = name_;
    node3->rg = rg_;
    n_node = (n_node) + 1;
    moviment = 7;
    cout << "comparacoes" << comp << endl;
    cout << "movimentacoes" << moviment << endl;
    cout << "posic" << index << endl;
    clock_t endTime = clock();
    clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    double time_ex = timeInSeconds;
    printf("%f", time_ex);
    free(node3);

}
void head::head_node::end_node(string name, string rg, node_list *p) {
    insert_end_node(name,rg, p);

}
void head::head_node::begin_node(string name, string rg, node_list *p) {
    insert_begin_node(name, rg, p);
    //afiliate = p;
    //afiliate->set_afiliate(this);
}
void head::head_node::middle_node(string name, string rg,int index, node_list *p) {
    insert_middle_node(name, rg,index, p);
}
void head::head_node::menu() {

}
void head::head_node::txt_node(const string &name, node_list *ptr_node) {
    string name_;
    string rg_;
    int flag;
    int i,j;
    string dados;
    //node_list *ptr = ptr_node;
    ifstream txt(name);
    if(txt.is_open())
    {
        while(getline(txt, dados))
        {
            flag = 0;
            j = 0;
            name_ = "";
            rg_ = "";
            for (j = 0; j < dados.size(); j++) {
                if (dados[j] != ',' && !flag)
                {
                    name_ = name_ + dados[j];
                }else{
                    flag = 1;
                }
                if (flag) {
                    rg_ = rg_ + dados[j+1];
                }
            }

            //node_list(name_, rg_, ptr_node);
            //insert(dados.size(), name_, rg_, ptr_node);
            //ptr_node->insert(ptr_node);
            //lista_node_name.push_back(name_);
            //lista_node_rg.push_back(rg_);
         //inclui_info(ptr_node, name_, rg_);
         seta_lista_up(ptr_node, name_, rg_);
            //insert_begin_node(name_, rg_, ptr);
            //HEAD1.seta_lista_up(ptr_node);
        }
    }else{
        cout << "(arq.fail()) = " << txt.fail() << endl;
    }
    //seta_lista_up(ptr_node);
    txt.close();
}
void head::head_node::trig(){
    string name_;
    string rg_;
    int flag;
    int i,j;
    string dados;
    node_list *p;
    //first = NULL;
    //second = NULL;
   //head_node::~head_node();
    ifstream txt_("arq1.txt");
    if(txt_.is_open())
    {
        while(getline(txt_, dados))
        {
            flag = 0;
            j = 0;
            name_ = " ";
            rg_ = " ";
            for (j = 0; j < dados.size(); j++) {
                if (dados[j] != ',' && !flag)
                {
                    name_ = name_ + dados[j];
                }else{
                    flag = 1;
                }
                if (flag) {
                    rg_ = rg_ + dados[j+1];
                }
            }

            //node_list(name_, rg_, ptr_node);
            //insert(dados.size(), name_, rg_, ptr_node);
            //ptr_node->insert(ptr_node);
     p = (node_list*)malloc(20*sizeof(node_list));
     if (first == NULL)
     {
         first = p;
         second = p;
         first->p_previous = NULL;
         second->p_previous = NULL;
         first->name = name_;
         first->rg = rg_;
         second->name = name_;
         second->rg = rg_;
     }else {
         //node_list *aux;
         //aux = second;
         second->p_next = p;
         p->p_previous = second;
         second = p;
         second->name = name_;
         second->rg = rg_;
         second->p_next = NULL;
         second->p_previous = NULL;
         //second->p_previous = aux;
         moviment = moviment + 3;
     }
      n_node = n_node + 1;
            //HEAD1.seta_lista_up(ptr_node);
        }
    }else{
        cout << "(arq.fail()) = " << txt_.fail() << endl;
    }
    txt_.close();

}
void head::head_node::set_name(string n) {
    name = n;
}
void head::head_node::insert(int size, string name_, string rg_, node_list *ptr) {
    ptr = (node_list*)malloc(size * sizeof(node_list));
    ptr->name =  name_;
    ptr->rg = rg_;
}
void head::head_node::Insertion() {
     time_ex = 0.0;
    clock_t startTime = clock();
    node_list *percorre;
    comp = 0;
    if (first == nullptr || first->p_next == nullptr) {
        return;
    }

    node_list *sorted = nullptr;
    node_list *current = first;

    while (current != nullptr) {
        node_list *nextNode = current->p_next;

        if (sorted == nullptr || current->rg < sorted->rg) {
            // Atualiza o início da lista ordenada
            if (sorted != nullptr) {
                sorted->p_previous = current;
            }
            current->p_previous = nullptr;
            current->p_next = sorted;
            sorted = current;
        } else {
            //Encontra a posição correta para inserir o nó atual na lista ordenada
            node_list *temp = sorted;
            while (temp->p_next != nullptr && temp->p_next->rg <= current->rg) {
                temp = temp->p_next;
            }

            current->p_previous = temp;
            current->p_next = temp->p_next;

            if (temp->p_next != nullptr) {
                temp->p_next->p_previous = current;
            }
            temp->p_next = current;
        }
        current = nextNode;
    }

    // Atualiza o início da lista
    first = sorted;
     moviment = 5;
     cout << "comparacoes" << comp << endl;
        cout << "movimentacoes" << moviment << endl;
        cout << "posic" << n_node << endl;
        clock_t endTime = clock();
    
        clock_t clockTicksTaken = endTime - startTime;
        double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
        double time_ex = timeInSeconds;
        printf("%f", time_ex);
}

void head::head_node::Bubble(){
    time_ex = 0.0;
    clock_t startTime = clock();
   comp = 0;
    int ant, curr;
    int index;
    node_list **primeiro;
    node_list **h; //ponteiro da head;
    primeiro = &first;
    int flag;
    
    for (int i = 0; i <= n_node; i++)
    {
        h = primeiro;
        flag = 0; // flag swapped
        for (int j = 0; j < n_node - i - 1; j++)
        {
            //index = j;
            node_list *p1 = *h;
            node_list *p2 = p1->p_next;
            //index_curr = j+1;
            
                //index = index_curr;
                //node_list aux;
            if (p1->rg > p2->rg) {
                //aux.rg = percorre[index].rg;
                //percorre[index].rg= percorre[index_curr].rg;
               // percorre[index_curr].rg= aux.rg;
                *h = (node_list*)swap_node(p1, p2, *h);
                flag = 1;
                
            }
            
            h = &(*h)->p_next;
        }
            if (flag == 0) { break;}
    }
   moviment = 5;
    cout << "comparacoes" << comp << endl;
    cout << "movimentacoes" << moviment << endl;
    clock_t endTime = clock();
    clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    double time_ex = timeInSeconds;
    printf("%f", time_ex);
}
void head::head_node::Shell() {
    time_ex = 0.0;
    clock_t startTime = clock();
    node_list *percorre;
    comp = 0;
    if (first == nullptr || first->p_next == nullptr)
        return;

    // Determinar o intervalo inicial
    int interval = 1;
    node_list* current = first;
    while (current->p_next != nullptr) {
        interval = interval * 3 + 1;
        current = current->p_next;
    }

    // Aplicar o algoritmo Shell Sort
    while (interval >= 1) {
        for (int i = interval; i < n_node; i++) {
            node_list* temp = first;
            for (int j = 0; j < i; j++) {
                temp = temp->p_next;
            }

            node_list* key = temp;
            node_list* prev = nullptr;
            while (temp != nullptr && temp->p_previous != nullptr && key->rg < temp->p_previous->rg) {
                prev = temp->p_previous;
                swap_info(prev, temp);
                temp = prev;
            }
        }
        interval = (interval - 1) / 3;
    }
 moviment = 5;
 cout << "comparacoes" << comp << endl;
    cout << "movimentacoes" << moviment << endl;
    cout << "posic" << n_node << endl;
    clock_t endTime = clock();

    clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    double time_ex = timeInSeconds;
    printf("%f", time_ex);
}

// Função auxiliar para dividir a lista em torno do pivô
int* head::head_node::partition(node_list *low, node_list *high) {
    string pivot = high->rg;
    node_list *i = low->p_previous;

    for (node_list *j = low; j != high; j = j->p_next) {
        if (j->rg < pivot) {
            i = (i == nullptr) ? low : i->p_next;
            swap_info(i, j);
        }
    }

    i = (i == nullptr) ? low : i->p_next;
    swap_info(i, high);
    return (int*)i;
}

// Função principal do algoritmo Quick Sort
void head::head_node::Quick(node_list *low, node_list *high) {
    if (high != nullptr && low != high && low != high->p_next) {
        node_list *pivot = (node_list*)partition(low, high);
        Quick(low, pivot->p_previous);
        Quick(pivot->p_next, high);
    }
}
// Função wrapper para chamar o Quick Sort
void head::head_node::QuickSort() {
    time_ex = 0.0;
    clock_t startTime = clock();
    node_list *percorre;
    comp = 0;
    Quick(first, second);
    moviment = 5;
     cout << "comparacoes" << comp << endl;
        cout << "movimentacoes" << moviment << endl;
        cout << "posic" << n_node << endl;
        clock_t endTime = clock();
    
        clock_t clockTicksTaken = endTime - startTime;
        double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
        double time_ex = timeInSeconds;
        printf("%f", time_ex);
}
void head::head_node::particiona(node_list *p, int low, int high, int pivot){
    //p = sequencial_f;
    node_list *h;
    low = 1;
    high = n_node;
    int index_pivot = high;
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (p[j].rg <= p[index_pivot].rg) {
            i++;
            swap_node(&p[j], &p[i],h);
        }
    }
    swap_node(&p[i+1], &p[index_pivot], h);

    pivot = i+1;
}
void head::head_node::Selection() {
    node_list **primeiro = &first;
    node_list **head = primeiro;
    time_ex = 0.0;
    clock_t startTime = clock();
    node_list *percorre;
    comp = 0;
    if (*head == nullptr || (*head)->p_next == nullptr)
        return;

    while (*head != nullptr) {
        node_list *minNode = *head;
        node_list *temp = minNode->p_next;

        while (temp != nullptr) {
            if (temp->rg < minNode->rg) {
                minNode = temp;
            }
            
            temp = temp->p_next;
        }
        
        if (minNode != *head) {
            // Swap info values
            swap_info(*head, minNode);
        }

        head = &((*head)->p_next);
    }
 moviment = 5;
 cout << "comparacoes" << comp << endl;
    cout << "movimentacoes" << moviment << endl;
    cout << "posic" << n_node << endl;
    clock_t endTime = clock();

    clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    double time_ex = timeInSeconds;
    printf("%f", time_ex);
}

void head::head_node::swap_info(node_list* node1, node_list* node2) {
    string temp_rg = node1->rg;
    string temp_name = node1->name;
    node1->rg = node2->rg;
    node1->name = node2->name;
    node2->rg = temp_rg;
    node2->name = temp_name;
}

void head::head_node::MergeSort(node_list** head) {
    if (*head == nullptr || (*head)->p_next == nullptr)
        return;

    node_list* current = *head;
    node_list* front = nullptr;
    node_list* back = nullptr;

    split(current, &front, &back);

    MergeSort(&front);
    MergeSort(&back);

    *head = merge(front, back);
}

void head::head_node::Sort() {
     time_ex = 0.0;
    clock_t startTime = clock();
    node_list *percorre;
    comp = 0;
    MergeSort(&first);
     moviment = 5;
     cout << "comparacoes" << comp << endl;
        cout << "movimentacoes" << moviment << endl;
        cout << "posic" << n_node << endl;
        clock_t endTime = clock();
    
        clock_t clockTicksTaken = endTime - startTime;
        double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
        double time_ex = timeInSeconds;
        printf("%f", time_ex);
}

head::node_list* head::head_node::merge(node_list* list1, node_list* list2) {
    if (list1 == nullptr)
        return list2;
    if (list2 == nullptr)
        return list1;

    if (list1->rg <= list2->rg) {
        list1->p_next = merge(list1->p_next, list2);
        list1->p_next->p_previous = list1;
        list1->p_previous = nullptr;
        return list1;
    } else {
        list2->p_next = merge(list1, list2->p_next);
        list2->p_next->p_previous = list2;
        list2->p_previous = nullptr;
        return list2;
    }
}

void head::head_node::split(node_list* head, node_list** front, node_list** back) {
    if (head == nullptr || head->p_next == nullptr) {
        *front = head;
        *back = nullptr;
        return;
    }

    node_list* slow = head;
    node_list* fast = head->p_next;

    while (fast != nullptr) {
        fast = fast->p_next;
        if (fast != nullptr) {
            slow = slow->p_next;
            fast = fast->p_next;
        }
    }

    *front = head;
    *back = slow->p_next;
    slow->p_next = nullptr;
    if (*back != nullptr) {
        (*back)->p_previous = nullptr;
    }
}


int *head::head_node::swap_node(node_list *one, node_list *two, node_list *curr){
   node_list *aux = two->p_next;
   node_list *aux1 = one->p_previous;
   two->p_next = one;
   two->p_previous = aux1;
   one->p_next = aux;
   one->p_previous = two;
   curr = two;
   return ((int *)two);
}
void head::head_node::swap_selection(node_list* node1, node_list* node2) {
    if (node1 == nullptr || node2 == nullptr)
        return;

    // Adjust previous pointers
    if (node1->p_previous)
        node1->p_previous->p_next = node2;
    if (node2->p_previous)
        node2->p_previous->p_next = node1;

    // Adjust next pointers
    if (node1->p_next)
        node1->p_next->p_previous = node2;
    if (node2->p_next)
        node2->p_next->p_previous = node1;

    // Swap previous pointers of nodes
    node_list* tempPrev = node1->p_previous;
    node1->p_previous = node2->p_previous;
    node2->p_previous = tempPrev;

    // Swap next pointers of nodes
    node_list* tempNext = node1->p_next;
    node1->p_next = node2->p_next;
    node2->p_next = tempNext;

    // Adjust first pointer if necessary
    if (first == node1)
        first = node2;
    else if (first == node2)
        first = node1;
}

void head::head_node::listar() {
    node_list *iterator;
    node_list *p;
    iterator = first;
    int count = 1;
    while((iterator != NULL)) {
        cout << count++ << ")" ;
        cout << "name: "<< iterator->name << endl;
        cout << "rg: " << iterator->rg << endl;
        //afiliar(phead, iterator->name, iterator->rg, iterator);
       // phead->HEAD_NODE.push_back(iterator);
        iterator = iterator->p_next;
        
    }
    cout << "n_node: " << n_node << endl;
    //iterator->p_next = NULL;
}
void head::head_node::file_node(node_list *p) {
    string name_;
    string rg_;
     for (vector<string>::iterator it = lista_node_name.begin() = lista_node_rg.begin(); (it != lista_node_name.end()) && (it != lista_node_rg.end()); ++it) {

        seta_lista_up(p, name_, rg_);
    }
}


bool head::head_seq::inclui_info(seq_list *p, string name, string rg) {
    if (p != NULL) {
        seq_list *ptr = NULL;
        ptr = (seq_list*)malloc(sizeof(seq_list));
        ptr->start_seq(name, rg);
        ptr->setInfo(p);
        //seta_lista_seq(ptr,name,rg);
        return true;
    }else {
        cout << "Error, informacao nula na lista" << endl;
        return false;
    }
}
head::seq_list* head::head_seq::search_node(const string &rg_wanted) {
    clock_t startTime = clock();
    seq_list *iterator, *no = NULL;
    int flag = 0;
    iterator =  sequencial_elemento;
    while((iterator != NULL) && !flag)
    {
        if (strcmp(iterator->rg.c_str(), rg_wanted.c_str()) == 0) {
            /*cout << "Nome do Rg encontrado: " << iterator->name << endl;
            cout << "Rg encontrado: " << iterator->rg << endl;
            */
            iterator->return_values();
            return iterator;
            no = iterator;
            //return no;
            flag = 1;
        }
        iterator = iterator->next;
    }
    clock_t endTime = clock();
    clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    time_ex_seq = timeInSeconds;
    cout << "time de execucao lista sequencial " << time_ex_seq << endl;
    return 0;
}
void head::head_seq::end_seq(string name, string rg, seq_list *p) {
   // insert_end_seq(name, rg, p);
}
void head::head_seq::begin_seq(string name, string rg, seq_list *p) {
    //insert_begin_seq(name, rg, p);
}
void head::head_seq::middle_seq(string name, string rg,int index, seq_list *p) {
    //insert_middle_seq(name, rg,index, p);
}

void head::head_seq::menu() {

}
void head::head_seq::txt_seq(const string &name, seq_list *ptr_seq, int *tam) {
    int flag;
    int i,j;
    int cont = 1;
    //seq_list *ptr_seq;
    string dados1;
    string name_1;
    string rg_1;
    i = 0;
    ifstream txt1(name);
    if(txt1.is_open())
    {
        i++;
            while(getline(txt1, dados1))
            {

                flag = 0;
                j = 0;
                name_1 = "";
                rg_1 = "";
                for (j = 0; j < dados1.size(); j++) {
                    if (dados1[j] != ',' && !flag)
                    {
                        name_1 = name_1 + dados1[j];
                    }else{
                        flag = 1;
                    }
                    if (flag) {
                        rg_1 = rg_1 + dados1[j+1];
                    }
                }
                //seq_list(name_1, rg_1);
                //seq_list(name_1, rg_1);
                //ptr_seq[i].start_seq(name_1, rg_1, ptr_seq + i);
                //ptr_seq[i].name = name_1;
                //ptr_seq[i].rg = rg_1;
                //cout << "list" << ptr_seq[i].name <<endl;
                //sequence[i].name = ptr_seq[i].name;
                //ptr_seq[i].afiliate(this, name_1, rg_1);
                //lista_seq_name.push_back(name_1);
                //lista_seq_rg.push_back(rg_1);
                //seta_lista_seq(ptr_seq, name_1, rg_1);
                //seta_lista_seq(ptr_seq, name_1, rg_1);
                insertar(name_1, rg_1, ptr_seq, tam);
                //HEAD2.seta_lista_seq(ptr_seq);

        }
    }else {
        cout << "(arq.fail()) = " << txt1.fail() << endl;
    }
    txt1.close();
}
void head::head_seq::trig() {
}
void head::head_seq::set_name(string n) {
    name = n;
}
void head::head_seq::realloca(seq_list *ptr, int new_size) {
    seq_list *new_ptr;
    new_ptr = (seq_list*)realloc(ptr, (new_size)*sizeof(seq_list));
}
void head::head_seq::Selection() {
    seq_list *percorre;
    seq_list *aux;
    int menor;
    percorre = sequencial_elemento;
    for (int i = 0; i < n_seq; i++)
    {
        menor = i;
        for (int j = i+1; j < n_seq; j++)
        {
            if (percorre[j].rg < percorre[menor].rg);
            {
               menor = j;
            }
            swap(&percorre[menor], &percorre[i]);
        }

    }
}
void head::head_seq::Insertion(){
    seq_list *percorre;
    percorre = sequencial_elemento;
    int index_ant, index_curr;
    for (int i = 1; i < n_seq; i++) {
        string key = percorre[i].rg;
        int j = i - 1;
        int key_curr = i;
        index_ant = j;
        index_curr = j+1;
        while ((key < percorre[j].rg) && j >= 0) {
            index_curr = index_ant;
            swap(&percorre[index_curr], &percorre[index_ant]);
            j--;
        }

        swap(&percorre[j+1], &percorre[key_curr]);
        //percorre[j+1] = key;
    }
}
void head::head_seq::Bubble(){
    int ant, curr;
    int index;
    seq_list *percorre;
    percorre = sequencial_elemento;
    int index_ant, index_curr;
    for (int i = 0; i < n_seq; i++)
    {
        for (int j = 0; j < n_seq - i; j++)
        {
            index = j;
            index_curr = j+1;
            if (percorre[index_curr].rg < percorre[index].rg) {
                index = index_curr;
                swap(&percorre[index], &percorre[index_curr]);
            }
        }

    }

}
void head::head_seq::Shell(){

}
void head::head_seq::Quick(seq_list *p, int low, int high){
    int index_pivot;
    high = n_seq;
    low = 0;
    p = sequencial_elemento;
    while (low < high){
        particiona(p, low, high, index_pivot);

        Quick(p, low, index_pivot-1);
        Quick(p, index_pivot+1, high);
    }
}
void head::head_seq::Merge(){

}
void head::head_seq::swap(seq_list *one, seq_list *two){
    seq_list *aux = one;
    one = two;
    two = aux;
}
void head::head_seq::particiona(seq_list *p, int low, int high, int pivot){
    //p = sequencial_f;
    low = 1;
    high = n_seq;
    int index_pivot = high;
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (p[j].rg <= p[index_pivot].rg) {
            i++;

            swap(&p[j], &p[i]);
        }
    }
    swap(&p[i+1], &p[index_pivot]);

    pivot = i+1;
}
void head::head_seq::buscanode(seq_list *b) {
    afiliate1 = b;
}
void head::head_seq::file_seq() {
    seq_list *p;
    for (vector<string>::iterator it = lista_seq_name.begin(); (it != lista_seq_name.end()); ++it) {
        cout << " name" << *it << endl;
    }
    for (vector<string>::iterator it = lista_seq_rg.begin(); (it != lista_seq_rg.end()); ++it) {
        cout << " rg" << *it << endl;
    }
}

head::node_list::node_list(string namecur, string rgcur, node_list *p){
   // start(namecur, rgcur);
    //insert(p);
}

head::node_list::node_list() {
    p_next = nullptr;
    p_previous = nullptr;
    name = "";
    rg = "";
}

head::node_list::~node_list() {
    p_next = nullptr;
    p_previous = nullptr;
    name = "";
    rg = "";
}

void head::node_list::start(string namecur,string rgcur) {
    name = namecur;
    rg = rgcur;
}

void head::node_list::set_afiliate(head *pointer, string name, string rg) {
}
void head::node_list::listar() {
    cout << "name: " << name << endl;
    cout << "rg: " << rg << endl;

}
int head::node_list::acres() {
    n = n+1;
    return n;
}
void head::node_list::return_values() {
    cout << "NAME: "<< name <<endl;
    cout << "RG: "<< rg <<endl;
    //node_list::~node_list();
}
void head::node_list::return_values1() {
    cout << "DELETED DATA: " << endl;
    cout << "NAME: "<< name <<endl;
    cout << "RG: "<< rg <<endl;
}
void head::node_list::insert(node_list *p) {
    p = (node_list*)malloc(sizeof(node_list));
}
void head::node_list::teste(head *p, string name, string rg) {
}
int head::node_list::count() {
    return (n_node++);
}
void head::node_list::setaname(string nome) {
    name = nome;
}
void head::node_list:: setInfo(node_list *pi) {
    pInfo = pi;
}







head::seq_list::seq_list(string name_, string rg_, seq_list *p) {
    //start_seq(name_, rg_);
    //insert(p);
}
head::seq_list::seq_list(){
    next = NULL;
    previous = NULL;
    name = "";
    rg = "";
}

head::seq_list::~seq_list(){
    next = NULL;
    previous = NULL;
    name = "";
    rg = "";
}
void head::head_seq::seta_lista_seq(seq_list *p, string name, string rg) {
    
}
void head::seq_list::start_seq(string name_, string rg_) {
    name = name_;
    rg = rg_;
}
void head::seq_list::tam_zero(){
    N = 0;
}
int head::seq_list::increase() {
    N = N+1;
    return N;
}
int head::seq_list::get_tam() {
    return N;
}
void head::seq_list::return_values() {
    cout << "NAME: "<< name <<endl;
    cout << "RG: "<< rg <<endl;
    //seq_list::~seq_list();
}
void head::seq_list::return_values1() {
    cout << "DELETED DATA: " << endl;
    cout << "NAME: "<< name <<endl;
    cout << "RG: "<< rg <<endl;
}
void head::seq_list::insert(seq_list *p) {
    p = (seq_list*)malloc(sizeof(seq_list));
}
void head::seq_list::teste(head *p) {

}
void head::seq_list::setInfo(seq_list *pi) {
    pInfo = pi;
}
void head::display(string name) {


}
void head::display1(string name) {

}

