from tandem_repeat import Tandem_repeat
import random
import copy


class Diploid:
    mutationrate = 1
    conversionrate = 1

    def __init__(self, l1, l2):
        self._paternal = Tandem_repeat(l1)
        self._maternal = Tandem_repeat(l2)

    def get_ids(self):
        ids = [self._paternal.get_ids(), self._maternal.get_ids()]
        return ids

    def get_fitnesses(self):
        fitnesses = [self._paternal.get_fitnesses(),
                     self._maternal.get_fitnesses()]
        return fitnesses

    def acquire_mutation(self, s=0.0):  # add mutation that raises fitness by s
        r = random.random()
        next_ind = copy.deepcopy(self)
        next_genotype = next_ind._genotype
        next_fitness = next_ind._fitness
        if r < Diploid.mutationrate:
            next_genotype.append(random.random())
            next_fitness = next_fitness + s
        next_ind._genotype = next_genotype
        next_ind._fitness = next_fitness
        return next_ind

    def gene_conversion(self):
        r = random.random()
#        if r < Diploid.conversionrate:
#            donor = random.choice()
#            recip = random.randint(0, 1)
#            next_diploid[recip] = donor
#        return next_diploid


test = Diploid(3, 2, 2, 0.2)
print(test.get_ids())
print(test.get_fitnesses())


test2 = test.copy_paternal()
print(test2.get_ids())
print(test2.get_fitnesses())
