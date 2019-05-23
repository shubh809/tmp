#include <cstdint>
#include <vector>
extern "C" {
//void demo_call(int , int , void**);
void demo_inner_call(void**);
void hella2(void**);
//void ispc_function(struct Tensors* t);
float* sol_x86_tmp_malloc(const uint32_t cnt);
void* sol_x86_ext_ptr(void** handle);
void sol_x86_tmp_free(void* ptr);
void* sol_x86_ext_ref();
float* sol_x86_ext_malloc_float(void** handle,const uint32_t cnt);
}
