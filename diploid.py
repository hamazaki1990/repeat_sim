from tandem_repeat import Tandem_repeat
import random
import copy


class Diploid:
    mutationrate = 0.25
    sliprate = 0.25
    conversrate = 0.25
    crossingrate = 0.25

    def __init__(self, ind_id, len1, len2, i=None, s=0.0):
        self._paternal = Tandem_repeat(ind_id, len1, i, s)
        self._maternal = Tandem_repeat(ind_id, len2)

    def get_ind_id(self):
        return self._paternal.get_repeat_id()

    def get_ind_monomerids(self):
        ids = [self._paternal.get_monomer_ids(),
               self._maternal.get_monomer_ids()]
        return ids

    def get_ind_repeatlengths(self):
        length = [self._paternal.get_repeat_length(),
                  self._maternal.get_repeat_length()]
        return length

    def get_ind_fitnesses(self):
        fitnesses = [self._paternal.get_repeat_fitnesses(),
                     self._maternal.get_repeat_fitnesses()]
        return fitnesses

    def get_ind_genotypes(self):
        genotype = [self._paternal.get_repeat_genotypes(),
                    self._maternal.get_repeat_genotypes()]
        return genotype

    def calculate_ind_fitnesses(self):
        dom = max(self._paternal.cal_repeat_fitness(),
                  self._maternal.cal_repeat_fitness())
        res = min(self._paternal.cal_repeat_fitness(),
                  self._maternal.cal_repeat_fitness())
        return sum(f)/l

    def acquire_mutation(self, s=0.0):  # add mutation that raises fitness by s
        r = random.random()
        next_repeats = copy.deepcopy(self)
        if r < 0.5:
            next_repeats._paternal.acquire_mutation()
        else:
            next_repeats._maternal.acquire_mutation()
        return next_repeats

    def slippage(self):
        r = random.random()
        next_repeats = copy.deepcopy(self)
        if r < 0.5:
            next_repeats._paternal.slippage()
        else:
            next_repeats._maternal.slippage()
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




    def replicate_error(self):
        error = [Tandem_repeat.mutationrate, Tandem_repeat.sliprate,
                 Tandem_repeat.conversrate, Tandem_repeat.crossingrate]
        errorrate = [sum(error[:i]) for i in range(1, len(error) + 1)]
        r = random.random()
        if r < errorrate[0]:
            return self.acquire_mutation()
        elif r < errorrate[1]:
            return self.slippage()
        elif r < errorrate[2]:
            return self.gene_conversion()
        elif r < errorrate[3]:
            return self.crossing_over()
        else:
            return self


test = Diploid(3)
print(test.get_ids())
print(test.get_fitnesses())


test2 = test.copy_paternal()
print(test2.get_ids())
print(test2.get_fitnesses())
