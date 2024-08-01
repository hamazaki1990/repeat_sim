/*#include <range/v3/action/insert.hpp>
*/

#include <iostream>
#include <vector>
#include <random>
#include "repeat.hpp"

/*
std::vector<int> Getslice(std::vector<int> v, unsigned int i, unsigned int j)
{
    try{
        v.at(i);
        v.at(j - 1);

    }
    catch(std::out_of_range){
        std::cout << "range error \n" << std::endl;
    }
    std::vector<int> v2(v.begin() + i, v.begin() + j);
    return v2;
}
*/

int main()
{
    std::vector<int> monomer1;
    monomer1.push_back(0);
    monomer1.push_back(1);
    monomer1.push_back(2);
    monomer1.push_back(3);
    monomer1.push_back(1);
    monomer1.push_back(2);

    std::cout << "monomer1" <<std::endl;
    for (int i: monomer1) {
        std::cout << i << ' ' <<std::endl;
    }


    CRepeat rep_0(0, 5, monomer1);    /* (mon1,mon1, mon1, mon1, mon1)のrepeat*/
    std::cout << "rep0" <<std::endl;
    std::cout << rep_0.GetRepeatId() << ' ' <<std::endl;
    for (std::vector<int> v: rep_0.GetRepeatSeq()){
      std::cout << "{";
        for (int j: v){
            std::cout << j << ",";
        }
      std::cout << "}" <<std::endl;
    }


    std::vector<std::vector<int>> test = rep_0.GetRepeatSlice(4, 4);

    std::cout << "slicetest" <<std::endl;
    for (std::vector<int> v: test){
        std::cout << "{";
          for (int j: v){
              std::cout << j << ",";
          }
        std::cout << "}" <<std::endl;
      }




    std::vector<int> monomer2;
    monomer2.push_back(0);
    monomer2.push_back(0);
    monomer2.push_back(0);
    monomer2.push_back(0);
    monomer2.push_back(0);
    monomer2.push_back(0);


    CRepeat rep_1(1, 6, monomer2);
    std::cout << "rep1" <<std::endl;
    std::cout << rep_1.GetRepeatId() << ' ' <<std::endl;
    for (std::vector<int> v: rep_1.GetRepeatSeq()){
      std::cout << "{";
        for (int j: v){
            std::cout << j << ",";
        }
      std::cout << "}" <<std::endl;
    }


    std::random_device rd1;
    std::mt19937 gen1(rd1());
    std::uniform_real_distribution<> dist1(0.0, 1.0);


    int l0;
    int l1;
    unsigned int i;
    unsigned int j;

    /* duplication*/
    double a = dist1(gen1);
    if(a < 1){
        l0 = rep_0.GetCopynumber();
        std::cout << "rep0_dup_len" << ' ' <<std::endl;
        std::cout << l0 << ' ' <<std::endl;
        std::random_device rd2;
        std::mt19937 gen2(rd2());
        std::uniform_int_distribution<> dist2(0, l0-1);

        i = dist2(gen2);
        std::cout << "rep0_dup_i" << ' ' <<std::endl;
        std::cout << i << ' ' <<std::endl;
        j = dist2(gen2);
        std::cout << "rep0_dup_j" << ' ' <<std::endl;
        std::cout << j << ' ' <<std::endl;
        rep_0.SetSDedSeq(std::min(i, j), std::max(i, j));
    }

    a = dist1(gen1);
    if(a < 1){
        l1 = rep_1.GetCopynumber();
        std::cout << "rep1_dup_len" << ' ' <<std::endl;
        std::cout << l1 << ' ' <<std::endl;
        std::random_device rd2;
        std::mt19937 gen2(rd2());
        std::uniform_int_distribution<> dist2(0, l1-1);

        i = dist2(gen2);
        std::cout << "rep1_dup_i" << ' ' <<std::endl;
        std::cout << i << ' ' <<std::endl;
        j = dist2(gen2);
        std::cout << "rep1_dup_j" << ' ' <<std::endl;
        std::cout << j << ' ' <<std::endl;
        rep_1.SetSDedSeq(std::min(i, j), std::max(i, j));
    }


    std::cout << "rep0_dup_seq" <<std::endl;
    std::cout << rep_0.GetRepeatId() << ' ' <<std::endl;
    for (std::vector<int> v: rep_0.GetRepeatSeq()){
      std::cout << "{";
        for (int j: v){
            std::cout << j << ",";
        }
      std::cout << "}" <<std::endl;
    }

    std::cout << "rep1_dup_seq" <<std::endl;
    std::cout << rep_1.GetRepeatId() << ' ' <<std::endl;
    for (std::vector<int> v: rep_1.GetRepeatSeq()){
      std::cout << "{";
        for (int j: v){
            std::cout << j << ",";
        }
      std::cout << "}" <<std::endl;
    }

    /* deletion*/
        a = dist1(gen1);
        if(a < 1){
            l0  = rep_0.GetCopynumber();
            std::cout << "rep0_del_len" << ' ' <<std::endl;
            std::cout << l0 << ' ' <<std::endl;
            std::random_device rd2;
            std::mt19937 gen2(rd2());
            std::uniform_int_distribution<> dist2(0, l0-1);
            i = dist2(gen2);
            std::cout << "rep0_del_i" << ' ' <<std::endl;
            std::cout << i << ' ' <<std::endl;
            /*
            j = dist2(gen2);
            std::cout << "rep0_del_j" << ' ' <<std::endl;
            std::cout << j << ' ' <<std::endl;
            rep_0.SetDeletedSeq(std::min(i, j), std::max(i, j));
            */
        }

        a = dist1(gen1);
        if(a < 1){
            l1 = rep_1.GetCopynumber();
            std::cout << "rep1_del_len" << ' ' <<std::endl;
            std::cout << l1 << ' ' <<std::endl;
            std::random_device rd2;
            std::mt19937 gen2(rd2());
            std::uniform_int_distribution<> dist2(0, l1-1);
            i = dist2(gen2);
            std::cout << "rep1_del_i" << ' ' <<std::endl;
            std::cout << i << ' ' <<std::endl;
            j = dist2(gen2);
            std::cout << "rep1_del_j" << ' ' <<std::endl;
            std::cout << j << ' ' <<std::endl;
            rep_1.SetDeletedSeq(std::min(i, j), std::max(i, j));
        }

        std::cout << "rep0_dup_del_seq" <<std::endl;
        std::cout << rep_0.GetRepeatId() << ' ' <<std::endl;
        for (std::vector<int> v: rep_0.GetRepeatSeq()){
          std::cout << "{";
            for (int j: v){
                std::cout << j << ",";
            }
          std::cout << "}" <<std::endl;
        }

        std::cout << "rep1_dup_del_seq" <<std::endl;
        std::cout << rep_1.GetRepeatId() << ' ' <<std::endl;
        for (std::vector<int> v: rep_1.GetRepeatSeq()){
          std::cout << "{";
            for (int j: v){
                std::cout << j << ",";
            }
          std::cout << "}" <<std::endl;
        }


/*recombination*/
        a = dist1(gen1);
        if(a < 1){
            l0 = rep_0.GetCopynumber();
            l1 = rep_1.GetCopynumber();

            std::cout << "rep0_recombination_len" << ' ' <<std::endl;
            std::cout << l0 << ' ' <<std::endl;

            std::random_device rd2;
            std::mt19937 gen2(rd2());
            std::uniform_int_distribution<> dist2(0, l0-2);

            i = dist2(gen2);

            std::cout << "rep0_f_i" << ' ' <<std::endl;
            std::cout << i << ' ' <<std::endl;

            std::vector<std::vector<int>> r0_f = rep_0.GetRepeatSlice(0, i);

            std::cout << "rep0_f_seq" <<std::endl;
            for (std::vector<int> v: r0_f){
              std::cout << "{";
                for (int j: v){
                    std::cout << j << ",";
                }
              std::cout << "}" <<std::endl;
            }


            std::vector<std::vector<int>> r0_l = rep_0.GetRepeatSlice(i+1, l0-1);

            std::cout << "rep0_l_seq" <<std::endl;
            for (std::vector<int> v: r0_l){
              std::cout << "{";
                for (int j: v){
                    std::cout << j << ",";
                }
              std::cout << "}" <<std::endl;
            }




            std::random_device rd3;
            std::mt19937 gen3(rd3());
            std::uniform_int_distribution<> dist3(0, l1-2);
            j = dist3(gen3);
            std::vector<std::vector<int>> r1_f = rep_1.GetRepeatSlice(0, j);

            std::cout << "rep1_f_seq" <<std::endl;
            for (std::vector<int> v: r1_f){
              std::cout << "{";
                for (int j: v){
                    std::cout << j << ",";
                }
              std::cout << "}" <<std::endl;
            }


            std::vector<std::vector<int>> r1_l = rep_1.GetRepeatSlice(j+1, l1-1);

            std::cout << "rep1_l_seq" <<std::endl;
            for (std::vector<int> v: r1_l){
              std::cout << "{";
                for (int j: v){
                    std::cout << j << ",";
                }
              std::cout << "}" <<std::endl;
            }


            r0_f.insert(r0_f.end(), r1_l.begin(), r1_l.end());
            r1_f.insert(r1_f.end(), r0_l.begin(), r0_l.end());

            rep_0.SetRepeatSeq(r0_f);
            rep_1.SetRepeatSeq(r1_f);

        }


            std::cout << "rep0_recombination_seq" <<std::endl;
            std::cout << rep_0.GetRepeatId() << ' ' <<std::endl;
            for (std::vector<int> v: rep_0.GetRepeatSeq()){
              std::cout << "{";
                for (int j: v){
                    std::cout << j << ",";
                }
              std::cout << "}" <<std::endl;
            }

            std::cout << "rep1_recombination_seq" <<std::endl;
            std::cout << rep_1.GetRepeatId() << ' ' <<std::endl;
            for (std::vector<int> v: rep_1.GetRepeatSeq()){
              std::cout << "{";
                for (int j: v){
                    std::cout << j << ",";
                }
              std::cout << "}" <<std::endl;
            }



/*
    CIndividual ind_0(rep_0, rep_0);
    CIndividual ind_1(rep_1, rep_1);


    std::cout << "ind0_rep1" <<std::endl;
    std::cout << ind_0.GetRepeat1Id() << ' ' <<std::endl;
    for (std::vector<int> v: ind_0.GetRepeat1Seq()){
      std::cout << "{";
        for (int j: v){
            std::cout << j << ",";
        }
      std::cout << "}" <<std::endl;
    }

    std::cout << "ind0_rep2" <<std::endl;
    std::cout << ind_0.GetRepeat2Id() << ' ' <<std::endl;
    for (std::vector<int> v: ind_0.GetRepeat2Seq()){
      std::cout << "{";
        for (int j: v){
            std::cout << j << ",";
        }
      std::cout << "}" <<std::endl;
    }

    std::cout << "ind0_zygote" <<std::endl;
    CRepeat zygote0 = ind_0.MakeZygote(0.5, 0.5, 1);
    std::cout << zygote0.GetRepeatId() << ' ' <<std::endl;
    for (std::vector<int> v: zygote0.GetRepeatSeq()){
      std::cout << "{";
        for (int j: v){
            std::cout << j << ",";
        }
      std::cout << "}" <<std::endl;
    }

    CRepeat zygote1 = ind_1.MakeZygote(0.5, 0.5, 1);
    std::cout << "ind1_zygote" <<std::endl;
    std::cout << zygote1.GetRepeatId() << ' ' <<std::endl;
    for (std::vector<int> v: zygote1.GetRepeatSeq()){
      std::cout << "{";
        for (int j: v){
            std::cout << j << ",";
        }
      std::cout << "}" <<std::endl;
    }
    CIndividual child1(zygote0, zygote1);
    std::cout << "child1_rep1" <<std::endl;
    std::cout << child1.GetRepeat1Id() << ' ' <<std::endl;
    for (std::vector<int> v: child1.GetRepeat1Seq()){
      std::cout << "{";
        for (int j: v){
            std::cout << j << ",";
        }
      std::cout << "}" <<std::endl;
    }

    std::cout << "child1_rep2" <<std::endl;
    std::cout << child1.GetRepeat2Id() << ' ' <<std::endl;
    for (std::vector<int> v: child1.GetRepeat2Seq()){
      std::cout << "{";
        for (int j: v){
            std::cout << j << ",";
        }
      std::cout << "}" <<std::endl;
    }


*/

    return 0;

}
