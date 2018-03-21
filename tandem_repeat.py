import random
import copy
from monomer import Monomer


class Tandem_repeat:

    def __init__(self, length, i=None, s=0.0):
        repeats = [Monomer(x) for x in range(length)]
        if i is not None:
            repeats[i] = Monomer(i, 1+s)
        self.__repeats = repeats

    def get_ids(self):
        return [x.get_id() for x in self.__repeats]

    def get_length(self):
        return len(self.__repeats)

    def get_fitnesses(self):
        fitness = [x.get_fitness() for x in self.__repeats]
        return fitness

    def get_genotypes(self):
        genotype = [x.get_genotype() for x in self.__repeats]
        return genotype

    def calculate_fitness(self):
        l = len(self.__repeats)
        f = [x.get_fitness() for x in self.__repeats]
        return sum(f)/l

    def copy_self(self):
        return copy.deepcopy(self)

    def acquire_mutation(self, s=0.0):  # add mutation that raises fitness by s
        r = random.random()
        if r < Tandem_repeat.mutationrate:
            i = random.randrange(len(self.__repeats))
            self.__repeats[i] = self.__repeats[i].acquire_mutation(s)
        return self

    def slippage(self):
        r = random.random()
        if r < Tandem_repeat.slippagerate:
            i = random.randrange(self.get_length())
            self.__repeats.pop(i)
        return self

    def gene_conversion(self):
        r = random.random()
        if r < Tandem_repeat.conversionrate:
            i = random.randrange(self.get_length())
            j = random.randrange(self.get_length())
            self.__repeats[i] = self.__repeats[j]
        return self


def main():
    repeat = Tandem_repeat(5)
    print(repeat.get_ids())
    print(repeat.get_fitnesses())
    print(repeat.get_length())
    print(repeat.get_genotypes())
    print(repeat.calculate_fitness())
    repeat2 = repeat.acquire_mutation(0.1)
    print(repeat2.get_ids())
    print(repeat2.get_fitnesses())
    print(repeat2.get_genotypes())
    print(repeat2.calculate_fitness())
    repeat3 = repeat2.acquire_mutation(0.2)
    print(repeat3.get_ids())
    print(repeat3.get_fitnesses())
    print(repeat3.get_genotypes())
    print(repeat3.calculate_fitness())
    repeat4 = repeat3.slippage()
    print(repeat4.get_ids())
    print(repeat4.get_fitnesses())
    print(repeat4.get_genotypes())
    print(repeat4.calculate_fitness())
    repeat5 = repeat3.gene_conversion()
    print(repeat5.get_ids())
    print(repeat5.get_fitnesses())
    print(repeat5.get_genotypes())
    print(repeat5.calculate_fitness())
    repeat6 = repeat5.gene_conversion()
    print(repeat6.get_ids())
    print(repeat6.get_fitnesses())
    print(repeat6.get_genotypes())
    print(repeat6.calculate_fitness())


if __name__ == '__main__':
    main()
