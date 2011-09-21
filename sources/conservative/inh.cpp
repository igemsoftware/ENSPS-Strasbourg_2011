#include "Inh.h"
#include <string>


using namespace std;

Inh::Inh(string device_name,string generated_entity_name, string generated_file_name, Species a, Species inh)
{
    pattern_react_file_name = "inh_pattern.txt";
    reaction_name = device_name;
    reaction_type = CST_INHIBITION;
    entity_name_user = generated_entity_name;
    file_name_user = generated_file_name;
    A = a;
    I = inh;

    in = new Species[2];
    in[0] = A;
    in[1] = I;
    nb_in = 2;

    string s_name = "S_"+this->get_reaction_name();

    Species s_test = Species(s_name,0);
    out = s_test;
}


Inh::~Inh()
{
    //dtor
}

const string Inh::log_eq() const
{
    string str="";

    str += "S <= (";
    str += (this->A.Get_name() + ") AND ( ");
    str += ("NOT(" + this->I.Get_name() + ") );\n");

    return str;
}

const string Inh::portmap() const
{
    string str="";

    str+= ("\t\t" + this->A.Get_name() + " : IN  STD_LOGIC;\n");
    str+= ("\t\t" + this->I.Get_name() + " : IN  STD_LOGIC;\n");
    str += "\t\tS : OUT STD_LOGIC";

    return str;
}

Species Inh::get_inh_species() const
{
    return I;
}

Species Inh::get_main_species() const
{
    return A;
}




const string Inh::Act_nature_fct() const
{

    string str="";
    return str;
}

const string Inh::Act_cell_fct() const
{

    string str="";
    return str;
}

const string Inh::Act_resistor_fct() const
{

    string str="";
    return str;
}


const string Inh::Rep_nature_fct() const
{

    string str="";
    return str;
}

const string Inh::Rep_cell_fct() const
{

    string str="";
    return str;
}

const string Inh::Rep_resistor_fct() const
{

    string str="";
    return str;
}

const string Inh::arnm_nature_fct() const
{

    string str="";
    return str;
}

const string Inh::arnm_cell_fct() const
{

    string str="";
    return str;
}

const string Inh::arnm_resistor_fct() const
{

    string str="";
    return str;
}

const string Inh::arnm_capacitor_fct() const
{

    string str="";
    return str;
}

const string Inh::out_nature_fct() const
{

    string str="";
    return str;
}

const string Inh::out_cell_fct() const
{

    string str="";
    return str;
}

const string Inh::out_resistor_fct() const
{

    string str="";
    return str;
}

const string Inh::out_capacitor_fct() const
{

    string str="";
    return str;
}

const string Inh::nature_declaration_fct() const
{

    string str="";
    return str;
}

const string Inh::alias_declaration_fct() const
{

    string str="";
    return str;
}
