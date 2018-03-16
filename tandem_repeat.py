from monomer import Monomer


class Tandem_repeat:

    def __init__(self, l, i=None, s=0.0):
        repeats = [Monomer(x) for x in range(l)]
        if i is not None:
            repeats[i] = Monomer(i, 1+s)
        self._repeats = repeats

    def get_repeat_ids(self):
        return self._repeats

    def get_repeat_length(self):
        return len(self._repeats)

    def get_repeat_fitnesses(self):
        fitness = [x.get_fitness() for x in self._repeats]
        return fitness

    def get_repeat_genotypes(self):
        genotype = [x.get_genotype() for x in self._repeats]
        return genotype

    def cal_repeat_fitness(self):
        l = len(self._repeats)
        f = [x.get_fitness() for x in self._repeats]
        return sum(f)/l



def main():
    repeat = Tandem_repeat(5)
    print(repeat.get_ids())
    print(repeat.get_fitnesses())
    print(repeat.get_length())
    print(repeat.get_genotypes())
    print(repeat.cal_fitness())
    repeat2 = repeat.acquire_mutation(0.1)
    print(repeat2.get_ids())
    print(repeat2.get_fitnesses())
    print(repeat2.get_genotypes())
    print(repeat2.cal_fitness())
    repeat3 = repeat2.acquire_mutation(0.2)
    print(repeat3.get_ids())
    print(repeat3.get_fitnesses())
    print(repeat3.get_genotypes())
    print(repeat3.cal_fitness())
    repeat4 = repeat3.slippage()
    print(repeat4.get_ids())
    print(repeat4.get_fitnesses())
    print(repeat4.get_genotypes())
    print(repeat4.cal_fitness())
    repeat5 = repeat3.gene_conversion()
    print(repeat5.get_ids())
    print(repeat5.get_fitnesses())
    print(repeat5.get_genotypes())
    print(repeat5.cal_fitness())
    repeat6 = repeat5.gene_conversion()
    print(repeat6.get_ids())
    print(repeat6.get_fitnesses())
    print(repeat6.get_genotypes())
    print(repeat6.cal_fitness())

if __name__ == '__main__':
    main()
