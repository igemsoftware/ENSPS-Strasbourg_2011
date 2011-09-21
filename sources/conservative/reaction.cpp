#include "Reaction.h"

#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
#include <WinBase.h>

#define ENTITY_NAME "%%Synthesis_name%%"
#define ACT_NATURE "%%Act_nature%%"
#define REP_NATURE "%%Rep_nature%%"
#define ARNM_NATURE "%%ARNm_nature%%"
#define PROT_NATURE "%%Prot_nature%%"
#define ACT_CELL "%%Act_cell_nature%%"
#define REP_CELL "%%Rep_cell_nature%%"
#define ARNM_CELL "%%ARNm_cell_nature%%"
#define PROT_CELL "%%Prot_cell_nature%%"
#define RESISTOR_ACT_NAME "%%Resistor_act_name%%"
#define RESISTOR_REP_NAME "%%Resistor_rep_name%%"
#define RESISTOR_ARNM_NAME "%%Resistor_arnm_name%%"
#define CAPACITOR_ARNM_NAME "%%Capacitor_arnm_name%%"
#define RESISTOR_PROT_NAME "%%Resistor_prot_name%%"
#define CAPACITOR_PROT_NAME "%%Capacitor_prot_name%%"

#define RESISTOR_NAME "%%Resistor_name%%"
#define CAPACITOR_NAME "%%Capacitor_name%%"
#define PORT_NATURE "%%Port_nature%%"

#define NATURE_DECLARATION "%%Nature_declaration%%"
#define ALIAS_DECLARATION "%%Alias_declaration%%"


Reaction::Reaction()
{
    //ctor
}

Reaction::~Reaction()
{
    //dtor
}

string Reaction::get_file_name_user()
{
    return file_name_user;
}

void Reaction::set_file_name_user(string str)
{
    file_name_user = str;
}

string Reaction::get_entity_name_user()
{
    return entity_name_user;
}

void Reaction::set_entity_name_user(string str)
{
    entity_name_user = str;
}

string Reaction::get_reaction_name()
{
    return reaction_name;
}

Species Reaction::get_output_species()
{
    return out;
}

int Reaction::get_nb_input_species()
{
    return nb_in;
}

const Species* Reaction::get_input_species() const
{
   return this->in;
}

int Reaction::get_reaction_type()
{
    return reaction_type;
}


void Reaction::set_reaction_type(int new_type)
{
  reaction_type = new_type;
}


bool Reaction::filereact_creation()
{
    string entity_name = ENTITY_NAME;
    string act_nature = ACT_NATURE;
    string rep_nature = REP_NATURE;
    string arnm_nature = ARNM_NATURE;
    string prot_nature = PROT_NATURE;
    string act_cell = ACT_CELL;
    string rep_cell = REP_CELL;
    string arnm_cell = ARNM_CELL;
    string prot_cell = PROT_CELL;
    string resistor_act_name = RESISTOR_ACT_NAME;
    string resistor_rep_name = RESISTOR_REP_NAME;
    string resistor_arnm_name = RESISTOR_ARNM_NAME;
    string capacitor_arnm_name = CAPACITOR_ARNM_NAME;
    string resistor_prot_name = RESISTOR_PROT_NAME;
    string capacitor_prot_name = CAPACITOR_PROT_NAME;

    string pattern_path = "pattern_files\\" + pattern_react_file_name;
    ifstream r_file(pattern_path.c_str(), ios::in);
    //file_name_user += ".vhd";
    string path = "generated_files\\" + file_name_user + ".vhd";

    ofstream w_file(path.c_str(), ios::out | ios::trunc);

//    bool test = r_file;
    bool res = w_file;

    if(r_file && w_file)
    {
        string line;
        size_t found = string::npos;

        while(r_file)
        {
            getline(r_file, line);

            found = line.find(entity_name);
            if(found!=string::npos)
            {
                line.erase(found,entity_name.size());
                line.insert(found,entity_name_user);
            }

            found = line.find(act_nature);
            if(found!=string::npos)
            {
                line.erase(found,act_nature.size());
                line.insert(found,Act_nature_fct());
            }

            found = line.find(rep_nature);
            if(found!=string::npos)
            {
                line.erase(found,rep_nature.size());
                line.insert(found,Rep_nature_fct());
            }

            found = line.find(arnm_nature);
            if(found!=string::npos)
            {
                line.erase(found,arnm_nature.size());
                line.insert(found,arnm_nature_fct());
            }

            found = line.find(prot_nature);
            if(found!=string::npos)
            {
                line.erase(found,prot_nature.size());
                line.insert(found,out_nature_fct());
            }

            found = line.find(act_cell);
            if(found!=string::npos)
            {
                line.erase(found,act_cell.size());
                line.insert(found,Act_cell_fct());
            }

            found = line.find(rep_cell);
            if(found!=string::npos)
            {
                line.erase(found,rep_cell.size());
                line.insert(found,Rep_cell_fct());
            }

            found = line.find(arnm_cell);
            if(found!=string::npos)
            {
                line.erase(found,arnm_cell.size());
                line.insert(found,arnm_cell_fct());
            }

            found = line.find(prot_cell);
            if(found!=string::npos)
            {
                line.erase(found,prot_cell.size());
                line.insert(found,out_cell_fct());
            }

            found = line.find(resistor_act_name);
            if(found!=string::npos)
            {
                line.erase(found,resistor_act_name.size());
                line.insert(found,Act_resistor_fct());
            }

            found = line.find(resistor_rep_name);
            if(found!=string::npos)
            {
                line.erase(found,resistor_rep_name.size());
                line.insert(found,Rep_resistor_fct());
            }

            found = line.find(resistor_arnm_name);
            if(found!=string::npos)
            {
                line.erase(found,resistor_arnm_name.size());
                line.insert(found,arnm_resistor_fct());
            }

            found = line.find(capacitor_arnm_name);
            if(found!=string::npos)
            {
                line.erase(found,capacitor_arnm_name.size());
                line.insert(found,arnm_capacitor_fct());
            }

            found = line.find(resistor_prot_name);
            if(found!=string::npos)
            {
                line.erase(found,resistor_prot_name.size());
                line.insert(found,out_resistor_fct());
            }

            found = line.find(capacitor_prot_name);
            if(found!=string::npos)
            {
                line.erase(found,capacitor_prot_name.size());
                line.insert(found,out_capacitor_fct());
            }

            w_file << line << endl;
        }

        w_file.close();
        r_file.close();
    }
    else
    {
        cerr << "Impossible d'ouvrir le fichier !" << endl;
    }

    return res;

}


bool Reaction::fileresandcap_creation()
{
    string resistor_name = RESISTOR_NAME;
    string capacitor_name = CAPACITOR_NAME;
    string port_nature = PORT_NATURE;

    string pattern_r_path = "pattern_files\\" + pattern_r_file_name;
    string pattern_c_path = "pattern_files\\" + pattern_c_file_name;


    ifstream r1_file(pattern_r_path.c_str(), ios::in);
    string path = "generated_files\\" + Act_resistor_fct() + ".vhd";

    ofstream w1_file(path.c_str(), ios::out | ios::trunc);

    if(r1_file && w1_file)
    {
        string line;
        size_t found = string::npos;

        while(r1_file)
        {
            getline(r1_file, line);

            found = line.find(resistor_name);
            if(found!=string::npos)
            {
                line.erase(found,resistor_name.size());
                line.insert(found,Act_resistor_fct());
            }

            found = line.find(port_nature);
            if(found!=string::npos)
            {
                line.erase(found,port_nature.size());
                line.insert(found,Act_nature_fct());
            }

            w1_file << line << endl;
        }

        w1_file.close();
        r1_file.close();
    }
    else
    {
        cerr << "Impossible d'ouvrir le fichier !" << endl;
    }


    ifstream r2_file(pattern_r_path.c_str(), ios::in);
    path = "generated_files\\" + Rep_resistor_fct() + ".vhd";

    ofstream w2_file(path.c_str(), ios::out | ios::trunc);

    if(r2_file && w2_file)
    {
        string line;
        size_t found = string::npos;

        while(r2_file)
        {
            getline(r2_file, line);

            found = line.find(resistor_name);
            if(found!=string::npos)
            {
                line.erase(found,resistor_name.size());
                line.insert(found,Rep_resistor_fct());
            }

            found = line.find(port_nature);
            if(found!=string::npos)
            {
                line.erase(found,port_nature.size());
                line.insert(found,Rep_nature_fct());
            }

            w2_file << line << endl;
        }

        w2_file.close();
        r2_file.close();
    }
    else
    {
        cerr << "Impossible d'ouvrir le fichier !" << endl;
    }


    ifstream r3_file(pattern_r_path.c_str(), ios::in);
    path = "generated_files\\" + arnm_resistor_fct() + ".vhd";

    ofstream w3_file(path.c_str(), ios::out | ios::trunc);

    if(r3_file && w3_file)
    {
        string line;
        size_t found = string::npos;

        while(r3_file)
        {
            getline(r3_file, line);

            found = line.find(resistor_name);
            if(found!=string::npos)
            {
                line.erase(found,resistor_name.size());
                line.insert(found,arnm_resistor_fct());
            }

            found = line.find(port_nature);
            if(found!=string::npos)
            {
                line.erase(found,port_nature.size());
                line.insert(found,arnm_nature_fct());
            }

            w3_file << line << endl;
        }

        w3_file.close();
        r3_file.close();
    }
    else
    {
        cerr << "Impossible d'ouvrir le fichier !" << endl;
    }


    ifstream r4_file(pattern_r_path.c_str(), ios::in);
    path = "generated_files\\" + out_resistor_fct() + ".vhd";

    ofstream w4_file(path.c_str(), ios::out | ios::trunc);

    if(r4_file && w4_file)
    {
        string line;
        size_t found = string::npos;

        while(r4_file)
        {
            getline(r4_file, line);

            found = line.find(resistor_name);
            if(found!=string::npos)
            {
                line.erase(found,resistor_name.size());
                line.insert(found,out_resistor_fct());
            }

            found = line.find(port_nature);
            if(found!=string::npos)
            {
                line.erase(found,port_nature.size());
                line.insert(found,out_nature_fct());
            }

            w4_file << line << endl;
        }

        w4_file.close();
        r4_file.close();
    }
    else
    {
        cerr << "Impossible d'ouvrir le fichier !" << endl;
    }


    ifstream r5_file(pattern_c_path.c_str(), ios::in);
    path = "generated_files\\" + arnm_capacitor_fct() + ".vhd";

    ofstream w5_file(path.c_str(), ios::out | ios::trunc);

    if(r5_file && w5_file)
    {
        string line;
        size_t found = string::npos;

        while(r5_file)
        {
            getline(r5_file, line);

            found = line.find(capacitor_name);
            if(found!=string::npos)
            {
                line.erase(found,capacitor_name.size());
                line.insert(found,arnm_capacitor_fct());
            }

            found = line.find(port_nature);
            if(found!=string::npos)
            {
                line.erase(found,port_nature.size());
                line.insert(found,arnm_nature_fct());
            }

            w5_file << line << endl;
        }

        w5_file.close();
        r5_file.close();
    }
    else
    {
        cerr << "Impossible d'ouvrir le fichier !" << endl;
    }


    ifstream r6_file(pattern_c_path.c_str(), ios::in);
    path = "generated_files\\" + out_capacitor_fct() + ".vhd";

    ofstream w6_file(path.c_str(), ios::out | ios::trunc);

    bool res = w6_file;

    if(r6_file && w6_file)
    {
        string line;
        size_t found = string::npos;

        while(r6_file)
        {
            getline(r6_file, line);

            found = line.find(capacitor_name);
            if(found!=string::npos)
            {
                line.erase(found,capacitor_name.size());
                line.insert(found,out_capacitor_fct());
            }

            found = line.find(port_nature);
            if(found!=string::npos)
            {
                line.erase(found,port_nature.size());
                line.insert(found,out_nature_fct());
            }

            w6_file << line << endl;
        }

        w6_file.close();
        r6_file.close();
    }
    else
    {
        cerr << "Impossible d'ouvrir le fichier !" << endl;
    }

    return res;

}

bool Reaction::filepkg_creation()
{
    string nature_declaration = NATURE_DECLARATION;
    string alias_declaration = ALIAS_DECLARATION;

    string pattern_syst_path = "pattern_files\\" + pattern_pkg_file_name;
    ifstream r_file(pattern_syst_path.c_str(), ios::in);
    string path = "generated_files\\biological_systems_pkg.vhd";

    ofstream w_file(path.c_str(), ios::out | ios::trunc);

    bool res = w_file;

    if(r_file && w_file)
    {
        string line;
        size_t found = string::npos;

        while(r_file)
        {
            getline(r_file, line);

            found = line.find(nature_declaration);
            if(found!=string::npos)
            {
                line.erase(found,nature_declaration.size());
                line.insert(found,nature_declaration_fct());
            }

            found = line.find(alias_declaration);
            if(found!=string::npos)
            {
                line.erase(found,alias_declaration.size());
                line.insert(found,alias_declaration_fct());
            }

            w_file << line << endl;
        }

        w_file.close();
        r_file.close();
    }
    else
    {
        cerr << "Impossible d'ouvrir le fichier !" << endl;
    }

    return res;

}
