#include "SortingAlgorithm.hpp"
#include <vector>
#include <iostream>
#include <chrono>
using namespace std;


void printVec(vector<int>& v, int dim){
    for (int i = 0; i < dim; i++){
        cout << v[i] << " ";
    }
}


int main(int argc, char **argv){

    int dim = stoi(argv[1]);
    vector<int> v(dim);

    int c = 0;
    generate(v.begin(), v.end(), [&c](){return c++;});   // genero un vettore ordinato da lina di comando


    std::chrono::steady_clock::time_point t_begin = std::chrono::steady_clock::now(); // Tempo inizio
    SortLibrary::BubbleSort(v);
    std::chrono::steady_clock::time_point t_end = std::chrono::steady_clock::now(); // Tempo fine
    double td = std::chrono::duration_cast<std::chrono::milliseconds>(t_end - t_begin).count();  // Diff tempi end - begin
    cout << "Vettore ordinato\nTempo per BS: " << td;

    t_begin = std::chrono::steady_clock::now(); // Tempo inizio
    SortLibrary::MergeSort(v);
    t_end = std::chrono::steady_clock::now(); // Tempo fine
    td = std::chrono::duration_cast<std::chrono::milliseconds>(t_end - t_begin).count();
    cout << "\tTempo per MS: " << td << endl;


    c = dim;
    generate(v.begin(), v.end(), [&c](){return c--;}); // genero un vettore ordinato al 'contrario' da lina di comando
    // printVec(v, dim);


    vector<int> v1 = v;
    t_begin = std::chrono::steady_clock::now(); // Tempo inizio
    SortLibrary::BubbleSort(v);
    t_end = std::chrono::steady_clock::now(); // Tempo fine
    td = std::chrono::duration_cast<std::chrono::milliseconds>(t_end - t_begin).count();
    cout << "Vettore al contrario\nTempo per BS: " << td;

    v1 = v;
    t_begin = std::chrono::steady_clock::now(); // Tempo inizio
    SortLibrary::MergeSort(v);
    t_end = std::chrono::steady_clock::now(); // Tempo fine
    td = std::chrono::duration_cast<std::chrono::milliseconds>(t_end - t_begin).count();
    cout << "\tTempo per MS: " << td << endl;



    generate(v.begin(), v.end(), [&dim](){return rand()%dim;}); // genero un vettore random su [0, Dim -1]
    // printVec(v, dim);

    v1 = v;
    t_begin = std::chrono::steady_clock::now(); // Tempo inizio
    SortLibrary::BubbleSort(v);
    t_end = std::chrono::steady_clock::now(); // Tempo fine
    td = std::chrono::duration_cast<std::chrono::milliseconds>(t_end - t_begin).count();
    cout << "Vettore random su [0, Dim -1]\nTempo per BS: " << td;

    v1 = v;
    t_begin = std::chrono::steady_clock::now(); // Tempo inizio
    SortLibrary::MergeSort(v);
    t_end = std::chrono::steady_clock::now(); // Tempo fine
    td = std::chrono::duration_cast<std::chrono::milliseconds>(t_end - t_begin).count();
    cout << "\tTempo per MS: " << td << endl;



    generate(v.begin(), v.end(), [&dim](){return rand()%8;}); // genero un vettore randomico su [0,7]
    // printVec(v, dim);

    v1 = v;
    t_begin = std::chrono::steady_clock::now(); // Tempo inizio
    SortLibrary::BubbleSort(v);
    t_end = std::chrono::steady_clock::now(); // Tempo fine
    td = std::chrono::duration_cast<std::chrono::milliseconds>(t_end - t_begin).count();
    cout << "Vettore random su [0,7]\nTempo per BS: " << td;

    v1 = v;
    t_begin = std::chrono::steady_clock::now(); // Tempo inizio
    SortLibrary::MergeSort(v);
    t_end = std::chrono::steady_clock::now(); // Tempo fine
    td = std::chrono::duration_cast<std::chrono::milliseconds>(t_end - t_begin).count();
    cout << "\tTempo per MS: " << td << endl;



    return 0;
}

