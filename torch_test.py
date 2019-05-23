import torch
import ctypes

runtime = ctypes.cdll.LoadLibrary('libsol_runtime.so')

a = torch.tensor([])
b = torch.tensor([])
c = torch.tensor([])
d = torch.tensor([])
__tensors = (a._cdata, b._cdata, c._cdata, d._cdata)


tensors = (ctypes.c_void_p*4)(*__tensors)

runtime.hella1(tensors)
