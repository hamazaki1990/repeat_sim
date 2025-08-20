#pragma once
#include "individual.hpp"


class CPopulation
{
    private:
    std::vector<CIndividual> individuals;

    public:
    CPopulation(unsigned int n, unsigned int m, std::vector<CBase> monomer);
    std::vector<CIndividual> GetPopulation();
/*    std::vector<std::vector<unsigned int>> GetIndIds();  */
    std::vector<double> GetIndFitnesses();
    std::vector<std::vector<unsigned int>> GetIndRepeatsCN();
    std::vector<std::vector<std::vector<std::vector<CBase>>>> GetIndRepeatsSeq();
    void SetMigration(int i, CIndividual ind);
    void NextGenWF(double duplicationrate, double deletionrate);
/*    int ID_is_not_fixed();  */
/*    void NextGenMo();   */
};
