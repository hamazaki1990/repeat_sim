#pragma once
#include "individual.hpp"


class CPopulation
{
    private:
    std::vector<CIndividual> individuals;

    public:
    CPopulation(unsigned int n, unsigned int m);
    std::vector<CIndividual> GetPopulation();
    std::vector<unsigned int> GetIndIds();
    std::vector<double> GetIndFitnesses();
    std::vector<std::vector<unsigned int>> GetIndRepeatsCN();
    void NextGenWF();
/*    void NextGenMo();
*/
};
