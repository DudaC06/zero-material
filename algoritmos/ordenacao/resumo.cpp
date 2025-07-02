#include <iostream>
#include <vector>
using namespace std;

// ------------------------------------
// Função para exibir um vetor
void printVector(const vector<int>& v) {
    for (int val : v) {
        cout << val << " ";
    }
    cout << "\n";
}

// ------------------------------------
// 1. SELECTION SORT
// A cada passo, encontra o menor elemento e o coloca na posição correta
void selectionSort(vector<int>& v) {
    int n = v.size();
    for (int i = 0; i < n - 1; i++) {
        int menor = i;
        for (int j = i + 1; j < n; j++) {
            if (v[j] < v[menor])
                menor = j; // Atualiza índice do menor elemento
        }
        swap(v[i], v[menor]); // Troca o menor com o da posição atual
    }
}

// ------------------------------------
// 2. INSERTION SORT
// Insere cada elemento na parte ordenada do vetor
void insertionSort(vector<int>& v) {
    int n = v.size();
    for (int i = 1; i < n; i++) {
        int atual = v[i];
        int j = i - 1;

        // Desloca elementos maiores que o atual para a direita
        while (j >= 0 && v[j] > atual) {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = atual; // Insere o elemento na posição correta
    }
}

// ------------------------------------
// 3. BUBBLE SORT
// "Borbulha" os maiores elementos para o final
void bubbleSort(vector<int>& v) {
    int n = v.size();
    bool trocou;
    for (int i = 0; i < n - 1; i++) {
        trocou = false;
        for (int j = 0; j < n - 1 - i; j++) {
            if (v[j] > v[j + 1]) {
                swap(v[j], v[j + 1]);
                trocou = true;
            }
        }
        if (!trocou) break; // Se nenhuma troca ocorreu, já está ordenado
    }
}

// ------------------------------------
// 4. SHELL SORT
// Ordena usando gaps que vão diminuindo (variação do insertion sort)
void shellSort(vector<int>& v) {
    int n = v.size();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = v[i];
            int j;
            // Move elementos maiores que temp para frente
            for (j = i; j >= gap && v[j - gap] > temp; j -= gap) {
                v[j] = v[j - gap];
            }
            v[j] = temp; // Insere temp na posição correta
        }
    }
}

// ------------------------------------
// 5. QUICKSORT
// Usa recursão e partição com pivô para dividir e ordenar
int particiona(vector<int>& v, int inicio, int fim) {
    int pivo = v[fim]; // Pivô como último elemento
    int i = inicio - 1;

    for (int j = inicio; j < fim; j++) {
        if (v[j] <= pivo) {
            i++;
            swap(v[i], v[j]); // Coloca elementos menores à esquerda do pivô
        }
    }
    swap(v[i + 1], v[fim]); // Coloca pivô na posição correta
    return i + 1; // Retorna a posição final do pivô
}

void quickSort(vector<int>& v, int inicio, int fim) {
    if (inicio < fim) {
        int pi = particiona(v, inicio, fim);
        quickSort(v, inicio, pi - 1); // Ordena a parte esquerda
        quickSort(v, pi + 1, fim);    // Ordena a parte direita
    }
}

// ------------------------------------
// 6. MERGESORT
// Divide o vetor e intercala (merge) as partes ordenadas
void merge(vector<int>& v, int esq, int meio, int dir) {
    int n1 = meio - esq + 1;
    int n2 = dir - meio;

    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++) L[i] = v[esq + i];
    for (int j = 0; j < n2; j++) R[j] = v[meio + 1 + j];

    int i = 0, j = 0, k = esq;

    // Intercala os dois vetores ordenados
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) v[k++] = L[i++];
        else v[k++] = R[j++];
    }

    // Copia o restante de L ou R (se houver)
    while (i < n1) v[k++] = L[i++];
    while (j < n2) v[k++] = R[j++];
}

void mergeSort(vector<int>& v, int esq, int dir) {
    if (esq < dir) {
        int meio = esq + (dir - esq) / 2;
        mergeSort(v, esq, meio);      // Ordena metade esquerda
        mergeSort(v, meio + 1, dir);  // Ordena metade direita
        merge(v, esq, meio, dir);     // Intercala as duas metades
    }
}

// ------------------------------------
// Função principal para testar os algoritmos
int main() {
    vector<int> original = {10, 3, 7, 4, 1, 9, 2, 5, 6, 8};

    cout << "Original: ";
    printVector(original);

    // Testar Selection Sort
    vector<int> v1 = original;
    selectionSort(v1);
    cout << "Selection Sort: ";
    printVector(v1);

    // Testar Insertion Sort
    vector<int> v2 = original;
    insertionSort(v2);
    cout << "Insertion Sort: ";
    printVector(v2);

    // Testar Bubble Sort
    vector<int> v3 = original;
    bubbleSort(v3);
    cout << "Bubble Sort: ";
    printVector(v3);

    // Testar Shell Sort
    vector<int> v4 = original;
    shellSort(v4);
    cout << "Shell Sort: ";
    printVector(v4);

    // Testar QuickSort
    vector<int> v5 = original;
    quickSort(v5, 0, v5.size() - 1);
    cout << "Quick Sort: ";
    printVector(v5);

    // Testar MergeSort
    vector<int> v6 = original;
    mergeSort(v6, 0, v6.size() - 1);
    cout << "Merge Sort: ";
    printVector(v6);

    return 0;
}