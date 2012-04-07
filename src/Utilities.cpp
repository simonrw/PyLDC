#include "Utilities.h"
#include <vector>
#include <map>

using namespace std;


/* Wrapper class to return a vector rather than a map.
 * This makes it easier to wrap into cython */
VectorLDC::VectorLDC(const string &dbname, int filtertype) 
: LimbDarkeningCoefficients(dbname, filtertype) {
}

VectorLDC::~VectorLDC() {
}

vector<double> VectorLDC::coefficients(double teff) {
    map<string, double> coeffs = this->fetch(teff);
    vector<double> returnvals;
    returnvals.push_back(coeffs["a1"]);
    returnvals.push_back(coeffs["a2"]);
    returnvals.push_back(coeffs["a3"]);
    returnvals.push_back(coeffs["a4"]);


    return returnvals;
}

