from tandem_repeat import Tandem_repeat


class Population:

    def __init__(self, n, l, mutant=0.0, i=None, s=0.0):
        num_mutant = int(n * mutant)
        mutant_inds = [Tandem_repeat(l, i, s) for x in range(num_mutant)]
        wild_inds = [Tandem_repeat(l) for x in range(num_mutant, n)]
        self._inds = mutant_inds + wild_inds

    def get_ids(self):
        return self._inds

    def get_inds_fitnesses(self):
        fitness = [x.cal_fitness() for x in self._inds]
        return fitness

    def get_monomer_fitnesses(self):
        fitness = [x.get_fitnesses() for x in self._inds]
        return fitness

    def get_inds_genotypes(self):
        genotypes = [x.get_genotypes() for x in self._inds]
        return genotypes

    def next_genwf(self):
        fitness = [x.cal_fitness() for x in self._inds]
        size = len(self._inds)
        cumsum_fitness = [sum(fitness[:i]) for i in range(1, size + 1)]
        next_generation = []
        for x in range(size):
            parent_inds = roulettechoice(self._inds, cumsum_fitness)
            next_inds = parent_inds.acquire_mutation()
            next_generation.append(next_inds)
        self._inds = next_generation

    def next_genmo(self):
        fitness = [x.get_fitness() for x in self._inds]
        size = len(self._inds)
        cumsum_fitness = [sum(fitness[:i]) for i in range(1, size + 1)]
        i_dying = random.randrange(size)
        parent_inds = roulettechoice(self._inds, cumsum_fitness)
        next_inds = parent_inds.acquire_mutation()
        self._inds[i_dying] = next_inds

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

    def is_not_fixed(self):
        for x in range(1, len(self._inds)):
            if self._inds[0] != self._inds[x]:
                return True
        else:
            return False
