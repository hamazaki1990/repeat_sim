#pragma once
#include "repeat.hpp"


class CIndividual
{
    private:
/*    unsigned int ind_id;
    int parent_id1;
    int parent_id2;    */
    double ind_fitness;
    CRepeat ind_repeat0;
    CRepeat ind_repeat1;

    public:
    CIndividual(/*unsigned int n, */unsigned int initialCN, std::vector<CBase> v);
    CIndividual(CRepeat repeat0, CRepeat repeat1);
/*    unsigned int GetIndId();
    unsigned int GetParentId1();
    unsigned int GetParentId2();    */
    double GetIndFitness();
    CRepeat GetRepeat0();
    CRepeat GetRepeat1();

/*    unsigned int GetRepeat0Id();  */
    unsigned int GetRepeat0CN();
    std::vector<std::vector<CBase>> GetRepeat0Seq();
    std::vector<CBase> GetRepeat0Monomer(unsigned int i);
    std::vector<std::vector<CBase>> GetRepeat0Slice(unsigned int i, unsigned int j);

/*    unsigned int GetRepeat1Id();  */
    unsigned int GetRepeat1CN();
    std::vector<std::vector<CBase>> GetRepeat1Seq();
    std::vector<CBase> GetRepeat1Monomer(unsigned int i);
    std::vector<std::vector<CBase>> GetRepeat1Slice(unsigned int i, unsigned int j);

/*    std::vector<unsigned int> GetIndId();  */
    std::vector<unsigned int> GetIndRepeatCN();
    std::vector<std::vector<std::vector<CBase>>> GetIndRepeatSeq();

/*    void SetIndId(unsigned int ids);   */
    void SetIndFitness(double fitness);
/*    void SetRepeat0Id(unsigned int n);
    void SetRepeat1Id(unsigned int n);  */
    void SetRepeat0Seq(std::vector<std::vector<CBase>> v);
    void SetRepeat1Seq(std::vector<std::vector<CBase>> v);
    void SetRepeat0Monomer(unsigned int i, std::vector<CBase> monomer);
    void SetRepeat1Monomer(unsigned int i, std::vector<CBase> monomer);

    CRepeat MakeZygote(double mutationrate, double duplicationrate, double deletionrate , double recombinationrate, double conversionrate);
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

inline CRepeat CIndividual::GetRepeat0()
{
    return ind_repeat0;
}

inline CRepeat CIndividual::GetRepeat1()
{
    return ind_repeat1;
}

/*
inline unsigned int CIndividual::GetRepeat0Id()
{
    return ind_repeat0.GetRepeatId();
}

inline unsigned int CIndividual::GetRepeat1Id()
{
    return ind_repeat1.GetRepeatId();
}
*/

inline unsigned int CIndividual::GetRepeat0CN()
{
    return ind_repeat0.GetCopynumber();
}

inline unsigned int CIndividual::GetRepeat1CN()
{
    return ind_repeat1.GetCopynumber();
}

inline std::vector<std::vector<CBase>> CIndividual::GetRepeat0Seq()
{
    return ind_repeat0.GetRepeatSeq();
}

inline std::vector<CBase> CIndividual::GetRepeat0Monomer(unsigned int i)
{
    return ind_repeat0.GetRepeatMonomer(i);
}

inline std::vector<std::vector<CBase>> CIndividual::GetRepeat0Slice(unsigned int i, unsigned int j)
{
    return ind_repeat0.GetRepeatSlice(i, j);
}

inline std::vector<std::vector<CBase>> CIndividual::GetRepeat1Seq()
{
    return ind_repeat1.GetRepeatSeq();
}

inline std::vector<CBase> CIndividual::GetRepeat1Monomer(unsigned int i)
{
    return ind_repeat1.GetRepeatMonomer(i);
}

inline std::vector<std::vector<CBase>> CIndividual::GetRepeat1Slice(unsigned int i, unsigned int j)
{
    return ind_repeat1.GetRepeatSlice(i, j);
}

/*
inline std::vector<unsigned int> CIndividual::GetIndId()
{
    std::vector<unsigned int> v;
    v.push_back(ind_repeat0.GetRepeatId());
    v.push_back(ind_repeat1.GetRepeatId());
    return v;
}
*/


inline std::vector<unsigned int> CIndividual::GetIndRepeatCN()
{
    std::vector<unsigned int> v;
    v.push_back(ind_repeat0.GetCopynumber());
    v.push_back(ind_repeat1.GetCopynumber());
    return v;
}

inline std::vector<std::vector<std::vector<CBase>>> CIndividual::GetIndRepeatSeq()
{
    std::vector<std::vector<std::vector<CBase>>> v;
    v.push_back(ind_repeat0.GetRepeatSeq());
    v.push_back(ind_repeat1.GetRepeatSeq());
    return v;
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

/*
inline void CIndividual::SetRepeat0Id(unsigned int n)
{
    ind_repeat0.SetRepeatId(n);
}

inline void CIndividual::SetRepeat1Id(unsigned int n)
{
    ind_repeat1.SetRepeatId(n);
}
*/

inline void CIndividual::SetRepeat0Seq(std::vector<std::vector<CBase>> v)
{
    ind_repeat0.SetRepeatSeq(v);
}

inline void CIndividual::SetRepeat1Seq(std::vector<std::vector<CBase>> v)
{
    ind_repeat1.SetRepeatSeq(v);
}

inline void CIndividual::SetRepeat0Monomer(unsigned int i, std::vector<CBase> monomer)
{
    ind_repeat0.SetRepeatMonomer(i, monomer);
}

inline void CIndividual::SetRepeat1Monomer(unsigned int i, std::vector<CBase> monomer)
{
    ind_repeat1.SetRepeatMonomer(i, monomer);
}
