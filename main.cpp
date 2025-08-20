/*#include <range/v3/action/insert.hpp>
*/

#include <iostream>
#include <vector>
#include <random>
#include "individual.hpp"



int main()
{
    CBase test0(0);
    std::cout << "base_test0 "<< test0.GetBase() <<std::endl;
    test0.SetMutation();
    std::cout << "base_test0_mutation "<< test0.GetBase() <<std::endl;
    CBase test1(5);
    std::cout << "base_test1 "<< test1.GetBase() <<std::endl;


    std::vector<CBase> monomer0_1 = {0, 0, 0, 0, 0, 0};
    std::vector<CBase> monomer0_2 = {0, 0, 0, 0, 0, 0};
    std::vector<CBase> monomer0_3 = {0, 0, 0, 0, 0, 0};
    std::vector<CBase> monomer0_4 = {0, 0, 0, 0, 0, 0};
    std::vector<CBase> monomer0_5 = {0, 0, 0, 0, 0, 0};

    std::vector<std::vector<CBase>> polymer0 = {monomer0_1, monomer0_2, monomer0_3, monomer0_4, monomer0_5};

    CRepeat rep_0(polymer0);


    std::vector<CBase> monomer1_6 = {0, 0, 0, 0, 0, 0};
    std::vector<CBase> monomer1_7 = {0, 0, 0, 0, 0, 0};
    std::vector<CBase> monomer1_8 = {0, 0, 0, 0, 0, 0};
    std::vector<CBase> monomer1_9 = {0, 0, 0, 0, 0, 0};
    std::vector<CBase> monomer1_10 = {0, 0, 0, 0, 0, 0};

    std::vector<std::vector<CBase>> polymer1 = {monomer1_6, monomer1_7, monomer1_8, monomer1_9, monomer1_10};

    CRepeat rep_1(polymer1);

    CIndividual ind_0(rep_0, rep_1);

    std::cout << "ind0_rep0" <<std::endl;
    for (std::vector<CBase> v: ind_0.GetRepeat0Seq()){
        std::cout << "{";
          for (CBase j: v){
              std::cout << j.GetBase() << ",";
          }
        std::cout << "}" <<std::endl;
      }

      std::cout << "ind0_rep1" <<std::endl;
      for (std::vector<CBase> v: ind_0.GetRepeat1Seq()){
          std::cout << "{";
              for (CBase j: v){
                  std::cout << j.GetBase() << ",";
              }
          std::cout << "}" <<std::endl;
      }

/*
    CPopulation pop_0(3, 5, {0, 0, 0, 0, 0});

    std::cout << "pop0_repeats" <<std::endl;
    for (std::vector<std::vector<std::vector<CBase>>> ind: pop_0.GetIndRepeatsSeq()){
        std::cout << "<";
        for (std::vector<std::vector<CBase>> rep: ind){
            std::cout << "[";
            for(std::vector<CBase> v: rep){
                std::cout << "{";
                for (CBase j: v){
                    std::cout << j.GetBase() << ",";
                }
                std::cout << "}, ";
            }
            std::cout << "], ";
        }
        std::cout << ">" <<std::endl;
    }

    std::vector<CIndividual> inds0 = pop_0.GetPopulation();



    pop_0.SetMigration(0, ind_0);

    std::cout << "pop0_ind0_seq" <<std::endl;
    for (std::vector<std::vector<std::vector<CBase>>> ind: pop_0.GetIndRepeatsSeq()){
        std::cout << "<";
        for (std::vector<std::vector<CBase>> rep: ind){
            std::cout << "[";
            for(std::vector<CBase> v: rep){
                std::cout << "{";
                for (CBase j: v){
                    std::cout << j.GetBase() << ",";
                }
                std::cout << "}, ";
            }
            std::cout << "], ";
        }
        std::cout << ">" <<std::endl;
    }



    pop_0.NextGenWF(0.5, 0.5);

    std::cout << "pop0_F1_seq" <<std::endl;
    for (std::vector<std::vector<std::vector<CBase>>> ind: pop_0.GetIndRepeatsSeq()){
        std::cout << "<";
        for (std::vector<std::vector<CBase>> rep: ind){
            std::cout << "[";
            for(std::vector<CBase> v: rep){
                std::cout << "{";
                for (CBase j: v){
                    std::cout << j.GetBase() << ",";
                }
                std::cout << "}, ";
            }
            std::cout << "], ";
        }
        std::cout << ">" <<std::endl;
    }


    pop_0.NextGenWF(0.5, 0.5);

    std::cout << "pop0_F2_seq" <<std::endl;
    for (std::vector<std::vector<std::vector<CBase>>> ind: pop_0.GetIndRepeatsSeq()){
        std::cout << "<";
        for (std::vector<std::vector<CBase>> rep: ind){
            std::cout << "[";
            for(std::vector<CBase> v: rep){
                std::cout << "{";
                for (CBase j: v){
                    std::cout << j.GetBase() << ",";
                }
                std::cout << "}, ";
            }
            std::cout << "], ";
        }
        std::cout << ">" <<std::endl;
    }

    pop_0.NextGenWF(0.5, 0.5);

    std::cout << "pop0_F3_seq" <<std::endl;
    for (std::vector<std::vector<std::vector<CBase>>> ind: pop_0.GetIndRepeatsSeq()){
        std::cout << "<";
        for (std::vector<std::vector<CBase>> rep: ind){
            std::cout << "[";
            for(std::vector<CBase> v: rep){
                std::cout << "{";
                for (CBase j: v){
                    std::cout << j.GetBase() << ",";
                }
                std::cout << "}, ";
            }
            std::cout << "], ";
        }
        std::cout << ">" <<std::endl;
    }


    pop_0.NextGenWF(0.5, 0.5);

    std::cout << "pop0_F4_seq" <<std::endl;
    for (std::vector<std::vector<std::vector<CBase>>> ind: pop_0.GetIndRepeatsSeq()){
        std::cout << "<";
        for (std::vector<std::vector<CBase>> rep: ind){
            std::cout << "[";
            for(std::vector<CBase> v: rep){
                std::cout << "{";
                for (CBase j: v){
                    std::cout << j.GetBase() << ",";
                }
                std::cout << "}, ";
            }
            std::cout << "], ";
        }
        std::cout << ">" <<std::endl;
    }


    pop_0.NextGenWF(0.5, 0.5);

    std::cout << "pop0_F5_seq" <<std::endl;
    for (std::vector<std::vector<std::vector<CBase>>> ind: pop_0.GetIndRepeatsSeq()){
        std::cout << "<";
        for (std::vector<std::vector<CBase>> rep: ind){
            std::cout << "[";
            for(std::vector<CBase> v: rep){
                std::cout << "{";
                for (CBase j: v){
                    std::cout << j.GetBase() << ",";
                }
                std::cout << "}, ";
            }
            std::cout << "], ";
        }
        std::cout << ">" <<std::endl;
    }

*/


/*    std::vector<CBase> monomer2;
    monomer2.push_back(0);
    monomer2.push_back(0);
    monomer2.push_back(0);
    monomer2.push_back(0);
    monomer2.push_back(0);
    monomer2.push_back(0);


    CRepeat rep_2(2, 6, monomer2);
    std::cout << "rep2" <<std::endl;
    std::cout << rep_2.GetRepeatId() << ' ' <<std::endl;
    for (std::vector<CBase> v: rep_1.GetRepeatSeq()){
      std::cout << "{";
        for (CBase j: v){
            std::cout << j.GetBase() << ",";
        }
      std::cout << "}" <<std::endl;
    }
*/
/*
    std::random_device rd1;
    std::mt19937 gen1(rd1());
    std::uniform_real_distribution<> dist1(0.0, 1.0);


    int l0;
    int l1;
    unsigned int i;
    unsigned int k;

    std::random_device rd2;
    std::mt19937 gen2(rd2());
    std::geometric_distribution<> dist2(0.3);
*/
    /* duplication*/
/*    double a = dist0(gen0);  duplication rate
    if(a < 1){
        l0 = rep_0.GetCopynumber();
        std::cout << "rep0_dup_len" << ' ' <<std::endl;
        std::cout << l0 << ' ' <<std::endl;
        std::random_device rd3;
        std::mt19937 gen3(rd3());
        std::uniform_int_distribution<> dist3(0, l0 - 1);

        i = dist3(gen3);
        std::cout << "rep0_dup_i" << ' ' <<std::endl;
        std::cout << i << ' ' <<std::endl;
        k = dist2(gen2);
        std::cout << "rep0_dup_k" << ' ' <<std::endl;
        std::cout << k << ' ' <<std::endl;

        double b = dist0(gen0);
        std::cout << "b" << ' ' <<std::endl;
        std::cout << b << ' ' <<std::endl;

        if(b < 0.5){


            if(i >= k){
              std::cout << "left-end success" << ' ' <<std::endl;
              rep_0.SetSDedSeq(i - k, i);

              std::cout << "rep0_left-end success" <<std::endl;
              std::cout << rep_0.GetRepeatId() << ' ' <<std::endl;
              for (std::vector<CBase> v: rep_0.GetRepeatSeq()){
                std::cout << "{";
                  for (CBase j: v){
                      std::cout << j.GetBase() << ",";
                  }
                std::cout << "}" <<std::endl;
              }

            }
            else{
              std::cout << "left-end error" << ' ' <<std::endl;
            }
        }
        else{
            if(i + k + 1 <= l0){
                std::cout << "right-end success" << ' ' <<std::endl;
                rep_0.SetSDedSeq(i, i + k);

                std::cout << "rep0_right-end success" <<std::endl;
                std::cout << rep_0.GetRepeatId() << ' ' <<std::endl;
                for (std::vector<CBase> v: rep_0.GetRepeatSeq()){
                  std::cout << "{";
                    for (CBase j: v){
                        std::cout << j.GetBase() << ",";
                    }
                std::cout << "}" <<std::endl;
              }

            }
            else{
                std::cout << "right-end error" << ' ' <<std::endl;
            }
        }

        std::cout << "rep0" <<std::endl;
        std::cout << rep_0.GetRepeatId() << ' ' <<std::endl;
        for (std::vector<CBase> v: rep_0.GetRepeatSeq()){
          std::cout << "{";
            for (CBase j: v){
                std::cout << j.GetBase() << ",";
            }
          std::cout << "}" <<std::endl;
        }
    }
    */
/*
    a = dist0(gen0);
    if(a < 1){
        l1 = rep_1.GetCopynumber();
        std::cout << "rep1_dup_len" << ' ' <<std::endl;
        std::cout << l1 << ' ' <<std::endl;
        std::random_device rd3;
        std::mt19937 gen3(rd3());
        std::uniform_int_distribution<> dist3(0, l1-1);

        i = dist3(gen3);
        std::cout << "rep1_dup_i" << ' ' <<std::endl;
        std::cout << i << ' ' <<std::endl;
        k = dist2(gen2);
        std::cout << "rep1_dup_j" << ' ' <<std::endl;
        std::cout << k << ' ' <<std::endl;

        rep_1.SetSDedSeq(i, i + k);
    }


    std::cout << "rep0_dup_seq" <<std::endl;
    std::cout << rep_0.GetRepeatId() << ' ' <<std::endl;
    for (std::vector<CBase> v: rep_0.GetRepeatSeq()){
      std::cout << "{";
        for (CBase j: v){
            std::cout << j.GetBase() << ",";
        }
      std::cout << "}" <<std::endl;
    }
*/
    return 0;

}

/*
    std::cout << "rep1_dup_seq" <<std::endl;
    std::cout << rep_1.GetRepeatId() << ' ' <<std::endl;
    for (std::vector<CBase> v: rep_1.GetRepeatSeq()){
      std::cout << "{";
        for (CBase j: v){
            std::cout << j.GetBase() << ",";
        }
      std::cout << "}" <<std::endl;
    }
*/

    /* deletion
        double a = dist0(gen0);
        if(a < 1){
            l0  = rep_0.GetCopynumber();
            std::cout << "rep0_del_len" << ' ' <<std::endl;
            std::cout << l0 << ' ' <<std::endl;
            std::random_device rd3;
            std::mt19937 gen3(rd3());
            std::uniform_int_distribution<> dist3(0, l0-1);
            i = dist3(gen3);
            std::cout << "rep0_del_i" << ' ' <<std::endl;
            std::cout << i << ' ' <<std::endl;

            k = dist2(gen2);
            std::cout << "rep0_del_k" << ' ' <<std::endl;
            std::cout << k << ' ' <<std::endl;

            double b = dist0(gen0);
            std::cout << "b" << ' ' <<std::endl;
            std::cout << b << ' ' <<std::endl;

            if(b < 0.5){
                if(i >= k){
                  std::cout << "left-end success" << ' ' <<std::endl;
                  rep_0.SetDeletedSeq(i - k, i);

                  std::cout << "rep0_left-end success" <<std::endl;
                  std::cout << rep_0.GetRepeatId() << ' ' <<std::endl;
                  for (std::vector<CBase> v: rep_0.GetRepeatSeq()){
                    std::cout << "{";
                      for (CBase j: v){
                          std::cout << j.GetBase() << ",";
                      }
                    std::cout << "}" <<std::endl;
                  }

                }
                else{
                  std::cout << "left-end error" << ' ' <<std::endl;
                }
            }
            else{
                if(i + k + 1 <= l0){
                    std::cout << "right-end success" << ' ' <<std::endl;
                    rep_0.SetDeletedSeq(i, i + k);

                    std::cout << "rep0_right-end success" <<std::endl;
                    std::cout << rep_0.GetRepeatId() << ' ' <<std::endl;
                    for (std::vector<CBase> v: rep_0.GetRepeatSeq()){
                      std::cout << "{";
                        for (CBase j: v){
                            std::cout << j.GetBase() << ",";
                        }
                    std::cout << "}" <<std::endl;
                  }

                }
                else{
                    std::cout << "right-end error" << ' ' <<std::endl;
                }
            }
        }

            if(b < 0.5){
                std::cout << "left-end success" << ' ' <<std::endl;
                rep_0.SetDeletedSeq(std::max(0, i - k), i);

                std::cout << "rep0" <<std::endl;
                std::cout << rep_0.GetRepeatId() << ' ' <<std::endl;
                for (std::vector<CBase> v: rep_0.GetRepeatSeq()){
                  std::cout << "{";
                    for (CBase j: v){
                        std::cout << j.GetBase() << ",";
                    }
                  std::cout << "}" <<std::endl;
                }
            }
*/


/*
        a = dist0(gen0);
        if(a < 1){
            l1 = rep_1.GetCopynumber();
            std::cout << "rep1_del_len" << ' ' <<std::endl;
            std::cout << l1 << ' ' <<std::endl;
            std::random_device rd3;
            std::mt19937 gen3(rd3());
            std::uniform_int_distribution<> dist3(0, l1-1);
            i = dist3(gen3);
            std::cout << "rep1_del_i" << ' ' <<std::endl;
            std::cout << i << ' ' <<std::endl;

            j = dist2(gen2);
            std::cout << "rep1_del_j" << ' ' <<std::endl;
            std::cout << j.GetBase() << ' ' <<std::endl;

            rep_1.SetDeletedSeq(i, i);
        }

        std::cout << "rep0_dup_del_seq" <<std::endl;
        std::cout << rep_0.GetRepeatId() << ' ' <<std::endl;
        for (std::vector<CBase> v: rep_0.GetRepeatSeq()){
          std::cout << "{";
            for (CBase j: v){
                std::cout << j.GetBase() << ",";
            }
          std::cout << "}" <<std::endl;
        }

        std::cout << "rep1_dup_del_seq" <<std::endl;
        std::cout << rep_1.GetRepeatId() << ' ' <<std::endl;
        for (std::vector<CBase> v: rep_1.GetRepeatSeq()){
          std::cout << "{";
            for (CBase j: v){
                std::cout << j.GetBase() << ",";
            }
          std::cout << "}" <<std::endl;
        }
*/

/*recombination*/
/*
        a = dist0(gen0);
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

            std::vector<std::vector<CBase>> r0_f = rep_0.GetRepeatSlice(0, i);

            std::cout << "rep0_f_seq" <<std::endl;
            for (std::vector<CBase> v: r0_f){
              std::cout << "{";
                for (CBase j: v){
                    std::cout << j.GetBase() << ",";
                }
              std::cout << "}" <<std::endl;
            }


            std::vector<std::vector<CBase>> r0_l = rep_0.GetRepeatSlice(i+1, l0-1);

            std::cout << "rep0_l_seq" <<std::endl;
            for (std::vector<CBase> v: r0_l){
              std::cout << "{";
                for (CBase j: v){
                    std::cout << j.GetBase() << ",";
                }
              std::cout << "}" <<std::endl;
            }




            std::random_device rd3;
            std::mt19937 gen3(rd3());
            std::uniform_int_distribution<> dist3(0, l1-2);
            j = dist3(gen3);
            std::vector<std::vector<CBase>> r1_f = rep_1.GetRepeatSlice(0, j);

            std::cout << "rep1_f_seq" <<std::endl;
            for (std::vector<CBase> v: r1_f){
              std::cout << "{";
                for (CBase j: v){
                    std::cout << j.GetBase() << ",";
                }
              std::cout << "}" <<std::endl;
            }


            std::vector<std::vector<CBase>> r1_l = rep_1.GetRepeatSlice(j+1, l1-1);

            std::cout << "rep1_l_seq" <<std::endl;
            for (std::vector<CBase> v: r1_l){
              std::cout << "{";
                for (CBase j: v){
                    std::cout << j.GetBase() << ",";
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
            for (std::vector<CBase> v: rep_0.GetRepeatSeq()){
              std::cout << "{";
                for (CBase j: v){
                    std::cout << j.GetBase() << ",";
                }
              std::cout << "}" <<std::endl;
            }

            std::cout << "rep1_recombination_seq" <<std::endl;
            std::cout << rep_1.GetRepeatId() << ' ' <<std::endl;
            for (std::vector<CBase> v: rep_1.GetRepeatSeq()){
              std::cout << "{";
                for (CBase j: v){
                    std::cout << j.GetBase() << ",";
                }
              std::cout << "}" <<std::endl;
            }
*/


/*
    CIndividual ind_0(rep_0, rep_0);
    CIndividual ind_1(rep_1, rep_1);


    std::cout << "ind0_rep1" <<std::endl;
    std::cout << ind_0.GetRepeat1Id() << ' ' <<std::endl;
    for (std::vector<CBase> v: ind_0.GetRepeat1Seq()){
      std::cout << "{";
        for (CBase j: v){
            std::cout << j.GetBase() << ",";
        }
      std::cout << "}" <<std::endl;
    }

    std::cout << "ind0_rep2" <<std::endl;
    std::cout << ind_0.GetRepeat2Id() << ' ' <<std::endl;
    for (std::vector<CBase> v: ind_0.GetRepeat2Seq()){
      std::cout << "{";
        for (CBase j: v){
            std::cout << j.GetBase() << ",";
        }
      std::cout << "}" <<std::endl;
    }

    std::cout << "ind0_zygote" <<std::endl;
    CRepeat zygote0 = ind_0.MakeZygote(0.5, 0.5, 1);
    std::cout << zygote0.GetRepeatId() << ' ' <<std::endl;
    for (std::vector<CBase> v: zygote0.GetRepeatSeq()){
      std::cout << "{";
        for (CBase j: v){
            std::cout << j.GetBase() << ",";
        }
      std::cout << "}" <<std::endl;
    }

    CRepeat zygote1 = ind_1.MakeZygote(0.5, 0.5, 1);
    std::cout << "ind1_zygote" <<std::endl;
    std::cout << zygote1.GetRepeatId() << ' ' <<std::endl;
    for (std::vector<CBase> v: zygote1.GetRepeatSeq()){
      std::cout << "{";
        for (CBase j: v){
            std::cout << j.GetBase() << ",";
        }
      std::cout << "}" <<std::endl;
    }
    CIndividual child1(zygote0, zygote1);
    std::cout << "child1_rep1" <<std::endl;
    std::cout << child1.GetRepeat1Id() << ' ' <<std::endl;
    for (std::vector<CBase> v: child1.GetRepeat1Seq()){
      std::cout << "{";
        for (CBase j: v){
            std::cout << j.GetBase() << ",";
        }
      std::cout << "}" <<std::endl;
    }

    std::cout << "child1_rep2" <<std::endl;
    std::cout << child1.GetRepeat2Id() << ' ' <<std::endl;
    for (std::vector<CBase> v: child1.GetRepeat2Seq()){
      std::cout << "{";
        for (CBase j: v){
            std::cout << j.GetBase() << ",";
        }
      std::cout << "}" <<std::endl;
    }




    return 0;

}

*/
