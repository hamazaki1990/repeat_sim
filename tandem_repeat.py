from monomer import Monomer


class Tandem_repeat:
    def __init__(self, l):
        repeats = [Monomer(x) for x in range(l)]
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


def main():
    repeat = Tandem_repeat(5)
    print(repeat.get_ids())
    print(repeat.get_fitnesses())
    print(repeat.get_length())
    print(repeat.get_genotypes())


if __name__ == '__main__':
    main()
