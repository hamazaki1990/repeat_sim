import random
import copy
from monomer import Monomer


class Tandem_repeat:
    mutationrate = 1
    conversionrate = 1
    slippagerate = 1

    def __init__(self, l, i=None, s=0.0):
        repeats = [Monomer(x) for x in range(l)]
        if i is not None:
            repeats[i] = Monomer(i, 1+s)
        self._repeats = repeats

    def get_ids(self):
        return self._repeats

    def get_length(self):
        return len(self._repeats)

    def get_fitnesses(self):
        fitness = [x.get_fitness() for x in self._repeats]
        return fitness

    def get_genotypes(self):
        genotype = [x.get_genotype() for x in self._repeats]
        return genotype

    def cal_fitness(self):
        l = len(self._repeats)
        f = [x.get_fitness() for x in self._repeats]
        return sum(f)/l

    def acquire_mutation(self, s=0.0):  # add mutation that raises fitness by s
        r = random.random()
        next_repeats = copy.deepcopy(self)
        if r < Tandem_repeat.mutationrate:
            l = len(next_repeats._repeats)
            i = int(r*l/Tandem_repeat.mutationrate)
            next_monomer = next_repeats._repeats[i]
            next_monomer._fitness += s
            next_monomer._genotype.append(random.random())
            next_repeats._repeats[i] = next_monomer
        return next_repeats

    def slippage(self):
        r = random.random()
        next_repeats = copy.deepcopy(self)
        if r < Tandem_repeat.mutationrate:
            l = len(next_repeats._repeats)
            i = int(r*l/Tandem_repeat.mutationrate)
            

#    def gene_conversion(self):
#        r = random.random()
#        if r < Diploid.conversionrate:
#            donor = random.choice()
#            recip = random.randint(0, 1)
#            next_diploid[recip] = donor
#        return next_diploid


def main():
    repeat = Tandem_repeat(5)
    print(repeat.get_ids())
    print(repeat.get_fitnesses())
    print(repeat.get_length())
    print(repeat.get_genotypes())
    repeat2 = repeat.acquire_mutation(0.1)
    print(repeat2.get_ids())
    print(repeat2.get_fitnesses())
    print(repeat2.get_genotypes())
    repeat3 = repeat2.acquire_mutation(0.2)
    print(repeat3.get_ids())
    print(repeat3.get_fitnesses())
    print(repeat3.get_genotypes())


if __name__ == '__main__':
    main()
