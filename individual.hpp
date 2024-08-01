#pragma once
#include "repeat.hpp"


class CIndividual
{
    private:
/*    unsigned int ind_id;
    int parent_id1;
    int parent_id2;    */
    double ind_fitness;
    CRepeat ind_repeat1;
    CRepeat ind_repeat2;

    public:
    CIndividual(unsigned int n, unsigned int initialCN, std::vector<int> v);
    CIndividual(CRepeat repeat1, CRepeat repeat2);
/*    unsigned int GetIndId();
    unsigned int GetParentId1();
    unsigned int GetParentId2();    */
    double GetIndFitness();
    CRepeat GetRepeat1();
    CRepeat GetRepeat2();
    unsigned int GetRepeat1Id();
    unsigned int GetRepeat1CN();
    std::vector<std::vector<int>> GetRepeat1Seq();
    std::vector<int> GetRepeat1Monomer(unsigned int i);
    std::vector<std::vector<int>> GetRepeat1Slice(unsigned int i, unsigned int j);

    unsigned int GetRepeat2Id();
    unsigned int GetRepeat2CN();
    std::vector<std::vector<int>> GetRepeat2Seq();
    std::vector<int> GetRepeat2Monomer(unsigned int i);
    std::vector<std::vector<int>> GetRepeat2Slice(unsigned int i, unsigned int j);

    void SetIndId(unsigned int ids);
    void SetIndFitness(double fitness);
    void SetRepeat1Id(unsigned int n);
    void SetRepeat2Id(unsigned int n);
    void SetRepeat1Seq(std::vector<std::vector<int>> v);
    void SetRepeat2Seq(std::vector<std::vector<int>> v);
    void SetRepeat1Monomer(unsigned int i, std::vector<int> monomer);
    void SetRepeat2Monomer(unsigned int i, std::vector<int> monomer);

    CRepeat MakeZygote(/*double mutationrate, */ double duplicationrate, double deletionrate, double recombinationrate/*, double conversionrate,*/);
 };

/*
inline unsigned int CIndividual::GetIndId()
{
    return ind_id;
}

inline unsigned int CIndividual::GetParentId1()
{
    return parent_id1;
}

inline unsigned int CIndividual::GetParentId2()
{
    return parent_id2;
}
*/


inline double CIndividual::GetIndFitness()
{
    return ind_fitness;
}

inline CRepeat CIndividual::GetRepeat1()
{
    return ind_repeat1;
}

inline CRepeat CIndividual::GetRepeat2()
{
    return ind_repeat2;
}

inline unsigned int CIndividual::GetRepeat1Id()
{
    return ind_repeat1.GetRepeatId();
}

inline unsigned int CIndividual::GetRepeat2Id()
{
    return ind_repeat2.GetRepeatId();
}

inline unsigned int CIndividual::GetRepeat1CN()
{
    return ind_repeat1.GetCopynumber();
}

inline unsigned int CIndividual::GetRepeat2CN()
{
    return ind_repeat2.GetCopynumber();
}

inline std::vector<std::vector<int>> CIndividual::GetRepeat1Seq()
{
    return ind_repeat1.GetRepeatSeq();
}

inline std::vector<int> CIndividual::GetRepeat1Monomer(unsigned int i)
{
    return ind_repeat1.GetRepeatMonomer(i);
}

inline std::vector<std::vector<int>> CIndividual::GetRepeat1Slice(unsigned int i, unsigned int j)
{
    return ind_repeat1.GetRepeatSlice(i, j);
}

inline std::vector<std::vector<int>> CIndividual::GetRepeat2Seq()
{
    return ind_repeat2.GetRepeatSeq();
}

inline std::vector<int> CIndividual::GetRepeat2Monomer(unsigned int i)
{
    return ind_repeat2.GetRepeatMonomer(i);
}

inline std::vector<std::vector<int>> CIndividual::GetRepeat2Slice(unsigned int i, unsigned int j)
{
    return ind_repeat2.GetRepeatSlice(i, j);
}

/*
inline void CIndividual::SetIndId(unsigned int id)
{
    ind_id = id;
}
*/

inline void CIndividual::SetIndFitness(double fitness)
{
    ind_fitness = fitness;
}

inline void CIndividual::SetRepeat1Id(unsigned int n)
{
    ind_repeat1.SetRepeatId(n);
}

inline void CIndividual::SetRepeat2Id(unsigned int n)
{
    ind_repeat2.SetRepeatId(n);
}

inline void CIndividual::SetRepeat1Seq(std::vector<std::vector<int>> v)
{
    ind_repeat1.SetRepeatSeq(v);
}

inline void CIndividual::SetRepeat2Seq(std::vector<std::vector<int>> v)
{
    ind_repeat2.SetRepeatSeq(v);
}

inline void CIndividual::SetRepeat1Monomer(unsigned int i, std::vector<int> monomer)
{
    ind_repeat1.SetRepeatMonomer(i, monomer);
}

inline void CIndividual::SetRepeat2Monomer(unsigned int i, std::vector<int> monomer)
{
    ind_repeat2.SetRepeatMonomer(i, monomer);
}
