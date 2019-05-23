#include "my_ispc.h"
#include <iostream>
#include <vector>
using namespace std;
extern "C" {


typedef struct {
void* a1;
void* a2;
void* a3;
void* a4;
} Tensors;


void demo_call(int a, int b, void** tensors){
//demo_inner_call(tensors);
}

void hella1(void **tensors){
    hella2(tensors);
}


void ispc_function(Tensors *t){

float *res = sol_x86_ext_malloc_float(&t->a3, 10);
float *pp = sol_x86_ext_malloc_float(&t->a4, 5);

//std::cout << "tmp malloc" << std::endl;
//float* a = sol_x86_tmp_malloc(20* sizeof(float));
//float* b = sol_x86_tmp_malloc(30* sizeof(float));
//std::cout << "Setting values " << std::endl;
//a[9] = 761;
//b[19] = 98;
//sol_x86_tmp_free(a);
//sol_x86_tmp_free(b);
//cout << "Freed...." << endl;


//float* t1 = static_cast<float*>(sol_x86_ext_ptr(&t->a1));
//float* t2 = static_cast<float*>(sol_x86_ext_ptr(&t->a2));
//float* t3 = static_cast<float*>(sol_x86_ext_ptr(&t->a3));

//t1[14] = 140;
//t1[54] = 16;

//auto h = sol_x86_ext_ref();
//std::cout << "HANDLE RECEIVED ISPC : " << handle << std::endl;
//std::cout << "*HANDLE RECEIVED ISPC : " << *handle << std::endl;
//std::cout << "CALLING EXT MALLOC: " << std::endl;
//float* res = sol_x86_ext_malloc_float(handle, 10);
//std::cout << "DATA POINTER : " << res << std::endl;
//std::cout << "HANDLE AFTER MALLOC CALLED : " << handle << std::endl;
//std::cout << "*HANDLE AFTER MALLOC CALLED : " << *handle << std::endl;


res[0] = 22;
res[1] = 24;
res[2] = 29;
res[3] = 51;
res[4] = 12;
res[5] = 66;
res[6] = 74;
res[7] = 37;
res[8] = 176;
res[9] = 226;

pp[0] = 444;
pp[1] = 555;
pp[2] = 666;
pp[3] = 777;
pp[4] = 888;

//----------------------------//
}
}
