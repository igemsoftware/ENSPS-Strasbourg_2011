#include "Synth.h"

using namespace std;

Synth::Synth(string name_device,string generated_entity_name, string generated_file_name, Species* activators, Species* repressors,int size_Act, int size_Rep, Species output_species)
{
    pattern_react_file_name = "synthesis_pattern.txt";
    pattern_pkg_file_name = "biological_systems_pkg.txt";
    pattern_r_file_name = "resistor_pattern.txt";
    pattern_c_file_name = "capacitor_pattern.txt";
    reaction_name = name_device;
    reaction_type = CST_SYNTHESIS;
    entity_name_user = generated_entity_name;
    file_name_user = generated_file_name;

    nb_Act = size_Act;
    nb_Rep = size_Rep;

    nb_in = nb_Act + nb_Rep;

    Act = new Species[size_Act];

    for(int i=0; i<size_Act; i++)

    {
        Act[i] = activators[i];
    }


    Rep = new Species[size_Rep];

    for(int i=0; i<size_Rep; i++)
    {
        Rep[i] = repressors[i];
    }

    in = new Species[nb_in];

        for(int i=0; i<size_Act; i++)
    {
        in[i] = Act[i];
    }

         for(int i=0; i<size_Rep; i++)
    {
        in[i+(size_Act)] = Rep[i];
    }

    out = output_species;
}

Synth::~Synth()
{
    //dtor
}

const Species* Synth::get_act_species() const
{
    return this -> Act;
}

const Species* Synth::get_rep_species() const
{
    return this -> Rep;
}

const string Synth::Act_nature_fct() const
{

    string str="";

    str += (Act[0].Get_name());

    return str;
}

const string Synth::Act_cell_fct() const
{

    string str="";

    str += (Act[0].Get_name() + "_cell");

    return str;
}

const string Synth::Act_resistor_fct() const
{

    string str="";

    str += (Act[0].Get_name() + "_resistor");

    return str;
}


const string Synth::Rep_nature_fct() const
{

    string str="";

    str += (Rep[0].Get_name());

    return str;
}

const string Synth::Rep_cell_fct() const
{

    string str="";

    str += (Rep[0].Get_name() + "_cell");

    return str;
}

const string Synth::Rep_resistor_fct() const
{

    string str="";

    str += (Rep[0].Get_name() + "_resistor");

    return str;
}

const string Synth::arnm_nature_fct() const
{

    string str="";

    str += (out.Get_name() + "_arnm");

    return str;
}

const string Synth::arnm_cell_fct() const
{

    string str="";

    str += (out.Get_name() + "_arnm_cell");

    return str;
}

const string Synth::arnm_resistor_fct() const
{

    string str="";

    str += (out.Get_name() + "_arnm_resistor");

    return str;
}

const string Synth::arnm_capacitor_fct() const
{

    string str="";

    str += (out.Get_name() + "_arnm_capacitor");

    return str;
}

const string Synth::out_nature_fct() const
{

    string str="";

    str += (out.Get_name());

    return str;
}

const string Synth::out_cell_fct() const
{

    string str="";

    str += (out.Get_name() + "_cell");

    return str;
}

const string Synth::out_resistor_fct() const
{

    string str="";

    str += (out.Get_name() + "_resistor");

    return str;
}

const string Synth::out_capacitor_fct() const
{

    string str="";

    str += (out.Get_name() + "_capacitor");

    return str;
}

const string Synth::nature_declaration_fct() const
{

    string str="";

    str += ("nature " + Act[0].Get_name() + " is\n      CONCENTRATION        across\n      FLUX        through\n      " + Act[0].Get_name() + "_REF reference;\n\n");
    str += ("   nature " + Rep[0].Get_name() + " is\n      CONCENTRATION        across\n      FLUX        through\n      " + Rep[0].Get_name() + "_REF reference;\n\n");
    str += ("   nature " + out.Get_name() + "_ARNM is\n      CONCENTRATION        across\n      FLUX        through\n      " + out.Get_name() + "_ARNM_REF reference;\n\n");
    str += ("   nature " + out.Get_name() + " is\n      CONCENTRATION        across\n      FLUX        through\n      " + out.Get_name() + "_REF reference;\n\n");

    return str;
}

const string Synth::alias_declaration_fct() const
{

    string str="";

    str += ("alias " + Act[0].Get_name() + "_CELL is " + Act[0].Get_name() +"_REF;\n");
    str += ("   alias " + Rep[0].Get_name() + "_CELL is " + Rep[0].Get_name() + "_REF;\n");
    str += ("   alias " + out.Get_name() + "_ARNM_CELL is " + out.Get_name() + "_ARNM_REF;\n");
    str += ("   alias " + out.Get_name() + "_CELL is " + out.Get_name() + "_REF;\n");

    return str;
}


const string Synth::log_eq() const
{

    string str="";
    return str;
}

const string Synth::portmap() const
{

    string str="";
    return str;
}
