#include <iostream>
#include <ctime>
#include "m_funcs.h"
using namespace std;

void replace_str_col_with_fixation_element(int **array, const int size_str, const int size_col) {

    // Using continue if index == index min_el

    // Initialization indexes of min_element
    //
    int min_str, min_col;

    for (int str = 0; str < size_str; str++) {
        for (int col = 0; col < size_col; col++) {
            if (array[str][col] > 0) { min_str = str; min_col = col; break; }
        }
    }

    // Search min_el
    //
    for (int str = 0; str < size_str; str++) {
        for (int col = 0; col < size_col; col++) {
            if (array[str][col] < array[min_str][min_col] && array[str][col] > 0) { min_str = str; min_col = col; }
        }
    }
  
    cout << "Min element = " << array[min_str][min_col] << endl;
    cout << "Index str = " << min_str << ", index col = " << min_col << endl << endl;
  
    // Main replace str <-> col
    // Work with str
    //
    int col_str = 0; // index matrix's col

    for (int rp_col = 0; rp_col < size_col; rp_col++) {

        if (rp_col == min_col) { continue; }

        else {

            if (col_str == min_str) {
                col_str++;

                int tmp = array[min_str][rp_col];
                array[min_str][rp_col] = array[col_str][min_col];
                array[col_str][min_col] = tmp;
                col_str++;
            }

            else {
                int tmp = array[min_str][rp_col];
                array[min_str][rp_col] = array[col_str][min_col];
                array[col_str][min_col] = tmp;
                col_str++;
            }

        }
    }
}


int main() {

    srand(time(NULL));
    cout << "Using random range [-99;99]" << endl;

    // Determine the size
    //
    //
    int size_str, size_col;

    cout << "Write the size of the square matrix (str = col):" << endl;
    cin >> size_str >> size_col;
    cout << endl;

    // Error
    //
    //
    if (size_str <= 0 || size_col <= 0 || size_str != size_col) { cout << "Error! Your size of matrix is wrong!"; return -1;}

    // Initialization
    //
    //
    int** array = new int* [size_str]; // "**" - ?????????????????????? ??????????????????????
    // ???????????????? n ????????????, ???? ???????????? - ???????????? ????-???? "*"
    for (int i = 0; i < size_str; i++) {
        array[i] = new int[size_col]; // ???????????? ???? ????. ???????? ???????????? ???? m ??????????????????.
    }

    // Main part
    //
    //
    cout << "Your matrix is:" << endl;
    initialization(array,size_str,size_col);
    print_array(array, size_str, size_col);

    replace_str_col_with_fixation_element(array,size_str,size_col);

    // I don't know, if we didn't fixation minimal element, we will have bad matrix.
    // I try to realise algorithm in graphic, and I see
    // that new matrix without fixation element is ambiguous.

    cout << "New matrix is:" << endl;
    print_array(array, size_str, size_col);
    
    
    // Memory clear
    del_array(array,size_str,size_col);
}
