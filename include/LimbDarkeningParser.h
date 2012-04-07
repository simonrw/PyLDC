#ifndef LIMBDARKENINGPARSER_H

#define LIMBDARKENINGPARSER_H

#include <map>
#include <stdexcept>
#include <string>
#include <vector>

namespace ftype {

    enum _ftype
    {
        v, u, b, y, U, B, V, R, I, J, H, K
    };

    std::string nameOf(int ft);
    int typeOf(const std::string &name);
}

class LDCException : public std::runtime_error
{
    public:
    LDCException(const std::string &s) : std::runtime_error(s) {}
};

template <typename T>
class ValidValues
{
    public:
    ValidValues()
    {
    }

    virtual ~ValidValues()
    {
    }

    void add(T val)
    {
        mData.push_back(val);
    }

    void check(T checkval)
    {
        bool found = false;


        for (int i=0; i<mData.size(); ++i)
        {
            if (checkval == mData.at(i))
            {
                found = true;
                break;
            }
        }

        if (!found)
            throw LDCException("Cannot find value in range");
    }

    private:
    std::vector<T> mData;

};



class LimbDarkeningCoefficients
{
    double teff, vturb, grav, metal;
    std::string dbname;
    int ftype;

    void validate()
    {
        /* Check for invalid filter types */
        switch (this->ftype)
        {
            case ftype::v: break;
            case ftype::u: break;
            case ftype::b: break;
            case ftype::y: break;
            case ftype::U: break;
            case ftype::B: break;
            case ftype::V: break;
            case ftype::R: break;
            case ftype::I: break;
            case ftype::J: break;
            case ftype::H: break;
            case ftype::K: break;
            default: throw LDCException("Invalid filter passed");
        }

        //Set up checks for the vturb, grav and metal values 
        ValidValues<double> VTurbRange;
        VTurbRange.add(0.0);
        VTurbRange.add(1.0);
        VTurbRange.add(2.0);
        VTurbRange.add(4.0);
        VTurbRange.add(8.0);
        VTurbRange.check(this->getVturb());

        ValidValues<double> gravRange;
        gravRange.add(0.0);
        gravRange.add(0.5);
        gravRange.add(1.0);
        gravRange.add(1.5);
        gravRange.add(1.9);
        gravRange.add(2.0);
        gravRange.add(2.5);
        gravRange.add(3.0);
        gravRange.add(3.5);
        gravRange.add(4.0);
        gravRange.add(4.5);
        gravRange.add(5.0);
        gravRange.check(this->getGrav());

        ValidValues<double> metalRange;
        metalRange.add(-5.0);
        metalRange.add(-4.5);
        metalRange.add(-4.0);
        metalRange.add(-3.5);
        metalRange.add(-3.0);
        metalRange.add(-2.5);
        metalRange.add(-2.0);
        metalRange.add(-1.5);
        metalRange.add(-1.0);
        metalRange.add(-0.5);
        metalRange.add(-0.3);
        metalRange.add(-0.2);
        metalRange.add(-0.1);
        metalRange.add(0.0);
        metalRange.add(0.1);
        metalRange.add(0.2);
        metalRange.add(0.3);
        metalRange.add(0.5);
        metalRange.add(1.0);
        metalRange.check(this->getMetal());

    }

    public:
    LimbDarkeningCoefficients(const std::string &dbname, int filtertype)
        : teff(5600), vturb(2), grav(4.5), metal(0.1), dbname(dbname),
        ftype(filtertype) 
    {
        this->validate();
    }

    ~LimbDarkeningCoefficients() {}

    std::map<std::string, double> fetch(double teff);

    /* Getters */
    double getTeff() const { return this->teff; }
    double getVturb() const { return this->vturb; }
    double getGrav() const { return this->grav; }
    double getMetal() const { return this->metal; }

    /* Setters */
    void setTeff(const double val) { this->teff = val; this->validate(); }
    void setVturb(const double val) { this->vturb = val; this->validate(); }
    void setGrav(const double val) { this->grav = val; this->validate(); }
    void setMetal(const double val) { this->metal = val; this->validate(); }


};


#endif /* end of include guard: LIMBDARKENINGPARSER_H */

