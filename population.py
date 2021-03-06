from diploid import Diploid
from tandem_repeat import Tandem_repeat
from numpy import random
# import numpy as np
import pprint
# import matplotlib.pyplot as plt


# def roulettechoice(individuals, cumsum_fitness):
#     r = random.uniform(0.0, max(cumsum_fitness))
#     for i in range(len(cumsum_fitness)):
#         if r < cumsum_fitness[i]:
#             return individuals[i]


class Population:

    def __init__(self, popsize, replength, mut_allelerate=0.0, i=None, s=0.0):
        mutantrate = mut_allelerate ** 2
        heterorate = 2 * mut_allelerate * (1 - mut_allelerate)
        num_mutant = int(popsize * mutantrate)
        num_hetero = int(popsize * heterorate)
        num_notwild = num_mutant + num_hetero
        mutant_inds = [Diploid(Tandem_repeat(x, replength, i, s))
                       for x in range(num_mutant)]
        het_inds = [Diploid(Tandem_repeat(x, replength),
                    Tandem_repeat(x, replength, i, s))
                    for x in range(num_mutant, num_notwild)]
        wild_inds = [Diploid(Tandem_repeat(x, replength))
                     for x in range(num_notwild, popsize)]
        self._inds = mutant_inds + het_inds + wild_inds

    def get_repeat_ids(self):
        return [x.get_repeatids() for x in self._inds]

    def get_ind_ids(self):
        return [x.get_ind_id() for x in self._inds]

    def get_ind_repeatlengths(self):
        return [x.get_ind_repeatlength() for x in self._inds]

    def get_ind_fitnesses(self):
        fitness = [x.calculate_ind_sc() for x in self._inds]
        return fitness

    def get_monomer_fitnesses(self):
        fitness = [x.get_fitnesses() for x in self._inds]
        return fitness

    def get_ind_genotypes(self):
        genotypes = [x.get_ind_genotypes() for x in self._inds]
        return genotypes

    # def calc_cumsum_fitness(self):
    #     fitness = [x.calculate_ind_sc() for x in self._inds]
    #     size = len(self._inds)
    #     cumsum_fitness = [sum(fitness[:i]) for i in range(1, size + 1)]
    #     return cumsum_fitness

    def next_genwf(self):
        next_generation = []
        size = len(self._inds)
        for x in range(size):
            f = [x.calculate_ind_sc()/size for x in self._inds]
            parent = random.choice(self._inds, 2, False, f)
            father = parent[0]
            mother = parent[1]
            next_p = father.replicate_error().make_zygote()
            next_m = mother.replicate_error().make_zygote()
            next_generation.append(Diploid(next_p, next_m))
        self._inds = next_generation
        return self

    def next_genmo(self):
        size = len(self._inds)
        i_dying = random.randrange(size)
        f = [x.calculate_ind_sc()/size for x in self._inds]
        parent = random.choice(self._inds, 2, False, f)
        father = parent[0]
        mother = parent[1]
        next_p = father.replicate_error().make_zygote()
        next_m = mother.replicate_error().make_zygote()
        self._inds[i_dying] = Diploid(next_p, next_m)
        return self

    def list_mutation(self):
        genotypes = [x.get_genotype() for x in self._inds]
        m_sites = []
        for x in genotypes:
            m_sites.extend(x)
        m_sites = sorted(list(set(m_sites)))
        m_list = ([[0 for x in range(len(m_sites))]
                  for y in range(len(self._inds))])
        for i in range(len(self._inds)):
            for j in range(len(genotypes[i])):
                k = m_sites.index(genotypes[i][j])
                m_list[i][k] += 1
        return m_list

    def mutantfreq_per_site(self):
        genotypes = [x.get_genotype() for x in self._inds]
        m_sites = []
        for x in genotypes:
            m_sites.extend(x)
        m_sites = sorted(list(set(m_sites)))
        m_count = [0 for x in range(len(m_sites))]
        for i in range(len(self._inds)):
            for j in range(len(genotypes[i])):
                k = m_sites.index(genotypes[i][j])
                m_count[k] += 1
        mutantfreq = [x/len(self._inds) for x in m_count]
        mutantfreq_per_site = ([[m_sites[i], mutantfreq[i]]
                               for i in range(len(m_sites))])
        return mutantfreq_per_site

    def is_not_fixed_ind(self):
        for x in range(1, len(self._inds)):
            if self.get_ind_ids()[0] != self.get_ind_ids()[x]:
                return True
        else:
            return False

    def is_not_fixed_rep(self):
        for x in range(1, len(self._inds)):
            if self.get_repeat_ids()[0] != self.get_repeat_ids()[x]:
                return True
        else:
            return False


def main():
    # R = random.choice(range(10), 2, False)[1]
    # for x in range(10000):
    #     r = random.choice(range(10), 2, False)[1]
    #     R = np.hstack((R, r))
    # plt.hist(R, bins=100)   # 100本のヒストグラムを作成
    # plt.show()              # グラフを表示

    print("100generation")
    test = Population(5, 10)
    for i in range(100):
        pprint.pprint(test.get_ind_ids())
        pprint.pprint(test.get_repeat_ids())
        pprint.pprint(test.get_ind_repeatlengths())
        pprint.pprint(test.get_ind_fitnesses())
        test = test.next_genwf()
# pprint.pprint("wf")
# test = Population(10, 3, 0.1, 0)
# pprint.pprint(test.get_ind_ids())
# pprint.pprint(test.get_repeat_ids())
# pprint.pprint(test.get_ind_genotypes())
# test2 = test.next_genwf()
# pprint.pprint(test2.get_ind_ids())
# pprint.pprint(test2.get_repeat_ids())
# pprint.pprint(test2.get_ind_genotypes())
# pprint.pprint(test2.is_not_fixed_ind())
# test3 = test2.next_genwf()
# pprint.pprint(test3.get_ind_ids())
# pprint.pprint(test3.get_repeat_ids())
# pprint.pprint(test3.get_ind_genotypes())
# pprint.pprint(test3.is_not_fixed_ind())
# pprint.pprint("mo")
# test = Population(10, 3, 0.1, 0)
# pprint.pprint(test.get_ind_ids())
# pprint.pprint(test.get_repeat_ids())
# pprint.pprint(test.get_ind_genotypes())
# test3 = test.next_genmo()
# pprint.pprint(test3.get_ind_ids())
# pprint.pprint(test3.get_repeat_ids())
# pprint.pprint(test3.get_ind_genotypes())
# pprint.pprint(test2.is_not_fixed_ind())

# while (test.is_not_fixed_ind() or test.is_not_fixed_rep()):
#     pprint.pprint(test.get_ind_ids())
#     pprint.pprint(test.get_repeat_ids())
#     pprint.pprint(test.get_ind_genotypes())
#     print("ind_id")
#     for x in range(10):
#         print(test.get_ind_ids()[0] != test.get_ind_ids()[x])
#     print("repeat_id")
#     for x in range(10):
#         print(test.get_repeat_ids()[0] != test.get_repeat_ids()[x])
#     print("fix_ind:" + str(test.is_not_fixed_ind()))
#     print("fix_repeat:" + str(test.is_not_fixed_rep()))


# pprint.pprint(test.get_ind_genotypes())

if __name__ == '__main__':
    main()
