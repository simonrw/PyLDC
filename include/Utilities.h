#ifndef UTILITIES_H_9HIFG5T1
#define UTILITIES_H_9HIFG5T1

#include <string>
#include "LimbDarkeningParser.h"


class VectorLDC : public LimbDarkeningCoefficients {
    public:
        VectorLDC(const std::string &dbname, int filtertype);
        ~VectorLDC();

        std::vector<double> coefficients(double teff);
};


#endif /* end of include guard: UTILITIES_H_9HIFG5T1 */

