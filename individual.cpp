#include "individual.hpp"
#include <random>

CIndividual::CIndividual(/*unsigned int n, */unsigned int initialCN, std::vector<CBase> v):ind_repeat0(/*n, */initialCN, v), ind_repeat1(/*n, */initialCN, v)
{
/*    ind_id = n;
    parent_id1 = n;
    parent_id2 = n;  */
    ind_fitness = 1.0;
}

CIndividual::CIndividual(CRepeat repeat0, CRepeat repeat1):ind_repeat0(repeat0), ind_repeat1(repeat1)
{
/*    ind_id = repeat0.GetRepeatId();
    parent_id1 = a;
    parent_id2 = b;  */
    ind_fitness = 1.0;
}


std::random_device rd2;
std::mt19937 gen2(rd2());
std::uniform_real_distribution<> dist2(0.0, 1.0);



CRepeat CIndividual::MakeZygote(double mutationrate, double duplicationrate, double deletionrate,  double recombinationrate, double conversionrate)
{
    CRepeat rep0 = ind_repeat0;
    CRepeat rep1 = ind_repeat1;

    int l0;
    int l1;

    unsigned int i;
    unsigned int k;

    std::random_device rd3;
    std::mt19937 gen3(rd3());
    std::geometric_distribution<> dist3(0.3);

/* mutation */
    a = dist2(gen2);
    if(a < mutationrate){




/* duplication */
    double a = dist2(gen2);
    if(a < duplicationrate){
        l0 = rep0.GetCopynumber();
        std::random_device rd4;
        std::mt19937 gen4(rd4());
        std::uniform_int_distribution<> dist4(0, l0 - 1);
        i = dist4(gen4);
        k = dist3(gen3);

        double b = dist2(gen2);
        if(b < 0.5){
            if(i >= k){
                std::cout << "rep0 left-end-dup success" << ' ' <<std::endl;
                rep0.SetSDedSeq(i - k, i);
            }
        }
        else{
            if(i + k + 1 <= l0){
                std::cout << "rep0 right-end-dup success" << ' ' <<std::endl;
                rep0.SetSDedSeq(i, i + k);
            }
        }
    }

    a = dist2(gen2);
    if(a < duplicationrate){
        l1 = rep1.GetCopynumber();
        std::random_device rd4;
        std::mt19937 gen4(rd4());
        std::uniform_int_distribution<> dist4(0, l1 - 1);
        i = dist4(gen4);
        k = dist3(gen3);

        double b = dist2(gen2);
        if(b < 0.5){
            if(i >= k){
  /*              std::cout << "rep1 left-end-dup success" << ' ' <<std::endl;   */
                rep1.SetSDedSeq(i - k, i);
            }
        }
        else{
            if(i + k + 1 <= l1){
/*                std::cout << "rep1 right-end-dup success" << ' ' <<std::endl;  */
                rep1.SetSDedSeq(i, i + k);
            }
        }
    }

/* deletion*/
    a = dist2(gen2);
    if(a < deletionrate){
        l0 = rep0.GetCopynumber();
        std::random_device rd4;
        std::mt19937 gen4(rd4());
        std::uniform_int_distribution<> dist4(0, l0 - 1);
        i = dist4(gen4);
        k = dist3(gen3);

        double b = dist2(gen2);
        if(b < 0.5){
            if(i >= k){
/*                std::cout << "rep0 left-end-del success" << ' ' <<std::endl;  */
                rep0.SetDeletedSeq(i - k, i);
            }
        }
        else{
            if(i + k + 1 <= l0){
/*                std::cout << "rep0 right-end-del success" << ' ' <<std::endl;  */
                rep0.SetDeletedSeq(i, i + k);
            }
        }
    }

    a = dist2(gen2);
    if(a < deletionrate){
        l1 = rep1.GetCopynumber();
        std::random_device rd4;
        std::mt19937 gen4(rd4());
        std::uniform_int_distribution<> dist4(0, l1 - 1);
        i = dist4(gen4);
        k = dist3(gen3);

        double b = dist2(gen2);
        if(b < 0.5){
            if(i >= k){
/*                std::cout << "rep1 left-end-del success" << ' ' <<std::endl;  */
                rep1.SetDeletedSeq(i - k, i);
            }
        }
        else{
            if(i + k + 1 <= l1){
/*                std::cout << "rep1 right-end-del success" << ' ' <<std::endl;  */
                rep1.SetDeletedSeq(i, i + k);
            }
        }
    }

/*
    a = dist2(gen2);
    if(a < recombinationrate){
        l0 = rep0.GetCopynumber();
        l1 = rep1.GetCopynumber();
        std::random_device rd3;
        std::mt19937 gen3(rd3());
        std::uniform_int_distribution<> dist3(0, l0-1);
        i = dist3(gen3);
        std::vector<std::vector<CBase>> r1_f = rep0.GetRepeatSlice(0, i);
        std::vector<std::vector<CBase>> r1_l = rep0.GetRepeatSlice(i, l0-1);

        std::random_device rd4;
        std::mt19937 gen4(rd4());
        std::uniform_int_distribution<> dist4(0, l1-1);
        j = dist4(gen4);
        std::vector<std::vector<CBase>> r2_f = rep1.GetRepeatSlice(0, j);
        std::vector<std::vector<CBase>> r2_l = rep1.GetRepeatSlice(j, l1-1);

        r1_f.insert(r1_f.end(), r2_l.begin(), r2_l.end());
        r2_f.insert(r2_f.end(), r1_l.begin(), r1_l.end());

        rep0.SetRepeatSeq(r1_f);
        rep1.SetRepeatSeq(r2_f);
    }
*/

    a = dist2(gen2);
    if(a < 0.5){
/*        std::cout << "zygote is rep0" << ' ' <<std::endl;  */
        return rep0;
    }
    else{
/*        std::cout << "zygote is rep1" << ' ' <<std::endl;  */
        return rep1;
    }
}
