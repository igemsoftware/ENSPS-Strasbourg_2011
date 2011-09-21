#ifndef SYSTEM_H
#define SYSTEM_H

#include <QList>
#include <QStringList>
#include <string>
#include <math.h>
#include "reaction.h"
#include "bio_cst.h"



class System
{
public :
    System(p_Reaction* _reaction_array, int _size_array, string testbench_entity_name, string testbench_architecture_name, string file_name, QStringList var_species, double sim_time);
    ~System();
    bool test_bench_generation();
    QList<list_sig> get_species_in_system();

private :

// Attributs pour la génération du fichier
string tb_pattern_file_name;
string tb_file_name;
string tb_architecture_name;
string tb_entity_name;
string tb_high_states_init;
string tb_low_states_init;
QStringList species_to_vary;
double time;
p_Reaction* reaction_array;
int size_array;
list_sig* species_list;
int species_list_size;

string generate_port_map();
string signal_declaration();
string signal_variation();
void species_list_generation();

};

#endif
