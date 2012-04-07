from libcpp.string cimport string
from libcpp.vector cimport vector

cimport numpy as np
import numpy as np

# Utility function to convert from numpy array to vector
cdef vector[double] arrayToVector(np.ndarray[np.double_t,ndim=1] array):
    cdef long size = array.size
    cdef vector[double] vec
    cdef long i
    for i in range(size):
        vec.push_back(array[i])

    return vec

cdef np.ndarray[np.double_t, ndim=1] vectorToArray(vector[double] vec):
    cdef np.ndarray[np.double_t, ndim=1] arr = np.zeros(vec.size())
    cdef long i
    for i in range(vec.size()):
        arr[i] = vec[i]

    return arr
    


cdef extern from "Utilities.h":
    cdef cppclass VectorLDC:
        VectorLDC(string dbname, int filtername)
        vector[double] coefficients(double teff)

cdef class PyLDC:
    '''
    Python LDC class
    '''
    cdef VectorLDC *thisptr

    def __cinit__(self, dbname, filtername):
        py_byte_string = dbname.encode("UTF-8")
        cdef char *c_byte_string = py_byte_string
        cdef string cython_string = string(c_byte_string)

        self.thisptr = new VectorLDC(cython_string, filtername)

    def __dealloc__(self):
        del self.thisptr

    def coefficients(self, teff):
        cdef vector[double] results = self.thisptr.coefficients(teff)
        return vectorToArray(results)

