from tandem_repeat import Tandem_repeat
import random
import copy


class Diploid:
    mutationrate = 1
    conversionrate = 1
    crossingrate = 1
    slippagerate = 1

    def __init__(self, l, i=None, s=0.0):
        self._paternal = Tandem_repeat(l, i, s)
        self._maternal = Tandem_repeat(l)

    def get_diploid_ids(self):
        ids = [self._paternal.get_repeat_ids(),
               self._maternal.get_repeat_ids()]
        return ids

    def get_diploid_lengths(self):
        length = [self._paternal.get_repeat_length(),
                  self._maternal.get_repeat_length()]
        return length

    def get_diploid_fitnesses(self):
        fitnesses = [self._paternal.get_repeat_fitnesses(),
                     self._maternal.get_repeat_fitnesses()]
        return fitnesses

    def get_diploid_genotypes(self):
        genotype = [self._paternal.get_repeat_genotypes(),
                    self._maternal.get_repeat_genotypes()]
        return genotype

    def cal_diploid_fitnesses(self):
        dom = max(self._paternal.cal_repeat_fitness(),
                  self._maternal.cal_repeat_fitness)
        res = min(self._paternal.cal_repeat_fitness(),
                  self._maternal.cal_repeat_fitness)
        return sum(f)/l

    def acquire_mutation(self, s=0.0):  # add mutation that raises fitness by s
        r = random.random()
        next_repeats = copy.deepcopy(self)
        if r < Tandem_repeat.mutationrate:
            i = random.randrange(len(next_repeats._repeats))
            next_monomer = next_repeats._repeats[i]
            next_monomer._fitness += s
            next_monomer._genotype.append(random.random())
            next_repeats._repeats[i] = next_monomer
        return next_repeats

    def slippage(self):
        r = random.random()
        next_repeats = copy.deepcopy(self)
        if r < Tandem_repeat.slippagerate:
            i = random.randrange(len(next_repeats._repeats))
            next_repeats._repeats.pop(i)
        return next_repeats

    def gene_conversion(self):
        r = random.random()
        next_repeats = copy.deepcopy(self)
        if r < Tandem_repeat.conversionrate:
            i = random.randrange(len(next_repeats._repeats))
            j = random.randrange(len(next_repeats._repeats))
            next_repeats._repeats[i] = next_repeats._repeats[j]
        return next_repeats

    def crossing_over(self):
        r = random.random()
        next_repeats = copy.deepcopy(self)
        if r < Tandem_repeat.crossingraterate:



test = Diploid(3)
print(test.get_ids())
print(test.get_fitnesses())


test2 = test.copy_paternal()
print(test2.get_ids())
print(test2.get_fitnesses())
