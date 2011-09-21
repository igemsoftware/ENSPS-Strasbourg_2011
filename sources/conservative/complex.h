#ifndef COMPLEX_H
#define COMPLEX_H

#include "Reaction.h"
#include "bio_cst.h"

/*! \brief Complex(ation) class used to create a complexation device.
                                inherits from the Reaction class */

class Complex : public Reaction
{
    public:

    /*!
    \brief Complexation constructor

    \param name_device : name of the device (string)
    \param generated_entity_name : name of the generated entity on the VHDL file (string)
    \param generated_file_name : name of the VHDL file generated (string)
    \param input_species : array of Species which contains all the input inputs species of this complexation
    \param number_species : number of input species of this complexation
    */
    Complex(string name_device,string generated_entity_name, string generated_file_name, Species* input_species, int number_in_species,Species output_species);

    /*!
    \brief Complexation default destructor
    */
    virtual ~Complex();


    /*!
    \brief Method which gives all the Species of this complexation
    \return returns an array of Species which contains all the Species of this complexation
    */
    const Species* get_input_species() const;


    const int get_number_in_species() const;

protected:

    /*!
    \brief Method which calculates the logical equation for the VHDL-File linked with this complexation
    \return returns a string which contains the logical equation linked with this complexation    */
    const string log_eq() const;

    /*!
    \brief Method which calculates the port mapping for the VHDL-file linked with this complexation
    \return returns a string which the port mapping of this complexation
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


};

#endif // COMPLEX_H
