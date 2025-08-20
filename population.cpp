#include "population.hpp"
#include <random>
#include <algorithm>

std::vector<double> cumsum_cal(std::vector<double> v){
    int n = v.size();
    std::vector<double> s(n, 0);
    s[0] = v[0];
    for (int i = 0; i < n; ++i){
        s[i + 1] = s[i] + v[i + 1];
    }
    return s;
}

std::random_device rd3;
std::mt19937 gen3(rd3());

CIndividual roulettechoice(std::vector<CIndividual> inds, std::vector<double> s){
    try{
        if (inds.size() != s.size()){
            throw "range error in cumsum_cal";
        }
    }
    catch(char *str){
        std::cout << str << std::endl;
    }

    std::uniform_real_distribution<> dist3(0.0, s.back());
    double a = dist3(gen3);
    int i = 0;
    while (s[i] < a){
        i++;
    }
    return inds[i];
}


CPopulation::CPopulation(unsigned int n, unsigned int m, std::vector<CBase> monomer)
{
    std::vector<CIndividual> v;
    int i;
    for(i = 0; i < n; ++i){
        v.push_back(CIndividual(m, monomer));
    }
    individuals = v;
}

std::vector<CIndividual> CPopulation::GetPopulation(){
    return individuals;
}

/*
std::vector<std::vector<unsigned int>> CPopulation::GetIndIds(){
    std::vector<std::vector<unsigned int>> ids;
    for(CIndividual x: individuals){
        ids.push_back(x.GetIndId());
    }
    return ids;
}
*/

std::vector<double> CPopulation::GetIndFitnesses(){
    std::vector<double> fitnesses;
    for(CIndividual x: individuals){
        fitnesses.push_back(x.GetIndFitness());
  }
  return fitnesses;
}

std::vector<std::vector<unsigned int>> CPopulation::GetIndRepeatsCN(){
    std::vector<std::vector<unsigned int>> repeatCN;
    for(CIndividual x: individuals){
        repeatCN.push_back(x.GetIndRepeatCN());
    }
    return repeatCN;
}

std::vector<std::vector<std::vector<std::vector<CBase>>>> CPopulation::GetIndRepeatsSeq()
{
    std::vector<std::vector<std::vector<std::vector<CBase>>>> sequenses;
    for(CIndividual x: individuals){
        sequenses.push_back(x.GetIndRepeatSeq());
    }
    return sequenses;
}

void CPopulation::SetMigration(int i, CIndividual ind){
    try
    {
        individuals.at(i);
    }
    catch (std::out_of_range)
    {
        std::cout << "population size error" << std::endl;
    }
    individuals.at(i) = ind;
}


void CPopulation::NextGenWF(double duplicationrate, double deletionrate){
    int l = individuals.size();
    std::vector<double> fitness;
    for(CIndividual x: individuals){
        fitness.push_back(x.GetIndFitness());
    }
    std::vector<double> cumsum = cumsum_cal(fitness);
    std::vector<CIndividual> next_generation;
    int i;
    CIndividual parent0(0, {});
    CIndividual parent1(0, {});
    CRepeat zygote0(0, {});
    CRepeat zygote1(0, {});
    CIndividual * child;
    for(i = 0; i < l; ++i){ /*このforループ内で子個体1つ作る*/
        /*親個体を選ぶ*/

        parent0 = roulettechoice(individuals, cumsum);
        parent1 = roulettechoice(individuals, cumsum);


        /*配偶子を作る*/
        zygote0 = parent0.MakeZygote(duplicationrate, deletionrate);
        zygote1 = parent1.MakeZygote(duplicationrate, deletionrate);

        child = new CIndividual(zygote0, zygote1);
        next_generation.push_back(*child);
    }
    individuals = next_generation;
}

/*
int CPopulation::ID_is_not_fixed(){
    std::vector<std::vector<unsigned int>> ids;
    for(CIndividual x: individuals){
        ids.push_back(x.GetIndId());
    }
    if (std::adjacent_find(ids.begin(), ids.end(),
        std::not_equal_to<std::vector<unsigned int>>()) == ids.end()){
            return 0;
    }
    else{
            return 1;
    }
}
*/
