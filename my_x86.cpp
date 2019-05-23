#include <iostream>
#include <vector>
//#include <thread>
//#include <chrono>
#include "mxnet-cpp/MxNetCpp.h"

using namespace mxnet::cpp;
using namespace std;

typedef struct {
void* a1;
void* a2;
void* a3;
void* a4;
} Tensors;

//NDArrayHandle hdl;
//void *ret;
static std::map<void*, NDArrayHandle> s_map;

static NDArrayHandle handle(void* ptr, const bool del = false) {
	auto it = s_map.find(ptr);	assert(it != s_map.end()); // Possible double free?
	auto handle = it->second;
    cout << "Erasing from map...." << endl;
	if(del)
		s_map.erase(it);
	return handle;
}

extern "C" {
void hella2(Tensors* t){
cout << "HELLA" << endl;
cout << &t->a1 << endl;
cout << t->a1 << endl;
cout << &t->a2 << endl;
cout << t->a2 << endl;
cout << &t->a3 << endl;
cout << t->a3 << endl;

}




void demo_inner_call( Tensors* t ){
//cout << "INNER RECEIVES HANDLE1 " << *(&t->a1) << endl;
//cout << "INNER RECEIVES HANDLE2 " << t->a2 << endl;
cout << "INNER RECEIVES HANDLE2 " << &t->a2 << endl;
cout << "INNER RECEIVES HANDLE2 " << *(&t->a2) << endl;
}

//funct(&t->a2) --------> funct(void** a2)

void* sol_x86_ext_ptr(NDArrayHandle *handle) {
    	 cout << "Fetching" << endl;
        void *ret;
	cout << ret << " handle :" << handle << " *h : " << *handle << endl;
	MXNDArrayGetData(*handle,&ret);
         cout << "Fetched" << endl;
	return ret;
}	

//------------------------------------------------------------------------------
void sol_x86_tmp_free(void*	ptr) {
	cout << "Freeing...." << endl;
	MXNDArrayFree(handle(ptr, true));
}	

NDArrayHandle sol_x86_ext_ref() {
	NDArrayHandle handle;
	MXNDArrayCreateNone(&handle);
	return handle;
}

	
float* sol_x86_tmp_malloc(const uint32_t cnt) {

    Context c = Context::cpu();
    NDArrayHandle handle;	
    MXNDArrayCreate(&cnt, 1, c.GetDeviceType(), c.GetDeviceId(), 0, &handle);
    std::cout << "created " << std::endl;
    auto ptr = sol_x86_ext_ptr(&handle);
	s_map.emplace(ptr, handle);
	return static_cast<float*>(ptr);
	//uint64_t* dd = static_cast<uint64_t*>(ret);    
	//dd[800] = 66.0;
    //cout << " " << "  " << dd[800] << endl;
    //cout << "Set" << endl;
    //cout<<"Handle Size =" << sizeof(handle)<< endl;    
	//float* a = static_cast<float *>(handle);
    //return a;
}


//------------------------------------------------------------------------------
#define EXT_ALLOC(CPP) NDArrayHandle hdl; MXNDArrayReshape(handle, 1, &cnt, &hdl); return static_cast<CPP>(sol_x86_ext_ptr(hdl))
//#define EXT_ALLOC(CPP)   std::vector<int32_t> dims; dims.push_back((int32_t)cnt); \
                         NDArrayHandle hdl; MXNDArrayReshape(handle, 1, &dims[0], &hdl); \
                         return static_cast<CPP>(sol_x86_ext_ptr(hdl))

float* sol_x86_ext_malloc_float(void** handle, const uint32_t cnt)	{
cout << "------------------------" << endl;
cout << "\nËXT MALLOC " << endl;
cout << "MXNET X86 RECEIVES HANDLE " << handle << endl;
cout << "MXNET X86 RECEIVES *HANDLE " << *handle << endl;
   //EXT_ALLOC(float*);
   //NDArrayHandle hdl;   
   //MXNDArrayReshape(handle,1,&cnt,&handle);
   //NDArray n = NDArray(handle);
   //n.GetData();
   //vector<mx_uint> s = n.GetShape();
   //cout << "SHAPE : " << s[0] << endl;
   //void *ret;
   //NDArray *arr = static_cast<NDArray*>(hdl);
   //*ret = arr->data().dptr_;
  // return NULL;
   //MXNDArrayReshape64(handle, 1, &cnt, true,&hdl);
   Context c = Context::cpu();
   MXNDArrayCreate(&cnt, 1, c.GetDeviceType(), c.GetDeviceId(), 0, handle);
cout << "MXNDCREATE CALLED , HANDLE " << handle << endl;
cout << "MXNDCREATE CALLED , *HANDLE " << *handle << endl;

   //return NULL;
   return static_cast<float*>(sol_x86_ext_ptr(handle));     
   // auto ptr = sol_x86_ext_ptr(handle);
   // return static_cast<float*>(ptr);
}
}

