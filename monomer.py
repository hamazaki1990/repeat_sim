from decimal import Decimal
import random
import copy


class Monomer:
    mutationrate = 0.01

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

    def acquire_mutation(self, s=0.0):
        r = random.random()
        next_ind = copy.deepcopy(self)
        next_genotype = next_ind._genotype
        next_fitness = next_ind._fitness
        if r < Monomer.mutationrate:
            next_genotype.append(random.random())
            next_fitness = next_fitness + s
        next_ind._genotype = next_genotype
        next_ind._fitness = next_fitness
        return next_ind

    def __repr__(self):
        return str(self._id)


def main():
    test = Monomer(1)
    print(test.get_fitness())
    test2 = test.acquire_mutation()
    print(test2.get_id())
    print(test2.get_genotype())
    print(test2.get_fitness())
    test3 = test.acquire_mutation(0.2)
    print(test3.get_id())
    print(test3.get_genotype())
    print(test3.get_fitness())
    test4 = test3.acquire_mutation(-0.1)
    print(test4.get_id())
    print(test4.get_genotype())
    print(test4.get_fitness())

if __name__ == '__main__':
    main()
