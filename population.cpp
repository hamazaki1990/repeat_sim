#include "population.hpp"
#include <random>

CPopulation::CPopulation(unsigned int n, unsigned int m)
{
    std::vector<CIndividual> v;
    int i;
    for(i = 0; i < n; ++i){
        v.push_back(CIndividual(i, m));
    }
    individuals = v;
}

std::vector<CIndividual> CPopulation::GetPopulation(){
    return individuals;
}

std::vector<unsigned int> CPopulation::GetIndIds(){
    std::vector<unsigned int> ids;
    for(CIndividual x: individuals){
        ids.push_back(x.GetIndId());
    }
    return ids;
}

std::vector<double> CPopulation::GetIndFitnesses(){
    std::vector<double> fitnesesses;
    for(CIndividual x: individuals){
        fitnesesses.push_back(x.GetIndId());
  }
  return fitnesesses;
}

std::vector<std::vector<unsigned int>> CPopulation::GetIndRepeatsCN(){
    std::vector<std::vector<unsigned int>> repeats;
    for(CIndividual x: individuals){
        std::vector<unsigned int> v = {x.GetRepeat1CN(), x.GetRepeat2CN()};
        repeats.push_back(v);
    }
    return repeats;
}


std::random_device rd1;
std::mt19937 gen1(rd1());
std::random_device rd2;
std::mt19937 gen2(rd2());
std::uniform_real_distribution<> dist1(0.0, 1.0);

void CPopulation::NextGenWF(){
    int l = individuals.size();
    std::uniform_int_distribution<> dist2(0, l-1);
    std::vector<CIndividual> next_generation;
    int i;
    int a;
    int b;
    CIndividual parent1(0, 0);
    CIndividual parent2(0, 0);
    double c = dist1(gen1);
    double d = dist1(gen1);
    double e = dist1(gen1);
    CRepeat zygote1(0, 0);
    CRepeat zygote2(0, 0);
    CIndividual *child;
    for(i = 0; i < l; ++i){ /*このforループ内で子個体1つ作る*/
        /*zygote 1*/
        /*親個体を選ぶ*/
        a = dist2(gen2);
        b = dist2(gen2);
        parent1 = individuals[a];
        parent2 = individuals[b];

        /*変異を加える*/
        c = dist1(gen1);
        if(c < 0.5){
            parent1.ChangeRepeat1CN(0.5, 0.5);
        }else{
            parent1.ChangeRepeat2CN(0.5, 0.5);
        }
        c = dist1(gen1);
        if(c < 0.5){
            parent2.ChangeRepeat1CN(0.5, 0.5);
        }else{
            parent2.ChangeRepeat2CN(0.5, 0.5);
        }

        /*配偶子を作る*/
        d = dist1(gen1);
        e = dist1(gen1);
        if((d < 0.5) && (e < 0.5)){
            zygote1 = parent1.GetRepeat1();
            zygote2 = parent2.GetRepeat1();
        }else if(d < 0.5){
            zygote1 = parent1.GetRepeat1();
            zygote2 = parent2.GetRepeat2();
        }else if(e < 0.5){
            zygote1 = parent1.GetRepeat2();
            zygote2 = parent2.GetRepeat1();
        }else{
            zygote1 = parent1.GetRepeat2();
            zygote2 = parent2.GetRepeat2();
        }
        child = new CIndividual(a, b, zygote1, zygote2);
        next_generation.push_back(*child);
    }
    individuals = next_generation;
}
