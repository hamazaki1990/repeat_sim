import random
import copy


class Monomer:
    mutationrate = 0.001

    def __init__(self, n, f=1.0):
        self._id = n
        self._fitness = f
        self._genotype = []

    def get_id(self):
        return self._id

    def get_fitness(self):
        return self._fitness

    def get_genotype(self):
        return self._genotype

    def acquire_mutation(self):
        r = random.random()
        next_ind = copy.deepcopy(self)
        next_genotype = next_ind._genotype
        if r < Monomer.mutationrate:
            next_genotype.append(random.random())
        next_ind._genotype = next_genotype
        return next_ind

    def __repr__(self):
        return str(self._id)
