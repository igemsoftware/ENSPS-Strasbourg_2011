#include "Species.h"

using namespace std;

// Source file for Species class allowing to create and modify name and/or state of a species.

Species::Species(float state)						// Default creator
{
    initial_state = state;
}

Species::Species(string name_s, float state)			// Creator giving name_s to the create species
{
    name = name_s;
    initial_state = state;
}

Species::Species(const char* name_s, float state)
{
    string tmp = name_s;
    name = tmp;
    initial_state = state;
}

const string Species::Get_name() const							// Return the species name
{
    return name;
}

void Species::Set_name(string name_s)				// Modify the species name with name_s
{
    name = name_s;
}

const float Species::Get_initial_state()	const				// Return the initial state of species
{
    return initial_state;
}

void Species::Set_initial_state(float state)			// Modify the initial state of species with 1 or 0
{
    initial_state = state;
}
