import ctypes
import mxnet
from mxnet.ndarray import NDArray
import numpy as np
runtime = ctypes.cdll.LoadLibrary('libsol_runtime.so')


def call_ispc(x, y, tensors):
    print(type(tensors))
    runtime.demo_call(x,y, tensors)


a1 = mxnet.nd.array([], dtype=np.float32)
a2 = mxnet.nd.array([], dtype=np.float32)
a3 = mxnet.nd.array([], dtype=np.float32)
#print("python creates handle ", a2.handle)
#print("python creates handle ", ctypes.byref(a2.handle))
#a3 = mxnet.nd.array([], dtype=np.float32)
#print ("Start ",a1.handle.value)
#print ("Start ", ctypes.byref(a1.handle))

__tensors1 = (a1.handle, 0, a2.handle, a3.handle)
#__tensors2 = (ctypes.byref(a1.handle), ctypes.byref(a2.handle), ctypes.byref(a3.handle))
tensors1 = (ctypes.c_void_p*4)(*__tensors1)
runtime.hella1(tensors1)
#a3 = mxnet.nd.array(handle=tensors1[1])

'''
print ("handle ",ctypes.c_void_p(tensors1[2]))
ttt = ctypes.c_void_p(tensors1[2])
print ("&handle ",ctypes.byref(ttt))
a3 = NDArray(handle = ctypes.c_void_p(tensors1[2]))
print (a3.reshape((2,5)))


print ("handle ",ctypes.c_void_p(tensors1[3]))
ttt = ctypes.c_void_p(tensors1[3])
print ("&handle ",ctypes.byref(ttt))
a4 = NDArray(handle = ctypes.c_void_p(tensors1[3]))
print (a4.reshape((1,5)))
'''

#__tensors2 = (a1._tvm_handle, a2._tvm_handle, a3._tvm_handle)
#a2_h = ctypes.byref(a2.handle)
#print ("A2's handle : ", a2.handle)
#print("A2's handle address")
#print(a2_h)
#tensors = (ctypes.c_void_p*3)()
#tensors1 = ctypes.POINTER(ctypes.POINTER(ctypes.c_void_p))
#tensors1 = __tensors1
#tensors1 = ( *3)(*__tensors1)

#tensors2 = (ctypes.c_void_p*3)(*__tensors2)
#tensors = __tensors2
#print ("CREATE ", a.handle )
#call_ispc(1, 2, __tensors2)
