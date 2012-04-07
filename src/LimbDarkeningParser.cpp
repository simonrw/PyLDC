#include "LimbDarkeningParser.h"
#include <sqlitepp/sqlitepp.hpp>


/* ensure that stl vectors are used */
#define _USESTDVECTOR_
#include <nr/nr3.h>
#include <nr/interp_1d.h>

using namespace std;
using namespace sqlitepp;

struct Row
{
    double filter, teff;
    string coefftype;

    Row()
    {
        filter = 0;
        teff = 0;
        coefftype = "";
    }
};


string ftype::nameOf(int ft)
{
    switch (ft)
    {
        case v:
            return "v";
            break;
        case u:
            return "u";
            break;
        case b:
            return "b";
            break;
        case y:
            return "y";
            break;
        case U:
            return "U";
            break;
        case B:
            return "B";
            break;
        case V:
            return "V";
            break;
        case R:
            return "R";
            break;
        case I:
            return "I";
            break;
        case J:
            return "J";
            break;
        case H:
            return "H";
            break;
        case K:
            return "K";
            break;
        default:
            return "";
    }
}

int ftype::typeOf(const std::string &name)
{
    if (name == "U")
        return ftype::U;
    else if (name == "B")
        return ftype::B;
    else if (name == "V")
        return ftype::V;
    else if (name == "R")
        return ftype::R;
    else if (name == "I")
        return ftype::I;
    else if (name == "J")
        return ftype::J;
    else if (name == "H")
        return ftype::H;
    else if (name == "K")
        return ftype::K;
    else if (name == "u")
        return ftype::u;
    else if (name == "v")
        return ftype::v;
    else if (name == "b")
        return ftype::b;
    else if (name == "y")
        return ftype::y;
    else
        return -1;

}

map<string, double> LimbDarkeningCoefficients::fetch(double teff)
{
    this->teff = teff;
    map<string, double> result;
    session conn(this->dbname);
    statement st(conn);
    Row r;

    vector<double> teffa1, teffa2, teffa3, teffa4;
    vector<double> a1, a2, a3, a4;



    /* switch for the different filter types */
    switch (this->ftype)
    {
        case ftype::U:
            st << "select filteru, coefftype, teff from ldc"
                << " WHERE grav = " << this->grav
                << " AND vturb = " << this->vturb
                << " AND metal = " << this->metal
                << " AND teff > " << this->teff - 1000.
                << " AND teff < " << this->teff + 1000.,
                into(r.filter), into(r.coefftype), into(r.teff)
                    ;
            break;
        case ftype::V:
            st << "select filterv, coefftype, teff from ldc"
                << " WHERE grav = " << this->grav
                << " AND vturb = " << this->vturb
                << " AND metal = " << this->metal
                << " AND teff > " << this->teff - 1000.
                << " AND teff < " << this->teff + 1000.,
                into(r.filter), into(r.coefftype), into(r.teff)
                    ;
            break;
        case ftype::B:
            st << "select filterb, coefftype, teff from ldc"
                << " WHERE grav = " << this->grav
                << " AND vturb = " << this->vturb
                << " AND metal = " << this->metal
                << " AND teff > " << this->teff - 1000.
                << " AND teff < " << this->teff + 1000.,
                into(r.filter), into(r.coefftype), into(r.teff)
                    ;
            break;
        case ftype::R:
            st << "select filterr, coefftype, teff from ldc"
                << " WHERE grav = " << this->grav
                << " AND vturb = " << this->vturb
                << " AND metal = " << this->metal
                << " AND teff > " << this->teff - 1000.
                << " AND teff < " << this->teff + 1000.,
                into(r.filter), into(r.coefftype), into(r.teff)
                    ;
            break;
        case ftype::I:
            st << "select filteri, coefftype, teff from ldc"
                << " WHERE grav = " << this->grav
                << " AND vturb = " << this->vturb
                << " AND metal = " << this->metal
                << " AND teff > " << this->teff - 1000.
                << " AND teff < " << this->teff + 1000.,
                into(r.filter), into(r.coefftype), into(r.teff)
                    ;
            break;
        case ftype::J:
            st << "select filterj, coefftype, teff from ldc"
                << " WHERE grav = " << this->grav
                << " AND vturb = " << this->vturb
                << " AND metal = " << this->metal
                << " AND teff > " << this->teff - 1000.
                << " AND teff < " << this->teff + 1000.,
                into(r.filter), into(r.coefftype), into(r.teff)
                    ;
            break;
        case ftype::H:
            st << "select filterh, coefftype, teff from ldc"
                << " WHERE grav = " << this->grav
                << " AND vturb = " << this->vturb
                << " AND metal = " << this->metal
                << " AND teff > " << this->teff - 1000.
                << " AND teff < " << this->teff + 1000.,
                into(r.filter), into(r.coefftype), into(r.teff)
                    ;
            break;
        case ftype::K:
            st << "select filterk, coefftype, teff from ldc"
                << " WHERE grav = " << this->grav
                << " AND vturb = " << this->vturb
                << " AND metal = " << this->metal
                << " AND teff > " << this->teff - 1000.
                << " AND teff < " << this->teff + 1000.,
                into(r.filter), into(r.coefftype), into(r.teff)
                    ;
            break;
        case ftype::y:
            st << "select filtersmally, coefftype, teff from ldc"
                << " WHERE grav = " << this->grav
                << " AND vturb = " << this->vturb
                << " AND metal = " << this->metal
                << " AND teff > " << this->teff - 1000.
                << " AND teff < " << this->teff + 1000.,
                into(r.filter), into(r.coefftype), into(r.teff)
                    ;
            break;
        case ftype::b:
            st << "select filtersmallb, coefftype, teff from ldc"
                << " WHERE grav = " << this->grav
                << " AND vturb = " << this->vturb
                << " AND metal = " << this->metal
                << " AND teff > " << this->teff - 1000.
                << " AND teff < " << this->teff + 1000.,
                into(r.filter), into(r.coefftype), into(r.teff)
                    ;
            break;
        case ftype::v:
            st << "select filtersmallv, coefftype, teff from ldc"
                << " WHERE grav = " << this->grav
                << " AND vturb = " << this->vturb
                << " AND metal = " << this->metal
                << " AND teff > " << this->teff - 1000.
                << " AND teff < " << this->teff + 1000.,
                into(r.filter), into(r.coefftype), into(r.teff)
                    ;
            break;
        case ftype::u:
            st << "select filtersmallu, coefftype, teff from ldc"
                << " WHERE grav = " << this->grav
                << " AND vturb = " << this->vturb
                << " AND metal = " << this->metal
                << " AND teff > " << this->teff - 1000.
                << " AND teff < " << this->teff + 1000.,
                into(r.filter), into(r.coefftype), into(r.teff)
                    ;
            break;
        default:
            throw runtime_error("Invalid filter type passed");
    }


    int nReturned = 0;
    while (st.exec())
    {
        if (r.coefftype == "a1")
        {
            teffa1.push_back(r.teff);
            a1.push_back(r.filter);
        }
        else if (r.coefftype == "a2")
        {
            teffa2.push_back(r.teff);
            a2.push_back(r.filter);
        }
        else if (r.coefftype == "a3")
        {
            teffa3.push_back(r.teff);
            a3.push_back(r.filter);
        }
        else if (r.coefftype == "a4")
        {
            teffa4.push_back(r.teff);
            a4.push_back(r.filter);
        }
        else
        {
            /* Some error occured here */
            throw LDCException("Unknown coeff type encountered");
        }

        ++nReturned;
    }


    /* Need at least 5 points to interpolate over */
    if (nReturned < 5)
    {
        throw LDCException("Too few points to interpolate over");
    }







    Spline_interp a1interp(teffa1, a1),
                  a2interp(teffa2, a2),
                  a3interp(teffa3, a3),
                  a4interp(teffa4, a4);

    result["a1"] = a1interp.interp(this->teff);
    result["a2"] = a2interp.interp(this->teff);
    result["a3"] = a3interp.interp(this->teff);
    result["a4"] = a4interp.interp(this->teff);


    return result;

}
