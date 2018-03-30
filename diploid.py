from tandem_repeat import Tandem_repeat
import random
import copy


class Diploid:
<<<<<<< HEAD
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
=======
    mutationrate = 0.25
    sliprate = 0.25
    conversrate = 0.25
    crossingrate = 0.25

    def __init__(self, ind_id, len1, len2, i=None, s=0.0):
        self._paternal = Tandem_repeat(ind_id, len1, i, s)
        self._maternal = Tandem_repeat(ind_id, len2)

    def get_ind_id(self):
        return self._paternal.get_repeat_id()

    def get_ind_repeatids(self):
        ids = [self._paternal.get_monomer_ids(),
               self._maternal.get_monomer_ids()]
        return ids

    def get_ind_repeatlengths(self):
>>>>>>> diploid
        length = [self._paternal.get_repeat_length(),
                  self._maternal.get_repeat_length()]
        return length

<<<<<<< HEAD
    def get_diploid_fitnesses(self):
=======
    def get_ind_fitnesses(self):
>>>>>>> diploid
        fitnesses = [self._paternal.get_repeat_fitnesses(),
                     self._maternal.get_repeat_fitnesses()]
        return fitnesses

<<<<<<< HEAD
    def get_diploid_genotypes(self):
=======
    def get_ind_genotypes(self):
>>>>>>> diploid
        genotype = [self._paternal.get_repeat_genotypes(),
                    self._maternal.get_repeat_genotypes()]
        return genotype

<<<<<<< HEAD
    def cal_diploid_fitnesses(self):
        dom = max(self._paternal.cal_repeat_fitness(),
                  self._maternal.cal_repeat_fitness)
        res = min(self._paternal.cal_repeat_fitness(),
                  self._maternal.cal_repeat_fitness)
=======
    def calculate_ind_fitnesses(self):
        dom = max(self._paternal.cal_repeat_fitness(),
                  self._maternal.cal_repeat_fitness())
        res = min(self._paternal.cal_repeat_fitness(),
                  self._maternal.cal_repeat_fitness())
>>>>>>> diploid
        return sum(f)/l

    def acquire_mutation(self, s=0.0):  # add mutation that raises fitness by s
        r = random.random()
        next_repeats = copy.deepcopy(self)
<<<<<<< HEAD
        if r < Tandem_repeat.mutationrate:
=======
        if r < 0.5:
>>>>>>> diploid
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
<<<<<<< HEAD
        if r < Tandem_repeat.crossingraterate:


=======


    def replicate_error(self):
        error = [Tandem_repeat.mutationrate, Tandem_repeat.sliprate,
                 Tandem_repeat.conversrate, crossingrate]
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

>>>>>>> diploid

test = Diploid(3)
print(test.get_ids())
print(test.get_fitnesses())


test2 = test.copy_paternal()
print(test2.get_ids())
print(test2.get_fitnesses())
