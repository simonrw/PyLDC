from PyLDC.LDC import PyLDC
import os.path
import numpy as np

DB_NAME = os.path.join(
        os.path.expanduser("~"),
        'work',
        'ReferenceDatabase',
        'Reference.db')


def test_ldc():
    filt_type = 6  #  V band
    temp = 6400.

    ldc = PyLDC(DB_NAME, filt_type)
    coeffs = ldc.coefficients(temp)

    assert type(coeffs) == np.ndarray
    assert coeffs.size == 4
