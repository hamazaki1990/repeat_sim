#include "individual.hpp"
#include <random>

CIndividual::CIndividual(unsigned int n, unsigned int initialCN, std::vector<int> v):ind_repeat1(n, initialCN, v), ind_repeat2(n, initialCN, v)
{
/*    ind_id = n;
    parent_id1 = n;
    parent_id2 = n;  */
    ind_fitness = 1.0;
}

CIndividual::CIndividual(CRepeat repeat1, CRepeat repeat2):ind_repeat1(repeat1), ind_repeat2(repeat2)
{
/*    ind_id = repeat1.GetRepeatId();
    parent_id1 = a;
    parent_id2 = b;  */
    ind_fitness = 1.0;
}


std::random_device rd1;
std::mt19937 gen1(rd1());
std::uniform_real_distribution<> dist1(0.0, 1.0);



CRepeat CIndividual::MakeZygote(/*double mutationrate,*/ double duplicationrate, double deletionrate, double recombinationrate/*, double conversionrate, */)
{
    CRepeat rep1 = ind_repeat1;
    CRepeat rep2 = ind_repeat2;


    int l1 = rep1.GetCopynumber();
    int l2 = rep2.GetCopynumber();
    unsigned int i;
    unsigned int j;

/* duplication*/
    double a = dist1(gen1);
    if(a < duplicationrate){
        std::random_device rd2;
        std::mt19937 gen2(rd2());
        std::uniform_int_distribution<> dist2(0, l1-1);
        i = dist2(gen2);
        j = dist2(gen2);
        rep1.SetSDedSeq(std::min(i, j), std::max(i, j));
    }

    a = dist1(gen1);
    if(a < duplicationrate){
        std::random_device rd2;
        std::mt19937 gen2(rd2());
        std::uniform_int_distribution<> dist2(0, l2-1);
        i = dist2(gen2);
        j = dist2(gen2);
        rep2.SetSDedSeq(std::min(i, j), std::max(i, j));
    }

/* deletion*/
    a = dist1(gen1);
    if(a < deletionrate){
        l1 = rep1.GetCopynumber();
        std::random_device rd2;
        std::mt19937 gen2(rd2());
        std::uniform_int_distribution<> dist2(0, l1-1);
        i = dist2(gen2);
        j = dist2(gen2);
        rep1.SetDeletedSeq(std::min(i, j), std::max(i, j));

    }

    a = dist1(gen1);
    if(a < deletionrate){
        l2 = rep2.GetCopynumber();
        std::random_device rd2;
        std::mt19937 gen2(rd2());
        std::uniform_int_distribution<> dist2(0, l2-1);
        i = dist2(gen2);
        dist2.reset();
        j = dist2(gen2);
        rep2.SetDeletedSeq(std::min(i, j), std::max(i, j));
    }


    a = dist1(gen1);
    if(a < recombinationrate){
        l1 = rep1.GetCopynumber();
        l2 = rep2.GetCopynumber();
        std::random_device rd2;
        std::mt19937 gen2(rd2());
        std::uniform_int_distribution<> dist2(0, l1-1);
        i = dist2(gen2);
        std::vector<std::vector<int>> r1_f = rep1.GetRepeatSlice(0, i);
        std::vector<std::vector<int>> r1_l = rep1.GetRepeatSlice(i, l1-1);

        std::random_device rd3;
        std::mt19937 gen3(rd3());
        std::uniform_int_distribution<> dist3(0, l2-1);
        j = dist3(gen3);
        std::vector<std::vector<int>> r2_f = rep2.GetRepeatSlice(0, j);
        std::vector<std::vector<int>> r2_l = rep2.GetRepeatSlice(j, l2-1);

        r1_f.insert(r1_f.end(), r2_l.begin(), r2_l.end());
        r2_f.insert(r2_f.end(), r1_l.begin(), r1_l.end());

        rep1.SetRepeatSeq(r1_f);
        rep2.SetRepeatSeq(r2_f);
    }

    a = dist1(gen1);
    if(a >= 0.5){
        return rep1;
    }
    else{
        return rep2;
    }



}
