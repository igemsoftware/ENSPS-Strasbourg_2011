#ifndef INH_H
#define INH_H

#include "Reaction.h"
#include "bio_cst.h"

class Inh : public Reaction
{
public:

    /*!
    \brief Inh constructor

    \param name_device : name of the device (string)
    \param generated_entity_name : name of the generated entity on the VHDL file (string)
    \param generated_file_name : name of the VHDL file generated (string)
    \param a : Species to inhibit
    \param inh : inhibiter Species
    */
    Inh(string device_name, string generated_entity_name, string generated_file_name, Species a, Species inh);

    /*!
    \brief Inh default destructor
    */
    virtual ~Inh();

    /*!
    \brief Method which gives the "inhibiter Species" of this inhibition
    \return returns the inhibiter Species
    */
    Species get_inh_species() const;

    /*!
    \brief Method which gives the "Species to inhibit" of this inhibition
    \return returns the Species to inhibit
    */
    Species get_main_species() const;

protected:
    /*!
    \brief Method which calculates the logical equation for the VHDL-File linked with this inhibition
    \return returns a string which contains the logical equation linked with this inhibition    */
    const string log_eq() const;

    /*!
    \brief Method which calculates the port mapping for the VHDL-file linked with this inhibition
    \return returns a string which the port mapping of this inhibition
    */
    const string portmap() const;

    const string Act_nature_fct() const;
    const string Act_cell_fct() const;
    const string Act_resistor_fct() const;
    const string Rep_nature_fct() const;
    const string Rep_cell_fct() const;
    const string Rep_resistor_fct() const;
    const string arnm_nature_fct() const;
    const string arnm_cell_fct() const;
    const string arnm_resistor_fct() const;
    const string arnm_capacitor_fct() const;
    const string out_nature_fct() const;
    const string out_cell_fct() const;
    const string out_resistor_fct() const;
    const string out_capacitor_fct() const;
    const string nature_declaration_fct() const;
    const string alias_declaration_fct() const;

private:

    /*!
    \brief int attribute which contains the Species to inhibit
    */
    Species A;

    /*!
    \brief int attribute which contains the inhibiter Species
    */
    Species I;

};

#endif // INH_H
